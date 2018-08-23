int subarraySum(int* nums, int numsSize, int k) {
    int res = 0;
    int temp_res = 0;
    if (numsSize == 0)  return res;
    int *sum = (int *)malloc(sizeof(int) * (numsSize + 1));
    memset(sum, 0, sizeof(int) * (numsSize + 1));
    for (int i = 0; i < numsSize; i ++) {
        temp_res += nums[i];
        sum[i+1] += temp_res;
    }
    for (int i = 0; i < numsSize; i ++) {
        for (int j = i+1; j <= numsSize; j ++) {
            if (sum[j] - sum[i] == k) {
                ++res;
            }
        }
    }
    return res;
}