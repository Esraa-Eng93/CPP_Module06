/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esraa <esraa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:41:54 by ealshorm          #+#    #+#             */
/*   Updated: 2025/10/07 20:54:48 by esraa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <ctime>

Base * generate(void)
{
	srand(time(NULL));
	int i = rand() % 3;
	if (i == 0)
		return (new A);
	else if ( i == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base* p)
{
	//It prints the actual type of the object pointed to by p: "A", "B", or "C".
	if (dynamic_cast<A*>(p)) // we use if becuse if faild it will return nullptr
		cout << "A" << endl;
	else if (dynamic_cast<B*>(p))
		cout << "B" << endl;
	else if (dynamic_cast<C*>(p))
		cout << "C" << endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		cout << "A" << endl;
	}
	catch(const std::exception& e){}
	try
	{
		(void)dynamic_cast<B&>(p);
		cout << "B" << endl;
	}
	catch(const std::exception& e){}
	try
	{
		(void)dynamic_cast<C&>(p);
		cout << "C" << endl;
	}
	catch(const std::exception& e){}
	
}
int main()
{
	
	Base *a = generate();
	identify(a);
	identify(*a);
	delete a;
	return (0); 
}

