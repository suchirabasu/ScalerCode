/*
Q10. Min Sum Path In Triangle
Problem Description
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
Adjacent numbers for jth column of ith row is jth and (j+1)th column of (i + 1)th row

Problem Constraints
|A| <= 1000
A[i] <= 1000

Input Format
First and only argument is the vector of vector A defining the given triangle

Output Format
Return the minimum sum

Example Input
Input 1:
A = [ 
         [2],
        [3, 4],
       [6, 5, 7],
      [4, 1, 8, 3]
    ]
Input 2:
 A = [ [1] ]

Example Output
Output 1:
 11
Output 2:
 1

Example Explanation
Explanation 1:
 The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Explanation 2:
 Only 2 can be collected.

*/
int Solution::minimumTotal(vector<vector<int> > &A) {
    vector<int> minSum(A.size());

    int ans = INT_MAX;
    
    for(int i=0;i<A.size();i++){
        for(int j=A[i].size()-1;j>=0;j--){

            if(i>0){
                int topLeft, topRight;
            
                if (j-1 < 0) topLeft = INT_MAX;
                else topLeft = minSum[j-1];
                
                if(j >= A[i-1].size()) topRight = INT_MAX;
                else topRight = minSum[j];

                minSum[j] = min(topLeft, topRight) + A[i][j];
            } else {
                minSum[i] = A[i][i];
            }
            if(i==A.size()-1){
                if(minSum[j] < ans)
                    ans = minSum[j];
            }
        }
    }
    return ans;
}
