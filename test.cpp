#include <iostream>
#include <memory>
 
int c = 'a'; // global scope

// memory storage in stack, heap, static data

// Any global variables will be stored in the static memory
// These variables will remain in a memory until the program stops running

void pass_by_value_funct(int x)
{ // this is the scope of this function
	x = 3;
}

void pass_by_pointer(int* x)
{
	x = 3;
}

void pass_by_refernce(int& x)
{

}

int main()
{
	// local variables in a scope will be in stack memory
	// all local variables destroyed at the end of the scope, stack memory will be cleared

	int x = 1; // scope of main function
	int a = 2;
	std::cout << "the value of x is" << x << std::endl;
	std::cout << "the memory address of x is " << &x << std::endl;
	pass_by_value_funct(a);
	pass_by_pointer(&a) // send memory address

	{
		double y = 1.1; // only available inside this scope
	}

	// pointer
	int* p; // a pointer is a variable that stores a memory address
	// The pointer itself is also stored somewhere inside a memory

	p = &x; // pointer p pointing to an address of an existing variable x
	std::cout << "the value of p is " << p << std::endl; // memory address of x
	std::cout << "the memory address of p is " << &p << std::endl; // memory address of p
	std::cout << "The dereference value of p is " << *p << std::endl; // the value stored at the memory address where p is pointing at

	std::cout << "the memory address of c is " << &c << std::endl;

	int array[3] = { 1,2,3 }; // also inside stack memory
	std::cout << "the memory address of arr is " << &array << std::endl;
	std::cout << "the memory address of arr is " << &array[0] << std::endl;
	std::cout << "the memory address of arr is " << &array[1] << std::endl;
	std::cout << "the memory address of arr is " << &array[2] << std::endl;


	// Heap memory
	// where you can ask for as many memory blocks as you want from a computer
	// you can use a pointer to point to a block of memory where it hasn't been allocated to any existing variables
	// When working with a heap memory, there is a chance of a memory leak
	// memory leak means that you lose access to the dynamically ollocated memory
	
	{
		int* ptr = new int; // an int (4bytes) is dynamically allocated memory
		std::cout << "The value of ptr is " << ptr << std::endl;
		std::cout << "The mrmory address of ptr is " << &ptr << std::endl;
		std::cout << "The dereference value of ptr is " << *ptr << std::endl;
		// to return a memory
		delete ptr; // returns back the memory, 1 way to prevent a memory leak

		// Another way to prevent a memory leak is to use a smart pointer
		std::unique_ptr<int> sp = std::make_unique<int>();



		// Reference
		// Reference is an alias of a variable (rename a variable)
		double abc = 4.5;
		double& def = abc; // def is a reference of abc

		def = 6.7;
		std::cout << abc << std::endl;
		std::cout << def << std::endl;



	}
	// whatever block of memory ptr is pointing at, we cannot access it if ptr goes out of the scope, we lose 4 bytes of memory



	return 0;
	
}