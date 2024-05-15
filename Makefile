rl: RLoutput

RLoutput: ./internals/main.cpp
	@ g++ -o ./builds/RLoutput ./internals/main.cpp -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
	@ ./builds/RLoutput
