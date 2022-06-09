#include <iostream>
#include <fstream>
#include <cstring>
#include "io.h"
#include "KenoBet.h"
#include "func.h"
using io::error;
using func::str_to_num;
using func::qksort;
using func::prt_vec;
using func::create_random_vec;
using io::print_bar;

int main(int argc, char *argv[]){
    const cash_type arr[15][16] = {
    {0, 3},
    {0, 1, 9},
    {0, 1, 2, 16},
    {0, 0.5, 2, 6, 12},
    {0, 0.5, 1, 3, 15, 50},
    {0, 0.5, 1, 2, 3, 30, 75},
    {0, 0.5, 0.5, 1, 6, 12, 36, 100},
    {0, 0.5, 0.5, 1, 3, 6, 19, 90, 720},
    {0, 0.5, 0.5, 1, 2, 4, 8, 20, 80, 1200},
    {0, 0, 0.5, 1, 2, 3, 5, 10, 30, 600, 1800},
    {0, 0, 0.5, 1, 1, 2, 6, 15, 25, 180, 1000, 3000},
    {0, 0, 0, 0.5, 1, 2, 4, 24, 72, 250, 500, 2000, 4000},
    {0, 0, 0, 0.5, 0.5, 3, 4, 5, 20, 80, 240, 500, 3000, 6000},
    {0, 0, 0, 0.5, 0.5, 2, 3, 5, 12, 50, 150, 500, 1000, 2000, 7500},
    {0, 0, 0, 0.5, 0.5, 1, 2, 5, 15, 50, 150, 300, 600, 1200, 2500, 10000}
    };

    io::welcome();

    srand(time(NULL)); //Creates the seed to generate random numbers.

    if(argc < 2){ //See if the .dat file was not specified.
        error("SEM ARQUIVO DE APOSTAS. PARA TER AJUDA DIGITE ./KENO --HELP");
        return 0;
    }

    if(!strcmp(argv[1], "--help") or !strcmp(argv[1], "-h")){
        io::help();
        return 0;
    }

    KenoBet bet;
    string bets;
    cash_type dummyNum;

    ifstream file(argv[1]); //Reads from the .dat file.

    //Start converting the values of the .dat file from strings to numbers.
    getline(file, bets); //Get the credits string.
    if(file.fail()){
        error("O ARQUIVO DE APOSTAS ESTÁ EM BRANCO OU OS CRÉDITOS NÃO FORAM ESPECIFICADOS.");
        return 0;
    }
    if(!str_to_num(bets, &dummyNum)) return 0;
    bet.set_wage(dummyNum);

    getline(file, bets); //Get the rounds string.
    if(file.fail()){
        error("O NÚMERO DE ROUNDS NÃO FOI ESPECIFICADO NO ARQUIVO DE APOSTAS.");
        return 0;
    }
    if(!str_to_num(bets, &dummyNum)) return 0;
    bet.m_rounds = (number_type)dummyNum;

    getline(file, bets); //Get the spots string.
    if(file.fail()){
        error("OS SPOTS NÃO FORAM ESPECIFICADOS NO ARQUIVO DE APOSTAS.");
        return 0;
    }
    string delimiter = " ";
    size_t pos = 0;
    string token;
    int betNum = bet.get_spots().size();
    bool notRepeted = true;

    //Add all the string's tokens into the bet.m_spots vector.
    while((pos = bets.find(delimiter)) != std::string::npos){
        token = bets.substr(0, pos); //Break the string into tokens.
        if(!str_to_num(token, &dummyNum)) return 0;

        notRepeted = bet.add_number((number_type)dummyNum);
        if(!notRepeted) return 0;

        betNum = bet.get_spots().size();
        bets.erase(0, pos + delimiter.length()); //Erase the token from the original string.
    }

    //Add the last string token into the bet.m_spots vector.
    if(!str_to_num(bets, &dummyNum)) return 0;

    notRepeted = bet.add_number((number_type)dummyNum);
    if(!notRepeted) return 0;

    else if(betNum > 14){
        error("VOCÊ ESTÁ APOSTANDO MAIS DE 15 NÚMEROS.");
        return 0;
    }
    file.close(); 
    //End converting the values of the .dat file from strings to numbers.

    qksort(bet.get_begin(), bet.get_end()-1); //Sort the spots vector using iterators.
    set_of_numbers_type random; //Creates the drawn numbers vector.
    random.resize(20, 0); //Set the random vector size.
    set_of_numbers_type match;   //Creates the matched numbers vector.

    cash_type initialMoney = bet.get_wage();
    cash_type gameMoney = bet.get_wage();


    cash_type perRound = bet.get_wage()/bet.m_rounds;
    betNum = bet.get_spots().size();

    print_bar();
    cout << "\033[1;34mAposta recebida!";
    cout << "\033[1;34mVocê esta apostando " << initialMoney << " LPcoins.\n"
    "E vai apostar " << perRound << " LPcoins por rodada.\n"
    "Você está apostando " << betNum << " números. Eles são:\n[ ";
    prt_vec(bet.get_spots()); cout << "\033[1;34m]\n"
    "Você tem " << bet.m_rounds << " rodadas\nBoa sorte... Meu chapa";

    int round = 0;
    while(bet.m_rounds != 0){
        round++;
        gameMoney -= perRound;
        create_random_vec(random, 0, 20);
        print_bar();
        cout << "\033[1;33mRODADA " << round << endl;
        cout << "\033[1;34mOs números sorteados são:\n[ ";
        prt_vec(random); cout << "\033[1;34m]\n";

        match = bet.get_hits(random);

        cout << "\033[1;34mResultados da rodada:\nVocê acertou " << match.size() 
        << " números.Ele(s) são:\n[ "; prt_vec(match); cout << "\033[1;34m]\n";

        cash_type returnRate = arr[betNum-1][match.size()];
        cout << "Você vai ganhar " << returnRate << "x o valor apostado\n"
        "Você sai com " << perRound*returnRate << " LPcoins nessa rodada\n";

        bet.set_wage(gameMoney += perRound*returnRate);
        gameMoney = bet.get_wage();

        cout << "Você tem no total " << gameMoney <<  " LPcoins";
        bet.m_rounds--;
    }

    io::game_summary(initialMoney, gameMoney - initialMoney, gameMoney);

    return 0;
}
