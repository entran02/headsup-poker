#include "../include/player.h"

Player::Player(int c) : chips(c), folded(false) {}

void Player::receiveCard(Card c) {
    hand.push_back(c);
}

void Player::clearHand() {
    hand.clear();
    folded = false;
}

void Player::bet(int amount) {
    if (amount >= chips) {
        amount = chips;
    }
    chips -= amount;
}

void Player::fold() {
    folded = true;
}
