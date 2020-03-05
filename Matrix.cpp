#include "Matrix.h"

int Matrix<matfloat>::i_InstanceId;


Matrix<matfloat>::Matrix(const Matrix<matfloat>& a):
rows_num(a.rows_num), cols_num(a.cols_num), data(a.data), cols(a.cols){
	i_InstanceId += 1;
	LOG("Instance id  ",i_InstanceId);
}

Matrix<matfloat>::Matrix(const  int r, const  int c):
rows_num(r), cols_num(c)
{
	data.reserve(r);
	cols.reserve(c);
	i_InstanceId += 1;
	for (int r = 0; r < rows_num; r++){
		data.push_back(cols);
		for (int c = 0; c < cols_num; c++){
			data[r].push_back(0);
		}
	}
}

void Matrix<matfloat>::print(){
	for (int r = 0; r < rows_num; r++){
		for (int c = 0; c < cols_num; c++){
			std::cout << data[r][c];
			std::cout << " ";
		}
		std::cout << "" << std::endl;
	}
}

void Matrix<matfloat>::map(const std::function<matfloat(matfloat)>& func){
	for (int r = 0; r < rows_num; r++){
		for (int c = 0; c < cols_num; c++){
			data[r][c] = func(data[r][c]);
		}
	}
}


const int& Matrix<matfloat>::GetNumCols(){
	return cols_num;
}

const int& Matrix<matfloat>::GetNumRows(){
	return rows_num;
}

void Matrix<matfloat>::zeros(){
	for (int r = 0; r < rows_num; r++){
		for (int c = 0; c < cols_num; c++){
			data[r][c] += 0;
		}
	}
}


const Matrix<matfloat>& Matrix<matfloat>::operator+(const Matrix<matfloat>& a){
	if (rows_num != a.rows_num || cols_num != a.cols_num)
		LOG("Columns and Rows of A must match Columns and Rows of B", "");
	for (int r = 0; r < rows_num; r++){
		for (int c = 0; c < cols_num; c++){
			data[r][c] += a.data[r][c];
		}
	}
	return *(this);
}

const Matrix<matfloat>& Matrix<matfloat>::operator-(const Matrix<matfloat>& a){
	if (rows_num != a.rows_num || cols_num != a.cols_num)
		LOG("Columns and Rows of A must match Columns and Rows of B", "");
	for (int r = 0; r < rows_num; r++){
		for (int c = 0; c < cols_num; c++){
			data[r][c] -= a.data[r][c];
		}
	}
	return *(this);
}
const Matrix<matfloat>& Matrix<matfloat>::hadamard(const Matrix<matfloat>& a){
	if (rows_num != a.rows_num || cols_num != a.cols_num)
		LOG("Columns and Rows of A must match Columns and Rows of B", "");
	for (int r = 0; r < rows_num; r++){
		for (int c = 0; c < cols_num; c++){
			data[r][c] *= a.data[r][c];
		}
	}
	return *(this);
}

const Matrix<matfloat>& Matrix<matfloat>::operator*(const matfloat& a){
	for (int r = 0; r < rows_num; r++){
		for (int c = 0; c < cols_num; c++){
			data[r][c] *= a;
		}
	}
	return *(this);
}



//dot product
const Matrix<matfloat>& Matrix<matfloat>::operator*(const Matrix<matfloat>& a){
	if (rows_num != a.cols_num)
		LOG("Columns of A must match rows of B.", "");
	Matrix<matfloat>* result_ptr = new Matrix<matfloat>(rows_num, a.cols_num);
	for (int i = 0; i < result_ptr->rows_num; i++){
		for (int j = 0; j < result_ptr->cols_num; j++){
			for (int k = 0; k < a.cols_num; k++){
				result_ptr->data[i][j] += (data[i][k] * a.data[k][j]) ;
			}
		}
	}
	return *result_ptr;
}

void Matrix<matfloat>::randomize(const unsigned int seed){
	srand(seed);
	for (int r = 0; r < rows_num; r++){
		for (int c = 0; c < cols_num; c++){
			data[r][c] = 1 / rand();
		}
	}
}

const std::vector<matfloat>& Matrix<matfloat>::toVector(){
	std::vector<matfloat> *matVec = new std::vector<matfloat>();
	for (int r = 0; r < rows_num; r++){
		for (int c = 0; c < cols_num; c++){
			matVec->push_back(data[r][c]);
		}
	}
	return *matVec;
}

std::vector<std::vector<matfloat>>& Matrix<matfloat>::GetData(){
	return data;
}
Matrix<matfloat>::~Matrix()
{
	i_InstanceId -= 1;
	std::cout << "Destroyed "<< "Instance id = " << i_InstanceId << std::endl;
}
