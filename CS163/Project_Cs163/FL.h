#pragma once

#include "LL.h"
#include "bNode.h"

class FL
{
private:
    bNode** arr;
    int m_size, c_size;
    Node<bNode*>* t_arr;
public:
    FL(int);
    FL(const FL&);
    ~FL();

    bNode*& operator[](int);
    FL& operator=(const FL&);

    void AoR(bNode*);
    bool remove(int);

    int size();
    void save(ofstream&);
};