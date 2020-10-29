#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <vector>

class DirectedGraph {
 private:
  std::map<int, std::vector<int>> graph;
  std::set<int> visited;
  std::set<int> path;
  bool loop;
  size_t size;
  /* Inicializa recorrido DFS del grafo */
  void dfs(int actual);
  /* Wrapper del dfs recursivo para iterar los nodos */
  void dfs_base();

 public:
  /* Init del grafo, reciben un mapa con <linea: posibles saltos>. */
  explicit DirectedGraph(const std::map<int, std::vector<int>> &graph);

  /* Devuelve True si existe un loop en el grafo, False en caso contrario.
   Notar que siempre se comienza por la primer linea que exista. */
  bool find_loop();

  /* Devuelve True si el grafo solo tiene una componente conexa. Falso en
  caso contrario. (Si todas las lineas son accesibles desde la primera) */
  bool find_unused();

  /* Destructor del Grafo. */
  ~DirectedGraph() {}
};

#endif  // DIRECTED_GRAPH_H
