/*
Q7. Very Large Power
Problem Description
Given two Integers A, B. You have to calculate (A ^ (B!)) % (1e9 + 7).
"^" means power,
"%" means "mod", and
"!" means factorial.

Problem Constraints
1 <= A, B <= 5e5

Input Format
First argument is the integer A
Second argument is the integer B

Output Format
Return one integer, the answer to the problem

Example Input
Input 1:
A = 1
B = 1
Input 2:
A = 2
B = 2

Example Output
Output 1:
1
Output 2:
4

Example Explanation
Explanation 1:
 1! = 1. Hence 1^1 = 1.
Explanation 2:
 2! = 2. Hence 2^2 = 4.

*/
int factorial(int A){
    long long power = 1;
    int mod = 1e9+7;
    for(int i=A;i>=1;i--){
        power *= i;
        power %= (mod-1);             //because we know m is prime so no a is divisible (i.e a^(p-1) = 1%p = 1) 
    }                                                       // what is means is we need to take mod by (1e9+7 - 1) because if power 
    return power;                            //becomes (1e9+7 - 1) then mod will be 1 ---(by fermat's theorem)
}

int powerFunc(int a, int b, int m){
    if(b==0)
        return 1;
    if(b==1)
        return a;
    long long ans = powerFunc(a, b/2, m)%m;
    if(b&1)
        return ((ans%m * ans%m)%m * a)%m;
    return (ans%m * ans%m)%m;
}

int Solution::solve(int A, int B) {
    long long exponent = factorial(B);
    long long ans = powerFunc(A, exponent, 1000000007);
    return ans;
}