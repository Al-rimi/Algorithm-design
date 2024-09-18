#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define INF 999999        // Define a large number as infinity for representing no direct edge between nodes
#define MaxSize 100       // Maximum number of vertices in the graph

// Structure to represent a node in the Union-Find Set (UFS) tree
struct UFSTree {
    int rank;    // Rank of the tree (used to keep the tree flat during Union operations)
    int parent;  // Parent node in the UFS tree
};

// Structure to represent an edge in the graph
struct edge {
    int u, v, w; // u: starting vertex, v: ending vertex, w: weight of the edge
    // Comparison operator to sort edges by weight
    bool operator<(const edge &e) const {
        return w < e.w;
    }
};

// Structure to represent a graph using an adjacency matrix
struct MGraph {
    int edges[MaxSize][MaxSize]; // 2D array to represent the adjacency matrix
    int n, e; // n: number of vertices, e: number of edges
};


// Function prototypes
void makeSet(UFSTree t[], int n);
int findSet(UFSTree t[], int x);
void Union(UFSTree t[], int x, int y);
void createMat(MGraph &g, int A[][MaxSize], int n, int e);
void dispMat(MGraph &g);
void kruskal(MGraph g);
void displaySignature();

int main() {
    displaySignature();

    MGraph g; // Create a graph object
    // Define the adjacency matrix for the graph
    int A[MaxSize][MaxSize] = {
        {0, 6, 1, 5, INF, INF},
        {6, 0, 5, INF, 3, INF},
        {1, 5, 0, 5, 6, 4},
        {5, INF, 5, 0, INF, 2},
        {INF, 3, 6, INF, 0, 6},
        {INF, INF, 4, 2, 6, 0},
    };

    int n = 6, e = 10; // Number of vertices and edges
    createMat(g, A, n, e); // Initialize the graph with the adjacency matrix

    printf("\033[33mAdjacency matrix of the graph:\033[0m\n"); 
    dispMat(g); // Display the adjacency matrix
    printf("\n\033[33mResults of kruskal's algorithm:\033[0m\n"); // Yellow text for the heading
    kruskal(g); // Run kruskal's algorithm to find the MST
    printf("\n"); 

    return 0;
}

// Function to initialize the Union-Find Set for each node
void makeSet(UFSTree t[], int n) {
    for (int i = 0; i < n; i++) {
        t[i].rank = 0;  // Initially, the rank is 0
        t[i].parent = i; // Each node is its own parent
    }
}

// Function to find the root of the set containing x with path compression
int findSet(UFSTree t[], int x) {
    if (x != t[x].parent)
        t[x].parent = findSet(t, t[x].parent); // Recursively find the root and perform path compression
    return t[x].parent;
}

// Function to Union two sets containing x and y
void Union(UFSTree t[], int x, int y) {
    int rootX = findSet(t, x); // Find the root of the set containing x
    int rootY = findSet(t, y); // Find the root of the set containing y
    
    if (rootX != rootY) { // If x and y are in different sets, merge them
        // Attach the tree with lower rank to the root of the tree with higher rank
        if (t[rootX].rank > t[rootY].rank) {
            t[rootY].parent = rootX;
        } else if (t[rootX].rank < t[rootY].rank) {
            t[rootX].parent = rootY;
        } else { // If ranks are equal, make one root the parent of the other and increase its rank
            t[rootY].parent = rootX;
            t[rootX].rank++;
        }
    }
}

// Function to create the graph from an adjacency matrix
void createMat(MGraph &g, int A[][MaxSize], int n, int e) {
    g.n = n; // Set the number of vertices
    g.e = e; // Set the number of edges
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g.edges[i][j] = A[i][j]; // Copy the adjacency matrix into the graph
        }
    }
}

// Function to display the adjacency matrix of the graph
void dispMat(MGraph &g) {
    for (int i = 0; i < g.n; i++) {
        for (int j = 0; j < g.n; j++) {
            if (g.edges[i][j] == INF)
                cout << "\033[31mINF \033[0m"; // Print "INF" in red if there is no direct edge
            else
                cout << g.edges[i][j] << "  "; // Print the edge weight in green otherwise
        }
        cout << endl;
    }
}

// Function to implement kruskal's algorithm to find the Minimum Spanning Tree (MST)
void kruskal(MGraph g) {
    int u1, v1, sn1, sn2;
    UFSTree t[MaxSize]; // Array to store the Union-Find Set
    vector<edge> E; // Vector to store all the edges in the graph

    // Collect all edges from the adjacency matrix
    for (int i = 0; i < g.n; i++) {
        for (int j = i + 1; j < g.n; j++) { // Only consider upper triangle (i < j) to avoid duplicates
            if (g.edges[i][j] != 0 && g.edges[i][j] != INF) {
                edge edge = {i, j, g.edges[i][j]}; // Create an edge
                E.push_back(edge); // Add the edge to the vector
            }
        }
    }

    // Sort the edges by their weight
    sort(E.begin(), E.end());

    // Initialize the Union-Find Set for all vertices
    makeSet(t, g.n);

    int k = 0; // Counter for the number of edges included in the MST
    for (int j = 0; j < E.size() && k < g.n - 1; j++) { // Loop until we have n-1 edges in the MST
        u1 = E[j].u;
        v1 = E[j].v;
        sn1 = findSet(t, u1); // Find the set of vertex u1
        sn2 = findSet(t, v1); // Find the set of vertex v1

        if (sn1 != sn2) { // If u1 and v1 are in different sets, add the edge to the MST
            printf("  (%d,%d): %d\n", u1, v1, E[j].w); // Print the edge in blue
            k++; // Increase the number of edges in the MST
            Union(t, sn1, sn2); // Union the sets containing u1 and v1
        }
    }
}

// Function to display a signature graphic
void displaySignature()
{
    const char *signature = R"(  
  _  __               _         _            _                  _ _   _               
 | |/ /              | |       | |     /\   | |                (_) | | |              
 | ' / _ __ _   _ ___| | ____ _| |    /  \  | | __ _  ___  _ __ _| |_| |__  _ __ ___  
 |  < | '__| | | / __| |/ / _` | |   / /\ \ | |/ _` |/ _ \| '__| | __| '_ \| '_ ` _ \ 
 | . \| |  | |_| \__ \   < (_| | |  / ____ \| | (_| | (_) | |  | | |_| | | | | | | | |
 |_|\_\_|   \__,_|___/_|\_\__,_|_| /_/    \_\_|\__, |\___/|_|  |_|\__|_| |_|_| |_| |_|
                                                __/ |                                 
                                               |___/                                  
)";

    std::cout 
				<< "\033[90mName: AL RAIMI ABDULLAH\033[0m\n"
				<< "\033[90mID:   202336020211\033[0m"
				<< "\033[31m" << signature << "\033[0m"
				<< std::endl; // Display the signature in the terminal
}