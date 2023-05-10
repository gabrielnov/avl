#include "bst.h"
#include <iostream>

void ArvoreBST::inserir(std::string chave, Title *p){
        if(raiz == NULL) 
            raiz = new Node(chave, p); 
        else
            inserirAux(raiz, chave, p);
}

 void ArvoreBST::inserirAux(Node *no, std::string chave, Title *p)
    {
        // se for menor, ent�o insere na sub-�rvore � esquerda
        if(chave < no->getChave())
        {
            // verifica se n�o tem filho a esquerda: achou local de inser��o 
            if(no->getEsq() == NULL)
            {
                Node *novo_no = new Node(chave, p);
                no->setEsq(novo_no); // add o novo_no � esquerda do n� atual
            }
            else
            {
                // sen�o, continua percorrendo recursivamente para esquerda
                inserirAux(no->getEsq(), chave, p);
            }
        }
        // se for maior, ent�o insere na sub-�rvore � direita
        else if(chave > no->getChave())
        {
            // verifica se n�o tem filho a direita: achou local de inser��o
            if(no->getDir() == NULL)
            {
                Node *novo_no = new Node(chave, p);
                no->setDir(novo_no); // add o novo_no � direita do n� atual
            }
            else
            {
                // sen�o, continua percorrendo recursivamente para direita
                inserirAux(no->getDir(), chave, p);
            }
        }
        // se a chave for igual a alguma presente na �rvore, n�o vamos inserir
        // n�o pode existir 2 chaves iguais na nossa BST
    }

void ArvoreBST::emOrdem(Node* no)
{
    if(no != NULL)
    {
        emOrdem(no->getEsq());
        std::cout << no->getChave() << std::endl;
        emOrdem(no->getDir());
    }
}

void ArvoreBST::preOrdem(Node* no)
    {
    if(no != NULL)
    {
        std::cout << no->getChave() << " ";
        preOrdem(no->getEsq());
        preOrdem(no->getDir());
    }
}

void ArvoreBST::posOrdem(Node* no)
{
    if(no != NULL)
    {
        posOrdem(no->getEsq());
        posOrdem(no->getDir());
        std::cout << no->getChave() << " ";
    }
}

Node* ArvoreBST::Pesquisar (Node* r, std::string k)
{
    if (r == NULL || r->getChave() == k)
        return r;
    if (r->getChave() > k)
        return Pesquisar(r->getEsq(), k);
    else
        return Pesquisar(r->getDir(), k);
}

void ArvoreBST::LimparArvore (Node* no)
{
    if(no != NULL){
    	LimparArvore(no->getEsq());
    	LimparArvore(no->getDir());
    	delete no;
    	no = NULL;
	}
}

void ArvoreBST::auxLimpar(){
	LimparArvore(raiz);
	raiz = NULL;
}

int ArvoreBST::contarNos(Node* atual)
{
    if(atual == NULL)  return 0;
    else return ( 1 + contarNos(atual->getEsq()) + contarNos(atual->getDir()));
}

 int ArvoreBST::altura(Node* atual)
{
    if(atual == NULL)
        return -1; //�rvore ou sub-�rvore vazia: altura = -1
    else
    {
        if(atual->getEsq() == NULL && atual->getDir() == NULL)
            return 0; //�vore com apenas 1 n�, altura = 0
        else
        {//altura da �rvore � a altura da sub-�rvore de maior altura
            if (altura(atual->getEsq()) > altura(atual->getDir()))
                return ( 1 + altura(atual->getEsq()) );
            else
                return ( 1 + altura(atual->getDir()) );
        }
    }
}

Node* ArvoreBST::excluir(Node* t, std::string key){
        
        //Arvore t � vazia
        if (t == NULL) 
            return t;
        
        if (key < t->getChave())
            t->setEsq(excluir(t->getEsq(),key));
        else
            if (key > t->getChave())
                t->setDir(excluir(t->getDir(),key));
        
        //encontramos o n� a ser removido
        else{ 
            //Caso1: o no a ser excluido nao tem filhos
            if (t->getEsq() == NULL and t->getDir() == NULL){
            	delete(t);
                return NULL; //faz o pai apontar para NULL e o n� n�o faz mais parte da BST	
			}            	
            else 
                //Caso2: tem apenas um filho, a esquerda ou a direita
                if (t->getEsq() == NULL){
                    Node* temp = t->getDir();
                    delete(t);
                    return temp; //Faz o pai apontar para o �nico filho do n�
                }
                else 
                    if  (t->getDir() == NULL){
                        Node* temp = t->getEsq();
                        delete(t);
                        return temp; //Faz o pai apontar para o �nico filho do n�
                    }
            
            //Caso3: o no a ser excluido tem 2 filhos. Vamos escolher o menor dos maiores
            //para substituir o no que sera removido. Sucessor = menor no na sub-arvore da direita
            
            Node* temp = findMin(t->getDir()); 
            
            //Copia a chave do sucessor para o no que esta sendo removido
            t->setChave(temp->getChave());
            
            //Remove da arvore o sucessor!
            t->setDir(excluir(t->getDir(),temp->getChave()));
        }
        
        //retorna a raiz da arvore
        return t;
        
}

  int ArvoreBST::folhas(Node *atual)
    {
        if(atual == NULL) return 0;
        if(atual->getEsq() == NULL && atual->getDir() == NULL) return 1;
        return folhas(atual->getEsq()) + folhas(atual->getDir());
    }

 Node* ArvoreBST::findMin(Node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->getEsq() == NULL)
            return t;
        else
            return findMin(t->getEsq());
    }

	//recursivo
    Node* ArvoreBST::findMax(Node* t) {
        if(t == NULL)
            return NULL;
        else if(t->getDir() == NULL)
            return t;
        else
            return findMax(t->getDir());
    }

  
    void ArvoreBST::infs(Node* r)
    {
        Node* aux;
        std::cout << "\nInformacoes gerais da arvore: \n";
        std::cout << "\n Altura da arvore: " << altura(raiz);
        std::cout << "\n Quantidade de folhas: " << folhas(raiz);
        std::cout << "\n Quantidade de Nos: " << contarNos(raiz);
        if (raiz != NULL )    // se arvore nao esta vazia
        {           
            aux = findMin(r);
            std::cout << "\n Valor minimo: " << aux->getChave();            
            aux = findMax(r);
            std::cout << "\n Valor maximo: " << aux->getChave();
        }
    }

    void ArvoreBST::print()
	{
  		emOrdem(raiz);
	}

	void ArvoreBST::print(Node *no, int space)
	{
  		if (no != NULL)
  		{	
    		print(no->getDir(), space + 5);
    		for (int k = 0; k < space; ++k) 
				std::cout << " ";
    		std::cout << no->getChave() << "\n";
//    		std::cout << no->getTitulo()->getSalarioBruto() << "\n";
    		print(no->getEsq(), space + 5);
  		}
	}
	
