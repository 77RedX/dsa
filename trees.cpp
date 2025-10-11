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
    int val;
    Node* left;
    Node* right;
    Node(int val1){
        val=val1;
        left=nullptr;
        right=nullptr;
    }  
    Node(int val1,Node* left1,Node* right1){
        val=val1;
        left=left1;
        right=right1;
    }
};
// function for Breadth First Traversal, also called Level Order Traversal
// basically poora tree ko level-wise traverse krte hai starting from root val, left val then right val level wise
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
            l.push_back(q.front()->val);
            q.pop();
        }
        ans.push_back(l);
    }
    return ans;
}
//Depth First Search types:
//root,left,right
void preorder_traversal(Node* root){
    Node* node=root; //not really required still good for safety
    if(node==NULL){
        return;
    }
    cout<<node->val<<" ";
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
    cout<<node->val<<" ";
}
//left,root,right
void inorder_traversal(Node* root){
    Node* node=root;
    if(node==NULL){
        return;
    }
    inorder_traversal(node->left);
    cout<<node->val<<" ";
    inorder_traversal(node->right);
}
Node* populate_tree(){
    int val;
    cout<<"Enter the value of root\n";
    cin>>val;
    if(val==-1) return NULL;
    Node* root=new Node(val);
    cout<<"Root created\n";
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        cout<<"Enter the left and right values for the node "<<q.front()->val;
        int leftval,rightval;
        cin>>leftval>>rightval;
        Node* left=new Node(leftval);
        Node* right= new Node(rightval);
        //under construction
    }
    return root;
}
vector<int> iterative_inorder(Node* root){
    vector<int> ans;
    stack<Node*> s;
    Node* n=root;    
    while(true){
        if(n!=NULL){
            s.push(n);
            n=n->left;
        }
        else{
            if(s.empty()) break;
            n=s.top();
            s.pop();
            ans.push_back(n->val);
            n=n->right;
        }
    } 
    return ans;
}
vector<int> iterative_preorder(Node* root){
    vector<int> ans;
    stack<Node*> s;
    s.push(root);    
    while(!s.empty()){
        root=s.top();
        s.pop();
        ans.push_back(root->val);
        if(root->right) s.push(root->right);
        if(root->left) s.push(root->left);
    } 
    return ans;
}
//left,right,root
vector<int> iterative_postorder(Node* root){
    vector<int> ans;
    if(root==NULL) return ans;
    stack<Node*> s,s1;
    s.push(root);
    while(!s.empty()){
        Node* n=s.top();
        s1.push(n);
        s.pop();
        if(n->left) s.push(n->left);
        if(n->right) s.push(n->right);
    }
    while(!s1.empty()) {
        ans.push_back(s1.top()->val);
        s1.pop();
    }
    return ans;
}
bool isSameTree(Node* p, Node* q) {
        // Can't use BFS, check test case 2, same Vectors will be returned for different trees
       if(!p && !q) return true; //both null true same as p==null && q==null
       if(!p || !q) return false; //1 null then false same as p==null || q==null
       if(p->val!=q->val) return false; // value mismatch
       return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout<<"im so cooked";
    return 0;
}