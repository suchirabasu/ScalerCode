/*
Q16. Ways to form Max Heap 2
Problem Description
Max heap is a special kind of complete binary tree in which, for every node, the value present in that node is greater than the value present in its children nodes.
Given an array A of size N consisting of N - 1 distinct elements. In other words, there is exactly one element that is repeated.
It is given that the element that would repeat would be either the maximum element or the minimum element.
Find the number of structurally different Max heaps possible using all the N elements of the array i.e., Max heap of size N.
As the final answer can be very large return your answer modulo 109 + 7.

Problem Constraints
1 <= N <= 1000

Input Format
The first and only argument is an integer array A.

Output Format
Return an integer denoting the number of structurally different Max heaps possible modulo 109 + 7.

Example Input
Input 1:
 A = [1, 5, 5]
Input 2:
 A = [2, 2, 7]

Example Output
Output 1:
 2
Output 2:
 1

Example Explanation
Explanation 1:
 The possible max heaps using the given elements are:- First: 5 on the root. 1 as the left child of root and 5 as the right child of the root.   
                5
              /   \
            1       5
 Second: 5 on the root. 5 as the left child of root and 1 as the right child of the root.
                5
              /   \
            5       1            
Explanation 2:
 There is only one possible max heaps: 7 on the root. 2 as the left child of root and 2 as the right child of the root.   
                7
              /   \
            2       2

*/
#define MAXN 1005

long long int dp[MAXN]; /* dp[i] = number of max heaps for i distinct integers */
long long int dp1[MAXN]; /*dp1[i]=number of max heaps for i-1 distinct integers */
long long int nck[MAXN][MAXN]; /* nck[i][j] = i choose j if i>=j else 0 */
int log_2[MAXN]; /* log_2[i] = int(log_2 base 2 of i) */
long long int MOD = 1000000007;

const int M = 1001;
long long int f[M], inv[M];

long long int expo(long long int base, long long int exponent, long long int mod) {
    long long int ans = 1;
    while (exponent != 0) {
        if (exponent & 1) ans = (1LL * ans * base) % mod;
        base = (1LL * base * base) % mod;
        exponent >>= 1;
    }
    return ans % mod;
}
void compute() {
    if (f[0])
        return;
    f[0] = 1;
    for (int i = 1; i < M; i++) {
        f[i] = (1LL * i * f[i - 1]) % MOD;
    }
    inv[M - 1] = expo(f[M - 1], MOD - 2, MOD);
    for (int i = M - 2; i >= 0; i--) {
        inv[i] = (1LL * (i + 1) * inv[i + 1]) % MOD;
    }
}
long long int C(int n, int r) {
    return (1LL * ((1LL * f[n] * inv[r]) % MOD) * inv[n - r]) % MOD;
}

long long int choose(int n, int k) {
    if (k > n)
        return 0;
    if (n <= 1)
        return 1;
    if (k == 0)
        return 1;

    if (nck[n][k] != -1)
        return nck[n][k];
    nck[n][k] = C(n, k);
    return nck[n][k];
}

int getL(int n) {
    if (n == 1)
        return 0;

    int h = log_2[n];
    int p = n - ((1 << (h)) - 1);
    int m = (1 << h);
    if (p >= (m / 2))
        return (1 << (h)) - 1;
    else
        return (1 << (h)) - 1 - ((m / 2) - p);
}

long long int getNumberOfMaxHeaps(int n) {
    if (n <= 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    int L = getL(n);
    long long int ans = (choose(n - 1, L) * getNumberOfMaxHeaps(L)) % MOD * (getNumberOfMaxHeaps(n - 1 - L));
    ans %= MOD;
    dp[n] = ans;
    return ans;
}
long long int getNumberOfMaxHeaps2(int n) {
    if (n < 2)
        return (long long int) 0;
    if (n < 4)
        return (long long int) 1;
    if (n == 4)
        return (long long int) 2;
    if (n == 5)
        return (long long int) 4;
    if (dp1[n] != 0)
        return dp1[n];
    int l = getL(n);
    int r = n - l - 1;
    long long int ans = (((choose(n - 3, l - 2) * getNumberOfMaxHeaps2(l)) % MOD) * getNumberOfMaxHeaps(r)) % MOD;
    ans = (ans + (((choose(n - 3, r - 2) * getNumberOfMaxHeaps(l)) % MOD) * getNumberOfMaxHeaps2(r)) % MOD) % MOD;
    ans = (ans + (((choose(n - 3, l - 1) * getNumberOfMaxHeaps(l)) % MOD) * getNumberOfMaxHeaps(r)) % MOD) % MOD;
    dp1[n] = ans;
    return ans;
}

int Solution::solve(vector < int > & arr) {
    compute();
    int n = arr.size();
    for (int i = 0; i <= n; i++) {
        dp[i] = -1;
        dp1[i] = 0;
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            nck[i][j] = -1;

    int currlog_2Answer = -1;
    int currPower2 = 1;
    for (int i = 1; i <= n; i++) {
        if (currPower2 == i) {
            currlog_2Answer++;
            currPower2 *= 2;
        }
        log_2[i] = currlog_2Answer;
    }
    int max = -1;
    int min = 10000000;
    int maxcount = 0;
    int mincount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            mincount = 1;
        } else if (arr[i] == min) {
            mincount++;
        }
        if (arr[i] > max) {
            max = arr[i];
            maxcount = 1;
        } else if (arr[i] == max) {
            maxcount++;
        }
    }
    if (maxcount == 2)
        return (int) getNumberOfMaxHeaps(n);
    else
        return (int) getNumberOfMaxHeaps2(n);
}