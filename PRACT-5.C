#include <stdio.h>
#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void insert() {
    int value;

    if (rear == MAX - 1) {
        printf("Queue Overflow!\n");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    if (front == -1)
        front = 0;

    queue[++rear] = value;
    printf("Element inserted successfully.\n");
}

void delete() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);
    front++;

    if (front > rear) {
        front = -1;
        rear = -1;
    }
}

void display() {
    int i;

    if (front == -1) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue elements: ");

    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

int main() {
    int choice;

    do {
        printf("\n--- QUEUE OPERATIONS ---\n");
        printf("1. INSERT (Enqueue)\n");
        printf("2. DELETE (Dequeue)\n");
        printf("3. DISPLAY\n");
        printf("4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                delete();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 4);

    return 0;
}
