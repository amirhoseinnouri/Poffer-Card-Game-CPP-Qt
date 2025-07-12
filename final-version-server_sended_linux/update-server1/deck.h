#ifndef DECK_H
#define DECK_H
#include "card.h"
#include <vector>
class Deck
{
private:
    std::vector<Card> cards;
public:
    Deck();
    void Shuffle();
    Card deal();
    void restart();
    Card dealOneDiamondCard();

};

#endif


// just need some change 
