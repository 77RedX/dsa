#include <bits/stdc++.h>
#define int long long
#define MXI 1000000007LL
#define vi vector<int>
#define cy cout << "YES" << endl
#define cn cout << "NO" << endl
using namespace std;
vector<vector<int>> adj_matrix(int n, int m){           //n nodes and m edges
    vector<vector<int>> arr(n+1, vector<int>(n+1,0));
    for(int i=0;i<=m;i++){
        int u,v;
        cin>>u>>v;
        arr[u][v]=1;
        arr[v][u]=1;                                     //bidirectional graph/undirected
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
    vector<int> dr={1,0,0,-1};
    vector<int> dc={0,1,-1,0};
    void bfs_m4(vector<vector<int>> & grid, int row, int col, vector<vector<int>>& vis){
        vis[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int newr=row+dr[i];
                int newc=col+dc[i];
                if(newr>=0 && newr<n && newc>=0 && newc<m && !vis[newr][newc] && grid[newr][newc]==1){
                    vis[newr][newc]=1;
                    q.push({newr,newc});
                }
            }
        }
    }
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
                for(int delc=-1;delc<=1;delc++){// these two loops combined will give all 8 directions movement
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
int numberofislands(vector<vector<int>>& grid){ //grid is a matrix representing information. 1 for land and 0 for water here
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
    vector<int> BFS(int n, vector<vector<int>> adj_list){// this function does not store level, even though it does level traversal
        vector<int> vis (n,0);// update: now this can handle levels, could've also used pair but mingw doesnt like it i guess
        vis[0]=1;
        //let starting node be 0
        queue<int> q;
        q.push(0);
        vector<int> level(n,-1);//not reached yet so all -1
        level[0]=0;
        vector<int> bfs;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto i: adj_list[node]){
                if(!vis[i]){
                    level[i]=level[node]+1;
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
vector<int> shortest_path(vector<vector<int>> adj_list, int start){
    int n=adj_list.size();
    vector<int> dist(n,1e9);
    queue<int> q;
    dist[start]=0;
    q.push(start);
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto i: adj_list[node]){
            if(dist[node]+1<dist[i]){ // Can also use dist[i]==1e9, but Dijkstra algo uses this so just to keep things same
                dist[i]=dist[node]+1;
                q.push(i);
            }
        }
    }
    return dist;
}
int rotten_oranges(vector<vector<int>>& grid){
    //check rotten oranges first
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<pair<int,int>,int>> q; //{{r,c},t}
    vector<vector<int>> vis(m,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                vis[i][j]=2; //visited and rotten
            }
            else{
                vis[i][j]=0;
            }
        }
    }
    int tim=0;
    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int t=q.front().second;
        tim=max(tim,t);
        q.pop();
        vector<int> dr={-1,0,0,1};
        vector<int> dc={0,1,-1,0};
        for(int i=0;i<4;i++){
            newr=row+dr[i];
            newc=col+dc[i];
            if(newr>=0 && newr<n && newc>=0 && newc<m && vis[newr][newc]!=2 && grid[newr][newc]==1){
                q.push({{newr,newc},t+1});
                vis[newr][newc]==2;
            }
        }
    }
    for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=2 && grid[i][j]==1){
                    return -1;
                }
            }
    }
    return tim;
}
class isCycle{
    private:
    bool detect(int src, vector<vector<int>> adj, vector<int>& vis){
        vis[src]=1;
        queue<<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto i: adj[node]){
                if(!vis[i]){
                    vis[i]=1;
                    q.push({i,node});
                }
                else if(parent!=i){
                    return true;
                }
            }
        }
        return false;
    }
    public:
    bool Cycle(int V, vector<vector<int>> adj){//detecting cycle in undirected graph, graph can be broken into multiple components
        vector<int> vis(V);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i,adj,vis)) return true;
            }
        }
        return false;
    }
};
int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}