//
//#include <iostream>
//#include <cstring>
//#include "List.h"
//
//using namespace std;
///**
// * @brief Metodo constructor de List con sus atributos inicializados NULL
// *
// *
// */
//List::List()
//{
//    first_node = NULL;
//    last_node = NULL;
//}
///**
// * @brief Metodo constructor de List
// *@param *first_node puntero por la cabeza
// *@param *last_node puntero por la cola
// *
// */
//List::List(Node* firstNode, Node* lastNode)
//{
//    first_node = firstNode;
//    last_node = lastNode;
//}
//
///**
// * @brief metodo getter del nodo por la cabeza
// *
// *
// */
//Node* List::getFirstNode()
//{
//    return first_node;
//}
//
///**
// * @brief metodo getter del nodo por la cola
// *
// *
// */
//Node* List::getLastNode()
//{
//    return last_node;
//}
//
///**
// * @brief metodo setter del nodo por la cabeza
// *
// *
// */
//void List::setFirstNode(Node* firstNode)
//{
//    first_node = firstNode;
//}
//
///**
// * @brief metodo setter del nodo por la cola
// *
// *
// */
//void List::setLastNode(Node* lastNode)
//{
//    last_node = lastNode;
//}
//
///**
// * @brief metodo verifica si la lista esta o no vacia
// *@param List_ la lista a evaluar
// *
// */
//bool List::verify(List* List_)
//{
//    if (List_->getFirstNode() == NULL) {
//        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
//        cout << "\n\t    La lista esta vacia\n" << endl;
//        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//        return false;
//    }
//    else {
//        return true;
//    }
//}
//
///**
// * @brief metodo almacena espacion de memoria y crea un nuevo nodo en la lista
// *@param data es el valor que va a almacenar el nodo creado
// *
// */
//Node* List::createNode(Person client_)
//{
//    Node* node_ = new Node(); //Reserva memoria para 1 nodo
//    if (node_ != NULL) {
//        node_->setDataClient(client_);
//        node_->setNext(NULL);
//        cout << "\n\t   Cliente: " << node_->getDataClient().get_name();
//    }
//    return node_;
//}
//
///**
// * @brief metodo que crea un nuevo nodo al final de la lista
// *@param List_ la lista que vamos a recorrer
// *@param data es el valor que va a almacenar el nodo creado
// *
// */
//List* List::add_at_the_end(List* List_, Person client_) //Final
//{
//    Node* node_ = new Node(client_, NULL);
//    if (node_ != NULL)
//    {
//        if (List_->getFirstNode() != NULL) {
//            List_->getLastNode()->setNext(node_);
//            List_->setLastNode(node_);
//            cout << "\n\t   Datos ingresados de : " << node_->getDataClient().get_name() << endl;
//            return List_;
//        }
//        else { //Lista esta vacia
//            List* empty_list = new List(NULL, NULL);
//            empty_list->setFirstNode(node_);
//            empty_list->setLastNode(node_);
//            cout << "\n\t   Datos ingresados de : " << node_->getDataClient().get_name() << endl;
//            return empty_list;
//        }
//    }
//    else {
//        return NULL;
//    }
//}
//
///**
// * @brief metodo que realiza operaciones matematicas con los valores que almacenan los nodos de la lista
// *@param List_ la lista que vamos a recorrer
// *
// */
//
//void List::operations(List* List_)
//{
//    cout << "Operations";
//    /*
//    Node* node_ = List_->getFirstNode();
//    if (node_ != NULL)
//    {
//        int sum = 0;
//        int length = size_List(List_);
//        int counter = 0;
//        float average;
//        while (node_ != NULL)
//        {
//            sum = sum + node_->getData();
//            node_ = node_->getNext();
//            counter++;
//        }
//        printf("Suma de los elementos :%d\n", sum);
//        average = (float)sum / (float)counter;
//        printf("El promedio es:%f\n", average);
//        int* chain = NULL;
//        chain = new int[counter];
//        counter = 0;
//        node_ = List_->getFirstNode();
//        while (node_ != NULL)
//        {
//            chain[counter] = node_->getData();
//            node_ = node_->getNext();
//            counter++;
//        }
//        int new_counter = counter;
//        int s = 0, m = 0, a;
//        //m = s;
//
//        for (int i = 0; i < new_counter; i++) {
//            s = 0;
//            for (int j = 0; j < new_counter; j++) {
//                if (chain[i] == chain[j] && i != j)
//                {
//                    s = s + 1;
//                }
//            }
//            if (s >= m) {
//                m = s;
//                a = i;
//            }
//        }
//
//        cout << "la moda es: " << chain[a] << " y tiene " << m + 1 << " repeticiones" << endl;
//    }
//
//    else {
//        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
//        cout << "\n\t    La lista esta vacia\n" << endl;
//        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//
//    }
//    */
//}
//
///**
// * @brief metodo que crea un nuevo nodo al inicio de la lista
// *@param List_ la lista que vamos a recorrer
// *@param data es el valor que va a almacenar el nodo creado
// *
// */
//
//List* List::add_to_start(List* List_, Person client_)
//{
//    Node* node_ = new Node(client_, NULL);
//    if (node_ != NULL)
//    {
//        if (List_->getFirstNode() != NULL) {
//            node_->setNext(List_->getFirstNode());
//            List_->setFirstNode(node_);
//            cout << "\n\t   Datos ingresados de : " << node_->getDataClient().get_name() << endl;
//            return List_;
//        }
//        else {
//            List* active_list = new List(NULL, NULL);
//            active_list->setFirstNode(node_);
//            active_list->setLastNode(node_);
//            cout << "\n\t   Datos ingresados de : " << node_->getDataClient().get_name() << endl;
//            return active_list;
//        }
//    }
//    else {
//        return NULL;
//    }
//}
//
///**
// * @brief metodo que imprime los nodos y los valores de la lista
// *@param List_ la lista que vamos a recorrer
// *
// *
// */
//void List::print(List* List_)
//{
//    int counter = 1;
//    if (verify(List_)) {
//        Node* node_ = List_->getFirstNode();
//        do {
//            cout << "\n\t\tNodo " << counter << ": " << node_->getDataClient().get_name() << endl;
//            node_ = node_->getNext(); //Instruccion para moverme al siguiente
//            counter++;
//        } while (node_ != NULL);
//    }
//}
//
///**
// * @brief metodo que elimina el valor de un nodo
// *@param List_ la lista que vamos a recorrer
// *
// *
// */
//List* List::deleteNode(List* List_)
//{
//    int option;
//    if (verify(List_))
//    {
//        Node* node_ = List_->getFirstNode();
//        cout << "\n\tSe eliminaran los datos del cliente:  -> " << node_->getDataClient().get_name() << ". Desea continuar? \n\t1-SI / 0-NO: ";
//        cin >> option;
//        if (option == 1)
//        {
//            List_->setFirstNode(node_->getNext());
//            delete node_;
//            cout << "\n\tSe elimino el nodo" << endl;
//            if (List_->getFirstNode() == NULL)
//            {
//                delete List_;
//                //L = NULL;
//                List_->setLastNode(NULL);
//                cout << "\n\tSe elimino el ultimo elemento de la lista." << endl;
//                return List_;
//            }
//        }
//    }
//    return List_;
//}
//
///**
// * @brief metodo que busca entre una lista con desorden
// *@param List_ la lista que vamos a recorrer
// *@param searcher el valor que buscamos
// *
// */
//Node* List::searchDisorder(List* List_, string searcher)
//{
//    Node* node_ = NULL;
//    if (List_->getFirstNode() != NULL)
//    {
//        node_ = List_->getFirstNode();
//        while (node_ != NULL && node_->getDataClient().get_name() != searcher)
//        {
//            node_ = node_->getNext();
//        }
//    }
//    return node_;
//}
//
///**
// * @brief metodo que busca un dato almacenado en un nodo de la lista
// *@param List_ la lista que vamos a recorrer
// *@param searcher es el valor que buscamos
// *
// */
//void List::search(List* List_, string searcher)
//{
//    Node* node_ = new Node();
//    node_ = List_->searchDisorder(List_, searcher);
//    if (node_ != NULL)
//    {
//        cout << "\n\t> Dato encontrado\n" << endl;
//    }
//    else
//    {
//        cout << "\n\t> Dato no encontrado\n" << endl;
//    }
//    cout << endl;
//}
//
///**
// * @brief metodo que muestra el tamanio de la lista
// *@param List_ la lista que vamos a recorrer
// *
// *
// */
//int List::size_List(List* List_)
//{
//    int counter = 1;
//    if (List_->getFirstNode() != NULL) {
//        Node* node_ = List_->getFirstNode();
//        do {
//            node_ = node_->getNext();
//            counter++;
//        } while (node_ != NULL);
//        return counter;
//    }
//    else {
//        return 0;
//    }
//}
//
///**
// * @brief metodo que añade un nodo antes de otro elegido por el usuario
// *@param List_ la lista que vamos a recorrer
// *@param data es el valor que va a almacenar el nodo
// *@param counter recorre los limites de la lista
// *
// */
//List* List::addBefore(List* List_, Person client_, int counter)
//{
//    Node* node_ = new Node(client_, NULL);
//    if (counter <= List_->size_List(List_) - 2 || counter == 0)
//    {
//        if (List_->size_List(List_) != 0 && counter > 0) {
//            if (counter == List_->size_List(List_) - 1)
//            {
//                List_ = List_->add_at_the_end(List_, client_);
//                return List_;
//            }
//            else {
//                int i = 1;
//                Node* aux_node = List_->getFirstNode();
//                while (i != counter) {
//                    aux_node = aux_node->getNext();
//                    i++;
//                }
//                node_->setNext(aux_node->getNext());
//                aux_node->setNext(node_);
//                cout << "\n\t   Datos ingresados de : " << node_->getDataClient().get_name() << endl;
//            }
//        }
//        else {
//            cout << "\n\t   Se creara en el primer nodo" << endl;
//            List_ = List_->add_to_start(List_, client_);
//            return List_;
//        }
//    }
//    else {
//        cout << "\n\t   El nodo no existe" << endl;
//    }
//    return List_;
//}
//
//
///**
// * @brief metodo que añade un nodo despues de otro elegido por el usuario
// *@param List_ la lista que vamos a recorrer
// *@param data es el valor que va a almacenar el nodo
// *@param counter recorre los limites de la lista
// *
// */
//List* List::addAfter(List* List_, Person client_, int counter)
//{
//    Node* node_ = new Node(client_, NULL);
//    if (counter <= List_->size_List(List_) - 1 || counter == 0)
//    {
//        if (List_->size_List(List_) != 0 && counter > 0) {
//            if (counter == List_->size_List(List_) - 1)
//            {
//                List_ = List_->add_at_the_end(List_, client_);
//                return List_;
//            }
//            else {
//                int i = 1;
//                Node* aux_node = List_->getFirstNode();
//                while (i != counter) {
//                    aux_node = aux_node->getNext();
//                    i++;
//                }
//                node_->setNext(aux_node->getNext());
//                aux_node->setNext(node_);
//                cout << "\n\t   Datos ingresados de : " << node_->getDataClient().get_name() << endl;
//            }
//        }
//        else {
//            cout << "\n\t   Se creara en el primer nodo" << endl;
//            List_ = List_->add_to_start(List_, client_);
//            return List_;
//        }
//    }
//    else {
//        cout << "\n\t   El nodo no existe" << endl;
//    }
//    return List_;
//}
//
///**
// * @brief metodo que elimina el ultimo nodo de la lista
// *@param List_ la lista que vamos a recorrer
// *
// */
//List* List::deleteLast(List* List_)
//{
//    int option;
//    if (verify(List_))
//    {
//        Node* node_ = List_->getLastNode();
//        cout << "\n\tSe eliminaran los datos de dato -> " << node_->getDataClient().get_name() << " " << node_->getDataClient().get_last_name() << ". Desea continuar? \n\t1-SI / 0-NO: ";
//        cin >> option;
//        if (option == 1)
//        {
//            Node* aux_node = NULL;
//            node_ = List_->getFirstNode();
//            while (node_->getNext() != NULL) {
//                aux_node = node_;
//                node_ = node_->getNext();
//            }
//            if (aux_node == NULL)
//            {
//                List_->setFirstNode(node_->getNext());
//            }
//            else
//            {
//                aux_node->setNext(NULL);
//                List_->setLastNode(aux_node);
//                delete node_;
//            }
//            if (List_->getFirstNode() == NULL)
//            {
//                delete List_;
//                List_->setLastNode(NULL);
//                cout << "\n\tSe elimino el ultimo elemento en la lista." << endl;
//                return List_;
//            }
//            cout << "\n\tSe elimino el nodo" << endl;
//        }
//    }
//    return List_;
//}
//
///**
// * @brief metodo que elimina un nodo X elegido por el usuario de la lista
// *@param List_ la lista que vamos a recorrer
// *
// */
//List* List::delete_X_node(List* List_, int counter)
//{
//    int option;
//    Node* node_ = List_->getFirstNode();
//    Node* aux_node = NULL;
//    if (verify(List_)) {
//        if (counter == 1)
//        {
//            List_ = List_->deleteNode(List_);
//        }
//        else if (counter == List_->size_List(List_) - 1)
//        {
//            List_ = List_->deleteLast(List_);
//        }
//        else if (counter >= List_->size_List(List_) || counter < 1)
//        {
//            cout << "\n\tEl nodo no existe" << endl;
//        }
//        else if (node_ != NULL)
//        {
//            int i = 1;
//            while (i != counter)
//            {
//                aux_node = node_;
//                node_ = node_->getNext();
//                i++;
//            }
//            cout << "\n\tSe eliminaran los datos de -> " << node_->getDataClient().get_name() << " " << node_->getDataClient().get_last_name() << ". Desea continuar? \n\t1-SI / 0-NO: ";
//            cin >> option;
//            if (option == 1)
//            {
//                if (node_ != NULL)
//                {
//                    aux_node->setNext(node_->getNext());
//                }
//                delete node_;
//                cout << "\n\tSe elimino el nodo" << endl;
//            }
//        }
//    }
//    return List_;
//}
//
//
///**
// * @brief metodo que elimina un nodo ubicado despues de otro elegido por el usuario
// *@param List_ la lista que vamos a recorrer
// *
// */
//List* List::delete_after_to(List* List_)
//{
//    Node* node_ = List_->getFirstNode();
//    Node* aux_node;
//    int counter = 1, selected_node, option = 0;
//    int lenght = size_List(List_);
//    if (verify(List_))
//    {
//        List_->print(List_);
//        cout << "\n\tIngrese el nodo: ";
//        cin >> selected_node;
//
//        if (selected_node == lenght - 1 || selected_node < 1)
//        {
//            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
//            cout << "\n\tNo existe nodo despues del seleccionado" << endl;
//            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//        }
//        else {
//            if (selected_node == lenght - 2)
//            {
//                List_ = List_->deleteLast(List_);
//            }
//            else {
//                while (counter != selected_node)
//                {
//                    aux_node = node_;
//                    node_ = node_->getNext();
//                    counter++;
//                }
//                aux_node = node_;
//                node_ = node_->getNext();
//                cout << "\n\tSe eliminaran los datos de -> " << node_->getDataClient().get_name() << " " << node_->getDataClient().get_last_name() << ". Desea continuar? \n\t1-SI / 0-NO: ";
//                cin >> option;
//                if (option == 1)
//                {
//                    aux_node->setNext(node_->getNext());
//                    delete node_;
//                    cout << "\n\tSe elimino el nodo" << endl;
//                }
//            }
//        }
//    }
//    return List_;
//}
//
///**
// * @brief metodo que elimina un nodo ubicado antes de otro elegido por el usuario
// *@param List_ la lista que vamos a recorrer
// *
// */
//List* List::delete_before_to(List* List_)
//{
//    Node* node_ = List_->getFirstNode();
//    Node* aux_node;
//    int counter = 1, selected_node, option = 0;
//    int longitud = size_List(List_);
//    if (verify(List_))
//    {
//        List_->print(List_);
//        cout << "\n\tIngrese el nodo: ";
//        cin >> selected_node;
//
//        if (selected_node > longitud - 1 || selected_node <= 1)
//        {
//            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
//            cout << "\n\tNo existe nodo antes del seleccionado o excedio el tamanio de la lista" << endl;
//            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
//        }
//        else {
//            if (selected_node == 2)
//            {
//                List_ = List_->deleteNode(List_);
//            }
//            else {
//                while (counter != selected_node - 2)
//                {
//                    aux_node = node_;
//                    node_ = node_->getNext();
//                    counter++;
//                }
//                aux_node = node_;
//                node_ = node_->getNext();
//                cout << "\n\tSe eliminara el dato -> " << node_->getDataClient().get_name() << " " << node_->getDataClient().get_last_name() << ". Desea continuar? \n\t1-SI / 0-NO: ";
//                cin >> option;
//                if (option == 1)
//                {
//                    aux_node->setNext(node_->getNext());
//                    delete node_;
//                    cout << "\n\tSe elimino el nodo" << endl;
//                }
//            }
//        }
//    }
//    return List_;
//}