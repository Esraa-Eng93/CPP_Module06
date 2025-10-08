/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esraa <esraa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:41:54 by ealshorm          #+#    #+#             */
/*   Updated: 2025/10/07 18:25:38 by esraa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>

using std::cout;
using std::endl;

typedef struct
{
	int	value;
} data;


class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& cpy_ptr);
		Serializer& operator = (const Serializer& cpy_ptr);
		~Serializer();
	public:
		static uintptr_t serialize(data* ptr);
		static data* deserialize(uintptr_t raw);
};
