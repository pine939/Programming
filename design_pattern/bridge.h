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
		CatImpl *impl;
};
