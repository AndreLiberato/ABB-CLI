//! @file func.h
#ifndef FUNC_H
#define FUNC_H
#include "io.h"
#include <typeinfo>
#include <fstream>
#include <algorithm>
#include <sstream>
#include "definitions.h"
using io::error;

//! @brief This file contains some random as hell funcions.

namespace func{

    /*! Converts a number string to a cash_type number.
        @param bets A string that contains the credits, rounds or spots of the bets file.
        @param *num A pointer to the variable we will put the converted number.
        @return True there is any strage character. False otherwise. */
    bool str_to_num(string bets, cash_type *num);

    /*! Prints a vector.
        @param v Any vector that we want to print. */
    void prt_vec(set_of_numbers_type v);

    /*! Finds a pivot and divide the vector.
        @param right A iterator to the beginning of a vector.
        @param left A iterator to the end of a vector.
        @return A iterator to the beginning of the divided vector. */
    template<class ForwardIt>
    ForwardIt divide(ForwardIt right, ForwardIt left);

    /*! Sort the vector to the smallest to the biggest number.
        @param right A iterator to the beginning of a vector.
        @param left A iterator to the end of a vector. */
    template<class ForwardIt>
    void qksort(ForwardIt right, ForwardIt left);

    /*! Creates a random vector.
        @param &v A pointer to a vector.
        @param y The beginning of the random numbers creation.
        @param x The end of the random numbers creation. */
    void create_random_vec(set_of_numbers_type &v, int y, int x);

    /*! Prints the return table array.
        @param v[][16] The return table array. */
    void prt_array(cash_type v[][16]);
}
#endif
