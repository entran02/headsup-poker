#include "../include/game.h"
#include <iostream>

using namespace std;

Game::Game() : player(1000), ai(1000), pot(0), currentBet(0), playerIsDealer(true) {} // Both players start with 1000 chips

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

void Game::displayPlayerHand(){
    cout << "Player's Hand: ";
    for (const auto& card : player.hand) {
        cout << card.toString() << " ";
    }
    cout << endl;
}

void Game::clearHands() {
    player.clearHand();
    ai.clearHand();
    communityCards.clear();
    pot = 0;
    currentBet = 0;
}

void Game::preFlopBettingRound() {
    currentBet = 0;
    if (playerIsDealer) {
        playerAction();
        if (!player.folded) aiAction();
    } else {
        aiAction();
        if (!ai.folded) playerAction();
    }
    if (player.folded) {
        cout << "Player folds. AI wins the pot of " << pot << " chips.\n";
        ai.chips += pot;
    } else if (ai.folded) {
        cout << "AI folds. Player wins the pot of " << pot << " chips.\n";
        player.chips += pot;
    } else {
        cout << "Both players call. Pot is now " << pot << " chips.\n";
    }
}

void Game::postFlopBettingRound() {
    currentBet = 0;
    if (playerIsDealer) {
        aiAction();
        if (!ai.folded) playerAction();
    } else {
        playerAction();
        if (!player.folded) aiAction();
    }
    if (player.folded) {
        cout << "Player folds. AI wins the pot of " << pot << " chips.\n";
        ai.chips += pot;
    } else if (ai.folded) {
        cout << "AI folds. Player wins the pot of " << pot << " chips.\n";
        player.chips += pot;
    } else {
        cout << "Both players call. Pot is now " << pot << " chips.\n";
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
    }
}

void Game::switchDealer() {
    playerIsDealer = !playerIsDealer;
}

void Game::postBlinds() {
    int blindAmount = 20;
    player.bet(blindAmount);
    ai.bet(blindAmount);
    pot += 2 * blindAmount;
    cout << (playerIsDealer ? "player" : "AI") << " is dealer" << "\n";
    cout << "20 chip blind is posted by both players. Pot is " << pot << " chips.\n";
}

void Game::playRound() {
    clearHands();
    postBlinds();
    dealInitialCards();

    // pre-flop
    cout << "Pre-flop betting round.\n";
    displayPlayerHand();
    preFlopBettingRound();
    if (player.folded || ai.folded) {
        switchDealer();
        return;
    }

    // flop
    displayPlayerHand();
    cout << "Flop: ";
    dealCommunityCards(3);
    for (const auto& card : communityCards) {
        cout << card.toString() << " ";
    }
    cout << "\nFlop betting round.\n";
    postFlopBettingRound();
    if (player.folded || ai.folded) {
        switchDealer();
        return;
    }
    
    // turn
    displayPlayerHand();
    cout << "Turn: ";
    dealCommunityCards(1);
    for (const auto& card : communityCards) {
        cout << card.toString() << " ";
    }
    cout << "\nTurn betting round.\n";
    postFlopBettingRound();
    if (player.folded || ai.folded) {
        switchDealer();
        return;
    }
    
    // river
    displayPlayerHand();
    cout << "River: ";
    dealCommunityCards(1);
    for (const auto& card : communityCards) {
        cout << card.toString() << " ";
    }
    cout << "\nRiver betting round.\n";
    postFlopBettingRound();
    if (player.folded || ai.folded) {
        switchDealer();
        return;
    }

    // showdown
    cout << "Showdown: Both players reveal their hands.\n";
    displayPlayerHand();
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

    switchDealer();
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