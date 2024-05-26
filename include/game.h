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
    int pot;
    int currentBet;
    void dealInitialCards();
    void dealCommunityCards(int numCards);
    void clearHands();
    void bettingRound();
    void playerAction();
    void aiAction();
public:
    Game();
    void playRound();
    bool playerHasChips() const;
    bool aiHasChips() const;
    void displayChips() const;
};
