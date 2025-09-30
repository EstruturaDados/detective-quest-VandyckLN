#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura que representa uma sala da mansao
typedef struct Sala
{
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

// Cria uma sala dinamicamente com o nome fornecido
Sala *criarSala(const char *nome)
{
    Sala *novaSala = (Sala *)malloc(sizeof(Sala));
    if (novaSala == NULL)
    {
        printf("Erro ao alocar memoria para a sala!\n");
        exit(1);
    }
    strncpy(novaSala->nome, nome, 49);
    novaSala->nome[49] = '\0';
    novaSala->esquerda = NULL;
    novaSala->direita = NULL;
    return novaSala;
}

// Permite a navegacao do jogador pela arvore de salas
void explorarSalas(Sala *salaAtual)
{
    char escolha;
    while (salaAtual != NULL)
    {
        printf("\nVoce esta em: %s\n", salaAtual->nome);
        if (salaAtual->esquerda == NULL && salaAtual->direita == NULL)
        {
            printf("Voce chegou ao fim deste caminho.\n");
            break;
        }
        printf("Escolha para onde ir:\n");
        if (salaAtual->esquerda)
            printf("(e) Esquerda: %s\n", salaAtual->esquerda->nome);
        if (salaAtual->direita)
            printf("(d) Direita: %s\n", salaAtual->direita->nome);
        printf("(s) Sair da exploracao\n");
        printf("Opcao: ");
        scanf(" %c", &escolha);
        if (escolha == 'e' && salaAtual->esquerda)
        {
            salaAtual = salaAtual->esquerda;
        }
        else if (escolha == 'd' && salaAtual->direita)
        {
            salaAtual = salaAtual->direita;
        }
        else if (escolha == 's')
        {
            printf("Saindo da exploracao.\n");
            break;
        }
        else
        {
            printf("Opcao invalida. Tente novamente.\n");
        }
    }
}

// Libera a memoria alocada para a arvore de salas
void liberarSalas(Sala *sala)
{
    if (sala == NULL)
        return;
    liberarSalas(sala->esquerda);
    liberarSalas(sala->direita);
    free(sala);
}

// Monta o mapa da mansao e inicia a exploracao
int main()
{
    // Criacao manual da arvore (mansao)
    Sala *hall = criarSala("Hall de Entrada");
    hall->esquerda = criarSala("Sala de Estar");
    hall->direita = criarSala("Cozinha");
    hall->esquerda->esquerda = criarSala("Biblioteca");
    hall->esquerda->direita = criarSala("Sala de Jantar");
    hall->direita->esquerda = criarSala("Despensa");
    hall->direita->direita = criarSala("Jardim");

    printf("Bem-vindo ao Detective Quest!\nExplore a mansao para encontrar pistas.\n");
    explorarSalas(hall);
    liberarSalas(hall);
    printf("Obrigado por jogar!\n");
    return 0;
}
