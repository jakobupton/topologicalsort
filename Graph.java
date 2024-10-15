import java.util.*;

//Adjacent List based Graph
public class Graph<T> {
    ArrayList<T> adjacencyList = new ArrayList<>();
    ArrayList<LinkedList<Integer>> neighbor = new ArrayList<>();

    /**
     * DFS based topological sort.
     *
     * @return a topological vertex order, null if circle exist.
     */
    public List<T> topologicalSort() {
        int noParentIndex = findAnyNoParentVertex();

        //circle detected
        if (noParentIndex == -1) {
            return null;
        }

        HashSet<Integer> visitedIndex = new HashSet<>();

        //stack frame
        //index, current vertex index
        //children, next vertex indices
        //routes, all vertices from first vertex to current vertex. used to detect circle
        record Frame(int index, Iterator<Integer> children, HashSet<Integer> routes) {
        }

        Stack<Frame> stack = new Stack<>();
        LinkedList<T> result = new LinkedList<>();

        stack.push(new Frame(noParentIndex, neighbor.get(noParentIndex).iterator(), new HashSet<>(noParentIndex)));
        visitedIndex.add(noParentIndex);

        while (!stack.isEmpty()) {
            Frame frame = stack.peek();
            int index = frame.index;
            Iterator<Integer> children = frame.children;
            HashSet<Integer> routes = frame.routes;


            if (!children.hasNext()) {
                result.addFirst(adjacencyList.get(index));
                stack.pop();
            } else {
                int nextChildren = children.next();

                if (routes.contains(nextChildren)) {
                    //circle detected
                    return null;
                } else {
                    if (visitedIndex.contains(nextChildren)) {
                        //already visited.
                        continue;
                    } else {
                        visitedIndex.add(nextChildren);
                        HashSet<Integer> newRoutes = new HashSet<>(routes);
                        newRoutes.add(nextChildren);
                        stack.push(new Frame(nextChildren, neighbor.get(nextChildren).iterator(), newRoutes));
                    }
                }
            }
        }

        return result;
    }

    /**
     * find any vertex index which have no source.
     *
     * @return index , -1 if not exist or graph is empty..
     */
    private int findAnyNoParentVertex() {
        for (int index = 0; index < adjacencyList.size(); index++) {

            boolean haveParent = false;

            for (int currentIndex = 0; currentIndex < adjacencyList.size(); currentIndex++) {
                if (index != currentIndex) {
                    LinkedList<Integer> indices = neighbor.get(currentIndex);
                    if (indices.contains(index)) {
                        haveParent = true;
                        break;
                    }
                }
            }

            if (!haveParent) {
                return index;
            }

        }
        return -1;
    }


    /**
     * add vertex
     *
     * @param vertex vertex value
     */
    public void addVertex(T vertex) {


        //vertex exist do noting.
        for (T v : adjacencyList) {
            if (Objects.equals(v, vertex)) {
                return;
            }
        }
        adjacencyList.addLast(vertex);
        neighbor.addLast(new LinkedList<>());
    }


    /**
     * add a directed edge from 'source' to 'target'
     *
     * @param source source vertex
     * @param target target vertex
     */
    public void addEdge(T source, T target) {
        int sourceIndex = findVertexIndex(source);
        if (sourceIndex == -1) {
            throw new RuntimeException("source vertex not exist.");
        }
        int targetIndex = findVertexIndex(target);
        if (targetIndex == -1) {
            throw new RuntimeException("target vertex not exist.");
        }

        LinkedList<Integer> indices = neighbor.get(sourceIndex);
        for (Integer index : indices) {
            if (Objects.equals(index, targetIndex)) {
                return;
            }
        }
        indices.addLast(targetIndex);
    }


    private int findVertexIndex(T vertex) {
        int index = 0;
        for (T v : adjacencyList) {
            if (Objects.equals(v, vertex)) {
                return index;
            }
            index++;
        }
        return -1;
    }

    public void display() {
        for (int i = 0; i < adjacencyList.size(); i++) {
            T vertex = adjacencyList.get(i);
            System.out.print(i + ". " + vertex + " -> ");
            LinkedList<Integer> indices = neighbor.get(i);
            for (Integer index : indices) {
                System.out.print(index + " ");
            }
            System.out.println();
        }
    }
}




