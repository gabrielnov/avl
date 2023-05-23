#include "menu.h"

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
		<< "[2] Analise A - Comparar cargos\n"
		<< "[3] Analise B - Analise de unidades\n"
		<< "[4] Analise C - Estatisticas gerais\n"
		<< "[5] Analise D - Analise de funcionario(a)\n"
		<< "[6] Analise E - Distribuicao de salarios\n"
		<< "[7] Remover funcionario(a)\n"
		<< "[8] Salvar dados\n"
		<< "[9] Limpar a arvore\n"
		<< "[0] Encerrar\n\n"
		<< "Digite a opcao: ";		
}

bool readOption(int opt, ArvoreAVL* avl, ArvoreBST* bst, bool* fileRead){
	std::string titulo;
    BSTNode *respBST;

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
				// analise 1
				break;
			case 3:
			if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1)";
					break;
				}
				// analise 2
				break;
			case 4:
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1)";
					break;
				}
				// analise 3
				break;
			case 5:
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1)";
					break;
				}
				// analise 4
				break;
			case 6:
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1)" << std::endl;
					break;
				}
                //  analise 5
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
			case 9:
				if (!*fileRead){
					std::cout << "Necessario ler os dados primeiro (opcao 1) " << std::endl;
					break;
				}
				bst->auxLimpar();
				std::cout << "Arvore limpa com sucesso!" << std::endl;
				break;
			case 0:
				std::cout << "Encerrando programa..."<< std::endl;
				return true;
			
			default:
				std::cout << "Opcao invalida. Tenta novamente"<< std::endl;
		}
	return false;
}