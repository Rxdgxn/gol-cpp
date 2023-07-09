#include <iostream>
#include <vector>
#include <Windows.h>
#include <stdlib.h>
using namespace std;

int m, n, gen = 0, alive = 0;

inline short count(const vector<vector<int>>& board, int i, int j, int m, int n) {
    short nbrs = 0;
    nbrs += (i > 0 ? board[i-1][j] : 0);
    nbrs += (j > 0 ? board[i][j-1] : 0);
    nbrs += (i < m - 1 ? board[i+1][j] : 0);
    nbrs += (j < n - 1 ? board[i][j+1] : 0);
    nbrs += (i > 0 && j > 0 ? board[i-1][j-1] : 0);
    nbrs += (i > 0 && j < n - 1 ? board[i-1][j+1] : 0);
    nbrs += (i < m - 1 && j > 0 ? board[i+1][j-1] : 0);
    nbrs += (i < m - 1 && j < n - 1 ? board[i+1][j+1] : 0);
    return nbrs;
}

void nextStep(vector<vector<int>>& board, int m, int n) {
    vector<vector<int>> trans = board;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            short nbrs = count(board, i, j, m, n);
            if (board[i][j]) {
                if (nbrs < 2 || nbrs > 3) {
                    trans[i][j] = 0;
                    alive--;
                }
            }
            else {
                if (nbrs == 3) {
                    trans[i][j] = 1;
                    alive++;
                }
            }
        }
    }

    board = trans;
}
#define next() nextStep(board, m, n);

void print(const vector<vector<int>>& board, int m, int n) {
    for (int i = 0; i < 2 * n; i++) cout << "-";
    cout << endl;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << (board[i][j] ? "@" : " ") << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 2 * n; i++) cout << "-";
    cout << endl;
}
#define display() print(board, m, n);

int main(void) {

    cin >> m >> n;
    vector<vector<int>> board(m);

    srand(time(0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x = rand() % 2;
            if (x) alive++;
            board[i].push_back(x);
        }
    }

    while (true) {
        cout << "\033[2J\033[1;1H";
        printf("GENERATION: %d\nAlive cells: %d\n", gen, alive);
        gen++;
        display();
        next();
        Sleep(200);
    }

    return 0;
}