# headsup-poker
Heads-up poker made with C++

## compile & run:
```bash
g++ -g src/main.cpp src/card.cpp src/deck.cpp src/player.cpp src/game.cpp -o bin/main
./bin/main
```

### todo list:
- [x] create base classes 
- [x] deal player and AI cards
- [x] deal community cards
- [x] output to console
- [x] add betting phases
- [x] reveal community cards in order (turn, flop, river)
- [ ] add dealer chip and blinds
- [ ] identify type of hand (pair, set, straight, flush, etc.)
- [ ] logic to identify winner
- [ ] format output to be more readable
- [ ] improve AI (maybe include difficulty levels - strategy pattern?)
- [ ] add graphics visualization

