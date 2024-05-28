#pragma once
#include<iostream>

template<class T>
class Vect
{
	int sz = 0;
	T* v;
	void gen();

public:
//(de/con)srtructors
	Vect(int sz = 0);
	Vect(const Vect& next_v);
	~Vect();

//fun
	int size();
	void resize(int nsz);
	double modul();
	void push_back(T d);
	bool pop_back();
//operators
	T& operator[](const int i);
	Vect& operator=(const Vect& next_v);
	Vect operator+(const Vect& next_v) const;
	void operator+=(const Vect& next_v);
	Vect operator++();
	const Vect operator++(int);
	Vect operator*(const double  d) const;
	T operator*(const Vect& v) const;
	bool operator==(const Vect& vec) const;
	bool operator!=(const Vect& vec) const;
//friend operators
	friend std::ostream& operator<<(std::ostream& os, const Vect<T>& vec) {
		for (int i = 0; i < vec.sz; i++) os << vec.v[i] << " ";
		os << "\n";
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Vect<T>& vec) {
		for (int i = 0; i < vec.sz; i++) is >> vec.v[i];
		return is;
	}
};

template<class T>
void Vect<T>::gen() {
	v = new T[sz];
}



//(de/con)srtructors
template<class T>
Vect<T>::Vect(int sz_) {
	sz = sz_;
	gen();
}
template<class T>
Vect<T>::Vect(const Vect& next_v) {
	sz = next_v.sz;
	gen();
	for (int i = 0; i < sz; i++) {
		v[i] = next_v.v[i];
	}
}
template<class T>
Vect<T>::~Vect() {
	delete[] v;
}



//fun
template<class T>
int Vect<T>::size() { return sz; }
template<class T>
double Vect<T>::modul() {
	int m = 0;
	for (int i = 0; i < sz; i++) {
		m += v[i] * v[i];
	}
	return pow(m, 0.5);
}
template<class T>
void Vect<T>::push_back(T d) {
	Vect reserve(*this);
	delete[] v;
	sz++;

	v = new T[sz];
	v[sz - 1] = d;
	for (int i = 0; i < sz - 1; i++) v[i] = reserve.v[i];

}
template<class T>
void Vect<T>::resize(int nsz) {
	Vect<T> res(*this);

	delete[] v;
	sz = nsz;

	if (res.sz > sz) {
		v = new T[sz];
		for (int i = 0; i < sz; i++) v[i] = res.v[i];
	}
	else {
		int i = 0;
		v = new T[sz];
		for (; i < res.sz; i++) v[i] = res.v[i];
		for (; i < sz; i++) v[i] = NULL;
	}
}
template<class T>
bool Vect<T>::pop_back() {
	if (sz == 0) return false;

	Vect reserve(*this);
	delete[] v;
	sz--;
	v = new T[sz];
	for (int i = 0; i < sz; i++) v[i] = reserve.v[i];
	return true;
}
//operators
template<class T>
T& Vect<T>::operator[](int i) {
	return v[i];
}
template<class T>
Vect<T>& Vect<T>::operator=(const Vect& next_v) {
	if (sz != next_v.sz) {
		sz = next_v.sz;
		delete[] v;
		v = new T[sz];
	}

	for (int i = 0; i < sz; i++) v[i] = next_v.v[i];
	return *this;
}
template<class T>
Vect<T> Vect<T>::operator+(const Vect& next_v) const {
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
template<class T>
void Vect<T>::operator+=(const Vect& next_v) {
	*this = *this + next_v;
}
template<class T>
Vect<T> Vect<T>::operator*(const double d)const {
	Vect result(*this);
	for (int i = 0; i < result.sz; i++) result.v[i] *= d;
	return result;
}
template<class T>
Vect<T> Vect<T>::operator++() {
	for (int i = 0; i < sz; i++) v[i]++;
	return *this;
}
template<class T>
const Vect<T> Vect<T>::operator++(int) {
	Vect res(*this);
	++*this;
	return res;
}
template<class T>
T Vect<T>::operator*(const Vect& vec) const {
	T result;
	for (int i = 0; i < sz; i++) {
		result = result + v[i] * vec.v[i];
	}
	return result;
}
template<class T>
bool Vect<T>::operator==(const Vect& vec) const {
	if (sz != vec.sz) return false;
	for (int i = 0; i < sz; i++) {
		if (v[i] != vec.v[i]) return false;
	}
	return true;
}
template<class T>
bool Vect<T>::operator!=(const Vect& vec) const {
	return !(*this == vec);
}
//friend operators