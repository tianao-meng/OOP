#include <iostream>
#include <string>
#include "grid.h"
using namespace std;

int main() {
    cin.exceptions(ios::eofbit|ios::failbit);
    string cmd, aux;
    Grid g;
    int moves = 0;
    Xwindow w;
    // You will need to make changes to this code.

    try {
        while (true) {
            cin >> cmd;
            if (cmd == "new") {
                int n;
                cin >> n;
                int gap = 500 / n;
                for (int i = 0; i < n; i ++){
                    for (int j = 0; j < n; j++){
                        w.fillRectangle(((j * gap) + 1), ((i * gap) + 1), gap, gap, Xwindow::Black);
                    }
                }

                g.init(n, w);
            }
            else if (cmd == "init") {
                while (true) {
                    int r, c;
                    cin >> r >> c;

                    if ((r == -1) && (c == - 1)){
                        cout << g;
                        break;
                    }
                    g.init(r,c);

                }


            }
            else if (cmd == "game") {
                cin >> moves;
                cout << moves << " moves left" << endl;
            }
            else if (cmd == "switch") {
                int r = 0, c = 0;
                cin >> r >> c;
                g.toggle(r,c);
                cout << g;
                if (g.isWon()){
                    cout << "Won" << endl;

                    cout << "print any letter to quit graphics" << endl;
                    char c;
                    cin >> c;
                    break;
                }
                moves --;
                cout << moves << " moves left" << endl;
                if (moves == 0){
                    cout << "Lost" << endl;
                    cout << "print any letter to quit graphics" << endl;
                    char c;
                    cin >> c;
                    break;
                }
            }
        }
    }
    catch (ios::failure &) {
        cerr << "invalid input" << endl;
    }
}
