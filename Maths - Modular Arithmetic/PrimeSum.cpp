/*
Q16. Prime Sum
Problem Description
Given an even number A ( greater than 2 ), return two prime numbers whose sum will be equal to the given number.
If there is more than one solution possible, return the lexicographically smaller solution.
If [a, b] is one solution with a <= b, and [c,d] is another solution with c <= d, then 
[a, b] < [c, d], If a < c OR a==c AND b < d. 
NOTE: A solution will always exist. Read Goldbach's conjecture.

Problem Constraints
4 <= A <= 2*107

Input Format
First and only argument of input is an even number A.

Output Format
Return a integer array of size 2 containing primes whose sum will be equal to given number.

Example Input
 4
Example Output
 [2, 2]

Example Explanation
 There is only 1 solution for A = 4.

*/
vector<bool> sieve(int N){
    // Generate isPrime List less equal than N
    vector<bool> isPrime(N + 1, true);
    isPrime[0] = false;
    isPrime[1] = false;
    
    // Sieve of Erastothenes
    for(int i = 2; i <= N; i++) {
        if (!isPrime[i]) continue;
        if (i > N / i) break;
        for (int j = i * i; j <= N; j += i) isPrime[j] = false;
    }
    return isPrime;
}
vector<int> Solution::primesum(int A) {
    vector<bool> isPrime = sieve(A);
    for(int i = 2; i <= A; ++i) {
        if(isPrime[i] && isPrime[A - i]) {
            vector<int> ans;
            ans.push_back(i);
            ans.push_back(A - i);
            return ans;
        }
    } 
    vector<int> ans; 
    return ans;
}