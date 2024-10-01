#include <stdio.h>
#include <stdlib.h>

typedef struct sushi {
    unsigned long price;
    unsigned long weight;
    unsigned long index;
    double value; // value = weight / price
} sushi_t;

void find_longest_increasing_subsequence(sushi_t **sushi_array, const unsigned long count);

int main() {
    unsigned long n;
    scanf("%lu", &n);

    // Allocate memory for the sushi array
    sushi_t **sushi_belt = (sushi_t **)malloc(n * sizeof(sushi_t *));
    for (unsigned long i = 0; i < n; i++) {
        sushi_belt[i] = (sushi_t *)malloc(sizeof(sushi_t));
        scanf("%lu %lu", &sushi_belt[i]->price, &sushi_belt[i]->weight);
        sushi_belt[i]->index = i;
        sushi_belt[i]->value = (double)sushi_belt[i]->weight / (double)sushi_belt[i]->price;
    }

    find_longest_increasing_subsequence(sushi_belt, n);

    // Free allocated memory
    for (unsigned long i = 0; i < n; i++) {
        free(sushi_belt[i]);
    }
    free(sushi_belt);

    return 0;
}

void find_longest_increasing_subsequence(sushi_t **sushi_array, const unsigned long count) {
    long *predecessor = (long *)malloc(count * sizeof(long));
    long *m = (long *)malloc((count + 1) * sizeof(long));
    m[0] = -1;

    long length = 0;

    for (long i = 0; i < count; i++) {
        long low = 1;
        long high = length + 1;

        // Binary search to find the longest increasing subsequence
        while (low < high) {
            long mid = low + (high - low) / 2;
            if (sushi_array[m[mid]]->value > sushi_array[i]->value) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        long new_length = low;

        predecessor[i] = m[new_length - 1];
        m[new_length] = i;

        if (new_length > length) {
            length = new_length;
        }
    }

    // Reconstruct the longest increasing subsequence
    sushi_t **subsequence = (sushi_t **)malloc(length * sizeof(sushi_t *));
    long k = m[length];

    for (long j = length - 1; j >= 0; j--) {
        subsequence[j] = sushi_array[k];
        k = predecessor[k];
    }

    // Create a binary representation of the subsequence
    char *binary_representation = (char *)malloc((count + 1) * sizeof(char));
    for (unsigned long i = 0; i < count + 1; i++) {
        binary_representation[i] = '0';
    }

    unsigned long total_price = 0;
    for (unsigned long j = 0; j < length; j++) {
        binary_representation[subsequence[j]->index] = '1';
        total_price += subsequence[j]->price;
    }

    // Output the binary representation and total price
    for (unsigned long j = 0; j < count; j++) {
        putchar(binary_representation[j]);
        putchar(' ');
    }
    putchar('\n');

    printf("%lu\n", total_price);

    // Free allocated memory
    free(binary_representation);
    free(predecessor);
    free(m);
    free(subsequence);
}