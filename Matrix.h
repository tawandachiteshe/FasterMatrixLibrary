#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <memory>
#include <random>
#define LOG(x, y) std::cout << x << y << std::endl;
#define FLOAT32 0
#if FLOAT32
#define MATFLOAT float
#else
#define MATFLOAT double
#endif

typedef MATFLOAT matfloat;
template<typename T>
class Matrix
{
public:
	static int i_InstanceId;
	Matrix(const int r, const int c);
	Matrix(const Matrix& a);
	Matrix();
	~Matrix();
	void print();
	void map(const std::function<T(T)>& func);
	const int& GetNumRows();
	const int& GetNumCols();
	void randomize(const unsigned int seed = 2);
	const Matrix& operator+(const Matrix& a);
	const Matrix& operator-(const Matrix& a);
	const Matrix& operator*(const Matrix& a);
	const Matrix& operator*(const T& a);
	void zeros();
	const Matrix& hadamard(const Matrix& a);
	std::vector<std::vector<T>>& GetData();
	const std::vector<T>& toVector();
	static const Matrix& map(Matrix* x, const std::function<T(T)>& func){
		for (int r = 0; r < x->rows_num; r++){
			for (int c = 0; c < x->cols_num; c++){
				x->data[r][c] = func(x->data[r][c]);
			}
		}
		return *x;
	}

	static Matrix& transpose(const Matrix& x){
		Matrix* transMat = (new Matrix(x.cols_num, x.rows_num));
		for (int r = 0; r < transMat->rows_num; r++){
			for (int c = 0; c < transMat->cols_num; c++){
				transMat->data[r][c] = x.data[c][r];
			}
		}
		return *transMat;
	}

	static Matrix& Matrix::fromVector(const std::vector<T>& vec){
		Matrix *vecMat = new Matrix(vec.size(), 1);
		for (int r = 0; r < vecMat->rows_num; r++){
			for (int c = 0; c < vecMat->cols_num; c++){
				vecMat->data[r][c] = vec[r];
			}
		}
		return *vecMat;
	}

private:
	const int cols_num, rows_num;
	std::vector<std::vector<T>> &data = *(new std::vector<std::vector<T>>);
	std::vector<T> &cols = *(new std::vector<T>);
};
