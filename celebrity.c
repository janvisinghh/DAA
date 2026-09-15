#include <stdio.h>

int main() {
    int n, i, j;
    int M[100][100];
    int celebrity = -1;
    int found;

    printf("Enter number of people: ");
    scanf("%d", &n);

    printf("Enter the matrix:\n");

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &M[i][j]);
        }
    }

    for (i = 0; i < n; i++) {

        found = 1;

        // Celebrity should know nobody
        for (j = 0; j < n; j++) {
            if (i != j && M[i][j] == 1) {
                found = 0;
                break;
            }
        }

        if (!found)
            continue;

        for (j = 0; j < n; j++) {
            if (i != j && M[j][i] == 0) {
                found = 0;
                break;
            }
        }

        if (found) {
            celebrity = i;
            break;
        }
    }

    if (celebrity == -1)
        printf("No celebrity found\n");
    else
        printf("Celebrity is person %d\n", celebrity);

    return 0;
}
