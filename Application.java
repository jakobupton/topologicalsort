import java.util.List;

public class Application {

    /**
     * A->B
     * A->C
     * A->D
     * B->E
     * C->E
     * D->F
     * E->G
     * F->G
     * G->H
     * G->I
     */
    public static void main(String[] args) {
        Graph<String> graph = new Graph<>();
        List<String> vertices = List.of("A", "B", "C", "D", "E", "F", "G", "H", "I");

        for (String vertex : vertices) {
            graph.addVertex(vertex);
        }

        //add edges
        graph.addEdge("A", "B");
        graph.addEdge("A", "C");
        graph.addEdge("A", "D");
        graph.addEdge("B", "E");
        graph.addEdge("C", "E");
        graph.addEdge("D", "F");
        graph.addEdge("E", "G");
        graph.addEdge("F", "G");
        graph.addEdge("G", "H");
        graph.addEdge("G", "I");


        graph.display();

        List<String> results = graph.topologicalSort();


        if (results == null) {
            System.out.println("No topological sort found. As the graph is empty or circle found");
        } else {
            System.out.println(results);
        }

    }
}


