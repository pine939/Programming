#include <memory>
class cat;
class dog;
class handler {
	public:
		handler();
		~handler();
		void run();
	private:
		std::unique_ptr<cat> c;
		std::unique_ptr<dog> d;
};
