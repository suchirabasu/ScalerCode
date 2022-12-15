/*
Q3. Postorder Traversal
Problem Description
Given a binary tree, return the Postorder traversal of its nodes values.
NOTE: Using recursion is not allowed.

Problem Constraints
1 <= number of nodes <= 105

Input Format
First and only argument is root node of the binary tree, A.

Output Format
Return an integer array denoting the Postorder traversal of the given binary tree.

Example Input
Input 1:
   1
    \
     2
    /
   3
Input 2:
   1
  / \
 6   2
    /
   3

Example Output
Output 1:
 [3, 2, 1]
Output 2:
 [6, 3, 2, 1]

Example Explanation
Explanation 1:
 The Preoder Traversal of the given tree is [3, 2, 1].
Explanation 2:
 The Preoder Traversal of the given tree is [6, 3, 2, 1].

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
vector<int> Solution::postorderTraversal(TreeNode* A) {
    TreeNode* currentNode;
    TreeNode* processedNode = NULL;
    stack<TreeNode*> S;
    vector<int> ans;

    currentNode = A;

    while ((currentNode != NULL) || (!S.empty()))
    {
        while (currentNode != NULL)
        {
            S.push(currentNode);
            currentNode = currentNode->left;
        }
        // Now we reached the extreme Left Node;
        // So, we process Left node, followed by Right Node and then Parent/Root node.
        // Next, check for Right Node:
        // If there is no Right Child, and has only nested Left Child, then below
        // While loop with process them, else if there is a right child any where during
        // traversal, then again we need to start with outer While() loop that is through
        // currentNode = S.Top()->right;
        while(!S.empty())
        {
            // Check if current Top node in stack has any right node or not,
            // if S.top() node doesn't have any right node, then we can process
            // S.top() node because that as per Post Order Traversal.
            // There is one more scenario, where curretly processed/POP'ed node
            // can either be a left or right child of S.top() node, when currently
            // processed node is a right child then Parent that is S.top() can be
            // Processed.            
            if (((S.top())->right == NULL) || (processedNode == (S.top())->right))
            {
                processedNode = S.top();
                ans.push_back(processedNode->val);
                S.pop();
                continue;
            }
            else // if (processedNode == (S.top())->left)
            {
                currentNode = (S.top())->right;
                break;
            }
        }
    }

    return ans;
}
