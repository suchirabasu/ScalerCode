/*
Q9. N Queens
Problem Description
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
Given an integer A, return all distinct solutions to the n-queens puzzle.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
The final list should be generated in such a way that the indices of the queens in each list should be in reverse lexicographical order.

Problem Constraints
1 <= A <= 10

Input Format
First argument is an integer n denoting the size of chessboard

Output Format
Return an array consisting of all distinct solutions in which each element is a 2d char array representing a unique solution.

Example Input
Input 1:
A = 4
Input 2:
A = 1

Example Output
Output 1:
[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
Output 1:
[
 [Q]
]
*/
bool canItBePlacedInHSet(vector<string> curr, int row, int col, set<int> &hsC, set<int> &hsLD, set<int> &hsRD) {
    int r = row;
    int c = col;

    if (hsC.find(col) != hsC.end())
    {
            return false;
    }
   
    if (hsLD.find(row - col) != hsLD.end())
    {
        return false;
    }
   
    if (hsRD.find(row + col) != hsRD.end())
    {
        return false;
    }

    return true;
}

void solveNQueensUtil(vector<vector<string> >&ans, vector<string> &curr , int row, set<int> &hsC, set<int> &hsLD, set<int> &hsRD, int n) {
    if(row == n) {
        ans.push_back(curr);
        return;
    }

    for(int col = 0; col < n; col++) {
        if(canItBePlacedInHSet(curr, row, col, hsC, hsLD, hsRD)) {
            curr[row][col] = 'Q';
            hsC.insert(col);
            hsLD.insert(row - col);
            hsRD.insert(row + col);
            solveNQueensUtil(ans, curr, row + 1, hsC, hsLD, hsRD, n);
           
            // Backtrack
            curr[row][col]='.';
            hsC.erase(col);
            hsLD.erase(row - col);
            hsRD.erase(row + col);
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    vector<vector<string> >ans;
    vector<string> curr(A, string(A, '.'));
    set<int> hsC; // Column
    set<int> hsLD; // Left Diag
    set<int> hsRD; // Right Diag

    solveNQueensUtil(ans, curr, 0, hsC, hsLD, hsRD, A);
    return ans;
}
