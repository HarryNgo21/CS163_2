#pragma once

#include<string>
#include<fstream>
#include<vector>

#include "LL.h"
#include "FL.h"
#include "bNode.h"
#include "Keyword.h"

using namespace std;

class AVL
{
private:
    bNode* root;

    bool subadd(bNode*&, wstring, int);
    bNode* sub(bNode*&, bool);
    bNode* subremove(bNode*&, wstring);
    void lrotate(bNode*&);
    void rrotate(bNode*&);
public:
    AVL();
    ~AVL();

    int  maketree(string, string, string, string, c_hash&);
    bool insert(wstring, int);
    bool remove(wstring);//unnessessary

    bNode* search(wstring);

    int load(ifstream&, FL&);
    bool save(ofstream&);
    int Add(AVL&, wstring, string,int, c_hash&);
    bNode* get_root()
    {
        return root;
    }
    int height(bNode*);
    void num_of_words(bNode*, int&);
    void DeleteRoot();
};
