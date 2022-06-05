#include <bits/stdc++.h>
#define umap unordered_map
#define all(var) var.begin(), var.end()
#define input freopen("input", "r", stdin)
#define output freopen("output", "w", stdout)
#define Fast ios_base::sync_with_stdio(0),cin.tie(nullptr),cout.tie(nullptr)
#define dbg(x) cerr << #x << " => " << x << endl
using Long = long long;
using uLong = unsigned long long;
using namespace std;


class Solution {
    public:
        vector<string> grid; // for the board
        vector<int> col; // for the column 
        vector<int> diag; // for both diagonal
        int n, counter;

        Solution () {
            diag.resize(200);
            ios_base::sync_with_stdio(0);  // FastIO
            cin.tie(0); cout.tie(0);
            counter = 0;
        }

        void findGrid (int row, int queen) {
            if (queen == 0) {
                counter++;
                return;
            }
            /*
             * How the diagonal check is working? take a 4x4 matrix where 0 < i, j < n. add i + j and subtract i - j
             * You can find a pattern 
             * Ex: 00 01 02
             *     10 11 12
             *     20 21 22
             *
             * Add: 
             *      0 1 2
             *      1 2 3 
             *      2 3 4
             * Subtract:
             *      0 -1 -2
             *      1 0 -1
             *      2 1 0
             *
             * Loot at the diagonal. They follow a pattern
             */
            for (int j = 0; j < n; j++) {
                if (!diag[row + j] && !diag[row - j + 100] && !col[j]) {
                    diag[row + j] = 1; 
                    diag[row - j + 100] = 1;
                    col[j] = 1;
                    grid[row][j] = 'Q';
                    findGrid(row + 1, queen - 1); // no need to check for the current row anymore, go to the next row.
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
