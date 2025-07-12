#ifndef CARD_H
#define CARD_H
enum Suit{Diamond,Dollar,Coin,Gold};
enum Rank{Two,Three,Four,Five,Six,Seven,Eight,Nine,Ten,Soldier,Queen,King,Bitcoin};
class Card
{
private:
    Suit suit;
    Rank rank;
public:
    Card(Rank rank,Suit suit);
    Suit getSuit()const;
    Rank getRank()const;
    bool operator=(const Card & c);
};

#endif 
