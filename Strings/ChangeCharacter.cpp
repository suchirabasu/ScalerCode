/*
Q10. Change Character
Problem Description
You are given a string A of size N consisting of lowercase alphabets.

You can change at most B characters in the given string to any other lowercase alphabet such that the number of distinct characters in the string is minimized.

Find the minimum number of distinct characters in the resulting string.



Problem Constraints
1 <= N <= 100000

0 <= B < N



Input Format
The first argument is a string A.

The second argument is an integer B.



Output Format
Return an integer denoting the minimum number of distinct characters in the string.



Example Input
A = "abcabbccd"
B = 3



Example Output
2



Example Explanation
We can change both 'a' and one 'd' into 'b'.So the new string becomes "bbcbbbccb".
So the minimum number of distinct character will be 2.


*/
int Solution::solve(string A, int B) {
     vector<int> dict(26,0);
        for(int i=0; i<A.length(); i++){
            dict[A[i]-'a']++;
        }
        sort(dict.begin(), dict.end());
        for(int i=0; i<26; i++){
            if(dict[i] != 0){
                if(B>0 && B>=dict[i])
                    B -= dict[i];
                else
                    return 26-i;
            }
        }
        return 0;
}
