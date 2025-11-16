#include <bits/stdc++.h>
#define int long long
#define MXI 1000000007LL
#define vi vector<int>
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
using namespace std;
vector<vector<int>> adj_matrix(int n, int m){
    vector<vector<int>> arr(n+1, vector<int>(n+1,0));
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        arr[u][v]=1;
        arr[v][u]=1;
    }
    return arr;
}
vector<vector<int>> adj_list(int n,int m){
    vector<vector<int>> arr(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    return arr;
}
// use vector pair for storing weighted graph in adj list
class traverse{
    public:
    vector<int> BFS(int n, vector<vector<int>> adj_list){
        vector<int> vis (n,0);
        vis[0]=1;
        //let starting node be 0
        queue<int> q;
        q.push(0);
        vector<int> bfs;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto i: adj_list[node]){
                if(!vis[i]){
                    vis[i]=1;
                    q.push(i);
                }
            }
        }
        return bfs;

    }
    vector<int> dfsgraph(int n,vector<vector<int>> adj_list){
        vector<int> ls;
        vector<int> vis(n,0);
        int start=0;
        DFS(start,adj_list,vis,ls);
        return ls;
    }
    private:
    void DFS(int node, vector<vector<int>> adj_list,vector<int> vis, vector<int> &ls){
        vis[node]=1;
        ls.push_back(node);
        for(auto i:adj_list[node]){
            if(!vis[i]){
                DFS(i, adj_list,vis,ls);
            }
        }
    }
};
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    return 0;
}