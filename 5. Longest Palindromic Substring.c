char * longestPalindrome(char * s){
    // s++;
    char subtext[1000] = {};
    int size  = (int)strlen(s);
    // printf("%d",size);
    int dp[1000][1000]={0};
    int max_i= 0, max_j = 0, maxx =0;
    for(int i = 0; i < size; i++){
        dp[i][i] = 1;
    }
    for(int i = 0; i < size-1; i++){
        if(s[i] == s[i+1])
            dp[i][i+1] = dp[i][i]+1;
    }
    // for(int i = 0;i < size-1; i++){
    //     for(int j = 1; j < size; j++){
    //         if(dp[i+1][j-1] && s[i] == s[j]){
    //             dp[i][j] = j-i+1;
    //         }
    //         printf("%d %d\n", i, j);
    //     }
    // }
    int tmpx = 0, tmpy = 0;
    for(int j = 1; j < size; j++){
        for(int i = 0; i <size-1; i++){
            if(dp[i+1][j-1] && s[i] == s[j]){
                dp[i][j] = j-i+1;
            }
        }
    }
    
    for(int i = 0 ; i < size; i++){
        for(int j = 0; j<size; j++){
            if(dp[i][j] > maxx){
                maxx = dp[i][j];
                max_i = i;
                max_j = j;
            }
            // printf("%d", dp[i][j]);
        }
    }
    
    
    
    return strncpy(subtext,s+max_i,maxx);
}