# Trabalho - 1ª Unidade

Repositório contendo as especificações do Trabalho da 1ª unidade da disciplina de Estrutura de Dados Básica II.

# Pastas e especificações

- ``src`` - Contém todos os arquivos ``.cpp``;
- ``include`` - Contém todos os arquivos ``.hpp``;
- ``data/in`` - Contém o arquivo com um pequeno exemplo de entradas;
- ``build`` - Contém o ``Makefile``, o binário ``cli`` e todos os outros arquivos que o ``cmake`` cria.

# Como compilar o projeto

  ```
  cmake -B build
  cmake --build build
  ```
 
# Como executar o projeto
 Para uma execução padrão, execute:
  ```
  ./build/cli
  ```
## Especificação
  O projeto é complicado usando as seguintes flags de compilação
  -g
  -Wall
  -Werror
  -Wextra
  -Wpedantic
  -ansi
  -Ofast
  -fsanitize=address,undefined
  -lm
