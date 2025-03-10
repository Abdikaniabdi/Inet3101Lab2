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
void add_record() { // Function to add a new part record
    if (record_count >= MAX_PARTS) { // Check if the database is full
        printf("\nDatabase is full! Cannot add more records.\n"); // Print error message
        return;
    }

    // Get user input
    printf("\nEnter Part Number: "); // Prompt user to enter part number
    scanf("%d", &database[record_count].part_number);
    printf("Enter Part Name: "); // Prompt user to enter part name
    scanf(" %[^\n]", database[record_count].part_name);
    printf("Enter Part Size: "); // Prompt user to enter part size
    scanf("%f", &database[record_count].part_size);
    printf("Enter Part Size Metric (cm, mm, in): "); // Prompt user to enter part size metric
    scanf(" %s", database[record_count].part_size_metric); 
    printf("Enter Part Cost: "); // Prompt user to enter part cost
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
    for (int i = 0; i < record_count; i++) { // Loop through all records
        printf("Part Number: %d\n", database[i].part_number);
        printf("Part Name: %s\n", database[i].part_name);
        printf("Part Size: %.2f %s\n", database[i].part_size, database[i].part_size_metric);
        printf("Part Cost: $%.2f\n", database[i].part_cost);
    }
}

// Function to print the number of records
void print_record_count() {
    printf("\nTotal records: %d\n", record_count); // Print the total number of records
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
                add_record(); // Call add_record function
                break;
            case 2:
                print_records(); // Call print_records function
                break;
            case 3:
                print_record_count(); // Call print_record_count function
                break;
            case 4:
                printf("\nExiting program. Goodbye!\n"); // Print exit message
                return 0;
            default:
                printf("\nInvalid choice! Please try again.\n"); // Print error message
        }
    }

    return 0;
}
