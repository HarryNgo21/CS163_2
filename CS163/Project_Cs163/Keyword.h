#pragma once

#include<string>
#include<vector>

#include"LL.h"
#include"bNode.h"

using namespace std;

struct keyword
{
    wstring key;
    Node<wstring>* word;

    keyword();
    keyword(const wstring&,const wstring&);
    ~keyword();
};

struct c_hash
{
    private:
    Node<keyword>* arr[hash_len];
    int hf(const wstring&);

    public:
    c_hash();
    
    Node<keyword>*& get(const wstring&);
    void add(const wstring&, const wstring&);
    void save(ofstream&);
    void load(ifstream&);
};


vector<wstring> getKeyWord(const wstring&);