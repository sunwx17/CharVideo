#pragma once
#ifndef _VIDEO_H_
#define _VIDEO_H_
#include <iostream>
#include <opencv2\core\core.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <fstream>
#include <io.h>
#include <Windows.h>
#include <time.h>
#include <vector>
#include <string>

using namespace std;
using namespace cv;
/*
struct Cs {
	string name;
	int beg;
	int end;
	int frame;
	int WriteIn(vector<string>);
};
*/

/*
class Video {
public:
	void play();
	Video(string);
private:
	void img2str();
	Cs cs;
};
*/
void setConfig();
void play(string);
void img2str(const Mat&);

#endif // ! _VIDEO.H
