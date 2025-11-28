#include <stdio.h>
#include <stdlib.h>

//The returned array needs to be allocated using malloc (to avoid stack overflow), and the caller must manually free it.
// 返回的数组需要用 malloc 分配（避免栈溢出），调用者需手动释放
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
    *returnSize = 2;
    int* result = (int*)malloc(sizeof(int) * 2);
    
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result; // Return the answer directly without continuing the traversal
            }
        }
    }

    return result;
}

// Tast cases
int main() {
    int nums1[] = {2, 7, 11, 15};
    int target1 = 13;
    int returnSize1;
    int* res1 = twoSum(nums1, sizeof(nums1)/sizeof(nums1[0]), target1, &returnSize1);
    printf("[%d, %d]\n", res1[0], res1[1]);
    free(res1); // Release memory
    
    int nums2[] = {3, 2, 4};
    int target2 = 7;
    int returnSize2;
    int* res2 = twoSum(nums2, sizeof(nums2)/sizeof(nums2[0]), target2, &returnSize2);
    printf("[%d, %d]\n", res2[0], res2[1]);
    free(res2);
    
    int nums3[] = {3, 3};
    int target3 = 6;
    int returnSize3;
    int* res3 = twoSum(nums3, sizeof(nums3)/sizeof(nums3[0]), target3, &returnSize3);
    printf("[%d, %d]\n", res3[0], res3[1]);
    free(res3);
    
    printf("\nPress any key to exit...");
    getchar();
    return 0;
}