//
//  main.c
//  PerfectNumber
//
//  Created by Tayip on 3.09.2023.
//
#include <stdio.h>
#include <math.h>
#include <time.h>

// İkili üs alma işlemi
long long int power(int base, int exponent) {
    long long int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int is_prime(long long int number) {
    if (number <= 1) {
        return 0;
    }
    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void) {
    clock_t start = clock();
    int nth_number;
    printf("Kaçıncı mükemmel sayıyı hesaplamak istersiniz: ");
    scanf("%d", &nth_number);

    int count = 0;
    int candidate = 2;
    while (count < nth_number) {
        long long int mersenne = power(2, candidate) - 1;
        if (is_prime(mersenne)) {
            // Mersenne asal bulundu, mükemmel sayıyı hesapla
            long long int perfect = power(2, candidate - 1) * mersenne;
            printf("%d. mükemmel sayı: %lld\n", count + 1, perfect);
            count++;
        }
        candidate++;
    }
    clock_t end = clock();
    printf("Programlma icin harcanan süre: %f saniye\n", (double)(end - start) / CLOCKS_PER_SEC);
    return 0;
}
