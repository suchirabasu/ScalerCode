/*
Q18. Maximum Unsorted Subarray
Problem Description
Given an array A of non-negative integers of size N. Find the minimum sub-array Al, Al+1 ,..., Ar such that if we sort(in ascending order) that sub-array, then the whole array should get sorted. If A is already sorted, output -1.

Problem Constraints
1 <= N <= 1000000
1 <= A[i] <= 1000000

Input Format
First and only argument is an array of non-negative integers of size N.

Output Format
Return an array of length two where the first element denotes the starting index(0-based) and the second element denotes the ending index(0-based) of the sub-array. If the array is already sorted, return an array containing only one element i.e. -1.

Example Input
Input 1:
A = [1, 3, 2, 4, 5]
Input 2:
A = [1, 2, 3, 4, 5]

Example Output
Output 1:
[1, 2]
Output 2:
[-1]

Example Explanation
Explanation 1:
If we sort the sub-array A1, A2, then the whole array A gets sorted.
Explanation 2:
A is already sorted.

*/
void merge(vector<int> &A, int l, int m, int h, int &firstIndex, int &lastIndex){
    int temp[h-l+1];
    int p1 = l, p2 = m+1, tempPtr = 0;
    while(p1<=m && p2<=h){
        if(A[p1]<=A[p2])
            temp[tempPtr++] = A[p1++];
        else{
            if(p1<firstIndex)
                firstIndex = p1;
            if(p2>lastIndex)
                lastIndex = p2;
            temp[tempPtr++] = A[p2++];
        }
    }
    while(p1<=m)
        temp[tempPtr++] = A[p1++];
    while(p2<=h)
        temp[tempPtr++] = A[p2++];
    for(int i=0;i<(h-l+1);i++){
        A[l+i] = temp[i];
    }
}

void mergeSort(vector<int> &A, int l, int h, int &firstIndex, int &lastIndex){
    if(l>=h)
        return;
    int m = (l+h)/2;
    mergeSort(A, l, m, firstIndex, lastIndex);
    mergeSort(A, m+1, h, firstIndex, lastIndex);
    merge(A, l, m, h, firstIndex, lastIndex);
}

vector<int> Solution::subUnsort(vector<int> &A) {
    int firstIndex = INT_MAX, lastIndex = INT_MIN;
    mergeSort(A, 0, A.size()-1, firstIndex, lastIndex);
    if(firstIndex==INT_MAX)
        return {-1};
    return {firstIndex, lastIndex};
}