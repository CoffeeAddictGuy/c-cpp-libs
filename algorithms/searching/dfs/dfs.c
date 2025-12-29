#include "dfs.h"

#define MAX_VERICES 10000

DFSResult dfs(Graph *g, size_t source, size_t destination) {
  DFSState state = {0};
  DFSResult result = {0};

  state.parent[source] = -1;
  state.visited[source] = true;
  dfs_recurcive(g, source, &state, &result, destination);
  return result;
}

DFSResult *dfs_recurcive(Graph *g, size_t v, DFSState *state, DFSResult *result,
                         size_t end) {
  printf("Visit %zu\n", v);

  if (v == end) {
    printf("Found destination!\n");
    printf("(size_t)-1 test - %lld\n", (size_t)-1);
    result->found = true;
    size_t idx = 0;
    size_t current = end;
    while (current != ((size_t)-1)) {
      result->path[idx++] = current;
      current = state->parent[current];
    }
    result->path_length = idx;
    return result;
  }

  size_t neigh[32];
  size_t count = graph_get_neighbors(g, v, neigh, 32);
  for (size_t i = 0; i < count; i++) {
    size_t next = neigh[i];
    if (!state->visited[next]) {
      state->visited[next] = true;
      state->parent[next] = v;
      dfs_recurcive(g, next, state, result, end);
      if (result->found) {
        return result;
      }
    }
  }
  return result;
}