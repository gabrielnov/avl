 #ifndef __NODE_H__
#define __NODE_H__

#include <string>
#include "title.h"

class Node
{
private:
    Node *esq, *dir;
    std::string chave;
    Title *title;

public:
	Node(){
		this->chave = " ";
		this->title = new Title();
		esq = NULL;
		dir = NULL;
	}
    Node(std::string chave, Title *p)
    {
        this->chave = chave;
        this->title = p;
        esq = NULL;
        dir = NULL;
    }
    Title* getTitulo(){return this->title;}
    std::string getChave(){return chave;}
    Node* getEsq(){return esq;}
    Node* getDir(){return dir;}
   
    void setEsq(Node *no){esq = no;}
    void setDir(Node *no){dir = no;}
    void setChave(std::string k){chave = k;}
};

#endif
