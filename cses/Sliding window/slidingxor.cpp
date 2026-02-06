#include <bits/stdc++.h>
#define int long long
#define MXI 1000000007LL
#define vi vector<int>
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define fn for(int i=0;i<n;i++)
using namespace std;
//sliding window problems are o(n) time complexity
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    int x,a,b,c;
    cin>>x>>a>>b>>c;
    int ans=0;
    //creating array first
    vi v(n);
    fn{
        v[i]=x;
        x=(a*x+b)%c;
    }
    int winsum=0;
    //first window:
    for(int j=0;j<k;j++){
            winsum^=v[j];
    }
    ans^=winsum;
    for(int i=0;i<n-k;i++){
        winsum=winsum^v[i]^v[i+k];
        ans^=winsum;
    }
    cout<<ans;
    return 0;
}