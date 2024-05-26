#include "../include/game.h"
#include <iostream>

using namespace std;

Game::Game() : player(1000), ai(1000) {} // Both players start with 1000 chips

void Game::dealInitialCards() {
    player.receiveCard(deck.draw());
    player.receiveCard(deck.draw());
    ai.receiveCard(deck.draw());
    ai.receiveCard(deck.draw());
}

void Game::dealCommunityCards() {
    for (int i = 0; i < 5; ++i) {
        communityCards.push_back(deck.draw());
    }
}

void Game::clearHands() {
    player.clearHand();
    ai.clearHand();
    communityCards.clear();
}

void Game::playRound() {
    clearHands();
    dealInitialCards();
    dealCommunityCards();

    cout << "Player's Hand: ";
    for (const auto& card : player.hand) {
        cout << card.toString() << " ";
    }
    cout << "\nAI's Hand: ";
    for (const auto& card : ai.hand) {
        cout << card.toString() << " ";
    }
    cout << "\nCommunity Cards: ";
    for (const auto& card : communityCards) {
        cout << card.toString() << " ";
    }
    cout << endl;

    // Implement betting logic and AI decision making here
}
