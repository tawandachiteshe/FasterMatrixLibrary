#include <iostream>
#include <string>

#include "Timer.h"
#include "NN.h"
#include <thread>


void Train(NN& nn)
{

	int count = 50;
	
	for (int i = 0; i < 4000; i++)
	{
		float progress = (float)i / 4000.0f;
		nn.train({ 0.0, 1.0 }, { 1.0 });
		nn.train({ 1.0, 0.0 }, { 1.0 });
		nn.train({ 1.0, 1.0 }, { 0.0 });
		nn.train({ 0.0, 0.0 }, { 0.0 });

		count--;

		if (count == 0) {
			std::cout << "Solving Xor problem in progress.... " << progress << "% \n \n";
			count = 50;
		}
	}
}

int main()
{
	NN nn(2, 4, 1);

	Train(nn);

	std::cout << "Predicted Result after training... " << nn.predict({ 1.0, 1.0 })[0] << "\n";

	std::cin.get();
}