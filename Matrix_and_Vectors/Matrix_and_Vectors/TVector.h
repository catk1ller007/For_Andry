#pragma once
#include <iostream>

using namespace std;

template<typename T>
class TVector
{
protected:
	T* arr;
	int size;
	int start;
public:
	TVector<T>(int _size = 0, int startM = 0)
	{
		size = _size;
		//start = tmp.start; 
		start = startM;
		arr = new T[size];
		for (int i = 0; i < _size; i++)
		{
			arr[i] = T(0);
		}
	}
	TVector(const TVector& tmp)
	{
		size = tmp.size;
		arr = new T[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = tmp.arr[i];
		}
	}
	~TVector() {
		delete[] this->arr;
	}
	TVector& operator=(TVector tmp)
	{
		if (size != tmp.size)
		{
			if (size != 0)
			{
				delete[]arr;
			}
			size = tmp.size;
			arr = new T[size];
		}
		start = tmp.start;
		for (int i = 0; i < size; i++)
		{
			arr[i] = tmp.arr[i];
		}
		return *this;
	}

	T& operator[](int k)
	{
		if (!(k < start || k > size + start))
		{
			return arr[k - start];
		}
	}
	TVector operator +(const TVector& tmp)
	{
		TVector<T> res(*this);
		if (size == tmp.size)
		{
			res = *this;
			for (int i = 0; i < size; i++)
			{
				res.arr[i] = arr[i] + tmp.arr[i];
			}
		}
		return res;
	}
	TVector operator -(const TVector& tmp)
	{
		TVector<T> res(*this);
		if (size == tmp.size)
		{
			res = *this;
			for (int i = 0; i < size; i++)
			{
				res.arr[i] = arr[i] - tmp.arr[i];
			}
		}
		return res;
	}
	//
	TVector operator*(const TVector<T>& tmp)
	{
		T res(0);
		if (size == tmp.size && start == tmp.start)
		{
			for (int i = 0; i < size; i++)
			{
				res = arr[i] * tmp.arr[i];
			}
		}
		return res;
	}
	int GetSize()
	{
		return size;
	}
	//”множение вектора на число
	TVector operator*(const T& k)
	{
		TVector<T> res(*this);
		for (int i = 0; i < size; i++)
		{
			res.arr[i] *= k;
		}
		return res;
	}

	friend istream& operator>>(istream& in, TVector& v)
	{
		for (int i = 0; i < v.size; i++)
			in >> v.arr[i];
		return in;
	}

	friend ostream& operator<<(ostream& out, const TVector& v)
	{
		for (int i = 0; i < v.size; i++)
		{
			out << v.arr[i] << ' ';
		}
		return out;
	}
};




//template<typename T>
//class Tvector // класс “ вектор
//{
//private:
//	T* arr;
//	int size;
//	int start;
//public:
//	Tvector<T>(int _size = 0, int _start = 0) {
//		size = _size;
//		start = _start;
//		//start = tmp.start;
//		arr = new T[_size];
//		for (int i = 0; i < _size; i++) {
//			arr[i] = T(0);
//		}
//	}
//	Tvector(int _size = 0) {
//		size = _size;
//		arr = new T[size];
//		for (int i = 0; i < size; i++)
//		{
//			arr[i] = T(0);
//		}
//	}
//
//	~Tvector() {
//		/*for (int i = 0; i < size; i++)
//		{
//			delete[] arr[i];
//		}*/
//		delete[] arr;
//	}
//
//	TVector(const Tvector& tmp) {
//		size = tmp.size;
//		arr = new T[size];
//		for (int i = 0; i < size; i++) {
//			arr[i] = tmp.arr[i];
//		}
//	}
//	Tvector& operator=(Tvector tmp) {
//		if (size != tmp.size) {
//			if (size != 0) {
//				delete[] arr;
//			}
//			size = tmp.size;
//			arr = new T[size];
//			start = tmp.start;
//			for (int i = 0; i < size; i++) {
//				arr[i] = tmp.arr[i];
//			}
//			return *this;
//		}
//	}
//
//	T& operator[](int k) {
//		T res(0);
//		if (k < start + size && k >= start)
//		{
//			res = arr[k - start];
//		}
//		return res;
//	}
//	Tvector operator+(Tvector tmp) { //можно сделать и дл€ старта
//		Tvector res;
//		if (size == tmp.size) {
//			res = *this;
//			for (int i = 0; i < size; i++) {
//				res.arr[i] = arr[i] + tmp.arr[i];
//			}
//		}
//		return res;
//	}
//	Tvector operator-(Tvector tmp) { //можно сделать и дл€ старта
//		Tvector res;
//		if (size == tmp.size) {
//			res = *this;
//			for (int i = 0; i < size; i++) {
//				res.arr[i] = arr[i] - tmp.arr[i];
//			}
//		}
//		return res;
//	}
//	T operator*(Tvector tmp) {
//		T res(0);
//		if ((size == tmp.size) && (start == tmp.start)) {
//			for (int i = 0; i < size; i++) {
//				res = arr[i] * tmp.arr[i];
//			}
//		}
//		return res;
//	}
//	int GetsSize() {
//		return size;
//	}
//	Tvector operator*(int k) {
//		Tvector res (*this);
//		for (int i = 0; i < size; i++) {
//			res.arr[i] *= k;
//		}
//		return res;
//	}
//};



