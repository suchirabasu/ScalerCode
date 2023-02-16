/*
Q3. Matrix Median
Problem Description
Given a matrix of integers A of size N x M in which each row is sorted. Find and return the overall median of matrix A.
NOTE: No extra memory is allowed.
NOTE: Rows are numbered from top to bottom and columns are numbered from left to right.

Problem Constraints
1 <= N, M <= 10^5
1 <= N*M <= 10^6
1 <= A[i] <= 10^9
N*M is odd

Input Format
The first and only argument given is the integer matrix A.

Output Format
Return the overall median of matrix A.

Example Input
Input 1:
A = [   [1, 3, 5],
        [2, 6, 9],
        [3, 6, 9]   ] 
Input 2:
A = [   [5, 17, 100]    ]

Example Output
Output 1:
 5 
Output 2:
 17

Example Explanation
Explanation 1:
A = [1, 2, 3, 3, 5, 6, 6, 9, 9]
Median is 5. So, we return 5. 
Explanation 2:
Median is 17.

*/
int upperBoundInMatrix(const vector<vector<int> > &A, int k)
{
    int countUpperBound = 0 ;

    for(int i=0; i<A.size(); i++)
        countUpperBound+= upper_bound(A[i].begin(), A[i].end(), k) - A[i].begin() ;

    return countUpperBound ;
}

int Solution::findMedian(vector<vector<int> > &A) {

    int l= INT_MAX ;
    int r= INT_MIN ;

    for(int i=0; i<A.size(); i++)
    {
        r=max(r, A[i].back()) ;
        l=min(l, A[i].front()) ;
    }

    int mid ;

    const int rankMedian = (A.size()*A[0].size() +1)/2 ;

    int countSmallerElements ;

    while(l<=r)
    {
        mid = (l+r)/2 ;

        countSmallerElements = upperBoundInMatrix(A, mid) ;

        if(countSmallerElements < rankMedian)
            l = mid +1 ;

        else
            r=mid-1 ;
    }

    return l ;
}