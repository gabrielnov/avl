#include "file.h"

void readFile(ArvoreBST *bst, ArvoreAVL *avl){
	std::string nome, cargoBase, cargoComissao, unidade, caminho;
    float salarioBruto;
	int opAvl = 0, opBst = 0;
	
	int *ptrAvl = &opAvl, *ptrBst = &opBst;

	std::cout << "Informe o caminho do arquivo a ser lido: ";
	std::cin >> caminho;

	std::cout << "abrindo arquivo " << caminho << "... " << std::endl;

	std::fstream f;
    f.open(caminho, std::ios::in); 
    
	// verificamos se o arquivo realmente existe
	if (!f){
		std::cout << "!!! O arquivo informado nao existe. Tente novamente. !!!" << std::endl;
		readFile(bst, avl);
	}

    std::string line;
	std::string stringArray[15] = {};

	std::cout << "lendo linhas do arquivo " << caminho << "... " << std::endl;

    getline(f, line);

    if (f.is_open()){
	    while(getline(f, line) && line != ""){
	    	substring(line, stringArray);
			
			if (stringArray[0].size() < 3){
				continue;
			}

	    	Title *t = new Title();

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
	    	
			bst->inserir(t->getId(), t, ptrBst);
			avl->inserir(t, ptrAvl);
	    }

	f.close();
	}

	std::cout << "Dados lidos com sucesso!" << std::endl;
	std::cout << "Total de comparacoes na AVL: " << opAvl << std::endl;
	std::cout << "Total de comparacoes na BST: " << opBst << std::endl;
}

// substring inclui os campos do csv em um de string que ser� usado para construir uma instancia de Pessoa
void substring(std::string s, std::string v[15]){
	int j = 0;
	std::string aux;
	
	for(int i = 0; i < COLUMNS; i++){

		while (s[j] != ';' && j < s.size()){
			aux.push_back(s[j]);
			j++;
		}
		
		v[i] = aux;
		aux = "";
		j++;
	}
}

void escreverLinha(AVLNode* no, std::fstream *f)
{
    if(no != NULL)
    {
        escreverLinha(no->getLeft(), f);
        
		*f << no->getData()->getId() << ","
		<< no->getData()->getTitulo() << ","
		<< no->getData()->getShowType() << ","
		<< no->getData()->getDescription() << ","
		<< no->getData()->getReleaseYear() << ","
		<< no->getData()->getAgeCertification() << ","
		<< no->getData()->getRuntime() << ","
		<< no->getData()->getGenres() << ","
		<< no->getData()->getProductionCountries() << ","
		<< no->getData()->getSeasons() << ","
		<< no->getData()->getImdbId() << ","
		<< no->getData()->getImdbScore() << ","
		<< no->getData()->getImdbVotes() << ","
		<< no->getData()->getTmdbPopularity() << ","
		<< no->getData()->getTmdbScore();
		
		
        escreverLinha(no->getRight(), f);
    }
}

void saveFile(ArvoreAVL *avl){
    std::string caminho;
    std::fstream f;
	
	std::cout << "Informe o caminho do arquivo a ser salvo: ";
	std::cin >> caminho;

	f.open(caminho, std::ofstream::out | std::ofstream::trunc);	
	
	f << "id,title,show_type,release_year,age_certification"
    << "run_time,genres,\n";
	
	std::cout << "escrevendo linhas no arquivo " << caminho << "..." << std::endl;
	escreverLinha(avl->getRoot(), &f);
    
    f.close();
    
    std::cout << "Dados gravados com sucesso!" << std::endl;
}
