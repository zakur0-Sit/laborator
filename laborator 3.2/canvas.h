#pragma once
#include <stdarg.h>
#define _CRT_SECURE_NO_WARNINGS
class Canvas {
private:
    int Lines;
    int Columns;
    char a[100][100];
  public:
      
    // contructor will call the clear method
    Canvas(int lines, int columns) ;

    //set the character at the position x and y to value
    void set_pixel(int x, int y, char value);
    
    // tuples of x, y, value
    void set_pixels(int count, ...);

    void clear();
    void print() const;
};