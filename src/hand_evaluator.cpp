#include "../include/hand_evaluator.h"

bool isStraight(const vector<Card>& cards, vector<Rank>& ranks) {
    vector<Rank> sortedRanks;
    for (const auto& card : cards) {
        sortedRanks.push_back(card.rank);
    }
    sort(sortedRanks.begin(), sortedRanks.end());
    sortedRanks.erase(unique(sortedRanks.begin(), sortedRanks.end()), sortedRanks.end());

    if (sortedRanks.size() < 5) return false;

    for (size_t i = 0; i <= sortedRanks.size() - 5; ++i) {
        if (sortedRanks[i] == sortedRanks[i + 1] - 1 &&
            sortedRanks[i] == sortedRanks[i + 2] - 2 &&
            sortedRanks[i] == sortedRanks[i + 3] - 3 &&
            sortedRanks[i] == sortedRanks[i + 4] - 4) {
            ranks = {sortedRanks[i + 4]};
            return true;
        }
    }

    if (find(sortedRanks.begin(), sortedRanks.end(), ACE) != sortedRanks.end() &&
        sortedRanks[0] == TWO &&
        sortedRanks[1] == THREE &&
        sortedRanks[2] == FOUR &&
        sortedRanks[3] == FIVE) {
        ranks = {FIVE};
        return true;
    }

    return false;
}

bool isFlush(const vector<Card>& cards, vector<Rank>& ranks) {
    map<Suit, vector<Card>> suits;
    for (const auto& card : cards) {
        suits[card.suit].push_back(card);
    }

    for (const auto& entry : suits) {
        if (entry.second.size() >= 5) {
            vector<Rank> flushRanks;
            for (const auto& card : entry.second) {
                flushRanks.push_back(card.rank);
            }
            sort(flushRanks.begin(), flushRanks.end(), greater<Rank>());
            ranks.assign(flushRanks.begin(), flushRanks.begin() + 5);
            return true;
        }
    }
    return false;
}

bool isRoyalFlush(const vector<Card>& cards, vector<Rank>& ranks) {
    if (isStraightFlush(cards, ranks) && ranks[0] == ACE) {
        return true;
    }
    return false;
}

bool isStraightFlush(const vector<Card>& cards, vector<Rank>& ranks) {
    map<Suit, vector<Card>> suits;
    for (const auto& card : cards) {
        suits[card.suit].push_back(card);
    }

    for (const auto& entry : suits) {
        if (entry.second.size() >= 5) {
            if (isStraight(entry.second, ranks)) {
                return true;
            }
        }
    }
    return false;
}

bool isFourOfAKind(const vector<Card>& cards, vector<Rank>& ranks) {
    map<Rank, int> rankCounts;
    for (const auto& card : cards) {
        rankCounts[card.rank]++;
    }

    for (const auto& entry : rankCounts) {
        if (entry.second == 4) {
            ranks = {entry.first};
            for (const auto& card : cards) {
                if (card.rank != entry.first) {
                    ranks.push_back(card.rank);
                    break;
                }
            }
            return true;
        }
    }
    return false;
}

bool isFullHouse(const vector<Card>& cards, vector<Rank>& ranks) {
    map<Rank, int> rankCounts;
    for (const auto& card : cards) {
        rankCounts[card.rank]++;
    }

    Rank threeOfAKind = static_cast<Rank>(-1);
    Rank pair = static_cast<Rank>(-1);

    for (const auto& entry : rankCounts) {
        if (entry.second >= 3) {
            if (threeOfAKind == static_cast<Rank>(-1)) {
                threeOfAKind = entry.first;
            } else if (entry.first > threeOfAKind) {
                pair = threeOfAKind;
                threeOfAKind = entry.first;
            }
        } else if (entry.second == 2) {
            if (pair == static_cast<Rank>(-1)) {
                pair = entry.first;
            } else if (entry.first > pair) {
                pair = entry.first;
            }
        }
    }

    if (threeOfAKind != static_cast<Rank>(-1) && pair != static_cast<Rank>(-1)) {
        ranks = {threeOfAKind, pair};
        return true;
    }

    return false;
}

bool isThreeOfAKind(const vector<Card>& cards, vector<Rank>& ranks) {
    map<Rank, int> rankCounts;
    for (const auto& card : cards) {
        rankCounts[card.rank]++;
    }

    for (const auto& entry : rankCounts) {
        if (entry.second == 3) {
            ranks = {entry.first};
            for (const auto& card : cards) {
                if (card.rank != entry.first) {
                    ranks.push_back(card.rank);
                }
                if (ranks.size() == 3) break;
            }
            return true;
        }
    }
    return false;
}

bool isTwoPair(const vector<Card>& cards, vector<Rank>& ranks) {
    map<Rank, int> rankCounts;
    for (const auto& card : cards) {
        rankCounts[card.rank]++;
    }

    vector<Rank> pairs;
    vector<Rank> kickers;

    for (const auto& entry : rankCounts) {
        if (entry.second == 2) {
            pairs.push_back(entry.first);
        } else {
            kickers.push_back(entry.first);
        }
    }

    if (pairs.size() >= 2) {
        sort(pairs.begin(), pairs.end(), greater<Rank>());
        ranks = {pairs[0], pairs[1]};
        sort(kickers.begin(), kickers.end(), greater<Rank>());
        ranks.push_back(kickers[0]);  // Highest kicker
        return true;
    }

    return false;
}

bool isPair(const vector<Card>& cards, vector<Rank>& ranks) {
    map<Rank, int> rankCounts;
    for (const auto& card : cards) {
        rankCounts[card.rank]++;
    }

    for (const auto& entry : rankCounts) {
        if (entry.second == 2) {
            ranks = {entry.first};
            for (const auto& card : cards) {
                if (card.rank != entry.first) {
                    ranks.push_back(card.rank);
                }
                if (ranks.size() == 5) break;
            }
            return true;
        }
    }
    return false;
}

HandEvaluation evaluateHand(const vector<Card>& hand) {
    vector<Rank> ranks;
    if (isRoyalFlush(hand, ranks)) return {ROYAL_FLUSH, ranks};
    if (isStraightFlush(hand, ranks)) return {STRAIGHT_FLUSH, ranks};
    if (isFourOfAKind(hand, ranks)) return {FOUR_OF_A_KIND, ranks};
    if (isFullHouse(hand, ranks)) return {FULL_HOUSE, ranks};
    if (isFlush(hand, ranks)) return {FLUSH, ranks};
    if (isStraight(hand, ranks)) return {STRAIGHT, ranks};
    if (isThreeOfAKind(hand, ranks)) return {THREE_OF_A_KIND, ranks};
    if (isTwoPair(hand, ranks)) return {TWO_PAIR, ranks};
    if (isPair(hand, ranks)) return {PAIR, ranks};
    
    // high card
    for (const auto& card : hand) {
        ranks.push_back(card.rank);
    }
    sort(ranks.begin(), ranks.end(), greater<Rank>());
    ranks.resize(5);
    return {HIGH_CARD, ranks};
}

string handRankToString(HandRank rank) {
    switch (rank) {
        case HIGH_CARD: return "High Card";
        case PAIR: return "Pair";
        case TWO_PAIR: return "Two Pair";
        case THREE_OF_A_KIND: return "Three of a Kind";
        case STRAIGHT: return "Straight";
        case FLUSH: return "Flush";
        case FULL_HOUSE: return "Full House";
        case FOUR_OF_A_KIND: return "Four of a Kind";
        case STRAIGHT_FLUSH: return "Straight Flush";
        case ROYAL_FLUSH: return "Royal Flush";
        default: return "Unknown";
    }
}
