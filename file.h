#ifndef __FILE_H__
#define __FILE_H__

#define COLUMNS 15
#include <fstream>
#include "bst_tree.h"
#include "title.h"
#include "avl_tree.h"

void readFile(ArvoreBST *bst, ArvoreAVL *avl);
void substring(std::string s, std::string v[15]);
void saveFile(ArvoreAVL *avl);
void escreverLinha(BSTNode* no, std::fstream *f);

#endif
