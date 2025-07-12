#include "deck.h"
#include <random>
#include <algorithm>
#include <stdexcept>
Deck::Deck() {
    restart();
}
void Deck::restart()
{
    cards.clear();
    auto suits={Suit::Coin,Suit::Diamond,Suit::Dollar,Suit::Gold};
    auto ranks={Rank::Two,Rank::Three,Rank::Four,Rank::Five,Rank::Six,Rank::Seven,Rank::Eight,Rank::Nine,Rank::Ten,Rank::Soldier,Rank::Bitcoin
                  ,Rank::King,Rank::Queen};
    for(Suit suit:suits)
    {
        for(Rank rank:ranks)
        {
            cards.push_back(Card(rank,suit));
        }
    }
    Shuffle();
}

void Deck::Shuffle()
{
    std::random_device rand;
    std::mt19937 g(rand());
    std::shuffle(cards.begin(),cards.end(),g);
}
Card Deck::deal()
{
    if(cards.empty())
    {
        throw std::runtime_error("Empty cards, Error to deal!");
    }
    Card card=cards.back();
    cards.pop_back();
    return card;
}
 Card Deck::dealOneDiamondCard()
{
     std::vector<Card> diamondDeck;
    auto ranks={Rank::Two,Rank::Three,Rank::Four,Rank::Five,Rank::Six,Rank::Seven,Rank::Eight,Rank::Nine,Rank::Ten,Rank::Soldier,Rank::Bitcoin
                  ,Rank::King,Rank::Queen};
     for(Rank rank:ranks)
    {
        diamondDeck.emplace_back(rank,Suit::Diamond);
     }
     std::random_device rnd;
     std::mt19937 g(rnd());
     std::shuffle(diamondDeck.begin(),diamondDeck.end(),g);
     Card card=diamondDeck.back();
     diamondDeck.pop_back();
     return card;
}


//just need some change 