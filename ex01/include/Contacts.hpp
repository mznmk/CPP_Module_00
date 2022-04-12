/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 21:53:00 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/12 17:41:50 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
# define CONTACTS_HPP

// ================================= const ================================== //

# define DataCount                  8
# define MSG_ERR_FAIL_READ_INDEX    "Fail to read INDEX !!"

// --------------------------------- color ---------------------------------- //

# define ESC_RESET                  "\033[0m"
# define FNT_BOLD                   "\033[1m"
# define CLR_RED                    "\033[38;5;01m"
# define CLR_GREEN                  "\033[38;5;02m"

// ================================ library ================================= //

#include "../include/Contact.hpp"

// ================================= class ================================== //

class	Contacts
{
    private:
        // [ variable ]
        Contact _contacts[DataCount];
        int     _serialNumber;
        // [ method ]
        void    _initContacts();
        int     _searchWritableIndex();
        void    _printContactsForSearch();
        void    _readIndexForSearch();
    public:
        // [ constructor / destructor ]
        Contacts();
        ~Contacts();
        // [ method ]
        void    addContact();
        void    searchContact();
};

#endif
