#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

struct MyPair
{
	string first;
	int second;

	MyPair(const string& f, int s):first(f),second(s){}
	bool operator<(const MyPair & others)const
	{
		if (second == others.second)
			return first > others.first;
		return second < others.second;
	}
};

ifstream f("string.txt");

int main()
{
	 
	map<string, int> myMap;
	map<string, int> secondMap;
	string str;
	getline(f, str);
	string token;
	auto start = 0;
	string delimitator = " ,.!?";
	
	while ((start = str.find_first_not_of(delimitator)) != string::npos)
	{
		str = str.substr(start);
		start = str.find_first_of(delimitator);
		token = str.substr(0, start);
		transform(token.begin(), token.end(), token.begin(), ::tolower);
		auto it = myMap.find(token);

		if (it != myMap.end())
			it->second++;
		else
			myMap.emplace(token, 1);
		str.erase(0, start);
	}

	f.close();
	priority_queue<MyPair> q;

	for (auto i : myMap)
		q.emplace(i.first, i.second);
		
	while (!q.empty())
	{
		cout<<q.top().first<<" => "<<q.top().second<<endl;
		q.pop();
	}
	
	return 0;
}