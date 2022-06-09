#ifndef DEFINITIONS_H
#define DEFINITIONS_H
#include <iomanip>
#include <iostream>
#include <vector>
using number_type = unsigned short int; //<! data type for a keno hit.
using cash_type = float; //<! Defines the wage type in this application.
using set_of_numbers_type = std::vector< number_type >;
using itr_of_num_type = set_of_numbers_type::iterator;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::stringstream;
using std::vector;
using std::iter_swap;
using std::setprecision;
#endif
