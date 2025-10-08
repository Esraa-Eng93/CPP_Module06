/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esraa <esraa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:41:54 by ealshorm          #+#    #+#             */
/*   Updated: 2025/10/07 18:20:54 by esraa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}
Serializer::Serializer(const Serializer& cpy_ptr)
{
	*this = cpy_ptr;
}
Serializer& Serializer::operator = (const Serializer& cpy_ptr)
{
	(void) cpy_ptr;
	return (*this);
}
Serializer::~Serializer()
{}
uintptr_t Serializer::serialize(data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<data *>(raw));
}