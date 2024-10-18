#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
using namespace std;

//globals
//2d vector = adj matrix
vector<vector<int>> adj_matrix;        
//vecotr for list of classes
vector<string> classes;
//map for class name to index in adj matrix for faster access
map<string, int> class_to_vertex;

//initialize graph and map classes
void initialize_graph(int n, vector<string> classes_names)
{   
    //adj matrix = n x n and set n to zero where to initialize
    adj_matrix = vector<vector<int>>(n, vector<int>(n, 0));

    classes = classes_names;
    //for every value in class_names map its index to itself
    for (int i = 0; i < n; ++i) {
        class_to_vertex[classes_names[i]] = i;
    } 
}
//function to add edge (a 1 in the adj matrix)
void add_edge(string class_u, string class_v)
{   
    //adds edge from U ---> V
    int u = class_to_vertex[class_u];
    int v = class_to_vertex[class_v];
    adj_matrix[u][v] = 1;   
    //adds edge from  U <--- V *undirected
    //adj_matrix[v][u] = 1;
}

//function to print the adjacency matrix
void print_adj_matrix()
{   
    cout << "Adjacency Matrix Representation\n";
    //nested for loop to traverse graph(adj matrix) and print the value 0 or 1 for connection
    int n = adj_matrix.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//function to print what classes are connected
void print_connections()
{
    cout << "Graph Connections\n";
    //for every row in graph print the collumns where there are ones (connections)
    int n = adj_matrix.size();
    for (int i = 0; i < n; i++) {
        cout << classes[i] << " Points To: ";
        for (int j = 0; j < n; j++) {
            if (adj_matrix[i][j] == 1) {
                cout << classes[j] << " ";
            }
        }
        cout << endl;
    }
}

//DFS utility function
void dfs(int v, vector<bool>& visited, stack<int>& topo_stack)
{
    //bool to check if we've visited node (ensure DAG)
    visited[v] = true;
    
    //for all index in adj matrix check check theres a connection between current node v
    //if theres connection between v and i and i hasnt been visted recur dfs for i
    for (int i = 0; i < adj_matrix.size(); i++) {
        if (adj_matrix[v][i] == 1 && !visited[i]) {
            dfs(i, visited, topo_stack);
        }
    }
    //push last vertex visted to stack then when we pop will be in topo order
    topo_stack.push(v);
}

void topological_sort()
{
    //stack to store topological sort and to pass dfs
    stack<int> topo_stack;

    //init vector visited of size adj matrix and set false
    vector<bool> visited(adj_matrix.size(), false);

    //call dfs helper function all values in adj if it hasnt been visited
    for (int i = 0; i < adj_matrix.size(); i++) {
        if (!visited[i]) {
            dfs(i, visited, topo_stack);
        }
    }
    cout << "Topological Sorted\n";
    while (!topo_stack.empty()) {
        cout << classes[topo_stack.top()] << " ";
        topo_stack.pop();
    }
    cout << endl;
}


//edge f//function to check for cycles in graphunction for readibility
void add_edges ()
{
    add_edge("COMP 061","COMP 071");    
    add_edge("COMP 071","COMP 091"); 
    add_edge("COMP 071","COMP 092"); 
    add_edge("MATH 096","COMP 120"); 
    add_edge("MATH 110","COMP 120");  
    add_edge("PRE-CALC 12","COMP 120"); 
    add_edge("MATH 092","COMP 120"); 
    add_edge("MATH 093","COMP 120"); 
    add_edge("PRE-CALC 12","COMP 125");
    add_edge("MATH 085","COMP 125");
    add_edge("MATH 092","COMP 125");
    add_edge("MATH 094","COMP 125");
    add_edge("MATH 12","COMP 150");
    add_edge("PRE-CALC 12","COMP 150");
    add_edge("MATH 092","COMP 150");
    add_edge("MATH 094","COMP 150");
    add_edge("MATH 12","COMP 152");
    add_edge("PRE-CALC 12","COMP 152");
    add_edge("MATH 093","COMP 152");
    add_edge("MATH 095","COMP 152");
    add_edge("COMP 150","COMP 155");
    add_edge("COMP 152","COMP 155");
    add_edge("COMP 155","COMP 230");
    add_edge("STAT 106","COMP 230");
    add_edge("STAT 270","COMP 230");
    add_edge("COMP 125","COMP 251");
    add_edge("COMP 155","COMP 251");
    add_edge("MATH 125","COMP 251");
    add_edge("COMP 125","COMP 256");
    add_edge("COMP 150","COMP 256");
    add_edge("COMP 152","COMP 256");
    add_edge("COMP 155","COMP 325");
    add_edge("CIS 221","COMP 325");
    add_edge("COMP 230","COMP 331");
    add_edge("STAT 270","COMP 331");
    add_edge("COMP 251","COMP 340");
    add_edge("COMP 251","COMP 350");
    add_edge("COMP 251","COMP 351");
    add_edge("COMP 251","COMP 359");
    add_edge("MATH 125","COMP 359");
    add_edge("MATH 225","COMP 359");
    add_edge("STAT 106","COMP 359");
    add_edge("STAT 270","COMP 359");
    add_edge("COMP 251","COMP 360");
    add_edge("COMP 251","COMP 361");
    add_edge("COMP 251","COMP 370");
    add_edge("CIS 270","COMP 370");
    add_edge("CIS 270","COMP 371");
    add_edge("COMP 230","COMP 371");
    add_edge("COMP 251","COMP 371");
    add_edge("COMP 251","COMP 380");
    add_edge("STAT 106","COMP 380");
    add_edge("STAT 270","COMP 380");
    add_edge("COMP 251","COMP 381");
    add_edge("STAT 270","COMP 381");
    add_edge("STAT 106","COMP 381");
    add_edge("COMP 251","COMP 382");
    add_edge("MATH 225","COMP 382");
    add_edge("COMP 359","COMP 386");
    add_edge("COMP 370","COMP 386");
    add_edge("MATH 125","COMP 390");
    add_edge("COMP 251","COMP 390");
    add_edge("STAT 106","COMP 390");
    add_edge("STAT 270","COMP 390");
    add_edge("COMP 230","COMP 430");
    add_edge("COMP 251","COMP 430");
    add_edge("COMP 230","COMP 431");
    add_edge("STAT 271","COMP 431");
    add_edge("STAT 331","COMP 431");
    add_edge("COMP 390","COMP 445");
    add_edge("COMP 251","COMP 455");
    add_edge("COMP 251","COMP 481");
    add_edge("COMP 251","COMP 482");
    add_edge("STAT 106","COMP 482");
    add_edge("STAT 270","COMP 482");
    add_edge("COMP 359","COMP 486");
    add_edge("COMP 370","COMP 486");
    add_edge("COMP 390","COMP 490");
    add_edge("STAT 106","COMP 490");
    add_edge("STAT 270","COMP 490");
    add_edge("STAT 270","STAT 331");
    add_edge("MATH 112","STAT 270");
    add_edge("MATH 111","MATH 112");
    add_edge("PRE-CALC 12","MATH 111");
    add_edge("MATH 112", "MATH 225");
}

int main()
{
    vector<string> classes_names = { "COMP 061", "COMP 071", "COMP 091", "COMP 092", "COMP 120", "COMP 125", "COMP 150", "COMP 152", "COMP 155", "COMP 230", "COMP 251", "COMP 256", "COMP 325", "COMP 331", "COMP 340", "COMP 350", "COMP 351", "COMP 359", "COMP 360", "COMP 361", "COMP 370", "COMP 371", "COMP 380", "COMP 381", "COMP 382", "COMP 386", "COMP 390", "COMP 420", "COMP 430", "COMP 431", "COMP 440", "COMP 445", "COMP 455","COMP 481", "COMP 482", "COMP 486", "COMP 490" , "MATH 096", "MATH 110", "PRE-CALC 12", "MATH 092", "MATH 093", "MATH 085", "MATH 12", "MATH 095", "CIS 221","MATH 125", "MATH 225", "STAT 270", "STAT 106","CIS 270","STAT 331","MATH 111", "MATH 112"};
    
    initialize_graph(classes_names.size(), classes_names);
    //priont empty adj matrix to show working
    print_adj_matrix();
    //add edges (pre reqs)
    add_edges();
    //print full adj matrix
    print_adj_matrix();
    //show connections(initialized graph)
    print_connections();
    //sort and print
    topological_sort();
    
    return 0;
}