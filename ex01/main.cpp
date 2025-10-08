/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esraa <esraa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:41:54 by ealshorm          #+#    #+#             */
/*   Updated: 2025/10/07 18:28:32 by esraa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	data *d = new data;;
	d->value = 42;
	uintptr_t raw = Serializer::serialize(d);
	data *ptr = Serializer::deserialize(raw);
	cout << "Before Sreializer: " << d->value << endl;
	cout << "After Sreializer: " << raw << endl;
	cout << "After deserializer: " << ptr->value << endl;

	delete (d);
	return (0); 
}

