#include <stdio.h>
#include <stdlib.h>


int ispossible(int index, int range, int m) {
    if ((index - range >= 0) && (index + range < m))
        return 1;
    else {
        return 0;
    }

}

int squares(int m, int t[], int n) {


    int k, i, j, suma, counter_i, wynik = 0, ctr = 0;
    for (k = 1; k < m; k++) {
        for (i = 0; i < m; i++) {
            for (j = 0; j < m; j++) {
                suma = 0;
                counter_i = i - k;

                if (ispossible(i, k, m) && ispossible(j, k, m)) {
                    while (counter_i <= i + k) {
                        if (counter_i == i - k || counter_i == i + k) {
                            for (int counter_j=j-k; counter_j <= j+k; counter_j++) {
                                suma += t[counter_i * m + counter_j];
                            }
                        }

                        if (counter_i > i - k && counter_i < i + k)
                        {
                            suma+=t[counter_i*m+j-k];
                            suma+=t[counter_i*m+j+k];
                        }

                        counter_i++;
                    }
                    if (suma == n) {
                        wynik += 1;


                    }
                }
            }
        }
    }
    printf("%d\n", wynik);
    return 0;
}

int squares2(int m, int t[], int n) {


    int k, i, j, suma, counter_i, wynik = 0, ctr = 0;
    for (k = 1; k < m; k++) {
        for (i = 0; i < m; i++) {
            for (j = 0; j < m; j++) {
                suma = 0;
                counter_i = i - k;
                if (ispossible(i, k, m) && ispossible(j, k, m)) {
                    while (counter_i <= i + k) {
                        if (counter_i == i - k || counter_i == i + k) {
                            for (int counter_j=j-k; counter_j <=j+k; counter_j++) {
                                suma += t[counter_i * m + counter_j];
                            }
                        }

                        if (counter_i > i - k && counter_i < i + k)
                        {
                            suma+=t[counter_i*m+j-k];
                            suma+=t[counter_i*m+j+k];
                        }

                        counter_i++;
                    }
                    if (suma == n) {
                        wynik += 1;
                        printf("%d %d\n", i, j);


                    }
                }
            }
        }
    }
    return 0;
}

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    int *array = (int *) malloc(m * m * sizeof(int));

    int i, k;
    for (i = 0; i < m; i++) {
        for (k = 0; k < m; k++) {
            scanf("%d", &array[i * m + k]);
        }
    }
    squares(m, array, n);
    squares2(m, array, n);
    return 0;
}