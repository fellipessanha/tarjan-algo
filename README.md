# implementation of tarjan's algorithm for finding strongly connected components in graphs

A [strongly connected component](https://en.wikipedia.org/wiki/Strongly_connected_component) in a graph -- which I may call a cycle in this repo -- is subgraph in which we can find a path that starts and ends in the same node, as you may see illustrated in the example below

```mermaid
graph LR;
  subgraph strongly connected component
    1 --> 2;
    2 --> 3;
    3 --> 1;
  end

  0 --> 1;
```

## todo:
1. benchmark
2. write a brief explanation based on the comments in [the implementation code](src/tarjan.cc)
