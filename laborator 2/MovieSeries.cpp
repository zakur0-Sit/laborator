#include "MovieSeries.h"
#include <iostream>
#include <stdio.h>
#include "global_functions.h"

using namespace std;

void MovieSeries::init() {
     count = 0;
}

void MovieSeries::add(Movie* movie) {
    if (count < MAX_MOVIES) {
        movies[count++] = movie;
    }
}

void MovieSeries::print() {
    for (int i = 0; i < count; i++) {
        cout << endl;
        cout << "Name: " << movies[i]->get_name() << endl;
        cout << "Release year: " << movies[i]->get_year() << endl;
        cout << "IMDB score: " << movies[i]->get_score() << endl;
        cout << "Length: " << movies[i]->get_length() << " minutes" << endl;
        cout << "Passed years: " << movies[i]->get_year() <<endl;
    }
}

void MovieSeries::sort() {
    for(int i=0;i<count;i++)
        for (int j = i+1;j < count;j++)
        {
            if (movies[i]->get_year() <  movies[j]->get_year())
            {
                swap(movies[i], movies[j]);
            }
        }
}
