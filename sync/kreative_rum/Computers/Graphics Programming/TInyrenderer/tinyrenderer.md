Contents:
- [Bresenham's line drawings](#bresenhams-line-drawings)

- By Dimitry V Sokolov
- Intention is to mimick graphics apis like opengl, vulkan, directx and metal through bare metal cpp and ideas
- End task is to use no third-party library to renderer which could generate images and render models
- Ideal input would be to have a 3D model be visualised and rendered while the output is to have it rendered and show out the image of the model
- [TGA files](https://en.wikipedia.org/wiki/Truevision_TGA)  are easiest format supporting rgb, rgba and greyscale images. We have one helper class to help aid image manipulations.
- our start point helper would get us to manipulate the image color by pixels and nothing more :D
- [codebase here](https://github.com/ssloy/tinyrenderer)


## bresenhams-line-drawings
### HW: Wireframe Rendering
- Objective is to create line segments 😄 and thereby end up creating triangles 🙂
-  we have an input obj model file
	- lines with a ***v*** is vertices and has a *[x,y,z]*
	- lines with a ***f*** is the face and has indices of the vertices to be joint!
	- **indices start from 1 in obj files**
- our output is to figure out a way to render this:
	- ![[Pasted image 20251216003541.png]]
- ***Idealogy:***
	- bresenham's line algo (modified and optimised version):
		- to utilize the string-view library from the latest CDD standards