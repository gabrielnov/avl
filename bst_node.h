#ifndef __NODE_H__
#define __NODE_H__

#include <string>
#include "title.h"

class BSTNode
{
private:
    BSTNode *esq, *dir;
    std::string chave;
    Title *title;

public:
	BSTNode(){
		this->chave = " ";
		this->title = new Title();
		esq = NULL;
		dir = NULL;
	}
    BSTNode(std::string chave, Title *p)
    {
        this->chave = chave;
        this->title = p;
        esq = NULL;
        dir = NULL;
    }
    Title* getData(){return this->title;}
    std::string getChave(){return chave;}
    BSTNode* getEsq(){return esq;}
    BSTNode* getDir(){return dir;}
   
    void setEsq(BSTNode *no){esq = no;}
    void setDir(BSTNode *no){dir = no;}
    void setChave(std::string k){chave = k;}
};

#endif
