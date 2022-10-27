#pragma once

class Matrix3
{
private:
	int** mem;
	int size;
public:
	Matrix3(int _size = 0) {
		size = _size;
		mem = new int* [size];
		for (int i = 0; i < size; i++) {
			mem[i] = new int[size];
			for (int j = 0; j < size; j++) {
				mem[i][j] = 0;
			}
		}
	};
	~Matrix3() {
		for (int i = 0; i < size; i++)
		{
			delete[] mem[i];
		}
		delete[] mem;
	};


	Matrix3(const Matrix3& tmp) {
		size = tmp.size;
		mem = new int* [size];
		for (int i = 0; i < size; i++)
		{
			mem[i] = new int[size];
			for (int j = 0; j < size; j++)
			{
				mem[i][j] = tmp.mem[i][j];
			}
		}
	};

	Matrix3& operator=(Matrix3 tmp) {
		if (size != tmp.size) {
			if (size != 0) {
				for (int i = 0; i < size; i++)
				{
					delete[] mem[i];
				}
				delete[] mem;
			}
			size = tmp.size;
			mem = new int* [size];
		}
		for (int i = 0; i < size; i++) {
			mem[i] = new int[size];
			for (int j = 0; j < size; j++)
			{
				mem[i][j] = tmp.mem[i][j];
			}
		}
		return *this;
	}
};



