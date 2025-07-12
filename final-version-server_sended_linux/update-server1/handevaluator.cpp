#include "handevaluator.h"
#include <algorithm>
HandEvaluator::HandEvaluator() {}
 HandName HandEvaluator::HandEvaluate(QVector<Card>& hand)
{
    std::sort(hand.begin(),hand.end(),[](Card& a,Card& b)
              {
        return a.getRank()<b.getRank();
    });
    if(isGoldenHand(hand))
        return HandName::GoldenHand;
    if(isOrderHand(hand))
        return HandName::OrderHand;
    if(isFourPlusOneHand(hand))
        return HandName::FourPlusOneHand;
    if(isPenthouseHand(hand))
        return HandName::PenthouseHand;
    if(isMSCHand(hand))
        return HandName::MSCHand;
    if(isSeries(hand))
        return HandName::Series;
    if(isThreePlusTwoHand(hand))
        return HandName::ThreePlusTwoHand;
    if(isDoublePairHand(hand))
        return HandName::DoublePairHand;
    if(isSinglePairHand(hand))
        return HandName::SinglePairHand;
    return HandName::MessyHand;
}
bool  HandEvaluator::isGoldenHand(const QVector<Card>& Hand)
{
    for(auto i=0;i<Hand.size()-1;++i)
    {
        if(Hand[i].getSuit()!=Hand[i+1].getSuit())
            return false;
    }
    if(Hand[0].getRank()==Rank::Ten&&Hand[4].getRank()==Rank::Bitcoin)
        return true;
    return false;
}
bool  HandEvaluator::isOrderHand(const QVector<Card>& Hand)
{
    for(auto i=0;i<Hand.size()-1;++i)
    {
        if(Hand[i].getSuit()!=Hand[i+1].getSuit())
            return false;
    }
    if(isSeries(Hand))
        return true;
    return false;
}
bool HandEvaluator::isFourPlusOneHand(const QVector<Card>& Hand)
{
    //the kiker can be the fist or the last due to the sorted cards in rank i have two case
    bool case1=Hand[1].getRank()==Hand[4].getRank();
    bool case2=Hand[0].getRank()==Hand[3].getRank();
    return case1||case2;

}
bool HandEvaluator::isPenthouseHand(const QVector<Card>& hand)
{
    //it also has two cases three comes fist or two comes
    bool case1=(hand[0].getRank()==hand[2].getRank())&&(hand[3].getRank()==hand[4].getRank());
    bool case2=(hand[0].getRank()==hand[1].getRank())&&(hand[2].getRank()==hand[4].getRank());
    return case1||case2;
}
bool HandEvaluator::isMSCHand(const QVector<Card>& Hand)
{
    for(auto i=0;i<Hand.size()-1;++i)
    {
        if(Hand[i].getSuit()!=Hand[i+1].getSuit())
        {
            return false;
        }
    }
    return true;
}
bool HandEvaluator::isSeries(const QVector<Card>& Hand)
{
    for(auto i=0;i<Hand.size();++i)
    {
        if(Hand[i].getRank()+1!=Hand[i+1].getRank())
            return false;
    }
    return true;
}
bool HandEvaluator::isThreePlusTwoHand(const QVector<Card>& hand)
{
    //there is 3 cases three same rank cards can be in first , middle or end
    bool case1=hand[0].getRank()==hand[2].getRank();
    bool case2=hand[1].getRank()==hand[3].getRank();
    bool case3=hand[2].getRank()==hand[4].getRank();
    return case1||case2||case3;
}
bool HandEvaluator::isDoublePairHand(const QVector<Card>& hand)
{
    bool case1=(hand[0].getRank()==hand[1].getRank())&&(hand[2].getRank()==hand[3].getRank());
    bool case2=(hand[0].getRank()==hand[1].getRank())&&(hand[3].getRank()==hand[4].getRank());
    bool case3=(hand[1].getRank()==hand[2].getRank())&&(hand[3].getRank()==hand[4].getRank());
    return case1||case2||case3;
}
bool HandEvaluator::isSinglePairHand(const QVector<Card>& hand)
{
    for(int i=0;i<hand.size()-1;++i)
    {
        if(hand[i].getRank()==hand[i+1].getRank())
            return true;
    }
    return false;
}
