#include <stdio.h>
#define MAX 100

int stack[MAX];
int top = -1;

void push() {
    int value;

    if (top == MAX - 1) {
        printf("Stack Overflow!\n");
        return;
    }

    printf("Enter value: ");
    scanf("%d", &value);

    stack[++top] = value;
    printf("Element pushed successfully.\n");
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        return;
    }

    printf("Deleted element: %d\n", stack[top--]);
}

void peep() {
    int pos;

    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Enter position from top: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > top + 1) {
        printf("Invalid position!\n");
        return;
    }

    printf("Element: %d\n", stack[top - pos + 1]);
}

void change() {
    int pos, value;

    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Enter position from top: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > top + 1) {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter new value: ");
    scanf("%d", &value);

    stack[top - pos + 1] = value;
    printf("Element changed successfully.\n");
}

void display() {
    int i;

    if (top == -1) {
        printf("Stack is empty!\n");
        return;
    }

    printf("Stack elements (top to bottom):\n");

    for (i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    int choice;

    do {
        printf("\n--- STACK OPERATIONS ---\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEP\n");
        printf("4. CHANGE\n");
        printf("5. DISPLAY\n");
        printf("6. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                peep();
                break;

            case 4:
                change();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 6);

    return 0;
}
