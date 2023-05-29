#ifndef __GRAFICO_H__
#define __GRAFICO_H__

#include <iostream>
#include <iomanip>
#include "avl_tree.h"

void plot(ArvoreAVL* avl);
int limit(float total, int div);
std::string repeat(std::string s, int n);

#endif