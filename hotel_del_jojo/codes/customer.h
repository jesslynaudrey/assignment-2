void create (Customer *c) {
    char inputNama[500];
    int fail;
    Customer *newCus = (Customer*)malloc(sizeof(Customer));
    do {
        fail=0;
        printf("Name (lowercase letters): ");
        scanf("%s", inputNama); getchar();
        for (int i = 0; i < strlen(inputNama); i++) {
            if (inputNama[i]<'a') {
                fail++;
            }
        }
    } while (fail!=0);

    int age;
    printf("Age (0 - 100): ");
    scanf("%d", &age); getchar();
    while (age<0 || age>100) {
        printf("Age (0 - 100): ");
        scanf("%d", &age); getchar();
    }
    
    char cause[300];
    printf("Cause of Death (max 255 letters): ");
    scanf("%[^\n]", cause); getchar();
    while (strlen(cause)>255) {
        printf("Cause of Death (max 255 letters): ");
        scanf("%[^\n]", cause); getchar();
    }

    char place[300];
    printf("Resting Place (max 255 letters): ");
    scanf("%[^\n]", place); getchar();
    while (strlen(place)>255) {
        printf("Resting Place (max 255 letters): ");
        scanf("%[^\n]", place); getchar();
    }

    char roomType[300];
    int roomID;
    printf("Room Type (Pantai, Rooftop, Taman, Bar): ");
    scanf("%s", roomType); getchar();
    do
    {
        printf("Room Type (Pantai, Rooftop, Taman, Bar): ");
        scanf("%s", roomType); getchar();
        if(strcmp(roomType, "Pantai") == 0){
            roomID = 1;
        } else if (strcmp(roomType, "Rooftop") == 0){
            roomID = 2;
        } else if (strcmp(roomType, "Taman") == 0){
            roomID = 3;
        } else if (strcmp(roomType, "Bar") == 0){
            roomID = 4;
        }
    } while (strcmp(roomType, "Pantai") != 0 && strcmp(roomType, "Rooftop") != 0 && strcmp(roomType, "Taman") != 0 && strcmp(roomType, "Bar") != 0);

    printf("Welcome to Hotel del Jojo!\n");

    c[idxC].cus_id = idxC+1;
    strcpy(c[idxC].cus_name, inputNama);
    c[idxC].cus_age = age;
    strcpy(c[idxC].cus_death, cause);
    strcpy(c[idxC].cus_place, place);
    strcpy(c[idxC].r.room_name, roomType);
    idxC++;

    FILE *fca = fopen("../customer/customer_data.txt", "a");
    fprintf(fca, "\n");
    if (idxC<10) {
        fprintf(fca, "C00%d,%s,%d,%s,%s,0000,R00%d", idxC, inputNama, age, cause, place, roomID);
    } else if (idxC>10) {
        fprintf(fca, "C0%d,%s,%d,%s,%s,0000,R00%d", idxC, inputNama, age, cause, place, roomID);
    }
    fclose(fca);

}


void read(Customer *c, int idxC) {
    printf("|   | ID   | Name  | Age | Room    |\n");
    printf("|---|------|-------|-----|---------|\n");
    for (int i = 0; i < idxC; i++) {
        if (c[i].cus_id<10) {
            printf("| %d | COO%d ", i+1, c[i].cus_id);
        } else if (c[i].cus_id < 100) {
            printf("| %d | CO%d ", i+1, c[i].cus_id);
        }
        printf("| %-5s | %-3d | %-7s |\n", c[i].cus_name, c[i].cus_age, c[i].r.room_name);
    }
    puts("");
}

void update(Customer *c) {
    int ID, temp;
    char roomNameUpdate[200];

    do {
        printf("Enter ID: ");
        scanf("C%d", &ID); getchar();
    } while (ID>idxC);

    for(int i = 0; i < idxC; i++){
        if(c[i].cus_id == ID){
            temp = i;
        }
    }   
    printf("%d", temp);

    int roomID;
    do {
        printf("Insert New Room (Pantai, Rooftop, Taman, Bar): ");
        scanf("%s", roomNameUpdate); getchar();
        if(strcmp(roomNameUpdate, "Pantai") == 0){
            roomID = 1;
        } else if (strcmp(roomNameUpdate, "Rooftop") == 0){
            roomID = 2;
        } else if (strcmp(roomNameUpdate, "Taman") == 0){
            roomID = 3;
        } else if (strcmp(roomNameUpdate, "Bar") == 0){
            roomID = 4;
        }
    } while (strcmp(roomNameUpdate, "Pantai") != 0 && strcmp(roomNameUpdate, "Rooftop") != 0 && strcmp(roomNameUpdate, "Taman") != 0 && strcmp(roomNameUpdate, "Bar") != 0);

    strcpy(c[temp].r.room_name, roomNameUpdate);

    FILE *fcu = fopen("../customer/customer_data.txt", "w");

    for(int i = 0; i < idxC; i++){
        if(idxC < 10){
            if(i == temp){
                fprintf(fcu, "C00%d,%s,%d,%s,%s,%d,R00%d\n", i+1, c[i].cus_name, c[i].cus_age, c[i].cus_death, c[i].cus_place, c[i].cus_year, roomID);
            }else {
                fprintf(fcu, "C00%d,%s,%d,%s,%s,%d,R00%d\n", i+1, c[i].cus_name, c[i].cus_age, c[i].cus_death, c[i].cus_place, c[i].cus_year, roomID);
            }
        } else if (idxC < 100){
            if(i == temp){
                fprintf(fcu, "C0%d,%s,%d,%s,%s,%d,R00%d\n", i+1, c[i].cus_name, c[i].cus_age, c[i].cus_death, c[i].cus_place, c[i].cus_year, roomID);
            }else {
                fprintf(fcu, "C0%d,%s,%d,%s,%s,%d,R00%d\n", i+1, c[i].cus_name, c[i].cus_age, c[i].cus_death, c[i].cus_place, c[i].cus_year, roomID);
            }
        }
    }
    fclose(fcu);
}