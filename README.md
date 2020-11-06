# FasterMatrixLibrary

## How to build
- CMAKE 3.10

### Api usage

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
