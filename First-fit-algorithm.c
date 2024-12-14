#include <stdio.h>

int main() {
    int bno, pno, bs[20], ps[20], allocation[20], i, j;

    // Initialize allocation array to -1 (indicating not allocated)
    for (i = 0; i < 20; i++) {
        allocation[i] = -1;
    }

    printf("Enter the number of blocks: ");
    scanf("%d", &bno);

    for (i = 0; i < bno; i++) {
        printf("Enter the size of Block %d: ", i + 1);
        scanf("%d", &bs[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &pno);

    for (i = 0; i < pno; i++) {
        printf("Enter the size of Process %d: ", i + 1);
        scanf("%d", &ps[i]);
    }

    // First Fit Allocation
    for (i = 0; i < pno; i++) {
        for (j = 0; j < bno; j++) {
            if (ps[i] <= bs[j]) {
                allocation[i] = j;  // Allocate block j to process i
                bs[j] -= ps[i];     // Reduce block size by allocated size
                break;
            }
        }
    }

    // Display Allocation Results
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (i = 0; i < pno; i++) {
        if (allocation[i] != -1) {
            printf("%d\t\t%d\t\t%d\n", i + 1, ps[i], allocation[i] + 1);
        } else {
            printf("%d\t\t%d\t\tNot Allocated\n", i + 1, ps[i]);
        }
    }

    return 0;
}