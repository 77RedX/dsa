#include <bits/stdc++.h>
#define int long long
#define MXI 1000000007LL
#define vi vector<int>
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
using namespace std;
// declaring Node of tree
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data1){
        data=data1;
        left=nullptr;
        right=nullptr;
    }  
    Node(int data1,Node* left1,Node* right1){
        data=data1;
        left=left1;
        right=right1;
    }
};
// function for Breadth First Traversal, also called Level Order Traversal
// basically poora tree ko level-wise traverse krte hai starting from root data, left data then right data level wise
vector<vector<int>> BFS_traversal(Node* root){
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        vector<int> l;
        int si=q.size();
        for(int i=0;i<si;i++){
            if(q.front()->left!=NULL) q.push(q.front()->left);
            if(q.front()->right!=NULL) q.push(q.front()->right);
            l.push_back(q.front()->data);
            q.pop();
        }
        ans.push_back(l);
    }
    return ans;
}
//root,left,right
void preorder_traversal(Node* root){
    Node* node=root; //not really required but still for safety
    if(node==NULL){
        return;
    }
    cout<<node->data<<" ";
    preorder_traversal(node->left);
    preorder_traversal(node->right);
}
//left,right,root
void postorder_traversal(Node* root){
    Node* node=root;
    if(node==NULL){
        return;
    }
    postorder_traversal(node->left);
    postorder_traversal(node->right);
    cout<<node->data<<" ";
}
//left,root,right
void inorder_traversal(Node* root){
    Node* node=root;
    if(node==NULL){
        return;
    }
    inorder_traversal(node->left);
    cout<<node->data<<" ";
    inorder_traversal(node->right);
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<"im so cooked";
    return 0;
}