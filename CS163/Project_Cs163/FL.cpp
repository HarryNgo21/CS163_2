#include "FL.h"
#include "AVL.h"

FL::FL(int size) : arr(new bNode* [size]), m_size(size), c_size(0)
{
    t_arr = new Node<bNode*>(new bNode(L"errMSG", -1), nullptr);
}

FL::~FL()
{
    delete[] arr;
    t_arr->clear();
}

bNode*& FL::operator[](int i)
{
    if (i >= c_size) return t_arr->data;
    if (i < m_size) return arr[i];
    i -= m_size;
    Node<bNode*>* temp = t_arr;
    while (i--) temp = temp->next;
    return temp->data;
}

void FL::AoR(bNode* b)
{
    b->f = !b->f;
    if (b->f)
    {
        if (m_size > c_size) arr[c_size] = b;
        else t_arr = new Node<bNode*>(b, t_arr);
        ++c_size;
        return;
    }
    for (int i = 0; i < m_size; ++i)
    {
        if (arr[i] == b)
        {
            while (i < m_size - 1)
            {
                ++i;
                arr[i - 1] = arr[i];
            }
            bNode* temp = nullptr;
            if (c_size > m_size)
            {
                Node<bNode*>* t = t_arr;
                t_arr = t_arr->next;
                temp = t->data;
                delete t;
            }
            arr[i] = temp;
            --c_size;
            return;
        }
    }
    Node<bNode*>* t = t_arr;
    if (t_arr->data == b)
    {
        t_arr = t_arr->next;
        delete t;
        return;
    }
    while (t->next->data != b) t = t->next;
    Node<bNode*>* temp = t->next;
    t->next = temp->next;
    delete temp;
}

bool FL::remove(int i)
{
    if (i < m_size)
    {
        arr[i]->f = false;
        while (i < m_size - 1)
        {
            ++i;
            arr[i - 1] = arr[i];
        }
        bNode* temp = nullptr;
        if (c_size > m_size)
        {
            Node<bNode*>* t = t_arr;
            t_arr = t_arr->next;
            temp = t->data;
            delete t;
        }
        arr[i] = temp;
        --c_size;
        return true;
    }
    else
    {
        i -= m_size;
        if (t_arr->data->d == -1) return false;
        Node<bNode*>* temp = t_arr;
        if (i == 0)
        {
            t_arr = t_arr->next;
            temp->data->f = false;
            delete temp;
            --c_size;
            return true;
        }
        while (--i)
        {
            temp = temp->next;
            if (temp->data->d == -1) return false;
        }
        Node<bNode*>* t = temp->next;
        temp->next = t->next;
        t->data->f = false;
        delete t;
        --c_size;
        return true;
    }
}

int FL::size()
{
    return c_size;
}

bool FL::save(string dir)
{
    ofstream fout(dir, ios_base::binary);
    if (!fout.is_open()) return false;
    fout.write((char*)&c_size, sizeof(int));
    return true;
}
