# Topological Sort for Directed Acyclic Graphs
<b>Jinkai Zhang</b> - <br>
<b>Diego Mackay</b> - <br>
<b>Jakob Upton</b> - <br>

<h2>Instructions for running</h2>


<h2>Citations and Link to Repo</h2>
https://github.com/jakobupton/topologicalsort

<h2>Diego C++</h2>

Analysis Framework

Time Complexity
THe DFS function is linear as it calls itself n times the size of the class size
the topological sort function is O(N^2) as the topological sort calls the DFS function N times 

Space complexity 
DFS and Topological sort functions are both O(n^2) because of the adjaceny matrix. While all other data structures are O(n) the adj matrix dominates

REFERENCES

https://stackoverflow.com/questions/13467674/determining-complexity-for-recursive-functions-big-o-notation

GeeksforGeeks. (2024, August 8). Detect cycle in a directed graph. GeeksforGeeks. https://www.geeksforgeeks.org/detect-cycle-in-a-graph/ 

GeeksforGeeks. (2024, July 1). C++ program to implement adjacency list. https://www.geeksforgeeks.org/cpp-program-to-implement-adjacency-list/ 

GeeksforGeeks. (2024, July 23). Topological sorting. GeeksforGeeks. https://www.geeksforgeeks.org/topological-sorting/ 




