#pragma once
#include <string>

enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
enum Rank { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE };

class Card {
public:
    Suit suit;
    Rank rank;
    Card(Suit s, Rank r) : suit(s), rank(r) {}

    std::string getSuitString() const {
        switch (suit) {
            case HEARTS: return "Hearts";
            case DIAMONDS: return "Diamonds";
            case CLUBS: return "Clubs";
            case SPADES: return "Spades";
            default: return "Unknown";
        }
    }

    std::string getRankString() const {
        switch (rank) {
            case TWO: return "2";
            case THREE: return "3";
            case FOUR: return "4";
            case FIVE: return "5";
            case SIX: return "6";
            case SEVEN: return "7";
            case EIGHT: return "8";
            case NINE: return "9";
            case TEN: return "10";
            case JACK: return "J";
            case QUEEN: return "Q";
            case KING: return "K";
            case ACE: return "A";
            default: return "Unknown";
        }
    }

    std::string toString() const {
        return getRankString() + " of " + getSuitString();
    }

    bool operator<(const Card& other) const {
        return rank < other.rank;
    }

    bool operator==(const Card& other) const {
        return rank == other.rank;
    }
};
