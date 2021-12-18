#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Room_type {
    int room_id;
    char room_name[10];
    int room_price;
};

struct Customer {
    int cus_id;
    char cus_name[255];
    int cus_age;
    char cus_death[255];
    char cus_place[255];
    int cus_year;
    Room_type r;
};

Customer c[50];

int idxC = 0;
int idxR = 0;

#include "customer.h"
void import_data_from_file();
void menu();
// void read(Customer *c);
// void create(Customer *c);

int main () {
    import_data_from_file();
    menu();
    return 0;
}

// while(fscanf(fp, "%[^#]#%d\n", names[index], &scores[index]) != EOF) {
//         index++;
//     }

void import_data_from_file() {
    FILE *fc, *fr;
    fc = fopen("../customer/customer_data.txt", "r");
    fr = fopen("../room/room.txt", "r");
    // if (!fc) {
    //     puts("Cant find");
    // } else {
    //     puts("Find");
    // }
    while(fscanf(fc, "C%d,%[^,],%d,%[^,],%[^,],%d,R%d\n", &c[idxC].cus_id, c[idxC].cus_name, &c[idxC].cus_age, c[idxC].cus_death, c[idxC].cus_place, &c[idxC].cus_year, &c[idxC].r.room_id) != EOF) {
        // printf("%d", c[idxC].cus_age);
        // printf("%s,%s,%d,%s,%s,%d,%s\n", c[idxC].cus_id, c[idxC].cus_name, c[idxC].cus_age, c[idxC].cus_death, c[idxC].cus_place,  c[idxC].cus_year, c[idxC].r.room_id);
        idxC++;
    }

    printf("\n\n");
    
    while(fscanf(fr, "R%d,%[^,],%d\n", &c[idxR].r.room_id, c[idxR].r.room_name, &c[idxR].r.room_price) != EOF) {
        // printf("%s,%s,%d", c[idxR].r.room_id, c[idxR].r.room_name, c[idxR].r.room_price);
        idxR++;
    }

    fclose(fc);
    fclose(fr);
}

void main_menu() {
    printf("Hotel del Jojo\n");
    printf("1. Add new customer\n");
    printf("2. Read data\n");
    printf("3. Update data\n");
    printf("4. Remove data\n");
    printf("5. Exit\n\n");
}

void menu() {
    bool onApp = true;

    while (onApp) {
        main_menu();
        int choice = -1;
        // import_data_from_file();
        do {
            printf("Choice [1-5] >> ");
            scanf("%d", &choice); getchar();
        } while (choice<1 || choice>5);

        if (choice==1) {
            create(c);
            menu();
        } else if (choice==2) {
            read(c, idxC);
            menu();
        } else if (choice==3) {
            update(c);
            menu();
        // } else if (choice==4) {
        //     remove();
        } else if (choice==5) {
            // exit();
            onApp = false;
        }
    }
}
