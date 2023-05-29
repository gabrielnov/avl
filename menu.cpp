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
		<< "[0] Encerrar\n\n"
		<< "Digite a opcao: ";		
}

bool readOption(int opt, ArvoreAVL* avl, ArvoreBST* bst, bool* fileRead){
	std::string titulo;
    BSTNode *respBST;
	std::string id1, id2, pais, year1, year2;
	int AB = 0;
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


				respBST = bst->excluir(bst->getRaiz(), titulo);
                bst->setRaiz(respBST);

                avl->remove(titulo);
				
				std::cout << "Titulo " << titulo << " removido(a) com sucesso!" << std::endl;
				break;

			case 8:
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1) " << std::endl;
					break;
				}
				saveFile(avl);
				break;
			
			case 0:
				std::cout << "Encerrando programa..."<< std::endl;
				return true;
			
			default:
				std::cout << "Opcao invalida. Tenta novamente"<< std::endl;
		}
	return false;
}
