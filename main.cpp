#include <iostream>
#include <array>
#include <vector>
#include "Matrix.h"
#include "Timer.h"
#include <memory>
#include <time.h>
#include <string>
int main(){
	try{
		//cant do stack allocation now
		Timer time;
		Matrix<matfloat> mm(64, 64);
		Matrix<matfloat> mm2(64, 64);
		mm.randomize(5);
		mm2.randomize(10);
		Matrix<matfloat> result = mm * mm2;
	}
	catch (int x){
		LOG(x, "");
	}

	std::cin.get();
}