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

    stack<int> st;
    st.push(start_node);
    vis[start_node] = true;

    cout << endl;
    cout << "BFS traversal ";

    while(!st.empty())
    {
        int f = st.top();
        st.pop();
        cout << f << " ";

        for(int i = 0; i < adj[f].size(); i++)
        {
            if(!vis[adj[f][i]])
            {
                vis[adj[f][i]] = true;
                st.push(adj[f][i]);
            }
        }
    }


    cout << endl;
    return 0;
}
