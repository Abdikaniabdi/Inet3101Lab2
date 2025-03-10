#include <stdio.h>
#include <string.h>

#define MAX_PARTS 100  // Maximum number of parts that can be stored

// Structure to store part information
struct Part {
    int part_number;
    char part_name[50];
    float part_size;
    char part_size_metric[10];
    float part_cost;
};

// Global variables
struct Part database[MAX_PARTS];  // Array to store records
int record_count = 0;  // Keep track of how many records exist

// Function to add a new part record
void add_record() {
    if (record_count >= MAX_PARTS) {
        printf("\nDatabase is full! Cannot add more records.\n");
        return;
    }

    // Get user input
    printf("\nEnter Part Number: ");
    scanf("%d", &database[record_count].part_number);
    printf("Enter Part Name: ");
    scanf(" %[^\n]", database[record_count].part_name);
    printf("Enter Part Size: ");
    scanf("%f", &database[record_count].part_size);
    printf("Enter Part Size Metric (cm, mm, in): ");
    scanf(" %s", database[record_count].part_size_metric);
    printf("Enter Part Cost: ");
    scanf("%f", &database[record_count].part_cost);

    record_count++;  // Increase the record count

    printf("\nRecord added successfully!\n");
}

// Function to print all records
void print_records() {
    if (record_count == 0) {
        printf("\nNo records found!\n");
        return;
    }

    printf("\nList of Parts:\n");
    printf("---------------------------------------\n");
    for (int i = 0; i < record_count; i++) {
        printf("Part Number: %d\n", database[i].part_number);
        printf("Part Name: %s\n", database[i].part_name);
        printf("Part Size: %.2f %s\n", database[i].part_size, database[i].part_size_metric);
        printf("Part Cost: $%.2f\n", database[i].part_cost);
        printf("---------------------------------------\n");
    }
}

// Function to print the number of records
void print_record_count() {
    printf("\nTotal records: %d\n", record_count);
}

// Main function with a simple menu
int main() {
    int choice;

    while (1) {
        // Print menu options
        printf("\nMENU\n");
        printf("=====\n");
        printf("1. Add new record\n");
        printf("2. Print all records\n");
        printf("3. Print number of records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process user choice
        switch (choice) {
            case 1:
                add_record();
                break;
            case 2:
                print_records();
                break;
            case 3:
                print_record_count();
                break;
            case 4:
                printf("\nExiting program. Goodbye!\n");
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }

    return 0;
}
