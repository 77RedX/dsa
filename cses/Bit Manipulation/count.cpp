#include <bits/stdc++.h>
#define int long long
#define MXI 1000000007LL
#define vi vector<int>
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define fn for(int i=0;i<n;i++)
using namespace std;
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int ones=0;
    int bit=0;
    while(n>0){
        if((n&1)==0){
            ones++;
        }
        bit++;
        n=n>>1;
    }
    cout<<ones*2<<endl;
    return 0;
}