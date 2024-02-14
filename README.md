# Fract_ol
Discover how to program in 2D and explore the mesmerizing world of fractals through this project utilizing the 42 MinilibX library. This project consists of creating a small fractal exploration program, through the Julia set and the Mandelbrot set.

## Fractals

A fractal is a never-ending pattern. Fractals are infinitely complex patterns that are self-similar across different scales. They are created by repeating a simple process over and over in an ongoing feedback loop. Driven by recursion, fractals are images of dynamic systems – the pictures of Chaos. Mathematical fractals, like the Mandelbrot and Julia sets, are formed by calculating a simple equation thousands of times. These fractals are infinitely complex,  meaning we can zoom in forever (within the capacity of one's machine).

## ALGEBRAIC FRACTALS : The Math behind it

Both Mandelbrot and Julia sets are calculated using the following equation $Z_n+_1=Z_n^2+Z_0$ over and over again within the [-2 , 2] interval.
Anytime the value of the orbit goes beyond an absolute value of two, it is guaranteed to hit towards infinity. Any point that has an orbit that escapes the radius 2 boundary is known to be outside the Mandelbrot set.

Our algorithm consists of calculating the set for a number of iterations. If a given point stay bounded, we say that it belongs to the set and we color it black. However, if a given point escapes after a certain number of iteration, we color it differently depending on how many iterations it took for the point to escape. This concept is known as the **[escape time algorithm](https://mcanv.com/Art/escape_time_algorithm.html)** referring to the amount of iterations it takes a number to escape the value of 2. The Mandelbrot isn't a measurement of distance, but rather time. Not all numbers blow up and reveal their **unboundedness** as quickly. Some numbers may remain "small" for many hundreds of ith iterations before exploding in absolute value. That's why the number that we define as MAX iterations matter to visualize the true precision of set.

<p align="center">
<img src="https://github.com/yasmineww/Fract_ol/blob/main/Mandelbrot.gif">
</p>

Compared to Mandelbrot set, where c is variable in the parametric plane C, Julia sets are obtained for fixed c, therefore each number c generate a different Julia. Which makes every point in the Mandelbrot set is connected to the center of the corresponding Julia set. Fascinating isn't it?

<p align="center">
<img src="https://github.com/yasmineww/Fract_ol/blob/main/Julia.png" width=70% height=70%>
</p>

## Why is it challenging?

Theoretically, the project consists of creating an algorithm that will have the machine calculate a certain equation many times over which makes life easy. However, the challenge lies behind implementing the math graphically using mlx. This projects needs good understanding of scaling and mapping concepts, which can be tricky at first. 

Since our set exists in the complex plane, we’ll need to map the pixels so that the whole Mandelbrot will show up in the middle of the screen. If not, we'll only be displaying a very small portion of the set. Check my medium blog for further details.

<p align="center">
<img src="https://github.com/yasmineww/Fract_ol/blob/main/Julia.gif">
</p>

## Burning Ship Fractal

I added an extra fractal to my collection as required in the bonus section of the project. It consists of simply calculating the imaginary part in absolute value.

<p align="center">
<img src="https://github.com/yasmineww/Fract_ol/blob/main/Burning%20Ship.png" width=70% height=70%>
</p>
