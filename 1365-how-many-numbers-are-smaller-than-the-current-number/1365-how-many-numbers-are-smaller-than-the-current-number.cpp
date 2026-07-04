class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> smaller;

        for (int i : nums) {
            int count = 0;
            for (int j : nums) {
                if (i > j && i != j) count++;
            }
            smaller.push_back(count);
        }
        return smaller;
    }
};