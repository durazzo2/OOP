#include <stdio.h>

#define MAX_TRANSACTIONS 100

typedef struct {
    int id;
    int amount;
    int commission;
    int type;
} Transaction;

int main() {
    Transaction transactions[MAX_TRANSACTIONS];
    int n, i, has_credit = 0;
    int credit_sum = 0;


    scanf("%d", &n);


    for (i = 0; i < n; i++) {
        scanf("%d %d %d %d", &transactions[i].id, &transactions[i].amount, &transactions[i].commission, &transactions[i].type);

        if (transactions[i].type == 1) { // Credit card transaction
            has_credit = 1;
            credit_sum += transactions[i].amount + transactions[i].commission;
        }
    }


    if (has_credit) {
        for (i = 0; i < n; i++) {
            if (transactions[i].type == 1) {
                printf("%d %d\n", transactions[i].id, transactions[i].amount + transactions[i].commission);
            }
        }
    } else {
        printf("No credit card transaction\n");
    }

    return 0;
}
