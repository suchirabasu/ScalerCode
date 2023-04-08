/*
Q8. Subsets II
Problem Description
Given a collection of integers denoted by array A of size N that might contain duplicates, return all possible subsets.
NOTE:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
The subsets must be sorted lexicographically.

Problem Constraints
0 <= N <= 16

Input Format
Only argument is an integer array A of size N.

Output Format
Return a 2-D vector denoting all the possible subsets.

Example Input
Input 1:
 A = [1, 2, 2]
Input 2:
 A = [1, 1]

Example Output
Output 1:
 [
    [],
    [1],
    [1, 2],
    [1, 2, 2],
    [2],
    [2, 2]
 ]
Output 2:
 [
    [],
    [1],
    [1, 1]
 ]

Example Explanation
Explanation 1:
All the subsets of the array [1, 2, 2] in lexicographically sorted order.
*/
void findSubsets(vector<int>&A,int n,int i,
               set<vector<int>>&ans,vector<int>&temp){
    if(i==n){
        ans.insert(temp);
        return;
    }
    temp.push_back(A[i]);
    findSubsets(A,n,i+1,ans,temp);
    temp.pop_back();
    findSubsets(A,n,i+1,ans,temp);
}
vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    sort(A.begin(),A.end());
    set<vector<int>> hs;
    vector<vector<int>> ans;
    vector<int> temp;
    findSubsets(A,A.size(),0,hs,temp);
    for(auto i:hs){
        ans.push_back(i);
    }
    return ans;
}