/*
Q36. Best Time to Buy and Sell Stocks I
Problem Description
Say you have an array, A, for which the ith element is the price of a given stock on day i.
If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
Return the maximum possible profit.

Problem Constraints
0 <= A.size() <= 700000
1 <= A[i] <= 107

Input Format
The first and the only argument is an array of integers, A.

Output Format
Return an integer, representing the maximum possible profit.

Example Input
Input 1:
A = [1, 2]
Input 2:
A = [1, 4, 5, 2, 4]

Example Output
Output 1:
1
Output 2:
4
*/
int Solution::maxProfit(const vector<int> &A) {
    int i = 0;
    int n = A.size();
    if(n<2) return 0;
    int cl = A[n-1];
    int ans = 0;
    for(i=n-2;i>=0;i--)
    {
        if(A[i]>cl) cl = A[i];
        else ans = max(ans,cl-A[i]);
    }
    return ans;
}
