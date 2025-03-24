/*
 * 🚨 WARNING: CHALLENGE MODE ACTIVATED 🚨
 * 
 * 1️⃣ Sit back, take a deep breath, and **THINK**.
 * 2️⃣ For the next **10 minutes**, avoid using **Gen AI, ChatGPT, or any shortcuts**.
 * 3️⃣ Trust your **brain**—you’re smarter than you think!
 * 4️⃣ Consider yourself a **LOSER** if you cheat. Seriously, promise yourself you won't. 😤
 * 5️⃣ If you solve it on your own, **you WIN** and level up as a true programmer and come and meet me ! 
 * 
 * 
 * 💡 Remember: The best coders aren’t the ones who copy-paste. They are the ones who **struggle, think, fail, and then succeed.** 
 *    
 * Now, write your code! You got this! 💪🔥
 */
#include <stdio.h>

#define MAX_ROOMS 5  // Define the maximum number of rooms

// Function prototypes
void initializeSystem();
void displayMenu();
void controlLights();
void readTemperature();
void detectMotion();
void securitySystem();
void analyzeHouseStatus();

// Global arrays to store states
int lights[MAX_ROOMS];
int temperature[MAX_ROOMS];
int motion[MAX_ROOMS];
int locks[MAX_ROOMS];

int main() {
    initializeSystem();
    int choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                controlLights();
                break;
            case 2:
                readTemperature();
                break;
            case 3:
                detectMotion();
                break;
            case 4:
                securitySystem();
                break;
            case 5:
                analyzeHouseStatus();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice, try again.\n");
        }
    } while (choice != 6);
    return 0;
}

void initializeSystem() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        lights[i] = 0;
        temperature[i] = 22 + (i % 5);
        motion[i] = 0;
        locks[i] = 1;
    }
    printf("System initialized with all lights OFF, doors LOCKED, and no motion detected.\n");
}

void displayMenu() {
    printf("\n===== Smart Home Menu =====\n");
    printf("1. Toggle Light\n");
    printf("2. Read Temperature\n");
    printf("3. Check Motion Sensor\n");
    printf("4. Lock/Unlock Security System\n");
    printf("5. House Status Summary\n");
    printf("6. Exit\n");
}

void controlLights() {
    int room;
    printf("Enter room number to toggle light (1-%d): ", MAX_ROOMS);
    scanf("%d", &room);
    if (room >= 1 && room <= MAX_ROOMS) {
        lights[room - 1] = !lights[room - 1];
        printf("Light in Room %d is now %s.\n", room, lights[room - 1] ? "ON" : "OFF");
    } else {
        printf("Invalid room number.\n");
    }
}

void readTemperature() {
    int room;
    printf("Enter room number to read temperature (1-%d): ", MAX_ROOMS);
    scanf("%d", &room);
    if (room >= 1 && room <= MAX_ROOMS) {
        printf("Temperature in Room %d: %d°C\n", room, temperature[room - 1]);
        if (temperature[room - 1] > 30) {
            printf("Warning: High temperature detected in Room %d!\n", room);
        }
    } else {
        printf("Invalid room number.\n");
    }
}

void detectMotion() {
    int room;
    printf("Enter room number to check motion (1-%d): ", MAX_ROOMS);
    scanf("%d", &room);
    if (room >= 1 && room <= MAX_ROOMS) {
        printf("Motion in Room %d: %s\n", room, motion[room - 1] ? "Detected" : "No Motion");
    } else {
        printf("Invalid room number.\n");
    }
}

void securitySystem() {
    int room;
    printf("Enter room number to lock/unlock (1-%d): ", MAX_ROOMS);
    scanf("%d", &room);
    if (room >= 1 && room <= MAX_ROOMS) {
        locks[room - 1] = !locks[room - 1];
        printf("Room %d is now %s.\n", room, locks[room - 1] ? "LOCKED" : "UNLOCKED");
    } else {
        printf("Invalid room number.\n");
    }
}

void analyzeHouseStatus() {
    printf("\nHouse Status:\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        printf("- Room %d: Light %s, Temp %d°C, %s, %s\n",
               i + 1,
               lights[i] ? "ON" : "OFF",
               temperature[i],
               motion[i] ? "Motion Detected" : "No Motion",
               locks[i] ? "Locked" : "Unlocked");
    }
}
