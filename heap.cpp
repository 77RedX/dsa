#include <bits/stdc++.h>
#define int long long
#define MXI 1000000007LL
#define vi vector<int>
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
using namespace std;
//implementing heap using array
/* A heap is like a complete binary tree* where all child elements are smaller than their parents. We store a heap in an array.
If the number of elements in a heap is n, we make a n+1 size array, leave the 0th index, and start filling from root to leaf,
left to right from 1 to nth index. For any given index i, its parent is i/2 and left child is 2*i and right child is (2*i)+1.

Complete Binary Tree is a tree where all levels are completely filled except maybe the last one, and the elements are always in 
left side first.
*/
void insertion(vi &a, int x){ // compare with parent
    a.push_back(x);
    int n=a.size()-1;
    while(n>1 && a[n]>a[n/2]){
        swap(a[n],a[n/2]);
        n/=2;
    }
}
void deletion(vi &a){
    int n = a.size() - 1;
    a[1] = a[n];      // move last element to root
    a.pop_back();     // remove last element
    int p = 1;

    while (true) {
        int left = p * 2;
        int right = p * 2 + 1;

        if (left >= a.size()) break;

        // Choose larger child
        int child = left;
        if (right < a.size() && a[right] > a[left])
            child = right;

        // If parent is bigger than both children
        if (a[p] >= a[child]) break;

        // Swap and go down
        swap(a[p], a[child]);
        p = child;
    }
}
void heapify_check(vi &a, int n, int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && a[largest]<a[left]){
        largest=left;
    }
    if(right<=n && a[largest]<a[right]){
        largest=right;
    }

    if(largest!=i){
        swap(a[i],a[largest]);
        heapify_check(a,n,largest);
    }
}
void heapify(vi &a){// agar 6 size ka array hai to heap me 5 element hai 1 to 5 numbered
    int n=a.size()-1;
    for(int i=n/2;i>0;i--){
        heapify_check(a,n,i);
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> a;
    a.push_back(-1);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a.push_back(x);
    }
    heapify(a);
    for(int i=1;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    return 0;
}