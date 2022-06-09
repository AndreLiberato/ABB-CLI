#include "func.h"

bool func::str_to_num(string bets, cash_type *num){
    stringstream ss(bets);  
    ss >> *num;  
    if(ss.fail()) {
        error("EXISTEM CARACTERES ESTRANHOS NO ARQUIVO DE APOSTAS.");
        return false;
    }
    string aux;
    ss >> aux;
    if(!ss.fail()){
        error("EXISTEM CARACTERES ESTRANHOS NO ARQUIVO DE APOSTAS.");
        return false;
    }
    return true;
}

void func::prt_vec(set_of_numbers_type v){ 
    for(auto i=0; i < (int)v.size(); i++) 
    cout << "\033[1;33m" << v[i] << " \033[0m"; 
} 

template<class ForwardIt>
ForwardIt func::divide(ForwardIt right, ForwardIt left){ 
    ForwardIt pivot = left;
    ForwardIt i = right-1;   

    for (ForwardIt j = right; j < left; j++){ 
        if(*j <= *pivot){ 
            i++;
            iter_swap(i, j); 
        } 
    } 
    iter_swap(i+1, left); 
    return i+1; 
} 

template<class ForwardIt>
void func::qksort(ForwardIt right, ForwardIt left){ 
    if(right < left){ 
        ForwardIt pivot = divide(right, left); 
        qksort(right, pivot-1); 
        qksort(pivot+1, left); 
    } 
} 

void func::create_random_vec(set_of_numbers_type &v, int y, int x){
    auto begin = v.begin();
    auto last = v.end()-1;
    for(int i = y; i < x; ++i){
        v[i] = (rand() % 81);
    }
    qksort(begin, last);
    begin = v.begin();
    last = v.end();
    auto aux = std::unique(begin, last);
    int auxSize = std::distance(v.begin(), aux); 
    if(auxSize != (int)v.size()){
        create_random_vec(v, auxSize, v.size());
    }
}

void func::prt_array(cash_type v[][16]){
    for (int i = 0; i < 15; i++){
        cout << i << " ";
        for (int j = 0; j < 16; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
