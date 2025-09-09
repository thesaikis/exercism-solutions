import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Graph {
    private Map<String, String> attributes;
    private List<Node> nodes;
    private List<Edge> edges;

    public Graph() {
        attributes = new HashMap<String,String>();
        nodes = new ArrayList<>();
        edges = new ArrayList<>();
    }

    public Graph(Map<String, String> attributes) {
        nodes = new ArrayList<>();
        edges = new ArrayList<>();
        this.attributes = attributes;
    }

    public Collection<Node> getNodes() {
        return nodes;
    }

    public Collection<Edge> getEdges() {
        return edges;
    }

    public Graph node(String name) {
        nodes.add(new Node(name));
        return this;
    }

    public Graph node(String name, Map<String, String> attributes) {
        nodes.add(new Node(name, attributes));
        return this;
    }

    public Graph edge(String start, String end) {
        edges.add(new Edge(start, end));
        return this;
    }

    public Graph edge(String start, String end, Map<String, String> attributes) {
        edges.add(new Edge(start, end, attributes));
        return this;
    }

    public Map<String, String> getAttributes() {
        return attributes;
    }
}
