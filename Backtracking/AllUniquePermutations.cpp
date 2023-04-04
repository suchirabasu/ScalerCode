/*
Q4. All Unique Permutations
Problem Description
Given an array A of size N denoting collection of numbers that might contain duplicates, return all possible unique permutations.
NOTE: No 2 entries in the permutation sequence should be the same.
WARNING: DO NOT USE LIBRARY FUNCTION FOR GENERATING PERMUTATIONS. 
Example : next_permutations in C++ / itertools.permutations in python.
If you do, we will disqualify your submission retroactively and give you penalty points.

Problem Constraints
1 <= |A| <= 9
0 <= A[i] <= 10

Input Format
Only argument is an integer array A of size N.

Output Format
Return a 2-D array denoting all possible unique permutation of the array.

Example Input
Input 1:
A = [1, 1, 2]
Input 2:
A = [1, 2]

Example Output
Output 1:
[ [1,1,2]
  [1,2,1]
  [2,1,1] ]
Output 2:
[ [1, 2]
  [2, 1] ]

Example Explanation
Explanation 1:
 All the possible unique permutation of array [1, 1, 2].
Explanation 2:
 All the possible unique permutation of array [1, 2].

*/
void findPermutations(int n, vector<int> &temp, vector<vector<int>> &ans, unordered_map<int, int> &umap) {
    if(temp.size() == n) {
        ans.push_back(temp);
    }

    for(auto [key, value] : umap) {
        if(value > 0) {
            temp.push_back(key); umap[key]--;
            findPermutations(n, temp, ans, umap);
            temp.pop_back(); umap[key]++;
        }
    }
}

vector<vector<int> > Solution::permute(vector<int> &A) {
    unordered_map<int, int> umap;
    vector<int> temp;
    vector<vector<int>> ans;
    for(int i=0; i<A.size(); i++) {
        umap[A[i]]++;
    }

    findPermutations(A.size(), temp, ans, umap);

    return ans;
}
