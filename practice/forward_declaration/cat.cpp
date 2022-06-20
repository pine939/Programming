#include<iostream>
#include "cat.h"

cat::cat() {
	std::cout << "cat()" << std::endl;
}

cat::~cat() {
	std::cout << "~cat()" << std::endl;
}

void cat::run() {
	std::cout << "run cat" << std::endl;
}
