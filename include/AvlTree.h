/*Encabezado de la clase AvlTree*/
#include "Node.h" //Se incluye la clase Node
#ifndef AVLTREE_H
#define AVLTREE_H
#include <fstream> //Clase para operar sobre archivos
#include <sstream> //Clase para operar sobre "strings"
using namespace std; //para escribir "cout" en vez de "std::cout", etcetera
#include <cmath>  //Para realizar operaciones matemáticas como abs()
#include<deque> //Clase deque

//Inicio de la clase AvlTree
class AvlTree{
	
public:

	//Atributo puntero a la raíz del árbol
	Node* root; 

	 //Atributo deque "cola especial" que permite saber qué camino de nodos se recorre al buscar un nodo infractor
    deque<Node*> mydeque;

    //Constructor de la clase AvlTree
	AvlTree(); 

	//Funcion que inserta cada nodo al árbol
	Node* AvlTree_Insert(Node* node, uint32_t id, string nombre, Node* parent); 

	//Funcion que recibe la locación del archivo de texto y construye el arbol a partir de inserts
	//Devuelve 
	//0 si la función termina con éxito
	//1 si la función no puede abrir el archivo que se le brindó ERROR
	//2 si la función encontró un nombre que no contiene solamente letras ERROR
	//3 si la función encontró una cedula que no contiene solamente numeros o espacios ERROR

	int AvlTree_Build(string file_location); 

	//Funcion recursiva para imprimir el arbol primero root luego hijo izquierdo luego hijo derecho										 
	int print_tree_pre_order(Node* root);

	//Funcion recursiva para imprimir el arbol primero hijo izquierdo luego root luego hijo derecho
	//Es la que se utilizó porque imprime el árbol en orden ascendente										 
	int print_tree_in_order(Node* root);

	//Funcion recursiva para imprimir el arbol primero hijo izquierdo luego hijo derecho luego root									 
	int print_tree_post_order(Node* root);

	//Funcion que encuentra la altura máxima del subárbol izquierdo
	int get_max_height_left_sub_tree(Node* node);

	//Funcion que encuentra la altura máxima del subárbol derecho
	int get_max_height_right_sub_tree(Node* node);

	//Funcion rotación LL
	int LL_Rotation(Node* &Z, Node* &Y, Node* &X);

	//Funcion rotación RR
	int RR_Rotation(Node* &Z, Node* &Y, Node* &X);

	//Funcion rotación LR
	int LR_Rotation(Node* Z, Node* Y, Node* X);

	//Funcion rotación RL
	int RL_Rotation(Node* Z, Node* Y, Node* X);

	//Destructor de la clase AvlTree
    virtual ~AvlTree();

private:

};

#endif /* AVLTREE_H */