/*
Q33. Russian Doll Envelopes
Problem Description
Given a matrix of integers A of size N x 2 describing dimensions of N envelopes, where A[i][0] denotes the height of the ith envelope and A[i][1] denotes the width of the ith envelope.
One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
Find the maximum number of envelopes you can put one inside other.

Problem Constraints
1 <= N <= 1000
1 <= A[i][0], A[i][1] <= 109

Input Format
The only argument given is the integer matrix A.

Output Format
Return an integer denoting the maximum number of envelopes you can put one inside other.

Example Input
Input 1:
 A = [ 
         [5, 4]
         [6, 4]
         [6, 7]
         [2, 3]  
     ]
Input 2:
 A = [     '
         [8, 9]
         [8, 18]    
     ]

Example Output
Output 1:
 3
Output 2:
 1

Example Explanation
Explanation 1:
 Step 1: put [2, 3] inside [5, 4]
 Step 2: put [5, 4] inside [6, 7]
 3 envelopes can be put one inside other.
Explanation 2:
 No envelopes can be put inside any other so answer is 1.

*/
bool comp(const pair<int, int> &a, const pair<int, int> &b) {
    if (a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    vector<pair<int, int> > pr;
    for (int i = 0; i < n; i++)
        pr.push_back({A[i][0], A[i][1]});
    // sort vector of pair {height, width}
    sort(pr.begin(), pr.end(), comp);
    // Bottom Up DP Approach to find LIS
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++) {
        lis[i] = 1;
        for (int j = 0; j < i; j++) {
            if (pr[i].second > pr[j].second && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
        }
    }
    return *max_element(lis, lis + n);
}