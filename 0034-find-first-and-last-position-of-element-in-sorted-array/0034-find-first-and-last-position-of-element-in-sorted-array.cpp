class Solution {
public:
    int first(vector<int>& nums, int x) {
        int low = 0;
        int high = nums.size() - 1;
        int first = -1;

        while (low <= high) {
            int mid = (low + high)/2;

            if (nums[mid] == x) {
                first = mid;
                high = mid - 1;
            }

            else if (nums[mid] < x)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return first;
    }

    int last(vector<int>& nums, int x) {
        int low = 0;
        int high = nums.size() - 1;
        int last = -1;

        while (low <= high) {
            int mid = (low + high)/2;

            if (nums[mid] == x) {
                last = mid;
                low = mid + 1;
            }

            else if (nums[mid] < x)
                low = mid + 1;

            else
                high = mid - 1;
        }

        return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int f = first(nums, target);
        if (f == -1) return {-1, -1};
        int l = last(nums, target);
        return {f, l};
    }
};