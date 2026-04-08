# The Anti-Fragile April Roadmap: GPU Architecture

**Objective:** Build a C++20 Software Rasterizer by April 30th to pivot into Hardware Simulation/GPU Architecture.
**The Anti-Fragile Protocol:** 
1. Assume a maximum of 3 deep-focus days per week.
2. If the week blows up, execute the "15-Minute Minimum": Read theory on the phone.
3. **Scavenge** the theory online -> **Sandbox** the proof using `g++ -std=c++20`.

---

## Week 1: April 1 - April 7 (Bits & The Sandbox)
**Core Goal:** Master fixed-width memory, bitwise logic, and 1D memory buffers.

- [ ] **Core (Laptop):** Compile a C++20 test using `<cstdint>` (`uint32_t`) and `<bit>` (`std::popcount`).
- [ ] **Flex (Phone):** Research Bresenham's Line Algorithm. Focus on the integer-only coordinate stepping logic.
- [ ] **Core (Laptop):** Create a 1D `std::vector<uint32_t>` to act as a screen buffer.
- [ ] **Core (Laptop):** Write a function to calculate the 1D indices required to draw a line between two 2D coordinates (Bresenham's).

## Week 2: April 8 - April 14 (Memory & Triangles)
**Core Goal:** Unlearn OOP. Structure data for the CPU cache and fill a 2D shape.

- [ ] **Flex (Phone):** Research "Structure of Arrays (SoA)" vs "Array of Structures (AoS)". Understand CPU cache line hits.
- [ ] **Flex (Phone):** Investigate Barycentric coordinates for point-in-triangle testing.
- [ ] **Core (Laptop):** Structure your vertex and color data using the SoA paradigm.
- [ ] **Core (Laptop):** Implement a rasterizer function that sweeps the buffer, using Barycentric math to fill a solid triangle.

## Week 3: April 15 - April 21 (Safety & Depth)
**Core Goal:** Simulate hardware state machines and handle 3D overlapping geometry.

- [ ] **Flex (Phone):** Research `std::optional` for exceptionless state handling.
- [ ] **Flex (Phone):** Research the Z-buffer (Depth Buffer) algorithm and Early-Z culling.
- [ ] **Core (Laptop):** Allocate a second 1D vector to serve as the Z-buffer.
- [ ] **Core (Laptop):** Update the rasterizer to check the Z-buffer. Use `std::optional` to elegantly discard occluded pixels.

## Week 4: April 22 - April 28 (Parallel Execution)
**Core Goal:** Make the CPU emulate a GPU's SIMT (Single Instruction, Multiple Threads) architecture.

- [ ] **Flex (Phone):** Research C++ standard execution policies (`std::execution::par`).
- [ ] **Flex (Phone):** Understand standard `.obj` 3D model file structures (vertices and faces).
- [ ] **Core (Laptop):** Write a minimal parser to load a `.obj` file into your SoA memory.
- [ ] **Core (Laptop):** Wrap your rendering loop in a parallel execution policy to utilize all CPU cores simultaneously.

---
## Buffer Zone: April 29 - April 30
**Core Goal:** Catch up, polish, and synthesize. 
- [ ] Complete any spilled-over tasks. 
- [ ] Synthesize Obsidian notes on architecture bottlenecks discovered during the build.