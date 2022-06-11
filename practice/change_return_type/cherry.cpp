#include<iostream>
#include<memory>

class cherry {
public:
	cherry();
	virtual ~cherry();
	virtual void printType();
};

class bingcherry : public cherry {
public:
	bingcherry();
	virtual ~bingcherry();
	void polish();
	void printType() override;
};

class cherryTree {
public:
	cherryTree();
	virtual ~cherryTree();
	virtual cherry* pick();
};

class bingcherryTree : public cherryTree {
public:
	bingcherryTree();
	virtual ~bingcherryTree();
	cherry* pick() override;
};

cherry::cherry() {
	std::cout << "cherry()" << std::endl;
}

cherry::~cherry() {
	std::cout << "~cherry()" << std::endl;
}

bingcherry::bingcherry() {
	std::cout << "bingcherry()" << std::endl;
}

bingcherry::~bingcherry() {
	std::cout << "~bingcherry()" << std::endl;
}

cherryTree::cherryTree() {
	std::cout << "cherryTree()" << std::endl;
}

cherryTree::~cherryTree() {
	std::cout << "~cherryTree()" << std::endl;
}

bingcherryTree::bingcherryTree() {
	std::cout << "bingcherryTree()" << std::endl;
}

bingcherryTree::~bingcherryTree() {
	std::cout << "~bingcherryTree()" << std::endl;
}

cherry* cherryTree::pick() {
	return new cherry();  // 호출한 측에서 리턴된 결과를 스마트 포인터로 저장하자.
}

cherry* bingcherryTree::pick() {
	auto thecherry = std::make_unique<bingcherry>();  // here!
	thecherry->polish();
	return thecherry.release();
}

// 위 pick 함수는 항상 bingcherry를 리턴하므로, 아래와 같이 사용자에게 리턴타입을 알려줄 수도 있다.
/*
bingcherry* bingcherryTree::pick() {
	auto thecherry = std::make_unique<bingcherry>();
	thecherry->polish();
	return thecherry.release();
}
*/

// 단, 전혀 관련 없는 타입으로는 변경할 수 없다. 
/*
void bingcherryTree::pick() {
	auto thecherry = std::make_unique<bingcherry>();
	thecherry->polish();
	return thecherry.release();
}
*/

// 스마트 포인터로 바꿔도 동작하지 않는다. 스마트 포인터는 클래스 템플릿으로 두 인스턴스는 전혀 다른 타입이다. 
/*
std::unique_ptr<cherry> cherryTree::pick() {
	return std::make_unique<cherry>();
}
*/

void bingcherry::polish() {
	std::cout << "polish!" << std::endl;
}

void cherry::printType() {
	std::cout << "I'm cherry Type!" << std::endl;
}

void bingcherry::printType() {
	std::cout << "I'm bingcherry Type!" << std::endl;
}

int main() {
	bingcherryTree theTree;
	std::unique_ptr<cherry> theCherry(theTree.pick());  // cherry가 bingcherry 객체를 가리킨다.
	theCherry->printType();
	return 0;
}
