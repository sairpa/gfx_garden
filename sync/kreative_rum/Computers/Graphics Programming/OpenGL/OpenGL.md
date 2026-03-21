## Topics
- [Brief](#brief)
- [Core profile vs Immediate mode](#core-profile-vs-immediate-mode)
- [State System](#state-system)
- [Objects](#objects)
- [Window](#window)
- [Creating a Triangle](#creating_a_triangle)

Reference: [Learn OpenGL](https://learnopengl.com/)
## Brief
- Khronos group looks after the spec, development and maintainence of the OpenGL API.
- As of now its a legacy API as we have Vulkan, DirectX, WebGPU, WebGPU replacing it in the stack.
- For the OpenGL spec remained constant, but how you implement is free of any restraint, so each graphic card manufacturer had a verying approach on reaching the spec
- Latest spec as of now is v3.3
## Core- profile vs Immediate mode
- Default is immediate or the fixed function pipeline, very easy for drawing graphics
- immediate mode abstracts most of the implementation hence its easy but its very inefficient and non-developer friendly
- immeidate mode deprecated from v3.2 and now core-profile is the default
- core-profile helps us do most of the impl for the spec and thereby learn stuff but also is tough/good learning curve initally on how we achieve the spec needed
- post v3.3 core-profile remains intact but additional tasks get added to slightly efficiently achieve existing routines
- devs target old open gl version so as to target most of the gfx cards while latest cards support the latest open gl versions
- OpenGL supports extensions/ mods by third party which extends/optimizes internal impl  
## State System
- OpenGL by itself is a [state machine](https://en.wikipedia.org/wiki/Finite-state_machine)and operates through different states and the whole rendering/drawing things happens through manipulating the states
- so state, context, state change, current state are all common occurence across the different operations we do in opengl
## Objects
- OpenGL on its core impl, is written in C
- Since c's lang constructs don't universally translate to other high level langs, they use object abstractions to make it easier to do translations
- in specific, an object is a **collection of options** that is a subset of OpenGL's state.
- in a way, it is to abstract the individual apis and group them into different layers to abstract from
- derived from how c has structures or structs
- Helps abstracts lots of variables involved in the state machine by grouping them into sections and thereby using only appropriate ones when needed
## Window
- First things always is to create "an OpenGL Context" and an application window to draw in :)
- This step varies per usecase and also heavily as per the operating system so its not a thingy in consideration by OpenGL APIs
- **GLFW - Graphics library framework** is a helper library which helps us create the said context and app window agnostic of use cases/ operating system
- Usual gymnastics of cmake source, cmake build and cmake install commands ensue: <br>
`cmake ..; make -j 100; sudo make install`
- to link to our application, we need the linker flag -lGL
- once its all done, we can happily add: <br>
`#include <GLFW\glfw3.h>`
- **GLAD** is the library used for function definition lookups for the operating system to load stuff for apps using different or same versions of OpenGL
- [GLAD](https://github.com/Dav1dde/glad) is super conventional on it being a web service api instead of a core lib and we query through a web interface, setting lang to c++, then the OpenGL version and then the profile being Core and finally *"Generating the loader"*
  - Its better to download from [source](https://www.glfw.org/download.html) and build, make and sudo make install em and make it easier for building the app
- this was the build command with all of the linking libs added:
`g++ g01.cpp -o css -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl`


- glad zip to be pasted into the computer directory as is
  ![[Pasted image 20251208231558.png]]
  - include for glad to be put before glfw so as to use the version specified for us and utilize headers needed for OpenGL applications
  - need to use -I flag to include the newly added glad files
  - `g++ -I./include/ -lglfw -lGL -lm -lpthread -lXi -ldl ./window.cpp ./src/glad.c -o win`
  - ![[Pasted image 20251208232115.png]]
	  - glfwInit is the GLFW library initalizer
	  - glfwWindowHint helps us config the window we are trying to spawn
		  - context version to be atleast and atmost 3
		  - the profile to be core and not compatibility
		  - This is an enum and we habe a lot of other options
		  - Useful to point out which config went wrong when we get undefined references 
	  - This config broadly helps us to narrow down the subset of OpenGL features we want to utilize


### Creating_a_Triangle
- Context is everything we try to realise is 3D but in essence a monitor or a display is 2D so OpenGL and other gfx libraries do the heavy lifting of realising 3D scene in a 2D coordinate pixel system
- Rasterisation - the process of doing the above
	- Contains a lot of parallel pipelines with specialised steps
	- The pipeline defines structure while being specialized helps speed up the process 
	- Speed is important as unlike CPU, GPU has a fixed task of showing stuff imediately and can't swap or mutli thread stuff
	- GPUs contains lots of cores which process these pipeline steps and the program executing the pipeline steps is called a shader :D
	- Some are generic shader which will be common for lot of applications while some are user defined
	- OpenGL Shading Language GLSL
	- ![[Pasted image 20251210215410.png]]
	- Blue parts in the above photo are where we as developers could insert custom shaders to alter/realise a scene
	- GFX Pipeline:
		- We pass a list of 3D coordinates to form a triangle callsed the Vertex Data
			- it is a collection of vertixes
			- a vertex is a collection of data per 3D coordinate
			- In order for OpenGL to know what data we are passing, we have a config hint for that too- GL_POINTS, GL_TRAINGLES and GL_LINE_STRIP
		- First part of the Pipeline is the Vertex shader, which takes a single vertex as input
			- its main work is to transform 3D coordinates into processable data based on the vertex attributes
			- The primitive assembly stage takes in all vertices as inputs from the vertex shaders and forms a triangle from the gathered data
			- This triangle ouptut is fed as input to the Geometry shader
		- The second part is the geometry shader, taking the trangle/s as input
			- 