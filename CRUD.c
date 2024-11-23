#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int id;
    char name[50];
    int age;
} User;
void addUser();
void displayUsers();
void updateUser();
void deleteUser();
int userExists(int id);

int main() {
    int choice;

    do {
        printf("\nCRUD Operations Menu:\n");
        printf("1. Add User\n");
        printf("2. Display Users\n");
        printf("3. Update User\n");
        printf("4. Delete User\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser();
                break;
            case 2:
                displayUsers();
                break;
            case 3:
                updateUser();
                break;
            case 4:
                deleteUser();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
void addUser() {
    FILE *file = fopen("users.txt", "a");
    if (!file) {
        perror("Error opening file");
        return;
    }
    User user;
    printf("Enter user ID: ");
    scanf("%d", &user.id);
    if (userExists(user.id)) {
        printf("User with ID %d already exists.\n", user.id);
        fclose(file);
        return;
    }
    printf("Enter name: ");
    scanf(" %[^\n]", user.name);
    printf("Enter age: ");
    scanf("%d", &user.age);
    fprintf(file, "%d %s %d\n", user.id, user.name, user.age);
    printf("User added successfully.\n");
    fclose(file);
}
void displayUsers() {
    FILE *file = fopen("users.txt", "r");
    if (!file) {
        perror("Error opening file");
        return;
    }
    User user;
    printf("\nUser Records:\n");
    printf("ID\tName\t\tAge\n");
    printf("---------------------------------\n");
    while (fscanf(file, "%d %49s %d", &user.id, user.name, &user.age) != EOF) {
        printf("%d\t%s\t\t%d\n", user.id, user.name, user.age);
    }
    fclose(file);
}
void updateUser() {
    FILE *file = fopen("users.txt", "r");
    if (!file) {
        perror("Error opening file");
        return;
    }
    int id;
    printf("Enter user ID to update: ");
    scanf("%d", &id);
    if (!userExists(id)) {
        printf("User with ID %d does not exist.\n", id);
        fclose(file);
        return;
    }
    FILE *temp = fopen("temp.txt", "w");
    if (!temp) {
        perror("Error opening temporary file");
        fclose(file);
        return;
    }
    User user;
    int found = 0;
    while (fscanf(file, "%d %49s %d", &user.id, user.name, &user.age) != EOF) {
        if (user.id == id) {
            found = 1;
            printf("Enter new name: ");
            scanf(" %[^\n]", user.name);
            printf("Enter new age: ");
            scanf("%d", &user.age);
        }
        fprintf(temp, "%d %s %d\n", user.id, user.name, user.age);
    }
    if (found) {
        printf("User updated successfully.\n");
    } else {
        printf("User not found.\n");
    }
    fclose(file);
    fclose(temp);
    remove("users.txt");
    rename("temp.txt", "users.txt");
}
void deleteUser() {
    FILE *file = fopen("users.txt", "r");
    if (!file) {
        perror("Error opening file");
        return;
    }
    int id;
    printf("Enter user ID to delete: ");
    scanf("%d", &id);
    if (!userExists(id)) {
        printf("User with ID %d does not exist.\n", id);
        fclose(file);
        return;
    }
    FILE *temp = fopen("temp.txt", "w");
    if (!temp) {
        perror("Error opening temporary file");
        fclose(file);
        return;
    }
    User user;
    int found = 0;
    while (fscanf(file, "%d %49s %d", &user.id, user.name, &user.age) != EOF) {
        if (user.id == id) {
            found = 1;
            continue; // Skip the user to delete
        }
        fprintf(temp, "%d %s %d\n", user.id, user.name, user.age);
    }
    if (found) {
        printf("User deleted successfully.\n");
    } else {
        printf("User not found.\n");
    }
    fclose(file);
    fclose(temp);
    remove("users.txt");
    rename("temp.txt", "users.txt");
}
int userExists(int id) {
    FILE *file = fopen("users.txt", "r");
    if (!file) {
        return 0;
    }
    User user;
    while (fscanf(file, "%d %49s %d", &user.id, user.name, &user.age) != EOF) {
        if (user.id == id) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}
