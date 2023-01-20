/*
Q17. Prime Subsequences
Given an array A having N positive numbers. You have to find the number of Prime subsequences of A.
A Prime subsequence is one that has only prime numbers, for example [2, 3], [5] are the Prime subsequences where [2, 4] and [1, 2, 3, 4] are not.

Input Format
The first argument given is an Array A, having N integers.

Output Format
Return an integer X, i.e number of Prime subsequences. 
As X can be very large print X % (1000000007), here % is modulus operator.

Constraints
1 <= N <= 1e3
1 <= A[i] <= 1e6

For Example
Input:
    A = [1, 2, 3]
Output:
     3

Explanation:
    no. Subsequences      Prime subsequences
    1.  [1]                     No
    2.  [1, 2]                  No
    3.  [1, 3]                  No
    4.  [1, 2, 3]               No
    5.  [2]                     Yes
    6.  [2, 3]                  Yes
    7.  [3]                     Yes
    8.  []                      No

    here we have 3 subsequences(5, 6, 7) those have only prime number(s).
*/
vector<int> sieve(int n)
{
    vector<int> primes ;

    vector<bool> odds((n-1)/2, true) ;

    for(int i=3; i*i<=n; i+=2)
    {
        if(!odds[(i-3)/2])
            continue ;

        for(int j=i*i; j<=n; j+=i+i)
            odds[(j-3)/2]=false ;
    }

    primes.push_back(2) ;

    for(int i=3; i<=n; i+=2)
        if(odds[(i-3)/2])
            primes.push_back(i) ;

    return primes ;
}

int modPow(long long a, int b, int m)
{
    int result = 1 ;
    a%=m ;

    while(b)
    {
        if(b&1)
            result = (a * result)%m ;
       
        a = (a*a)%m ;

        b/=2 ;
    }

    return result ;
}

int Solution::solve(vector<int> &A) {
    // lets say we have n primes in A
    // nC1 + nC2 + nC3 + ... +nCn
    // = 2^n -1
    // if we have repeated primes
    //

    const int m = 1e9 + 7 ;
    const int A_MAX = 1e6 ;

    vector<int> primes = sieve(A_MAX) ;

    int countPrimes=0 ;

    for(int i:A)
        if(binary_search(primes.begin(), primes.end(), i))
            countPrimes++ ;

    return (modPow(2, countPrimes, m) -1 + m )% m;
}