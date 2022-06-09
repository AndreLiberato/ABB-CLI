#include "io.h"

void io::error(string error){
    cout << "\033[1;31m    ERROR: " << error << "\033[0m" << endl;
}

void io::welcome(){
    cout << "\033[1;34m";
    cout << R"(
                                ██╗  ██╗███████╗███╗   ██╗ ██████╗                             
                                ██║ ██╔╝██╔════╝████╗  ██║██╔═══██╗                            
                                █████╔╝ █████╗  ██╔██╗ ██║██║   ██║                            
                                ██╔═██╗ ██╔══╝  ██║╚██╗██║██║   ██║                            
                                ██║  ██╗███████╗██║ ╚████║╚██████╔╝                            
                                ╚═╝  ╚═╝╚══════╝╚═╝  ╚═══╝ ╚═════╝                             
    )";
    print_big_clover();
}

void io::print_bar(){
    cout << "\033[1;34m\n\n======================================\n\n";
}

void io::print_small_clover(){
    
    cout << "\033[1;32m";
    cout << R"(
     .-.-.
    (_\|/_)
    ( /|\ )       __
     '-'-'`-.__.-'  `-
    )" << endl;
    cout << "\033[0m";
}

void io::print_big_clover(){
    cout << "\033[1;34m";
    cout << R"(
                                             .'`'.'`'.
                                         .''.`.  :  .`.''.
                                         '.    '. .'    .'
                                         .```  .' '.  ```.
                                         '..',`  :  `,'..'
                                              `-'`'-`
    )" << endl;
    cout << "\033[0m";

}

void io::help(){
    cout << "\033[1;34m";
    cout << " O que é o Keno?";
    io::print_bar();
    cout << " Assim como loteria ou bingo, você irá escolher um\n"
    "valor financeiro,rodadas e um conjunto de números e\n"
    "caso esses sejam sorteados, você receberá um valor que\n"
    "poderá crescer o valor inicial. Quanto mais sorte, mais\n"
    "dinheiro você ganha.";
    io::print_bar();

    cout << " O jogo Keno funciona da seguinte maneira:\n"
    "Você vai precisar pensar em 3 valores:\n"
    "- O valor inicial que você quer apostar;\n"
    "- O número de rodadas que você quer jogador;\n"
    "- Um conjunto de elementos de 1 a 15, que vão do número 1 a 80.";
    io::print_bar();

    cout << " Monte seu arquivo .dat seguindo as especificações:\n"
            "Valor do crédito inicial\n"
            "Numero de rodadas\n"
            "conjunto de até 15 números inteiros\n"
            "----------------------------\n"
            "exemplo:\n"
             "500\n"
             "3\n"
             "1 4 34 7 32 71";
    io::print_bar();

    cout << " Escolha seus valores, insira o arquivo seguindo as recomendações acima, e boa sorte!\n";
    cout << "\033[0m";
}

void io::game_summary(cash_type initialMoney, cash_type profit, cash_type finalMoney){
    io::print_bar();
    cout << "\033[1;34mResumo do jogo:\nVocê começou o jogo com " << initialMoney << " LPcoins\n"
    "Você obteve ";
    if(profit > 0){
        cout << "\033[1;32m" << profit << "\033[1;34m" << " LPcoins\n"
        "\033[1;34mE seu crédito final é de " << "\033[1;32m" << finalMoney << "\033[1;34m LPcoins";
    }
    else{ 
        cout << "\033[1;31m" << profit << "\033[1;34m" << " LPcoins\n"
        "\033[1;34mE seu crédito final é de " << "\033[1;31m" << finalMoney << "\033[1;34m LPcoins";
    }

    io::print_bar();
    cout << "\033[1;34m";
    cout << R"(
                    ███████╗██╗███╗   ███╗    ██████╗ ███████╗         ██╗ ██████╗  ██████╗  ██████╗ 
                    ██╔════╝██║████╗ ████║    ██╔══██╗██╔════╝         ██║██╔═══██╗██╔════╝ ██╔═══██╗
                    █████╗  ██║██╔████╔██║    ██║  ██║█████╗           ██║██║   ██║██║  ███╗██║   ██║
                    ██╔══╝  ██║██║╚██╔╝██║    ██║  ██║██╔══╝      ██   ██║██║   ██║██║   ██║██║   ██║
                    ██║     ██║██║ ╚═╝ ██║    ██████╔╝███████╗    ╚█████╔╝╚██████╔╝╚██████╔╝╚██████╔╝
                    ╚═╝     ╚═╝╚═╝     ╚═╝    ╚═════╝ ╚══════╝     ╚════╝  ╚═════╝  ╚═════╝  ╚═════╝ 
    )" << endl;
}
