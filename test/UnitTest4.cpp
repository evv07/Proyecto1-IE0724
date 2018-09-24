//Prueba positiva, se le da un archivo al programa para que cree
//5 nodos válidos y prueba la rotación RR, se espera que el programa
//termine con éxito

#include "../include/AvlTree.h"

int main(int argc, char** argv) {

	cout<<"\n----------***Inicio de la prueba***----------\n"<<endl;

	//Instancia de la clase AvlTree llamada Avl
	AvlTree Avl;

	//Se construye el arbol
    int c = Avl.AvlTree_Build("../misc/input_unit_tests/UnitTest4.txt");

    //Se verifica el retorno de la función de construcción, para ver como finalizó
   	if(c==0){
    	cout<<"\n----------***PRUEBA EXITOSA***----------\n"<<endl;
   	}

    return 0;
}