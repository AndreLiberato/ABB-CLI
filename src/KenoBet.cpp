#include "KenoBet.h"

//Printar os erros aqui
bool KenoBet::add_number(number_type spot_){
    if(spot_ <= 0 or spot_ > 80){
        error("O NÚMERO APOSTADO NÃO É ENTRE 1 E 80.");
        return false;
    }
    for(int i = 0; i < (int)m_spots.size(); ++i)
        if(m_spots[i] == spot_){
            error("UM OU MAIS NÚMEROS REPETIDOS NO VETOR.");
            return false;
       }

    m_spots.push_back(spot_);
    return true;
}

bool KenoBet::set_wage(cash_type wage_){
    if(wage_ > 0){
        m_wage = wage_;
        return true;
    }
    else return false;
}

void KenoBet::reset( void ){
    m_wage = 0;
    m_rounds = 0;
    m_spots.clear();
}

cash_type KenoBet::get_wage( void ) const {return m_wage;}

size_t KenoBet::size( void ) const {return m_spots.size();}

set_of_numbers_type KenoBet::get_hits(set_of_numbers_type random){
    set_of_numbers_type hits;
    for (int i = 0; i < (int)m_spots.size(); i++){
        for (int j = 0; j < (int)random.size(); j++){
            if(m_spots[i] == random[j]) hits.push_back(m_spots[i]);
        }
    }
    return hits;
}

set_of_numbers_type KenoBet::get_spots(void) const {return m_spots;}

itr_of_num_type KenoBet::get_begin(void){return m_spots.begin();}

itr_of_num_type KenoBet::get_end(void){return m_spots.end();}
