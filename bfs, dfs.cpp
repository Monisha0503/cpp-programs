#include <iostream>
#include <queue>
#include <stack>
using namespace std;

#define MAX 100

int adj[MAX][MAX];   // Adjacency matrix
bool visited[MAX];   // Visited array
int V;               // Number of vertices

// BFS using queue
void BFS(int start) {
    for(int i = 0; i < V; i++) visited[i] = false;
    queue<int> q;
    visited[start] = true;
    q.push(start);

    cout << "BFS: ";
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for(int i = 0; i < V; i++) {
            if(adj[node][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
}

// DFS using stack (iterative)
void DFS(int start) {
    for(int i = 0; i < V; i++) visited[i] = false;
    stack<int> s;
    s.push(start);

    cout << "DFS: ";
    while(!s.empty()) {
        int node = s.top();
        s.pop();

        if(!visited[node]) {
            visited[node] = true;
            cout << node << " ";

            for(int i = V-1; i >= 0; i--) { // Push in reverse order
                if(adj[node][i] && !visited[i])
                    s.push(i);
            }
        }
    }
    cout << endl;
}

int main() {
    int E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    // Initialize adjacency matrix
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            adj[i][j] = 0;

    // Input edges
    for(int i = 0; i < E; i++) {
        int u, v;
        cout << "Enter edge " << i+1 << " (u v): ";
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // Comment this line for directed graph
    }

    int choice, start;
    do {
        cout << "\nMenu:\n";
        cout << "1. BFS\n";
        cout << "2. DFS\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter starting vertex for BFS: ";
                cin >> start;
                BFS(start);
                break;
            case 2:
                cout << "Enter starting vertex for DFS: ";
                cin >> start;
                DFS(start);
                break;
            case 3:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while(choice != 3);

    return 0;
}