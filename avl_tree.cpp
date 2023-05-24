#include "avl_tree.h"

ArvoreAVL::ArvoreAVL()
{    
    root = NULL;
}

ArvoreAVL::~ArvoreAVL()
{
 
}

AVLNode* ArvoreAVL::getRoot(){
    return root;
}

/*Fator de Balanceamento*/
int ArvoreAVL::getBalance(AVLNode *N) 
{ 
    if (N == NULL) 
        return 0; 
    return height(N->getLeft()) - height(N->getRight()); //FB = HL - HD
}

bool ArvoreAVL::isEmpty()
{
    return root==NULL;
}

int ArvoreAVL::height()
{
	return height(root);
}

int ArvoreAVL::height(AVLNode *no)
{	
	return no==NULL? -1 : no->getHeight();
}

AVLNode * ArvoreAVL::minimo(AVLNode* no) 
{ 
    AVLNode* current = no;     
    while (current->getLeft() != NULL) 
        current = current->getLeft(); 
    return current;
}

int ArvoreAVL::maximo(int lhs, int rhs)
{
    return lhs > rhs ? lhs : rhs;
    //Operador Condicional Ternário: condition ? expr1 : expr2
    //Se condition é true, retornará o valor de expr1; se não, ele retorna o valor de exp2
}

int ArvoreAVL::qtNodes()
{
    return qtNodes(root);
}

int ArvoreAVL::qtNodes(AVLNode* no)
{
    if (no == NULL)
		return 0;
	int qtleft = qtNodes (no->getLeft());
	int qtright = qtNodes (no->getRight());
	return qtleft + qtright + 1;
}

void ArvoreAVL::inserir (Title *t)
{
    root = inserir(root,t);
}

AVLNode* ArvoreAVL::inserir(AVLNode* node, Title *t)
{
    if (node == NULL)
       	return new AVLNode(t);
    if (t->getId() < node->getData()->getId())
    {
            node->setLeft(inserir(node->getLeft(), t));
            if( height( node->getRight() ) - height( node->getLeft() ) == -2 ) //FB = HR - HL
            /*
                    se FB > 1 então:
						se a Sub-árvore da direita tem FB < 0 então: 
			 				rotação dupla à esquerda
						senão:
							rotação simples à esquerda                    
            */
            {
                if(  t < node->getLeft()->getData() ) //Ao inserir o nó a esquerda, sub-árvore da esquerda de node terá FB < 0
                     {
                        node = rotateR( node ); //Rotação Simples para Direita
                     }
                 else{ //Ao inserir o nó a direita, sub-árvore da direita de node terá FB > 0
                        node = rotateLR( node ); //Rotação Dupla para Direita
                     }
            }
    }
    else
    {
        if (t->getId() > node->getData()->getId())
            {
                    node->setRight(inserir(node->getRight(),t));
                    if( height( node->getRight() ) - height( node->getLeft() ) == 2 ) //FB = HR - HL
                    /*
                    se FB > 1 então:
						se a Sub-árvore da direita tem FB < 0 então: 
			 				rotação dupla à esquerda
						senão:
							rotação simples à esquerda                    
                    */
                    {
                        if( t > node->getRight()->getData()) //Ao inserir o nó a direita, sub-árvore da direita de node terá FB > 0
                            node = rotateL( node ); //Rotação Simples para Esquerda
                        else //Ao inserir o nó a esquerda, sub-árvore da direita de node terá FB < 0
                            node = rotateRL( node ); //Rotação Dupla para Esquerda

                    }

            }
    }
    node->setHeight(maximo( height(node->getLeft()), height(node->getRight()) ) + 1);

    return node;
}

AVLNode* ArvoreAVL::rotateR(AVLNode *node) //Rotação Simples para Direita
     {
     	 std::cout << "Rotação Simples para Direita" << std::endl;
         AVLNode *leftSubTree = node->getLeft();
         node->setLeft(leftSubTree->getRight());
         leftSubTree->setRight( node );
         node->setHeight( maximo(height(node->getLeft()), height(node->getRight())) + 1);
         leftSubTree->setHeight( maximo(height(leftSubTree->getLeft()), height(node) + 1));
         return leftSubTree;
     }

AVLNode* ArvoreAVL::rotateL(AVLNode *node) //Rotação Simples para Esquerda
     {
     	 std::cout << "Rotação Simples para Esquerda" << std::endl;
         AVLNode *rightSubTree = node->getRight();
         node->setRight(rightSubTree->getLeft());
         rightSubTree->setLeft( node );
         node->setHeight( maximo(height(node->getLeft()), height(node->getRight())) + 1);
         rightSubTree->setHeight( maximo(height(rightSubTree->getRight()), height(node) + 1));
         return rightSubTree;
     }

AVLNode* ArvoreAVL::rotateLR(AVLNode *node) //Left-Right Rotation (LR) => Rotação Dupla para Direita: esquerda -> direita
{
	std::cout << "Rotação Dupla para Direita:" << std::endl; 
    node->setLeft(rotateL(node->getLeft())); //Rotação para esquerda na sub-árvore da esquerda
    return rotateR(node); //Rotação para direita no nó com o FB violado!
}

AVLNode* ArvoreAVL::rotateRL(AVLNode *node) //Right-Left Rotiation (RL) => Rotação Dupla para Esquerda: direita -> esquerda
{
	std::cout << "Rotação Dupla para Esquerda:" << std::endl;
    node->setRight(rotateR(node->getRight())); //Rotação para direita na sub-árvore da direita
    return rotateL(node); //Rotação para esquerda no nó com o FB violado!
}


AVLNode * ArvoreAVL::leftRotate(AVLNode *x) 
{ 
	std::cout << "leftRotate" << std::endl;
    AVLNode *y = x->getRight(); 
    AVLNode *T2 = y->getLeft(); 
  
    y->setLeft(x); 
    x->setRight(T2); 
   
    x->setHeight(maximo(height(x->getLeft()),height(x->getRight())) + 1); 
    y->setHeight(maximo(height(y->getLeft()),height(y->getRight())) + 1); 
     
    return y; 
}

AVLNode * ArvoreAVL::rightRotate(AVLNode *y) 
{ 
	std::cout << "rightRotate" << std::endl;
    AVLNode *x = y->getLeft(); 
    AVLNode *T2 = x->getRight(); 
     
    x->setRight(y); 
    y->setLeft(T2);
    
    y->setHeight(maximo(height(y->getLeft()),height(y->getRight())) + 1); 
    x->setHeight(maximo(height(x->getLeft()),height(x->getRight())) + 1); 

    return x; 
}


// **** Metodo que remove um elemento da Arvore ****
void ArvoreAVL::remove (std::string id)
{
    root = remove(root,id);
}

AVLNode* ArvoreAVL::remove(AVLNode* root, std::string key) 
{ 
    if (root == NULL)         
        return nullptr;
  
    if ( key < root->getData()->getId() ) 
        root->setLeft(remove(root->getLeft(), key));    
    else if( key > root->getData()->getId()) 
        root->setRight(remove(root->getRight(), key)); 
    else
    { 
        if( (root->getLeft() == NULL) || (root->getRight() == NULL) ) //node com 1 filho
        { 
            AVLNode *temp = root->getLeft() ? 
                        root->getLeft() : 
                        root->getRight(); 
            
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else 
            *root = *temp;                         
            free(temp); 
        } 
        else //node com 2 filhos
        {              
            AVLNode* temp = minimo(root->getRight()); //busca pelo menor dos maiores            
            root->setData(temp->getData());             
            root->setRight(remove(root->getRight(),temp->getData()->getId())); 
        } 
    }
 
    if (root == NULL) 
    return root; 
	    
    root->setHeight ( 1 + maximo(height(root->getLeft()),height(root->getRight()))); 

    int balance = getBalance(root); 

    // Left Left Case 
    if (balance > 1 && getBalance(root->getLeft()) >= 0) 
        return rightRotate(root); 

    // Left Right Case 
    if (balance > 1 && getBalance(root->getLeft()) < 0) 
    { 
        root->setLeft(leftRotate(root->getLeft())); 
        return rightRotate(root);  
    } 

    // Right Right Case 
    if (balance < -1 && getBalance(root->getRight()) <= 0) 
        return leftRotate(root); 

    // Right Left Case 
    if (balance < -1 && getBalance(root->getRight()) > 0) 
    { 
         root->setRight(rightRotate(root->getRight())); 
         return leftRotate(root); 
    } 

    return root; 
}



void ArvoreAVL::preOrder()
{
    preOrder(root);
}

void ArvoreAVL::inOrder()
{
    inOrder(root);
}

void ArvoreAVL::posOrder()
{
    posOrder(root);
}

void ArvoreAVL::reverseOrder()
{
    reverseOrder(root);
}

void ArvoreAVL::preOrder(AVLNode *no)
{
    if (no!=NULL)
    {
        std::cout<<no->getData()<<std::endl;
        preOrder(no->getLeft());
        preOrder(no->getRight());
    }
}

void ArvoreAVL::posOrder(AVLNode *no)
{
    if (no!=NULL)
    {
        posOrder(no->getLeft());
        posOrder(no->getRight());
        std::cout<<no->getData()<<std::endl;
    }
}

void ArvoreAVL::inOrder(AVLNode *no)
{
    if (no!=NULL)
    {
        inOrder(no->getLeft());
        std::cout<<no->getData()<<std::endl;
        inOrder(no->getRight());
    }
}

void ArvoreAVL::reverseOrder(AVLNode *no)
{
    if (no!=NULL)
    {
        reverseOrder(no->getRight());
		std::cout<<no->getData()<<std::endl;
        reverseOrder(no->getLeft());
    }
}


bool ArvoreAVL::isAVL()
{
    return isAVL(root);
}

bool ArvoreAVL::isAVL(AVLNode* no)
{
    if (root == NULL) return true;

    if (no == NULL) return true;
    
    if (getBalance(no) > 1 || getBalance(no) < -1) return false;
    
    if (no->getLeft() != NULL)
    {
        if (no->getLeft()->getData() > no->getData())
            return false;
    }
    if (no->getRight() != NULL)
    {
        if (no->getRight()->getData() < no->getData())
            return false;
    }

    bool x = isAVL(no->getLeft());
    bool y = isAVL(no->getRight());
    return x && y;
}

void ArvoreAVL::print()
{
  print(root, 0);
}

void ArvoreAVL::print(AVLNode *no, int space)
{
  if (no != NULL)
  {
    print(no->getRight(), space + 5);
    for (int k = 0; k < space; ++k) std::cout << " ";
    std::cout << no->getData() << "[" << getBalance(no) << "]\n";
    print(no->getLeft(), space + 5);
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
	
