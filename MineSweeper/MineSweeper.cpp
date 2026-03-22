#include "includes.h"

bool win = false;
char op = 0;
char x = 0, y = 0;

int main(int argc, char* argv) {
    MineSweeper game(MNS);
    game.show(x, y);
    do {
        op = _getch();
        switch (op) {
        case 'w':
            if (x > 0)x--;
            break;
        case 'a':
            if (y > 0)y--;
            break;
        case 's':
            if (x < ROW-1)x++;
            break;
        case 'd':
            if (y < COL-1)y++;
            break;
        case 'q':
            exit(0);
            break;
        case 'e':
            if (game.sweep(x, y) == true) {
                game.show(x, y);
                std::cout << "\033[0mGame over!\n";
                system("pause");
                exit(0);
            }
            else break;
        case 'f':
            game.f(x, y);
            break;
        default:
            _getch();
            break;
        }
        game.show(x, y);
        win = game.check();
    } while (win == false);
    std::cout << "\033[0mYou win!\n";
    system("pause");
    return 0;
}
