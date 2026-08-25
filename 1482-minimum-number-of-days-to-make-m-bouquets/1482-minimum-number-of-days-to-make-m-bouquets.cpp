class Solution {
public:
    int possible(vector<int>& bloomDay, int m, int k, int mid) {
        long count = 0;
        long long bloom = 0;
        for (long long i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                count++;
            }
            else {
                bloom += count/k;
                count = 0;
            }
        }
        bloom += count/k;
        if (bloom >= m) 
            return mid;
        else 
            return -1;
    } 

    int minDays(vector<int>& bloomDay, int m, int k) {

        if (bloomDay.size() < 1LL * m * k)
            return -1;

        long low = 0;
        long long high = *max_element(bloomDay.begin(), bloomDay.end());
        long long ans = low;

        while (low <= high) {
            long long mid = low + (high - low)/2;

            if (possible(bloomDay, m, k, mid) == mid) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};