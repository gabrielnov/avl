#ifndef __FILE_H__
#define __FILE_H__

#define COLUMNS 15
#include <fstream>
#include <algorithm>
#include "bst.h"
#include "avl_tree.h"
#include "node.h"
#include "title.h"
#include "avl_tree.h"


void readFile(ArvoreBST *bst, ArvoreAVL *avl);
void substring(std::string s, std::string v[15]);
void saveFile(ArvoreBST *bst);
void escreverLinha(Node* no, std::fstream *f);

#endif
