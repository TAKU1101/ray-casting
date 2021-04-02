# ray-casting

Implementation of Ray casting system in c language

Run the following
```shell
> make
> . . /cub3d mapfile/def_ok_2.cub
````

Specify the executable file (extension .cub) as the first argument and specify the map structure.

Configuration of map file
R: Resolution  
NO, SO, WE, EA: Paths to the wall textures for each direction (xpm files).  
S: Sprite texture  
F: Floor color  
C: Ceiling color  
Bottom: Map file (1: walls, 2: sprites, N,E,S,W: players)  

The second argument is the "--save" option, which saves the initial position image as a bmp file.

Library used:  
linux drawing library  
https://github.com/42Paris/minilibx-linux
