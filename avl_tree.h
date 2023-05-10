#ifndef __AVL_TREE__
#define __AVL_TREE__

#include <iostream>
#include <stdlib.h>
#include <clocale>
#include <queue>
#include "avl_node.h"

class ArvoreAVL
{
    public:
        ArvoreAVL();
        virtual ~ArvoreAVL();
        AVLNode* getRoot();
        bool isEmpty();
        int height();
        int qtNodes();
        void inserir (int valor);
        void remove(int valor);
        void preOrder();
        void posOrder();
        void inOrder();      
        void reverseOrder();
        int getBalance(AVLNode *N);
        bool isAVL();
        void print();

    private:
        AVLNode *root;
        int height(AVLNode*);
        int qtNodes(AVLNode*);
        AVLNode* inserir(AVLNode*, int);
        AVLNode* remove(AVLNode*, int);
        void preOrder(AVLNode *no);
        void posOrder(AVLNode *no);
        void inOrder(AVLNode *no);      
        AVLNode* rotateR(AVLNode*);
        AVLNode* rotateL(AVLNode*);
        AVLNode* rotateLR(AVLNode*);
        AVLNode* rotateRL(AVLNode*);
        AVLNode* leftRotate(AVLNode *x);
        AVLNode* rightRotate(AVLNode *y);
        void reverseOrder(AVLNode*);
        int maximo(int, int);
        AVLNode* minimo(AVLNode* no);
        bool isAVL(AVLNode* no);
        void print(AVLNode* no, int space);
};

#endif 
