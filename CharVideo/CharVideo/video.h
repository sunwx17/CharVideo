#pragma once
#ifndef _VIDEO_H_
#define _VIDEO_H_
#include <iostream>
#include <opencv2\core\core.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <fstream>
#include <Windows.h>
#include <time.h>
#include <vector>
#include <string>

using namespace std;
using namespace cv;

struct Cs {
	string name;
	int beg;
	int end;
	int frame;
	int WriteIn(vector<string>);
};



class Video {
public:
	void play();
	Video(string);
private:
	void img2str();
	Cs cs;
};


#endif // ! _VIDEO.H
