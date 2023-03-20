/*
Q12. Ways to form Max Heap
Problem Description
Max Heap is a special kind of complete binary tree in which, for every node, the value present in that node is greater than the value present in its children nodes.
Find the number of distinct Max Heap that can be made from A distinct integers.
In short, you have to ensure the following properties for the max heap :
Heap has to be a complete binary tree ( A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible.)
Every node is greater than all its children.
NOTE: If you want to know more about Heaps, please visit this link. Return your answer modulo 109 + 7.

Problem Constraints
1 <= A <= 100

Input Format
The first and only argument is an integer A.

Output Format
Return an integer denoting the number of distinct Max Heap.

Example Input
Input 1:
 A = 4
Input 2:
 A = 10

Example Output
Output 1:
 3
Output 2:
 3360

Example Explanation
Explanation 1:
 Let us take 1, 2, 3, 4 as our 4 distinct integers
 Following are the 3 possible max heaps from these 4 numbers :
      4           4                     4
    /  \         / \                   / \ 
   3    2   ,   2   3      and        3   1
  /            /                     /    
 1            1                     2
Explanation 2:
 Number of distinct heaps possible with 10 distinct integers = 3360.

*/
#define ll long long
#define M 1000000007

void fillChooseArray(vector< vector< ll > >&choose){
    for(int i=1;i<101;i++){
        for(int j=2;j<101;j++){
            if(i==j) choose[i][j] = 1;
            else {
                choose[i][j] = choose[i-1][j] + choose[i-1][j-1];
                choose[i][j] %= M;
            }
        }
    }
    return;
}

ll ways(int N, vector< ll > &waysToFormMaxHeap, vector< vector< ll > > &choose){
    
    if( N <= 1 ) return N;
    if( N == 2 ) return 1;
    
    if( waysToFormMaxHeap[N] != -1 ) return waysToFormMaxHeap[N];

    int height = log2(N);

    ll last =  ( min( 1 << ( height - 1 ), N - ( 1 << height ) + 1 ) ) % M ;

    ll left = last + ( ( 1 << height ) - 2 ) / 2 ;

    ll right = N - left - 1;    

    waysToFormMaxHeap[N] = ( ( choose[N-1][left] % M ) * ( ( ways(left, waysToFormMaxHeap, choose) % M ) * ( ways(right, waysToFormMaxHeap, choose) % M ) % M ) %M )%M;

    waysToFormMaxHeap[N] %= M;

    return waysToFormMaxHeap[N];
}


int Solution::solve(int A) {
    if(A <= 1) return A;
    if(A == 2) return 1;
    
    //filling choose array
    vector< vector< ll > > choose(101, vector< ll >(101, 0));
    for(int j=0;j<101;j++){
        choose[0][j] = 1; 
    }
    for(int i=0;i<101;i++){
        choose[i][1] = i;
    }
    fillChooseArray(choose);

    //memoization
    vector< ll > waysToFormMaxHeap(A+1, -1);
    waysToFormMaxHeap[0] = 0;
    waysToFormMaxHeap[1] = 1;
    waysToFormMaxHeap[2] = 1;

    return ways(A, waysToFormMaxHeap, choose) % M;
}