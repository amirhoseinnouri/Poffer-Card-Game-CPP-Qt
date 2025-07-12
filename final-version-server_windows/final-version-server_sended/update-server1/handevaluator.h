#ifndef HANDEVALUATOR_H
#define HANDEVALUATOR_H
#include "HandName.h"
#include "card.h"
#include <QVector>
class HandEvaluator
{
private:
    bool isGoldenHand(const QVector<Card>& Hand);
    bool isOrderHand(const QVector<Card>& Hand);
    bool isFourPlusOneHand(const QVector<Card>& Hand);
    bool isPenthouseHand(const QVector<Card>& Hand);
    bool isMSCHand(const QVector<Card>& Hand);
    bool isSeries(const QVector<Card>& Hand);
    bool isThreePlusTwoHand(const QVector<Card>& Hand);
    bool isDoublePairHand(const QVector<Card>& Hand);
    bool isSinglePairHand(const QVector<Card>& Hand);

public:
    HandEvaluator();
    HandName HandEvaluate(QVector<Card>& hand);
};

#endif // HANDEVALUATOR_H
