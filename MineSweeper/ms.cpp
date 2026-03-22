#include "includes.h"
MineSweeper::MineSweeper(char _) {
    m = _;
    for (char i = 0;i < ROW;i++) {
        for (char j = 0;j < COL;j++) {
            this->bord[i][j] = '0';
            this->flip[i][j] = false;
            this->flag[i][j] = false;
        }
    }
    for (char k = 0;k < _;k++) {
        unsigned long x = this->rng.nextNumber() % ROW;
        unsigned long y = this->rng.nextNumber() % COL;
        if (this->bord[x][y] == '@') {
            k--;
        }
        else {
            this->bord[x][y] = '@';
            if (x > 0 && y > 0) {
                if (this->bord[x - 1][y - 1] != '@') {
                    this->bord[x - 1][y - 1]++;
                }
            }
            if (x > 0 || false) {
                if (this->bord[x - 1][y - 0] != '@') {
                    this->bord[x - 1][y - 0]++;
                }
            }
            if (x > 0 && y < COL-1) {
                if (this->bord[x - 1][y + 1] != '@') {
                    this->bord[x - 1][y + 1]++;
                }
            }
            if (false || y > 0) {
                if (this->bord[x - 0][y - 1] != '@') {
                    this->bord[x - 0][y - 1]++;
                }
            }
            if (false || y < COL-1) {
                if (this->bord[x - 0][y + 1] != '@') {
                    this->bord[x - 0][y + 1]++;
                }
            }
            if (x < ROW-1 && y > 0) {
                if (this->bord[x + 1][y - 1] != '@') {
                    this->bord[x + 1][y - 1]++;
                }
            }
            if (x < ROW-1 || false) {
                if (this->bord[x + 1][y - 0] != '@') {
                    this->bord[x + 1][y - 0]++;
                }
            }
            if (x < ROW-1 && y < COL-1) {
                if (this->bord[x + 1][y + 1] != '@') {
                    this->bord[x + 1][y + 1]++;
                }
            }
        }
    }
}
bool MineSweeper::check() {
    char count = 0;
    for (char i = 0;i < ROW;i++) {
        for (char j = 0;j < COL;j++) {
            if (this->flip[i][j] == false)count++;
        }
    }
    if (count == m)return true;
    else return false;
}
void MineSweeper::f(char x, char y) {
    if (this->flag[x][y] == false)this->flag[x][y] = true;
    else this->flag[x][y] = false;
}
bool MineSweeper::sweep(char x, char y) {
    if (this->flag[x][y] == true) {
        return false;
    }
    this->flip[x][y] = true;
    if (bord[x][y] != '0') {
        goto line133;
    }
    if (x > 0 && y > 0) {
        if (this->flip[x - 1][y - 1] == false) {
            this->sweep(x - 1, y - 1);
        }
    }
    if (x > 0 || false) {
        if (this->flip[x - 1][y - 0] == false) {
            this->sweep(x - 1, y - 0);
        }
    }
    if (x > 0 && y < COL-1) {
        if (this->flip[x - 1][y + 1] == false) {
            this->sweep(x - 1, y + 1);
        }
    }
    if (false || y > 0) {
        if (this->flip[x - 0][y - 1] == false) {
            this->sweep(x - 0, y - 1);
        }
    }
    if (false || y < COL-1) {
        if (this->flip[x - 0][y + 1] == false) {
            this->sweep(x - 0, y + 1);
        }
    }
    if (x < ROW-1 && y > 0) {
        if (this->flip[x + 1][y - 1] == false) {
            this->sweep(x + 1, y - 1);
        }
    }
    if (x < ROW-1 || false) {
        if (this->flip[x + 1][y - 0] == false) {
            this->sweep(x + 1, y - 0);
        }
    }
    if (x < ROW-1 && y < COL-1) {
        if (this->flip[x + 1][y + 1] == false) {
            this->sweep(x + 1, y + 1);
        }
    }
line133:
    if (this->bord[x][y] == '@')return true;
    else return false;
}
void MineSweeper::show(char x, char y) {
    system("cls");
    for (int i = 0;i < ROW;i++) {
        for (int j = 0;j < COL;j++) {
            if (i == x && j == y) {
                std::cout << "\033[97;40m>";
            }
            else {
                std::cout << "\033[97;40m ";
            }
            if (this->flip[i][j] == true) {
                if (this->bord[i][j] == '0') {
                    std::cout << "\033[97;40m ";
                }
                else if(this->bord[i][j] <= '9') {
                    std::string str0 = "\033[9";
                    std::string str1 = ";40m";
                    std::cout << str0 + this->bord[i][j] + str1 << this->bord[i][j];
                }
                else {
                    std::cout << "\033[35;40m" << this->bord[i][j];
                }
            }
            else if (this->flag[i][j] == true) {
                std::cout << "\033[31;40mF";
            }
            else {
                std::cout << "\033[97;40m?";
            }
        }
        std::cout << '\n';
    }
}
MineSweeper::~MineSweeper() {}