#include "Vect.h"


void Vect::gen() {
	v = new double[sz];
}



//(de/con)srtructors
Vect::Vect(int sz_) {
	sz = sz_;
	gen();
}
Vect::Vect(const Vect& next_v) {
	sz = next_v.sz;
	gen();
	for (int i = 0; i < sz; i++) {
		v[i] = next_v.v[i];
	}
}
Vect::~Vect() {
	delete[] v;
}



//fun
int Vect::size() { return sz; }

//operators
double& Vect::operator[](int i) {
	return v[i];
}
Vect& Vect::operator=(const Vect& next_v) {
	if (sz != next_v.sz) {
		sz = next_v.sz;
		delete[] v;
		v = new double[sz];
	}

	for (int i = 0; i < sz; i++) v[i] = next_v.v[i];
	return *this;
}

//friend operators
std::ostream& operator<<(std::ostream& os, const Vect& vec) {
	for (int i = 0; i < vec.sz; i++) os << vec.v[i] << " ";
	os << "\n";
	return os;
}
std::istream& operator>>(std::istream& is, Vect& vec) {
	for (int i = 0; i < vec.sz; i++) is >> vec.v[i];
	return is;
}