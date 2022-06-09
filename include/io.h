//! @file io.h
#ifndef IO_H
#define IO_H
#include <string>
#include <iostream>
#include <iomanip>
#include "definitions.h"

namespace io{

    /*! Prints a error message.
        @param A string containing the error message. */
    void error(string error);

    //! Prints the welcome message.
    void welcome();

    //! Prints a horizontal bar.
    void print_bar();

    //! Prints a small green clover.
    void print_small_clover();

    //! Prints a big green clover.
    void print_big_clover();

    //! Prints the help message.
    void help();

    //! Prints the game summary.
    void game_summary(cash_type, cash_type, cash_type);
}
#endif
