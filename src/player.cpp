#include "../include/player.h"

Player::Player(int c) : chips(c) {}

void Player::receiveCard(Card c) {
    hand.push_back(c);
}

void Player::clearHand() {
    hand.clear();
}
