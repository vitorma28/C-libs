# Vetor generico para C

Funciona através de bytes usando o tamanho do dado

# Funções:

## Criação

Funções para criar ou destruir o vetor:

- VectorInit, vector.c -> Instanciar um Vector.
- VectorDestroy, destruct.c -> Destruir um Vector.

## Acesso

Funções para acesso e definição de itens:

Encontrados em `access.c`.

- VectorGet: Obtém o valor em determinado endereço.
- VectorSet: Define o valor em determinado endereço.
- VectorIndexOf: Procura um valor e retorna seu índice. Caso não seja encontrado, retorna -1.
- VectorContains: Verifica se existe um valor ou não.
- VectorForEach: Executa uma função para cada item.
- VectorMap: Executa uma função para cada item e o retorno será um novo valor.

## Redimensionamento
