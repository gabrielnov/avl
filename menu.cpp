#include "menu.h"
#include <iostream>
#include <string>

void menu(ArvoreAVL* avl, ArvoreBST* bst){

	int opt;
	bool exit = false;
	bool* fileRead = new bool(false);
	
	while (!exit){
		printMenu();
		std::cin >> opt;
		exit = readOption(opt, avl, bst, fileRead);
	}
	
	delete fileRead;
	fileRead = nullptr;
}

void printMenu(){
		std::cout << "\n\n"
        << "[1] Ler dados\n"	
		<< "[2] Analise A\n"
		<< "[3] Analise B\n"
		<< "[4] Analise C\n"
		<< "[5] Analise D\n"
		<< "[6] Analise E\n"
		<< "[7] Remover Filme\n"
		<< "[8] Salvar dados\n"
		<< "[9] Inserir novo titulo\n"
		<< "[10] Pesquisar\n"
		<< "[0] Encerrar\n\n"
		<< "Digite a opcao: ";		
}

bool readOption(int opt, ArvoreAVL* avl, ArvoreBST* bst, bool* fileRead){
	std::string titulo, pesquisar;
    BSTNode *respBST;
	std::string id1, id2, pais, year1, year2;
	int opAvl = 0, opBst = 0, AB = 0;
	int *ptrAvl = &opAvl, *ptrBst = &opBst;
	std::string stringArray[15] = {};
	Title *t = new Title();
	AVLNode* temp;
	BSTNode* bstNode;
	switch(opt){
			case 1:
				readFile(bst, avl);
				*fileRead = true;
				break;
			case 2:
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1)";
					break;
				}
				// analise 3
				std::cout << "id do primeiro filme: "; std::cin >> id1;
				std::cout << "id do segundo filme: "; std::cin >> id2;
				std::cout << "avl(1) ou bst(2)?: ";  std::cin >> AB;
				if(AB == 1){
					avl->analise3(id1, id2, avl->getRoot());
				} else {
					bst->analise3(id1, id2, bst->getRaiz());
				}
				break;
			case 3:
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1)";
					break;
				}
				// analise 4
				std::cout << "id do filme: "; std::cin >> id1;
				std::cout << "avl(1) ou bst(2)?: ";  std::cin >> AB;
				if(AB == 1){
					avl->analise4(id1, avl->getRoot());
				} else {
					bst->analise4(id1, bst->getRaiz());
				}
				break;
			case 4:
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1)";
					break;
				}
				// analise 5
				std::cout << "Ex: ['US'], ['US','AE']" << std::endl;
				std::cout << "pais(es) de acordo com o exemplo: "; std::cin >> pais;
				std::cout << "avl(1) ou bst(2)?: ";  std::cin >> AB;
				if(AB == 1){
					avl->analise5(pais, avl->getRoot());
				} else {
					bst->analise5(pais, bst->getRaiz());
				}
				break;
			case 5:
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1)";
					break;
				}
				// analise 6
				std::cout << "primeiro ano: "; std::cin >> year1;
				std::cout << "segundo ano: "; std::cin >> year2;
				std::cout << "avl(1) ou bst(2)?: ";  std::cin >> AB;
				if(AB == 1){
					avl->analise6(year1, year2, avl->getRoot());
				} else {
					bst->analise6(year1, year2, bst->getRaiz());
				}
				break;
			case 6:
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1)";
					break;
				}
				plot(avl);
				break;
			case 7:
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1)" << std::endl;
					break;
				}

				std::cin.ignore(256, '\n'); 
				std::cout << "Insira o nome do titulo a ser removido: ";
                std::getline(std::cin, titulo);


				respBST = bst->excluir(bst->getRaiz(), titulo, ptrBst);
                bst->setRaiz(respBST);

                avl->remove(titulo, ptrAvl);
				
				std::cout << "Titulo " << titulo << " removido(a) com sucesso!" << std::endl;
				std::cout << "Total de comparacoes na AVL: " << opAvl << std::endl;
				std::cout << "Total de comparacoes na BST: " << opBst << std::endl;
				break;

			case 8:
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1) " << std::endl;
					break;
				}
				saveFile(avl);
				break;
			
			case 9:
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1) " << std::endl;
					break;
				}
//				std::string id, title, type, desc, release, age, runtime, genres, prod, seasons, imdbId, imdbScore, imbdVotes, tmbdPop, tmdbSc;
				std::cout << "Informe os dados do novo programa: " << std::endl;
				std::cout << "ID: "; std::cin >> stringArray[0];
				std::cout << "\nTitle: "; std::cin >> stringArray[1];
				std::cout << "\ntype: "; std::cin >> stringArray[2];
				std::cout << "\nTDescricao: "; std::cin >> stringArray[3];
				std::cout << "\nRelease Year: "; std::cin >> stringArray[4];
				std::cout << "\nAge: "; std::cin >> stringArray[5];
				std::cout << "\nRuntime: "; std::cin >> stringArray[6];
				std::cout << "\ngenres: "; std::cin >> stringArray[7];
				std::cout << "\nproductionCountries: "; std::cin >> stringArray[8];
				std::cout << "\nSeasons: "; std::cin >> stringArray[9];
				std::cout << "\nimdbID: "; std::cin >> stringArray[10];
				std::cout << "\nimdbScore: "; std::cin >> stringArray[11];
				std::cout << "\nimdbVotes: "; std::cin >> stringArray[12];
				std::cout << "\ntmdbPopularity: "; std::cin >> stringArray[13];
				std::cout << "\ntmdbScore: "; std::cin >> stringArray[14];

	            t->setId(stringArray[0]);
	            t->setTitulo(stringArray[1]);
	            t->setShowType(stringArray[2]);
	            t->setDescription(stringArray[3]);
	            t->setReleaseYear(stringArray[4]);
	            t->setAgeCertification(stringArray[5]);
	            t->setRuntime(stringArray[6]);
	            t->setGenres(stringArray[7]);
	            t->setProductionCountries(stringArray[8]);
	            t->setSeasons(stringArray[9]);
	            t->setImdbId(stringArray[10]);
	            t->setImdbScore(stringArray[11]);
	            t->setImdbVotes(stringArray[12]);
	            t->setTmdbPopularity(stringArray[13]);
	            t->setTmdbScore(stringArray[14]);
				
				opAvl = 0; opBst = 0;
				bst->inserir(t->getId(), t, ptrBst);
				avl->inserir(t, ptrAvl);
				
				std::cout << "Dados inseridos com sucesso!" << std::endl;
				std::cout << "Total de comparacoes na AVL: " << opAvl << std::endl;
				std::cout << "Total de comparacoes na BST: " << opBst << std::endl;
				break;
				
			case 10:
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1) " << std::endl;
					break;
				}
				
				std::cout << "Informe o id do titulo a ser pesquisado: ";
				std::cin >> pesquisar;
				
				std::cout << "avl(1) ou bst(2)?: ";  std::cin >> AB;
				opAvl = 0; opBst = 0;
				
				if(AB == 1){
					temp = avl->pesquisar(pesquisar, avl->getRoot(), ptrAvl);
					temp->getData()->print();
					std::cout << "Total de comparacoes na AVL: " << opAvl << std::endl;
				} else {
					bstNode = bst->pesquisar(pesquisar, bst->getRaiz(), ptrBst);
					bstNode->getData()->print();
					std::cout << "Total de comparacoes na BST: " << opBst << std::endl;
				}
				
				
				
				
				break;
				
			case 0:
				std::cout << "Encerrando programa..."<< std::endl;
				return true;
			
			default:
				std::cout << "Opcao invalida. Tenta novamente"<< std::endl;
		}
	return false;
}
