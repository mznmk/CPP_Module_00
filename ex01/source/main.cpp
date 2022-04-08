/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmizuno <mmizuno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 21:41:18 by mmizuno           #+#    #+#             */
/*   Updated: 2022/04/08 18:58:55 by mmizuno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/phonebook.hpp"

/*!
** @brief   printTitle (ascii art)
** @param   none
** @return  none
*/
void    printTitle()
{
    std::cout << FNT_BOLD CLR_CYAN;
    std::cout << " ____  _                      ____              _" << std::endl;
    std::cout << "|  _ \\| |__   ___  _ __   ___| __ )  ___   ___ | | __" << std::endl;
    std::cout << "| |_) | '_ \\ / _ \\| '_ \\ / _ \\  _ \\ / _ \\ / _ \\| |/ /" << std::endl;
    std::cout << "|  __/| | | | (_) | | | |  __/ |_) | (_) | (_) |   <" << std::endl;
    std::cout << "|_|   |_| |_|\\___/|_| |_|\\___|____/ \\___/ \\___/|_|\\_\\" << std::endl;
    std::cout << "" << std::endl;
    std::cout << ESC_RESET;
}

/*!
** @brief   Run REPL
** @param   none
** @return  none
*/
void    runRepl(void)
{
    std::string		command;
    Contacts		contacts;

    // [ run REPL ]
    while (42)
    {
        //  [ print prompt ]
        std::cout << FNT_BOLD CLR_GREEN << "phonebook > " << ESC_RESET;
        //  [ read command from stdin ]
        std::getline(std::cin, command);
        if (std::cin.fail()) {
            std::cout << FNT_BOLD CLR_RED << MSG_ERR_FAIL_READ_COMMAND << ESC_RESET << std::endl;
            exit(EXIT_FAILURE);
        }
        // [ execute command ]
        if (command == "ADD") {
            contacts.addContact();
        }
        else if (command == "SEARCH") {
             contacts.searchContact();
        }
        else if (command == "EXIT") {
            break;
        }
    }
}

/*!
** @brief   main (entry point)
** @param   argc    argument count
** @param   argv    argument contents
** @return  status
*/
int     main(int argc, char **argv) {
    // [ check argument ]
    (void)argv;
    if (argc != 1){
        std::cout << FNT_BOLD CLR_RED << MSG_USAGE_DESCRIPTION << ESC_RESET << std::endl;
        return (EXIT_FAILURE);
    }
    // [ print title (ascii art) ]
    printTitle();
    // [ start REPL ]
    runRepl();
    // [ return ]
    return (EXIT_SUCCESS);
}
