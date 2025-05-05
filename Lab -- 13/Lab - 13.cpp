#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;


class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = right = nullptr;
    }
};


void dfsTree(TreeNode* root) {
    if (!root) return;

    cout << root->data << " ";
    dfsTree(root->left);
    dfsTree(root->right);
}


void bfsTree(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();

        cout << current->data << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

// ==============================
// DFS & BFS in a Graph
// ==============================
class Graph {
public:
    int vertices;
    vector<vector<int>> adj;

    Graph(int v) {
        vertices = v;
        adj.resize(v);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);  
    }

 
    void dfsGraph(int start, vector<bool>& visited) {
        visited[start] = true;
        cout << start << " ";

        for (int neighbor : adj[start]) {
            if (!visited[neighbor])
                dfsGraph(neighbor, visited);
        }
    }


    void bfsGraph(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
};


int main() {
  
    cout << "=== DFS in Tree ===\n";
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    dfsTree(root);
    cout << "\n\n=== BFS in Tree ===\n";
    bfsTree(root); 

   
    cout << "\n\n=== DFS in Graph ===\n";
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);

    vector<bool> visited(5, false);
    g.dfsGraph(0, visited);

    cout << "\n\n=== BFS in Graph ===\n";
    g.bfsGraph(0); 

    return 0;
}
