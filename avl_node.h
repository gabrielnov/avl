
#ifndef __AVL_NODE_H__
#define __AVL_NODE_H__

#include <stdlib.h>
#include "title.h"

class AVLNode
{
    private:
        AVLNode* left, *right;
        Title *title;
        int height;
     public:
        AVLNode(){
            left = NULL;
            right = NULL;
            height = 0;
        }
        AVLNode(Title *valor){
            left = NULL;
            right = NULL;
            title = valor;
            height = 0;
        };
        ~AVLNode(){};

        Title* getData(){return title;};
        int getHeight(){return height;};
        void setData(Title *valor){title = valor;};
        void setHeight(int h){height = h;};
        AVLNode* getLeft(){return left;};
        AVLNode* getRight(){return right;};
        void setRight(AVLNode *n){right = n;};
        void setLeft(AVLNode *n){left = n;};
        int getBalance(AVLNode *N);

};

#endif
