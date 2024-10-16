# DFS Approach
import courseGraph

courses = courseGraph.courses



def topological_sort(graph):
    visited = set() # keep track of visited for dfs
    path = set() # keep track of current path for cycle detection
    sorted_stack = [] # stack to store sorted nodes
    
    def dfs(node):
        # Check for cycle
        if node in path:
            raise ValueError(f"Cycle detected at {node}") # not a DAG, gotta be an error
        if node in visited:
            return # skip 
        path.add(node)
        for prereq in graph.get(node, []): # get prereqs for each node
            if prereq not in graph:
                raise ValueError(f"Prerequisite {prereq} for {node} not found in course list") # error if prereq not found
            dfs(prereq)
        path.remove(node)
        visited.add(node)
        sorted_stack.append(node)  # Push onto stack - last prerequisite will be at bottom
    
    try:
        for node in graph:
            if node not in visited:
                dfs(node)
    except ValueError as e:
        print(f"Error: {e}")
        return None
    

    # return the stack, works out to be the topologically sorted list
    # because our graph is directed, the last prerequisite will be at the bottom of the stack
    # and the first prerequisite will be at the top of the stack
    return sorted_stack


sorted_courses = topological_sort(courses)

if sorted_courses:
    print("Topologically sorted courses:")
    for i, course in enumerate(sorted_courses, 1):
        print(f"{i}. {course} (Prerequisites: {', '.join(courses.get(course, [])) or 'None'})")