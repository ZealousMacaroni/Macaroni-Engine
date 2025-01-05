MACARONI ENGINE
First step:
Build a renderer that can render multiple light sources using Phong Shading with specular and diffuse maps, multiple light sources, etc. 

3 Object Types: Object, Light, UIElement
Object: Has a Material, position, rotation, size, shape, optional diffuse/specular maps as assets
Light: Has a position, rotation, size, shape, and light color(also maybe a range thing too?)
UIElement: TBD

Object and Light are child classes of a base object class for position, size, rotation, and shape

Shapes are stored as an index, along with diffuse/specular maps

Shapes, images, and shaders are assets while in a "workspace" directory is where JSON files are stored which represent the Object types

Render the Object, blah blah blah as usual.

Make Objects have static or dynamic, showing where they are in memory.

For the first step, everything will be rendered as a static image.
