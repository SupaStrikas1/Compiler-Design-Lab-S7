#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;

void display(int c[n][n]) {
    printf("\nEpsilon Closure of all states:\n");
    for (int i = 0; i < n; i++) {
        printf("q%d: {", i);
        for (int j = 0; j < n; j++) if (c[i][j]) printf("q%d,", j);
        printf("}\n");
    }
}

int main() {
    printf("Enter number of states: ");
    scanf("%d", &n);
    int c[n][n]; memset(c, 0, sizeof(c));
    for (int i = 0; i < n; i++) c[i][i] = 1;

    FILE *fp = fopen("NFA.txt", "r");
    if (!fp) return printf("File not found!\n"), 1;

    char s1[3], s2[3], in[2];
    while (fscanf(fp, "%s %s %s", s1, in, s2) != EOF)
        if (in[0] == 'e') c[s1[1]-'0'][s2[1]-'0'] = 1;

    // Transitive closure (Floyd–Warshall logic)
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (c[i][k] && c[k][j]) c[i][j] = 1;

    display(c);
    fclose(fp);
    return 0;
}

/*
NFA.txt
----------------------------
q0 e q1
q1 e q2
q0 a q3
q2 b q4
*/
