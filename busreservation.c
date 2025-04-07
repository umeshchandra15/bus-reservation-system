#include <stdio.h>
#include <string.h>

#define TOTAL_SEATS 32

// Bus structure
struct Bus {
    char busNumber[10];
    char driver[50];
    char from[30];
    char to[30];
    char arrival[10];
    char departure[10];
    char seats[TOTAL_SEATS][50]; // Each seat holds a passenger name
};

// Initialize bus with empty seats
void initializeBus(struct Bus *bus) {
    for (int i = 0; i < TOTAL_SEATS; i++) {
        strcpy(bus->seats[i], "Empty");
    }
}

// Install bus details
void installBus(struct Bus *bus) {
    printf("Enter Bus Number: ");
    scanf("%s", bus->busNumber);
    printf("Enter Driver Name: ");
    scanf("%s", bus->driver);
    printf("From: ");
    scanf("%s", bus->from);
    printf("To: ");
    scanf("%s", bus->to);
    printf("Arrival Time: ");
    scanf("%s", bus->arrival);
    printf("Departure Time: ");
    scanf("%s", bus->departure);
    initializeBus(bus);
    printf("Bus Installed Successfully!\n");
}

// Book a seat
void reserveSeat(struct Bus *bus) {
    int seatNumber;
    printf("Enter seat number to reserve (1-32): ");
    scanf("%d", &seatNumber);

    if (seatNumber < 1 || seatNumber > TOTAL_SEATS) {
        printf("Invalid seat number!\n");
        return;
    }

    if (strcmp(bus->seats[seatNumber - 1], "Empty") == 0) {
        printf("Enter passenger name: ");
        scanf("%s", bus->seats[seatNumber - 1]);
        printf("Seat %d reserved successfully!\n", seatNumber);
    } else {
        printf("Seat already reserved by %s.\n", bus->seats[seatNumber - 1]);
    }
}

// Show bus status
void showBus(struct Bus *bus) {
    printf("\nBus Number: %s\nDriver: %s\nFrom: %s To: %s\nArrival: %s Departure: %s\n",
           bus->busNumber, bus->driver, bus->from, bus->to, bus->arrival, bus->departure);

    printf("\nSeat Status:\n");
    for (int i = 0; i < TOTAL_SEATS; i++) {
        printf("Seat %2d: %s\n", i + 1, bus->seats[i]);
    }
}

int main() {
    struct Bus myBus;
    int choice;

    while (1) {
        printf("\n=== BUS RESERVATION SYSTEM ===\n");
        printf("1. Install Bus\n");
        printf("2. Reserve Seat\n");
        printf("3. Show Bus Status\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                installBus(&myBus);
                break;
            case 2:
                reserveSeat(&myBus);
                break;
            case 3:
                showBus(&myBus);
                break;
            case 4:
                printf("Exiting... Thank you!\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
