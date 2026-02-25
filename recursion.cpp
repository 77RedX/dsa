#include <bits/stdc++.h>
#define int long long
#define MXI 1000000007LL
#define vi vector<int>
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
#define fn for(int i=0;i<n;i++)
using namespace std;


int sum_of_n(int n, int sum){ //backtracking
    if(n==1) return 1;
    sum=sum_of_n(n-1,sum);
    sum+=n;
    return sum;
}


int sumn(int n){
    if(n==1) return 1;
    return n+sumn(n-1);
}


int fact(int n){
    if(n==1) return 1;
    return n*fact(n-1);
}


int factf(int f,int n){
    if(n==1) return 1;
    f=factf(f,n-1);
    f*=n;
    return f;    
}


int fibo(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return fibo(n-1)+fibo(n-2);
}


void rev(vi& a, int l, int h){
    if(h<=l) return;
    swap(a[l],a[h]);
    rev(a,l+1,h-1);
    return;
}


bool palindrome(string s,int l, int h){
    if(l>=h) return 1;
    if(s[l]!=s[h]) return 0;
    return palindrome(s,l+1,h-1);
}


void powerset(vector<int>& a, vector<int>& ans, int i){
    int n=a.size();
    if(i==n){
        for(auto i:ans){
            cout<<i<<" ";
        }
        if(ans.size()==0) cout<<"{}";
        cout<<endl;
        return;
    }
    //take
    ans.push_back(a[i]);
    powerset(a,ans,i+1);
    //not take
    ans.pop_back();
    powerset(a,ans,i+1);
}


void suminseq(int sum, vi &ds, vi &a, int i, int x){
    int n=a.size();
    /*if(sum==x){
        for(auto i:ds){
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    if(i==n || sum>x){
        return;
    }*/
   //This is pruning of the rec. tree if condition met earlier
    if(i==n){//standard approach
        if(sum==x){
            for(auto i:ds){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        return;
    }
    // not pick
    suminseq(sum,ds,a,i+1,x);
    //pick
    ds.push_back(a[i]);
    suminseq(sum+a[i],ds,a,i+1,x);
    //restore ds
    ds.pop_back();
}


bool firstsum(vi &a, int i, vi ans, int sum, int x){
    int n=a.size();
    if(i==n){
        if(sum==x){
            for(auto i:ans){
                cout<<i<<" ";
            }
            cout<<endl;
            return true; // this subsequence is correct, the moment this is returned,the entire tree is returned/pruned the rest
        }
        return false;
    }
    //take
    ans.push_back(a[i]);
    if(firstsum(a,i+1,ans,sum+a[i],x)) return true;
    ans.pop_back();
    //not take
    if(firstsum(a,i+1,ans,sum,x)) return true;
    return false;
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vi a={1,2,1};
    int n=a.size();
    vi ans;
    firstsum(a,0,ans,0,2);
    return 0;
}