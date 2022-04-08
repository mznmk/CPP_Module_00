/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 21:52:15 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/08 19:11:08 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/contact.hpp"

// ======================== constructor / destructor ======================== //

Contact::Contact(void)
{
    initFields();
}

Contact::~Contact()
{
}

// ======================= public method (initFields) ======================= //

/*!
** @brief   initialize field data
** @param   none
** @return  none
*/
void Contact::initFields()
{
    _serialNumber = 0;
    _firstName = "";
    _lastName = "";
    _nickname = "";
    _phoneNumber = "";
    _darkestSecret = "";
}

// ======================= public method (setFields) ======================== //

/*!
** @brief   set field data
** @param   fieldName   contact field name (by value)
** @param   fieldData   contact field data (by reference)
** @return  none
*/
void Contact::_setField(std::string fieldName, std::string &fieldData)
{
    while (42)
    {
        // [ print prompt ]
        std::cout << FNT_BOLD CLR_YELLOW << "Enter your " << fieldName << " > " << ESC_RESET;
        // [ read data from stdin ]
        std::getline(std::cin, fieldData);
        if (std::cin.fail()) {
            std::cout << FNT_BOLD CLR_RED << MSG_ERR_FAIL_READ_DATA << ESC_RESET << std::endl;
            exit(EXIT_FAILURE);
        }
        if (!fieldData.empty()) {
            break;
        }
    }
}

/*!
** @brief   set all field data
** @param   serialNumber    serial number (unique number)
** @return  none
*/
void Contact::setFields(int serialNumber)
{
    _serialNumber = serialNumber;
    _setField("FIRST NAME", _firstName);
    _setField("LAST NAME", _lastName);
    _setField("NICK NAME", _nickname);
    _setField("PHONE NUMBER", _phoneNumber);
    _setField("DARKEST SECRET", _darkestSecret);
}

// ====================== public method (printFields) ======================= //

/*!
** @brief   print field data
** @param   fieldName   contact field name
** @param   fieldData   contact field data
** @return  none
*/
void Contact::_printField(std::string fieldName, std::string fieldData)
{
    std::cout << FNT_BOLD CLR_YELLOW << fieldName;
    std::cout << " : " << ESC_RESET;
    std::cout << fieldData;
    std::cout << std::endl;
}

/*!
** @brief	print all field data
** @param	none
** @return	none
*/
void Contact::printFields()
{
    _printField("FIRST NAME    ", _firstName);
    _printField("LAST NAME     ", _lastName);
    _printField("NICK NAME     ", _nickname);
    _printField("PHONE NUMBER  ", _phoneNumber);
    _printField("DARKEST SECRET", _darkestSecret);
}

// ================= public method (_printFieldForSearch) =================== //

/*!
** @brief	print contact index
** @param	index   contact field index (by reference)
** @return	none
*/
void Contact::_printIndexForSearch(int index)
{
    std::cout << std::setw(10) << std::right << std::setfill(' ') << index;
}

/*!
** @brief	print field data of contact (adjust string size)
** @param	fieldData   field data of contact
** @return	none
*/
void Contact::_printFieldForSearch(std::string fieldData)
{
    if (fieldData.size() <= 10) {
        std::cout << std::setw(10) << std::right << std::setfill(' ') << fieldData;
    }
    else {
        fieldData.resize(9);
        std::cout << fieldData << ".";
    }
}

/*!
** @brief	print all field data of contact (adjust string size)
** @param	index	contact index number
** @return	none
*/
void Contact::printFieldsForSearch(int index)
{
    // is data exist?
    if (!_serialNumber) {
        return;
    }
    // print contact field data for search
    std::cout << "|";
    _printIndexForSearch(index);
    std::cout << "|";
    _printFieldForSearch(_firstName);
    std::cout << "|";
    _printFieldForSearch(_lastName);
    std::cout << "|";
    _printFieldForSearch(_nickname);
    std::cout << "|" << std::endl;
}

// ============================= setter / getter ============================ //

int Contact::getSerialNumber()
{
    return (_serialNumber);
}
