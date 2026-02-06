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
    deque<int> q;
    fn{
        while(!q.empty() && v[i]<=v[q.back()]){
            q.pop_back();
        }
        q.push_back(i);
        if(q.front()<=i-k){
            q.pop_front();   
        }
        if(i>=k-1){
            ans^=v[q.front()];
        }
    }
    cout<<ans;
    return 0;
}