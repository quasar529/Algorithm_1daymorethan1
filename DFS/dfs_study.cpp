#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Graph
{
public:
    int N;                   //정점 개수
    vector<vector<int>> adj; // 인접리스트
    vector<bool> visited;    //방문 확인

    Graph() : N(0) {}
    Graph(int n) : N(n)
    {
        adj.resize(N);
        visited.resize(N);
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void sortList()
    {
        for (int i = 0; i < N; i++)
            sort(adj[i].begin(), adj[i].end());
    }

    void dfs()
    {
        fill(visited.begin(), visited.end(), false);
        dfs(0);
    }

private:
    int dfs(int curr)
    {
        int nodes = 1;
        visited[curr] = true;
        cout << "node" << curr << '\n';
        for (int next : adj[curr])
            if (!visited[next])
                nodes += dfs(next);
        return nodes;
    }
    int dfsAll()
    {
        int components = 0;
        fill(visited.begin(), visited.end(), false);
        for (int i = 0; i < N; i++)
        {
            if (!visited[i])
            {
                cout << "NEW DFS BEGIN" << '\n';
                int nodes = dfs(i);
                components++;
                cout << "size: " << nodes << '\n\n';
            }
        }
    }
};