#include <iostream>
#include <stdio.h>
#include "canvas.h"
#include <stdarg.h>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int main() {
    Canvas canvas(10, 50);
    canvas.set_pixels(4, 4, 25, 124, 3, 33, 124, 2, 24, 95, 4, 3, 95);
    canvas.set_pixels(3, 7, 2, 95, 4, 21, 124, 5, 16, 95);
    canvas.set_pixels(3, 4, 41, 124, 7, 1, 124, 5, 8, 92);
    canvas.set_pixels(3, 1, 31, 40, 2, 3, 95, 2, 41, 124);
    canvas.set_pixels(5, 2, 16, 95, 5, 35, 92, 6, 3, 95, 2, 11, 95, 5, 3, 95);
    canvas.set_pixels(5, 2, 38, 95, 4, 9, 40, 3, 41, 124, 2, 37, 95, 2, 25, 124);
    canvas.set_pixels(5, 5, 27, 124, 2, 27, 124, 4, 0, 124, 3, 35, 47, 2, 18, 95);
    canvas.set_pixels(4, 4, 13, 124, 4, 37, 95, 4, 16, 40, 3, 6, 124);
    canvas.set_pixels(4, 7, 32, 47, 4, 20, 124, 5, 11, 95, 5, 42, 95);
    canvas.set_pixels(4, 5, 15, 92, 4, 34, 124, 4, 45, 41, 5, 24, 95);
    canvas.set_pixels(3, 4, 2, 40, 7, 3, 95, 2, 44, 95);
    canvas.set_pixels(5, 6, 30, 95, 5, 45, 95, 4, 31, 124, 4, 7, 124, 3, 43, 39);
    canvas.set_pixels(3, 5, 17, 95, 1, 27, 124, 2, 5, 95);
    canvas.set_pixels(5, 3, 44, 95, 3, 19, 92, 5, 23, 95, 3, 8, 47, 2, 10, 95);
    canvas.set_pixels(4, 6, 6, 124, 5, 19, 47, 3, 24, 95, 3, 27, 124);
    canvas.set_pixels(5, 3, 10, 95, 4, 44, 95, 2, 9, 95, 0, 32, 95, 5, 2, 95);
    canvas.set_pixels(4, 6, 2, 95, 7, 31, 95, 1, 25, 124, 2, 36, 95);
    canvas.set_pixels(5, 3, 46, 92, 5, 25, 44, 1, 43, 124, 5, 46, 47, 3, 15, 47);
    canvas.set_pixels(3, 4, 17, 95, 2, 23, 95, 3, 39, 92);
    canvas.set_pixels(3, 4, 47, 124, 2, 45, 95, 3, 37, 95);
    canvas.set_pixels(5, 5, 44, 95, 2, 2, 95, 5, 10, 95, 5, 9, 95, 4, 43, 124);
    canvas.set_pixels(3, 4, 38, 41, 2, 17, 95, 0, 26, 95);
    canvas.set_pixels(4, 4, 18, 41, 7, 5, 47, 5, 41, 124, 5, 33, 124);
    canvas.set_pixels(4, 5, 12, 47, 5, 22, 92, 6, 33, 124, 5, 31, 124);
    canvas.set_pixels(5, 4, 40, 124, 3, 3, 95, 4, 4, 124, 6, 31, 47, 3, 4, 96);
    canvas.set_pixels(3, 0, 42, 95, 5, 18, 95, 4, 27, 124);
    canvas.set_pixels(5, 3, 12, 92, 2, 32, 95, 5, 37, 95, 5, 26, 95, 5, 39, 47);
    canvas.set_pixels(4, 3, 25, 96, 4, 14, 124, 4, 33, 124, 3, 1, 47);
    canvas.set_pixels(5, 5, 36, 95, 7, 30, 95, 6, 4, 47, 4, 24, 95, 1, 32, 95);
    canvas.set_pixels(3, 3, 22, 47, 4, 23, 40, 5, 6, 124);
    canvas.set_pixels(3, 1, 33, 41, 1, 41, 124, 7, 29, 124);
    canvas.set_pixels(4, 4, 6, 124, 5, 38, 95, 3, 31, 124, 7, 4, 95);
    canvas.set_pixels(3, 4, 11, 41, 4, 10, 95, 5, 1, 92);
    canvas.set_pixels(4, 2, 43, 124, 3, 17, 95, 5, 4, 44, 4, 36, 40);
    canvas.set_pixels(1, 5, 43, 46);

    canvas.print();
}