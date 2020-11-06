#include <iostream>
#include <string>

#include "Timer.h"
#include "NN.h"
#include <thread>


void Train(NN& nn)
{
	
	for (int i = 0; i < 4000; i++)
	{
		nn.train({ 0.0, 1.0 }, { 1.0 });
		nn.train({ 1.0, 0.0 }, { 1.0 });
		nn.train({ 1.0, 1.0 }, { 0.0 });
		nn.train({ 0.0, 0.0 }, { 0.0 });
	
	}
}

int main()
{
	NN nn(2, 4, 1);

	std::cout << "Training.... to Solve xor problem\n";

	Train(nn);

	std::cout << "Predict " << nn.predict({ 0.0, 1.0 })[0] << "\n";

	std::cin.get();
}