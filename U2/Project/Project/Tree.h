#include <iostream>
#include "Utils.h"
#include "Node.h"
#include "Stack.h"
#include <functional>
using namespace Utils;

class Tree {
private:
    int lenght = 0;
    Node* tmp = nullptr;
    Node* insert(Node*, std::string, std::string);
public:
    Tree() = default;
    void push(std::string, std::string);
    Node* pop(Node*, std::string);
    void delet(std::string);
    Node* node_mimum_value(Node* node);
    int get_balance(Node*);
    int find_height(Node*);
    Node* left_rotation(Node*);
    Node* right_rotation(Node*);
    void inorder(Node*);
    void preorder(Node*);
    void postorder(Node*);
    int get_lenght();
    void set_lenght(int);
    Node* get_node();
    void set_node(Node*);
    Node* search(std::string);
    void print(std::function<void(Node*)> callback);
    void print();
};
