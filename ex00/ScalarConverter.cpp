/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esraa <esraa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:41:54 by ealshorm          #+#    #+#             */
/*   Updated: 2025/10/06 00:54:21 by esraa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}
ScalarConverter::ScalarConverter(const ScalarConverter& cpy_ptr)
{
	*this = cpy_ptr;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& cpy_ptr)
{
	(void)cpy_ptr;
	return(*this);
}
ScalarConverter::~ScalarConverter()
{
}
bool ScalarConverter::isDisplayableChar(int value)
{
	return(value >= 32 && value <= 126);
}
Type ScalarConverter::literals_type(const string &input)
{
	Type type = UNKNOWN;
	if (input == "nan" || input == "+nan" || input == "-nan"
		|| input == "inf" || input == "+inf" || input == "-inf")
		type = DOUBLE;
	else if (input == "nanf" || input == "+nanf" || input == "-nanf"
		|| input == "inff" || input == "+inff" || input == "-inff")
		type = FLOAT;
	else if (input.length() == 1 && isprint(input[0]) && !isdigit(input[0]))
		type = CHAR;
	else if (!input.empty() && input[input.length() - 1] == 'f' && input.find('.') != string::npos)
		type = FLOAT;
	else if (input.find('.') != string::npos )
		type = DOUBLE;
	else
		type = INT;
	return (type);
}

void ScalarConverter::convert(const string &input)
{
	Type type = literals_type(input);
	try
	{
		switch (type)
		{
    		case CHAR:
			{	
				double c = static_cast<double>(input[0]);
        		toChar(c);
				toInt(c);
        		toFloat(c);
        		toDouble(c);
        		break;
			}
    		case INT:
    		{
        		char *end; // ptr to first worl cant conver
        		long val = std::strtol(input.c_str(), &end, 10);//long int
        		if (*end != '\0')
            		throw std::invalid_argument("Invalid int");
        		toChar(static_cast<double>(val));
        		toInt(static_cast<double>(val));
        		toFloat(static_cast<double>(val));
        		toDouble(static_cast<double>(val));
        		break;
    		}		
    		case FLOAT:
    		{
        		char *end;
        		float val = std::strtof(input.c_str(), &end);
        		if (*end != 'f' || *(end+1) != '\0')
            		throw std::invalid_argument("Invalid float");
        		toChar(static_cast<double>(val));
        		toInt(static_cast<double>(val));
        		toFloat(static_cast<double>(val));
        		toDouble(static_cast<double>(val));
        		break;
    		}
    		case DOUBLE:
    		{
        		char *end;
        		double val = std::strtod(input.c_str(), &end);
        		if (*end != '\0')
            		throw std::invalid_argument("Invalid double");
        		toChar(val);
        		toInt(val);
        		toFloat(val);
        		toDouble(val);
        		break;
    		}
    		default:
        		throw std::invalid_argument("Unknown type");
		}
	}

	catch(...)//this mean catch any type of execption
	{
		cout << "char: impossible" << endl;
		cout << "int: impossible" << endl;
		cout << "float: impossible" << endl;
		cout << "double: impossible" << endl;
		return;
	}
}
void ScalarConverter::toChar(double value)
{
	if (std::isnan(value) || std::isinf(value))
    {
        cout << "char: impossible" << endl;
        return;
    }
	char c = static_cast<char>(value);
	if (value > numeric_limits<char>::max() || value < numeric_limits<char>::min())
		cout << "char: impossible" << endl;
	else if (!ScalarConverter::isDisplayableChar(static_cast<int>(value)))
		cout << "char: Non displayable" << endl;
	else
		cout << "char: '" << c << "'" << endl;
	
}
void ScalarConverter::toInt(double value)
{
    if (std::isnan(value) || std::isinf(value)
        || value > numeric_limits<int>::max() 
        || value < numeric_limits<int>::min())
    {
        cout << "int: impossible" << endl;
        return;
    }
    int c = static_cast<int>(value);
    cout << "int: " << c << endl;
}
void ScalarConverter::toFloat(double value)
{
	float f = static_cast<float>(value);
	// NAN != NAN Always True according to IEEE-754(floting_point) like 0 /0 or seqr(-1) or inf - inf or inf / inf
	if (std::isnan(f))
        cout << "float: nanf" << endl;
	else if (std::isinf(f))
		cout << "float: " << (f > 0 ? "+inff ": "-inff" ) << endl;
	else 
		cout << "float: " << f << (f == static_cast<int>(f) ? ".0f" : "f") << endl;
}  
void ScalarConverter::toDouble(double value)
{
	if (std::isnan(value))
        cout << "double: nan" << endl;
	else if (std::isinf(value))
		cout << "double: " << (value > 0 ? "+inf ": "-inf" ) << endl;
	else 
		cout << "double: " << value << (value == static_cast<int>(value) ? ".0" : "") << endl;
}