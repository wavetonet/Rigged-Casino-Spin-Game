#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));
    int coins = 100;
    int command;
    bool isRigged = false;

    cout << "Slot Machine\n";
    cout << "Player starts with 100 coins\n";
    cout << "Commands: Press 1 for Spin, 2 for Quit, 3 to Toggle Rigged Mode\n";

    while (true) {
        cout << "\nCoins: " << coins << "\n";
        cin >> command;

         if (command == 3) {
            isRigged = !isRigged;
            cout << (isRigged ? "RIGGED MODE ON\n" : "RIGGED MODE OFF\n");
            continue;
        }

        if (command == 2) {
            cout << "You chose to quit. Thanks for Playing!\n";
            break;
        }

        if (command == 1) {
            cout << "You chose spin!\n";
            if (coins < 10) {
                cout << "You don't have enough coins :(\n";
                continue;
            }

            coins -= 10;
            int x, y, z;

            if (isRigged) {
                x = y = z = 7;
            } else {
                x = rand() % 8; 
                y = rand() % 8;
                z = rand() % 8;
            }

            cout << "[" << x << "]";
            cout << "[" << y << "]";
            cout << "[" << z << "]\n";

            if (x == 7 && y == 7 && z == 7) {
                cout << "JACKPOTTT! You won 300 coins!\n";
                coins += 300;
            } else if (x == y && y == z) {
                cout << "3 of a kind!!! You won 50 coins\n";
                coins += 50;
            } else if (x == y || y == z || x == z) {
                cout << "2 of a kind! You won 15 coins\n";
                coins += 15;
            } else {
                cout << "No prize :(\n";
            }
        }
    }

    return 0;
}

