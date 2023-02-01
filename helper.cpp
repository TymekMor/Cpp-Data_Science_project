#include <random>
#include <iostream>
using namespace std;

int getRandomInt(int lowerBound, int upperBound) {
    random_device rd;  // obtain a random number from hardware
    mt19937 engine(rd()); // seed the generator
    uniform_int_distribution<int> distr(lowerBound, upperBound); // define the range
    return distr(engine);
}