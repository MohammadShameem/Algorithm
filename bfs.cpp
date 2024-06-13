#include <bits/stdc++.h>

using namespace std;

//Kahn's Algo (youtube striver's top sort)

#define ar array
#define ll long long

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

int n, m;
vector<int> adj[MAX_N], dist;

void bfs(int s) {
    dist.assign(n + 1, -1);//init all level to -1 first of all
    queue<int> q; //to keep adjacent nodes
    dist[s] = 0; 
    q.push(s);
    while (q.size()) {
        int u = q.front(); 
        q.pop(); //first value will be removed from queue
        for (int v : adj[u]) {//push adj nodes
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;//level of the graph
                q.push(v); //un-visited nodes
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {//m means total edges
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int tc; tc = 1;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }

      for (int i = 0; i < dist.size()-1; i++) {
        // Printing the element at
        // index 'i' of vector
        cout<<"Distance " << dist[i] << endl;
    }
    
}