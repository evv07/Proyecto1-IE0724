/*Definición de funciones de la clase Node*/
#include "Node.h"

//Constructor de la clase Node que no recibe parametros, inicializa los valores de los atributos
Node::Node(){

    parent = 0x0;
    left_child = 0x0;
    right_child = 0x0;
    name = " ";
    id = 0;
    h_max_left_subtree =0 ;
    h_max_right_subtree = 0;
    k = 0;
}

//Constructor de copia de la clase Node
Node::Node(const Node &N){

    parent = N.parent;
    left_child = N.left_child;
    right_child = N.right_child;
    name = N.name;
    id = N.id;
    h_max_left_subtree = N.h_max_left_subtree;
    h_max_right_subtree = N.h_max_right_subtree;
    k = N.k;
}

//Constructor de la clase Node que recibe parametros
Node::Node(Node* parent, u_int32_t id, string name, u_int16_t k){
    
    parent = parent;
    id = id;
    name = name;
    k = k;
}

//Destructor de la clase Node
Node::~Node(){

}








