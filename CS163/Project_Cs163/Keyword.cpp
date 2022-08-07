#include<algorithm>

#include"Keyword.h"
#include"Const.h"

keyword::keyword() : key(), word(nullptr){}

keyword::keyword(const wstring& k,const wstring& l) : key(k)
{
    word = new Node<wstring>(l, nullptr);
}

keyword::~keyword()
{
    if(word) word->clear();
}

int c_hash::hf(const wstring& key)
{
    int val = 0;
    for(wchar_t c : key) val = (val*7 + c)%hash_len;
    return val;
}

c_hash::c_hash() : arr{}{}

Node<keyword>*& c_hash::get(const wstring& key)
{
    Node<keyword>*& temp = arr[hf(key)];
    while(temp && temp->data.key < key) temp = temp->next;
    return temp; 
}

void c_hash::add(const wstring& key, const wstring& word)
{
    Node<keyword>*& temp = get(key);
    if(!temp || temp->data.key != key) 
    {
        Node<keyword>* t = temp;
        temp = new Node<keyword>;
        temp->data.key = key;
        temp->data.word = new Node<wstring>(word, nullptr);
        temp->next = t;
    }
    else
    {
        Node<wstring>** t = &temp->data.word;
        while(*t && (*t)->data < word) t = &(*t)->next;
        if(!*t || (*t)->data != word) *t = new Node<wstring>(word, *t);
    }
}

void c_hash::save(ofstream& fout)
{
    for(int i = 0; i < hash_len; ++i)
    {
        int l;
        Node<keyword>* temp = arr[i];
        while(temp)
        {
            l = arr[i]->data.key.length() + 1;
            fout.write((char*)&l, sizeof(int));
            fout.write((char*)arr[i]->data.key.c_str(), l*sizeof(wchar_t));
            Node<wstring>* t = arr[i]->data.word;
            while(t)
            {
                l = t->data.length() + 1;
                fout.write((char*)&l, sizeof(int));
                fout.write((char*)t->data.c_str(), l*sizeof(wchar_t));
                t = t->next;
            }
            l = 0;
            fout.write((char*)&l, sizeof(int));
            temp = temp->next;
        }
        l = 0;
        fout.write((char*)&l, sizeof(int));
    }
}

void c_hash::load(ifstream& fin)
{
    for(int i = 0; i < hash_len; ++i)
    {
        int l;
        fin.read((char*)&l, sizeof(int));
        while (l > 0)
        {
            arr[i] = new Node<keyword>;
            wchar_t* temp = new wchar_t[l];
            fin.read((char*)temp, l*sizeof(wchar_t));
            arr[i]->data.key = temp;
            delete[] temp;
            fin.read((char*)&l, sizeof(int));
            Node<wstring>** t = &arr[i]->data.word;
            while(l > 0)
            {
                temp = new wchar_t[l];
                fin.read((char*)temp, l*sizeof(wchar_t));
                *t = new Node<wstring>;
                (*t)->data = temp;
                t = &(*t)->next;
                delete[] temp;
                fin.read((char*)&l, sizeof(int));
            }
            fin.read((char*)&l, sizeof(int));
        }
    }
}

wstring getWord(const wstring &def, int &i, const int &n)
{
    wstring temp;
    while(i < n && def[i] != L' ') temp += def[i++];
    ++i;
    return temp;
}

vector<wstring> getKeyWord(const wstring &def)
{
    int l = def.length(), i = 0;
    vector<wstring> sol;
    while(i < l)
    {
        wstring temp = getWord(def, i, l);
        int len = temp.length();
        while(len > 2 && (temp[len - 1] < 48 || (temp[len - 1] > 57 && temp[len - 1] < 65) || (temp[len - 1] > 122 && temp[len - 1] < 192)))
        {
            len--;
            temp.pop_back();
        }
        while(len > 2 && (temp[0] < 48 || (temp[0] > 57 && temp[0] < 65) || (temp[0] > 122 && temp[0] < 192)))
        {
            len--;
            temp.erase(temp.begin());
        }
        if(len > 2) 
        {
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            if(temp != L"the" && temp != L"and") sol.push_back(temp);
        }
    }
    return sol;
}