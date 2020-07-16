#ifndef GRAPH_H
#define GRAPH_H
#include "string"
#include "linkedList.h"

class graph{
public:
graph();
int numberNodes;
int numberEdges;
int matrixCapacity;
int linkedListCapacity;

linkedList * vertices; //array of linked lists;

int ** adjacencyMatrix;

void addVertex(std::string vertex);
void addEdge(std::string vertex1, std::string vertex2);
void print();


/*• A graph is a collection of vertices (or nodes) and edges that connect vertices
• Can simply store edges in a list 
– Unsorted
– Sorted
• What operations would you want to perform on a graph?
• addVertex() : Vertex
• addEdge(v1, v2)
• getAdjacencies(v1) : List<Vertices>
– Returns any vertex with an edge from v1 to itself
• removeVertex(v)
• removeEdge(v1, v2)
• edgeExists(v1, v2) : bool
• •
Graphs are really just a list of lists
– List of vertices each having their own list of adjacent vertices
Alternatively, sometimes graphs are also represented with an adjacency matrix
*/

};

#endif