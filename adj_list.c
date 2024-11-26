#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

typedef struct Graph {
    int numVertices;
    Node** adjLists; // Array of linked lists
} Graph;

// Function to create a node
Node* createNode(int vertex) {
    Node* newNode = malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
Graph* createGraph(int vertices) {
	int i;
    Graph* graph = malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Create an array of linked lists
    graph->adjLists = malloc(vertices * sizeof(Node*));

    // Initialize each adjacency list
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (for undirected graph)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to display the graph
void displayGraph(Graph* graph) {
	int i;
    for ( i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf(" -> %d", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    int vertices = 5,n,i,v1,v2;
    Graph* graph = createGraph(vertices);
	printf("Enter the number of edges:");
    scanf("%d",&n);
    for (i=0;i<n;i++){
  		printf("For edge %d:\n",i+1);
  		printf("Enter source and destination vertex positions:");
  		scanf ("%d%d",&v1,&v2);
  		addEdge(graph, v1, v2);
  }
    // Adding edges
    /*addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
*/

    displayGraph(graph);
    return 0;
}

