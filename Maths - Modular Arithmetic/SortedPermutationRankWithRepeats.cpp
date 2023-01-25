/*
Q24. Sorted Permutation Rank With Repeats
Problem Description
Given a string A, find the rank of the string amongst its permutations sorted lexicographically. Note that the characters might be repeated. If the characters are repeated, we need to look at the rank in unique permutations. Look at the example for more details.
NOTE:
The answer might not fit in an integer, so return your answer % 1000003 where 1000003 is a prime number.
String A can consist of both lowercase and uppercase letters. Characters with lesser ASCII values are considered smaller, i.e., 'a' > 'Z'.

Problem Constraints
1 <= len(A) <= 1000000

Input Format
First argument is a string A.

Output Format
Return an integer denoting the rank.

Example Input
Input 1:
 A = "aba"
Input 2:
 A = "bca"

Example Output
Output 1:
 2
Output 2:
 4

Example Explanation
Explanation 1:
 The order permutations with letters 'a', 'a', and 'b' :
    aab
    aba 
    baa
 So, the rank is 2.
Explanation 2:
 The order permutations with letters 'a', 'b', and 'c' :
    abc
    acb 
    bac
    bca
    cab
    cba
 So, the rank is 4.

*/
#define MOD 1000003

void initializeFactorials(int totalLen, vector<int> &fact) {
    // calculates factorial
    long long int factorial = 1;
    fact.push_back(1);
    for (int curIndex = 1; curIndex < totalLen; curIndex++) {
        factorial = (factorial * curIndex) % MOD;
        fact.push_back(factorial);
    }
    return;
}

long long int inverseNumber(int num) {
    // Find the modular multiplicative inverse
    // Calculates (num ^ (MOD - 2)) % MOD
    long long int ans = 1, base = (long long) num;
    int power = MOD - 2;
    while (power > 0) {
        if (power == 1) {
            return (ans * base) % MOD;
        }
        if (power % 2 == 0) {
            base = (base * base) % MOD;
            power /= 2;
        } else {
            ans = (ans * base) % MOD;
            power--;
        }
    }
    return ans;
}

int Solution::findRank(string A) {
    // Initializations
    int charCount[256]; // count of characters in A. 
    memset(charCount, 0, sizeof(charCount));
    for (int i = 0; i < A.length(); i++) {
        charCount[A[i]]++;
    }
    vector<int> fact; // fact[i] will contain i! % MOD
    initializeFactorials(A.length() + 1, fact);

    long long int rank =  1;
    for (int i = 0; i < A.length(); i++) {
        // find number of permutations placing character smaller than A[i] at ith position 
        // among characters from i to A.length 
        long long int less = 0;
        int remaining = A.length() - i - 1;
        for (int ch = 0; ch < A[i]; ch++) {
            if (charCount[ch] == 0) continue;
            // Lets try placing ch as the first character in remaining characters
            // and check the number of permutation possible.
            charCount[ch]--;
            long long int numPermutation = fact[remaining];
            for (int c = 0; c < 128; c++) {
                if (charCount[c] <= 1) continue; 
                numPermutation = (numPermutation * inverseNumber(fact[charCount[c]])) % MOD;
            }
            charCount[ch]++;
            less = (less + numPermutation) % MOD;
        }
        rank = (rank + less) % MOD;
        // remove the current character from the set. 
        charCount[A[i]]--;
    }
    return rank;
}