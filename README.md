# FasterMatrixLibrary

## How to build
- ##### CMAKE 3.10
- ##### CPP11
- ##### only MSVC or gnu c++ compiler where tested

### Api usage for the Matrix Library

```cpp

Matrix mat ( \* num of rows *\ 2, \* num of columns *\ 2);

//sets all the elements to one
mat.ones();

//maps all the elements to a function
mat.map([](auto num){ return std::sin(num); });
//dot product
Matrix dot = mat * mat;

//add
Matrix dot = mat + mat;

//subtration
Matrix dot = mat - mat;

//scalar multiplication
Matrix dot = mat * 2.0;


```

### Api usage for the Neural Network

```cpp

NN nn ( \* input size *\ 2, \* hidden layer size *\ 4, \* output size *\ 1);

const unsigned int NUM_OF_ITERATIONS = 10u;

for ( unsigned int = 0; i < NUM_OF_ITERATIONS; i++)
{
    nn.train( \* array of the input in double data type *\ { 1.0, 1.0  }, \* expected output in an array*\ { 1.0f }  );
    // continue the process for all the required data
}

// nn.predict returns std::vector<double>
auto& output = nn.predict({ 1.0, 1.0f });

std::cout << "Desired output prediction " << output[0] << "\n" ; 

```
