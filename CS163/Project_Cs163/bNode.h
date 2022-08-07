#pragma once

#include<fstream>
#include<string>

using namespace std;

struct bNode
{
    wstring key;
    int h, d;
    bool f;
    bNode* left, * right;

    bNode();
    bNode(wstring, int);

    bool add(bNode*&);

    int height();
    void updateH();

    void Add(wstring word, wstring dir);
    void save(ofstream&);
    void load(ifstream&);
};

void clear(bNode*&);