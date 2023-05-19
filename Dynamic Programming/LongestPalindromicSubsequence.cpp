/*
Q31. Longest Palindromic Subsequence
Problem Description
Given a string A. Find the longest palindromic subsequence (A subsequence which does not need to be contiguous and is a palindrome).
You need to return the length of longest palindromic subsequence.

Problem Constraints
1 <= length of(A) <= 103

Input Format
First and only integer is a string A.

Output Format
Return an integer denoting the length of longest palindromic subsequence.

Example Input
Input 1:
 A = "bebeeed"
Input 2:
 A = "aedsead"

Example Output
Output 1:
 4
Output 2:
 5

Example Explanation
Explanation 1:
 The longest palindromic subsequence is "eeee", which has a length of 4.
Explanation 2:
 The longest palindromic subsequence is "aedea", which has a length of 5.

*/
int Solution::solve(string s) {
    int n = s.length();
    vector<vector<int>>dp(n, vector<int>(n,-1));
    for(int diff = 0;diff<n;diff++)
    {
        int i = 0;
        int j = i+diff;
        while(j<n)
        {
            if(s[i] == s[j])
            {
                dp[i][j] = (j-i<=1?j-i+1:dp[i+1][j-1]+2);
            }
            else
            {
                dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
            i++;j++;
        }
    }
    return dp[0][n-1];
}