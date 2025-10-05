#include "whatever.hpp"

int main( void )
{
	std::cout << YELLOW << "================== FROM PDF =====================\n" << RESET;
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << YELLOW << "================== ADDITIONAL TESTS — CONST =====================\n" << RESET;

	// -----------------------------------------------------------------
	// 1) const ints
	//    min/max should accept const arguments and return const T&
	// -----------------------------------------------------------------
	const int ca = 42;
	const int cb = 24;

	std::cout << "ca = " << ca << ", cb = " << cb << std::endl;
	std::cout << "min( ca, cb ) = " << ::min( ca, cb ) << std::endl;
	std::cout << "max( ca, cb ) = " << ::max( ca, cb ) << std::endl;

	// Bind the result to a const reference to ensure it’s truly const
	const int & cref_min_ic = ::min( ca, cb );
	const int & cref_max_ic = ::max( ca, cb );
	std::cout << "cref_min_ic = " << cref_min_ic << ", cref_max_ic = " << cref_max_ic << std::endl;

	// -----------------------------------------------------------------
	// 2) const std::string
	// -----------------------------------------------------------------
	const std::string sc = "alpha";
	const std::string sd = "beta";

	std::cout << "sc = " << sc << ", sd = " << sd << std::endl;
	std::cout << "min( sc, sd ) = " << ::min( sc, sd ) << std::endl;
	std::cout << "max( sc, sd ) = " << ::max( sc, sd ) << std::endl;

	const std::string & cref_min_sc = ::min( sc, sd );
	const std::string & cref_max_sd = ::max( sc, sd );
	std::cout << "cref_min_sc = " << cref_min_sc << ", cref_max_sd = " << cref_max_sd << std::endl;

	// -----------------------------------------------------------------
	// 3) Mixed const / non-const arguments
	//    Should still compile: parameters are T const& so both bind.
	// -----------------------------------------------------------------
	int nx = 5;
	const int ny = 7;

	std::cout << "nx = " << nx << ", ny = " << ny << std::endl;
	std::cout << "min( nx, ny ) = " << ::min( nx, ny ) << std::endl;
	std::cout << "min( ny, nx ) = " << ::min( ny, nx ) << std::endl;
	std::cout << "max( nx, ny ) = " << ::max( nx, ny ) << std::endl;
	std::cout << "max( ny, nx ) = " << ::max( ny, nx ) << std::endl;

	// You can bind results to const refs (they are const T&).
	const int & cref_mixed_min = ::min( nx, ny );
	const int & cref_mixed_max = ::max( ny, nx );
	std::cout << "cref_mixed_min = " << cref_mixed_min << ", cref_mixed_max = " << cref_mixed_max << std::endl;

	return 0;
}

/*
	Expected Output
	a = 3, b = 2
	min(a, b) = 2
	max(a, b) = 3
	c = chaine2, d = chaine1
	min(c, d) = chaine1
	max(c, d) = chaine2

*/