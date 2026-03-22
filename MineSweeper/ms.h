#pragma once
class MineSweeper {
private:
    char bord[ROW][COL];
    bool flip[ROW][COL];
    bool flag[ROW][COL];
    RandomNumberGenerator rng;
    char m;
public:
    MineSweeper(char = 10);
    bool check();
    void f(char, char);
    bool sweep(char, char);
    void show(char, char);
    ~MineSweeper();
};
