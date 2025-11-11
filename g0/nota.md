# OpenGL
Reference: [Learn OpenGL](https://learnopengl.com/)

## brief:
- Khronos group looks after the spec, development and maintainence of the OpenGL API.

- As of now its a legacy API as we have Vulkan, DirectX, WebGPU, WebGPU replacing it in the stack.

- For the OpenGL spec remained constant, but how you implement is free of any restraint, so each graphic card manufacturer had a verying approach on reaching the spec

- Latest spec as of now is v3.3

## Core- profile vs Immediate mode:
- Default is immediate or the fixed function pipeline, very easy for drawing graphics
- immediate mode abstracts most of the implementation hence its easy but its very inefficient and non-developer friendly
- immeidate mode deprecated from v3.2 and now core-profile is the default
- core-profile helps us do most of the impl for the spec and thereby learn stuff but also is tough/good learning curve initally on how we achieve the spec needed
- post v3.3 core-profile remains intact but additional tasks get added to slightly efficiently achieve existing routines
- devs target old open gl version so as to target most of the gfx cards while latest cards support the latest open gl versions
- OpenGL supports extensions/ mods by third party which extends/optimizes internal impl

## State System:
- OpenGL by itself is a [state machine](https://en.wikipedia.org/wiki/Finite-state_machine)and operates through different states and the whole rendering/drawing things happens through manipulating the states
- so state, context, state change, current state are all common occurence across the different operations we do in opengl

## Objects:
- OpenGL on its core impl, is written in C
- Since c's lang constructs don't universally translate to other high level langs, they use object abstractions to make it easier to do translations
- in specific, an object is a **collection of options** that is a subset of OpenGL's state.
- in a way, it is to abstract the individual apis and group them into different layers to abstract from

