//Prueba negativa. Se le da al programa un archivo de texto que contiene
//una cedula que no contiene solo numeros, se espera error y que el programa
//despliegue qué error fue y en qué línea lo encontró

#include "../include/AvlTree.h"

int main(int argc, char** argv) {

	cout<<"\n----------***Inicio de la prueba***----------\n"<<endl;

	//Instancia de la clase AvlTree llamada Avl
	AvlTree Avl;

	//Se construye el arbol
    int c = Avl.AvlTree_Build("../misc/input_unit_tests/UnitTest2.txt");

    //Se verifica el retorno de la función de construcción, para ver como finalizó
   	if(c==3){
    	cout<<"\n----------***PRUEBA EXITOSA***----------\n"<<endl;
   	}

    return 0;
}