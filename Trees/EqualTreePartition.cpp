/*
Q18. Equal Tree Partition
Problem Description
Given a binary tree A. Check whether it is possible to partition the tree to two trees which have equal sum of values after removing exactly one edge on the original tree.

Problem Constraints
1 <= size of tree <= 100000
0 <= value of node <= 109

Input Format
First and only argument is head of tree A.

Output Format
Return 1 if the tree can be partitioned into two trees of equal sum else return 0.

Example Input
Input 1:
                5
               /  \
              3    7
             / \  / \
            4  6  5  6
Input 2:
                1
               / \
              2   10
                  / \
                 20  2

Example Output
Output 1:
 1
Output 2:
 0

Example Explanation
Explanation 1:
 Remove edge between 5(root node) and 7: 
        Tree 1 =                                               Tree 2 =
                        5                                                     7
                       /                                                     / \
                      3                                                     5   6    
                     / \
                    4   6
        Sum of Tree 1 = Sum of Tree 2 = 18
Explanation 2:
 The given Tree cannot be partitioned.

*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
long long sumOfNodes(TreeNode* root, long long sum, unordered_set<long long> &uset){
    if(root==NULL) return sum;
    sum += root->val + sumOfNodes(root->left, sum, uset) + sumOfNodes(root->right, sum, uset);
    uset.insert(sum);
    return sum;
}

int Solution::solve(TreeNode* A) {
    unordered_set<long long> uset;
    long long finalSum = sumOfNodes(A, 0, uset);
    if(finalSum&1) return 0;  //if sum is odd then there can't be 2 equal sub trees
    if(uset.find(finalSum/2)!=uset.end()) return 1;
    return 0;
}
