/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 21:52:01 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/12 17:41:48 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

// ================================= const ================================== //

# define MSG_ERR_FAIL_READ_DATA "Fail to read DATA !!"

// --------------------------------- color ---------------------------------- //

# define ESC_RESET              "\033[0m"
# define FNT_BOLD               "\033[1m"
# define CLR_RED                "\033[38;5;01m"
# define CLR_YELLOW             "\033[38;5;03m"

// ================================ library ================================= //

# include <iostream>
# include <iomanip>
# include <string>
# include <stdlib.h>

// ================================= class ================================== //

class Contact
{
    private:
        // [ variable ]
        int         _serialNumber;
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;
        // [ method ]
        bool        _isNumber(const std::string &fieldData);
        void        _setField(std::string fieldName, std::string &fieldData, bool isNumber);
        void        _printField(std::string fieldName, std::string fieldData);
        void        _printIndexForSearch(int index);
        void        _printFieldForSearch(std::string fieldData);
    public:
        // [ constructor / destructor ]
        Contact();
        ~Contact();
        // [ method ]
        void        initFields();
        void        setFields(int contactID);
        void        printFields();
        void        printFieldsForSearch(int index);
        // [ getter / setter ]
        int         getSerialNumber();
};

#endif
