#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstddef> // std::size_t
# include <string>
# include <stdexcept>
# include <cstdlib> // srand, rand
# include <ctime> // time

# define RED "\033[31m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define YELLOW "\033[33m"
# define CYAN "\033[36m"
# define MAGENTA "\033[35m"
# define WHITE "\033[37m"
# define RESET "\033[0m"

/*
	Class Template
*/
template <typename T>
class	Array
{
	private:
		T	*_arr;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		Array	&operator=(const Array &other);
		~Array();

		T &operator[](unsigned int index);
		const T &operator[](unsigned int index) const;

		unsigned int	size() const;

		class IndexOutofBounds: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

template <typename T>
Array<T>::Array():
	_arr(new T[0]()),
	_size(0)
{
	std::cout << "[Array]: Default Constructor is called. \n";
}

template <typename T>
Array<T>::Array(unsigned int n):
	_arr(new T[n]()),
	_size(n)
{
	std::cout << "[Array]: Parameter(Unsigned Int) Constructor is called. \n";
}

/*
	Construction by copy and assignment operator.
	In both cases, modifying either the original array or its copy after copying musn’t affect the other array.
*/
template <typename T>
Array<T>::Array(const Array &other):
	_arr(new T[other._size]()),
	_size(other._size)
{
	for (size_t i = 0; i < _size; i++)
		_arr[i] = other._arr[i];
	std::cout << "[Array]: Copy Constructor is called.\n";
}

/*
	delete [] helps to deallocate memory of an object array
*/
template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] this->_arr;
		this->_arr = new T[other._size]();
		for (size_t i = 0; i < other._size; i++)
			this->_arr[i] = other._arr[i];
		this->_size = other._size;
		std::cout << "[Array]: Copy Assignment Operator is called.\n";
	}
	return (*this);
}

/*
	Destructor should be deleting the array
*/
template <typename T>
Array<T>::~Array()
{
	std::cout << "[Array]: Destructor is called.\n";
	delete[] this->_arr;
}

// Elements can be accessed through the subscript operator: [ ].
// When accessing an element with the [ ] operator, if its index is out of bounds, an std::exception is thrown.
// Non-const version :: allow write
// a1[i] = 42 (WRITE)
template <typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw (Array<T>::IndexOutofBounds());
	return (this->_arr[index]);
}

// Const version : Allow read only
// std::cout << a1[i] << std:endl (READ)
template <typename T>
const T	&Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_size)
		throw (Array<T>::IndexOutofBounds());
	return (this->_arr[index]);
}

// A member function size() that returns the number of elements in the array.
// This member function takes no parameter and musn’t modify the current instance
template <typename T>
unsigned int	Array<T>::size() const
{
	return (this->_size);
}

template <typename T>
const char	*Array<T>::IndexOutofBounds::what() const throw()
{
	return ("[Array Exception] Index is out of bounds!");
}

#endif