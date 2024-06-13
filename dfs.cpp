#include <bits/stdc++.h>
using namespace std;

/*
https://www.youtube.com/watch?v=SGT-3e7Ze5Y

1. connected components
2. cycle detection
3. counting cycles
4. grid traveling
5. Diameter of tree:  max distance of a pair(u,v)
6. Topological Short using dfs : can apply on DAG (Directed Acyclic Graph)
*/

//---------------Cycle Count------------
void dfsCycleCount(int son, int father, vector<vector<int>> &adjList, vector<int> &par, vector<int> &color,int cnt) {
    if(color[son]==1){
        cnt++;
        return;
    }
    if(color[son]==2){ //completely visited
        return;
    }
    color[son] = 1;
    par[son] = father;
    for (auto &child : adjList[son]) {
        if (color[child] == -1) {
            dfsCycleCount(child,son, adjList, par, color,cnt); // Visiting the child
        }
    }
    color[son] = 2;
}

//---------------Cycle Detection------------
bool dfsCycleDetection(int son, int father, vector<vector<int>> &adjList, vector<int> &par, vector<int> &vis) {
    vis[son] = 1; // Mark node as visited
    par[son] = father;
    for (auto &child : adjList[son]) {
        if (vis[child] == -1) {
            dfsCycleDetection(child,son, adjList, par, vis); // Visiting the child
        }else{
            if(child != par[son]) {
                return true;
            }
        }
    }
    return false;
}

//---------------Top Sort------------
void dfsTopSort(int source, vector<vector<int>> &adjList, vector<int> &vis, vector<int> &sequence) {
    vis[source] = 1; // Mark node as visited
    //start
    //cout << source << " ";
    for (auto &child : adjList[source]) {
        if (vis[child] == -1) {
           // cout << "--->";
            dfsTopSort(child, adjList, vis, sequence); // Visiting the child
        }
    }
    // cout << "Completely visited Source " << source << "\n";
    sequence.push_back(source);//for top sort : indgree will be = 0
}

//--------------DFS------------
void dfs(int source, vector<vector<int>> &adjList, vector<int> &vis) {
    vis[source] = 1; // Mark node as visited
    //start
    //cout << source << " ";
    for (auto &child : adjList[source]) {
        if (vis[child] == -1) {
           // cout << "--->";
            dfs(child, adjList, vis); // Visiting the child
        }
    }
    // cout << "Completely visited Source " << source << "\n";
}

void solve() {
    int nodes, edges,cnt=0;
    cin >> nodes >> edges;

    vector<vector<int>> adjList(nodes + 1);
    vector<int> sequence; //for top sort
    vector<int> par(nodes+1); //for cycle detection
    vector<int> color(nodes+1); //for cycle count
    vector<int> vis(nodes + 1, -1);

    // Take input from user
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    //------------DFS----------------
      for (int i = 1; i <= nodes; i++) {
        if (vis[i] == -1) {
            dfs(i, adjList, vis);
        }
    }

    //------------TopSort------------
    for (int i = 1; i <= nodes; i++) {
        if (vis[i] == -1) {
            dfsTopSort(i, adjList, vis,sequence);
        }
    }
    reverse(sequence.begin(),sequence.end());
    for(auto &x: sequence){
        cout<<x<<" ";
    }
    cout<<"\n";

    //------------Cycle Detection-----------------
    for (int i = 1; i <= nodes; i++) {
        bool check = false;
        if (vis[i] == -1) {
            check = dfsCycleDetection(i, -1, adjList, par,vis);
            if(check){
                cout<<"Has Cycle\n";
                return;
            }
        }
    }
    cout<<"No Cycle\n";

    //------------Cycle Count-----------------
    for (int i = 1; i <= nodes; i++) {
        if (color[i] == -1) {
            dfsCycleCount(i, -1, adjList, par,color,cnt);
        }
    }
    cout<<cnt;

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }

    return 0;
}
