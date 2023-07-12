/*
Q19. Smallest Sequence with given Primes
Problem Description
Given three prime number(A, B, C) and an integer D. Find the first(smallest) D integers which have only A, B, C or a combination of them as their prime factors.

Problem Constraints
1 <= A, B, C <= 10000
1 <= D <= 100000

Input Format
First argument is an integer A.
Second argument is an integer B.
Third argument is an integer C.
Fourth argument is an integer D.

Output Format
Return an integer array of size D, denoting the first D integers described above.
NOTE: The sequence should be sorted in ascending order

Example Input
Input 1:
 A = 2
 B = 3
 C = 5
 D = 5
Input 2:
 A = 3
 B = 2
 C = 7
 D = 3

Example Output
Output 1:
 [2, 3, 4, 5, 6]
Output 2:
 [2, 3, 4]

Example Explanation
Explanation 1:
 4 = A * A ( 2 * 2 ), 6 = A * B ( 2 * 3 )
Explanation 2:
 2 has only prime factor 2. Similary 3 has only prime factor 3. 4 = A * A ( 2 * 2 )

*/
vector<int> Solution::solve(int A, int B, int C, int D) {
    priority_queue<int,vector<int>,greater<int>>pq;
    set<int>st;
    st.insert(A); st.insert(B); st.insert(C);
    for(int i : st) pq.push(i);
   
    vector<int>ans;

    for(int i=0;i<D;i++) {
        int t = pq.top();
        ans.push_back(t);
        pq.pop();
        int t1 = t*A;
        int t2 = t*B;
        int t3 = t*C;
        if(st.find(t1)==st.end()) {
            st.insert(t1);
            pq.push(t1);
        }
        if(st.find(t2)==st.end()) {
            st.insert(t2);
            pq.push(t2);
        }
        if(st.find(t3)==st.end()) {
            st.insert(t3);
            pq.push(t3);
        }
    }

    return ans;
};