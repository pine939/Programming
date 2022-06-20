#include<iostream>
#include "animal.h"

animal::animal() {
	std::cout << "animal()" << std::endl;
}

animal::~animal() {
	std::cout << "~animal()" << std::endl;
}

void animal::run() {
	std::cout << "run animal" << std::endl;
}
