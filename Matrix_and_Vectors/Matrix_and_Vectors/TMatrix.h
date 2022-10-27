#pragma once
//#include <iostream>
#include "TVector.h"

using namespace std;

template <typename T>
class TMatrix : public TVector<TVector<T>>
{
public:
	TMatrix(int _size_matr) : TVector<TVector<T> >(_size_matr)
	{
		for (int i = 0; i < this->size; i++)
		{
			this->arr[i] = TVector<T>(this->size - i, i);
		}
	}
	TMatrix(const TMatrix& mt) : TVector<TVector<T> >(mt) {}
	TMatrix& operator=(const TMatrix& tmp)
	{
		if (this != &tmp)
		{
			if (this->size != tmp.size)
			{
				this->size = tmp.size;
				delete[] this->arr;
				this->arr = new TVector<T>[this->size];
			}
			this->start = tmp.start;
			for (int i = 0; i < this->size; ++i)
				this->arr[i] = tmp.arr[i];
		}
		return *this;
	}
	TMatrix  operator+ (const TMatrix& mt)
	{
		TMatrix<T> result(*this);
		for (int i = 0; i < this->size; i++)
		{
			result.arr[i] = this->arr[i] + mt.arr[i];
		}
		return result;
	}
	TMatrix  operator- (const TMatrix& mt) {
		TMatrix<T> result(*this);
		for (int i = 0; i < this->size; i++)
		{
			result.arr[i] = this->arr[i] - mt.arr[i];
		}
		return result;
	}

	friend istream& operator>>(istream& in, TMatrix& mt)
	{
		for (int i = 0; i < mt.size; i++)
		{
			in >> mt.arr[i];
		}
		return in;
	}

	friend ostream& operator<<(ostream& out, const TMatrix& mt)
	{
		for (int i = 0; i < mt.size; i++)
		{
			out << mt.arr[i] << endl;
		}
		return out;
	}
};