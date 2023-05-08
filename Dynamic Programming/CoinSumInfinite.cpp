/*
Q23. Coin Sum Infinite
Problem Description
You are given a set of coins A. In how many ways can you make sum B assuming you have infinite amount of each coin in the set.
NOTE:
Coins in set A will be unique. Expected space complexity of this problem is O(B).
The answer can overflow. So, return the answer % (106 + 7).

Problem Constraints
1 <= A <= 500
1 <= A[i] <= 1000
1 <= B <= 50000

Input Format
First argument is an integer array A representing the set.
Second argument is an integer B.

Output Format
Return an integer denoting the number of ways.

Example Input
Input 1:
 A = [1, 2, 3]
 B = 4
Input 2:
 A = [10]
 B = 10

Example Output
Output 1:
 4
Output 2:
 1

Example Explanation
Explanation 1:
 The 4 possible ways are:
 {1, 1, 1, 1}
 {1, 1, 2}
 {2, 2}
 {1, 3} 
Explanation 2:
 There is only 1 way to make sum 10.

*/
int Solution::coinchange2(vector<int> &A, int B) {
    vector< vector< int > > numberOfWays(2, vector< int >(B+1, 0));

    numberOfWays[0][0] = 1, numberOfWays[1][0] = 1;

    int mod = 1000007;
    int row = 0;
    for(int i=1;i<=A.size();i++){
        for(int j=1;j<=B;j++){
            if( j - A[i-1] >= 0 ){
                numberOfWays[row ^ 1][j] = numberOfWays[row ^ 1][j - A[i-1]] + numberOfWays[row][j];
            } else {
                numberOfWays[row ^ 1][j] = numberOfWays[row][j];
            }
            numberOfWays[row ^ 1][j] %= mod;
        }
        row ^= 1;
    }

    return numberOfWays[row][B];
}