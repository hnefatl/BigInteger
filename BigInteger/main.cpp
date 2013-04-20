#include <iostream>
#include <conio.h>

#include "BigInteger.h"

int main()
{
	BigInteger Number1("157351684213513543203151");
	BigInteger Number2("305489845315469846854135");
	BigInteger Answer("462841529528983390057286");

	std::cout<<((Number1+Number2)==Answer)<<std::endl;

	_getch();

    return 0;
}
