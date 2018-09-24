/* Encabezados de la clase Node*/

#ifndef NODE_H
#define NODE_H
#include <cstdint> //Biblioteca que provee tipos de entero de tamaño específico
#include <string.h> //Para manipulación de arreglos de caracteres
#include <iostream> //Biblioteca que define objetos estándar de entrada y salida
using namespace std; //para escribir "cout" en vez de "std::cout", etcetera

//Inicio de la clase Node
class Node {
    
public:

    //Atributo: Puntero al padre de cada Node
    Node* parent; 

    //Atributo: Puntero al hijo izquierdo de cada Node
    Node* left_child; 

    //Atributo: Puntero al hijo derecho de cada Node
    Node* right_child; 

    //Atributo: Nombre de cada Node
    string name; 

    //Atributo: Identificacion de cada Node
    uint32_t id; 

    //Atributo: Altura maxima del sub-arbol izquierdo del Node
    uint16_t h_max_left_subtree; 

    //Atributo: Altura maxima del sub-arbol derecho del Node
    uint16_t h_max_right_subtree; 

    //Atributo: Altura maxima del sub-arbol derecho del Node - //Altura maxima del sub-arbol izquierdo del Node
    int k; 

    //Contructor de la clase Node
    Node(); 
    
    //Constructor de copia de la clase Node
    Node(const Node &N); 

    //Constructor que recibe ciertos parámetros de atributo del Node
    Node(Node* parent, u_int32_t id, string name, uint16_t k);

    //Destructor de la clase Node
    virtual ~Node();
   
private:

};

#endif /* NODE_H */
