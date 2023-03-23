/*
Q15. Special Median
Problem Description
You are given an array A containing N numbers. This array is called special if it satisfies one of the following properties:
There exists an element A[i] in the array such that A[i] is equal to the median of elements [A[0], A[1], ...., A[i-1]]
There exists an element A[i] in the array such that A[i] is equal to the median of elements [A[i+1], A[i+2], ...., A[N-1]]
The Median is the middle element in the sorted list of elements. If the number of elements is even then the median will be (sum of both middle elements) / 2.
Return 1 if the array is special else return 0.
NOTE:
Do not neglect decimal point while calculating the median
For A[0] consider only the median of elements [A[1], A[2], ..., A[N-1]] (as there are no elements to the left of it)
For A[N-1] consider only the median of elements [A[0], A[1], ...., A[N-2]]

Problem Constraints
1 <= N <= 1000000.
A[i] is in the range of a signed 32-bit integer.

Input Format
The first and only argument is an integer array A.

Output Format
Return 1 if the given array is special else return 0.

Example Input
Input 1:
 A = [4, 6, 8, 4]
Input 2:
 A = [2, 7, 3, 1]

Example Output
Output 1:
 1
Output 2:
 0

Example Explanation
Explantion 1:
 Here, 6 is equal to the median of [8, 4].
Explanation 2:
 No element satisfies any condition.

*/
int Solution::solve(vector<int> &A) {
    priority_queue<int>max_heap;
    priority_queue<int,vector<int>,greater<int>>min_heap;
    max_heap.push(A[0]);
    for(int i=1;i<A.size();i++){
        int x=max_heap.top();
        if(max_heap.size()==min_heap.size()){
    //cout<<max_heap.top()<<","<<min_heap.top()<<endl;
    //cout<<(max_heap.top()+min_heap.top())/2;
            if(A[i]==((double)max_heap.top()+min_heap.top())/2) return 1;
        }
        else{
            if(A[i]==max_heap.top()) return 1;
        }
        if(A[i]<=x){
            max_heap.push(A[i]);
            if((max_heap.size()-min_heap.size())>1){
                min_heap.push(max_heap.top());
                max_heap.pop();
            }
        }
        else{
            min_heap.push(A[i]);
            if(min_heap.size()-max_heap.size()>=1){
                max_heap.push(min_heap.top());
                min_heap.pop();
            }
        }
    }
    int n=A.size();
    priority_queue<int>max_heap1;
    priority_queue<int,vector<int>,greater<int>>min_heap1;
    max_heap1.push(A[n-1]);
    for(int i=n-2;i>=0;i--){
        int x=max_heap1.top();
        if(max_heap1.size()==min_heap1.size()){
            if(A[i]==((double)max_heap1.top()+min_heap1.top())/2) return 1;
        }
        else{
            if(A[i]==max_heap1.top()) return 1;
        }
        if(A[i]<=x){
            max_heap1.push(A[i]);
            if((max_heap1.size()-min_heap1.size())>1){
                min_heap1.push(max_heap1.top());
                max_heap1.pop();
            }
        }
        else{
            min_heap1.push(A[i]);
            if(min_heap1.size()-max_heap1.size()>=1){
                max_heap1.push(min_heap1.top());
                min_heap1.pop();
            }
        }
    }
    return 0;
}
