#include<memory>
#include<iostream>
#include "handler.h"
#include "cat.h"
#include "dog.h"

handler::handler() 
	: c(std::make_unique<cat>()), d(std::make_unique<dog>()) {
	//c = std::make_unique<cat>();
	std::cout << "handler()" << std::endl;
}

handler::~handler() {
	std::cout << "~handler()" << std::endl;
}

void handler::run() {
	c->run();
	d->run();
}
