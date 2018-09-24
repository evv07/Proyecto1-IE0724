//Prueba negativa. Se le da al programa un archivo de texto que contiene
//un nombre que no contiene solo letras, se espera error y que el programa
//despliegue qué error fue y en qué línea lo encontró

#include "../include/AvlTree.h"

int main(int argc, char** argv) {

	cout<<"\n----------***Inicio de la prueba***----------\n"<<endl;

	//Instancia de la clase AvlTree llamada Avl
	AvlTree Avl;

	//Se construye el arbol
    int c = Avl.AvlTree_Build("../misc/input_unit_tests/UnitTest1.txt");

    //Se verifica el retorno de la función de construcción, para ver como finalizó
    if(c==2){
    	cout<<"\n----------***PRUEBA EXITOSA***----------\n"<<endl;
    }
    return 0;
}