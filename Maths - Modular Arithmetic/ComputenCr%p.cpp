/*
Q22. Compute nCr % p
Problem Description
Given three integers A, B, and C, where A represents n, B represents r, and C represents p and p is a prime number greater than equal to n, find and return the value of nCr % p where nCr % p = (n! / ((n-r)! * r!)) % p.
x! means factorial of x i.e. x! = 1 * 2 * 3... * x.
NOTE: For this problem, we are considering 1 as a prime.

Problem Constraints
1 <= A <= 106
1 <= B <= A
A <= C <= 109+7

Input Format
The first argument given is the integer A ( = n).
The second argument given is the integer B ( = r).
The third argument given is the integer C ( = p).

Output Format
Return the value of nCr % p.

Example Input
Input 1:
 A = 5
 B = 2
 C = 13
Input 2:
 A = 6
 B = 2
 C = 13

Example Output
Output 1:
 10
Output 2:
 2

Example Explanation
Explanation 1:
 nCr( n=5 and r=2) = 10.
 p=13. Therefore, nCr%p = 10.

*/
int pwr(int A, int B, int C) {
    if(A == 0 || B == 1) return (A + C) % C;
    if(B == 0 || A == 1) return 1;

    int temp = (pwr(A, B/2, C) + C) % C ;

    if(B & 1){
        return (((((1L * temp * temp) + C )  % C) * 1L * A) + C) % C;
    }

    return ((1L * temp * temp) + C) % C;
}

int Solution::solve(int A, int B, int C) {

    int factors[A];

    factors[0] = 1;

    for(int i = 1; i <= A; i++)
        factors[i] = ((1L * i * factors[i - 1]) + C) % C;
   
    // (n - r)! r!
    int temp = ((1L * factors[A - B] * factors[B]) + C) % C;

    temp = pwr(temp, C - 2, C);
    return ((1L * factors[A] * temp) + C) % C;
   
}