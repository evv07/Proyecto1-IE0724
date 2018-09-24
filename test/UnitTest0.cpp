//Prueba negativa. Se le da al programa un archivo de texto que no existe
//Se espera obtener el error

#include "../include/AvlTree.h"

int main(int argc, char** argv) {

	cout<<"\n----------***Inicio de la prueba***----------\n"<<endl;

	//Instancia de la clase AvlTree llamada Avl
	AvlTree Avl;

	//Se construye el arbol
    int c = Avl.AvlTree_Build("a.txt");

    //Se verifica el retorno de la función de construcción, para ver como finalizó
   	if(c==1){
    	cout<<"\n----------***PRUEBA EXITOSA***----------\n"<<endl;
   	}

    return 0;
}