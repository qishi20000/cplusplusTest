#include <iostream>

class HasPtrMem
{
public:
	HasPtrMem() :d(new int[4]) 
	{ 
		std::cout << "Construct: " << ++n_cstr << std::endl; 
	}
	HasPtrMem(const HasPtrMem& b)
	{
		memcpy(d, b.d, sizeof(int) * 4);
		std::cout << "Copy Construct: " << ++n_dstr << std::endl;
	}

	HasPtrMem(HasPtrMem&& b):d(b.d)
	{
		b.d = nullptr;
		std::cout << "move Construct: " << ++n_dstr << std::endl;
	}

	~HasPtrMem()
	{
		std::cout << "Deconstruct: " << ++n_cptr << std::endl;
		delete [] d;
	}

	int* d = nullptr;
	static int n_cstr;
	static int n_dstr;
	static int n_cptr;
};

int HasPtrMem::n_cstr = 0;
int HasPtrMem::n_dstr = 0;
int HasPtrMem::n_cptr = 0;

HasPtrMem GetTemp() { return HasPtrMem(); }

int main()
{
	HasPtrMem a = GetTemp();
}