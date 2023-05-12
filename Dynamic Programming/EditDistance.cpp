/*
Problem Description
Given two strings A and B, find the minimum number of steps required to convert A to B. (each operation is counted as 1 step.)
You have the following 3 operations permitted on a word:
Insert a character
Delete a character
Replace a character

Problem Constraints
1 <= length(A), length(B) <= 450

Input Format
The first argument of input contains a string, A.
The second argument of input contains a string, B.

Output Format
Return an integer, representing the minimum number of steps required.

Example Input
Input 1:
 A = "abad"
 B = "abac"
Input 2:
 A = "Anshuman"
 B = "Antihuman

Example Output
Output 1:
 1
Output 2:
 2

Example Explanation
Exlanation 1:
 A = "abad" and B = "abac"
 After applying operation: Replace d with c. We get A = B.
 Explanation 2:
 A = "Anshuman" and B = "Antihuman"
After applying operations: Replace s with t and insert i before h. We get A = B.

*/
int fun(int i,int j,int n,int m,vector<vector<int>> &dp,string word1,string word2){
        if(i==n){
            return m-j;
        }
        if(j==m){
            return n-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        // if match
        if(word1[i]==word2[j]){
           return dp[i][j] = fun(i+1,j+1,n,m,dp,word1,word2);
        }
        // else do
        else{
            return dp[i][j] = min(fun(i+1,j+1,n,m,dp,word1,word2),min(fun(i,j+1,n,m,dp,word1,word2),fun(i+1,j,n,m,dp,word1,word2)))+1;
        }
    }
    int Solution::minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if(n==0&&m==0){
            return 0;
        }
        // memoisation code
        //vector<vector<int>> dp(n+1,vector<int> (m+1,-1));
        //return fun(0,0,n,m,dp,word1,word2);


        // tabulation code
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        // step 1 : copy base case of memoisation
        for(int j=0;j<=m;j++){
            dp[n][j]=m-j;
        }
        for(int i=0;i<=n;i++){
            dp[i][m]=n-i;
        }
        // step 2 : write loops in reverse direction
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                // step 3 : copy recurrence realtion of memoisation
                // if match
                if(word1[i]==word2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }
                // else do
                else{
                    dp[i][j] = min(dp[i+1][j+1],min(dp[i][j+1],dp[i+1][j]))+1;
                }
            }
        }
        return dp[0][0];
    }
