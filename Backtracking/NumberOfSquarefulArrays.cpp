/*
Q5. Number of Squareful Arrays
Problem Description
Given an array of integers A, the array is squareful if for every pair of adjacent elements, their sum is a perfect square.
Find and return the number of permutations of A that are squareful. Two permutations A1 and A2 differ if and only if there is some index i such that A1[i] != A2[i].

Problem Constraints
1 <= length of the array <= 12
1 <= A[i] <= 109

Input Format
The only argument given is the integer array A.

Output Format
Return the number of permutations of A that are squareful.

Example Input
Input 1:
 A = [2, 2, 2]
Input 2:
 A = [1, 17, 8]

Example Output
Output 1:
 1
Output 2:
 2

Example Explanation
Explanation 1:
 Only permutation is [2, 2, 2], the sum of adjacent element is 4 and 4 and both are perfect square.
Explanation 2:
 Permutation are [1, 8, 17] and [17, 8, 1].

*/
bool isSquare(int x) {
    int n = round(sqrt(x));
    return pow(n, 2) == x;
}

void rec(vector<int> nums, int i, int &count) {
    if (nums.size() == 1)
        return;
    if (i == nums.size() - 1) {
        if (isSquare(nums[i] + nums[i - 1]))
            count += 1;
        return;
    }
    // check for all permutations
    for (int k = i; k < nums.size(); k++) {
        if (i != k && nums[i] == nums[k])
            continue;
        swap(nums[i], nums[k]);
        if (i == 0 || (i > 0 && isSquare(nums[i] + nums[i - 1])))
            rec(nums, i + 1, count);
    }
}

int Solution::solve(vector<int> &A) {
    sort(A.begin(), A.end());
    int ans = 0;
    rec(A, 0, ans);
    return ans;
}