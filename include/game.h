#pragma once
#include <vector>
#include "deck.h"
#include "player.h"
#include "hand_evaluator.h"

using namespace std;

class Game {
private:
    Deck deck;
    Player player;
    Player ai;
    vector<Card> communityCards;
    int pot;
    int currentBet;
    bool playerIsDealer;
    void dealInitialCards();
    void dealCommunityCards(int numCards);
    void displayPlayerHand();
    void clearHands();
    void preFlopBettingRound();
    void postFlopBettingRound();
    void playerAction();
    void aiAction();
    void switchDealer();
    void postBlinds();
    HandEvaluation evaluatePlayerHand() const;
    HandEvaluation evaluateAIHand() const;
public:
    Game();
    void playRound();
    bool playerHasChips() const;
    bool aiHasChips() const;
    void displayChips() const;
};
