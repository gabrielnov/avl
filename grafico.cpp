#include "grafico.h"

void plot(ArvoreAVL *avl){
    int notas[11];

	for (int i = 0; i <= 10; i++){
		notas[i] = 0;
	}
	// caractere que sera usado para plotar as barras do grafico
	char m = ']';
    int total = 0, space = 6;
	std::string traco;

    avl->analise7(avl->getRoot(), notas, &total);

    std::cout << "Total de registros: " << total << "\n\n";
    
	// usado para encontrarmos a proporcao correta do grafico
    int div = 10;

	// imprimos cada faixa de acordo com a sua quantidade
	std::cout << std::setw(5) << ' ' << "nota" << std::endl;	
	std::cout << std::setw(space) << ' ' << " ^ " << std::endl;	
	std::cout << std::setw(space) << ' ' << " | " << std::endl;

	for ( int i = 0; i <= 10; i++){
		std::cout << std::setw(space) << ' ' << " | " << std::endl;
		std::cout << std::setw(space) <<  i << " | ";

		for (int j = 0; j < limit(notas[i], div) ; j++)
			std::cout << m;
			
		if (notas[i]!=0) 
			std::cout << " " << notas[i];
		std::cout << std::endl;
	}


	std::cout << std::setw(space) << ' ' << " | \n ";

	traco = repeat("-", 113);
	std::cout << traco << "> total"<< std::endl;	
	
	std::cout << std::setw(space) << ' ' << " | ";
	std::cout << std::setw(3) << ' ' << "50 ";

	for (int i = 100; i <= 1000; i+=50){
		std::cout << std::setw(2) << ' ' << i;
	}
}

std::string repeat(std::string s, int n) {
  std::string repeat;

  for (int i = 0; i < n; i++)
    repeat += s;

  return repeat;
}

int limit(float total, int div){
	if (total == 0) return 0;

	float r = total/div;
	
	if (r < 1) return 1;
	return r;
}
