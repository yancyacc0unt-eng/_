#include "includes.h"
RandomNumberGenerator::RandomNumberGenerator(unsigned long s) {
    this->seed = s;
}
unsigned long RandomNumberGenerator::thisNumber() {
    return this->seed;
}
unsigned long RandomNumberGenerator::nextNumber() {
    this->seed = seed ^ (seed << 13);
    this->seed = seed ^ (seed >> 17);
    this->seed = seed ^ (seed << 5);
    return this->seed;
}
RandomNumberGenerator::~RandomNumberGenerator() {
}