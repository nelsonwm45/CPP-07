#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <cstddef> // std::size_t
# include <string>
# include <cctype> // std::toupper

# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define YELLOW "\033[33m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define WHITE "\033[37m"
# define RESET "\033[0m"

/*
	Function template allows you to write algorithm once and have the compiler
		to generate a version for each data type you use with it
*/

/*
	Requirement:
		Implement a function template iter that takes 3 parameters and returns nothing.
			• The first parameter is the address of an array.
			• The second one is the length of the array.
			• The third one is a function that will be called on every element of the array.

	Const version: read-only operation on each element
*/
template <typename T>
void	iter(const T* array, const size_t len, void (*function)(const T &))
{
	if (array == NULL)
		return ;
	for (size_t i = 0; i < len; i++)
		function(array[i]);
}

/*
	Requirement:
	Implement a function template iter that takes 3 parameters and returns nothing.
		• The first parameter is the address of an array.
		• The second one is the length of the array.
		• The third one is a function that will be called on every element of the array.

	Non-const version: allows mutation of elements
*/
template <typename T>
void	iter(T* array, size_t len, void(*function)(T &))
{
	if (array == NULL)
		return ;
	for (size_t i = 0; i < len; i++)
		function(array[i]);
}

template <typename T>
void	printComponent(const T &component)
{
	std::cout << component << " ";
}

// Works for arithmetic types (int, char, float, double). We'll just not use it for std::string.
template <typename T>
void	incrementAllComponents(T &component)
{
	component += static_cast<T>(5);
}

/*
	Does not need template because only string can be capitalise
*/
void	capitaliseFirst(std::string &array)
{
	if (array.empty())
		return ;
	// cast to unsigned char before toupper to avoid UB on negative char values
	array[0] = std::toupper(static_cast<unsigned char>(array[0]));
}

void	capitaliseCharacter(char &c)
{
	c = std::toupper(static_cast<unsigned char>(c));
}

void	lowercaseString(std::string	&str)
{
	if (str.empty())
		return ;
	for (size_t i = 0; i < str.length(); i++)
		str[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(str[i])));
}
#endif