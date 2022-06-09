# Trabalho - 2ª Unidade

Repositório contendo as especificações do Trabalho da 2ª unidade da disciplina de Estrutura de Dados Básica II.

# Pastas e especificações

- src - Contém todos os arquivos ``.cpp``;
- include - Contém todos os arquivos ``.hpp``;
- data - Contém os arquivos de aposta;
- build - Contém o ``Makefile``, o binário ``calc*`` e todos os outros arquivos que o ``cmake`` cria.

# Como compilar o projeto

  ```
  cmake -B build
  cmake --build build
  ```

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

## Documento de Especificação
