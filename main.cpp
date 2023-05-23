#include "main.h"

int main(){
    ArvoreBST *bst = new ArvoreBST();
    ArvoreAVL *avl = new ArvoreAVL();
    
 	menu(avl, bst);
	
    delete bst;
	bst = NULL;
    delete avl;
    avl = NULL;
    return 0;
}