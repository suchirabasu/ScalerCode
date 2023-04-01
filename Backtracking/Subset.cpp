/*
Q1. Subset
Problem Description
Given a set of distinct integers A, return all possible subsets.
NOTE:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
Also, the subsets should be sorted in ascending ( lexicographic ) order.
The list is not necessarily sorted.

Problem Constraints
1 <= |A| <= 16
INTMIN <= A[i] <= INTMAX

Input Format
First and only argument of input contains a single integer array A.

Output Format
Return a vector of vectors denoting the answer.

Example Input
Input 1:
A = [1]
Input 2:
A = [1, 2, 3]

Example Output
Output 1:
[
    []
    [1]
]
Output 2:
[
 []
 [1]
 [1, 2]
 [1, 2, 3]
 [1, 3]
 [2]
 [2, 3]
 [3]
]

Example Explanation
Explanation 1:
 You can see that these are all possible subsets.
Explanation 2:
You can see that these are all possible subsets.

*/
void generate(int N,vector<int>& A,vector<int> &list,vector<vector<int>> &ans,int index){
        if(index>=N)
        {
            ans.push_back(list);
            return;
        }
         list.push_back(A[index]);
         generate(N,A,list,ans,index+1);
         list.pop_back();
          generate(N,A,list,ans,index+1);
       

     }

vector<vector<int> > Solution::subsets(vector<int> &A) {
        sort(A.begin(), A.end());
       vector<int> list;
       vector<vector<int>> ans;
       generate(A.size(),A,list,ans,0);
       sort(ans.begin(), ans.end());
        return ans;
       
    }