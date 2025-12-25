#include "bfs.h"

void bfs(Graph *g, size_t source, size_t destination) {
  Queue *q = q_init(10);
  if (q == NULL) {
    return;
  }
  bool visited[100] = {0};
  q_write(q, source);
  visited[source] = true;

  while (q_size(q).result != 0) {
    int curr = q_read(q).result;

    printf("Visit: %d\n", curr);
    if (curr == destination) {
      printf("Found destination!\n");
      break;
    }

    size_t neighbors[10];
    size_t count = graph_get_neighbors(g, curr, neighbors, 10);

    for (size_t i = 0; i < count; i++) {
      size_t next = neighbors[i];
      if (!visited[next]) {
        q_write(q, next);
        visited[next] = true;
      }
    }
  }
}