
#include <iostream>
#include "Node.h"

using namespace std;
/**
 * @brief Metodo constructor de Node con sus atributos inicializados NULL
 *
 *
 */
Node::Node()
{
    //data = NULL;
    client;
    next = NULL;
}

/**
 * @brief Metodo constructor de Node
 * @param client_ obj_Persona que almacena el nodo
 * @param *next el puntero del nodo
 *
 */
Node::Node(Person client_, Node* next_) {
    client = client_;
    next = next_;
}


/**
 * @brief metod getter del objeto almacenado en el nodo
 *
 *
 */
Person Node::getDataClient() {
    return client;
}

/**
 * @brief metod getter del puntero correspondiente al nodo
 *
 *
 */

Node* Node::getNext()
{
    return next;
}



/**
 * @brief metod setter del  obj en el nodo
 *
 *
 */
void Node::setDataClient(Person client_) {

    client = client_;
}

/**
 * @brief metod setter del puntero almacenado en el nodo
 *
 *
 */
void Node::setNext(Node* next_)
{
    next = next_;
}




/**
 * @brief Metodo constructor de Node
 * @param data_ valor que almacena el nodo
 * @param *next el puntero del nodo
 *
 */

 /*Node::Node(int data_, Node* next_) {
     data = data_;
     next = next_;
 }*/


 /**
  * @brief metod getter del dato almacenado en el nodo
  *
  *
  */

  /*int Node::getData()
  {
      return data;
  }*/


  /**
   * @brief metod setter del dato almacenado en el nodo
   *
   *
   */
   /*void Node::setData(int data_)
   {
       data = data_;
   }*/