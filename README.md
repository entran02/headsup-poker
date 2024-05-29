# headsup-poker
Heads-up poker made with C++

## compile & run:
```bash
g++ -g src/main.cpp src/card.cpp src/deck.cpp src/player.cpp src/game.cpp src/hand_evaluator.cpp -o bin/main
./bin/main
```

## tests:
```bash
g++ -g src/test_hands.cpp src/card.cpp src/deck.cpp src/player.cpp src/game.cpp src/hand_evaluator.cpp -o bin/test_hands
./bin/test_hands
```

### todo list:
- [x] create base classes 
- [x] deal player and AI cards
- [x] deal community cards
- [x] output to console
- [x] add betting phases
- [x] reveal community cards in order (turn, flop, river)
- [x] add dealer chip and blinds
- [x] identify type of hand (pair, set, straight, flush, etc.)
- [x] logic to identify winner
- [x] add tests
- [ ] format output to be more readable
- [ ] add min raise value
- [ ] improve AI (maybe include difficulty levels - strategy pattern?)
- [ ] add data collection and analysis (call%, fold%, etc.)
- [ ] add graphics visualization
- [ ] improve testing to actual framework

