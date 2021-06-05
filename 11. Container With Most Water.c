int maxArea(int* height, int heightSize){
    int water = 0, *i = height, *j = height+heightSize-1;
    while(i < j){
        int h = *i, w=0;
        if(*i>*j)
            h = *j;
        w = h*(j-i);
        if(w > water)
            water = w;
        while(i<j && *i <= h) i++;
        while(i<j && *j <= h) j--;
    }
    
    return water;
}
