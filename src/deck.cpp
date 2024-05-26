#include "../include/deck.h"
#include <algorithm>
#include <random>

using namespace std;

Deck::Deck() {
    for (int s = HEARTS; s <= SPADES; ++s) {
        for (int r = TWO; r <= ACE; ++r) {
            cards.push_back(Card(static_cast<Suit>(s), static_cast<Rank>(r)));
        }
    }
    shuffle();
}

void Deck::shuffle() {
    std::shuffle(cards.begin(), cards.end(), mt19937{ random_device{}() });
}

Card Deck::draw() {
    Card drawnCard = cards.back();
    cards.pop_back();
    return drawnCard;
}
