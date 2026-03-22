#pragma once
class RandomNumberGenerator {
private:
    unsigned long seed;
public:
    RandomNumberGenerator(unsigned long = time(nullptr));
    unsigned long thisNumber();
    unsigned long nextNumber();
    ~RandomNumberGenerator();
};
