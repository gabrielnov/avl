#include "bst_tree.h"
#include <iostream>
using namespace std;

void ArvoreBST::inserir(std::string chave, Title *t){
        if(raiz == NULL) 
            raiz = new BSTNode(chave, t); 
        else
            inserirAux(raiz, chave, t);
}

 void ArvoreBST::inserirAux(BSTNode *no, std::string chave, Title *p)
    {
        // se for menor, entï¿½o insere na sub-ï¿½rvore ï¿½ esquerda
        if(chave < no->getChave())
        {
            // verifica se nï¿½o tem filho a esquerda: achou local de inserï¿½ï¿½o 
            if(no->getEsq() == NULL)
            {
                BSTNode *novo_no = new BSTNode(chave, p);
                no->setEsq(novo_no); // add o novo_no ï¿½ esquerda do nï¿½ atual
            }
            else
            {
                // senï¿½o, continua percorrendo recursivamente para esquerda
                inserirAux(no->getEsq(), chave, p);
            }
        }
        // se for maior, entï¿½o insere na sub-ï¿½rvore ï¿½ direita
        else if(chave > no->getChave())
        {
            // verifica se nï¿½o tem filho a direita: achou local de inserï¿½ï¿½o
            if(no->getDir() == NULL)
            {
                BSTNode *novo_no = new BSTNode(chave, p);
                no->setDir(novo_no); // add o novo_no ï¿½ direita do nï¿½ atual
            }
            else
            {
                // senï¿½o, continua percorrendo recursivamente para direita
                inserirAux(no->getDir(), chave, p);
            }
        }
        // se a chave for igual a alguma presente na ï¿½rvore, nï¿½o vamos inserir
        // nï¿½o pode existir 2 chaves iguais na nossa BST
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
        return -1; //ï¿½rvore ou sub-ï¿½rvore vazia: altura = -1
    else
    {
        if(atual->getEsq() == NULL && atual->getDir() == NULL)
            return 0; //ï¿½vore com apenas 1 nï¿½, altura = 0
        else
        {//altura da ï¿½rvore ï¿½ a altura da sub-ï¿½rvore de maior altura
            if (altura(atual->getEsq()) > altura(atual->getDir()))
                return ( 1 + altura(atual->getEsq()) );
            else
                return ( 1 + altura(atual->getDir()) );
        }
    }
}

BSTNode* ArvoreBST::excluir(BSTNode* t, std::string key){
        
    //Arvore t ï¿½ vazia
    if (t == NULL) 
        return t;
    
    if (key < t->getChave())
        t->setEsq(excluir(t->getEsq(),key));
    else
        if (key > t->getChave())
            t->setDir(excluir(t->getDir(),key));
    
    //encontramos o nï¿½ a ser removido
    else{ 
        //Caso1: o no a ser excluido nao tem filhos
        if (t->getEsq() == NULL and t->getDir() == NULL){
        	delete(t);
            return NULL; //faz o pai apontar para NULL e o nï¿½ nï¿½o faz mais parte da BST	
		}            	
        else 
            //Caso2: tem apenas um filho, a esquerda ou a direita
            if (t->getEsq() == NULL){
                BSTNode* temp = t->getDir();
                delete(t);
                return temp; //Faz o pai apontar para o ï¿½nico filho do nï¿½
            }
            else 
                if  (t->getDir() == NULL){
                    BSTNode* temp = t->getEsq();
                    delete(t);
                    return temp; //Faz o pai apontar para o ï¿½nico filho do nï¿½
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

void ArvoreBST::findMediaAnaliseFilme(std::string procurar, float *procuraValor, BSTNode* no, int choice, float *nPessoas){
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
        findMediaAnaliseFilme(procurar, procuraValor, no->getDir(), choice, nPessoas);
        findMediaAnaliseFilme(procurar, procuraValor, no->getEsq(), choice, nPessoas);
	}
}

void ArvoreBST::findMaxAnaliseFilme(std::string procurar, float *maximo, BSTNode* no, int choice, std::string *nomeFilmeProcurado){
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
        findMaxAnaliseFilme(procurar, maximo, no->getDir(), choice, nomeFilmeProcurado);
        findMaxAnaliseFilme(procurar, maximo, no->getEsq(), choice, nomeFilmeProcurado);
	}
}

void ArvoreBST::findMinAnaliseFilme(std::string procurar, float *minimo, BSTNode* no, int choice, std::string *nomeFilmeProcurado){
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
        findMinAnaliseFilme(procurar, minimo, no->getDir(), choice, nomeFilmeProcurado);
        findMinAnaliseFilme(procurar, minimo, no->getEsq(), choice, nomeFilmeProcurado);
	}
}

BSTNode* ArvoreBST::pesquisar(std::string valor, BSTNode *no){
	if(no->getData()->getId() == valor || no == nullptr){
		return no;
	} else if (no->getData()->getId() < valor){
		return pesquisar(valor, no->getDir());
	} else {
		return pesquisar(valor, no->getEsq());
	}
}

void ArvoreBST::analise3(std::string id1, std::string id2, BSTNode *no){ //id do filme
	BSTNode *temp1 = pesquisar(id1, no);
	BSTNode *temp2 = pesquisar(id2, no);
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

void ArvoreBST::analise4(std::string id, BSTNode *no){ //certo
//	posOrder(no);
	BSTNode *temp = pesquisar(id, no);
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
	std::cout << "Minimo em age Certification: " << minimo << " | filme: " << filmeMinimo << std::endl;
	std::cout << "--------- IMDB score e Média(AGE CERT) ----------\n";
	std::cout << "filme: " << nomeFilme << std::endl;
	std::cout << "Imdb do filme: " << imdbEntrada << " | media do ageCertification: " << media << std::endl;
	std::cout << "Diferenca entre os dois: " << abs(imdbEntrada-media) << std::endl;
	std::cout << "Diferenca Percentual entre os dois: " << (abs(imdbEntrada-media)/((imdbEntrada+media)/2))*100 << "%" << std::endl;
}

void ArvoreBST::analise5(std::string pais, BSTNode *no){ //pais
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

void ArvoreBST::analise6(std::string year1, std::string year2, BSTNode *no){ //dois anos
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


