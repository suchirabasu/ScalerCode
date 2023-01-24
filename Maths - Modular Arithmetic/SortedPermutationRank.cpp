/*
Q23. Sorted Permutation Rank
Problem Description
Given a string A. Find the rank of the string amongst its permutations sorted lexicographically.
Assume that no characters are repeated.
Note: The answer might not fit in an integer, so return your answer % 1000003

Problem Constraints
1 <= |A| <= 1000

Input Format
First argument is a string A.

Output Format
Return an integer denoting the rank of the given string.

Example Input
Input 1:
A = "acb"
Input 2:
A = "a"

Example Output
Output 1:
2
Output 2:
1

Example Explanation
Explanation 1:
Given A = "acb".
The order permutations with letters 'a', 'c', and 'b' : 
abc
acb
bac
bca
cab
cba
So, the rank of A is 2.
Explanation 2:
Given A = "a".
Rank is clearly 1.

*/
int mod = 1000003;
int getLessCharOnRight(string &A, int i){
    int countlessChar = 0;
    for(int j = i+1; j < A.length(); j++){
        if(A[i] > A[j]) countlessChar++;
    }
    return countlessChar % mod;
}
long fact(long number){
    if(number == 0 || number == 1) 
        return number;
    return (number * fact(number - 1)) % mod;
}
long getPermutation(int size, int i){
    return fact(size - i - 1) % mod;
}
int Solution::findRank(string A) {
    long rankOfString = 0;
    for(int i = 0; i < A.length(); i++){
        long lessCharOnRight = getLessCharOnRight(A, i);
        long permutationCount = getPermutation(A.size(), i);
        rankOfString += (lessCharOnRight * permutationCount) % mod;
    }
    return (rankOfString + 1) % mod;
}