---
tags:
  - moc
  - cpp20
  - gpu-architecture
  - roadmap
status: Active
target_date: 2026-04-30
---
# GPU Architecture & C++20 Immersion Roadmap

---

  

## Week 1: The Silicon Foundation (Bits and Lines)

**Focus:** Memory footprint accuracy, bitwise logic, and one-dimensional memory buffers.

  

- [ ] **Mobile Device (Concept Familiarization):** Review documentation on the `<bit>` header and `<cstdint>`.

- [ ] **Mobile Device (Concept Familiarization):** Study intuitive explanations of Bresenham's line algorithm.

- [ ] **Secondary Screen (Theoretical Study):** Review CMU 15-462 (Rasterization), focusing on line drawing mechanics.

- [ ] **Secondary Screen (Theoretical Study):** Analyze architectural comparisons between CPU ALUs and GPU ALUs.

- [ ] **Workstation (Practical Implementation):** Implement C++20 bitwise flag operations (Set/Clear/Toggle).

- [ ] **Workstation (Practical Implementation):** Implement Bresenham's line algorithm utilizing strict `uint32_t` types, outputting to a one-dimensional `std::vector`.

  

## Week 2: Data Structures and Memory (Throughput Optimization)

**Focus:** Data-Oriented Design (SoA), CPU Cache utilization, and 2D shape rasterization.

  

- [ ] **Mobile Device (Concept Familiarization):** Research Structure of Arrays (SoA) versus Array of Structures (AoS) memory layouts.

- [ ] **Mobile Device (Concept Familiarization):** Research CPU Cache Lines and memory latency implications.

- [ ] **Mobile Device (Concept Familiarization):** Research Barycentric coordinates.

- [ ] **Secondary Screen (Theoretical Study):** Review CppCon presentations on Data-Oriented Design.

- [ ] **Secondary Screen (Theoretical Study):** Diagram Barycentric mathematics for point-in-triangle testing.

- [ ] **Workstation (Practical Implementation):** Refactor existing vertex data structures to conform to SoA principles.

- [ ] **Workstation (Practical Implementation):** Implement solid triangle rasterization utilizing Barycentric mathematics.

  

## Week 3: Safe Hardware States and Depth Testing

**Focus:** Modern C++ safety paradigms (`std::optional`) and 3D depth buffers.

  

- [ ] **Mobile Device (Concept Familiarization):** Review `std::optional` and `std::variant` documentation.

- [ ] **Mobile Device (Concept Familiarization):** Research Z-buffer algorithms and Early-Z culling concepts.

- [ ] **Secondary Screen (Theoretical Study):** Analyze visual breakdowns of Z-fighting and the depth testing pipeline.

- [ ] **Secondary Screen (Theoretical Study):** Review modern C++ error handling methodologies (exceptionless design).

- [ ] **Workstation (Practical Implementation):** Integrate a Z-buffer array into the rasterizer architecture.

- [ ] **Workstation (Practical Implementation):** Implement depth testing, utilizing `std::optional` to discard occluded pixels efficiently.

  

## Week 4: Parallel Execution and Architecture

**Focus:** SIMT (Single Instruction, Multiple Threads) architecture, C++ execution policies, and the complete rendering pipeline.

  

- [ ] **Mobile Device (Concept Familiarization):** Research `std::execution::par` implementation in C++17/20.

- [ ] **Mobile Device (Concept Familiarization):** Research NVIDIA Warp and Wavefront scheduling mechanisms.

- [ ] **Secondary Screen (Theoretical Study):** Review NVIDIA GTC architecture deep dives.

- [ ] **Secondary Screen (Theoretical Study):** Diagram the complete Fixed-Function Graphics Pipeline.

- [ ] **Workstation (Practical Implementation):** Develop a parser for `.obj` 3D model files.

- [ ] **Workstation (Practical Implementation):** Render a 3D model, applying parallel execution policies for multi-threaded triangle processing.