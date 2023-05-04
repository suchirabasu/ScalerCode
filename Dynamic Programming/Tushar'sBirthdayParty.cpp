/*
Q19. Tushar's Birthday Party
Problem Description
As it is Tushar's Birthday on March 1st, he decided to throw a party to all his friends at TGI Fridays in Pune. Given are the eating capacity of each friend, filling capacity of each dish and cost of each dish. A friend is satisfied if the sum of the filling capacity of dishes he ate is equal to his capacity. Find the minimum cost such that all of Tushar's friends are satisfied (reached their eating capacity).
NOTE:
Each dish is supposed to be eaten by only one person. Sharing is not allowed.
Each friend can take any dish unlimited number of times.
There always exists a dish with filling capacity 1 so that a solution always exists.

Problem Constraints
|A| <= 1000
|B| <= 1000
|C| <= 1000

Input Format
First Argument is vector A, denoting eating capacities
Second Argument is vector B, denoting filling capacities
Third Argument is vector C, denoting cost

Output Format
Return a single integer, the answer to the problem

Example Input
Input 1:
A = [2, 4, 6]
B = [2, 1, 3]
C = [2, 5, 3]
Input 2:
A = [2]
B = [1]
C = [2]

Example Output
Output 1:
12
Output 2:
4

Example Explanation
Explanation 1:
First friend takes dish 1, Second friend takes dish 1 twice and third friend takes dish 3 twice.
So 2 + 2*2 + 3*2 = 12.
Explanation 2:
Only way is to take 2 dishes of cost 2, hence 4.

*/
int Solution::solve(const vector<int> &A, const vector<int> &B, const vector<int> &C) {
    
    //creating a 2d dp array
    int maxEatingCapacity = 0;
    for(int i=0;i<A.size();i++)
        if(A[i] > maxEatingCapacity)
            maxEatingCapacity = A[i];
    
    vector< vector< int > > minCost(2, vector< int >(maxEatingCapacity+1, INT_MAX));
    minCost[0][0] = 0;
    minCost[1][0] = 0;
    int row = 0;

    for(int i=0;i<B.size();i++){
        for(int j=1;j<=maxEatingCapacity;j++){
            if(B[i] <= j) {
                if(minCost[row][j] == INT_MAX && minCost[row ^ 1][j-B[i]] == INT_MAX) minCost[row ^ 1][j] = INT_MAX;
                else if(minCost[row ^ 1][j - B[i]] == INT_MAX) minCost[row ^ 1][j] = minCost[row][j];
                else minCost[row ^ 1][j] = min( minCost[row][j], C[i] + minCost[row ^ 1][j - B[i]] );             
            }
            else minCost[row ^ 1][j] = minCost[row][j];
            if(minCost[row ^ 1][j] <= 0) minCost[row ^ 1][j] = INT_MAX;
            
        }
        row ^= 1;           
    }
    
    int ans = 0;
    for(int i=0;i<A.size();i++){
        ans += minCost[row][A[i]];
    }
    
    return ans;
}