#include <stdio.h>
#include <string.h>

void gen_code(char *inp) {
    char ops[] = "/*+-=", reg = 'Z', tmp[100];
    for (int o = 0; o < 5; o++) {
        int i = 0, j = 0;
        while (inp[i]) {
            if (inp[i] == ops[o]) {
                char op1 = inp[i - 1], op2 = inp[i + 1];
                if (ops[o] == '=') printf("=\t%c\t%c\t--\n", op1, op2);
                else printf("%c\t%c\t%c\t%c\n", ops[o], reg--, op1, op2);
                tmp[j - 1] = (ops[o] == '=') ? op1 : reg + 1;
                i += 2;
            } else tmp[j++] = inp[i++];
        }
        tmp[j] = '\0';
        strcpy(inp, tmp);
    }
}

int main() {
    char inp[100];
    printf("Enter expression: ");
    scanf("%s", inp);
    printf("Oprtr\tDestn\tOp1\tOp2\n");
    gen_code(inp);
    return 0;
}
