#include <stdio.h>
#include <string.h>

#define SEATS 5
#define EMPTY 0
#define TAKEN 1

// Define Seat structure
typedef struct
{
    char name[20];
    int ID;
    int status;
} Seat;

// Declare array of Seat structures
Seat seats[5];

// Function to list all the taken seats
void listTakenSeat()
{
    printf("listTakenSeat():\n");
    int flag = 0;
    for (int i = 0; i < 5; i++)
    {
        if (seats[i].status == 1)
        {
            printf("Customer name: %s Seat number (ID): %d\n", seats[i].name, seats[i].ID);
            flag = 1;
        }
    }
    if (flag == 0)
        printf("The seat assignment list is empty\n");
}

// Function to assign a customer to a seat
void assignSeat()
{
    // Check if all seats are taken
    int allTaken = 1;
    for (int i = 0; i < 5; i++)
    {
        if (seats[i].status == EMPTY)
        {
            allTaken = 0;
            break;
        }
    }

    if (allTaken)
    {
        printf("Sorry, the plane is full.\n");
        return;
    }

    int seatNum;
    char name[20];

    printf("assignSeat():\n");
    printf("Enter the seat number:\n");
    scanf("%d", &seatNum);

    // Check if seatNum is valid
    if (seatNum < 1 || seatNum > 5)
    {
        printf("Please enter a seat number between 1 and 5\n");
        return;
    }

    // Check if seat is already taken
    if (seats[seatNum - 1].status == TAKEN)
    {
        printf("Occupied! Please choose another seat\n");
        return;
    }

    printf("Enter customer name:\n");
    scanf("%s", name);

    // Assign the seat
    seats[seatNum - 1].ID = seatNum;
    seats[seatNum - 1].status = TAKEN;
    strcpy(seats[seatNum - 1].name, name);

    printf("The seat has been assigned successfully\n");
}

// Function to remove a seat assignment
void removeSeat()
{
    printf("removeSeat():\n");

    // Check if all seats are empty
    int allEmpty = 1;
    for (int i = 0; i < 5; i++)
    {
        if (seats[i].status == TAKEN)
        {
            allEmpty = 0;
            break;
        }
    }

    if (allEmpty)
    {
        printf("All seats are currently vacant\n");
        return;
    }

    int ID;
    printf("Enter the seat number:\n");
    scanf("%d", &ID);
    if (ID < 1 || ID > 5)
    {
        printf("Please enter a seat number between 1 and 5\n");
        return;
    }
    if (seats[ID - 1].status == EMPTY)
    {
        printf("This seat is already vacant\n");
        return;
    }
    Seat s = {.ID = ID, .status = EMPTY};
    seats[ID - 1] = s;
    printf("Removal is successful\n");
}

// Main function
int main()
{
    // Initialize seats
    for (int i = 0; i < 5; i++)
    {
        seats[i].ID = i + 1;
        seats[i].status = 0;
    }
    int choice;
    do
    {
        printf("ABC AIRLINES SEATING RESERVATION PROGRAM:\n1: listTakenSeat()\n2: assignSeat()\n3: removeSeat()\n4: quit\nEnter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            listTakenSeat();
            break;
        case 2:
            assignSeat();
            break;
        case 3:
            removeSeat();
            break;
        case 4:
            break;
        default:
            printf("Invalid choice. Please enter a valid choice\n");
        }
    } while (choice != 4);
    return 0;
}