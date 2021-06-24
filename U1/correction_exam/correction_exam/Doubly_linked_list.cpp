#include "Doubly_linked_list.h"
#include <sstream>
void Doubly_linked_list::insert_end(Person value) {
	Nodo* new_nodo = new Nodo(value);
	if (first == nullptr) {
		this->first = new_nodo;
		size++;
		return;
	}
	Nodo* last_nodo = last();
	last_nodo->set_next(new_nodo);
	new_nodo->set_last(last_nodo);
}


void Doubly_linked_list::insert_start(Person value) {
	Nodo* new_nodo = new Nodo(value);
	if (first == nullptr) {
		this->first = new_nodo;
		size++;
		return;
	}
	first->set_last(new_nodo);
	new_nodo->set_next(first);
	first = new_nodo;

}

void Doubly_linked_list::insert_between(Person value) {
	Nodo* new_nodo = new Nodo(value);
	if (first == nullptr) {
		this->first = new_nodo;
		size++;
		return;
	}
	Nodo* last_nodo = last();
	last_nodo->set_next(new_nodo);
	new_nodo->set_last(last_nodo);
}

//
//void Doubly_linked_list::delete_element(std::string value) {
//	Nodo* tmp = first;
//	if (value == 1) {
//		first = tmp->get_next();
//		return;
//	}
//	for (int i = 0; i < value - 2; i++)
//		tmp = tmp->get_next();
//	Nodo* tmp1 = tmp->get_next();
//	tmp->set_next(tmp1->get_next());
//}


void Doubly_linked_list::delete_first() {
	Nodo* tmp;
	if (first == nullptr)
		return;
	tmp = first;
	first = first->get_next();
	first->set_last(0);
}


void Doubly_linked_list::delete_last() {
	Nodo* tmp;
	if (last() == nullptr)
		return;
	else {
		tmp = last();
		last()->set_last(last()->get_next());
		//last() = last()->get_last();
		last()->set_last(last()->get_last());
	}
}



void Doubly_linked_list::print(std::function<void(std::string, int)>callback) {
	Nodo* tmp = first;
	int index = 0;
	while (tmp != nullptr) {
		callback(tmp->get_data().get_id(), index++);
		tmp = tmp->get_next();
	}
}


Nodo* Doubly_linked_list::last() {
	Nodo* tmp = first;
	while (tmp->get_next() != nullptr) {
		tmp = tmp->get_next();
	}
	return tmp;
}


void Doubly_linked_list::print() {
	Nodo* tmp = first;
	while (tmp->get_next() != nullptr) {
		cout << tmp->get_data().get_id() <<" " << tmp->get_data().get_name() << " ->";
		tmp = tmp->get_next();
	}
}

void Doubly_linked_list::modified() {
	Nodo* tmp = first;
	bool find = false;
	std::string nodo_search = 0, number;
	cout << " Ingrese el dato del nodo a Buscar para Modificar: ";
	getline(std::cin, nodo_search);
	//cin >> nodo_search;
	if (first != NULL) {
		do {

			if (tmp->get_data().get_id() == nodo_search) {
				cout << "\n Nodo con el dato ( " << nodo_search << " ) Encontrado";
				cout << "\n Ingrese el nuevo dato para este Nodo: ";
				getline(std::cin, number);
				/*cin >> number;
				tmp->set_data(number);
				tmp->get_data();*/
				tmp->get_data().set_id(number);
				tmp->get_data();
				cout << "\n Nodo Modificado\n\n";
				find = true;
			}

			tmp = tmp->get_next();

		} while (tmp != nullptr && find != true);

		if (!find) {
			cout << "\n Nodo no Encontrado\n\n";
		}
	}
	else {
		cout << "\n La lista se Encuentra Vacia\n\n";
	}
}

// dato a modificar, nuevo valor
void Doubly_linked_list::modified_input(std::string nodo_search, std::string number) {
	Nodo* tmp = first;
	bool find = false;
	//int nodo_search = 0;
	//cout << " Ingrese el dato del nodo a Buscar para Modificar: ";
	cout << "Nodo a buscar: " << nodo_search;
	//cin >> nodo_search;
	if (first != NULL) {
		do {
			if (tmp->get_data().get_id() == nodo_search) {
				cout << "\n Nodo con el dato ( " << nodo_search << " ) Encontrado";
				cout << "\n Ingrese el nuevo dato para este Nodo: ";
				cout << "\n Nuevo valor: " << number;
				//tmp->set_data(number);
				tmp->get_data().set_id(number);
				tmp->get_data();
				cout << "\n Nodo Modificado\n\n";
				find = true;
			}

			tmp = tmp->get_next();

		} while (tmp != nullptr && find != true);

		if (!find) {
			cout << "\n Nodo no Encontrado\n\n";
		}
	}
	else {
		cout << "\n La lista se Encuentra Vacia\n\n";
	}
}
// dato a modificar, nuevo valor
void Doubly_linked_list::modified_change(int nodo_search) {
	Nodo* tmp = first;
	bool find = false;
	//int nodo_search = 0;
	//cout << " Ingrese el dato del nodo a Buscar para Modificar: ";
	cout << "Nodo a buscar: " << nodo_search;
	//cin >> nodo_search;
	if (first != NULL) {
		do {
			int value_digits[3];
			int number = std::stoi(tmp->get_data().get_id());
			int* data = op.data_expand(number, value_digits);
			int i = (sizeof(data) / sizeof(data[0])) + 1;
			for (int s = i - 1; s >= 0; s--)
			{
				for (int j = i - 1; j >= 0; j--) {
					if ((s == 1 && j == 0) || (s == 2 && j == 1)) {
						number = data[s] * 10 + data[j];
						if (number == nodo_search) {
							cout << "\n Nodo con el dato ( " << tmp->get_data().get_id() << " ) Encontrado";
							// tiene que quedar el otro 13 2
							if (s == 1 && j == 0) {
								tmp->get_data().set_id(to_string(data[2]));
							}
							tmp->get_data().set_id(to_string(data[2]));
							tmp->get_data();
							cout << "\n Nodo Modificado\n\n";
							//find = true;
						}
					}
				}
			}
			tmp = tmp->get_next();

		} while (tmp != nullptr && find != true);
	}
	else {
		cout << "\n La lista se Encuentra Vacia\n\n";
	}
}
