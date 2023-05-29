#include "avl_tree.h"
#include <cmath>
using namespace std;

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
    //Operador Condicional Tern�rio: condition ? expr1 : expr2
    //Se condition � true, retornar� o valor de expr1; se n�o, ele retorna o valor de exp2
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
            if( height( node->getRight() ) - height( node->getLeft() ) == -2 ) 
            {
                if(  t->getId() < node->getLeft()->getData()->getId() ) 
                     {
                        node = rotateR( node ); 
                     }
                 else{ 
                        node = rotateLR( node ); 
                     }
            }
    }
    else
    {
        if (t->getId() > node->getData()->getId())
            {
                    node->setRight(inserir(node->getRight(),t));
                    if( height( node->getRight() ) - height( node->getLeft() ) == 2 ) //FB = HR - HL
                    {
                        if( t->getId() > node->getRight()->getData()->getId()) //Ao inserir o n� a direita, sub-�rvore da direita de node ter� FB > 0
                            node = rotateL( node ); //Rota��o Simples para Esquerda
                        else //Ao inserir o n� a esquerda, sub-�rvore da direita de node ter� FB < 0
                            node = rotateRL( node ); //Rota��o Dupla para Esquerda

                    }

            }
    }
    node->setHeight(maximo( height(node->getLeft()), height(node->getRight()) ) + 1);

    return node;
}

AVLNode* ArvoreAVL::rotateR(AVLNode *node) //Rota��o Simples para Direita
     {
         AVLNode *leftSubTree = node->getLeft();
         node->setLeft(leftSubTree->getRight());
         leftSubTree->setRight( node );
         node->setHeight( maximo(height(node->getLeft()), height(node->getRight())) + 1);
         leftSubTree->setHeight( maximo(height(leftSubTree->getLeft()), height(node) + 1));
         return leftSubTree;
     }

AVLNode* ArvoreAVL::rotateL(AVLNode *node) //Rota��o Simples para Esquerda
     {
         AVLNode *rightSubTree = node->getRight();
         node->setRight(rightSubTree->getLeft());
         rightSubTree->setLeft( node );
         node->setHeight( maximo(height(node->getLeft()), height(node->getRight())) + 1);
         rightSubTree->setHeight( maximo(height(rightSubTree->getRight()), height(node) + 1));
         return rightSubTree;
     }

AVLNode* ArvoreAVL::rotateLR(AVLNode *node) //Left-Right Rotation (LR) => Rota��o Dupla para Direita: esquerda -> direita
{
    node->setLeft(rotateL(node->getLeft())); //Rota��o para esquerda na sub-�rvore da esquerda
    return rotateR(node); //Rota��o para direita no n� com o FB violado!
}

AVLNode* ArvoreAVL::rotateRL(AVLNode *node) //Right-Left Rotiation (RL) => Rota��o Dupla para Esquerda: direita -> esquerda
{
    node->setRight(rotateR(node->getRight())); //Rota��o para direita na sub-�rvore da direita
    return rotateL(node); //Rota��o para esquerda no n� com o FB violado!
}


AVLNode * ArvoreAVL::leftRotate(AVLNode *x) 
{ 
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
        posOrder(no->getRight());
        posOrder(no->getLeft());
        if(no->getData()->getId() == "tm155787"){
        	std::cout<<no->getData()->getId()<<std::endl;
		}
//        std::cout<<no->getData()->getId()<<std::endl;
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

void ArvoreAVL::findMediaAnaliseFilme(std::string procurar, float *procuraValor, AVLNode* no, int choice, float *nPessoas){
    if (no != NULL) {
      	if (choice == 4){
            if(no->getData()->getAgeCertification() == procurar && no->getData()->getImdbScore() != ""){
//            	cout << "filme " << no->getData()->getTitulo() << " " << no->getData()->getImdbScore() << endl;
              	*procuraValor += stof(no->getData()->getImdbScore());
              	*nPessoas += 1;
            }
        } else if (choice == 5){
            if(no->getData()->getProductionCountries() == procurar && no->getData()->getImdbVotes() != ""){
                *procuraValor += stof(no->getData()->getImdbVotes());
                *nPessoas += 1;
//                cout << *procuraValor << " " << stof(no->getData()->getImdbVotes()) << endl;
            }
        } else if (choice == 6){
            if( no->getData()->getReleaseYear() == procurar && no->getData()->getRuntime() != ""){
                *procuraValor += stof(no->getData()->getRuntime());
                *nPessoas += 1;
            }
    	}
        findMediaAnaliseFilme(procurar, procuraValor, no->getRight(), choice, nPessoas);
        findMediaAnaliseFilme(procurar, procuraValor, no->getLeft(), choice, nPessoas);
	}
}

void ArvoreAVL::findMaxAnaliseFilme(std::string procurar, float *maximo, AVLNode* no, int choice, std::string *nomeFilmeProcurado){
    if (no != NULL) {
      	if (choice == 4){
      		if(no->getData()->getId() == "tm25947") {
      			cout << "gostei";
			}
            if(no->getData()->getAgeCertification() == procurar && no->getData()->getImdbScore() != ""){
              	if(stof(no->getData()->getImdbScore()) >= *maximo){
//              		cout << "maximo " << *maximo << endl;
                	*maximo = stof(no->getData()->getImdbScore());
                	*nomeFilmeProcurado = no->getData()->getTitulo();
                }
            }
        } else if (choice == 5){
            if(no->getData()->getProductionCountries() == procurar && no->getData()->getImdbVotes() != ""){
                if(stof(no->getData()->getImdbVotes()) >= *maximo){
                	*maximo = stof(no->getData()->getImdbVotes());
                	*nomeFilmeProcurado = no->getData()->getTitulo();
                }
            }
        } else if (choice == 6){
            if( no->getData()->getReleaseYear() == procurar && no->getData()->getRuntime() != ""){
                if(stof(no->getData()->getRuntime()) >= *maximo ){
                	*maximo = stof(no->getData()->getRuntime());
                }
            }
    	}
        findMaxAnaliseFilme(procurar, maximo, no->getRight(), choice, nomeFilmeProcurado);
        findMaxAnaliseFilme(procurar, maximo, no->getLeft(), choice, nomeFilmeProcurado);
	}
}

void ArvoreAVL::findMinAnaliseFilme(std::string procurar, float *minimo, AVLNode* no, int choice, std::string *nomeFilmeProcurado){
    if (no != NULL) {
      	if (choice == 4){
            if(no->getData()->getAgeCertification() == procurar && no->getData()->getImdbScore() != ""){
              	if(stof(no->getData()->getImdbScore()) <= *minimo){
                	*minimo = stof(no->getData()->getImdbScore());
                	*nomeFilmeProcurado = no->getData()->getTitulo();
                }
            }
        } else if (choice == 5){
            if(no->getData()->getProductionCountries() == procurar && no->getData()->getImdbVotes() != ""){
                if(stof(no->getData()->getImdbVotes()) <= *minimo){
                	*minimo = stof(no->getData()->getImdbVotes());
                	*nomeFilmeProcurado = no->getData()->getTitulo();
                }
            }
        } else if (choice == 6){
            if( no->getData()->getReleaseYear() == procurar && no->getData()->getRuntime() != ""){
                if(stof(no->getData()->getRuntime()) <= *minimo ){
                	*minimo = stof(no->getData()->getRuntime());
                }
            }
    	}
        findMinAnaliseFilme(procurar, minimo, no->getRight(), choice, nomeFilmeProcurado);
        findMinAnaliseFilme(procurar, minimo, no->getLeft(), choice, nomeFilmeProcurado);
	}
}

AVLNode* ArvoreAVL::pesquisar(std::string valor, AVLNode *no){
	if(no->getData()->getId() == valor || no == nullptr){
		return no;
	} else if (no->getData()->getId() > valor){
		return pesquisar(valor, no->getLeft());
	} else {
		return pesquisar(valor, no->getRight());
	}
}

void ArvoreAVL::analise3(std::string id1, std::string id2, AVLNode *no){ //id do filme
	AVLNode *temp1 = pesquisar(id1, no);
	AVLNode *temp2 = pesquisar(id2, no);
	std::cout << temp1->getData()->getTitulo() << " " << temp2->getData()->getTitulo();
	
	float imdb1 = stof(temp1->getData()->getImdbScore());
	float imdb2 = stof(temp2->getData()->getImdbScore());
	float pop1 = stof(temp1->getData()->getImdbVotes());
	float pop2 = stof(temp2->getData()->getImdbVotes());
	//print e resultado
	std::cout << "\n--------- IMDB SCORE ---------\n";
	std::cout << "Primeiro id: " << imdb1 << " | Segundo id: " << imdb2 << std::endl;
	std::cout << "Diferenca entre os ids: " << abs(imdb1-imdb2) << std::endl;
	std::cout << "Diferenca Percentual de score entre os dois ids: " << (abs(imdb2-imdb1)/((imdb2+imdb1)/2))*100 << "%" << std::endl;
	std::cout << "--------- IMDB VOTES ----------\n";
	std::cout << "Primeiro id: " << pop1 << " | Segundo id: " << pop2 << std::endl;
	std::cout << "Diferenca entre os ids: " << abs(pop2-pop1) << std::endl;
	std::cout << "Diferenca Percentual de votes entre os dois ids: " << (abs(pop2-pop1)/((pop2+pop1)/2))*100 << "%" << std::endl;
}

void ArvoreAVL::analise4(std::string id, AVLNode *no){ //certo
//	posOrder(no);
	AVLNode *temp = pesquisar(id, no);
	std::string nomeFilme = temp->getData()->getTitulo();
	std::string ageC = temp->getData()->getAgeCertification();
	float imdbEntrada = std::stof(temp->getData()->getImdbScore());

	float soma = 0, media, qntd = 0;
	findMediaAnaliseFilme(ageC, &soma, no, 4, &qntd);
	media = soma/qntd;
	
	float maximo = 0;
	std::string filmeMaximo = " ";
	findMaxAnaliseFilme(ageC, &maximo, no, 4, &filmeMaximo);
	
	float minimo = maximo;
	std::string filmeMinimo = " ";
	findMinAnaliseFilme(ageC, &minimo, no, 4, &filmeMinimo);
	
	///////////////////////////////////////////////////////////////////////////////
	std::cout << "--------- MAX ----------\n";
	std::cout << "Maximo em age Certification: " << maximo << " | filme: " << filmeMaximo << std::endl;
	std::cout << "--------- MIN ----------\n";
	std::cout << "Minimo do age Certification: " << minimo << " | filme: " << filmeMinimo << std::endl;
	std::cout << "--------- IMDB score e M�dia(AGE CERT) ----------\n";
	std::cout << "filme: " << nomeFilme << std::endl;
	std::cout << "Imdb do filme: " << imdbEntrada << " | media do ageCertification: " << media << std::endl;
	std::cout << "Diferenca entre os dois: " << abs(imdbEntrada-media) << std::endl;
	std::cout << "Diferenca Percentual entre os dois: " << (abs(imdbEntrada-media)/((imdbEntrada+media)/2))*100 << "%" << std::endl;
}

 void ArvoreAVL::analise7(AVLNode* no, int notas[], int *total){
    
        if(no != NULL){
            analise7(no->getLeft(), notas, total);
            analise7(no->getRight(), notas, total);
            
            int nota = stoi(no->getData()->getImdbScore());
            notas[nota] += 1;
            (*total)++;
        }
    }


void ArvoreAVL::analise5(std::string pais, AVLNode *no){ //pais
	float maximo = 0, minimo, soma = 0, media, qntd = 0;
	std::string filmeMax = " ", filmeMin = " ";
	
	findMaxAnaliseFilme(pais, &maximo, no, 5, &filmeMax);
	minimo = maximo;
	findMinAnaliseFilme(pais, &minimo, no, 5, &filmeMin);
	findMediaAnaliseFilme(pais, &soma, no, 5, &qntd);
	media = soma/qntd;
	
	//print e resultado
	std::cout << "--------- MAX e MIN ----------\n";
	std::cout << "Maximo do pais: " << maximo << " | minimo do pais: " << minimo << std::endl;
	std::cout << "Diferenca entre os dois ids: " << abs(maximo-minimo) << std::endl;
	std::cout << "Diferenca Percentual entre os dois ids: " << (abs(maximo-minimo)/((maximo+minimo)/2))*100 << "%" << std::endl;
	std::cout << "--------- MAX e MEDIA ----------\n";
	std::cout << "Maximo do pais: " << maximo << " | media do pais: " << media << std::endl;
	std::cout << "Diferenca entre os dois ids: " << abs(maximo-media) << std::endl;
	std::cout << "Diferenca Percentual entre os dois ids: " << (abs(maximo-media)/((maximo+media)/2))*100 << "%" << std::endl;
	std::cout << "--------- MIN e MEDIA ----------\n";
	std::cout << "Minimo do pais: " << minimo << " | media do pais: " << media << std::endl;
	std::cout << "Diferenca entre os dois ids: " << abs(minimo-media) << std::endl;
	std::cout << "Diferenca Percentual entre os dois ids: " << (abs(minimo-media)/((minimo+media)/2))*100 << "%" << std::endl;
}

void ArvoreAVL::analise6(std::string year1, std::string year2, AVLNode *no){ //dois anos
	float maximo1 = 0; //maximo1
	std::string filme1 = " ";;
	findMaxAnaliseFilme(year1, &maximo1, no, 6, &filme1);
	
	float maximo2 = 0; //maximo2
	std::string filme2 = " ";
	findMaxAnaliseFilme(year2, &maximo2, no, 6, &filme2);
	
	float qntd1 = 0, media1, soma1 = 0; //media1
	findMediaAnaliseFilme(year1, &soma1, no, 6, &qntd1);
	media1 = soma1/qntd1;
	
	float qntd2 = 0, media2, soma2 = 0; //media2
	findMediaAnaliseFilme(year2, &soma2, no, 6, &qntd2);
	media2 = soma2/qntd2;
	
	float minimo1 = maximo1; //minimo1
	std::string filmeMinimo1 = " ";
	findMinAnaliseFilme(year1, &minimo1, no, 6, &filmeMinimo1);
	
	float minimo2 = maximo2; //minimo2
	std::string filmeMinimo2 = " ";
	findMinAnaliseFilme(year2, &minimo2, no, 6, &filmeMinimo1);
	
	std::cout << "year1: " << minimo1 << " " << maximo1 << " " << soma1/qntd1 << std::endl;
	std::cout << "year2: " << minimo2 << " " << maximo2 << " " << soma2/qntd2 << std::endl;
	
	//print e resultado
	std::cout << "\n--------- Media ---------\n";
	std::cout << "Media da primeira unidade: " << media1 << " | Media da segunda unidade: " << media2 << std::endl;
	std::cout << "Diferenca entre as duas unidades: " << abs(media2-media1) << std::endl;
	std::cout << "Diferenca Percentual de media entre as duas unidades: " << (abs(media2-media1)/((media2+media1)/2))*100 << "%" << std::endl;
	std::cout << "--------- MAX ----------\n";
	std::cout << "Maximo da primeira unidade: " << maximo1 << " | Maximo da segunda unidade: " << maximo2 << std::endl;
	std::cout << "Diferenca entre as duas unidades: " << abs(maximo2-maximo1) << std::endl;
	std::cout << "Diferenca Percentual de maximo entre as duas unidades: " << (abs(maximo2-maximo1)/((maximo2+maximo1)/2))*100 << "%" << std::endl;
	std::cout << "--------- MIN ----------\n";
	std::cout << "Minimo da primeira unidade: " << minimo1 << " | Minimo da seguda unidade: " << minimo2 << std::endl;
	std::cout << "Diferenca entre as duas unidades: " << abs(minimo2-minimo1) << std::endl;
	std::cout << "Diferenca Percentual de minimo entre as duas unidades: " << (abs(minimo2-minimo1)/((minimo2+minimo1)/2))*100 << "%" << std::endl;
}
