#include "../include/game.h"
#include <iostream>

using namespace std;

Game::Game() : player(1000), ai(1000), pot(0), currentBet(0) {} // Both players start with 1000 chips

void Game::dealInitialCards() {
    player.receiveCard(deck.draw());
    player.receiveCard(deck.draw());
    ai.receiveCard(deck.draw());
    ai.receiveCard(deck.draw());
}

void Game::dealCommunityCards(int numCards) {
    for (int i = 0; i < numCards; ++i) {
        communityCards.push_back(deck.draw());
    }
}

void Game::clearHands() {
    player.clearHand();
    ai.clearHand();
    communityCards.clear();
    pot = 0;
    currentBet = 0;
}

void Game::bettingRound() {
    currentBet = 0;
    playerAction();
    if (!player.folded) {
        aiAction();
    }
    if (player.folded) {
        cout << "Player folds. AI wins " << pot << " chips." << endl;
        ai.chips += pot;
    } else if (ai.folded) {
        cout << "AI folds. Player wins " << pot << " chips." << endl;
        player.chips += pot;
    } else {
        cout << "Both players call. Pot is " << pot << endl;
    }
}

void Game::playerAction() {
    char action;
    cout << "Player's turn. Choose an action: (c)heck, (r)aise, (f)old: ";
    cin >> action;
    switch (action) {
        case 'c':
            cout << "Player checks.\n";
            break;
        case 'r': {
            int raiseAmount;
            cout << "Enter raise amount: ";
            cin >> raiseAmount;
            player.bet(raiseAmount);
            pot += raiseAmount;
            currentBet = raiseAmount;
            cout << "Player raises " << raiseAmount << "." << endl;
            break;
        }
        case 'f':
            player.fold();
            break;
        default:
            cout << "Invalid action. Player checks.\n";
            break;
    }
}

void Game::aiAction() {
    // improve ai decision making. for now calls or fold on random lmao.
    if (rand() % 2 == 0) {
        int callAmount = currentBet;
        ai.bet(callAmount);
        pot += callAmount;
        cout << "AI calls with " << callAmount << " chips.\n";
    } else {
        ai.fold();
        cout << "AI folds.\n";
    }
}

void Game::playRound() {
    clearHands();
    dealInitialCards();

    // pre-flop
    cout << "Pre-flop betting round.\n";
    cout << "Player's Hand: ";
    for (const auto& card : player.hand) {
        cout << card.toString() << " ";
    }
    bettingRound();
    if (player.folded || ai.folded) return;

    // flop
    cout << "Player's Hand: ";
    for (const auto& card : player.hand) {
        cout << card.toString() << " ";
    }
    cout << "Flop: ";
    dealCommunityCards(3);
    for (const auto& card : communityCards) {
        cout << card.toString() << " ";
    }
    cout << "\nFlop betting round.\n";
    bettingRound();
    if (player.folded || ai.folded) return;
    
    // turn
    cout << "Player's Hand: ";
    for (const auto& card : player.hand) {
        cout << card.toString() << " ";
    }
    cout << "Turn: ";
    dealCommunityCards(1);
    for (const auto& card : communityCards) {
        cout << card.toString() << " ";
    }
    cout << "\nTurn betting round.\n";
    bettingRound();
    if (player.folded || ai.folded) return;
    
    // river
    cout << "Player's Hand: ";
    for (const auto& card : player.hand) {
        cout << card.toString() << " ";
    }
    cout << "River: ";
    dealCommunityCards(1);
    for (const auto& card : communityCards) {
        cout << card.toString() << " ";
    }
    cout << "\nRiver betting round.\n";
    bettingRound();
    if (player.folded || ai.folded) return;

    // showdown
    cout << "Showdown: Both players reveal their hands.\n";
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
    cout << "\nPot is " << pot << " chips.\n";

    // add hand evaluation logic here to determine the winner.
    // pot is just split for now
    cout << "Pot is split between player and AI.\n";
    player.chips += pot / 2;
    ai.chips += pot / 2;
}

bool Game::playerHasChips() const {
    return player.chips > 0;
}

bool Game::aiHasChips() const {
    return ai.chips > 0;
}

void Game::displayChips() const {
    cout << "Player has " << player.chips << " chips.\n";
    cout << "AI has " << ai.chips << " chips.\n";
}