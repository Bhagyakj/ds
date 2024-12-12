#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Graph structure
typedef struct {
    int adj[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
    int in_degree[MAX_VERTICES];         // In-degree array
    int V;  // Number of vertices
} Graph;

// Function to initialize the graph
void init_graph(Graph* g, int vertices) {
    g->V = vertices;
    for (int i = 0; i < vertices; i++) {
        g->in_degree[i] = 0;
        for (int j = 0; j < vertices; j++) {
            g->adj[i][j] = 0;
        }
    }
}

// Add an edge to the graph
void add_edge(Graph* g, int u, int v) {
    g->adj[u][v] = 1;
    g->in_degree[v]++;
}

// Function to perform topological sort
void topological_sort(Graph* g) {
    int result[MAX_VERTICES];  // To store the topological sort
    int idx = 0;
    
    // Temporary queue to hold vertices with in-degree of 0
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    
    // Find all vertices with in-degree 0
    for (int i = 0; i < g->V; i++) {
        if (g->in_degree[i] == 0) {
            queue[rear++] = i;
        }
    }
    
    // Process the vertices with in-degree 0
    while (front < rear) {
        int node = queue[front++];
        result[idx++] = node;
        
        // Decrease the in-degree of the neighbors
        for (int i = 0; i < g->V; i++) {
            if (g->adj[node][i] == 1) { // There's an edge from node to i
                g->in_degree[i]--;
                
                // If in-degree becomes 0, add it to the queue
                if (g->in_degree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }
    }
    
    // If all vertices are processed, print the result
    if (idx == g->V) {
        printf("Topological Sort: ");
        for (int i = 0; i < g->V; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");
    } else {
        // If there's a cycle, not all vertices are processed
        printf("The graph contains a cycle!\n");
    }
}

int main() {
    Graph g;
    int vertices, edges, u, v;
    
    // Get the number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    init_graph(&g, vertices);
    
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    
    // Get the edges from user
    for (int i = 0; i < edges; i++) {
        printf("Enter edge (u v): ");
        scanf("%d %d", &u, &v);
        
        // Edge validation
        if (u >= vertices || v >= vertices || u < 0 || v < 0) {
            printf("Invalid edge input! Vertices must be between 0 and %d.\n", vertices - 1);
            i--; // Decrement i to re-enter the edge
            continue;
        }
        add_edge(&g, u, v);
    }
    
    // Perform topological sort
    topological_sort(&g);
    
    return 0;
}
