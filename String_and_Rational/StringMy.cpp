#include "StringMy.h"

StringMy::StringMy() {
	create();
}
StringMy::StringMy(int size_) {
	_size_ = size_ + 1;
	create();
	string[0] = '\0';
}
StringMy::StringMy(const StringMy& s) {
	_size_ = s._size_;
	create();
	for (int i = 0; i < _size_; i++) string[i] = s.string[i];
}
StringMy::StringMy(const char* c) {
	for (_size_ = 0; c[_size_] != '\0'; _size_++) {}
	_size_++;

	create();

	for (int i = 0; i < _size_; i++) string[i] = c[i];
}

StringMy::~StringMy() {
	delete[] string;
}


void StringMy::create() {
	string = new char[_size_];
	string[_size_ - 1] = '\0';
}
int StringMy::size() {
	return _size_ - 1;
}


const char StringMy::operator[](int char_num) {
	return  (char_num < _size_ - 1)?string[char_num]:static_cast<char>(178);
}
StringMy StringMy::operator+(const StringMy& s) const {
	StringMy result(_size_ + s._size_ - 2);
	int k = 0;
	for (; k < _size_ - 1; k++) result.string[k] = string[k];
	for (int i = 0; i < s._size_; i++, k++) result.string[k] = s.string[i];

	return result;
}
void StringMy::operator+=(const StringMy& s) {
	*this = *this + s;
}
void StringMy::operator=(const StringMy& s){
	_size_ = s._size_;

	delete[] string;
	create();

	for (int i = 0; i < _size_; i++) string[i] = s.string[i];
}
void StringMy::operator=(const char* c){
	for(_size_ = 0; c[_size_] != '\0';_size_++){}
	_size_++;

	delete[] string;
	create();

	for (int i = 0; i < _size_; i++) string[i] = c[i];
}
std::ostream& operator<<(std::ostream& os, const StringMy& s) {
	for (int i = 0; s.string[i] != '\0'; i++) {
		os << s.string[i];
	}
	os << '\n';
	return os;
}