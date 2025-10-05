#include "Array.hpp"

static void divider(std::string const & title, std::string const &colour)
{
	std::cout << colour << "\n// ===================================================================\n" << RESET;
	std::cout << colour << "// " << title << "\n" << RESET;
	std::cout << colour << "// ===================================================================\n" << RESET;
	return;
}

int main()
{
	{
		divider("Empty Array", GREEN);
		Array<int> a0;
		std::cout << "size = " << a0.size() << std::endl;
	}
	{
		divider("Array of 5 ints (value-initalised to 0)", BLUE);
		Array<int> a1(5);
		for (unsigned int i = 0; i < a1.size(); i++)
			std::cout << "a1[" << i << "] = " << a1[i] << std::endl;
		unsigned int j = 0;
		std::cout << "\nAdding value to each elements!" << std::endl;
		for (unsigned int i = 0; i < a1.size(); i++)
		{
			j += 7;
			a1[i] = j;
		}
		for (unsigned int i = 0; i < a1.size(); i++)
			std::cout << "a1[" << i << "] = " << a1[i] << std::endl;
	}
	{
		divider("Copy Constructor", YELLOW);
		Array<int> a2(8);
		Array<int> a3(a2);
		std::cout << "\nPrinting a2\n";
		for (unsigned int i = 0; i < a2.size(); i++)
			std::cout << "a2[" << i << "] = " << a2[i] << std::endl;
		std::cout << "\nPrinting a3\n";
		for (unsigned int i = 0; i < a3.size(); i++)
			std::cout << "a3[" << i << "] = " << a3[i] << std::endl;
		unsigned int j = 0;
		std::cout << "\nAdding value to each elements in a3!" << std::endl;
		for (unsigned int i = 0; i < a3.size(); i++)
		{
			j += 8;
			a3[i] = j;
		}
		std::cout << "\nPrinting a2\n";
		for (unsigned int i = 0; i < a2.size(); i++)
			std::cout << "a2[" << i << "] = " << a2[i] << std::endl;
		std::cout << "\nPrinting a3\n";
		for (unsigned int i = 0; i < a3.size(); i++)
			std::cout << "a3[" << i << "] = " << a3[i] << std::endl;
	}
	{
		divider("Copy Assignment Operator", GREEN);
		Array<int> a4(5);
		Array<int> a5 = a4;
		std::cout << "\nPrinting a4\n";
		for (unsigned int i = 0; i < a4.size(); i++)
			std::cout << "a4[" << i << "] = " << a4[i] << std::endl;
		std::cout << "\nPrinting a5\n";
		for (unsigned int i = 0; i < a5.size(); i++)
			std::cout << "a5[" << i << "] = " << a5[i] << std::endl;
		std::cout << "\nAdding value 42 in a5[2]!" << std::endl;
		a5[2] = 42;
		std::cout << "\nPrinting a4\n";
		for (unsigned int i = 0; i < a4.size(); i++)
			std::cout << "a4[" << i << "] = " << a4[i] << std::endl;
		std::cout << "\nPrinting a5\n";
		for (unsigned int i = 0; i < a5.size(); i++)
			std::cout << "a5[" << i << "] = " << a5[i] << std::endl;
	}
	{
		divider("Read and Write", BLUE);
		Array<int> a1(5);
		a1[0] = 42;
		std::cout << "a1[0] = " << a1[0] << std::endl;
	}
	{
		divider("Bounds check (expect exception)", YELLOW);
		Array<int> a1(42);
		try
		{
			std::cout << a1[999] << std::endl;
		}
		catch (std::exception const &e)
		{
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	{
		divider("Deep copy with copy-ctor", GREEN);
		Array<int> a1(42);
		Array<int> aCopy(a1);
		a1[0] = 7;
		std::cout << "a1[0]    = " << a1[0] << std::endl;
		std::cout << "aCopy[0] = " << aCopy[0] << std::endl;
	}
	{
		divider("Deep copy with assignment", BLUE);
		Array<std::string> as(3);
		as[0] = "alpha";
		as[1] = "beta";
		as[2] = "gamma";
		Array<std::string> bs;
		bs = as;
		as[1] = "BETA!";
		std::cout << "as[1] = " << as[1] << " | bs[1] = " << bs[1] << std::endl;
	}
}


// From Subject PDF Attachment
// #include <iostream>
// #include <Array.hpp>

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }

//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }