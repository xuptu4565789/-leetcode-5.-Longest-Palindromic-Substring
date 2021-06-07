int compare(const void * a, const void * b){
    return (*(int *)a- *(int *)b);
}

int threeSumClosest(int* nums, int numsSize, int target){
    qsort(nums, numsSize, sizeof(int), compare);
    printf("%d", numsSize);
    int start, end, sums, curr_sums, curr_ratio, min_ratio = INT_MAX;
    for(int i = 0; i < numsSize-2; i++){
        start = i+1;
        end = numsSize-1;
        while(start < end){
            curr_sums = nums[i] + nums[start] + nums[end];
            if(curr_sums == target)
                return target;
            
            curr_ratio = abs(target - curr_sums);
            if(curr_ratio < min_ratio){
                min_ratio = curr_ratio;
                sums = curr_sums;
            }
            if(curr_sums < target)
                start++;
            else if(curr_sums > target)
                end--;
        }
    }
    return sums;
}
