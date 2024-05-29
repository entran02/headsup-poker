#include <iostream>
#include <vector>
#include "../include/card.h"
#include "../include/game.h"
#include "../include/hand_evaluator.h"

using namespace std;

Card createCard(Rank rank, Suit suit) {
    return Card(suit, rank);
}

void printHandEvaluation(const string& name, const HandEvaluation& evaluation) {
    cout << name << "'s best hand: " << handRankToString(evaluation.rank) << " with ranks: ";
    for (const auto& rank : evaluation.ranks) {
        cout << rank << " ";
    }
    cout << endl;
}

void testHighCard() {
    Game game;

    vector<Card> playerHand = {
        createCard(ACE, HEARTS),
        createCard(KING, DIAMONDS)
    };

    vector<Card> aiHand = {
        createCard(QUEEN, CLUBS),
        createCard(JACK, SPADES)
    };

    vector<Card> communityCards = {
        createCard(FOUR, HEARTS),
        createCard(NINE, DIAMONDS),
        createCard(EIGHT, CLUBS),
        createCard(SEVEN, SPADES),
        createCard(FIVE, HEARTS)
    };

    game.setPlayerHand(playerHand);
    game.setAIHand(aiHand);
    game.setCommunityCards(communityCards);

    HandEvaluation playerEvaluation = game.testEvaluatePlayerHand();
    HandEvaluation aiEvaluation = game.testEvaluateAIHand();

    cout << "High card test:" << endl;
    printHandEvaluation("Player", playerEvaluation);
    printHandEvaluation("AI", aiEvaluation);
    if (playerEvaluation.rank > aiEvaluation.rank) {
        cout << "Player wins\n\n";
    } else if (aiEvaluation.rank > playerEvaluation.rank) {
        cout << "AI wins\n\n";
    } else {
        if (playerEvaluation.ranks > aiEvaluation.ranks) {
            cout << "Player wins\n\n";
        } else if (aiEvaluation.ranks > playerEvaluation.ranks) {
            cout << "AI wins\n\n";
        } else {
            cout << "It's a tie\n\n";
        }
    }
}

void testHighCardSplit() {
    Game game;

    vector<Card> playerHand = {
        createCard(ACE, HEARTS),
        createCard(THREE, DIAMONDS)
    };

    vector<Card> aiHand = {
        createCard(ACE, CLUBS),
        createCard(TWO, SPADES)
    };

    vector<Card> communityCards = {
        createCard(TEN, HEARTS),
        createCard(NINE, DIAMONDS),
        createCard(EIGHT, CLUBS),
        createCard(SEVEN, SPADES),
        createCard(FIVE, HEARTS)
    };

    game.setPlayerHand(playerHand);
    game.setAIHand(aiHand);
    game.setCommunityCards(communityCards);

    HandEvaluation playerEvaluation = game.testEvaluatePlayerHand();
    HandEvaluation aiEvaluation = game.testEvaluateAIHand();

    cout << "High card split test:" << endl;
    printHandEvaluation("Player", playerEvaluation);
    printHandEvaluation("AI", aiEvaluation);
    if (playerEvaluation.rank > aiEvaluation.rank) {
        cout << "Player wins\n\n";
    } else if (aiEvaluation.rank > playerEvaluation.rank) {
        cout << "AI wins\n\n";
    } else {
        if (playerEvaluation.ranks > aiEvaluation.ranks) {
            cout << "Player wins\n\n";
        } else if (aiEvaluation.ranks > playerEvaluation.ranks) {
            cout << "AI wins\n\n";
        } else {
            cout << "It's a tie\n\n";
        }
    }
}

void testPairComparison() {
    Game game;

    vector<Card> playerHand = {
        createCard(ACE, HEARTS),
        createCard(ACE, DIAMONDS)
    };

    vector<Card> aiHand = {
        createCard(KING, CLUBS),
        createCard(KING, SPADES)
    };

    vector<Card> communityCards = {
        createCard(QUEEN, HEARTS),
        createCard(JACK, DIAMONDS),
        createCard(TEN, CLUBS),
        createCard(FIVE, SPADES),
        createCard(TWO, HEARTS)
    };

    game.setPlayerHand(playerHand);
    game.setAIHand(aiHand);
    game.setCommunityCards(communityCards);

    HandEvaluation playerEvaluation = game.testEvaluatePlayerHand();
    HandEvaluation aiEvaluation = game.testEvaluateAIHand();

    cout << "Pair test:" << endl;
    printHandEvaluation("Player", playerEvaluation);
    printHandEvaluation("AI", aiEvaluation);
    if (playerEvaluation.rank > aiEvaluation.rank) {
        cout << "Player wins\n\n";
    } else if (aiEvaluation.rank > playerEvaluation.rank) {
        cout << "AI wins\n\n";
    } else {
        if (playerEvaluation.ranks > aiEvaluation.ranks) {
            cout << "Player wins\n\n";
        } else if (aiEvaluation.ranks > playerEvaluation.ranks) {
            cout << "AI wins\n\n";
        } else {
            cout << "It's a tie\n\n";
        }
    }
}

void testPairSplit() {
    Game game;

    vector<Card> playerHand = {
        createCard(ACE, HEARTS),
        createCard(ACE, DIAMONDS)
    };

    vector<Card> aiHand = {
        createCard(ACE, CLUBS),
        createCard(ACE, SPADES)
    };

    vector<Card> communityCards = {
        createCard(KING, HEARTS),
        createCard(QUEEN, DIAMONDS),
        createCard(FOUR, CLUBS),
        createCard(TEN, SPADES),
        createCard(FIVE, HEARTS)
    };

    game.setPlayerHand(playerHand);
    game.setAIHand(aiHand);
    game.setCommunityCards(communityCards);

    HandEvaluation playerEvaluation = game.testEvaluatePlayerHand();
    HandEvaluation aiEvaluation = game.testEvaluateAIHand();

    cout << "Pair split test:" << endl;
    printHandEvaluation("Player", playerEvaluation);
    printHandEvaluation("AI", aiEvaluation);
    if (playerEvaluation.rank > aiEvaluation.rank) {
        cout << "Player wins\n\n";
    } else if (aiEvaluation.rank > playerEvaluation.rank) {
        cout << "AI wins\n\n";
    } else {
        if (playerEvaluation.ranks > aiEvaluation.ranks) {
            cout << "Player wins\n\n";
        } else if (aiEvaluation.ranks > playerEvaluation.ranks) {
            cout << "AI wins\n\n";
        } else {
            cout << "It's a tie\n\n";
        }
    }

}

void testPairRiverHighCard() {
    Game game;

    vector<Card> playerHand = {
        createCard(THREE, HEARTS),
        createCard(ACE, DIAMONDS)
    };

    vector<Card> aiHand = {
        createCard(KING, CLUBS),
        createCard(TWO, SPADES)
    };

    vector<Card> communityCards = {
        createCard(QUEEN, HEARTS),
        createCard(QUEEN, DIAMONDS),
        createCard(TEN, CLUBS),
        createCard(FIVE, SPADES),
        createCard(FOUR, HEARTS)
    };

    game.setPlayerHand(playerHand);
    game.setAIHand(aiHand);
    game.setCommunityCards(communityCards);

    HandEvaluation playerEvaluation = game.testEvaluatePlayerHand();
    HandEvaluation aiEvaluation = game.testEvaluateAIHand();

    cout << "Pair river high card test:" << endl;
    printHandEvaluation("Player", playerEvaluation);
    printHandEvaluation("AI", aiEvaluation);
    if (playerEvaluation.rank > aiEvaluation.rank) {
        cout << "Player wins\n\n";
    } else if (aiEvaluation.rank > playerEvaluation.rank) {
        cout << "AI wins\n\n";
    } else {
        if (playerEvaluation.ranks > aiEvaluation.ranks) {
            cout << "Player wins\n\n";
        } else if (aiEvaluation.ranks > playerEvaluation.ranks) {
            cout << "AI wins\n\n";
        } else {
            cout << "It's a tie\n\n";
        }
    }
}

void testPairRiverSplit() {
    Game game;

    vector<Card> playerHand = {
        createCard(TWO, HEARTS),
        createCard(THREE, DIAMONDS)
    };

    vector<Card> aiHand = {
        createCard(TWO, CLUBS),
        createCard(FOUR, SPADES)
    };

    vector<Card> communityCards = {
        createCard(KING, HEARTS),
        createCard(KING, DIAMONDS),
        createCard(QUEEN, CLUBS),
        createCard(JACK, SPADES),
        createCard(TEN, HEARTS)
    };

    game.setPlayerHand(playerHand);
    game.setAIHand(aiHand);
    game.setCommunityCards(communityCards);

    HandEvaluation playerEvaluation = game.testEvaluatePlayerHand();
    HandEvaluation aiEvaluation = game.testEvaluateAIHand();

    cout << "Pair river split test:" << endl;
    printHandEvaluation("Player", playerEvaluation);
    printHandEvaluation("AI", aiEvaluation);
    if (playerEvaluation.rank > aiEvaluation.rank) {
        cout << "Player wins\n\n";
    } else if (aiEvaluation.rank > playerEvaluation.rank) {
        cout << "AI wins\n\n";
    } else {
        if (playerEvaluation.ranks > aiEvaluation.ranks) {
            cout << "Player wins\n\n";
        } else if (aiEvaluation.ranks > playerEvaluation.ranks) {
            cout << "AI wins\n\n";
        } else {
            cout << "It's a tie\n\n";
        }
    }

}

// test for two pair
void testTwoPairComparison() {
    Game game;

    vector<Card> playerHand = {
        createCard(ACE, HEARTS),
        createCard(ACE, DIAMONDS)
    };

    vector<Card> aiHand = {
        createCard(ACE, CLUBS),
        createCard(NINE, SPADES)
    };

    vector<Card> communityCards = {
        createCard(KING, HEARTS),
        createCard(KING, DIAMONDS),
        createCard(QUEEN, CLUBS),
        createCard(QUEEN, SPADES),
        createCard(TEN, HEARTS)
    };

    game.setPlayerHand(playerHand);
    game.setAIHand(aiHand);
    game.setCommunityCards(communityCards);

    HandEvaluation playerEvaluation = game.testEvaluatePlayerHand();
    HandEvaluation aiEvaluation = game.testEvaluateAIHand();
    
    cout << "Two pair test:" << endl;
    printHandEvaluation("Player", playerEvaluation);
    printHandEvaluation("AI", aiEvaluation);
    if (playerEvaluation.rank > aiEvaluation.rank) {
        cout << "Player wins\n\n";
    } else if (aiEvaluation.rank > playerEvaluation.rank) {
        cout << "AI wins\n\n";
    } else {
        if (playerEvaluation.ranks > aiEvaluation.ranks) {
            cout << "Player wins\n\n";
        } else if (aiEvaluation.ranks > playerEvaluation.ranks) {
            cout << "AI wins\n\n";
        } else {
            cout << "It's a tie\n\n";
        }
    }
}

void runTests() {
    testHighCard();
    testHighCardSplit();
    testPairComparison();
    testPairSplit();
    testPairRiverHighCard();
    testPairRiverSplit();
    testTwoPairComparison();
}

int main() {
    runTests();
    return 0;
}
