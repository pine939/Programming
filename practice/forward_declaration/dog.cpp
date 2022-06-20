#include<iostream>
#include "dog.h"

dog::dog() {
	std::cout << "dog()" << std::endl;
}

dog::~dog() {
	std::cout << "~dog()" << std::endl;
}

void dog::run() {
	std::cout << "run dog" << std::endl;
}
