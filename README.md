# Trabalho - 1ª Unidade

Repositório contendo as especificações do Trabalho da 1ª unidade da disciplina de Estrutura de Dados Básica II.

# Pastas e especificações

- ``src`` - Contém todos os arquivos ``.cpp``;
- ``include`` - Contém todos os arquivos ``.hpp``;
- ``data`` - Contém o arquivo com um pequeno exemplo de entradas;
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

# Comandos do projeto

## Create
  ```
  create x
  ```
  Inicializa uma árvore binária de busca com raíz possuíndo o valor passado x.Toda Árvore Binária de Busca deve ser iniciada antes de poder ser realizado outras operações.

## Insert (insere)
  ```
  insert x
  ```
  Insere um novo nó na árvore binária de busca com valor passado x. Caso valor já exista, é retornado uma mensagem.

## Remove (remove)
  ```
  remove x
  ```
  Remove o nó ná árvore binária de busca com valor passado x. Caso o valor não exista, é retornado uma mensagem.

## Search (busca)
  ```
  search x
  ```
  Busca pelo nó contendo um valor passado x. Caso o valor seja encontrado, é retornado o valor dele e é impresso a sub-árvore no qual esse nó é raiz. Caso não seja encontrado é retornado uma mensagem.

## At (enesimoElemento)
  ```
  at x
  ```
  Acessa o elemento na posição passada x de um percurso em ordem. Caso a posição exista, é retornado o valor do nó. Caso contrário, é retornado uma mensagem.
  
## Position (posicao)
  ```
  position x
  ```
  Busca pelo elemento com valor passado x e retorna a sua posição na Árvore Binária de Busca em percurso em ordem. Caso não exista nó com o valor passado x, é retornado uma mensagem.

## Median (mediana)
  ```
  median
  ```
  Retorna o elemento mediano da Árvore Binária de Busca.

## Average (media)
  ```
  average
  ```
  Calcula a média aritmética simples de toda Árvore Binária de Busca.

## Full (ehCheia)
  ```
  full
  ```
  Verifica se a Árvore Binária de Busca é completa.

## Complete (ehCompleta)
  ```
  complete
  ```
  Verifica se a Árvore Binária de Busca é completa.

## Pre-order (pre_ordem)
  ```
  pre
  ```
  Imprime os valores do nós da Árvore Binária de Busca em um percurso pré-ordem.

## Print (imprimeArvore)
  ```
  print
  ```
  Imprime a Árvore binária de busca de forma hierárquica.

## Read (leia)
  ```
  read ./path/to/file
  ```
  Lê um arquivo de texto com comandos válidos. `path/to/file` deve ser substituído pelo caminho até o arquivo que deseja ser lido.

  O projeto possuí um arquivo de leitura de exemplo.
  Execute: 
  ```
  read ./data/example.in
  ```

## Exit
  ```
  exit
  ```
  Encerra deleta a Árvore Binária de Busca criada e encerra o programa.
# Especificação
  O projeto é complicado usando as seguintes flags de compilação
  - g
  - Wall
  - Werror
  - Wextra
  - Wpedantic
  - ansi
  - Ofast
  - fsanitize=address,undefined
  - lm
