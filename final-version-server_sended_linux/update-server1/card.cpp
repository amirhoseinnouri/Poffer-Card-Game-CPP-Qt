#include "card.h"

Card::Card(Rank rank,Suit suit) :rank(rank),suit(suit){

}
Suit Card::getSuit() const
{
    return suit;
}
Rank Card::getRank()const
{
    return rank;
}
bool Card::operator=(const Card& c)
{
    return c.rank==rank&&c.suit==suit;
}

// just need some change and add base game rules 