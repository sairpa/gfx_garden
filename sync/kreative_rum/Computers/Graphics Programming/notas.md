- cpp17, cpp20
- shader toy, hlsl, glsl
- renderdoc, tracer, shader compilation 
- pbr
- blender add ons
	- usd or gltf import export helper tool

A timeline of sorts:
- phase1
	- graphics pipeline
		- real-time pipeline
		- vertex shaders to fragment shaders to compute shaders
		- rasterization
		- framebuffer
		- depth testing
		- blending
	- shaders
		- do stuff in unity or godot
		- post processing effects
		- use the engine's frame debugger
	- final delivery:
		- small scene with processing and custom shaders
		- renderdoc capture with notes about the scene( draw order, gbuffer)
- phase 2
	- modern C++ learning



# Plan

### **Phase 1: Modern C++ & Software Rendering (Weeks 1-4)**

**Goal:** Prove you understand the math behind the API using "Bleeding Edge" C++. **Environment:** Fedora 43 (GCC 15) | **Machine:** Dell G5 (Dev).

- **Week 1: C++20/23 Deep Dive**
    
    - **Focus:** Stop writing "C with Classes." Start writing **Data-Oriented C++**.
        
    - **Task:** Implement the `MinRend` wireframe code we started.
        
    - **Key Concept:** Use `std::span` to pass image buffers (zero copy). Use `std::variant` for material types.
        
    - **Reading:** _Effective Modern C++_ (Items on Move Semantics & Smart Pointers).
        
- **Week 2: Rasterization (The "Triangle" Math)**
    
    - **Task:** Implement "Barycentric Coordinates" manually. Fill the triangles with color.
        
    - **Why:** Performance roles ask: _"How does the GPU decide which pixel belongs to a triangle?"_ You need to know the math (Edge functions) to answer this.
        
    - **Deliverable:** A lit, textured African Head model rendered to TGA without OpenGL/Vulkan.
        
- **Week 3: The Z-Buffer (Hidden Surface Removal)**
    
    - **Task:** Implement a Depth Buffer (`std::vector<float> zbuffer`).
        
    - **Optimization:** Change your loop to check `if (z < zbuffer[x,y])` before calculating color.
        
    - **Why:** This teaches you about **Early-Z rejection**, a critical GPU optimization concept.
        
- **Week 4: The "Modern" Refactor**
    
    - **Task:** Rewrite your inner render loop using `std::execution::par` (Parallel Algorithms) to use all CPU cores.
        
    - **Why:** Shows you understand multi-threading and CPU saturation.
        

---

### **Phase 2: The GPU & Bottlenecks (Weeks 5-8)**

**Goal:** Learn how to break a GPU. **Environment:** Dell G5 (High Perf) & Dell Vostro (Low Perf).

- **Week 5: Vulkan Compute (No Graphics)**
    
    - **Task:** Write a "Headless" Vulkan program. No window. Just a **Compute Shader**.
        
    - **Project:** "N-Body Gravity Simulation." 100,000 particles attracting each other.
        
    - **Why:** Modelling jobs focus on _Compute_ and _Data Movement_, not just drawing pixels.
        
- **Week 6: The "Vostro" Challenge**
    
    - **Task:** Run your N-Body sim on the **Dell Vostro (Radeon 520)**.
        
    - **Observation:** It will crawl.
        
    - **Fix:** Change `float` (32-bit) variables to `float16` / `half` (16-bit) in your shader. Optimize the "Group Size" in the shader.
        
    - **Deliverable:** A text file log comparing FPS: `G5: 600 FPS` vs `Vostro Before: 5 FPS` vs `Vostro After: 22 FPS`.
        
- **Week 7: Shared Memory Optimization**
    
    - **Task:** Optimize the shader to use `shared` memory (L1 Cache on GPU). Pre-load particle data into shared memory before math.
        
    - **Why:** This is the #1 interview question at NVIDIA: _"How do you optimize global memory access?"_
        
- **Week 8: Integration**
    
    - **Task:** Visualise the particles using **Raylib** (Interop).
        
    - **Result:** A cool looking demo where 100k particles swirl smoothly.
        

---

### **Phase 3: The "Modelling" Career Project (Weeks 9-12)**

**Goal:** Build the tool that makes you a "Performance Modelling Engineer." **Concept:** You don't just run code; you _simulate_ how hardware runs code.

- **Week 9: The "Toy GPU" Simulator**
    - **Task:** Create a C++ Console App.
    - **Input:** A fake assembly text file:
    - **Logic:** Write a C++ class that tracks a "Global Clock." When it sees `LOAD`, it adds 100 to the clock.
        
    - **Why:** This is what the **Qualcomm Adreno Modelling Team** does all day.
        
- **Week 10: The Stall Analyzer**
    
    - **Task:** Add a "Pipeline" feature. If instruction 2 depends on instruction 1 (R1), the simulator must "Stall."
        
    - **Output:** `Total Cycles: 104. Pipeline Stalls: 1.`
        
- **Week 11: Profiling & Documentation**
    
    - **Task:** Profile your Phase 2 project using **NVIDIA Nsight Systems**.
        
    - **Deliverable:** A 2-page PDF Case Study.
        
        - _Title:_ "Optimizing Compute Shaders for Low-Power Architectures."
            
        - _Content:_ Screenshot of Nsight timeline showing a "Memory Stall," followed by code snippet of your fix, followed by the "After" screenshot.
            
- **Week 12: Application & Portfolio**
    
    - **Resume Update:**
        
        - **Title:** "C++ Systems Engineer | GPU Performance"
            
        - **Projects:** "Custom C++20 Rasterizer," "Vulkan Compute Particle Sim," "GPU Architecture Cycle Simulator.".s