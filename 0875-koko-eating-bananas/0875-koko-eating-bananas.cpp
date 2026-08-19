class Solution {
public:
    long long tc(vector<int>& piles, int mid) {
        long long totalhrs = 0;

        for (int pile : piles) {
            totalhrs += ((long long)pile + mid - 1) / mid;
        }

        return totalhrs;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = INT_MAX;

        while (low <= high) {
            int mid = (low + high) / 2;

            long long totalhrs = tc(piles, mid);

            if (totalhrs <= h ) {
                ans = mid;
                high = mid - 1;
            }

            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};