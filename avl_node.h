
#ifndef __AVL_NODE_H__
#define __AVL_NODE_H__

#include <stdlib.h>

class AVLNode
{
    public:
        AVLNode();
        AVLNode(int);
        virtual ~AVLNode();
        int getData();
        int getHeight();
        void setData(int);
        void setHeight(int);
        AVLNode* getLeft();
        AVLNode* getRight();
        void setRight(AVLNode*);
        void setLeft(AVLNode*);
        int getBalance(AVLNode *N);

    private:
        AVLNode* left, *right;
        int data;
        int height;
};



AVLNode::AVLNode()
{
    left = NULL;
    right = NULL;
    height = 0;
}

AVLNode::AVLNode(int valor)
{
    left = NULL;
    right = NULL;
    data = valor;
    height = 0;
}

AVLNode::~AVLNode()
{
}

void AVLNode::setData(int d)
{
    data = d;
}

int AVLNode::getData()
{
    return data;
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
