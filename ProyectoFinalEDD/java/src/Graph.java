import java.util.*;

public class Graph {

    private Map<Integer,
    List<Integer>> adjList;

    public Graph() {

        adjList =
        new HashMap<>();
    }

    public void addEdge(int u,
                        int v) {

        adjList.putIfAbsent(
        u,
        new ArrayList<>());

        adjList.putIfAbsent(
        v,
        new ArrayList<>());

        adjList.get(u).add(v);

        adjList.get(v).add(u);
    }

    public void display() {

        System.out.println(
        "\n===== GRAFO =====");

        for(Integer node :
            adjList.keySet()) {

            System.out.print(
            node + " -> ");

            for(Integer neighbor :
                adjList.get(node)) {

                System.out.print(
                neighbor + " ");
            }

            System.out.println();
        }
    }

    public void bfs(int start) {

        System.out.println(
        "\n===== BFS =====");

        Set<Integer> visited =
        new HashSet<>();

        Queue<Integer> queue =
        new LinkedList<>();

        visited.add(start);

        queue.add(start);

        while(!queue.isEmpty()) {

            int current =
            queue.poll();

            System.out.print(
            current + " ");

            for(Integer neighbor :
                adjList.get(current)) {

                if(!visited.contains(
                   neighbor)) {

                    visited.add(
                    neighbor);

                    queue.add(
                    neighbor);
                }
            }
        }

        System.out.println();
    }

    public void dfs(int start) {

        System.out.println(
        "\n===== DFS =====");

        Set<Integer> visited =
        new HashSet<>();

        dfsRecursive(start,
                     visited);

        System.out.println();
    }

    private void dfsRecursive(
            int node,
            Set<Integer> visited) {

        visited.add(node);

        System.out.print(
        node + " ");

        for(Integer neighbor :
            adjList.get(node)) {

            if(!visited.contains(
               neighbor)) {

                dfsRecursive(
                neighbor,
                visited);
            }
        }
    }
}