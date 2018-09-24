#include "AvlTree.h"

//Constructur de clase AvlTree, no recibe parámetros
AvlTree::AvlTree(){

    root = NULL;
}

//Funcion que construye el arbol AVL y recibe como parámetro la locación del archivo a partir 
//del cual se va a construir el arbol
int AvlTree::AvlTree_Build(string file_location){

    //Variables temporales
    string St;
    string Temp;
    string stringTemp;
    int cont=0;
    int i=0;

    //Instancia de la clase AvlTree
    AvlTree A;

    //input_file es la instancia de la clase ifstream para operar sobre archivos
    ifstream input_file;

    //Se abre el archivo
    input_file.open(file_location);

    //Si el archivo no se puede abrir, salirse
    if (!input_file){
        cout << "No se pudo abrir el archivo, revise el programa"<<endl;
        return 1;
        exit(EXIT_FAILURE);
    }

    //Si sí se abrió, empiece a leerlo y a insertar los nodos al árbol
    while (getline(input_file,St)){//Mientras que hayan lineas por leer en el archivo

        //St es un string que contiene la linea del archivo
        stringstream ss(St);

        //Se parte cada linea y se separa lo que está antes y después de la coma, se guarda en variable Temp
        while (getline(ss,Temp, ',')){
               
            //En este "if" se guarda el nombre en una variable temporal stringtemp
            if(cont%2==0){
                stringTemp=Temp;

                size_t found= stringTemp.find_first_not_of(" AaBbCcDdEeFfGgHhIiJjKkLlMmNnÑñOoPpQqRrSsTtUuVvWwXxYyZz");
                if(found!=std::string::npos){
                    cout<<"\n*****************ERROR**********************\n"<<endl;
                    cout<<  "Ha ingresado un nombre que contiene un caracter invalido en la linea " <<i<<" del archivo de entrada,revise e intente de nuevo"<<endl;
                    cout<<"\n*****************ERROR**********************\n"<<endl;
                    return 2;
                    exit(EXIT_FAILURE);
                }
            }

            //En este if se inserta cada nuevo nodo, dandole como parametros el root, la cedula (Temp) y el nombre (StringTemp)

            else{
                size_t found= Temp.find_first_not_of(" 0123456789");
                if(found!=std::string::npos){
                    cout<<"\n*****************ERROR**********************\n"<<endl;
                    cout<<  "Ha ingresado una cedula que no contiene solo numeros en la linea " <<i<<" del archivo de entrada,revise e intente de nuevo"<<endl;
                    cout<<"\n*****************ERROR**********************\n"<<endl;
                    return 3;
                    exit(EXIT_FAILURE);
                }
                root = A.AvlTree_Insert(root, stoi(Temp), stringTemp, NULL);  
            }

            cont++;
        }

        i++;
    }

    return 0;

}

//Funcion que obtiene la altura maxima del arbol del root que se le ingrese
int AvlTree::get_max_height_left_sub_tree(Node* node){

    //Condicion de parada
    if(node==NULL){
        return 0;
    }

    //Se recorre el subárbol recursivamente y se devuelve la máxima altura
    else{
        return 1+max(  get_max_height_left_sub_tree(node->left_child),
                        get_max_height_left_sub_tree(node->right_child));
    }
}

//Funcion que obtiene la altura maxima del arbol del root que se le ingrese
int AvlTree::get_max_height_right_sub_tree(Node* node){
    //Condicion de parada
    if(node==NULL){
        return 0;
    }

    //Se recorre el subárbol recursivamente y se devuelve la máxima altura
    else{
        return 1+max(  get_max_height_right_sub_tree(node->left_child),
                        get_max_height_right_sub_tree(node->right_child));
    }
}


int AvlTree::LL_Rotation(Node* &Z, Node* &Y, Node* &X){

    //Se imprime el árbol antes de la rotación
	cout<<"\n***Avl antes de la rotacion LL***\n"<<endl;
	print_tree_in_order(root);

    //Se imprime quién es Z,Y y X
    cout<<"Z es "<<Z->id<<endl;
    cout<<"Y es "<<Y->id<<endl; 
    cout<<"X es "<<X->id<<endl; 

    //Declaración de dos nodos temporales
    Node *grandpa = Z->parent;
    Node *temp = Y->right_child;

    //Si el abuelo existe se fija si Z es su hijo izquierdo o derecho para que ahora Y lo sea
    if(grandpa){
        if(grandpa->right_child->id == Z->id){
            grandpa->right_child = Y;
            cout<<"Ahora el hijo derecho de "<<grandpa->id<<" es "<<Y->id<<endl;
        }

        if(grandpa->left_child->id == Z->id){
            grandpa->left_child = Y;
            cout<<"Ahora el hijo derecho de "<<grandpa->id<<" es "<<Y->id<<endl;
        }
    }

    //Asignaciones propias de la rotación
    Y->parent = grandpa;
    if(grandpa){
        cout<<"Ahora el papa de "<<Y->id<<" es "<<grandpa->id<<endl;
    }

    Y->right_child = Z;
    cout<<"Ahora el hijo derecho de "<<Y->id<<" es "<<Z->id<<endl;

    Z->parent = Y;
    cout<<"Ahora el papa de "<<Z->id<<" es "<<Y->id<<endl;

    Z->left_child = temp;

    //Si el hijo derecho de Y existe se le asigna el papá, 
    //sino no porque no se puede acceder a atributo de un punter nulo 
    if(temp){
       	cout<<"Ahora el hijo izquierdo de "<<Z->id<<" es "<<temp->id;
    	Z->left_child->parent = Z;
        cout<<"Ahora el papa de "<<Z->left_child->id<<" es "<<Z->id<<endl;
    }

    //Se actualiza los k de los nodos afectados con la rotación
    Node* t = X;
    while(t!=NULL){
        t->h_max_left_subtree = get_max_height_left_sub_tree(t->left_child);
        t->h_max_right_subtree = get_max_height_right_sub_tree(t->right_child);
        t->k = t->h_max_right_subtree - t->h_max_left_subtree; 
        t = t->parent;
    }

    Z->h_max_left_subtree = get_max_height_left_sub_tree(Z->left_child);
    Z->h_max_right_subtree = get_max_height_right_sub_tree(Z->right_child);
    Z->k = Z->h_max_right_subtree - Z->h_max_left_subtree; 

    //Se imprime el árbol después de la rotación
	cout<<"\n***Avl despues de la rotacion LL***\n"<<endl;
	print_tree_in_order(root);

}

int AvlTree::RR_Rotation(Node* &Z, Node* &Y, Node* &X){

    //Se imprime el árbol antes de la rotación
	cout<<"\n***Avl antes de la rotacion RR***\n"<<endl;
	print_tree_in_order(root);

    //Se imprime quién es Z,Y y X
    cout<<"Z es "<<Z->id<<endl;
    cout<<"Y es "<<Y->id<<endl; 
    cout<<"X es "<<X->id<<endl;

    //Declaración de dos nodos temporales
    Node *grandpa = Z->parent;
    Node *temp = Y->left_child;

    //Si el abuelo existe se fija si Z es su hijo izquierdo o derecho para que ahora Y lo sea
    if(grandpa){
        if(grandpa->right_child->id == Z->id){
            grandpa->right_child = Y;
            cout<<"Ahora el hijo derecho de "<<grandpa->id<<" es "<<Y->id<<endl;
        }

        if(grandpa->left_child->id == Z->id){
            grandpa->left_child = Y;
            cout<<"Ahora el hijo derecho de "<<grandpa->id<<" es "<<Y->id<<endl;
        }
    }


    //Asignaciones propias de la rotación
    Y->parent = grandpa;
    if(grandpa){
        cout<<"Ahora el papa de "<<Y->id<<" es "<<grandpa->id<<endl;
    }

    Y->left_child = Z;
    cout<<"Ahora el hijo izquierdo de "<<Y->id<<" es "<<Z->id<<endl;

    Z->parent = Y;
    cout<<"Ahora el papa de "<<Z->id<<" es "<<Y->id<<endl;

    Z->right_child = temp;


    //Si el hijo izquierdo de Y existe se le asigna el papá, 
    //sino no porque no se puede acceder a atributo de un punter nulo 
    if(temp){
       	cout<<"Ahora el hijo derecho de "<<Z->id<<" es "<<temp->id;
    	Z->left_child->parent = Z;
        cout<<"Ahora el papa de "<<Z->left_child->id<<" es "<<Z->id<<endl;
    }

    //Se actualiza los k de los nodos afectados con la rotación
    Node* t = X;
    while(t!=NULL){
        t->h_max_left_subtree = get_max_height_left_sub_tree(t->left_child);
        t->h_max_right_subtree = get_max_height_right_sub_tree(t->right_child);
        t->k = t->h_max_right_subtree - t->h_max_left_subtree; 
        t = t->parent;
    }

    Z->h_max_left_subtree = get_max_height_left_sub_tree(Z->left_child);
    Z->h_max_right_subtree = get_max_height_right_sub_tree(Z->right_child);
    Z->k = Z->h_max_right_subtree - Z->h_max_left_subtree; 

    //Se imprime el árbol después de la rotación
	cout<<"\n***Avl despues de la rotacion RR***\n"<<endl;
	print_tree_in_order(root);

}

int AvlTree::LR_Rotation(Node* Z, Node* Y, Node* X){

    //Se imprime el árbol antes de la rotación
    cout<<"\n***Avl antes de la rotacion LR***\n"<<endl;
    print_tree_in_order(root);

    //Primero se rota hacia la izquierda Y y X
	Node *temp = X->left_child;
	Z->left_child = X;
	X->parent = Z;
	X->left_child = Y;
	Y->parent = X;
	Y->right_child = temp;

    //Si X tiene hijo izquierdo se le asigna el papa,
    // sino no porque no se podria accesar el atributo de puntero nulo
	if(temp){
		X->left_child->parent = Y;
	}

    //Luego se procede a hacer una rotación LL
	LL_Rotation(Z,X,Y);

}
int AvlTree::RL_Rotation(Node* Z, Node* Y, Node* X){

    //Se imprime el árbol antes de la rotación
    cout<<"\n***Avl antes de la rotacion RL***\n"<<endl;
    print_tree_in_order(root);

    //Primero se rota hacia la derecha Y y X
	Node *temp = X->right_child;
	Z->right_child = X;
	X->parent = Z;
	X->right_child = Y;
	Y->parent = X;
	Y->left_child = temp;

    //Si X tiene hijo derecho se le asigna el papa,
    // sino no porque no se podria accesar el atributo de puntero nulo
    if(temp){
		X->right_child->parent = Y;
	}

    //Luego se procede a hacer una rotación RR
	RR_Rotation(Z,X,Y);


}


//Funcion que inserta los nuevos nodos leídos de la lista, llamada por la función AvlTree_Build
Node* AvlTree::AvlTree_Insert(Node* node, uint32_t new_id, string new_name, Node* father){
    //En este if es donde se crea el nodo
    if(node == NULL){

        node = new Node;
        node->id = new_id;
        cout<<"se creó el nodo con identificacion "<<node->id<<endl;
        node->name = new_name;
        node->right_child = NULL;
        node->left_child = NULL;
        node->parent = father;

        //Calculo de las alturas y el k
        node->h_max_left_subtree = get_max_height_left_sub_tree(node->left_child);
        node->h_max_right_subtree = get_max_height_right_sub_tree(node->right_child);
        node->k = node->h_max_right_subtree - node->h_max_left_subtree; 
        cout<<"Nodo= "<<node->id<<" k= "<<node->k<<endl;

        //Se mete el nodo al deque
        mydeque.push_front(node);

    }

    //Si la cedula del nodo a ingresar es menor a la del nodo actual
    else if(new_id<node->id){

        cout<<new_id<<" es menor que " <<node->id <<endl;//debug***
        node->left_child = AvlTree::AvlTree_Insert(node->left_child, new_id, new_name, node);

        //Calculo de las alturas y el k        
        node->h_max_left_subtree = get_max_height_left_sub_tree(node->left_child);
        node->h_max_right_subtree = get_max_height_right_sub_tree(node->right_child);
        node->k = node->h_max_right_subtree - node->h_max_left_subtree; 
        cout<<"Nodo= "<<node->id<<" k= "<<node->k<<endl;

        //Se mete el nodo al deque
        mydeque.push_front(node);

    }

    //Si la cedula del nodo a ingresar es mayor a la del nodo actual
    else if(new_id>node->id){

        cout<<new_id<<" es mayor que " <<node->id <<endl;//debug***
        node->right_child = AvlTree::AvlTree_Insert(node->right_child, new_id, new_name,node);
        node->right_child->parent = node;

        //Calculo de las alturas y el k        
        node->h_max_left_subtree = get_max_height_left_sub_tree(node->left_child);
        node->h_max_right_subtree = get_max_height_right_sub_tree(node->right_child);///
        node->k = node->h_max_right_subtree - node->h_max_left_subtree; 
        cout<<"Nodo= "<<node->id<<" k= "<<node->k<<endl;

        //Se mete el nodo al deque
        mydeque.push_front(node);
    }

    //En este condicional se evalúa si el nodo actual es un nodo infractor
    if(node->k && abs(node->k)>=2){
        if((node->left_child!=NULL &&abs(node->left_child->k)>=2) ||
           (node->right_child!=NULL &&abs(node->right_child->k)>=2)) {

        }
        else{

            cout<<"el primer nodo infractor es: " <<node->id<<endl;

            //root va a ser el primer nodo ingresado al deque
            root = mydeque.back(); 

            //Z va a ser el ultimo nodo ingresado al deque
        	Node *Z = mydeque.front();
            //Se saca Z del deque
        	mydeque.pop_front(); 

            //Y va a ser penultimo nodo ingresado al deque
        	Node *Y = mydeque.front();
            //Se saca Y del deque
        	mydeque.pop_front(); 

            //X va a ser el antepenultimo nodo ingresado al deque
        	Node *X = mydeque.front();
            //Se saca X del deque
        	mydeque.pop_front(); 

            //Se limpia el deque
        	mydeque.clear(); 

            //Condicional que evalua si la rotación debe ser LL
            //   Z
            //  Y
            // X
        	if(((Z->left_child)&&(Z->left_child->id == Y->id)) && 
        		(Y->left_child)&&(Y->left_child->id == X->id)){  

        			cout<<"Ocupamos hacer una rotacion LL"<<endl;
                    LL_Rotation(node, node->left_child, node->left_child->left_child);
                }

            //Condicional que evalua si la rotación debe ser RR
            //Z
            // Y
            //  X
        	if(((Z->right_child)&&(Z->right_child->id == Y->id)) && 
        		(Y->right_child)&&(Y->right_child->id == X->id)){

        		  cout<<"Ocupamos hacer una rotacion RR"<<endl;	    
                    RR_Rotation(node, node->right_child, node->right_child->right_child);
        	}

            //Condicional que evalua si la rotación debe ser LR
            //   Z
            //  Y
            //   X
        	if(((Z->left_child)&&(Z->left_child->id == Y->id)) && 
        		(Y->right_child)&&(Y->right_child->id == X->id)){ 

        		cout<<"Ocupamos hacer una rotacion LR"<<endl;
        			LR_Rotation(node,node->left_child,node->left_child->right_child);
        	}

            //Condicional que evalua si la rotación debe ser RL
            //   Z
            //    Y
            //   X
        	if(((Z->right_child)&&(Z->right_child->id == Y->id)) &&  
        		(Y->left_child)&&(Y->left_child->id == X->id)){	   

        		cout<<"Ocupamos hacer una rotacion RL"<<endl;
        			RL_Rotation(node,node->right_child,node->right_child->left_child);
        	
        	}
        }
    }
    
    return node;
}

//Impresion recursiva donde va primero el nodo, luego el hijo izquierdo y luego el derecho
int AvlTree::print_tree_pre_order(Node* node){ 
                                                
    if(node!=NULL){
        cout<<node->id<<endl;
        print_tree_pre_order(node->left_child);
        print_tree_pre_order(node->right_child);
    }

    return 0;
}

//Impresion recursiva donde va primero el hijo izquierdo, luego el nodo, luego el hijo derecho
//Esta es la impresión utilizada porque da el arbol en orden ascendente
int AvlTree::print_tree_in_order(Node* node){

    if(node!=NULL){
        print_tree_in_order(node->left_child);
        cout<<"id = "<<node->id<<"\t"/*<<node->h_max_left_subtree << "/" <<
        node->h_max_right_subtree*/<< "k=" << node->k<<"\t";

        if(node->parent!=NULL){
            cout<<"Es el hijo";

            if(node->parent->left_child!=NULL){

                if(node->id == node->parent->left_child->id){
                    cout<<" izquierdo de ";
                }
            }

            if(node->parent->right_child!=NULL){

                if(node->id == node->parent->right_child->id){
                    cout<<" derecho de ";
                }
            }
        }

        if(node->parent ==NULL){
            cout<<"\tNULL"<<endl;
        }

        else{
            cout<<" "<<node->parent->id<<endl;
        }

        print_tree_in_order(node->right_child);
    }

    return 0;
}

//Impresion recursiva donde va primero el hijo izquierdo , luego el nodo y luego el hijo derecho
int AvlTree::print_tree_post_order(Node* node){
    if(node!=NULL){
        print_tree_post_order(node->left_child);
        print_tree_post_order(node->right_child);
        cout<<node->id<<endl;
    }

    return 0;
}


//Desctructor clase AvlTree
AvlTree::~AvlTree() {

}