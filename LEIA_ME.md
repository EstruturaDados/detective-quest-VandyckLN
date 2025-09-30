# Detective Quest

Um jogo de exploração textual desenvolvido em C que simula a navegação por uma mansão misteriosa usando estrutura de dados de árvore binária.

## Como Jogar

1. **Compile o programa:**

   ```bash
   gcc detective_quest.c -o detective_quest.exe
   ```

2. **Execute:**

   ```bash
   ./detective_quest.exe
   ```

3. **Navegue pela mansão:**
   - `e` - Ir para a esquerda
   - `d` - Ir para a direita
   - `s` - Sair do jogo

## Estrutura da Mansão

```
                    Hall de Entrada
                   /               \
            Sala de Estar       Cozinha
           /           \        /       \
    Biblioteca  Sala de Jantar Despensa Jardim
```

## Arquivos

- `detective_quest.c` - Código fonte principal
- `DOCUMENTACAO.md` - Documentação completa e técnica
- `README.md` - Este arquivo

## Objetivo

Explore a mansão navegando pelos cômodos até chegar a uma sala sem saídas. O jogo demonstra conceitos de:

- Árvores binárias
- Alocação dinâmica de memória
- Estruturas (structs)
- Navegação por ponteiros

## Exemplo de Execução

```
Bem-vindo ao Detective Quest!
Explore a mansao para encontrar pistas.

Voce esta em: Hall de Entrada
Escolha para onde ir:
(e) Esquerda: Sala de Estar
(d) Direita: Cozinha
(s) Sair da exploracao
Opcao: e

Voce esta em: Sala de Estar
Escolha para onde ir:
(e) Esquerda: Biblioteca
(d) Direita: Sala de Jantar
(s) Sair da exploracao
Opcao: e

Voce esta em: Biblioteca
Voce chegou ao fim deste caminho.
Obrigado por jogar!
```

---

**Desenvolvido para:** Enigma Studios  
**Linguagem:** C  
**Estrutura:** Árvore Binária
