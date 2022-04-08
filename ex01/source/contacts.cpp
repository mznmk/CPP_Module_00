/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 21:52:54 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/08 19:17:34 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/contacts.hpp"

// ======================== constructor / destructor ======================== //

Contacts::Contacts()
{
    _initContacts();
}

Contacts::~Contacts()
{
}

// ===================== private method (_initContacts) ===================== //

/*!
** @brief	initialize contacts
** @param	none
** @return	none
*/
void    Contacts::_initContacts()
{
    _serialNumber = 0;
    for (int i = 0; i < DataCount; i++) {
        _contacts[i].initFields();
    }
}

// ======================= public method (addContact) ======================= //

/*!
** @brief	search writable index of contacts
** @param	none
** @return	writable index of contacts
*/
int     Contacts::_searchWritableIndex()
{
    int     writableSerial;
    int     writableIndex;
    writableSerial = _contacts[0].getSerialNumber();
    writableIndex = 0;
    for (int i = 0; i < DataCount; i++)
    {
        if (_contacts[i].getSerialNumber() < writableSerial) {
            writableSerial = _contacts[i].getSerialNumber();
            writableIndex = i;
        }
    }
    return (writableIndex);
}

/*!
** @brief	add/update contact
** @param	none
** @return	none
*/
void    Contacts::addContact()
{
    // [ search writable contact ]
    int     writableIndex;
    writableIndex = _searchWritableIndex();
    // [ add/update contact ]
    _serialNumber++;
    _contacts[writableIndex].setFields(_serialNumber);
}

// ===================== public method (searchContact) ====================== //

/*!
** @brief	print contacts for search (index / 3 kind of name)
** @param	none
** @return	none
*/
void    Contacts::_printContactsForSearch()
{
    // [ print contact field name for search ]
    std::cout << "|";
    std::cout << "     Index|";
    std::cout << "FIRST NAME|";
    std::cout << " LAST NAME|";
    std::cout << " NICK NAME|";
    std::cout << std::endl;
    
    // [ print contact field data for search ]
    // (index range 1-8, not 0-7)
    for (int i = 0; i < DataCount; i++) {
        _contacts[i].printFieldsForSearch(i + 1);
    }
}

/*!
** @brief   read index for search
** @param   none
** @return  none
*/
void    Contacts::_readIndexForSearch()
{
    // [ variables ]
    std::string strIndex;
    int         intIndex;

    // [ read index until index is to be suitable value ]
    while (42)
    {
        // [ print prompt ]
        std::cout << FNT_BOLD CLR_GREEN << "Enter Index > " << ESC_RESET;
        // [ read index from stdin ]
        std::getline(std::cin, strIndex);
        if (std::cin.fail()) {
            std::cout << FNT_BOLD CLR_RED << MSG_ERR_FAIL_READ_INDEX << ESC_RESET << std::endl;
            exit(EXIT_FAILURE);
        }
        // check index is empty?
        if (strIndex.empty()) {
            continue;
        }
        // convert string to int
        intIndex = std::atoi(strIndex.c_str());
        // check index is in range
        // (index range 1-8, not 0-7)
        if (1 <= intIndex && intIndex <= DataCount) {
            // print field data
            if (_contacts[intIndex - 1].getSerialNumber())
            {
                _contacts[intIndex - 1].printFields();
                break;
            }
        } else {
            continue;
        }
    }
}

/*!
** @brief	search contact
** @param	none
** @return	none
*/
void    Contacts::searchContact()
{
    // [ contact exist ? ]
    if (!_serialNumber) {
        return;
    }
    // [ print contacts for search ]
    _printContactsForSearch();
    // [ print field data ]
    _readIndexForSearch();
}
