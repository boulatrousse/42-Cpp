/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:53:58 by lboulatr          #+#    #+#             */
/*   Updated: 2023/11/27 11:14:53 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>
# include <string.h>

template <typename T>
class Array
{
    public:
    
        Array(void)
        {
            this->_array = new T[0];
            this->_size = 0;
        };
        
        Array(unsigned int n)
        {
            this->_array = new T[n];
            memset(this->_array, 0, n * sizeof(T));
            this->_size = n;
        };

        ~Array(void)
        {
            delete [] this->_array;
        };
        
        Array(Array const &src)
        {
            this->_array = new T[src._size];
            this->_size = src._size;
            for (int i = 0; i < src._size; i++)
                this->_array[i] = src._array[i];
        };
        
        Array &operator=(Array const &src)
        {
            if (this != &src)
            {
                delete [] this->_array;
                this->_array = new T[src._size];
                this->_size = src._size;
                for (int i = 0; i < src._size; i++)
                    this->_array[i] = src._array[i];
            }
            return (*this);
        };

        T &operator[](int i) const
        {
            if (i < 0 || i >= this->_size)
                throw Array::OutOfBounds();
            return (this->_array[i]);
        };
        
        int size(void) const
        {
            return (this->_size);
        };

        class OutOfBounds : public std::exception
        {
            public:
                virtual const char      *what() const throw()
                {
                    return ("\033[1;31mOut of bounds\033[0m");
                };
        }; 

    private:

        T	            *_array;
        int	            _size;
};

#endif