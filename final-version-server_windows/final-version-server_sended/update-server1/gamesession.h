#ifndef GAMESESSION_H
#define GAMESESSION_H

#include <QObject>
#include "deck.h"
#include <QTcpSocket>
#include "card.h"
#include <QVector>
#include "HandName.h"
#include "handevaluator.h"
#include "server.h"
class GameSession:public QObject
{
    Q_OBJECT
private:
    QTcpSocket* m_player1;
    QTcpSocket* m_player2;
    Deck m_deck;
    int m_player1Score;
    int m_player2Score;
    int m_currentRound;
    QTcpSocket* m_currentPlayer;
    QVector<Card> m_player1Hand;
    QVector<Card> m_player2Hand;
    int m_turnCounter;
    QList<Card> m_currentDealtCards;
    void dealRemainingCardsTCurrentPlayer();
    void processNextTurn();
    void dealCardsToCurrentPlayer();
    int m_dealCounter;
    QTcpSocket* m_turnStarter;
     void endRound();
    void endGame();
     QString m_player1Username;
    QString m_player2Username;
     QList<QString> m_roundResults;
public:
    GameSession(QTcpSocket* player1,QString player1Username,QTcpSocket* player2,QString player2Username,QObject *parent=nullptr);
    void startNewRound();
    void startGame();
private slots:
    void playerMessage();
signals:
    void gameFinished(const QString & player1Username,const GameHistory& historyForP1,const QString& player2Username,const GameHistory & historyForP2);
};

#endif // GAMESESSION_H
