// shared_ptr::reset example
#include <iostream>
#include <memory>

int main() {
	std::shared_ptr<int> sp;  // empty
	std::cout << "line:" << __LINE__ << " use_count:" << sp.use_count() << std::endl;
	sp.reset(new int);       // takes ownership of 
	std::shared_ptr<int> sp2 = sp;
	std::cout << "line:" << __LINE__ << " use_count:" << sp.use_count() << std::endl;
	*sp = 10;
	std::cout << *sp << '\n';

	sp.reset(new int);       // deletes managed object, acquires new pointer
	std::cout << "line:" << __LINE__ << " use_count:" << sp.use_count() << std::endl;
	std::cout << "sp2:" << *sp2 << std::endl;
	*sp = 20;
	std::cout << "sp2:" << *sp2 << std::endl;
	std::cout << *sp << '\n';
	std::cout << "line:" << __LINE__ << " use_count:" << sp.use_count() << std::endl;
	sp.reset();               // deletes managed object
	std::cout << "line:" << __LINE__ << " use_count:" << sp.use_count() << std::endl;
	return 0;
}