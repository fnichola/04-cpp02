/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 02:49:52 by fnichola          #+#    #+#             */
/*   Updated: 2022/11/29 03:21:18 by fnichola         ###   ########.fr       */
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

private:
	int m_value;
	static const int m_binaryPoint = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixedNum);

#endif
