/*
Q10. Inversion Count In an array
Problem Description
Given an array of integers A. If i < j and A[i] > A[j], then the pair (i, j) is called an inversion of A. Find the total number of inversions of A modulo (109 + 7).

Problem Constraints
1 <= length of the array <= 105
1 <= A[i] <= 109

Input Format
The only argument given is the integer array A.

Output Format
Return the number of inversions of A modulo (109 + 7).

Example Input
Input 1:
A = [1, 3, 2]
Input 2:
A = [3, 4, 1, 2]

Example Output
Output 1:
1
Output 2:
4

Example Explanation
Explanation 1:
The pair (1, 2) is an inversion as 1 < 2 and A[1] > A[2]
Explanation 2:
The pair (0, 2) is an inversion as 0 < 2 and A[0] > A[2]
The pair (0, 3) is an inversion as 0 < 3 and A[0] > A[3]
The pair (1, 2) is an inversion as 1 < 2 and A[1] > A[2]
The pair (1, 3) is an inversion as 1 < 3 and A[1] > A[3]

*/
long long _mergeSort(int arr[], int temp[], int left, int right);
long long merge(int arr[], int temp[], int left, int mid, int right);
int hell = 1000000007;

/* This function sorts the input array and returns the  
number of inversions in the array */
int mergeSort(int arr[], int array_size) {
    int temp[array_size];
    return _mergeSort(arr, temp, 0, array_size - 1) % hell;
}

/* An auxiliary recursive function that sorts the input array and  
returns the number of inversions in the array. */
long long _mergeSort(int arr[], int temp[], int left, int right) {
    long long mid, inv_count = 0;
    if (right > left) {
        /* Divide the array into two parts and  
        call _mergeSortAndCountInv()  
        for each of the parts */
        mid = (right + left) / 2;
        /* Inversion count will be sum of  
        inversions in left-part, right-part  
        and number of inversions in merging */
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count % hell;
}

/* This funt merges two sorted arrays  
and returns inversion count in the arrays.*/
long long merge(int arr[], int temp[], int left, int mid, int right) {
    int i, j, k;
    long long inv_count = 0;
    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            /* this is tricky -- see above  
            explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i);
        }
    }
    /* Copy the remaining elements of left subarray  
            (if there are any) to temp*/
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    /* Copy the remaining elements of right subarray  
            (if there are any) to temp*/
    while (j <= right)
        temp[k++] = arr[j++];
    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++)
        arr[i] = temp[i];
    return inv_count % hell;
}

int Solution::solve(vector < int > & A) {
    int n = A.size();
    int a[n];
    for (int i = 0; i < n; i++)
        a[i] = A[i];
    return mergeSort(a, n);
}