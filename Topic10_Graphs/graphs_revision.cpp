#include <iostream>
using namespace std;

/* 
   TOPIC 10: GRAPHS
   ----------------
   Graph G = (V, E) where V is vertices and E is edges.
   1. Directed Graph (Digraph): Edges have direction.
   2. Undirected Graph: Edges have no direction.
   3. Weight: Cost associated with an edge.
   
   Representations:
   - Adjacency Matrix: 2D array [size][size]. 1 if edge exists, 0 otherwise.
   - Adjacency List: Array of linked lists.
*/

// --- EXAM SNIPPET: ADJACENCY MATRIX (Feb 2025 Q5i) ---
void adjacencyMatrixExample() {
    /* 
       Vertices: A, B, C, D, E, F (6 vertices)
       Matrix size: 6x6
       
          A B C D E F
       A [0, 1, 0, 0, 1, 0]  <- A points to B (weight 2) and E (weight 10)
       B [0, 0, 1, 0, 1, 0]  <- B points to C and E
       ...
    */
    int size = 6;
    int matrix[6][6] = {0}; // Initialize all to 0
    
    // Example: Edge from A(0) to B(1)
    matrix[0][1] = 1; // Or matrix[0][1] = 2 (if weighted)
}

// --- TRAVERSALS ---

/* 
   1. Breadth First Search (BFS): Uses a QUEUE.
      - Visit node, then visit all its neighbors before going deeper.
      
   2. Depth First Search (DFS): Uses a STACK (or Recursion).
      - Go as deep as possible down one branch before backtracking.
*/

// EXAM SNIPPET: Simple Cycles (Feb 2025 Q5ii)
/*
   Cycle: A path that starts and ends at the same vertex.
   Example from Figure 11:
   - Path: B -> C -> F -> D -> E -> B (Length 5)
   - Path: B -> E -> B (Length 2)
*/

void bfs_concept() {
    // 1. Enqueue starting node
    // 2. Mark as visited
    // 3. While queue not empty:
    //    a. Dequeue current
    //    b. For each unvisited neighbor:
    //       i. Mark visited
    //       ii. Enqueue neighbor
}

void dfs_concept() {
    // 1. Push starting node to stack
    // 2. While stack not empty:
    //    a. Pop current
    //    b. If not visited:
    //       i. Mark visited
    //       ii. Push all unvisited neighbors to stack
}

int main() {
    cout << "Graphs often ask for: " << endl;
    cout << "1. Drawing Adjacency Matrix" << endl;
    cout << "2. Listing BFS/DFS traversal order" << endl;
    cout << "3. Identifying cycles" << endl;
    return 0;
}
