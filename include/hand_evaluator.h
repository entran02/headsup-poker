#pragma once
#include "card.h"
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

enum HandRank {
    HIGH_CARD,
    PAIR,
    TWO_PAIR,
    THREE_OF_A_KIND,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    FOUR_OF_A_KIND,
    STRAIGHT_FLUSH,
    ROYAL_FLUSH
};

struct HandEvaluation {
    HandRank rank;
    vector<Rank> ranks;
};

bool isStraight(const vector<Card>& cards, vector<Rank>& ranks);
bool isFlush(const vector<Card>& cards, vector<Rank>& ranks);
bool isStraightFlush(const vector<Card>& cards, vector<Rank>& ranks);
bool isRoyalFlush(const vector<Card>& cards, vector<Rank>& ranks);
bool isFourOfAKind(const vector<Card>& cards, vector<Rank>& ranks);
bool isFullHouse(const vector<Card>& cards, vector<Rank>& ranks);
bool isThreeOfAKind(const vector<Card>& cards, vector<Rank>& ranks);
bool isTwoPair(const vector<Card>& cards, vector<Rank>& ranks);
bool isPair(const vector<Card>& cards, vector<Rank>& ranks);
HandEvaluation evaluateHand(const vector<Card>& hand);
string handRankToString(HandRank rank);
