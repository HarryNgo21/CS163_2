#pragma once

#include<iostream>
#include<fstream>
#include<iomanip>
#include<io.h>
#include<fcntl.h>
#include<string>
#include<codecvt>

#include "LL.h"
using namespace std;

class search_history {
private:
	Node<wstring>* hist_head;
public:
	search_history();
	string Dist(string def_dir);
	Node<wstring>* Load(string history_dist);
	Node<wstring>* Add(wstring word, string history_dist);
	Node<wstring>* Delete(string history_dir);
	int count();
	Node<wstring>* Find(int);
	void View();
};

bool check_empty_file(string dir);