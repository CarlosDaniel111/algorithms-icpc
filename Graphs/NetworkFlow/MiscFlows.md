###Applications of Max Flow
##Minimum vertex cover: 
A minimum vertex cover is a vertex cover having the smallest possible number of vertices for a given graph.
The minimum vertex cover problem can be formulated as a half-integral, linear program whose dual linear program is the maximum matching problem.
In any bipartite graph, the number of edges in a maximum matching equals the number of vertices in a minimum vertex cover.
##Minimum edge cover: 
In graph theory, an edge cover of a graph is a set of edges such that every vertex of the graph is incident to at least one edge of the set. 
In computer science, the minimum edge cover problem is the problem of finding an edge cover of minimum size.
A smallest edge cover can be found in polynomial time by finding a maximum matching and extending it greedily so that all vertices are covered.
##Minimum path cover: 
A path cover is a set of paths in a graph such that each node of the graph belongs to at least one
path. It turns out that in directed, acyclic graphs, we can reduce the problem of finding a 
minimum path cover to the problem of finding a maximum flow in another graph.
*/
