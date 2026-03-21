#### By Eric Haines, Autodesk

Main focus on fundamentals and using the inferences to build 3d graphics based applications

# Interactive 3D Rendering

Render -> To create an image :D
3D -> Representing the image in a 3 Dimensional Space
Interactive -> Not static and able to control, influence or affect things in the world

Distinction here being able to render things dynamically and also with agency of the user or interactions enabled!

## WebGL

Web Graphics Library

Supported amongst all chrome and firefox versions :D

## Core Ideas:
- [Refresh rate, frames per second](#interactivity)
- [Eye, pinhole cam, view frustum](#eyes)
- [Graphics pipeline](#graphics_pipeline)

## Interactivity

- Action and response
- 6 FPS is the minimal perceptable motion thought it still looks super choppy
- ideal fps are 24fps(films), 30fps(handheld consoles), 60fps(pc games)
- fps -> frame rate
- hertz -> monitor spec for max possible frames to be shown at one second
- films use 24fps thought won't look choppy due to the extensive use of motion blur and other techniques
- plus they are not interactive, which helps on not being discernable on the 24 vs 30 v 60 fps
-  CPU Cyles: - 1 hz -> 1fps -> 1/(time) -> no of time the image gets rendered/refreshed 

## Eyes
- rods (low level lighting, peripheral vision), cons(high level lighting, color vision)
- vision forms at a particular place in cons
- iris control the level of light entering stuff
- this is signal transmitted to the brain
#### Pinhole Camera:
- A way to simulate eye and principle of rays through physics and mechanics
- With a Pinhole camera, you put a piece of photographic film at one end of a box and poke a hole in the other end, then you cover up this hole.
- With the Pinhole camera, the light coming in from one-direction is detected by a single location on the flat rectangle of the film.Put these differing light contributions together, and you get a picture.
#### Eyes vs Cameras:
![[Pasted image 20251204215255.png]]
- eye is a dynamic system with controls over and not limiting to:
	- amount of light processed, to enter
	- the focal distance
	- dynamic range in a dynamic sense and not procedural-based

#### View Frustum
- In mechanical and physics terms, A pinhole camera captures an image upside down.
- In CG, we think ofa camera a bit differently with the image being formed in front of the viewer.
- The scene composition happens more of a projection onto our screen directly
- the pyramid like viz of the world is called a frustum
  ![[Pasted image 20251204215724.png]]
- In a camera we gather photons from the world and these createa photograph.
- In computer graphics, we simulate the real world as best we canand try to determine how many photons are coming in each direction
- This in the end appears as a pixel to the viewers on a screen :D

## Graphics_Pipeline

- Composition is key and we compose everything we realise in 3D in a 2D frustum plan and thereby define the scene
- The 3D component is defined through motion and interactivity
- A depth component too visible through the perspective of the rendering camera or through the way objects stack onto each other or with respect to others.
- ***How much light arrives and how to render em?***:
	- In theory, we can simulate the whole end to end physical process computationally but it is expensive and also not necessarily the efficient way
	- Rasterisation, ray tracing the common techniques used here :D
### Compromises:
To reduce unnecessary computation, we have base assumptions that carry through most CG practises/tech/frameworks:
1. Only the photons which reach the camera are needed to make the image
	- Each photon originates from a light source but we don't know where each of em end up
	- We reverse the process by ray casting through the eye of the camera and end up seeing what appears :D
	- when a surface gets hit, we calculate and compute the appropriate light calculations needed.
	- Do this reverse ray cast enough time and we end up with a gross but conclusive assessment of the surroundings :)
2. Every surface is considered visible unless it faces away from the light source
	- this helps eradicate complex compute needed to account bounces, scattering and transparency
Far more simpler rendering system could be achieved going for more assumptions but it is mainly due to artistic choice or resource constraints and would mostly result in not-so-realistic environment/rendering in general.

