/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int *arr = (int *)malloc(2*sizeof(int));
    arr[0] = -1;
    arr[1] = -1;

    for (int i = 0; i < numsSize; i++){
        if (nums[i] == target){
            arr[0] = i;
            break;
        }
    }
    for (int i = numsSize-1; i >= 0; i--){
        if (nums[i] == target){
            arr[1] = i;
            break;
        }
    }

    return arr;
}