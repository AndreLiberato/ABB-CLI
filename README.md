# Trabalho-2
Repositório contendo as especificações do Trabalho 1 da disciplina 

# Pastas e especificações

- src - Contém todos os arquivos ``.cpp``;
- include - Contém todos os arquivos ``.h``;
- data - Contém os arquivos de aposta;
- build - Contém o ``Makefile``, o binário ``keno*`` e todos os outros arquivos que o ``cmake`` cria.

# Como compilar o projeto
  Caso a pasta ``build`` ainda não exista. Crie-a, entre nela e execute os comandos ``cmake ..`` e
  ``cmake --build .``.
  Caso já exista, é só entrar nela e executar o comando ``make``.

 ```cpp
 if(!exists_dir(build)){
     create_dir(build);
     get_in(build);
     run_command(cmake ..);
     run_command(cmake --build .);
 }
 else{
     get_in(build);
     run_command(make);
 }
 ```
 
# Como executar o projeto
 
## Como ler os arquivos de aposta

Exemplo:

``./keno ../data/bet1.dat``.

## Como ter ajuda

## Documento de Especificação

