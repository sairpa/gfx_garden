# 🛠️ The Sandbox & Scavenge Roadmap: GPU Architecture

**Objective:** Transition to GPU Architecture (Vertical 1) via self-directed research and strict C++20 execution.
**Protocol:** Scavenge the theory on mobile/secondary devices -> Execute the proof in the `gfx_garden` sandbox on Fedora.

---

## Week 1: The Silicon Foundation
**The Core Problem:** Hardware registers are rigidly sized. Displays are 1D arrays of memory. You must translate 2D spatial coordinates into 1D memory addresses using exact bit-widths.

### 📱 Scavenge Objectives (Research)
- [ ] **Objective 1.1:** Determine the modern C++ standard method for defining integers that are *exactly* 32 bits and 64 bits wide.
- [ ] **Objective 1.2:** Investigate the C++20 `<bit>` header. Find the function that counts set bits (1s) to simulate checking active threads in a Warp.
- [ ] **Objective 1.3:** Research Bresenham's Line Algorithm. Understand the integer-only math required to step from point A to point B without floating-point division.

### 💻 Sandbox Mission (Execution)
- [ ] Write a 5-line C++20 test using the exact 32-bit type and the bit-counting function you discovered.
- [ ] Build a 1D `std::vector` of 32-bit integers to represent a screen buffer.
- [ ] Write a function that calculates the 1D indices required to draw a line between two 2D coordinates.

---

## Week 2: Cache Efficiency and Data Shapes
**The Core Problem:** Object-Oriented Programming (OOP) causes CPU cache misses. You must structure data for hardware throughput and understand geometry math.

### 📱 Scavenge Objectives (Research)
- [ ] **Objective 2.1:** Contrast "Array of Structures" (AoS) with "Structure of Arrays" (SoA). Why does SoA maximize CPU cache line utilization?
- [ ] **Objective 2.2:** Investigate Barycentric coordinates. How does this formula allow a GPU to determine if a pixel is inside a triangle?

### 💻 Sandbox Mission (Execution)
- [ ] Refactor your vertex coordinate and color structures from classes (AoS) to SoA format.
- [ ] Implement a rasterizer function that sweeps across your screen buffer, utilizing Barycentric math to fill a solid triangle with color.

---

## Week 3: Exceptionless State and Depth
**The Core Problem:** Hardware uses status flags, not C++ exceptions. Rendering 3D space requires depth testing without sorting geometry.

### 📱 Scavenge Objectives (Research)
- [ ] **Objective 3.1:** Explore `std::optional` and `std::variant`. How are they used to build exceptionless, type-safe state machines?
- [ ] **Objective 3.2:** Research the Z-buffer (Depth Buffer) algorithm. What is Early-Z rejection?

### 💻 Sandbox Mission (Execution)
- [ ] Allocate a second 1D vector to act as your Depth Buffer.
- [ ] Update your triangle rasterizer to check the Depth Buffer. Use `std::optional` to elegantly discard occluded pixels without throwing errors or using negative magic numbers.

---

## Week 4: Parallel Execution
**The Core Problem:** A GPU's SIMT (Single Instruction, Multiple Threads) architecture processes massive amounts of data concurrently. You must simulate this wide execution on your CPU.

### 📱 Scavenge Objectives (Research)
- [ ] **Objective 4.1:** Research C++17/20 standard execution policies, specifically `std::execution::par`.
- [ ] **Objective 4.2:** Investigate the standard `.obj` 3D model file format. How are vertices and faces stored?

### 💻 Sandbox Mission (Execution)
- [ ] Write a minimal parser to load a `.obj` file into your SoA memory structure.
- [ ] Apply parallel execution policies to your rendering loop to rasterize the 3D model using all available CPU cores simultaneously.