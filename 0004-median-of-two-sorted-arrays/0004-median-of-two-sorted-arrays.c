#include <limits.h>
#include <math.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    
    // Always apply binary search on smaller array
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int low = 0;
    int high = nums1Size;

    while (low <= high) {

        int cut1 = (low + high) / 2;
        int cut2 = (nums1Size + nums2Size + 1) / 2 - cut1;

        int left1  = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int left2  = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

        int right1 = (cut1 == nums1Size) ? INT_MAX : nums1[cut1];
        int right2 = (cut2 == nums2Size) ? INT_MAX : nums2[cut2];

        // Correct partition
        if (left1 <= right2 && left2 <= right1) {

            // Even total elements
            if ((nums1Size + nums2Size) % 2 == 0) {
                return (fmax(left1, left2) + fmin(right1, right2)) / 2.0;
            }

            // Odd total elements
            return fmax(left1, left2);
        }

        // Move left
        else if (left1 > right2) {
            high = cut1 - 1;
        }

        // Move right
        else {
            low = cut1 + 1;
        }
    }

    return 0.0;
}