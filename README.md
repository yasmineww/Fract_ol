# Fract_ol
Discover how to program in 2D and explore the mesmerizing world of fractals through this project utilizing the 42 MinilibX library. This project consists of creating a small fractal exploration program, through the Julia set and the Mandelbrot set.  
## Fractals

A fractal is a never-ending pattern. Fractals are infinitely complex patterns that are self-similar across different scales. They are created by repeating a simple process over and over in an ongoing feedback loop. Driven by recursion, fractals are images of dynamic systems – the pictures of Chaos. Mathematical fractals, like the Mandelbrot Set, are formed by calculating a simple equation thousands of times. These fractals are infinitely complex,  meaning we can zoom in forever. A fractal is made by repeating a simple process again and again.

## ALGEBRAIC FRACTALS : THE MANDELBROT SET

We can create fractals by repeatedly calculating a simple equation over and over. Because the equations must be calculated thousands or millions of times, we need computers to explore them. Not coincidentally, the Mandelbrot Set was discovered in 1980, shortly after the invention of the personal computer.

Anytime the value of the orbit goes beyond an absolute value of two, it is guaranteed to hit towards infinity. The orbits are contained within the area -2 to 2. Any point that has an orbit that escapes the radius 2 boundary is known to be outside the Mandelbrot set. So which points escape and which stay bounded. The values above 0.25 quickly escape and those below do not. 

The connection between the Julia set and the Mandelbrot set comes when you choose a specific initial value for Z in the Julia set iteration. If you pick the initial value Z to be 0, and then iterate over different C values, the resulting Julia sets will exhibit a relationship to the Mandelbrot set. in summary, if you use different initial values for Z when generating Julia sets, combining them won't necessarily give you the Mandelbrot set. The Mandelbrot set is more directly related to the Julia sets when the initial value of Z is fixed at 0.

## Working with complex numbers

We need to create a struct composing of two parameters; the first being the axe x (of real numbers) and the y axial (of the imaginary numbers). Our struct is going to look like this :

'''typedef complex
{
		double x;
		double y;
} n_complex;'''

## MiniLibX

A small library which implements some basic functions that allow you to quickly open a window and to draw within it. `mlx.h` should be included for a correct use of the MiniLibX API. It only contains function prototypes, no structs are needed.

- mlx_init : `void *mlx_init ();`
    
    First of all, you need to initialize the connection between your software and the display using the `mlx_init` function. If `mlx_init` fails to set up the connection to the graphical system, it will return NULL, otherwise a non-null pointer is returned as a connection identifier.
    
- mlx_new_window – Manage windows : `void  * mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);` **size_x** and **size_y** parameters to determine its size, title is the text displayed in the window’s title bar, **mlx_ptr** is the connection identifier returned by **mlx_init**. If **mlx_new_window** fails to create a new window, it will return NULL, otherwise a non-null pointer is returned as a window identifier.
- mlx_pixel_put – Draw inside windows :  `mlx_pixel_put  (void *mlx_ptr, void *win_ptr, int x, int y, int color);`
- mlx_new_image – Manipulate images
- mlx_loop – Handle keyboard or mouse events : `int mlx_loop (void *mlx_ptr);`
    
    **Events :** The program can get information from the keyboard and mouse associated to the screen called “events”. To receive events, you must use **mlx_loop**, It is an infinite loop that waits for an event, and then calls a user-defined function associated with this event.
