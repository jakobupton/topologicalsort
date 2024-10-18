# Topological Sort for Directed Acyclic Graphs
- Jinkai Zhang - Java Implementation
- Diego Mackay - C++ Implementation
- Jakob Upton - Python Implementation

## Instructions for Running
Python Implementation
```bash
python -m toposort
```
Python Tests
```bash
python -m toposorttest
```

### Diego C++

#### Time Complexity
THe DFS function is linear as it calls itself n times the size of the class size
the topological sort function is O(N^2) as the topological sort calls the DFS function N times 

#### Space complexity 
DFS and Topological sort functions are both O(n^2) because of the adjaceny matrix. While all other data structures are O(n) the adj matrix dominates

### Jakob Python Analysis
#### Space and Time Complexity
DFS function is called for each node in the graph. Each edge and node is only visited once.
The total number of iterations over all nodes and their prerequisites is how many edges we have in our graph.

So both our space and time complexity is O(V+E) where V is the number of nodes and E is the number of edges in the graph.

## References and Link to Repo
https://github.com/jakobupton/topologicalsort

https://stackoverflow.com/questions/13467674/determining-complexity-for-recursive-functions-big-o-notation

GeeksforGeeks. (2024, August 8). Detect cycle in a directed graph. GeeksforGeeks. https://www.geeksforgeeks.org/detect-cycle-in-a-graph/ 

GeeksforGeeks. (2024, July 1). C++ program to implement adjacency list. https://www.geeksforgeeks.org/cpp-program-to-implement-adjacency-list/ 

GeeksforGeeks. (2024, July 23). Topological sorting. GeeksforGeeks. https://www.geeksforgeeks.org/topological-sorting/