import unittest
import toposort

class TestToposort(unittest.TestCase):
    def test_empty_graph(self):
        self.assertEqual(toposort.topological_sort({}), [])

    def test_single_node(self):
        graph = {'A': []} # A has no prerequisites
        self.assertEqual(toposort.topological_sort(graph), ['A'])
    def test_single_node_with_cycle(self):
        graph = {'A': ['A']}
        self.assertEqual(toposort.topological_sort(graph), None)
    def test_two_nodes(self):
        graph = {'A': [], 'B': ['A']}
        self.assertEqual(toposort.topological_sort(graph), ['A', 'B'])
    def test_two_nodes_with_cycle(self):
        graph = {'A': ['B'], 'B': ['A']}
        self.assertEqual(toposort.topological_sort(graph), None)
    def test_three_nodes(self):
        graph = {'A': [], 'B': ['A'], 'C': ['B']}
        self.assertEqual(toposort.topological_sort(graph), ['A', 'B', 'C'])
if __name__ == '__main__':
    unittest.main()