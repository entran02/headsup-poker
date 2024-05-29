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

void testTwoPairSplit() {
    Game game;

    vector<Card> playerHand = {
        createCard(NINE, HEARTS),
        createCard(NINE, DIAMONDS)
    };

    vector<Card> aiHand = {
        createCard(EIGHT, CLUBS),
        createCard(EIGHT, SPADES)
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

    cout << "Two pair split test:" << endl;
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

void testSet() {
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
        createCard(ACE, HEARTS),
        createCard(KING, DIAMONDS),
        createCard(QUEEN, CLUBS),
        createCard(FIVE, SPADES),
        createCard(TWO, HEARTS)
    };

    game.setPlayerHand(playerHand);
    game.setAIHand(aiHand);
    game.setCommunityCards(communityCards);

    HandEvaluation playerEvaluation = game.testEvaluatePlayerHand();
    HandEvaluation aiEvaluation = game.testEvaluateAIHand();

    cout << "Set test:" << endl;
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

void testSetKicker() {
    Game game;

    vector<Card> playerHand = {
        createCard(ACE, HEARTS),
        createCard(KING, DIAMONDS)
    };

    vector<Card> aiHand = {
        createCard(ACE, CLUBS),
        createCard(QUEEN, SPADES)
    };

    vector<Card> communityCards = {
        createCard(ACE, HEARTS),
        createCard(JACK, DIAMONDS),
        createCard(ACE, CLUBS),
        createCard(FIVE, SPADES),
        createCard(TWO, HEARTS)
    };

    game.setPlayerHand(playerHand);
    game.setAIHand(aiHand);
    game.setCommunityCards(communityCards);

    HandEvaluation playerEvaluation = game.testEvaluatePlayerHand();
    HandEvaluation aiEvaluation = game.testEvaluateAIHand();

    cout << "Set kicker test:" << endl;
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

void testSetSplit() {
    Game game;

    vector<Card> playerHand = {
        createCard(ACE, HEARTS),
        createCard(NINE, DIAMONDS)
    };

    vector<Card> aiHand = {
        createCard(ACE, CLUBS),
        createCard(EIGHT, SPADES)
    };

    vector<Card> communityCards = {
        createCard(ACE, HEARTS),
        createCard(KING, DIAMONDS),
        createCard(ACE, CLUBS),
        createCard(QUEEN, SPADES),
        createCard(JACK, HEARTS)
    };

    game.setPlayerHand(playerHand);
    game.setAIHand(aiHand);
    game.setCommunityCards(communityCards);

    HandEvaluation playerEvaluation = game.testEvaluatePlayerHand();
    HandEvaluation aiEvaluation = game.testEvaluateAIHand();

    cout << "Set split test:" << endl;
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

void testStraightOverStraight() {
    Game game;

    vector<Card> playerHand = {
        createCard(JACK, HEARTS),
        createCard(ACE, DIAMONDS)
    };

    vector<Card> aiHand = {
        createCard(SIX, CLUBS),
        createCard(ACE, SPADES)
    };

    vector<Card> communityCards = {
        createCard(TEN, HEARTS),
        createCard(NINE, DIAMONDS),
        createCard(EIGHT, CLUBS),
        createCard(SEVEN, SPADES),
        createCard(TWO, HEARTS)
    };

    game.setPlayerHand(playerHand);
    game.setAIHand(aiHand);
    game.setCommunityCards(communityCards);

    HandEvaluation playerEvaluation = game.testEvaluatePlayerHand();
    HandEvaluation aiEvaluation = game.testEvaluateAIHand();

    cout << "Straight over straight test:" << endl;
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

void testStraightRiverSplit() {
    Game game;

    vector<Card> playerHand = {
        createCard(TEN, HEARTS),
        createCard(ACE, DIAMONDS)
    };

    vector<Card> aiHand = {
        createCard(SIX, CLUBS),
        createCard(ACE, SPADES)
    };

    vector<Card> communityCards = {
        createCard(TEN, HEARTS),
        createCard(NINE, DIAMONDS),
        createCard(EIGHT, CLUBS),
        createCard(SEVEN, SPADES),
        createCard(SIX, HEARTS)
    };

    game.setPlayerHand(playerHand);
    game.setAIHand(aiHand);
    game.setCommunityCards(communityCards);

    HandEvaluation playerEvaluation = game.testEvaluatePlayerHand();
    HandEvaluation aiEvaluation = game.testEvaluateAIHand();

    cout << "Straight River Split test:" << endl;
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

void testFlushOverStraight() {
    Game game;

    vector<Card> playerHand = {
        createCard(TWO, HEARTS),
        createCard(FIVE, HEARTS)
    };

    vector<Card> aiHand = {
        createCard(KING, CLUBS),
        createCard(ACE, SPADES)
    };

    vector<Card> communityCards = {
        createCard(TEN, HEARTS),
        createCard(JACK, DIAMONDS),
        createCard(QUEEN, HEARTS),
        createCard(SEVEN, HEARTS),
        createCard(SIX, HEARTS)
    };

    game.setPlayerHand(playerHand);
    game.setAIHand(aiHand);
    game.setCommunityCards(communityCards);

    HandEvaluation playerEvaluation = game.testEvaluatePlayerHand();
    HandEvaluation aiEvaluation = game.testEvaluateAIHand();

    cout << "Flush Over Straight test:" << endl;
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

void testHigherFlush() {
    Game game;

    vector<Card> playerHand = {
        createCard(TWO, HEARTS),
        createCard(ACE, HEARTS)
    };

    vector<Card> aiHand = {
        createCard(THREE, HEARTS),
        createCard(KING, HEARTS)
    };

    vector<Card> communityCards = {
        createCard(NINE, HEARTS),
        createCard(JACK, DIAMONDS),
        createCard(QUEEN, HEARTS),
        createCard(SEVEN, HEARTS),
        createCard(SIX, CLUBS)
    };

    game.setPlayerHand(playerHand);
    game.setAIHand(aiHand);
    game.setCommunityCards(communityCards);

    HandEvaluation playerEvaluation = game.testEvaluatePlayerHand();
    HandEvaluation aiEvaluation = game.testEvaluateAIHand();

    cout << "Higher Flush test:" << endl;
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

void testOneCardFlush() {
    Game game;

    vector<Card> playerHand = {
        createCard(TWO, CLUBS),
        createCard(ACE, HEARTS)
    };

    vector<Card> aiHand = {
        createCard(THREE, HEARTS),
        createCard(KING, HEARTS)
    };

    vector<Card> communityCards = {
        createCard(NINE, HEARTS),
        createCard(JACK, DIAMONDS),
        createCard(QUEEN, HEARTS),
        createCard(SEVEN, HEARTS),
        createCard(SIX, HEARTS)
    };

    game.setPlayerHand(playerHand);
    game.setAIHand(aiHand);
    game.setCommunityCards(communityCards);

    HandEvaluation playerEvaluation = game.testEvaluatePlayerHand();
    HandEvaluation aiEvaluation = game.testEvaluateAIHand();

    cout << "One Card Flush test:" << endl;
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

void testFlushSplit() {
    Game game;

    vector<Card> playerHand = {
        createCard(TWO, HEARTS),
        createCard(THREE, HEARTS)
    };

    vector<Card> aiHand = {
        createCard(FOUR, HEARTS),
        createCard(FIVE, HEARTS)
    };

    vector<Card> communityCards = {
        createCard(NINE, HEARTS),
        createCard(JACK, HEARTS),
        createCard(QUEEN, HEARTS),
        createCard(SEVEN, HEARTS),
        createCard(SIX, HEARTS)
    };

    game.setPlayerHand(playerHand);
    game.setAIHand(aiHand);
    game.setCommunityCards(communityCards);

    HandEvaluation playerEvaluation = game.testEvaluatePlayerHand();
    HandEvaluation aiEvaluation = game.testEvaluateAIHand();

    cout << "Flush Split test:" << endl;
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

void testFullOverFlush() {
    Game game;

    vector<Card> playerHand = {
        createCard(TWO, CLUBS),
        createCard(THREE, SPADES)
    };

    vector<Card> aiHand = {
        createCard(FOUR, HEARTS),
        createCard(FIVE, HEARTS)
    };

    vector<Card> communityCards = {
        createCard(TWO, HEARTS),
        createCard(THREE, DIAMONDS),
        createCard(QUEEN, CLUBS),
        createCard(SEVEN, HEARTS),
        createCard(THREE, HEARTS)
    };

    game.setPlayerHand(playerHand);
    game.setAIHand(aiHand);
    game.setCommunityCards(communityCards);

    HandEvaluation playerEvaluation = game.testEvaluatePlayerHand();
    HandEvaluation aiEvaluation = game.testEvaluateAIHand();

    cout << "Flush Split test:" << endl;
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

void testFullOverFull() {
    Game game;

    vector<Card> playerHand = {
        createCard(THREE, CLUBS),
        createCard(TWO, SPADES)
    };

    vector<Card> aiHand = {
        createCard(TWO, HEARTS),
        createCard(TWO, DIAMONDS)
    };

    vector<Card> communityCards = {
        createCard(TWO, HEARTS),
        createCard(THREE, DIAMONDS),
        createCard(SIX, CLUBS),
        createCard(SEVEN, DIAMONDS),
        createCard(THREE, SPADES)
    };

    game.setPlayerHand(playerHand);
    game.setAIHand(aiHand);
    game.setCommunityCards(communityCards);

    HandEvaluation playerEvaluation = game.testEvaluatePlayerHand();
    HandEvaluation aiEvaluation = game.testEvaluateAIHand();

    cout << "Full over full test:" << endl;
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

void testQuadsOverFull() {
    Game game;

    vector<Card> playerHand = {
        createCard(TWO, CLUBS),
        createCard(TWO, SPADES)
    };

    vector<Card> aiHand = {
        createCard(THREE, HEARTS),
        createCard(TWO, DIAMONDS)
    };

    vector<Card> communityCards = {
        createCard(TWO, HEARTS),
        createCard(TWO, DIAMONDS),
        createCard(SIX, CLUBS),
        createCard(SEVEN, DIAMONDS),
        createCard(THREE, SPADES)
    };

    game.setPlayerHand(playerHand);
    game.setAIHand(aiHand);
    game.setCommunityCards(communityCards);

    HandEvaluation playerEvaluation = game.testEvaluatePlayerHand();
    HandEvaluation aiEvaluation = game.testEvaluateAIHand();

    cout << "Quads over full test:" << endl;
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

void testQuadsOverQuads() {
    Game game;

    vector<Card> playerHand = {
        createCard(THREE, CLUBS),
        createCard(THREE, SPADES)
    };

    vector<Card> aiHand = {
        createCard(ACE, HEARTS),
        createCard(TWO, HEARTS)
    };

    vector<Card> communityCards = {
        createCard(THREE, HEARTS),
        createCard(THREE, DIAMONDS),
        createCard(TWO, CLUBS),
        createCard(TWO, DIAMONDS),
        createCard(TWO, SPADES)
    };

    game.setPlayerHand(playerHand);
    game.setAIHand(aiHand);
    game.setCommunityCards(communityCards);

    HandEvaluation playerEvaluation = game.testEvaluatePlayerHand();
    HandEvaluation aiEvaluation = game.testEvaluateAIHand();

    cout << "Quads over quads test:" << endl;
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

void testStraightFlushOverQuads() {
    Game game;

    vector<Card> playerHand = {
        createCard(ACE, HEARTS),
        createCard(TWO, HEARTS)
    };

    vector<Card> aiHand = {
        createCard(THREE, SPADES),
        createCard(THREE, CLUBS)
    };

    vector<Card> communityCards = {
        createCard(THREE, HEARTS),
        createCard(THREE, DIAMONDS),
        createCard(FOUR, HEARTS),
        createCard(FIVE, HEARTS),
        createCard(ACE, SPADES)
    };

    game.setPlayerHand(playerHand);
    game.setAIHand(aiHand);
    game.setCommunityCards(communityCards);

    HandEvaluation playerEvaluation = game.testEvaluatePlayerHand();
    HandEvaluation aiEvaluation = game.testEvaluateAIHand();

    cout << "SF over quads test:" << endl;
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

void testStraightFlushOverStraightFlush() {
    Game game;

    vector<Card> playerHand = {
        createCard(SIX, HEARTS),
        createCard(SEVEN, HEARTS)
    };

    vector<Card> aiHand = {
        createCard(TWO, HEARTS),
        createCard(ACE, HEARTS)
    };

    vector<Card> communityCards = {
        createCard(THREE, HEARTS),
        createCard(FOUR, HEARTS),
        createCard(FIVE, HEARTS),
        createCard(KING, HEARTS),
        createCard(QUEEN, HEARTS)
    };

    game.setPlayerHand(playerHand);
    game.setAIHand(aiHand);
    game.setCommunityCards(communityCards);

    HandEvaluation playerEvaluation = game.testEvaluatePlayerHand();
    HandEvaluation aiEvaluation = game.testEvaluateAIHand();

    cout << "SF over SF test:" << endl;
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

void testRoyalFlushOverStraightFlush() {
    Game game;

    vector<Card> playerHand = {
        createCard(KING, HEARTS),
        createCard(ACE, HEARTS)
    };

    vector<Card> aiHand = {
        createCard(EIGHT, HEARTS),
        createCard(NINE, HEARTS)
    };

    vector<Card> communityCards = {
        createCard(TEN, HEARTS),
        createCard(JACK, HEARTS),
        createCard(QUEEN, HEARTS),
        createCard(EIGHT, DIAMONDS),
        createCard(EIGHT, CLUBS)
    };

    game.setPlayerHand(playerHand);
    game.setAIHand(aiHand);
    game.setCommunityCards(communityCards);

    HandEvaluation playerEvaluation = game.testEvaluatePlayerHand();
    HandEvaluation aiEvaluation = game.testEvaluateAIHand();
    
    cout << "RF over SF test:" << endl;
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
    testTwoPairSplit();
    testSet();
    testSetKicker();
    testSetSplit();
    testStraightOverStraight();
    testStraightRiverSplit();
    testFlushOverStraight();
    testHigherFlush();
    testOneCardFlush();
    testFlushSplit();
    testFullOverFlush();
    testFullOverFull();
    testQuadsOverFull();
    testQuadsOverQuads();
    testStraightFlushOverQuads();
    testStraightFlushOverStraightFlush();
    testRoyalFlushOverStraightFlush();
}

int main() {
    runTests();
    return 0;
}
