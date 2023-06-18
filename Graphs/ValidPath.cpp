/*
Q9. Valid Path
Problem Description
There is a rectangle with left bottom as (0, 0) and right up as (x, y).
There are N circles such that their centers are inside the rectangle.
Radius of each circle is R. Now we need to find out if it is possible that we can move from (0, 0) to (x, y) without touching any circle.
Note : We can move from any cell to any of its 8 adjecent neighbours and we cannot move outside the boundary of the rectangle at any point of time.

Problem Constraints
0 <= x , y, R <= 100
1 <= N <= 1000
Center of each circle would lie within the grid

Input Format
1st argument given is an Integer x , denoted by A in input.
2nd argument given is an Integer y, denoted by B in input.
3rd argument given is an Integer N, number of circles, denoted by C in input.
4th argument given is an Integer R, radius of each circle, denoted by D in input.
5th argument given is an Array A of size N, denoted by E in input, where A[i] = x cordinate of ith circle
6th argument given is an Array B of size N, denoted by F in input, where B[i] = y cordinate of ith circle

Output Format
Return YES or NO depending on weather it is possible to reach cell (x,y) or not starting from (0,0).

Example Input
Input 1:
 x = 2
 y = 3
 N = 1
 R = 1
 A = [2]
 B = [3]
Input 2:
 x = 3
 y = 3
 N = 1
 R = 1
 A = [0]
 B = [3]

Example Output
Output 1:
 NO
Output 2:
 YES

Example Explanation
Explanation 1:
 There is NO valid path in this case
Explanation 2:
 There is many valid paths in this case.
 One of the path is (0, 0) -> (1, 0) -> (2, 0) -> (3, 0) -> (3, 1) -> (3, 2) -> (3, 3).

*/
int delrow[8]={-1,0,1,0,-1,1,-1,1};
int delcol[8]={0,-1,0,1,-1,1,1,-1};
bool dfs(vector<vector<int>> &mat,int x,int y,int dx,int dy,int n,int m){
     if(x<0||x>=n||y<0||y>=m||mat[x][y]==0) return false;
     if(x==dx&&y==dy) return true;
     for(int i=0;i<8;i++){
         int nx = x + delrow[i];
         int ny = y + delcol[i];
         if(nx>=0&&nx<n&&ny>=0&&ny<m&&mat[nx][ny]==1&&mat[nx][ny]!=2&&mat[nx][ny]!=0){
             mat[nx][ny]=2;
             if(dfs(mat,nx,ny,dx,dy,n,m)){
                 return true;
             }
         }
     }
     return false;
}
string Solution::solve(int x, int y, int N, int r, vector<int> &a, vector<int> &b) {
    int n = x+1;
    int m = y+1;
    vector<vector<int>> mat(n,vector<int> (m,1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<N;k++){
                int dist = pow((a[k] - i), 2)+pow((b[k] - j), 2);
                if(dist<=r*r){
                    mat[i][j]=0;
                }
            }
        }
    }
    // now do dfs from source 0,0 and check if x,y can be visited
    bool res = dfs(mat,0,0,x,y,n,m);
    return (res==true?"YES":"NO");
}