#pragma once

#include <cstdlib>
#include <ctime>
#include <random>
#include <stdlib.h>
#include <time.h>
#include "AVL.h"

int FindRandom(AVL& tree, bNode*& root);

void ViewRandom(bNode*& root, int number, int& count, AVL& tree, string dir, bNode*& random);
