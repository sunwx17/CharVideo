#pragma once
#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <string>
#include <vector>

using namespace std;

struct Config {
	struct A_Config {
		string name;
		int value;
	};
	vector<A_Config> configs = { { "reform", 1 },{ "recycle", 1 },{ "charsizeX", 3 } ,{ "charsizeY", 5 } ,{ "pxX", 1 } ,{ "pxY", 2 } ,{ "gradation", 8 } ,{"formfirst", 1} };
	int WriteIn(vector<string>);
};

int init();
int GetNumFromString(string);
vector<string> GetLineFromFile(string);
vector<string> SplitByChar(string, char);
vector<string> RemoveNote(vector<string>);


#endif // !_CONFIG_H_
