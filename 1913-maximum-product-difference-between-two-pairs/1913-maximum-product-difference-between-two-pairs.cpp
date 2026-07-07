class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int maxProd = INT_MIN;

        sort(nums.begin(), nums.end());

        maxProd = abs((nums[0]*nums[1]) - (nums[nums.size()-1]*nums[nums.size()-2]));

        return maxProd;
    }
};