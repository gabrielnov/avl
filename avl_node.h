
#ifndef __AVL_NODE_H__
#define __AVL_NODE_H__

#include <stdlib.h>
#include "title.h"

class AVLNode
{
    public:
        AVLNode();
        AVLNode(Title*);
        virtual ~AVLNode();
        Title* getData();
        int getHeight();
        void setData(Title*);
        void setHeight(int);
        AVLNode* getLeft();
        AVLNode* getRight();
        void setRight(AVLNode*);
        void setLeft(AVLNode*);
        int getBalance(AVLNode *N);

    private:
        AVLNode* left, *right;
        Title *title;
        int height;
};

AVLNode::AVLNode()
{
    left = NULL;
    right = NULL;
    height = 0;
}

AVLNode::AVLNode(Title *valor)
{
    left = NULL;
    right = NULL;
    title = valor;
    height = 0;
}

AVLNode::~AVLNode()
{
}

void AVLNode::setData(Title *valor)
{
    title = valor;
}

Title* AVLNode::getData()
{
    return title;
}

void AVLNode::setLeft(AVLNode *n)
{
    left = n;
}

AVLNode* AVLNode::getLeft()
{
    return left;
}

void AVLNode::setRight(AVLNode *n)
{
    right = n;
}

AVLNode* AVLNode::getRight()
{
    return right;
}

void AVLNode::setHeight(int h)
{
    height = h;
}

int AVLNode::getHeight()
{
    return height;
}

#endif
