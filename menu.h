#ifndef __MENU_H__
#define __MENU_H__

#include "bst_tree.h"
#include "avl_tree.h"
#include "file.h"

void menu(ArvoreAVL* avl, ArvoreBST* bst);
void printMenu();
bool readOption(int opt, ArvoreAVL* avl, ArvoreBST* bst, bool* fileRead);

#endif
