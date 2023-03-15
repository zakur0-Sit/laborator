#pragma once
class Movie
{
private:

	float score;
	int length;
	int year;
	char name[256];

public:

	void set_score(float score);
	void set_length(int length);
	void set_year(int year);
	void set_name(const char* name);

	float get_score();
	int get_length();
	int get_year();
	const char* get_name();
	int movie_compare_passed_years();

};

