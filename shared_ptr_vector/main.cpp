#include <cstdlib>
#include <vector>
#include <memory>
#include <iostream>

class A {
public:
	~A() {
		std::cout << "deconstruction A" << std::endl;
	}
};

int main() {
	std::shared_ptr<A> a = std::make_shared<A>();
	{
		std::vector<std::shared_ptr<A> > aBox;
		std::cout << "a.count:" << a.use_count() << std::endl;
		aBox.push_back(a);
		std::cout << "a.count:" << a.use_count() << std::endl;
	}
	std::cout << "a.count:" << a.use_count() << std::endl;
}