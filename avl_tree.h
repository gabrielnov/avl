#ifndef __AVL_TREE_H__
#define __AVL_TREE_H__

#include "avl_node.h"
#include <clocale>
#include <iostream>
#include <queue>
#include <stdlib.h>

class ArvoreAVL {
public:
  ArvoreAVL();
  virtual ~ArvoreAVL();
  AVLNode *getRoot();
  bool isEmpty();
  int height();
  int qtNodes();
  void inserir(Title *t, int *op);
  void remove(std::string id, int *op);
  void preOrder();
  void posOrder();
  void inOrder();
  void reverseOrder();
  int getBalance(AVLNode *N);
  bool isAVL();
  void print();
  void findMediaAnaliseFilme(std::string procurar, float *procuraValor, AVLNode* no, int choice, float *nPessoas);
  void findMaxAnaliseFilme(std::string procurar, float *maximo, AVLNode* no, int choice, std::string *nomeFilmeProcurado);
  void findMinAnaliseFilme(std::string procurar, float *minimo, AVLNode* no, int choice, std::string *nomeFilmeProcurado);
  void analise3(std::string id1, std::string id2, AVLNode *no);
  void analise4(std::string id, AVLNode *no);
  void analise5(std::string pais, AVLNode *no);
  void analise6(std::string year1, std::string year2, AVLNode *no);
  void analise7(AVLNode* no, int notas[], int *total);
  AVLNode* pesquisar(std::string valor, AVLNode *no, int *op);
  void posOrder(AVLNode *no);
private:
  AVLNode *root;
  int height(AVLNode *);
  int qtNodes(AVLNode *);
  AVLNode *inserir(AVLNode *, Title *, int *);
  AVLNode *remove(AVLNode *, std::string, int *);
  void preOrder(AVLNode *no);
  void inOrder(AVLNode *no);
  AVLNode *rotateR(AVLNode *);
  AVLNode *rotateL(AVLNode *);
  AVLNode *rotateLR(AVLNode *);
  AVLNode *rotateRL(AVLNode *);
  AVLNode *leftRotate(AVLNode *x);
  AVLNode *rightRotate(AVLNode *y);
  void reverseOrder(AVLNode *);
  int maximo(int, int);
  AVLNode *minimo(AVLNode *no, int *op);
  bool isAVL(AVLNode *no);
  void print(AVLNode *no, int space);
};

#endif
