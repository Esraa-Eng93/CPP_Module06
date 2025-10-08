/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esraa <esraa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:41:54 by ealshorm          #+#    #+#             */
/*   Updated: 2025/10/07 18:29:52 by esraa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

# include <iostream>
# include <limits>
# include <cmath>
# include <cstdlib>

using std::string;
using std::cout;
using std::endl;
using std::numeric_limits;
enum Type {CHAR, INT, FLOAT, DOUBLE, UNKNOWN};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& cpy_ptr);
		ScalarConverter& operator=(const ScalarConverter& cpy_ptr);
		~ScalarConverter();
	public:
		static bool isDisplayableChar(int value);
		static Type literals_type(const string &input);
        static void convert(const string &input);

        static void toChar(double value);
        static void toInt(double value);
        static void toFloat(double value);
        static void toDouble(double value);
};

#endif