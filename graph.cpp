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
int number_province(int n, vector<vector<int>> adj_list){
    traverse t;
    vector<int> vis(n,0);
    int counter=0;
    for(int i=0;i<n;i++){
        vector<int> ls;
        if(vis[i]==0){
            ls=t.dfsgraph(i,n,adj_list);
            for(auto i:ls)vis[i]=1;
            counter++;
        }
    }
    return counter;
}
class matrix_traverse{
    public:
    void bfs_m8(vector<vector<int>>& grid, int row, int col, vector<vector<int>>& vis){
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int delr=-1;delr<=1;delr++){
                for(int delc=-1;delc<=1;delc++){
                    int newr=row+delr;
                    int newc=col+delc;
                    if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc] && grid[newr][newc]==1){
                        vis[newr][newc]=1;
                        q.push({newr,newc});
                    }
                }
            }
        }
    }
};
int numberofislands(vector<vector<int>>& grid){ //grid is adj_matrix type of thing
    int n=grid.size();
    int m=grid[0].size();
    int count=0;
    vector<vector<int>> vis(n,vector<int>(m,0));
    matrix_traverse mt;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j]!=0){
                mt.bfs_m8(grid,i,j,vis);
                count++;
            }
        }        
    }
    return count;
}
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
    vector<int> dfsgraph(int start, int n,vector<vector<int>> adj_list){
        vector<int> ls;
        vector<int> vis(n,0);
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