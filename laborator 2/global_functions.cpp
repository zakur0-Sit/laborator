#include "global_functions.h"
#include "Movie.h"
#include <cstring>

char movie_compare_name(Movie episod_nume1, Movie episod_nume2)
{
	return strcmp(episod_nume1.get_name(), episod_nume2.get_name());
}

float movie_compare_score(Movie episod_scor1, Movie episod_scor2)
{
	if (episod_scor1.get_score() < episod_scor2.get_score())
		return -1;
	else if (episod_scor1.get_score() > episod_scor2.get_score())
		return 1;
	else
		return 0;
}

int movie_compare_year(Movie episod_year1, Movie episod_year2)
{
	if (episod_year1.get_year() < episod_year2.get_year())
		return -1;
	else if (episod_year1.get_year() > episod_year2.get_year())
		return 1;
	else
		return 0;
}

int movie_compare_length(Movie episod_length1, Movie episod_length2)
{
	if (episod_length1.get_length() < episod_length2.get_length())
		return -1;
	else if (episod_length1.get_length() > episod_length2.get_length())
		return 1;
	else
		return 0;
}

int movie_compare_passed_years(Movie episod_year_pass1, Movie episod_year_pass2)
{
	if (2023 - episod_year_pass1.get_year() < 2023 - episod_year_pass2.get_year())
		return -1;
	else if (2023 - episod_year_pass1.get_year() > 2023 - episod_year_pass2.get_year())
		return 1;
	else
		return 0;
}
