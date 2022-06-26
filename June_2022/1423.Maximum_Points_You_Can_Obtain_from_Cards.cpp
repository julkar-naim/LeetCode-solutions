#include<vector>
#include<numeric>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        partial_sum(cardPoints.begin(), cardPoints.end(), cardPoints.begin());
        
        auto rangeSum = [&] (int l, int r) {
            if (l == 0) 
                return cardPoints[r];
            return cardPoints[r] - cardPoints[l - 1];
        };
        int n = cardPoints.size();
        int ans = 0;
        
        for (int i = 0; i <= k; i++) {
            int ll = 0, lr = i - 1;
            int rr = n - 1, rl = n - (k - i);
            int left = 0, right = 0;
            if (lr >= 0)
                left = rangeSum(ll, lr);
            if (rl < n)
                right = rangeSum(rl, rr);
            ans = max(ans, left + right);
        }
        return ans;
    }
};
