/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnichola <fnichola@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 02:49:52 by fnichola          #+#    #+#             */
/*   Updated: 2022/11/28 10:50:25 by fnichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
public:
	Fixed();
	Fixed(const Fixed& src);
	~Fixed();
	Fixed& operator=(const Fixed& rhs);

	int getRawBits() const;
	void setRawBits(int const raw);

private:
	int m_value;
	static const int m_binaryPoint = 8;
};

#endif
