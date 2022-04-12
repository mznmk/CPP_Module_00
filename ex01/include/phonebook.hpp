/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 07:58:59 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/12 16:46:01 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

// ================================= const ================================== //

# define MSG_USAGE_DESCRIPTION      "./phonebook (need not argument)"
# define MSG_ERR_FAIL_READ_COMMAND  "Fail to read COMMAND !!"

// --------------------------------- color ---------------------------------- //

# define ESC_RESET                  "\033[0m"
# define FNT_BOLD                   "\033[1m"
# define CLR_RED                    "\033[38;5;01m"
# define CLR_GREEN                  "\033[38;5;02m"
# define CLR_CYAN                   "\033[38;5;06m"

// ================================ library ================================= //

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>

#include "Contacts.hpp"

#endif
