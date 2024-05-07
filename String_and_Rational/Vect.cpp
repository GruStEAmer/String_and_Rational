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
double Vect::modul() {
	int m = 0;
	for (int i = 0; i < sz; i++) {
		m += v[i] * v[i];
	}
	return pow(m,0.5);
}
void Vect::push_back(double d) {
	Vect reserve(*this);
	delete[] v;
	sz++;

	v = new double[sz];
	v[sz - 1] = d;
	for (int i = 0; i < sz - 1; i++) v[i] = reserve.v[i];

}
void Vect::resize(int nsz) {
	Vect res(*this);

	delete[] v;
	sz = nsz;

	if (res.sz > sz) {
		v = new double[sz];
		for (int i = 0; i < sz; i++) v[i] = res.v[i];
	}
	else {
		int i = 0;
		v = new double[sz];
		for (; i < res.sz; i++) v[i] = res.v[i];
		for (; i < sz; i++) v[i] = 0.0;
	}
}
bool Vect::pop_back() {
	if (sz == 0) return false;

	Vect reserve(*this);
	delete[] v;
	sz--;
	v = new double[sz];
	for (int i = 0; i < sz;i++) v[i] = reserve.v[i];
	return true;
}
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
Vect Vect::operator+(const Vect& next_v) const {
	Vect result;
	if (sz >= next_v.sz) {
		result = *this;
		for (int i = 0; i < next_v.sz; i++) result.v[i] += next_v.v[i];
	}
	else {
		result = next_v;
		for (int i = 0; i < sz; i++) result.v[i] += v[i];
	}
	return result;
}
void Vect::operator+=(const Vect& next_v) {
	*this = *this + next_v;
}
Vect Vect::operator*(const double d)const {
	Vect result(*this);
	for (int i = 0; i < result.sz; i++) result.v[i] *= d;
	return result;
}
Vect Vect::operator++() {
	for (int i = 0; i < sz; i++) v[i]++;
	return *this;
}
const Vect Vect::operator++(int) {
	Vect res(*this);
	++*this;
	return res;
}
double Vect::operator*(const Vect& vec) const {
	double result = 0;
	for (int i = 0; i < sz; i++) {
		result += v[i] * vec.v[i];
	}
	return result;
}
bool Vect::operator==(const Vect& vec) const {
	if(sz != vec.sz) return false;
	for (int i = 0; i < sz; i++) {
		if (v[i] != vec.v[i]) return false;
	}
	return true;
}
bool Vect::operator!=(const Vect& vec) const {
	return !(*this == vec);
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