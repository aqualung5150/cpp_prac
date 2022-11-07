#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int raw_bits;
    static const int f_bit = 8;
public:
    Fixed()
    : raw_bits(0)
    {
        std::cout << "Default constructor called" << std::endl;
    }

    Fixed(const int n)
    : raw_bits(n * (1 << f_bit))
    {
        std::cout << "Int constructor called" << std::endl;
    }

    Fixed(const float f)
    : raw_bits(roundf(f * (1 << f_bit)))
    {
        std::cout << "Float constructor called" << std::endl;
    }

    Fixed(const Fixed &fixed)
    {
        std::cout << "Copy constructor called" << std::endl;
        *this = fixed;
    }

    ~Fixed()
    {
        std::cout << "Destructor called" << std::endl;
    }

    Fixed& operator=(const Fixed& fixed)
    {
        std::cout << "Copy assignment operator called" << std::endl;

        if(this == &fixed)
            return *this;

        raw_bits = fixed.raw_bits;

        return *this;
    }

    int getRawBits(void) const
    {
        return raw_bits;
    }

    void setRawBits(int const raw)
    {
        raw_bits = raw;
    }

    float toFloat(void) const
    {
        return (float)raw_bits / (float)(1 << f_bit);
    }

    int toInt(void) const
    {
        return raw_bits >> f_bit;
    }
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
    out << (float)fixed.getRawBits() / (float)(1 << 8);

    return out;
}

#endif