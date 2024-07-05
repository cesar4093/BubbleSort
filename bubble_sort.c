#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

void bubbleSort(char arr[][MAX_NAME_LENGTH], int n) {
    char temp[MAX_NAME_LENGTH];
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (strcmp(arr[j], arr[j+1]) > 0) {
                // Troca os elementos
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);
            }
        }
    }
}

int main() {
    int n;
    printf("Digite o número de nomes: ");
    scanf("%d", &n);
    getchar(); // Captura o caractere de nova linha após o número de nomes

    char nomes[n][MAX_NAME_LENGTH];
    int i;
    printf("Digite os nomes:\n");
    for (i = 0; i < n; i++) {
        fgets(nomes[i], MAX_NAME_LENGTH, stdin);
        nomes[i][strcspn(nomes[i], "\n")] = '\0'; // Remove o caractere de nova linha
    }

    bubbleSort(nomes, n);

    printf("Nomes em ordem alfabética:\n");
    for (i = 0; i < n; i++) {
        printf("%s\n", nomes[i]);
    }

    return 0;
}
