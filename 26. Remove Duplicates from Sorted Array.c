int removeDuplicates(int* nums, int numsSize){
    int curr_integer = 0, count = 0;
    for(int i = 0 ,j = 0; i< numsSize;i++, j++){
        curr_integer = nums[i];
        count++;
        nums[j] = nums[i];
        while(i< numsSize-1 && curr_integer == nums[i+1])
            i++;
    }
    return count;
}
