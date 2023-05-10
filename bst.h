#ifndef __BST_H__
#define __BST_H__

#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include "title.h"
#include "node.h"

class ArvoreBST
{
private:
    Node *raiz;

public:
    ArvoreBST()
    {
        raiz = NULL;
    }
    
    void setRaiz(Node* root){raiz = root;}
    Node* getRaiz() {return raiz;}

    void inserir(std::string chave, Title *p);
    void inserirAux(Node *no, std::string chave, Title *p); 
    void emOrdem(Node* no);
    void preOrdem(Node* no);
    void posOrdem(Node* no);
    Node *Pesquisar (Node* r, std::string k);
    int contarNos(Node* atual);
    int altura(Node* atual);
    Node *excluir(Node* t, std::string key);
    int folhas(Node *atual);
    Node* findMin(Node* t);
    Node* findMax(Node* t);
    void infs(Node* r);
    void print();
  	void print(Node *no, int space);
    void LimparArvore (Node* no);
    void auxLimpar();
};



#endif
