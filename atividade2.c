#include <stdio.h>
#include <string.h>

int main() {

    char senha[16];
    char criptografada[16];

    int shift;
    int opcao;
    int i;
    int numero;
    int deslocamento;

    // Variáveis para Fibonacci //
    int a = 1;
    int b = 1;
    int proximo;

    // Variáveis para números primos //

    int primo;
    int divisores;

    FILE *arquivo;

    printf("=== CRIPTOGRAFIA SIMPLES ===\n\n");

    // Digitar uma senha //
    printf("Digite uma senha (ate 15 letras, sem acentos): ");
    scanf("%15s", senha);

    // Entrada do SHIFT //
    printf("Digite o SHIFT: ");
    scanf("%d", &shift);

    // Escolha da sequencia //
    printf("\nEscolha a sequencia:\n");
    printf("1 - PA\n");
    printf("2 - PG\n");
    printf("3 - Fibonacci\n");
    printf("4 - Numeros Primos\n");
    printf("Opcao: ");
    scanf("%d", &opcao);

    // Criptografia //
    for (i = 0; senha[i] != '\0'; i++) {

        // Descobre a sequencia //
        if (opcao == 1) {

            // PA: 1, 2, 3, 4, 5... //
            numero = i + 1;

        } else if (opcao == 2) {

            // PG: 1, 2, 4, 8, 16... //
            numero = 1;

            for (int j = 1; j <= i; j++) {
                numero = numero * 2;
            }

        } else if (opcao == 3) {

            // Fibonacci: 1, 1, 2, 3, 5, 8... //

            if (i == 0 || i == 1) {
                numero = 1;
            } else {

                a = 1;
                b = 1;

                for (int j = 2; j <= i; j++) {

                    proximo = a + b;
                    a = b;
                    b = proximo;
                }

                numero = b;
            }

        } else if (opcao == 4) {

            // Numeros primos: 2, 3, 5, 7, 11... //

            numero = 1;
            primo = 0;

            while (primo <= i) {

                numero++;
                divisores = 0;

                for (int j = 1; j <= numero; j++) {

                    if (numero % j == 0) {
                        divisores++;
                    }
                }

                if (divisores == 2) {
                    primo++;
                }
            }

        } else {

            printf("Opcao invalida!\n");
            return 0;
        }

        /*
           DUAS CAMADAS:
           1 - SHIFT
           2 - valor da sequencia
        */
        deslocamento = shift + numero;

        /*
           Transformamos a letra em uma posicao de 0 a 25.
           Depois somamos o deslocamento.
           % 26 faz voltar para o inicio quando passar do Z.
        */
        criptografada[i] =
            'a' + (senha[i] - 'a' + deslocamento) % 26;
    }

   
    criptografada[i] = '\0';

    printf("\nsenha original: %s\n", senha);
    printf("senha criptografada: %s\n", criptografada);

    // Criando o arquivo //
    arquivo = fopen("resultado_criptografia.txt", "w");

    if (arquivo == NULL) {

        printf("Erro ao criar o arquivo!\n");

    } else {

        fprintf(arquivo, "=== LOG DE CRIPTOGRAFIA ===\n");
        fprintf(arquivo, "senha codificada: %s\n", criptografada);
        fprintf(arquivo, "SHIFT: %d\n", shift);
        fprintf(arquivo, "Tipo de sequencia: %d\n", opcao);
        fprintf(arquivo, "Letras: %d\n", strlen(senha));

        fclose(arquivo);

        printf("\nArquivo criado com sucesso!\n");
    }

    return 0;
}


