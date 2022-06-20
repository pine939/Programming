#include<iostream>
#include "handler.h"

int main() {
	handler *h = new handler();
	h->run();
	delete h;
	return 0;
}
