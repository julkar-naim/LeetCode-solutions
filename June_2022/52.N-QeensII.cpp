#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        vector<string> grid;
        vector<int> col;
        vector<int> diag;
        int n, counter;

        Solution () {
            diag.resize(200);
            ios_base::sync_with_stdio(0);
            cin.tie(0); cout.tie(0);
            counter = 0;
        }

        void findGrid (int row, int queen) {
            if (queen == 0) {
                counter++;
                return;
            }
            for (int j = 0; j < n; j++) {
                if (!diag[row + j] && !diag[row - j + 100] && !col[j]) {
                    diag[row + j] = 1;
                    diag[row - j + 100] = 1;
                    col[j] = 1;
                    grid[row][j] = 'Q';
                    findGrid(row + 1, queen - 1);
                    diag[row + j] = 0;
                    diag[row - j + 100] = 0;
                    col[j] = 0;
                    grid[row][j] = '.';
                }
            }
        }

        int totalNQueens (int n) {
            col.resize(n + 1);
            grid = vector<string> (n, string(n, '.'));
            this->n = n;
            findGrid(0, n);
            return counter;
        }

};
