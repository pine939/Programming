#include "pimpl.h"
#include<iostream>

Cat::Cat() 
	: impl(new CatImpl()) {
		std::cout << "Cat()" << std::endl;
}

Cat::~Cat() {
	std::cout<< "~Cat()" << std::endl;
	delete impl;
}

void Cat::setAge(int age) {
	impl->setAge(age);
}

void Cat::setColor(int color) {
	impl->setColor(color);
}

int Cat::getAge() const {
	return impl->getAge();
}

int Cat::getColor() const {
	return impl->getColor();
}

CatImpl::CatImpl()
	: age(0), color(0) { 
		std::cout << "CatImpl()" << std::endl;
}

CatImpl::~CatImpl() {
	std::cout << "~CatImpl()" << std::endl;
}

void CatImpl::setAge(int age) {
	std::cout << "CatImpl's setAge()" << std::endl;
	this->age = age;
}

void CatImpl::setColor(int color) {
	std::cout << "CatImpl's setColor()" << std::endl;
	this->color = color;
}

int CatImpl::getAge() const {
	std::cout << "CatImpl's getAge()" << std::endl;
	return age;
}

int CatImpl::getColor() const {
	std::cout << "CatImpl's getColor()" << std::endl;
	return color;
}

int main() {
	// 사용자는 Cat 객체를 생성하고, Cat 메서드만 호출한다.
	Cat cat;
	cat.setAge(10);
	cat.setColor(5);

	std::cout << cat.getAge() << std::endl;
	std::cout << cat.getColor() << std::endl;
	return 0;
}
