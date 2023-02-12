/*
Q16. Quick Sort
Problem Description
Given an integer array A, sort the array using QuickSort.

Problem Constraints
1 <= |A| <= 105
1 <= A[i] <= 109

Input Format
First argument is an integer array A.

Output Format
Return the sorted array.

Example Input
Input 1:
 A = [1, 4, 10, 2, 1, 5]
Input 2:
 A = [3, 7, 1]

Example Output
Output 1:
 [1, 1, 2, 4, 5, 10]
Output 2:
 [1, 3, 7]

Example Explanation
Explanation 1:
 Return the sorted array.

*/
int partition(vector<int> &A, int low, int high) {
    int pivot = A[low];
    int i = low;
    int j = high;
    while(i<j) {
        while(i<=high-1 && A[i]<=pivot) {
            i++;
        }
        while(j>=low && pivot<A[j]) {
            j--;
        }
        if(i<j) {
            swap(A[i], A[j]);
        }
    }
    swap(A[j], A[low]);
    return j;
}

void quickSort(vector<int> &A, int low, int high) {
    if(low>=high) {
        return ;
    }
    if(low<high) {
        int pivot = partition(A, low, high);
        quickSort(A, low, pivot-1);
        quickSort(A, pivot+1, high);
    }
}

vector<int>Solution::solve(vector<int> &A) {
    quickSort(A, 0, A.size()-1);
    return A;
}