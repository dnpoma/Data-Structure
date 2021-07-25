#include "Node.h"

Node::Node(std::string _spain, std::string _english) {
	this->spain = _spain;
	this->english = _english;
	this->height = 1;
}

Node::Node(std::string _spain, std::string _english, int _height) {
	this->spain = _spain;
	this->english = _english;
	this->height = _height;
}

std::string Node::get_spain() {
	return spain;
}

std::string Node::get_english() {
	return english;
}

void Node::set_spain(std::string _spain) {
	this->spain = _spain;
}


void Node::set_english(std::string _english) {
	this->english = _english;
}

void Node::set_left(Node* _left) {
	this->left = _left;
}

void Node::set_right(Node* _right) {
	this->right = _right;
}

int Node::get_height() {
	return height;
}

void Node::set_height(int _height) {
	this->height = _height;
}

Node* Node::get_left() {
	return left;
}

Node* Node::get_right() {
	return right;
}