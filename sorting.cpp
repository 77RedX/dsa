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
int partition(vi &a, int low, int high){
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<high;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[high]);
    return i+1;
}
void quickSort(vi &a, int low, int high){
    if(low<high){
        int pi=partition(a, low ,high);
        quickSort(a, low, pi-1);
        quickSort(a, pi+1, high);
    }
    return;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    quickSort(a,0,n-1);
    arrprint(a);
    return 0;
}