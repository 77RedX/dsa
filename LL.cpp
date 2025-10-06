#include <bits/stdc++.h>
// #define int long long
#define MXI 1000000007LL
#define vi vector<int>
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};
Node* arr2ll(vector<int>& a){
    int n=a.size();
    Node* head=new Node(a[0]);
    Node* mover=head;
    for(int i=1;i<n;i++){
        Node* temp=new Node(a[i]);
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
Node* finder(Node* head,int key){
    Node* temp=head;
    int cnt=0;
    while(temp){
        cnt++;
        if(temp->data==key){
            cout<<"Value Found at address "<<temp<<" at index :"<<cnt<<endl;
            return temp;
        }
        temp=temp->next;
    }
    cout<<"Value not found"<<endl;
    return nullptr;
}
Node* deleter(Node* head,int key){ //by value/key
    if(head==NULL) return head;
    Node* found=finder(head,key);
    if(found==nullptr){
        return head;
    }
    else if(found==head){
        Node* temp=head;
        head=head->next;
        delete(temp);
        cout<<"Head deleted"<<endl;
    }
    else{
        Node* prev=NULL;
        Node* temp=head;
        while(temp!=found){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        delete temp;
        cout<<"Element deleted"<<endl;
    }
    return head;
}
Node* insert(Node* head,int val,int k){
    if(head==NULL){
        if(k==1) {
            return new Node(val);
            cout<<"Element added\n";
        }
        else{
            cout<<"Error\n";
            return head;
        }
    }
    if(k==1){
        Node* temp=new Node(val,head);
        cout<<"Element added\n";
        return temp;
    }
    else{
        int cnt=1;
        Node* temp=head;
        while(temp){
            if(cnt==(k-1)){
                Node* in=new Node(val,temp->next);
                temp->next=in;
                cout<<"Element added\n";
                break;
            }
            temp=temp->next;
            cnt++;
        }
        return head;
    }
}
Node* reverse(Node* head){
    if(head==NULL) return head;
    Node* temp=head;
    Node* prev=nullptr;
    Node* n=temp->next;
    while(n){
        temp->next=prev;
        prev=temp;
        temp=n;
        n=n->next;
    }
    temp->next=prev;
    return temp;
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    // say gex
    vector<int> a={3,2,5,10};
    Node* head=arr2ll(a);
    printll(head);
    //finder(head,3);
    head=deleter(head,10);
    printll(head);
    head=insert(head,69,4);
    printll(head);
    head=reverse(head);
    cout<<"Reversed the Linked List:\n";
    printll(head);
}