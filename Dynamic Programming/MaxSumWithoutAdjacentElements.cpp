/*
Q4. Max Sum Without Adjacent Elements
Problem Description
Given a 2 x N grid of integer, A, choose numbers such that the sum of the numbers is maximum and no two chosen numbers are adjacent horizontally, vertically or diagonally, and return it.
Note: You can choose more than 2 numbers.

Problem Constraints
1 <= N <= 20000
1 <= A[i] <= 2000

Input Format
The first and the only argument of input contains a 2d matrix, A.

Output Format
Return an integer, representing the maximum possible sum.

Example Input
Input 1:
 A = [   
        [1]
        [2]    
     ]
Input 2:
 A = [   
        [1, 2, 3, 4]
        [2, 3, 4, 5]    
     ]

Example Output
Output 1:
 2
Output 2:
 8

Example Explanation
Explanation 1:
 We will choose 2.
Explanation 2:
 We will choose 3 and 5.

*/
int Solution::adjacent(vector<vector<int> > &A) {
    int first = 0, second = max(A[0][0], A[1][0]), curr = 0;
    
    for(int i=1;i<A[0].size();i++){
        curr = max(A[0][i], A[1][i]);
        curr = max(curr+first, second);
        first = second;
        second = curr;
    }

    return second;
}
