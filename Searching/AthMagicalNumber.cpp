/*
Q1. Ath Magical Number
Problem Description
You are given three positive integers, A, B, and C.
Any positive integer is magical if divisible by either B or C.
Return the Ath smallest magical number. Since the answer may be very large, return modulo 109 + 7.

Problem Constraints
1 <= A <= 109
2 <= B, C <= 40000

Input Format
The first argument given is an integer A.
The second argument given is an integer B.
The third argument given is an integer C.

Output Format
Return the Ath smallest magical number. Since the answer may be very large, return modulo 109 + 7.

Example Input
Input 1:
 A = 1
 B = 2
 C = 3
Input 2:
 A = 4
 B = 2
 C = 3

Example Output
Output 1:
 2
Output 2:
 6

Example Explanation
Explanation 1:
 1st magical number is 2.
Explanation 2:
 First four magical numbers are 2, 3, 4, 6 so the 4th magical number is 6.

*/
int gcd(int a, int b)
{
    if(a==0)
        return b ;

    return gcd(b%a, a) ;
}

int lcm(int a, int b)
{
    return a*b/gcd(a,b) ;
}



int Solution::solve(int A, int B, int C) {
    // we have to return Nth no which is either multiple of B or C
    // apply bin search
    // Nth no. will be <= N * min(B, C)
    // >= min(B,C)

    long long l = min(B, C) ;
    long long r= (long long)A * min(B, C) ;

    long long mid ;

    long long count_multiples ;

    const int mod = 1e9+7 ;

    while(l<=r)
    {
        mid = (l+r)/2 ;

        count_multiples = mid/B + mid/C ;
        count_multiples -= mid/lcm(B, C) ;  // to remove duplicates

        if(count_multiples==A && (mid%B==0 || mid%C==0))
            break ;

        else if(count_multiples < A)
            l=mid+1 ;

        else    
            r=mid - 1 ;
    }

    return mid%mod ;
}