#include "bst_tree.h"
#include <iostream>

void ArvoreBST::inserir(std::string chave, Title *t){
        if(raiz == NULL) 
            raiz = new BSTNode(chave, t); 
        else
            inserirAux(raiz, chave, t);
}

 void ArvoreBST::inserirAux(BSTNode *no, std::string chave, Title *p)
    {
        // se for menor, ent�o insere na sub-�rvore � esquerda
        if(chave < no->getChave())
        {
            // verifica se n�o tem filho a esquerda: achou local de inser��o 
            if(no->getEsq() == NULL)
            {
                BSTNode *novo_no = new BSTNode(chave, p);
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
                BSTNode *novo_no = new BSTNode(chave, p);
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

void ArvoreBST::emOrdem(BSTNode* no)
{
    if(no != NULL)
    {
        emOrdem(no->getEsq());
        std::cout << no->getChave() << std::endl;
        emOrdem(no->getDir());
    }
}

void ArvoreBST::preOrdem(BSTNode* no)
    {
    if(no != NULL)
    {
        std::cout << no->getChave() << " ";
        preOrdem(no->getEsq());
        preOrdem(no->getDir());
    }
}

void ArvoreBST::posOrdem(BSTNode* no)
{
    if(no != NULL)
    {
        posOrdem(no->getEsq());
        posOrdem(no->getDir());
        std::cout << no->getChave() << " ";
    }
}

BSTNode* ArvoreBST::Pesquisar (BSTNode* r, std::string k)
{
    if (r == NULL || r->getChave() == k)
        return r;
    if (r->getChave() > k)
        return Pesquisar(r->getEsq(), k);
    else
        return Pesquisar(r->getDir(), k);
}

void ArvoreBST::LimparArvore (BSTNode* no)
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

int ArvoreBST::contarNos(BSTNode* atual)
{
    if(atual == NULL)  return 0;
    else return ( 1 + contarNos(atual->getEsq()) + contarNos(atual->getDir()));
}

 int ArvoreBST::altura(BSTNode* atual)
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

BSTNode* ArvoreBST::excluir(BSTNode* t, std::string key){
        
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
                    BSTNode* temp = t->getDir();
                    delete(t);
                    return temp; //Faz o pai apontar para o �nico filho do n�
                }
                else 
                    if  (t->getDir() == NULL){
                        BSTNode* temp = t->getEsq();
                        delete(t);
                        return temp; //Faz o pai apontar para o �nico filho do n�
                    }
            
            //Caso3: o no a ser excluido tem 2 filhos. Vamos escolher o menor dos maiores
            //para substituir o no que sera removido. Sucessor = menor no na sub-arvore da direita
            
            BSTNode* temp = findMin(t->getDir()); 
            
            //Copia a chave do sucessor para o no que esta sendo removido
            t->setChave(temp->getChave());
            
            //Remove da arvore o sucessor!
            t->setDir(excluir(t->getDir(),temp->getChave()));
        }
        
        //retorna a raiz da arvore
        return t;
        
}

  int ArvoreBST::folhas(BSTNode *atual)
    {
        if(atual == NULL) return 0;
        if(atual->getEsq() == NULL && atual->getDir() == NULL) return 1;
        return folhas(atual->getEsq()) + folhas(atual->getDir());
    }

 BSTNode* ArvoreBST::findMin(BSTNode* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->getEsq() == NULL)
            return t;
        else
            return findMin(t->getEsq());
    }

	//recursivo
    BSTNode* ArvoreBST::findMax(BSTNode* t) {
        if(t == NULL)
            return NULL;
        else if(t->getDir() == NULL)
            return t;
        else
            return findMax(t->getDir());
    }

  
    void ArvoreBST::infs(BSTNode* r)
    {
        BSTNode* aux;
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

	void ArvoreBST::print(BSTNode *no, int space)
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
	void ArvoreAVL::mediaAnaliseFilme(std::string procurar, float *soma, int* filme, AVLNode *no, int choice){
		if (no != NULL)
  		{	
  			if(choice == 3){
  				if(no->getTitulo()->getImdbScore() == procurar){
 				std::cout << no->getChave() << std::endl;
  					*soma = *soma + no->getReleaseYear();
  					*filme += 1;
				}	
			} else if (choice == 4){
				if(no->getTitulo()->getageCertification() == procurar && no->getTitulo()->getImdbPopularity() == procurar){
//  				std::cout << no->getChave() << std::endl;
  					*soma = *soma + nogetImdbPopularity();
  					*filme += 1;
				}
			} else if (choice == 5){
                if(no->getTitulo()->getProductionContries() == procurar && no->getTitulo()->getImdbScore() ){
				*soma = *soma + no->getImdbPopularity();
  				*filme += 1;
                }
			}
            } else if (choice == 6){
                if(no->getTitulo()->getRuntime() == procurar && no->getTitulo()->getImdbVotes() ){
				*soma = *soma + no)->getVotes();
  				*filme += 1;
                }
			}
    		mediaAnaliseFilme(procurar, soma, filme, no->getRight(), choice);
    		mediaAnaliseFilme(procurar, soma, filme, no->getLeft(), choice);
        }
  	}
	
	void ArvoreAVL::findMaxAnaliseFilme(std::string procurar, float *maximo, AVLNode* no, int choice, AVLNode* noMaximo){
		if (no != NULL)
  		{	
  			if(choice == 3){
  				if(no->getReleaseYear() == procurar){
  					if(no->getImdbScore() >= *maximo){
//  						std::cout << *maximo << " ";
//  						std::cout << no->getChave() << " " << no->getTituo()->getImdbScore() << std::endl;
  						*maximo = no)->getImdbScore();
					}
				}
			} else if (choice == 4) {
				if(no->getTitulo()->getageCertification() == procurar && no->getTitulo()->getImdbPopularity() == 0.0){
  					if(no->getTitulo()->getImdbPopularity() >= *maximo){
  						*maximo = no->getImdbPopularity();
					}
				}
			} else if (choice == 5){
				if(no->getTitulo()->getProductionContries() == procurar && no->getTitulo()->getImdbScore() != 0.0 ){
  					if(no->getTitulo()->getImdbPopularity() >= *maximo){
                    *maximo = no->getImdbPopularity() >= *maximo;
                    }
				}
			}
            else if (choice == 6){
				if(no->getTitulo()->getRuntime() == procurar && no->getTitulo()->getImdbVotes() != 0.0){
  					if(no->getTitulo()->getImdbVotes() >= *maximo){
                    *maximo = no)->getImdbPopularity() >= *maximo;
                    }
				}
			}
    		findMaxAnaliseFilme(procurar, maximo, no->getRight(), choice, noMaximo);
    		findMaxAnaliseFilme(procurar, maximo, no->getLeft(), choice, noMaximo);
  		}
	}
	
	void ArvoreAvl::findMinAnaliseFilme(std::string procurar, float *minimo, AVLNode* no, int choice, AvlNode* noMinimo){
		if (no != NULL)
  		{	
  			if(choice == 3){
  				if(no->getTitulo()->getReleaseYear() == procurar){
  					if(no->getTitulo()->getImdbScore() <= *minimo){
  						std::cout << *minimo << " ";
  						std::cout << no->getChave() << " " << no->getImdbScore() << std::endl;
  						*minimo = no->getImdbScore();
					}
				}	
			} else if (choice == 4){
				if(no->getTitulo()->getageCertification() == procurar && no->getTitulo()->getImdbPopularity() != 0.0){
  					if(no->getageCertification() <= *minimo && no->getImdbPopularity() != 0.0){
  						*minimo = no->getImdbPopularity();
					}
				}
			} else if (choice == 5){
				if(no->getTitulo()->getageCertification() <= *minimo && no->getTitulo()->getImdbPopularity() != 0.0){
  					*minimo = no->getImdbPopularity();
				}
			}
            else if (choice == 6){
				if(no->getTitulo()->getRuntime() <= *minimo && no->getTitulo()->getImdbVotes() != 0.0){
  					if(no->getImdbVotes() <= *minimo ){
                    *minimo = no->getImdbVotes() <= *minimo;
                    }
				}
			}
    		findMinAnaliseFilme(procurar, minimo, no->getRight(), choice, noMinimo);
    		findMinAnaliseFilme(procurar, minimo, no->getLeft(), choice, noMinimo);
  		}
	}
void ArvoreAVL:: analise1(std::string:age , std::string popularity ){
		float soma = 0, *tSoma = &soma, media1 = 0, media2 = 0;
		float maximo1 = 0, *tMaximo1 = &maximo1, minimo1, *tMinimo1 = &minimo1;
		float maximo2 = 0, *tMaximo2 = &maximo2, minimo2, *tMinimo2 = &minimo2;
    int filmes = 0, *tfilmes = &filmes;
}
  
}

void ArvoreAVL:: analise2(std::string:year , std::string Score ){
		float soma = 0, *tSoma = &soma, media1 = 0, media2 = 0;
		float maximo1 = 0, *tMaximo1 = &maximo1, minimo1, *tMinimo1 = &minimo1;
		float maximo2 = 0, *tMaximo2 = &maximo2, minimo2, *tMinimo2 = &minimo2;
    int filmes = 0, *tfilmes = &filmes;

mediaAnaliseFilme(year,tsoma,tfilmes,root,3);
media1 = soma/filmes;
*pfilmes= 0; &filmes=0.0;
mediaAnalise(Score, tSoma, tfilmes, root, 3);
media2 = soma/filmes;

findMaxAnalise(year, tMaximo1, root, 3, nullptr);
minimo1 = maximo1;
findMinAnalise(year,TMinimo1, root, 3, nullptr);
	
		//Max e Min para cargo2 
findMaxAnalise(Score, tMaximo2, raiz, 3, nullptr);
minimo2 = maximo2;
findMinAnalise(Score, tMinimo2, raiz, 3, nullptr);

//print dos resultados
std::cout<< "min do year" << minimo 1 ;
std::cout<< "medio do year" << media 1; 
std::cout<< "min do year" << maximo 1; 

std::cout<< "min do score" << minimo 2;
std::cout<< "medio do score" << media 2; 
std::cout<< "min do score" << maximo 2; 

std::cout<<"Diferença entre os dois generos"<<(media2-media1);
  
}

void ArvoreAVL:: analise3(std::string:country , std::string popularity ){
		float soma = 0, *tSoma = &soma, media1 = 0, media2 = 0;
		float maximo1 = 0, *tMaximo1 = &maximo1, minimo1, *tMinimo1 = &minimo1;
		float maximo2 = 0, *tMaximo2 = &maximo2, minimo2, *tMinimo2 = &minimo2;
    int filmes = 0, *tfilmes = &filmes;

mediaAnaliseFilme(country,tsoma,tfilmes,root,3);
media1 = soma/filmes;
*pfilmes= 0; &filmes=0.0;
mediaAnalise(popularity, tSoma, tfilmes, root, 3);
media2 = soma/filmes;

findMaxAnalise(country, tMaximo1, root, 3, nullptr);
minimo1 = maximo1;
findMinAnalise(country,TMinimo1, root, 3, nullptr);
	
		//Max e Min para cargo2 
findMaxAnalise(popularity, tMaximo2, raiz, 3, nullptr);
minimo2 = maximo2;
findMinAnalise(popularity, tMinimo2, raiz, 3, nullptr);

//print dos resultados
std::cout<< "min do country" << minimo 1 ;
std::cout<< "medio do country" << media 1; 
std::cout<< "min do country" << maximo 1; 

std::cout<< "min do popularity" << minimo 2;
std::cout<< "medio do popularity" << media 2; 
std::cout<< "min do popularity" << maximo 2; 
  
}

void ArvoreAVL:: analise4(std::string:year , std::string Votes ){
		float soma = 0, *tSoma = &soma, media1 = 0, media2 = 0;
		float maximo1 = 0, *tMaximo1 = &maximo1, minimo1, *tMinimo1 = &minimo1;
		float maximo2 = 0, *tMaximo2 = &maximo2, minimo2, *tMinimo2 = &minimo2;
    int filmes = 0, *tfilmes = &filmes;

mediaAnaliseFilme(year,tsoma,tfilmes,root,3);
media1 = soma/filmes;
*pfilmes= 0; &filmes=0.0;
mediaAnalise(Votes, tSoma, tfilmes, root, 3);
media2 = soma/filmes;

findMaxAnalise(year, tMaximo1, root, 3, nullptr);
minimo1 = maximo1;
findMinAnalise(year,TMinimo1, root, 3, nullptr);
	
		//Max e Min para cargo2 
findMaxAnalise(Votes, tMaximo2, raiz, 3, nullptr);
minimo2 = maximo2;
findMinAnalise(Votes, tMinimo2, raiz, 3, nullptr);

//print dos resultados
std::cout<< "min do year" << minimo 1 ;
std::cout<< "medio do year" << media 1; 
std::cout<< "min do year" << maximo 1; 

std::cout<< "min do score" << minimo 2;
std::cout<< "medio do score" << media 2; 
std::cout<< "min do score" << maximo 2; 

  
}
	

