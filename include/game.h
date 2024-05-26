#pragma once
#include <vector>
#include "deck.h"
#include "player.h"

using namespace std;

class Game {
private:
    Deck deck;
    Player player;
    Player ai;
    vector<Card> communityCards;
    void dealInitialCards();
    void dealCommunityCards();
    void clearHands();
public:
    Game();
    void playRound();
};
