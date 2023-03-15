#pragma once
#include "Movie.h"

class MovieSeries {
private:
    Movie* movies[16];
    int count;
    int MAX_MOVIES = 16;

public:
    

    void init();

    void add(Movie* movie);

    void sort();

    void print();

};

