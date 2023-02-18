/*
Q9. Kth Smallest Element in BST
Problem Description
Given a binary search tree represented by root A, write a function to find the Bth smallest element in the tree.

Problem Constraints
1 <= Number of nodes in binary tree <= 100000
0 <= node values <= 10^9

Input Format
First and only argument is head of the binary tree A.

Output Format
Return an integer, representing the Bth element.

Example Input
Input 1:
 
            2
          /   \
         1    3
B = 2
Input 2:
 
            3
           /
          2
         /
        1
B = 1

Example Output
Output 1:
 2
Output 2:
 1

Example Explanation
Explanation 1:
2nd element is 2.
Explanation 2:
1st element is 1.

*/
void inorder(TreeNode* root, int &ans, int &cnt, int &B){
    if(root == NULL) return;
    inorder(root->left, ans, cnt, B);
    cnt++;
    if(cnt == B){
        ans = root->val;
        return;
    }
    inorder(root->right, ans, cnt, B);
}

int Solution::kthsmallest(TreeNode* A, int B) {
    int ans = 0, cnt = 0;
    inorder(A, ans, cnt, B);
    return ans;

}