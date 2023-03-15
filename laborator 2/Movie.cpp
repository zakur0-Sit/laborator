#define _CRT_SECURE_NO_WARNINGS
#include "Movie.h"
#include <cstring>

void Movie::set_score(float score)
{
	this->score = score;
}

void Movie::set_length(int length)
{
	this->length = length;
}

void Movie::set_year(int year)
{
	this->year = year;
}

void Movie::set_name(const char* name)
{
	strcpy(this->name, name);
}

float Movie::get_score()
{
	return score;
}

int Movie::get_length()
{
	return length;
}

int Movie::get_year()
{
	return year;
}

const char* Movie::get_name()
{
	return name;
}