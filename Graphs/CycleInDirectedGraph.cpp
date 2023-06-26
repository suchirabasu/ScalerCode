/*
Q15. Cycle in Directed Graph
Problem Description
Given an directed graph having A nodes. A matrix B of size M x 2 is given which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].

Find whether the graph contains a cycle or not, return 1 if cycle is present else return 0.

NOTE:

The cycle must contain atleast two nodes.
There are no self-loops in the graph.
There are no multiple edges between two nodes.
The graph may or may not be connected.
Nodes are numbered from 1 to A.
Your solution will run on multiple test cases. If you are using global variables make sure to clear them.


Problem Constraints
2 <= A <= 105

1 <= M <= min(200000,A*(A-1))

1 <= B[i][0], B[i][1] <= A



Input Format
The first argument given is an integer A representing the number of nodes in the graph.

The second argument given a matrix B of size M x 2 which represents the M edges such that there is a edge directed from node B[i][0] to node B[i][1].



Output Format
Return 1 if cycle is present else return 0.



Example Input
Input 1:

 A = 5
 B = [  [1, 2] 
        [4, 1] 
        [2, 4] 
        [3, 4] 
        [5, 2] 
        [1, 3] ]
Input 2:

 A = 5
 B = [  [1, 2]
        [2, 3] 
        [3, 4] 
        [4, 5] ]


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 The given graph contain cycle 1 -> 3 -> 4 -> 1 or the cycle 1 -> 2 -> 4 -> 1
Explanation 2:

 The given graph doesn't contain any cycle.


*/
typedef pair<int, int> PAIR;


struct comparator {
    bool operator()(PAIR &A, PAIR &B) {
        if(A.second == B.second)
            return A.first > B.first;
        return A.second > B.second;
    }
};


int Solution::solve(int A, vector<vector<int> > &B) {

    int count_traversed = 0;

    priority_queue<PAIR, vector<PAIR>, comparator> MinHeap;
    unordered_map<int, vector<int>> m;
    vector<int> count_Incoming_Edge(A + 1, 0);


    for(int i=0; i<B.size(); i++) {
        count_Incoming_Edge[B[i][1]]++;
        m[B[i][0]].push_back(B[i][1]);
    }
    for(int i=1; i<=A; i++)
        if(count_Incoming_Edge[i] == 0)
            MinHeap.push({i, 0});
   

    if(MinHeap.empty())
        return 1;
   

    while(!MinHeap.empty()) {
        PAIR currNode = MinHeap.top();
        MinHeap.pop();
       
        count_traversed++;

        for(auto itr : m[currNode.first]) {
            count_Incoming_Edge[itr]–;
            if(count_Incoming_Edge[itr] == 0)
                MinHeap.push({itr, 0});
        }
    }

    return (count_traversed == A) ? 0 : 1;
}
