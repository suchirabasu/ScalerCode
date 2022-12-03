/*
Q5. Sum of Digits
Problem Description
Given a number A, we need to find the sum of its digits using recursion.

Problem Constraints
1 <= A <= 109

Input Format
The first and only argument is an integer A.

Output Format
Return an integer denoting the sum of digits of the number A.

Example Input
Input 1:
 A = 46
Input 2:
 A = 11

Example Output
Output 1:
 10
Output 2:
 2

*/
int sum(int n){
    if(n==0)
        return 0;
    return (n%10 + sum(n/10));    
}
int Solution::solve(int A) {
    return sum(A);
}
