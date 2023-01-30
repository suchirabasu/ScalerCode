/*
Q12. Implement Power Function
Problem Description
Implement pow(A, B) % C. In other words, given A, B and C, Find (AB % C).
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
int powerfunc(long long A, long long B, long long C){
    if(B == 0)
        return 1;
    if(B == 1)
        return A%C;   
    long long x = powerfunc(A, B/2, C);     
    if(B%2 == 0)
        return (x*x)%C;
    return (((x*x)%C)*A)%C;    

}
int Solution::pow(int A, int B, int C) {
    A = A%C;
    if(A<0)
        A += C;
    if(A==0)
        return 0;    
    return powerfunc(A*1LL, B*1LL, C*1LL);    
}
