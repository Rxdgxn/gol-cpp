#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <stdlib.h>
using namespace std;

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
                if (nbrs < 2 || nbrs > 3) trans[i][j] = 0;
            }
            else {
                if (nbrs == 3) trans[i][j] = 1;
            }
        }
    }

    board = trans;
}
#define next() nextStep(board, m, n);

void print(const vector<vector<int>>& board, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 2 * n; i++) cout << "-";
    cout << endl;
}
#define display() print(board, m, n);

int main(void) {

    int m, n;
    cin >> m >> n;
    vector<vector<int>> board(m);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            board[i].push_back(x);
        }
    }

    while (true) {
        system("cls");
        display();
        next();
        Sleep(1000);
    }

    return 0;
}