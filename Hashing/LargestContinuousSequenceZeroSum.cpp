/*
Q3. Largest Continuous Sequence Zero Sum
Problem Description
Given an array A of N integers.Find the largest continuous sequence in a array which sums to zero.

Problem Constraints
1 <= N <= 106
-107 <= A[i] <= 107

Input Format
Single argument which is an integer array A.

Output Format
Return an array denoting the longest continuous sequence with total sum of zero.
NOTE : If there are multiple correct answers, return the sequence which occurs first in the array.

Example Input
A = [1,2,-2,4,-4]

Example Output
[2,-2,4,-4]

Example Explanation
[2,-2,4,-4] is the longest sequence with total sum of zero.

*/
vector<int> Solution::lszero(vector<int> &A) {
     unordered_map<int,int> mp;
    int curr_sum = 0;
    int max_size = 0;
    vector<int> res;
    for(int i = 0 ; i <  A.size(); i++)
    {
        curr_sum +=A[i];

        if(curr_sum == 0)
        {
            max_size = i+1;
            res.clear();
             for(int j = 0; j < max_size; j++)
             {
                res.push_back(A[j]);
             }
        }
        else
        {
            if(mp.find(curr_sum)!=mp.end())
            {
                int temp = max_size;
                max_size = max(max_size,i-mp[curr_sum]);
                if(max_size!=temp)
                {
                    res.clear();
                    for(int j = mp[curr_sum]+1; j <= i; j++)
                    {
                        res.push_back(A[j]);
                    }
                }
            }
            else{
                mp[curr_sum] = i;
            }
        }
    }
    return res;

}
