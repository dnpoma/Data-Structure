#include "Tree.h"

void Tree::push(std::string _spa, std::string _eng) {
    _spa = Utils::Validation::upper(_spa);
    _eng = Utils::Validation::upper(_eng);
    tmp = insert(tmp, _spa, _eng);
    fl.add_word(1, tmp);

}

int Tree::find_height(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->get_height();
}

int Tree::get_balance(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return find_height(node->get_left()) - find_height(node->get_right());
}

Node* Tree::left_rotation(Node* x) {
    Node* y = x->get_right();
    Node* z = y->get_left();

    y->set_left(x);
    x->set_right(z);

    x->set_height(Utils::Math::max(find_height(x->get_left()), find_height(x->get_right())) + 1);
    y->set_height(Utils::Math::max(find_height(y->get_left()), find_height(y->get_right())) + 1);
    return y;
}

Node* Tree::right_rotation(Node* y) {
    Node* x = y->get_left();
    Node* z = x->get_right();

    x->set_right(y);
    y->set_left(z);

    y->set_height(Utils::Math::max(find_height(y->get_left()), find_height(y->get_right())) + 1);
    x->set_height(Utils::Math::max(find_height(x->get_left()), find_height(x->get_right())) + 1);
    return x;
}

Node* Tree::insert(Node* root, std::string _spa, std::string _eng) {
    if (root == nullptr) {
        lenght++;
        return new Node(_spa, _eng);
    }
    else if (_spa < root->get_spain())
        root->set_left(insert(root->get_left(), _spa, _eng));
    else if (_spa > root->get_spain())
        root->set_right(insert(root->get_right(), _spa, _eng));
    else {
        std::cout << "La palabra ingresada ya existe :)";
        return root;
    }

    root->set_height(Utils::Math::max(find_height(root->get_left()), find_height(root->get_right()) + 1));
    int balance = get_balance(root);
    if (balance > 1 && _spa < root->get_left()->get_spain()) {
        return right_rotation(root);
    }
    if (balance < -1 && _spa > root->get_right()->get_spain()) {
        return left_rotation(root);
    }
    if (balance > 1 && _spa > root->get_left()->get_spain()) {
        root->set_left(left_rotation(root->get_left()));
        return right_rotation(root);
    }
    if (balance < -1 && _spa < root->get_right()->get_spain()) {
        root->set_right(right_rotation(root->get_right()));
        return left_rotation(root);
    }
    return root;
}

Node* Tree::node_mimum_value(Node* node) {
    Node* current = node;
    while (current->get_left() != nullptr) {
        current = current->get_left();
    }
    return current;
}

void Tree::delet(std::string word) {
    if (search(word) != nullptr) {
        word = Utils::Validation::upper(word);
        word = search(word)->get_english();
        tmp = pop(tmp, word);
    }
    else {
        std::cout << "La palabra ingresada no se encontro" << std::endl;
    }
}

Node* Tree::pop(Node* node, std::string data) {
    if (node == nullptr) {
        return node;
    }
    if (data < node->get_english()) {
        node->set_left(pop(node->get_left(), data));
    }
    else if (data > node->get_english()) {
        node->set_right(pop(node->get_right(), data));
    }
    else {
        if (node->get_left() == nullptr || node->get_right() == nullptr) {
            Node* temp = node->get_left() ? node->get_left() : node->get_right();
            if (temp == nullptr) {
                temp = node;
                node = nullptr;
            }
            else
                *node = *temp;
            free(temp);
        }
        else {
            Node* temp = node_mimum_value(node->get_right());
            node->set_english(temp->get_english());
            node->set_spain(temp->get_spain());
            node->set_right(pop(node->get_right(), temp->get_english()));

        }
    }

    if (node == nullptr)
        return node;

    node->set_height(Utils::Math::max(find_height(node->get_left()), find_height(node->get_right()) + 1));
    int balance = get_balance(node);
    if (balance > 1 && get_balance(node->get_left())>=0) {
        return right_rotation(node);
    }
    if (balance < -1 && get_balance(node->get_right()) <=  0) {
        return left_rotation(node);
    }
    if (balance > 1 && get_balance(node->get_left()) < 0) {
        node->set_left(left_rotation(node->get_left()));
        return right_rotation(node);
    }
    if (balance < -1 && get_balance(node->get_right()) > 0) {
        node->set_right(right_rotation(node->get_right()));
        return left_rotation(node);
    }
    return node;
}

Node* Tree::search(std::string data) {
    if (tmp == nullptr) {
        return nullptr;
    }
    data = Utils::Validation::upper(data);
    Node* node = nullptr;
    data = Utils::Validation::upper(data);
    print([&data, &node](Node* temp){
        if (data == temp->get_english() || data == temp->get_spain()) {
           std::cout<<"Word: "<< data << " English: " << temp->get_english() << " Spain: " << temp->get_spain() <<std::endl;
            node = temp;
        }
    });
    return node;
}

void Tree::print(std::function<void(Node*)> callback) {
    if (tmp == nullptr) {
        return;
    }
    Stack<Node*> stk;
    Node* current = tmp;
    while (!stk.empty_stack() || current != nullptr)
    {
        if (current != nullptr) {
            stk.insert_front(current);
            current = current->get_left();
        }
        else {
            current = stk.get_first()->get_data();
            stk.delete_front();
            callback(current);
            current = current->get_right();

        }
    }
}

void Tree::print() {
    if (tmp == nullptr) {
        return;
    }
    inorder(tmp->get_left());
    std::cout << tmp->get_spain() << ' ' << tmp->get_english() << ' ' << std::endl;
    inorder(tmp->get_right());
}

Node* Tree::get_node() {
    return tmp;
}

void Tree::set_node(Node* _tmp) {
    this->tmp = _tmp;
}

void Tree::inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->get_left());
    std::cout << root->get_spain() << ' ' << root->get_english() << ' ' << std::endl;
    inorder(root->get_right());
}

void Tree::postorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->get_left());
    std::cout << root->get_spain() << ' ' << root->get_english() << ' ' << std::endl;
    inorder(root->get_right());
}

void Tree::preorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->get_left());
    std::cout << root->get_spain() << ' ' << root->get_english() << ' ' << std::endl;
    inorder(root->get_right());
}

int Tree::get_lenght() {
    return lenght;
}

void Tree::set_lenght(int _lenght) {
    this->lenght = _lenght;
}

