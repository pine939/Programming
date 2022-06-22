class CatImpl;

class Cat {
	public:
		Cat();
		virtual ~Cat();

		void setAge(int age);
		void setColor(int color);

		int getAge() const;
		int getColor() const;
	private:
		CatImpl *impl;  // implementation 객체를 포인터로 소유함
};

class CatImpl {
	public:
		CatImpl();
		~CatImpl();

		void setAge(int age);
		void setColor(int color);
		int getAge() const;
		int getColor() const;
	private:
		int age;
		int color;
};
