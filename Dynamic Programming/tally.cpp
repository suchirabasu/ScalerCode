/*
Input = {[2,4],[3,6],[7,9],[6,12]}

output = {[2,12]}

 

input = {[2,4],[3,6],[7,9],[8,12]}

output = {[2,6],[7,12]}
*/
struct Interval{
    int start, end;
};
bool compare(Interval i1, Interval i2){
    return(i1.start <i2.start);
}
vector<vector<int> > mergeInterval(Interval A[]){
    int n = A.size();
    stack<Interval> st;
    sort(A,A+n,compare);
    st.push(A[0]);
    for(int i=1;i<n;i++){
        Interval top = st.top();
        if(top.end < A[i].start){
            st.push(A[i]);
        }
        else if(top.end < A[i].end){
            top.end = A[i].end;
            st.pop();
            st.push(top);
        }
    }
    vector<vector<int> > ans;
    while(!st.empty()){
        Interval top = st.top();
        vector<int> temp(2,0);
        temp[0] = top.start;
        temp[1] = top.end();
        ans.pushback(temp);
    }
    return ans;
}

1
struct Node{
    int val;
    Node* next;
    Node* random;

    Node(int x){
        this->val = x;
        this->next = NULL;
        this->random = NULL;
    }
};
Node* deepCopyLL(Node * head){
    unordered_map<Node*, Node*> mp;
    Node *final, *temp;
    temp = head;
    final = new Node(temp->val);
    mp[temp] = final;// 1
    while(temp->next != NULL){ 
        temp = temp->next;   1->2->3->4->5
        final->next = new Node(temp->val);
        final = final->next;
        mp[temp] = final;
    }
    temp = head;
    while(temp != NULL){
        mp[temp]->random = mp[temp->random];1->3
        temp = temp->next;
    }
    return mp[head];

}