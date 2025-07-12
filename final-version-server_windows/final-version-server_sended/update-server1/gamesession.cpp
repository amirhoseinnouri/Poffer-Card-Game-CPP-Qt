#include "gamesession.h"
QString rankToString(Rank rank)
{
    switch (rank) {
    case Rank::Two:
        return "2";
        break;
    case Rank::Three:
        return "3";
        break;
    case Rank::Four:
        return "4";
        break;
    case Rank::Five:
        return "5";
        break;
    case Rank::Six:
        return "6";
        break;
    case Rank::Seven:
        return "7";
        break;
    case Rank::Eight:
        return "8";
        break;
    case Rank::Nine:
        return "9";
        break;
    case Rank::Ten:
        return "10";
        break;
    case Rank::Soldier:
        return "Soldier";
        break;
    case Rank::Queen:
        return "Queen";
        break;
    case Rank::King:
        return "King";
        break;
    case Rank::Bitcoin:
        return "Bitcoin";
        break;
    default:
        return "Unkown";
        break;
    }
}
QString suitToString(Suit suit)
{
    switch (suit) {
    case Suit::Coin:
        return "Coin";
        break;
    case Suit::Diamond:
        return "Diamond";
        break;
    case Suit::Dollar:
        return "Doallar";
        break;
    case Suit::Gold:
        return "Gold";
        break;
    default:
        return "Unkown";
        break;
    }
}
GameSession::GameSession(QTcpSocket* player1,QString player1Username,QTcpSocket* player2,QString player2Username,QObject* parent)
    :QObject(parent),m_player1(player1),m_player2(player2),m_player1Score(0),
    m_player2Score(0),m_currentRound(0),m_player1Username(player1Username),m_player2Username(player2Username)
{
    qDebug()<<"the game session created.";
    connect(m_player1,&QTcpSocket::readyRead,this,&GameSession::playerMessage);
    connect(m_player2,&QTcpSocket::readyRead,this,&GameSession::playerMessage);
}
void GameSession::startGame()
{
    m_player1Score=0;
    m_player2Score=0;
    m_currentRound=0;
    startNewRound();

}
void GameSession::startNewRound()
{
    qDebug()<<"starting a new round...";
    m_currentRound++;
    m_deck.restart();
    qDebug()<<"Main deck has been reset and shuffled.";
    Card p1_start=m_deck.dealOneDiamondCard();
    Card p2_start=m_deck.dealOneDiamondCard();
    qDebug()<<"both player deel a diamond card.";
    QTcpSocket* startingPlayer;
    if(p1_start.getRank()>p2_start.getRank())
    {
        startingPlayer=m_player1;
        qDebug()<<"player 1 will start the round.";
    }
    else
    {
        startingPlayer=m_player2;
        qDebug()<<"player 2 will start the round.";
        m_player1->write(QString("ROUND_START;STARTING_PLAYER_IS_%1\n").arg(startingPlayer==m_player1 ? "YOU":"OPPONENT").toUtf8());
        m_player2->write(QString("ROUND_START;STARTING_PLAYER_IS_%1\n").arg(startingPlayer==m_player2 ? "YOU":"OPPONENT").toUtf8());
    }
    m_turnCounter=1;
    m_currentPlayer=startingPlayer;
    m_turnStarter=startingPlayer;
    qDebug()<<"current turn is "<<m_turnCounter;
    dealCardsToCurrentPlayer();
}
void GameSession::dealCardsToCurrentPlayer()
{
    if(!m_currentPlayer)
        return;
 m_dealCounter=1;
    qDebug()<<"dealing 7 card to the current player...";
    m_currentDealtCards.clear();
    for(int i=0;i<7;++i)
    {
        m_currentDealtCards.append(m_deck.deal());
    }
    QString message="DEALT_CARDS";
    for(const Card &card:m_currentDealtCards)
    {
        message+=";"+rankToString(card.getRank());
        message+=";"+suitToString(card.getSuit());
    }
    message+="\n";
    m_currentPlayer->write(message.toUtf8());
    qDebug()<<"Sent cards to the player.";
}
void GameSession::playerMessage()
{
    QTcpSocket* client=qobject_cast<QTcpSocket*>(sender());
    if(!client||client!=m_currentPlayer)
        return;
    QByteArray data=client->readAll();
    QString message=QString::fromLatin1(data).trimmed();
    qDebug()<<"game session received message:"<<message;
    QStringList parts=message.split(';');
    if(parts.size()<2)
    {
        qDebug()<<"invalid message format.";
        return;
    }
    QString command=parts[0];
    if(command=="CHOOSE_CARD")
    {
        bool conversionOk;
        int choosenIndex=parts[1].toInt(&conversionOk);
        if(!conversionOk)
        {
            qDebug()<<"Received card index is not a number.";
            return;
        }
        if(choosenIndex<0||choosenIndex>6)
        {
            qDebug()<<"received card index is out of bounds.";
            return;
        }


        Card chosenCard=m_currentDealtCards[choosenIndex];
        qDebug()<<"player chose a card.";
        QTcpSocket* otherPlayer=nullptr;
        if(m_currentPlayer==m_player1)
        {
            m_player1Hand.append(chosenCard);
            qDebug()<<"added the card to player1 hand";
            otherPlayer=m_player2;
        }
        else
        {
            m_player2Hand.append(chosenCard);
             qDebug()<<"added the card to player2 hand";
            otherPlayer=m_player1;
        }
        m_currentDealtCards.removeAt(choosenIndex);
        m_currentPlayer=otherPlayer;
        if(m_dealCounter==1)
        {
        dealRemainingCardsTCurrentPlayer();
        }
        else if(m_dealCounter==2)
        {
            processNextTurn();
        }
    }
}
void GameSession::dealRemainingCardsTCurrentPlayer()
{
    if(!m_currentPlayer)
        return;
     m_dealCounter=2;
    QString message="DEALT_CARDS";
    for(const Card & card:m_currentDealtCards)
    {
        message+=";"+rankToString(card.getRank());
        message+=";"+suitToString(card.getSuit());
    }
    message+="\n";
    m_currentPlayer->write(message.toUtf8());
    qDebug()<<"Sent remaining cards to player with message: "<<message;
}
void GameSession::processNextTurn()
{
    if(m_turnCounter<5)
    {
        m_turnCounter++;
        m_currentPlayer=(m_turnStarter==m_player1)?m_player2:m_player1;
        m_turnStarter=m_currentPlayer;
        dealCardsToCurrentPlayer();
    }
    else
    {
        qDebug()<<"All 5 turns are complete, round ended.";
        endRound();
    }
}
void GameSession::endRound()
{
    HandEvaluator handEva;
   HandName p1_rank=handEva.HandEvaluate(m_player1Hand);
    HandName p2_rank=handEva.HandEvaluate((m_player2Hand));
   QTcpSocket* roundWinner=nullptr;
    if(p1_rank>p2_rank)
   {
       roundWinner=m_player1;
    }
    else if(p2_rank>p1_rank)
    {
        roundWinner=m_player2;
    }
    // if rounds are equal i will code later
    if(roundWinner==m_player1)
    {
        m_player1Score++;
        m_roundResults.append("Player1_Won");
        qDebug()<<"Player 1 wins the round!";
        m_player1->write("ROUND_OVER;YOU_WON\n");
         m_player2->write("ROUND_OVER;YOU_LOST\n");
    }else if(roundWinner==m_player2)
    {
        m_player2Score++;
        m_roundResults.append("Player2_Won");
        qDebug()<<"player 2 wins the round.";
        m_player2->write("ROUND_OVER;YOU_WON\n");
        m_player1->write("ROUND_OVER;YOU_LOST\n");
    }
    if(m_player1Score==2||m_player2Score==2)
    {
        qDebug()<<"Game over!";
        endGame();
    }
    else
    {
        qDebug()<<"starting next round...";
        startNewRound();
    }
}
void GameSession::endGame()
{
    qDebug()<<"game has ended, determining the winner...";
    GameHistory historyP1;
    historyP1.opponentUsername=m_player2Username;
    historyP1.gameDate=QDateTime::currentDateTime().toString();
    historyP1.roundResults=m_roundResults;
    GameHistory historyP2;
    historyP2.opponentUsername=m_player1Username;
    historyP2.gameDate=QDateTime::currentDateTime().toString();
    historyP2.roundResults=m_roundResults;
    if(m_player1Score>m_player2Score)
    {
        qDebug()<<"player 1 wins the game.";
        historyP1.finalResult="Won";
        historyP2.finalResult="Lost";
        m_player1->write(QString("GAME_OVER;YOU_WON;FINAL_SCORE_%1-%2\n").arg(m_player1Score).arg(m_player2Score).toUtf8());
         m_player2->write(QString("GAME_OVER;YOU_LOST;FINAL_SCORE_%1-%2\n").arg(m_player1Score).arg(m_player2Score).toUtf8());
    }else if(m_player2Score>m_player1Score)
    {
        qDebug()<<"player 2 wins the game.";
        historyP1.finalResult="Lost";
        historyP2.finalResult="Won";
        m_player2->write(QString("GAME_OVER;YOU_WON;FINAL_SCORE_%1-%2\n").arg(m_player2Score).arg(m_player1Score).toUtf8());
        m_player1->write(QString("GAME_OVER;YOU_LOST;FINAL_SCORE_%1-%2\n").arg(m_player2Score).arg(m_player1Score).toUtf8());
    }
    else
    {
        qDebug()<<"Game ended in a draw.";
        historyP1.finalResult="Draw";
        historyP2.finalResult="Draw";
        QString message=QString("GAME_OVER;DRAW;FINAL_SCORE_%1-%2\n").arg(m_player1Score).arg(m_player2Score);
        m_player1->write(message.toUtf8());
        m_player2->write(message.toUtf8());
    }
    emit gameFinished(m_player1Username,historyP1,m_player2Username,historyP2);
    this->deleteLater();
}
