/*
Q12. Max Rectangle in Binary Matrix
Problem Description
Given a 2-D binary matrix A of size N x M filled with 0's and 1's, find the largest rectangle containing only ones and return its area.

Problem Constraints
1 <= N, M <= 100

Input Format
The first argument is a 2-D binary array A.

Output Format
Return an integer denoting the area of the largest rectangle containing only ones.

Example Input
Input 1:
 A = [
       [1, 1, 1]
       [0, 1, 1]
       [1, 0, 0] 
     ]
Input 2:
 A = [
       [0, 1, 0]
       [1, 1, 1]
     ] 

Example Output
Output 1:
 4
Output 2:
 3

Example Explanation
Explanation 1:
 As the max area rectangle is created by the 2x2 rectangle created by (0, 1), (0, 2), (1, 1) and (1, 2).
Explanation 2:
 As the max area rectangle is created by the 1x3 rectangle created by (1, 0), (1, 1) and (1, 2).

*/
int maxHistogramArea(vector<int> &A) {
    int N = A.size();
    int ans = 0;

    vector<int> leftMinIndex(N, 0);
    vector<int> rightMinIndex(N, N-1);
    stack<int> s;
   
    for(int i=0; i<N; i++) {
        while(!s.empty() && A[s.top()] >= A[i])
            s.pop();

        leftMinIndex[i] = (!s.empty()) ? s.top() + 1 : 0;
        s.push(i);
    }

    while(!s.empty())
        s.pop();
   
    for(int i=N-1; i>=0; i–) {
        while(!s.empty() && A[s.top()] >= A[i])
            s.pop();

        rightMinIndex[i] = (!s.empty()) ? s.top() - 1 : N-1;
        s.push(i);
    }
   
    for(int i=0; i<N; i++) {
        int width = rightMinIndex[i] - leftMinIndex[i] + 1;
        int height = A[i];
        ans = max(ans, width * height);
    }

    return ans;
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    int ans = 0;

    for(int i=0; i<A[0].size(); i++)
        ans = max(ans, maxHistogramArea(A[0]));

    for(int i=1; i<A.size(); i++) {

        for(int j=0; j<A[0].size(); j++) {
            if(A[i][j] == 1)
                A[i][j] += A[i - 1][j];
        }

        ans = max(ans, maxHistogramArea(A[i]));
    }

    return ans;
}