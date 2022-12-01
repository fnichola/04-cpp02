/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 01:47:40 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/01 02:39:49 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define BYEL "\e[1;33m"
#define RST "\033[0m"

float fabs(float num)
{
	if (num < 0)
		return num * (-1);
	return num;
}

std::string toBinary(const int num)
{
	(void)num;
	std::string bString;
	for (int i = sizeof(int) * __CHAR_BIT__ - 1; i >= 0; --i)
	{
		const char bit = (((unsigned int)num & (1 << i)) >> i) + '0';
		bString.push_back(bit);
	}
	return bString;
}

void test_add(const float a, const float b, int line)
{
	float test = (Fixed(a) + Fixed(b)).toFloat();
	float ref = a + b;
	if (fabs(test - ref) > fabs(0.01 * ref))
		std::cout << RED;
	else
		std::cout << GRN;
	std::cout << line << ": " << a << " + " << b << " = ";
	std::cout << test << " (" << ref << ")" << std::endl;
	std::cout << RST;
	std::cout << "------------------------------------------" << std::endl;
}

void test_subtract(const float a, const float b, int line)
{
	float test = (Fixed(a) - Fixed(b)).toFloat();
	float ref = (a - b);
	if (fabs(test -ref) > fabs(0.01 * ref))
		std::cout << RED;
	else
		std::cout << GRN;
	std::cout << line << ": " << a << " - " << b << " = ";
	std::cout << test << " (" << ref << ")" << std::endl;
	std::cout << RST;
	std::cout << "------------------------------------------" << std::endl;
}

void test_multiply(const float a, const float b, int line)
{
	float test = (Fixed(a) * Fixed(b)).toFloat();
	float ref = (a * b);
	if (fabs(test - ref) > fabs(0.01 * ref))
		std::cout << RED;
	else
		std::cout << GRN;
	std::cout << line << ": " << a << " * " << b << " = ";
	std::cout << test << " (" << ref << ")" << std::endl;
	std::cout << RST;
	std::cout << "------------------------------------------" << std::endl;
}

void test_divide(const float a, const float b, int line)
{
	float test = (Fixed(a) / Fixed(b)).toFloat();
	float ref = (a / b);
	if (fabs (test - ref) > fabs(0.02 * ref))
		std::cout << RED;
	else
		std::cout << GRN;
	std::cout << line << ": " << a << " / " << b << " = ";
	std::cout << test << " (" << ref << ")" << std::endl;
	std::cout << RST;
	std::cout << "------------------------------------------" << std::endl;
}

void test_min(float a, float b, int line)
{
	Fixed fa = Fixed(a);
	Fixed fb = Fixed(b);
	float test = Fixed::min(fa, fb).toFloat();
	float ref = std::min(a, b);
	if (fabs (test - ref) > fabs(0.02 * ref))
		std::cout << RED;
	else
		std::cout << GRN;
	std::cout << line << ": min(" << a << ", " << b << ") = ";
	std::cout << test << " (" << ref << ")" << std::endl;
	std::cout << RST;
	std::cout << "------------------------------------------" << std::endl;
}

void test_max(float a, float b, int line)
{
	Fixed fa = Fixed(a);
	Fixed fb = Fixed(b);
	float test = Fixed::max(fa, fb).toFloat();
	float ref = std::max(a, b);
	if (fabs (test - ref) > fabs(0.02 * ref))
		std::cout << RED;
	else
		std::cout << GRN;
	std::cout << line << ": max(" << a << ", " << b << ") = ";
	std::cout << test << " (" << ref << ")" << std::endl;
	std::cout << RST;
	std::cout << "------------------------------------------" << std::endl;
}

void test_min_const(const float a, const float b, int line)
{
	const Fixed fa = Fixed(a);
	const Fixed fb = Fixed(b);
	float test = Fixed::min(fa, fb).toFloat();
	float ref = std::min(a, b);
	if (fabs (test - ref) > fabs(0.02 * ref))
		std::cout << RED;
	else
		std::cout << GRN;
	std::cout << line << ": min(" << a << ", " << b << ") = ";
	std::cout << test << " (" << ref << ")" << std::endl;
	std::cout << RST;
	std::cout << "------------------------------------------" << std::endl;
}

void test_max_const(const float a, const float b, int line)
{
	const Fixed fa = Fixed(a);
	const Fixed fb = Fixed(b);
	float test = Fixed::max(fa, fb).toFloat();
	float ref = std::max(a, b);
	if (fabs (test - ref) > fabs(0.02 * ref))
		std::cout << RED;
	else
		std::cout << GRN;
	std::cout << line << ": max(" << a << ", " << b << ") = ";
	std::cout << test << " (" << ref << ")" << std::endl;
	std::cout << RST;
	std::cout << "------------------------------------------" << std::endl;
}

void test_pre_increment(float a, int line)
{
	Fixed fa = Fixed(a);
	Fixed fa2 = Fixed(a);

	std::cout << "++a, a = " << a << std::endl;
	std::cout << line << ": " << toBinary((fa).getRawBits()) << "  " << fa2 << std::endl;
	std::cout << line << ": " << toBinary((++fa).getRawBits()) << "  " << ++fa2 << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}

void test_post_increment(float a, int line)
{
	Fixed fa = Fixed(a);
	Fixed fa2 = Fixed(a);

	std::cout << "a++, a = " << a << std::endl;
	std::cout << line << ": " << toBinary((fa++).getRawBits()) <<  "  " << fa2++ << std::endl;
	std::cout << line << ": " << toBinary((fa).getRawBits()) <<  "  " << fa2 << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}

void test_pre_decrement(float a, int line)
{
	Fixed fa = Fixed(a);
	Fixed fa2 = Fixed(a);

	std::cout << "--a, a = " << a << std::endl;
	std::cout << line << ": " << toBinary((fa).getRawBits()) << "  " << fa2 << std::endl;
	std::cout << line << ": " << toBinary((--fa).getRawBits()) << "  " << --fa2 << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}

void test_post_decrement(float a, int line)
{
	Fixed fa = Fixed(a);
	Fixed fa2 = Fixed(a);

	std::cout << "a--, a = " << a << std::endl;
	std::cout << line << ": " << toBinary((fa--).getRawBits()) <<  "  " << fa2-- << std::endl;
	std::cout << line << ": " << toBinary((fa).getRawBits()) <<  "  " << fa2 << std::endl;
	std::cout << "------------------------------------------" << std::endl;
}

int main()
{
	std::cout << BYEL;
	std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
	std::cout << "Basic Tests:" << std::endl;
	std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
	std::cout << RST;
	Fixed a;
	Fixed const b( Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;

	std::cout << std::endl << BYEL;
	std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
	std::cout << "Additional Tests:" << std::endl;
	std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
	std::cout << RST;
	test_add(1.5, 3, __LINE__);
	test_add(8388607, 0, __LINE__);
	test_add(8388607, 42, __LINE__); // should overflow
	test_add(0, 8388607, __LINE__);
	test_add(0.99609375, 8388607, __LINE__);
	test_add(0.998046875, 8388607, __LINE__); // should overflow

	test_subtract(1.5, 3, __LINE__);
	test_subtract(8388607, 0, __LINE__);
	test_subtract(8388607, 42, __LINE__);
	test_subtract(0, 8388607, __LINE__);
	test_subtract(0.99609375, 8388607, __LINE__);
	test_subtract(0.998046875, 8388607, __LINE__);

	test_divide(2, 3, __LINE__);
	test_divide(2, 0, __LINE__);
	test_divide(3, 2, __LINE__);
	test_divide(2, 0.5, __LINE__);
	test_divide(3, 0.1, __LINE__);
	test_divide(2, 0.5, __LINE__);
	test_divide(-1, 2, __LINE__);
	test_divide(-1.1, -0.3, __LINE__);
	test_divide(10.004, 1, __LINE__);
	test_divide(10.004, 2, __LINE__);
	test_divide(10.004, -1, __LINE__);
	test_divide(10.004, -2, __LINE__);
	test_divide(-10.004, 1, __LINE__);
	test_divide(-10.004, 2, __LINE__);
	test_divide(-10.004, -1, __LINE__);
	test_divide(-10.004, -2, __LINE__);

	test_multiply(5.05f, 2, __LINE__);
	test_multiply(-1, 2, __LINE__);
	test_multiply(-1.5, 2, __LINE__);
	test_multiply(-7, 13, __LINE__);
	test_multiply(7, 13, __LINE__);
	test_multiply(-3, 13, __LINE__);
	test_multiply(1.1, -0.3, __LINE__);
	test_multiply(1.1, 0.3, __LINE__);
	test_multiply(1.004, 1.004, __LINE__);
	test_multiply(2.5, 1.25, __LINE__);
	test_multiply(2.5, 0.125, __LINE__);
	test_multiply(1.25, 2.5, __LINE__);
	test_multiply(0.125, 2.5, __LINE__);
	test_multiply(10.004, 1, __LINE__);
	test_multiply(10.004, 2, __LINE__);

	test_min(0, 0, __LINE__);
	test_min(42, 0, __LINE__);
	test_min(0, 42, __LINE__);
	test_min(42, -42, __LINE__);
	test_min(1.5, .25, __LINE__);
	test_min(.25, 1.5, __LINE__);
	test_min(8388607, 42, __LINE__);
	test_min(8388607, -99999999, __LINE__); // should overflow
	test_min(-8388606, 1.5, __LINE__);

	test_max(0, 0, __LINE__);
	test_max(42, 0, __LINE__);
	test_max(0, 42, __LINE__);
	test_max(42, -42, __LINE__);
	test_max(1.5, .25, __LINE__);
	test_max(.25, 1.5, __LINE__);
	test_max(8388607, 42, __LINE__);
	test_max(8388607, -99999999, __LINE__); // should overflow
	test_max(-8388606, 1.5, __LINE__);

	test_min_const(0, 0, __LINE__);
	test_min_const(42, 0, __LINE__);
	test_max_const(0, 0, __LINE__);
	test_max_const(42, 0, __LINE__);

	test_pre_increment(0, __LINE__);
	test_pre_increment(42, __LINE__);
	test_pre_increment(-42, __LINE__);
	test_pre_increment(8388607, __LINE__);
	test_pre_increment(8388607.99609375, __LINE__);

	test_post_increment(0, __LINE__);
	test_post_increment(42, __LINE__);
	test_post_increment(-42, __LINE__);
	test_post_increment(8388607, __LINE__);
	test_post_increment(8388607.99609375, __LINE__);

	test_pre_decrement(0, __LINE__);
	test_pre_decrement(42, __LINE__);
	test_pre_decrement(-42, __LINE__);
	test_pre_decrement(8388607, __LINE__);
	test_pre_decrement(8388607.99609375, __LINE__);

	test_post_decrement(0, __LINE__);
	test_post_decrement(42, __LINE__);
	test_post_decrement(-42, __LINE__);
	test_post_decrement(8388607, __LINE__);
	test_post_decrement(8388607.99609375, __LINE__);

	return 0;
}
