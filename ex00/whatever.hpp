#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>
# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define YELLOW "\033[33m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define WHITE "\033[37m"
# define RESET "\033[0m"

/*
	Template must be in header so the compiler can see the definition

	"typename" and "class" are synonyms
	template <typename T> // same as template <class T>
	
	The following is a function template

*/
template <typename T>
void	swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

// read-write version (non-const refs)
template <typename T>
T &min(T &a, T &b)
{
	if (a < b)
		return (a);
	return (b);
}

// read-only version (const refs)
template <typename T>
const T &min(const T &a, const T &b)
{
	if (a < b)
		return (a);
	return (b);
}

// read-write version (non-const refs)
template <typename T>
T &max(T &a, T &b)
{
	if (a > b)
		return (a);
	return (b);
}

// read-only version (const refs)
template <typename T>
const T &max(const T &a, const T &b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif