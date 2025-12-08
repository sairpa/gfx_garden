### **Month 1: The "Black Box" Breaker**

**Prerequisites (Linux/Fedora):**

* Ensure you have the build tools: `sudo dnf install cmake gcc-c++ mesa-libGL-devel glfw-devel glm-devel`
* Debuggers: `gdb` and `valgrind` (crucial for C++ segfaults).

#### **Week 1: The "Hello World" (The API Contract)**

* **Goal:** Get a triangle on the screen using  **OpenGL 3.3+ (Core Profile)** .
* **The Trap:** Most tutorials give you a "boilerplate" header file. **Do not use it.**
* **The Task:**
  1. Follow([https://learnopengl.com/Getting-started/Hello-Triangle](https://learnopengl.com/Getting-started/Hello-Triangle)).
  2. **Manual Setup:** Type out the `gladLoadGLLoader` and `glfwCreateWindow` logic manually. You need to feel the pain of setting up a graphics context.
  3. **The "Driver" Test:** Once the triangle works, intentionally break the data. Change the `float vertices` array size but tell OpenGL it's the original size.
     * *Result:* You will likely see garbage pixels or a crash. This is memory aliasing. You just saw what happens when a driver reads bad memory.

#### **Week 2: The Math (The Pipeline)**

* **Goal:** A rotating 3D Cube with a texture.
* **The Trap:** Using GLM (the math library) for everything without understanding the layout.
* **The Task:**
  1. Follow([https://learnopengl.com/Getting-started/Coordinate-Systems](https://learnopengl.com/Getting-started/Coordinate-Systems)).
  2. **The "Anti-Tutorial" Twist:** Do not use `glm::rotate`. Write your own function that constructs a 4x4 Rotation Matrix from scratch (using simple arrays) and pass that to the shader.
  3. **Why:** This forces you to understand **Memory Layout** (Column-Major vs. Row-Major). If your cube stretches or vanishes, your memory layout doesn't match what the GPU expects—a classic Driver Engineer bug.

#### **Week 3: The "Bridge" (The Software Driver)**

* **Goal:** Write a "Software Rasterizer" (Draw a triangle *without* OpenGL).
* **The Trap:** Thinking graphics is magic.
* **The Task:**
  1. Put OpenGL aside. Create a `ppm` image file using a C++ `for` loop.
  2. Implement **Barycentric Coordinates** to fill a triangle with color.
  3. **Resource:** ([https://github.com/ssloy/tinyrenderer](https://github.com/ssloy/tinyrenderer)) (Lessons 1-3).
  4. **Why:** By writing the logic to turn "three points" into "filled pixels" on the CPU, you are effectively  **writing a driver** . You will face problems like "Z-fighting" and "floating point precision" firsthand.

#### **Week 4: The Hardware Reality (Profiling)**

* **Goal:** Profile your Week 2 Cube.
* **The Trap:** optimizing code based on guesses.
* **The Task:**
  1. Install **NVIDIA Nsight Systems** (Linux version).
  2. Run your "Spinning Cube" application through Nsight.
  3. **Identify:** Look for the blue bars (CPU work) and the green/other bars (GPU work).
  4. **Experiment:** What happens to the timeline if you draw 10,000 cubes? Do the CPU bars get longer (Driver overhead) or do the GPU bars get longer (Rendering bottleneck)?
