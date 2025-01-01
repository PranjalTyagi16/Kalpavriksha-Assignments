#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Represents an item in the cart
typedef struct item_t {
    char *item_name;
    int item_cost;
} item;

typedef struct pair {
    char *item_name;
    int freq;
} item_freq;

item_freq *newcart[100];
item *cart[100];         

int contains(item_freq *newcart[], char *item_name, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(newcart[i]->item_name, item_name) == 0) {
            return 1;
        }
    }
    return 0;
}

void update(item_freq *newcart[], char *item_name, int size) {
    for (int i = 0; i < size; i++) {
        if (strcmp(newcart[i]->item_name, item_name) == 0) {
            newcart[i]->freq += 1;
            return;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int sum = 0;
    int size = 0;
    int newsize = 0;

    for (int i=0;i<n;i++) {
        char temp_string[100];
        int temp_cost;
        scanf(" %[^,],%d", temp_string, &temp_cost);

        cart[i] = (item *)malloc(sizeof(item));
        cart[i]->item_name = (char *)malloc(strlen(temp_string) + 1);
        strcpy(cart[i]->item_name, temp_string);
        cart[i]->item_cost = temp_cost;

        size++;
        sum += temp_cost;
    }

    printf("item list\n");
    for (int i=0; i<size;i++) {
        printf("%s,%d\n", cart[i]->item_name, cart[i]->item_cost);
    }

    printf("Total cost %d\n", sum);
    for (int i=0;i<size;i++) {
        if (contains(newcart, cart[i]->item_name, newsize) == 0) {
            newcart[newsize] = (item_freq *)malloc(sizeof(item_freq));
            newcart[newsize]->item_name = (char *)malloc(strlen(cart[i]->item_name) + 1);
            strcpy(newcart[newsize]->item_name, cart[i]->item_name);
            newcart[newsize]->freq = 1;
            newsize++;
        } else {
            update(newcart, cart[i]->item_name, newsize);
        }
    }
    printf("item quantities\n");
    for (int i = 0; i < newsize; i++) {
        printf("%s - %d\n", newcart[i]->item_name, newcart[i]->freq);
    }

    for (int i=0; i<size; i++) {
        free(cart[i]->item_name);
        free(cart[i]);
    }
    for (int i=0;i<newsize;i++) {
        free(newcart[i]->item_name);
        free(newcart[i]);
    }

    return 0;
}