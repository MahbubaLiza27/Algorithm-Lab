#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dl;

#define optimize() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fraction() cout.unsetf( ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define mem(a, b) memset(a, b, sizeof(a) );
#define endl '\n'

int main()
{
    //optimize();

    int node, edge;
    cout << "Enter the number of nodes: ";
    cin >> node;
    cout << "Enter the number of edge: ";
    cin >> edge;


    bool vis[node + 1];
    vector<int> adj[node + 1];

    cout << "Enter the edges: " << endl;
    for(int i = 0; i < edge; i++){
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    cout << endl;
    int start_node;
    cout << "Enter start node ";
    cin >> start_node;

    for(int i = 0; i <= node; i++){
        vis[i] = false;
    }

    queue<int> q;
    q.push(start_node);
    vis[start_node] = true;

    cout << endl;
    cout << "BFS traversal ";

    while(!q.empty())
    {
        int f = q.front();
        q.pop();
        cout << f << " ";

        for(int i = 0; i < adj[f].size(); i++)
        {
            if(!vis[adj[f][i]])
            {
                vis[adj[f][i]] = true;
                q.push(adj[f][i]);
            }
        }
    }


    cout << endl;
    return 0;
}
/*

1 2
1 3
2 4
2 5
3 8
3 10
5 6
6 7
8 9
10 11
11 12
*/

