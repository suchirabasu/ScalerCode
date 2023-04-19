/* sum of pairs = k*
1 2 3 4 5
k = 5
[1,4]
[2,3]
*/
#include <bit>
using namespace std;
vector<vector<int>> pairSum(vector<int> A, int k){
    sort(A.begin(), A.end());
    int n = A.size(); // 5
    int low = 0, high = n-1;
    vector<vector<int>> ans;
    while(low<high){
        if(A[low] + A[high] == k){
            vector<int> temp(2,0);
            temp[0] = A[low];
            temp[1] = A[high];
            ans.push_back(temp);//1,4 , 2,3
        }
        if(A[low] + A[high] > k)
            high--;
        else    
            low++;    
    }
    return ans;
}

1 2 3
  5 4
struct Node{
    int data;
    struct Node* next;
};
void
int detectAndRemoveLoop(struct Node* head){
    struct Node *slow_p = head, *fast_p = head;
    while(slow_p != NULL && fast_p != NULL && fast_p->next != NULL  ){
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if(slow_p == fast_p){
            removeLoop(slow_p, head);
        }
    }
}

