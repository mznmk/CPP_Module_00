/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:53:01 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/08 23:21:51 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    if (argc <= 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    else {
        for (int i = 1; i < argc; i++) {
            std::string str = argv[i];
            for (size_t j = 0; j < str.length(); j++) {
                std::cout << (char)std::toupper(str[j]);
            }
        }
    }
    std::cout << std::endl;
    return (0);
}
