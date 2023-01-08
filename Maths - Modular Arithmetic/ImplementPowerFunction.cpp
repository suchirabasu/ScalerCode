/*
Q3. Implement Power function
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
int powerFunc(long long a, long long b, long long mod){
    if(b==0)
        return 1;
    if(b==1)
        return a%mod;
    long long x = powerFunc(a, b/2, mod)%mod;
    if(b&1)
        return (((x*x)%mod)*a)%mod;
    return (x*x)%mod;
}

int Solution::pow(int A, int B, int C) {
    A = A%C;
    if(A<0)
        A+=C;
    return powerFunc(A*1LL,B*1LL,C*1LL)%C;
}