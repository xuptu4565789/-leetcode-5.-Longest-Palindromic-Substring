/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int compare(const void *a, const void *b){
    return *(int *)a-*(int *)b;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    // if(nums == NULL)
    //     return returnColumnSizes;
    
    qsort((void*)nums, numsSize, sizeof(int), compare);
    int counter = 0;
    
    returnColumnSizes = (int**)malloc(sizeof(int*) * numsSize * (numsSize-1) *(numsSize-2) / 6);
    
    if (numsSize < 3)
        return returnColumnSizes;
    
    for(int i = 0; i < numsSize; i++){
        int start = i+1;
        int end = numsSize-1;
        int sum;
        
        if(i > 0 && nums[i] == nums[i - 1])
            continue;
        
        while(start < end){
            sum = nums[i] + nums[start] + nums[end];
            if(sum == 0){
                counter++;
                returnColumnSizes[counter-1] = (int*)malloc(sizeof(int)*3);
                returnColumnSizes[counter-1][0] = nums[i];
                returnColumnSizes[counter-1][1] = nums[start];
                returnColumnSizes[counter-1][2] = nums[end];
                while(start < end && nums[start] == nums[start + 1])
                    start++;
                while(start < end && nums[end] == nums[end -1])
                    end--;
                
                start++;
                end--;
            }
            else if(sum>0)
                end--;
            else
                start++;
        }
       
    }
    // printf("%d %d %d %d %d %d", returnColumnSizes[0][0], returnColumnSizes[0][1], returnColumnSizes[0][2],returnColumnSizes[1][0],returnColumnSizes[1][1],returnColumnSizes[1][2]);
    return returnColumnSizes;
}
