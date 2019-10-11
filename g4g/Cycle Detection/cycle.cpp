#include <bits/stdc++.h>
using namespace std;

bool isCyclic(int V, vector<int> adj[]);
bool dfs(int s, bool visited[], bool recStack[], vector<int> adj[]);

//Position this line where user code will be pasted.
int main() {

	int t;
	cin >> t;

	while(t--){

	    int v, e;
	    cin >> v >> e;

	    vector<int> adj[v];

	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }

	    cout << isCyclic(v, adj) << endl;

	}

	return 0;
}
/*This is a function problem.You only need to complete the function given below*/
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

bool dfs(int s, bool visited[], bool recStack[], vector<int> adj[]);

bool isCyclic(int V, vector<int> adj[])
{
    bool visited[V] = {};
    bool recStack[V] = {};

    for(int i = 0; i < V; i++)
    {
        if(dfs(i, visited, recStack, adj)) return true;
    }
    return false;
}

bool dfs(int v, bool visited[], bool recStack[], vector<int> adj[])
{
    if(visited[v] == false)
    {
        visited[v] = true;
        recStack[v] = true;

        list<int>::iterator i;
        for(auto u : adj[v])
        {
            if (!visited[u] && dfs(u, visited, recStack, adj)) return true;
            else if (recStack[u]) return true;
        }

    }
    recStack[v] = false;
    return false;
}
