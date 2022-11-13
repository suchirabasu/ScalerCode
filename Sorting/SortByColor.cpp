/*
Q1. Sort By Color
Problem Description
Given an array with N objects colored red, white, or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent red, white, and blue, respectively.
Note: Using the library sort function is not allowed.

Problem Constraints
1 <= N <= 1000000
0 <= A[i] <= 2

Input Format
First and only argument of input contains an integer array A.

Output Format
Return an integer array in asked order

Example Input
Input 1 :
    A = [0 1 2 0 1 2]
Input 2:
    A = [0]

Example Output
Output 1:
    [0 0 1 1 2 2]
Output 2:
    [0]


Example Explanation
Explanation 1:
    [0 0 1 1 2 2] is the required order.

*/
vector<int> Solution::sortColors(vector<int> &A) {
    //Every element on the left of low is 0
    //Every element on the right of high is 2
    //All the elements between low and high is 1
    int n=A.size();
    int low=0,mid=0,high=n-1;
    while(mid<=high)
    {
        if(A[mid]==0) swap(A[low++],A[mid++]); //Dutch National Flag
        else if(A[mid]==1) mid++;
        else if(A[mid]==2) swap(A[mid],A[high--]);
    }
    return A;
}