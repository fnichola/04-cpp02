/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 10:23:49 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/01 01:18:14 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed()
: m_value(0)
{
}

Fixed::Fixed(const Fixed& src)
{
	*this = src;
}

Fixed::Fixed(const int value)
{
	m_value = value * (1 << m_binaryPoint);
}

Fixed::Fixed(const float floatValue)
{
	m_value = (int)roundf(floatValue * (1 << m_binaryPoint));
}

Fixed::~Fixed()
{
}

Fixed& Fixed::operator=(const Fixed& rhs)
{
	m_value = rhs.m_value;
	return *this;
}

int Fixed::getRawBits() const
{
	return m_value;
}

void Fixed::setRawBits(int const raw)
{
	m_value = raw;
}

float Fixed::toFloat() const
{
	return ((float)m_value / (1 << m_binaryPoint));
}

int Fixed::toInt() const
{
	return (m_value >> m_binaryPoint);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixedNum)
{
	os << fixedNum.toFloat();
	return os;
}

bool Fixed::operator<(const Fixed& rhs) const
{
	return (m_value < rhs.m_value);
}

bool Fixed::operator>(const Fixed& rhs) const
{
	return (m_value > rhs.m_value);
}

bool Fixed::operator<=(const Fixed& rhs) const
{
	return (m_value <= rhs.m_value);
}

bool Fixed::operator>=(const Fixed& rhs) const
{
	return (m_value >= rhs.m_value);
}

bool Fixed::operator==(const Fixed& rhs) const
{
	return (m_value == rhs.m_value);
}

bool Fixed::operator!=(const Fixed& rhs) const
{
	return (m_value != rhs.m_value);
}

Fixed Fixed::operator+(const Fixed& rhs) const
{
	Fixed result;
	result.setRawBits(m_value + rhs.m_value);
	return (result);
}

Fixed Fixed::operator-(const Fixed& rhs) const
{
	Fixed result;
	result.setRawBits(m_value - rhs.m_value);
	return (result);
}

Fixed Fixed::operator*(const Fixed& rhs) const
{
	Fixed result;
	result.setRawBits(((int64_t)m_value * (int64_t)rhs.m_value) / (1 << m_binaryPoint));
	return (result);
}

Fixed Fixed::operator/(const Fixed& rhs) const
{
	Fixed result(*this);

	result.setRawBits(((int64_t)m_value * (1 << m_binaryPoint)) / rhs.m_value);
	return (result);
}

Fixed& Fixed::operator++() // ++prefix
{
	++m_value;
	return *this;
}

Fixed& Fixed::operator--() // --prefix
{
	--m_value;
	return *this;
}

Fixed Fixed::operator++(int) // postfix++
{
	Fixed old(*this);
	operator++();
	return old;
}

Fixed Fixed::operator--(int) // postfix--
{
	Fixed old(*this);
	operator--();
	return old;

}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	if (b < a)
		return b;
	return a;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	if (b < a)
		return b;
	return a;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	if (b > a)
		return b;
	return a;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	if (b > a)
		return b;
	return a;
}
