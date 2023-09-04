//
//  main.c
//  PerfectNumber
//
//  Created by Tayip on 3.09.2023.
//
#include <stdio.h>
#include <time.h>

long long int perfect_zahlen(int th_number) {
    long long int i = 1;
    int number = 0;
    for(i = 1;number != th_number; ++i){
        long long int gesamt = 0;
        for(long long int j = 1;j <= i; ++j){
            if(i % j == 0){
                gesamt += j;
            }
        }
        if(2 * i == gesamt){
            number++;
        }
        if(number == th_number){
            break;
        }
       
    }
    return i;
}

int main(void) {
    clock_t start = clock();
    int zahl;
    printf("Geben Sie bitte eine Zahl um perfekte Zahl zu berechnen:\n");
    (void)scanf("%d",&zahl);
    if(zahl > 9){
        printf("Die eingegebene Zahl überschreitet den Typ long long int.\n");
        return -1;
    }
    printf("Die suchende Zahl ist gleich:%lld \n" ,perfect_zahlen(zahl));
    clock_t end = clock();
    printf("Die Zeit für die Programmierung: %f sekunde\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
