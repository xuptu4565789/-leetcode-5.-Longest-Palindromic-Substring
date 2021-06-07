int removeElement(int* nums, int numsSize, int val){
    int count = 0;
    for(int i = 0, j = 0; i < numsSize;i++){
        if(nums[i] != val){
            nums[j] = nums[i];
            count++;
            j++;
        }
        
    }
    return count;
}
