#include <iostream>

class Node {
public:
	Node() = default;
	Node(std::string, std::string);
	Node(std::string, std::string, int);
	Node* create_Tree(std::string);
	std::string get_spain();
	std::string get_english();
	void set_english(std::string);
	void set_spain(std::string);
	void set_left(Node*);
	void set_right(Node*);
	Node* get_left();
	Node* get_right();
	void set_height(int);
	int get_height();
private:
	std::string spain;
	std::string english;
	int height = { 1 };
	Node* left = nullptr;
	Node* right = nullptr;
};