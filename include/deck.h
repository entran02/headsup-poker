#pragma once
#include <vector>
#include "card.h"

using namespace std;

class Deck {
private:
    vector<Card> cards;
public:
    Deck();
    Card draw();
    void shuffle();
};
