# headsup-poker
Heads-up poker made with C++

## compile & run:
```bash
g++ -g src/main.cpp src/card.cpp src/deck.cpp src/player.cpp src/game.cpp -o bin/main
./bin/main
```

### todo list
- [x] create base classes 
- [x] deal player and AI cards
- [x] deal community cards
- [x] output to console
- [ ] add betting phases
- [ ] reveal community cards in order (turn, flop, river)
- [ ] identify type of hand (pair, set, straight, flush, etc.)
- [ ] add graphics visualization
- [ ] improve AI (maybe include difficulty levels - strategy pattern?)

