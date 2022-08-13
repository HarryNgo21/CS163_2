#include <iomanip>
#include <algorithm>
#include <io.h>
#include <fcntl.h>
#include "search.h"
#include "Const.h"

using namespace std;


vector<wstring> search_for_def(bNode* root, string dir)
{
    vector<wstring> str;
    int num = 0, size_def = 0;
    wchar_t* tmp;
    wstring tmps;
    ifstream fin(dir, ios::binary);
    fin.seekg(root->d);
    fin.read((char*)&num, sizeof(int));
    num += 1;
    for (int i = 0; i < num; i++)
    {
        fin.read((char*)&size_def, sizeof(int));
        tmp = new wchar_t[size_def];
        fin.read((char*)tmp, size_def * sizeof(wchar_t));
        tmps = tmp;
        str.push_back(tmps);
        delete[] tmp;
    }
    return str;
}

vector<vector<wstring>> random_word(AVL& tree, string dir, int n)
{
    vector <vector<wstring>> strs;
    vector<bNode*> arr;
    vector <int> lists;
    bNode* root = tree.get_root();
    srand(time(NULL));
    for (int i = 0; i < 4; i++)
    {
        int tmp = rand() % (n + 1);
        lists.push_back(tmp);
    }
    sort(lists.begin(), lists.end());
    vector<bNode*> nodes = random_take(root, lists);
    for (int j = 0; j < 4; j++)
    {
        vector <wstring> stmps;
        stmps.push_back(nodes[j]->key);
        vector<wstring> def_str = search_for_def(tree.search(nodes[j]->key), dir);
        stmps.push_back(def_str[rand() % (def_str.size() - 1)]);
        strs.push_back(stmps);
    }
    return strs;
}

vector<bNode*> random_take(bNode* root, vector<int> lists) //sorted list
{
    int num = 0;
    vector<bNode*> nodes;
    queue<bNode*> qu;
    qu.push(root);
    for (int i = 0; i < 4; i++)
    {
        while (num != lists[i])
        {
            num += 1;
            Node<bNode*>* tmp1 = qu.dequeue();
            bNode* tmp = tmp1->data;
            if (tmp->left != nullptr)
                qu.push(tmp->left);
            if (tmp->right != nullptr)
                qu.push(tmp->right);
            //delete tmp1;
        }
        nodes.push_back(qu.rear());
    }
    return nodes;
}

bool random_game(vector<vector<wstring>> lists)
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    if (lists.empty())
        return false;
    int random, t = 0, tmp, choice, cmp;
    srand(time(NULL));
    vector <bool> is_take;
    is_take.resize(4);
    fill(is_take.begin(), is_take.end(), false);
    random = rand() % 4;
    wcout << L"Can you guess the meaning of " << L"\"" << lists[random][0] << L"\"" << L" ?" << endl;
    while (t < 4)
    {
        do
        {
            tmp = rand() % 4;
        } while (is_take[tmp] == true);
        is_take[tmp] = true;
        if (tmp == random)
            cmp = t;
        wcout << setw(tap) << t + 1 << L". " << lists[tmp][1] << endl;
        t += 1;
    }
    do
    {
        wcout << L"your choice: ";
        wcin >> choice;
    } while (choice <= 0 || choice > 4);
    if (choice == cmp + 1)
    {
        wcout << L"you win" << endl;
        return true;
    }
    else
    {
        wcout << L"you've lost" << endl;
        wcout << L"correct answer: " << lists[random][1] << endl;
        return false;
    }
}

void random_keywords(vector<vector<wstring>> lists)
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    for (int i = 0; i < 4; i++)
    {
        wcout << lists[i][0] << ". " << lists[i][1] << endl;
    }
}

bool random_def_game(vector<vector<wstring>> lists)
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    _setmode(_fileno(stdin), _O_U16TEXT);
    srand(time(NULL));
    vector<bool> is_visited;
    is_visited.resize(4);
    fill(is_visited.begin(), is_visited.end(), false);
    int random = rand() % 4, tmp, ctmp, choice;
    wcout << L"Can you guess the meaning of " << L"\"" << lists[random][1] << L"\"" << L" ?" << endl;
    for (int i = 0; i < 4; i++)
    {
        do
        {
            ctmp = rand() % 4;
        } while (is_visited[ctmp] == true);
        is_visited[ctmp] = true;
        if (ctmp == random)
        {
            tmp = i + 1;
        }
        wcout << setw(10) << i + 1 << L". " << lists[i][0] << endl;
    }
    do
    {
        wcout << L"your choice: ";
        wcin >> choice;
    } while (choice <= 0 || choice > 4);
    if (choice == tmp)
    {
        wcout << L"you win" << endl;
        return true;
    }
    else
    {
        wcout << L"you've lost" << endl;
        wcout << L"correct answer: " << lists[random][0] << endl;
        return false;
    }
}

wstring modify_input(wstring& str)
{
    locale::global(locale(""));
    wcout.imbue(locale());
    bool is_leading = false, fspace = true;
    auto& env = std::use_facet< std::ctype<wchar_t> >(locale());
    wstring ans;
    env.tolower(&str[0], &str[0] + str.size());
    for (int i = 0; i < str.length(); i++)
    {
        if (is_leading == false)
        {
            if (str[i] == ' ')
            {
                str.erase(i, 1);
                i--;
            }
            else
            {
                is_leading = true;
            }
        }
        else
        {
            if (str[i] == ' ' && str[i + 1] == ' ')
            {
                str.erase(i, 1);
                i--;
            }
        }
    }
    ans = str;
    return ans;
}
