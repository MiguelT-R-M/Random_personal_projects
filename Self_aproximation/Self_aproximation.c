// Code to use with macrodroid to acertain the precise position of my phone
// Baby's first data analysis program:
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define isValid(Choices, Current) ((Choices[0] == Current[0])&&(Choices[1] == Current[1])&&(Choices[2] == Current[2])&&(Current[3]>=Choices[3])&&(Current[3]<=Choices[4]))

void checkNull(void *pointer){
    if(pointer == NULL){
        printf("Memory Error. Closing the program.");
        exit(1);
    }
}

int main(void){

    int Loc_size = 1, Capacity = 10;

    int Choices[5] = {0}, Current[4] = {0};
    printf("Escolha o ano desejado: "); scanf("%d", &Choices[0]);
    printf("Escolha o mês desejado: "); scanf("%d", &Choices[1]);
    printf("Escolha o dia desejado: "); scanf("%d", &Choices[2]);
    printf("Escolha a hora inicial: "); scanf("%d", &Choices[3]);
    printf("Escolha a hora final: "); scanf("%d", &Choices[4]);

    FILE *locale = fopen("locale.txt", "r");
    checkNull(locale);

    long double *Loc_X = calloc(Capacity, sizeof(*Loc_X)), *Loc_Y = calloc(Capacity, sizeof(*Loc_Y));
    long double Sum_locx = 0, Sum_locy = 0, Avg_locx = 0, Avg_locy = 0;
    checkNull(Loc_X); checkNull(Loc_Y);

    char BUFFER[100];
    // char *garbage;

    while(fgets(BUFFER, 100, locale)){
        
        int found = sscanf(BUFFER, " hora: %d-%d-%d %d:%*d:%*d, Local: %Lf,%Lf", &Current[0], &Current[1], &Current[2], &Current[3], &Loc_X[Loc_size-1], &Loc_Y[Loc_size-1]);

        // Current[0] = strtold(BUFFER + 6, &garbage); Old method, good to maintain it here for knowledge and documentation.
        // Current[1] = strtold(garbage + 1, &garbage);
        // Current[2] = strtold(garbage + 1, &garbage);
        // Current[3] = strtold(garbage + 1, &garbage);
        // Loc_X[Loc_size-1] = strtold(garbage + 15, &garbage);
        // Loc_Y[Loc_size-1] = strtold(garbage + 1, &garbage);

        if((found == 6)&&(isValid(Choices, Current))){
            Sum_locx+=Loc_X[Loc_size-1]; Sum_locy+=Loc_Y[Loc_size-1];

            printf("%.7Lf, %.7Lf\n", Loc_X[Loc_size-1], Loc_Y[Loc_size-1]);

            Loc_size++;

            if(Loc_size-1>=Capacity){

                Capacity = Capacity * 2;
                void *tempX = realloc(Loc_X, Capacity * sizeof(*Loc_X)); void *tempY = realloc(Loc_Y, Capacity * sizeof(*Loc_Y));
                checkNull(tempX); checkNull(tempY);
                Loc_X = tempX; Loc_Y = tempY;

            }
        }else{
            printf("Localização inválida, checando próxima\n");
        }

    }
    printf("Fim dos testes\n");
    printf("\n");

    if(Loc_size > 1){
        Avg_locx = Sum_locx/(Loc_size-1); Avg_locy = Sum_locy/(Loc_size-1);

        printf("Média de X: %.7Lf, Média de Y: %.7Lf\n\n", Avg_locx, Avg_locy);
        printf("%.7Lf, %.7Lf\n\n", Avg_locx, Avg_locy);
    }else{
        printf("Nenhuma localização válida, FIM DO CÓDIGO.\n");
    }

    free(Loc_X); free(Loc_Y); fclose(locale);
    return 0;
}