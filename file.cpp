#include "file.h"

void readFile(ArvoreBST *bst, ArvoreAVL *avl){
	std::string nome, cargoBase, cargoComissao, unidade, caminho;
    float salarioBruto;

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

			//algumas linhas possuem o valor em branco ou inválido, isso causa exceção na conversão
			try{
				// stringArray[6].erase(std::remove(stringArray[6].begin(), stringArray[6].end(), '.'), stringArray[6].end());
				// std::replace(stringArray[6].begin(), stringArray[6].end(), ',', '.');
				// salarioBruto = std::stof(stringArray[6]);
			} 
			catch( ... ){
				salarioBruto = 0.0;
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
	    	
			bst->inserir(nome, t);
	    }

	f.close();
	}
	
	std::cout << "Dados lidos com sucesso!" << std::endl;
}

// substring inclui os campos do csv em um de string que será usado para construir uma instancia de Pessoa
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

void escreverLinha(Node* no, std::fstream *f)
{
    if(no != NULL)
    {
        escreverLinha(no->getEsq(), f);
        
		*f << no->getTitulo()->getId() << ","
		<< no->getTitulo()->getTitulo() << ","
		<< no->getTitulo()->getShowType() << ","
		<< no->getTitulo()->getDescription() << ","
		<< no->getTitulo()->getReleaseYear() << ","
		<< no->getTitulo()->getAgeCertification() << ","
		<< no->getTitulo()->getRuntime() << ","
		<< no->getTitulo()->getGenres() << ","
		<< no->getTitulo()->getProductionCountries() << ","
		<< no->getTitulo()->getSeasons() << ","
		<< no->getTitulo()->getImdbId() << ","
		<< no->getTitulo()->getImdbScore() << ","
		<< no->getTitulo()->getImdbVotes() << ","
		<< no->getTitulo()->getTmdbPopularity() << ","
		<< no->getTitulo()->getTmdbScore();
		
		
        escreverLinha(no->getDir(), f);
    }
}

void saveFile(ArvoreBST *bst){
    std::string caminho;
    std::fstream f;
	
	std::cout << "Informe o caminho do arquivo a ser salvo: ";
	std::cin >> caminho;

	f.open(caminho, std::ofstream::out | std::ofstream::trunc);	
	
	f << "id,title,show_type,release_year,age_certification"
    << "run_time,genres,\n";
	
	std::cout << "escrevendo linhas no arquivo " << caminho << "..." << std::endl;
	escreverLinha(bst->getRaiz(), &f);
    
    f.close();
    
    std::cout << "Dados gravados com sucesso!" << std::endl;
}
