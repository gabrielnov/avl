#ifndef __MENU_H__
#define __MENU_H__

#include "file.h"
#include "grafico.h"

void menu(ArvoreAVL* avl, ArvoreBST* bst);
void printMenu();
bool readOption(int opt, ArvoreAVL* avl, ArvoreBST* bst, bool* fileRead);

#endif
