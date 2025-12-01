# OpenGL

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
  
## Window :D

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