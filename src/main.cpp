#include "../include/game.h"
#include <iostream>

using namespace std;

int main() {
    Game game;
    while (game.playerHasChips() && game.aiHasChips()) {
        game.playRound();
        game.displayChips();
    }
    cout << "Game over!" << endl;
    if (game.playerHasChips()) {
        cout << "Player wins!" << endl;
    } else {
        cout << "AI wins!" << endl;
    }
    return 0;
}
