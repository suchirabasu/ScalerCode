/*
Q20. Distinct Primes
You have given an array A having N integers. Let say G is the product of all elements of A.
You have to find the number of distinct prime divisors of G.

Input Format
The first argument given is an Array A, having N integers.

Output Format
Return an Integer, i.e number of distinct prime divisors of G.

Constraints
1 <= N <= 1e5
1 <= A[i] <= 1e5

For Example
Input:
    A = [1, 2, 3, 4]
Output:
     2

Explanation:
    here G = 1 * 2 * 3 * 4 = 24
    and distinct prime divisors of G are [2, 3]
*/
int Solution::solve(vector<int> &A) {
    unordered_set <int> s;
    for(int i =0;i<A.size();i++)
    {
        for(int j=2;j*j<=A[i];j++)
        {
            if(A[i]%j==0)
            s.insert(j);
            while(A[i]%j==0)
            {
                A[i]/=j;
            }
        }
        if(A[i]>2)
        {
            s.insert(A[i]);
        }
    }
    return s.size();

}
