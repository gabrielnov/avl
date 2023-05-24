#ifndef __BST_H__
#define __BST_H__

#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include "title.h"
#include "bst_node.h"

class ArvoreBST
{
private:
    BSTNode *raiz;

public:
    ArvoreBST()
    {
        raiz = NULL;
    }
    
    void setRaiz(BSTNode* root){raiz = root;}
    BSTNode* getRaiz() {return raiz;}

    void inserir(std::string chave, Title *p);
    void inserirAux(BSTNode *no, std::string chave, Title *p); 
    void emOrdem(BSTNode* no);
    void preOrdem(BSTNode* no);
    void posOrdem(BSTNode* no);
    BSTNode *Pesquisar (BSTNode* r, std::string k);
    int contarNos(BSTNode* atual);
    int altura(BSTNode* atual);
    BSTNode *excluir(BSTNode* t, std::string key);
    int folhas(BSTNode *atual);
    void mediaAnaliseFilme(std::string procurar, float *soma, int *filme,AVLNode *no, int choice);
    void findMaxAnaliseFilme(std::string procurar, float *maximo, AVLNode *no,int choice, AVLNode *noMaximo);
    void findMinAnaliseFilme(std::string procurar, float *minimo, AVLNode *no,int choice, AVLNode *noMinimo);
    void analise1(std::string age, std::string popularity);
    void analise2(std::string year, std::string Score);
    void analise3(std::string country, std::string popularity);
    void analise4(std::string year, std::string Votes);
    BSTNode* findMin(BSTNode* t);
    BSTNode* findMax(BSTNode* t);
    void infs(BSTNode* r);
    void print();
  	void print(BSTNode *no, int space);
    void LimparArvore (BSTNode* no);
    void auxLimpar();
};



#endif
