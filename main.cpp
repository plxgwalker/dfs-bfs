#include <iostream>
#include <vector>
#include <stack>
#include <list>
using namespace std;

vector<int> g[6];
stack<int> s;
list<int> q;

bool visited[6] = { false };
int dfs_number[6];
int bfs_number[6];
int dfs = 0;
int bfs = 0;

void create_edge(int src, int dest)
{
    g[src].push_back(dest);
}

void DFS(int vertex)
{
    visited[vertex] = true;
    dfs_number[vertex] = ++dfs;
    cout << "Vertex: " << vertex << " DFS-number: " << dfs_number[vertex] << endl;
    s.push(vertex);
    for (auto node : g[vertex])
    {
        while (!s.empty())
        {
            if (visited[node] == true)
                s.pop();
            else if (visited[node] != true)
            {
                visited[node] = true;
                dfs_number[node] = ++dfs;
                s.push(node);
                cout << "Vertex: " << node << " DFS-number: " << dfs_number[node] << endl;
            }
        }
    }
}

void dfs_total(int v)
{
    for (int i = v; i <= 5; i++)
        if (!visited[i])
            DFS(i);
}

void rec_dfs(int vertex)
{
    dfs_number[vertex] = ++dfs;
    if (visited[vertex] == true)
        return;
    cout << "Vertex: " << vertex << " DFS-number: " << dfs_number[vertex] << endl;
    for (auto node : g[vertex])
        rec_dfs(node);
}
void BFS(int vertex)
{
    visited[vertex] = true;
    bfs_number[vertex] = ++bfs;
    q.push_back(vertex);
    while (!q.empty())
    {
        vertex = q.front();
        cout << "Vertex: " << vertex << " BFS-number: " << bfs_number[vertex] << endl;
        q.pop_front();

        for (auto adjecent : g[vertex])
        {
            if (!visited[adjecent])
            {
                bfs_number[adjecent] = ++bfs;
                visited[adjecent] = true;
                q.push_back(adjecent);
            }
        }
    }
}

int main()
{
    int choice = 10;

    while (choice != 0)
    {
        cout << "1 - DFS(no recursive)" << endl;
        cout << "2 - DFS(recursive)" << endl;
        cout << "3 - BFS" << endl;
        cout << "0 - Exit" << endl;
        cout << "Choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            create_edge(1, 2);
            create_edge(1, 4);
            create_edge(1, 5);
            create_edge(2, 3);
            create_edge(3, 6);
            dfs_total(1);//1 2 3 6 4 5
            cout << endl;
            break;
        case 2:
            create_edge(1, 2);
            create_edge(1, 4);
            create_edge(1, 5);
            create_edge(2, 3);
            create_edge(3, 6);
            rec_dfs(1);//1 2 3 6 4 5
            cout << endl;
            break;
        case 3:
            create_edge(1, 2);
            create_edge(1, 4);
            create_edge(1, 5);
            create_edge(2, 3);
            create_edge(3, 6);
            BFS(1);//1 2 4 5 3 6
            cout << endl;
            break;
        }
    }
}
