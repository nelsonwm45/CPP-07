#include "iter.hpp"

int	main()
{
	{
		std::cout << GREEN << "=========== INT ===========" << RESET << std::endl;
		int	array[] = {2, 6, 8};
		::iter(array, 3, printComponent<int>);

		std::cout << RED << "\n=========== Increment by 5 ===========" << RESET << std::endl;
		::iter(array, 3, incrementAllComponents<int>);
		::iter(array, 3, printComponent<int>);
		std::cout << std::endl << std::endl << std::endl;
	}
	{
		std::cout << GREEN << "=========== CHAR ===========" << RESET << std::endl;
		char	array[] = {'a', 'b', 'c'};
		::iter(array, 3, printComponent<char>);
		std::cout << RED << "\n=========== Increment by 5 ===========" << RESET << std::endl;
		::iter(array, 3, incrementAllComponents<char>);
		::iter(array, 3, printComponent<char>);
		std::cout << std::endl << std::endl << std::endl;
	}
	{
		std::cout << GREEN << "=========== CHAR ===========" << RESET << std::endl;
		char	array[] = {'a', 'b', 'c'};
		::iter(array, 3, printComponent<char>);
		std::cout << RED << "\n=========== Capitalise Character ===========" << RESET << std::endl;
		::iter(array, 3, capitaliseCharacter);
		::iter(array, 3, printComponent<char>);
		std::cout << std::endl << std::endl << std::endl;
	}
	{
		std::cout << GREEN << "=========== DOUBLE ===========" << RESET << std::endl;
		double	array[] = {1.6, 3.2, 5.0};
		::iter(array, 3, printComponent<double>);
		std::cout << RED << "\n=========== Increment by 5 ===========" << RESET << std::endl;
		::iter(array, 3, incrementAllComponents<double>);
		::iter(array, 3, printComponent<double>);
		std::cout << std::endl << std::endl << std::endl;
	}
	{
		std::cout << GREEN << "=========== FLOAT ===========" << RESET << std::endl;
		float	array[] = {0.8f, 2.2f, 5.1f};
		::iter(array, 3, printComponent<float>);
		std::cout << RED << "\n=========== Increment by 5===========" << RESET << std::endl;
		::iter(array, 3, incrementAllComponents<float>);
		::iter(array, 3, printComponent<float>);
		std::cout << std::endl << std::endl << std::endl;
	}
	{
		std::cout << GREEN << "=========== STRING ===========" << RESET << std::endl;
		std::string	array[] = {"bestie", "cat", "dog"};
		::iter(array, 3, printComponent<std::string>);
		std::cout << RED << "\n=========== Capitalise First ===========" << RESET << std::endl;
		::iter(array, 3, capitaliseFirst);
		::iter(array, 3, printComponent<std::string>);
		std::cout << std::endl << std::endl << std::endl;
	}
	{
		std::cout << GREEN << "=========== STRING ===========" << RESET << std::endl;
		std::string	array[] = {"PENGUIN", "CAT", "DOG"};
		::iter(array, 3, printComponent<std::string>);
		std::cout << RED << "\n=========== Lowercase All ===========" << RESET << std::endl;
		::iter(array, 3, lowercaseString);
		::iter(array, 3, printComponent<std::string>);
		std::cout << std::endl << std::endl << std::endl;
	}
}