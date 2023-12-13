/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:10:10 by lboulatr          #+#    #+#             */
/*   Updated: 2023/12/12 13:15:59 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Array.hpp>
#define MAX_VAL 750

// int main()
// {
//     int *a = new int();
//     std::cout << "a = " << *a << std::endl;

//     Array<int> numbers(5);
//     const Array<int> numbers2(5);

//     std::cout << numbers2[0] << std::endl;

//     for (int i = 0; i < 5; i++)
//     {
//         numbers[i] = i;
//         std::cout << numbers[i] << std::endl;
//     }

//     std::cout << "\ncopy:" << std::endl;

//     Array<int> copy(numbers);

//     for (int i = 0; i < 5; i++)
//     {
//         copy[i] = i;
//         std::cout << copy[i] << std::endl;
//     }

//     std::cout << "\nmodif and print on copy:" << std::endl;

//     for (int i = 0; i < 5; i++)
//     {
//         copy[i] *= 100;
//         std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
//         std::cout << "copy   [" << i << "] = " << copy[i] << std::endl;
//     }

//     std::cout << "\nouf of bonds test:" << std::endl;
//     int x = 0;
//     int y = 2;
//     int z = -2;
//     int za = 45;
//     try
//     {
//         numbers[x] = 50;
//         std::cout << "numbers[" << x << "] = " << numbers[x] << std::endl;
//         numbers[y] = 250;
//         std::cout << "numbers[" << y << "] = " << numbers[y] << std::endl;
//         numbers[z] = 500;
//         std::cout << "numbers[" << z << "] = " << numbers[z] << std::endl;
//         numbers[za] = 1000;
//         std::cout << "numbers[" << za << "] = " << numbers[za] << std::endl;
//     }
//     catch(const std::exception& e)
//     {
//         std::cout << e.what() << std::endl;
//     }
//     delete a;
// }

int main(int, char**)
{
    const Array<int> num(MAX_VAL);
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    Array<int> tmp = numbers;
    Array<int> test(tmp);
    for (int i = 0; i < MAX_VAL; i++)
    {
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
        std::cout << "mirror[" << i << "] = " << mirror[i] << std::endl;
        std::cout << "tmp[" << i << "] = " << tmp[i] << std::endl;
        std::cout << "test[" << i << "] = " << test[i] << std::endl;
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}