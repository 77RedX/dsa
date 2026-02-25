#include<bits/stdc++.h>
#define int long long
#define MXI 1000000007LL
#define vi vector<int>
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
using namespace std;
void arrprint(vi a){
    int n=a.size();
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
void insertion(vi & a){ // pick an element, place it in it's proper place (literally inserting)
    int n=a.size();
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(j>=0 && key<a[j]){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
void selection(vi &a){ // select the smallest element in the remaining array, then move on
    int n=a.size();
    //cout<<"size="<<n<<endl;
    for(int i=0;i<n;i++){
        int mx=i;
        for(int j=i+1;j<n;j++){
            if(a[mx]>a[j]){
                mx=j;
            }
        }
        swap(a[i],a[mx]);
    }
}
void bubble(vi &a){
    int n=a.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(a[j]>a[i]) swap(a[j],a[i]);
        }
    }
}

// Quick Sort
int partition(vi &a, int low, int high){//1st element is pivot
    int pivot=a[low];
    int i=low;
    int j=high;
    while(i<j){
        while(a[i]<=pivot && i<=high-1){
            i++;
        }
        while(a[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j) swap(a[i],a[j]);
    }
    swap(a[j],a[low]); // placing in the correct place;
    return j;
    
}
void quickSort(vi &a, int low, int high){
    if(low<high){
        int pi=partition(a, low ,high);
        quickSort(a, low, pi-1);
        quickSort(a, pi+1, high);
    }
    return;
}
//  k-way sorting
struct Node {
    int value;
    int runIndex;     // from which run the value came
    int posInRun;     // index inside that run
};

struct Compare {
    bool operator()(Node a, Node b) {
        return a.value > b.value;  // min-heap
    }
};


// k-way merge
vector<int> kWayMerge(vector<vector<int>> &runs) {
    priority_queue<Node, vector<Node>, Compare> pq;
    vector<int> output;

    // initialize heap with first element of each run
    for (int i = 0; i < runs.size(); i++) {
        if (!runs[i].empty())
            pq.push({runs[i][0], i, 0});
    }

    while (!pq.empty()) {
        Node temp = pq.top();
        pq.pop();

        output.push_back(temp.value);

        // insert next element from the same run
        int nextPos = temp.posInRun + 1;
        int run = temp.runIndex;

        if (nextPos < runs[run].size())
            pq.push({runs[run][nextPos], run, nextPos});
    }

    return output;
}

//Merge Sort
void merge(vi &a,int l, int mid, int h){//sort krke return
    int fo=l;
    int ft=mid+1;
    vi temp;
    while(fo<=mid && ft<=h){
        if(a[fo]>a[ft]){
            temp.push_back(a[ft]);
            ft++;
        }
        else{
            temp.push_back(a[fo]);
            fo++;
        }
    }
    while(fo<=mid){
        temp.push_back(a[fo]);
        fo++;
    }
    while(ft<=h){
        temp.push_back(a[ft]);
        ft++;
    }
    //temp is completely sorted now, now we swap it with og array a;
    for(int i=l;i<=h;i++){
        a[i]=temp[i-l];
    }
}

void mergediv(vi &a, int l, int h){
    if(l>=h){// 1 element remaining in array
        return;
    }
    int mid=l+((h-l)/2);
    mergediv(a,l,mid);
    mergediv(a,mid+1,h);
    merge(a,l,mid,h);
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vi a={1,6,7,4,5,2,3};
    quickSort(a,0,a.size()-1);
    arrprint(a);
    return 0;
}