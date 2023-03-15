#include "canvas.h"
#include <stdarg.h>
#include <stdio.h>
#include <iostream>

using namespace std;

// Implement the Canvas class methods
Canvas::Canvas(int lines, int columns) {
    
    Lines = lines;
    Columns = columns;
    clear();
}

void Canvas::set_pixel(int x, int y, char value) {
        a[x][y] = value;
}

void Canvas::set_pixels(int count, ...) {
    va_list factor;
    va_start(factor, count);
    for (int i = 0; i < count; i++) {
        int x = va_arg(factor, int);
        int y = va_arg(factor, int);
        char value = va_arg(factor, char);
        set_pixel(x,y,value);
    }
    va_end(factor);
}

void Canvas::clear() {
    for (int i = 0; i < Lines; i++) {
        for (int j = 0; j < Columns; j++) {
            a[i][j] = ' ';
        }
    }
}

void Canvas::print() const {
    for (int i = 0; i < Lines; i++) {
        for (int j = 0; j < Columns; j++) {
            printf("%c",a[i][j]);
        }
        cout << endl;
    }
}