#include <bits/stdc++.h>
//#define int long long
#define MXI 1000000007LL
#define vi vector<int>
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    public:
    Node(int data1,Node* next1,Node* prev1){
        data=data1;
        next=next1;
        prev=prev1;
    }
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        prev=nullptr;
    }
};
Node* arr2dll(vector<int>& a){
    int n=a.size();
    Node* head=new Node(a[0]);
    Node* mover=head;
    for(int i=1;i<n;i++){
        Node* temp=new Node(a[i],nullptr,mover);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
void printll(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> a={1,2,3,4,5};
    Node* head=arr2dll(a);
    printll(head);
    return 0;
}