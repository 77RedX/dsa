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
void insertion(vi & a){
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
    arrprint(a);
}
void selection(vi &a){
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
    arrprint(a);
}
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    insertion(a);
    return 0;
}