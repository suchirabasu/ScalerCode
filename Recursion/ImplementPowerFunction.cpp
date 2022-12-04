/*
Q6. Implement Power Function
Problem Description
Implement pow(A, B) % C.
In other words, given A, B and C, Find (AB % C).
Note: The remainders on division cannot be negative. In other words, make sure the answer you return is non-negative.

Problem Constraints
-109 <= A <= 109
0 <= B <= 109
1 <= C <= 109

Input Format
Given three integers A, B, C.

Output Format
Return an integer.

Example Input
A = 2, B = 3, C = 3

Example Output
2

Example Explanation
23 % 3 = 8 % 3 = 2

*/
int power(int a,int n,int m){
    if(n==0){
        return 1;
    }
    long hp=power(a,n/2,m);
    long ha=((hp%m) *(hp%m))%m;
    if(n%2==0){
        return ha;
    }else{
        return ((ha%m)*a%m)%m;
    }
}


int Solution::pow(int A, int B, int C) {
    if(A==0){
        return 0;
    }
    if(A<0){
        A=C+A;
    }
    return power(A,B,C);
}