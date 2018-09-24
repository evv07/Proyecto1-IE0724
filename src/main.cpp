#include "../include/AvlTree.h"
using namespace std;
#include <cstdlib>

int main(int argc, char** argv) {

	//Se crea una instancia de la clase AvlTree llamada Avl
	AvlTree Avl;

	//Se construye el arbol Avl
    int c = Avl.AvlTree_Build("../misc/input/lista_10.txt");

    switch(c){
    	case 0 : cout<<"\n***\nEl programa se ha finalizado con normalidad\n***\n";
    	break;
    	case 1 : cout<<"\n***\nHubo un error, no se pudo abrir el archivo\n***\n";
    	break;
    	case 2 : cout<<"\n***\nHubo un error, uno de los nombres tiene caracter inválido\n***\n";
    	break;
    	case 3 : cout<<"\n***\nHubo un error, uno de las cedulas tiene caracter invalido\n***\n";
    	break;
    }

    //Se imprime el arbol 
    /*cout<<"****Impresión en orden****"<<endl;
    Avl.print_tree_in_order(Avl.root);*/

    return 0;
}