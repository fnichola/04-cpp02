/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 02:49:52 by fnichola          #+#    #+#             */
/*   Updated: 2022/12/01 01:18:06 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& src);
	Fixed(const int value);
	Fixed(const float floatValue);
	~Fixed();
	Fixed& operator=(const Fixed& rhs);

	int getRawBits() const;
	void setRawBits(int const raw);
	float toFloat() const;
	int toInt() const;

	bool operator<(const Fixed& rhs) const;
	bool operator>(const Fixed& rhs) const;
	bool operator<=(const Fixed& rhs) const;
	bool operator>=(const Fixed& rhs) const;
	bool operator==(const Fixed& rhs) const;
	bool operator!=(const Fixed& rhs) const;
	
	Fixed operator+(const Fixed& rhs) const;
	Fixed operator-(const Fixed& rhs) const;
	Fixed operator*(const Fixed& rhs) const;
	Fixed operator/(const Fixed& rhs) const;

	Fixed& operator++(); // ++prefix
	Fixed& operator--(); // --prefix
	Fixed operator++(int); // postfix++
	Fixed operator--(int); // postfix--

	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

private:
	int m_value;
	static const int m_binaryPoint = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixedNum);

#endif
