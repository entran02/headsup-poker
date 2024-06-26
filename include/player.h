#pragma once
#include <vector>
#include "card.h"

using namespace std;

class Player {
public:
    vector<Card> hand;
    int chips;
    bool folded;
    Player(int c);
    void receiveCard(Card c);
    void clearHand();
    void bet(int amount);
    void fold();
};
