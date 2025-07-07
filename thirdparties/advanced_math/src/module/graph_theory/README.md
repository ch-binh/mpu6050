# Dijkstra's Algorithm Implementation — Embedded-Oriented Design

Note: AI generated 

## Overview

This project aims to implement Dijkstra's shortest path algorithm in C with a design philosophy aligned with embedded systems development. The focus is on performance, memory predictability, and portability. The project also includes a Python-based visualization tool to aid in understanding and debugging graph traversal behavior.

---

## Objectives

- Implement Dijkstra's algorithm in C without dynamic memory allocation.
- Utilize data structures and coding practices suitable for resource-constrained embedded environments.
- Design the system in a modular way, separating algorithm logic from platform-dependent code.
- Build a Python tool to visualize graph structures and highlight computed shortest paths.
- Gain foundational knowledge in graph theory and algorithmic efficiency applicable to firmware-level programming.

---

## Skills and Concepts Covered

| Category            | Skills Acquired                                                                |
| ------------------- | ------------------------------------------------------------------------------ |
| **Algorithms**      | Dijkstra's shortest path, BFS, greedy selection, priority queue design         |
| **Data Structures** | Static adjacency list, array-based min-heap, distance tables, visitation flags |
| **Embedded Design** | Memory-bounded logic, static allocation, deterministic execution               |
| **Software Design** | Modular C codebase, clear API design, minimal dependencies                     |
| **Visualization**   | Use of Python (`networkx`, `matplotlib`) for real-time graph rendering         |

---

## Project Structure


dijkstra_project/
├── src/
│ ├── dijkstra.c # Core algorithm implementation
│ ├── graph.c # Graph construction and parsing utilities
│ └── main.c # Entry point, I/O handling
├── include/
│ ├── dijkstra.h
│ └── graph.h
├── test/
│ └── input_graph.txt # Graph input in text format
├── output/
│ └── result_path.txt # Output shortest path and costs
└── python/
└── visualize_path.py # Visualization and performance



---

## Development Phases

### Phase 1: Core Algorithm (C)
- Implement graph parsing using a static adjacency list.
- Implement Dijkstra's algorithm using a manually managed array-based min-heap.
- Output shortest path and cost to a structured file format.

### Phase 2: Python Visualization
- Read input and output files.
- Use `networkx` to render the graph.
- Highlight the path, node costs, and optionally animate the traversal.

### Phase 3: Embedded Optimization
- Replace all dynamic allocations with fixed-size arrays.
- Convert types to fixed-width integers (e.g., `uint8_t`, `int16_t`).
- Remove `printf` in favor of pluggable logging macros.
- Encapsulate all logic in standalone functions to ease firmware integration.

---

## Embedded-Friendly Design Notes

| Feature              | Implementation Strategy                                   |
| -------------------- | --------------------------------------------------------- |
| Memory Management    | No `malloc`; all buffers statically allocated             |
| Priority Queue       | Custom min-heap using fixed-size array                    |
| Graph Representation | Adjacency list in static arrays (`graph[MAX][MAX_EDGES]`) |
| Output Logging       | Buffered file output or stubs for UART/serial logging     |
| Portability          | Avoid all non-standard C features and dependencies        |

---

## Optional Extensions

| Challenge                  | Benefit                                                 |
| -------------------------- | ------------------------------------------------------- |
| Implement A*, Bellman-Ford | Learn cost heuristics and negative-edge handling        |
| Visualize large graphs     | Benchmark scalability and cache behavior                |
| Dynamic graph updates      | Add/remove edges at runtime using embedded-safe buffers |
| Port to STM32 or ESP32     | Test performance and resource limits on real hardware   |

---

## Dependencies

- **C Toolchain**: `gcc` or any embedded-compatible compiler (e.g., `arm-none-eabi-gcc`)
- **Python Tools**: `networkx`, `matplotlib`, `pandas` (for analysis and plotting)

---

## License

This project is provided under the MIT License.

