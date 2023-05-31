/*
Q37. Unique Binary Search Trees II
Problem Description
Given an integer A, how many structurally unique BST's (binary search trees) exist that can store values 1...A?

Problem Constraints
1 <= A <=18

Input Format
First and only argument is the integer A

Output Format
Return a single integer, the answer to the problem

Example Input
Input 1:
 1
Input 2:
 2

Example Output
Output 1:
 1
Output 2:
 2

Example Explanation
Explanation 1:
 Only single node tree is possible.
Explanation 2:
 2 trees are possible, one rooted at 1 and other rooted at 2.
*/
int Solution::numTrees(int A) {
    vector<int> dp(A+1, 1);

    // dp[0]=1;
    // dp[1]=1;

    for(int i=2;i<=A;i++)
    {
        dp[i]=0;
        for(int j=0;j<i;j++)
        {
            dp[i] += dp[j] * dp[i-1-j];
        }
    }
    return dp[A];
}