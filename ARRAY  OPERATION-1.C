#include <stdio.h>

int main() {
    int arr[100], n, i, choice, pos, value, found;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\n--- ARRAY OPERATIONS ---\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Searching\n");
        printf("4. Traversal (Display)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (n >= 100) {
                    printf("Array is full!\n");
                    break;
                }

                printf("Enter position (1 to %d): ", n + 1);
                scanf("%d", &pos);

                if (pos < 1 || pos > n + 1) {
                    printf("Invalid position!\n");
                    break;
                }

                printf("Enter value to insert: ");
                scanf("%d", &value);

                for (i = n; i >= pos; i--) {
                    arr[i] = arr[i - 1];
                }

                arr[pos - 1] = value;
                n++;

                printf("Element inserted successfully.\n");
                break;

            case 2:
                if (n == 0) {
                    printf("Array is empty!\n");
                    break;
                }

                printf("Enter position to delete (1 to %d): ", n);
                scanf("%d", &pos);

                if (pos < 1 || pos > n) {
                    printf("Invalid position!\n");
                    break;
                }

                value = arr[pos - 1];

                for (i = pos - 1; i < n - 1; i++) {
                    arr[i] = arr[i + 1];
                }

                n--;

                printf("Deleted element: %d\n", value);
                break;

            case 3:
                printf("Enter element to search: ");
                scanf("%d", &value);

                found = 0;

                for (i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        printf("Element found at position %d\n", i + 1);
                        found = 1;
                        break;
                    }
                }

                if (!found) {
                    printf("Element not found.\n");
                }
                break;

            case 4:
                if (n == 0) {
                    printf("Array is empty!\n");
                } else {
                    printf("Array elements: ");
                    for (i = 0; i < n; i++) {
                        printf("%d ", arr[i]);
                    }
                    printf("\n");
                }
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
