#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define PATH "data/data.txt"

typedef struct Book
{
    int id;
    char author[100];
    char title[100];
    char category[100];
    int year;
    char publisher[100];
    int available;
    struct Book *next;
} Book;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int compareBooksByAuthor(const void* a, const void* b) {
    return strcmp(((Book*)a)->author, ((Book*)b)->author);
}

int compareBooksByTitle(const void* a, const void* b) {
    return strcmp(((Book*)a)->title, ((Book*)b)->title);
}

int compareBooksByAvailability(const int* a, const int* b) {
    return *a - *b;
}

int getCountBook(Book *head);
Book* getLastBook(Book *head);
Book* getBookById(Book *head, int id);
void addBook(Book **head);
void addBookToEnd(Book **head, Book *book);
void deleteBook(Book **head);
int printAllBooks(Book *head);
void printBook(Book *book);
void readFile(Book **head);
void writeFile(Book *head);
void editBook(Book *head);
void searchBook(Book *head);
Book* sortBooks(Book *head);

int main()
{
    Book *head = NULL;
    readFile(&head);

    printf(" _     ___ ____  ____      _    ______   __\n");
    printf("| |   |_ _| __ )|  _ \\    / \\  |  _ \\ \\ / /\n");
    printf("| |    | ||  _ \\| |_) |  / _ \\ | |_) \\ V / \n");
    printf("| |___ | || |_) |  _ <  / ___ \\|  _ < | |  \n");
    printf("|_____|___|____/|_| \\_\\/_/   \\_\\_| \\_\\|_|  \n");

    int choice;
    while (1) {
        printf("\nLibrary management menu:\n");
        printf("\n1. Add a book\n");
        printf("2. Delete a book\n");
        printf("3. Edit a book\n");
        printf("4. Search a book\n");
        printf("5. View all books\n");
        printf("6. Sort all books\n");
        printf("7. Save Changes\n");
        printf("8. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addBook(&head);
                break;
            case 2:
                clearScreen();
                printf("Deleting a book\n");
                deleteBook(&head);
                clearScreen();
                break;
            case 3:
                clearScreen();
                printf("Book editing\n");
                editBook(head);
                clearScreen();
                break;
            case 4:
                clearScreen();
                searchBook(head);
                break;
            case 5:
                clearScreen();
                printAllBooks(head);
                break;
            case 6:
                clearScreen();
                head = sortBooks(head);
                break;
            case 7:
                writeFile(head);
                clearScreen();
                break;
            case 8:
                printf("Goodbye\n");
                writeFile(head);
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

int getCountBook(Book *head)
{
    int counter = 0;
    while(head)
    {
        head = head->next;
        counter++;
    }
    return counter;
}

Book* getBookById(Book *head, int id)
{
    while(head)
    {
        if(head->id == id)
        {
            return head;
        }
        head = head->next;
    }
    return NULL;
}

Book* getLastBook(Book *head)
{
    if (head == NULL)
        return NULL;

    while(head->next)
    {
        head = head->next;
    }

    return head;
}

void addBook(Book **head)
{
    clearScreen();
    Book *last = getLastBook(*head);
    Book *tmp = (Book*) malloc(sizeof(Book));

    printf("Book data entry \n");
    tmp->id = getCountBook(*head);
    printf("\nEnter the author: ");
    fflush(stdin);
    fgets(tmp->author, 100 , stdin);
    tmp->author[strlen(tmp->author)-1] = '\0';

    printf("Enter the title: ");
    fflush(stdin);
    fgets(tmp->title, 100, stdin);
    tmp->title[strlen(tmp->title)-1] = '\0';

    printf("Enter the category: ");
    fflush(stdin);
    fgets(tmp->category, 100, stdin);
    tmp->category[strlen(tmp->category)-1] = '\0';

    printf("Enter the publisher: ");
    fflush(stdin);
    fgets(tmp->publisher, 100, stdin);
    tmp->publisher[strlen(tmp->publisher)-1] = '\0';

    printf("Enter the year: ");
    scanf("%d", &tmp->year);

    printf("Enter the availability (1 for available, 0 for not available): ");
    scanf("%d", &tmp->available);
    while (tmp->available != 1 && tmp->available != 0)
    {
        printf("\nInvalid input. Please enter 1 for available or 0 for not available: ");
        scanf("%d", &tmp->available);
    }

    tmp->next = NULL;
    if (last == NULL) {
        *head = tmp;
    } else {
        last->next = tmp;
    }
    clearScreen();
    printf("Book successfully added!\n");
}

void addBookToEnd(Book **head, Book *book)
{
    Book *last = getLastBook(*head);
    Book *tmp = (Book*) malloc(sizeof(Book));
    tmp->id = getCountBook(*head);
    strcpy(tmp->author, book->author);
    strcpy(tmp->title, book->title);
    strcpy(tmp->category, book->category);
    tmp->year = book->year;
    strcpy(tmp->publisher, book->publisher);
    tmp->available = book->available;
    tmp->next = NULL;

    if (last == NULL) {
        *head = tmp;
    } else {
        last->next = tmp;
    }
}

int printAllBooks(Book *head)
{
    if (!head) {
        printf("No books available\n");
        return 0;
    }

    Book *tmp = head;
    while(head)
    {
        printf("\nCatalog: %d\n", head->id);
        printf("Title: %s \n", head->title);
        printf("Author: %s \n", head->author);
        head = head->next;
    }

    head = tmp;

    int choice;
    printf("\nView the full information of the selected book?\n");
    printf("1. Yes \n2. No\n");
    printf("Choose: ");
    scanf("%d", &choice);
    if(choice == 2)
        return 0;
    if (choice == 1) {
        printf("\nEnter the catalog number of the book you want to view information of: ");
        int id;
        scanf("%d", &id);
        clearScreen();
        printBook(getBookById(head, id));
    }
    return 0;
}

void writeFile(Book *head)
{
    FILE *file;
    file = fopen(PATH, "wb");
    while(head)
    {
        fprintf(file, "%d,%s,%s,%s,%d,%s,%d\n", head->id, head->author, head->title, head->category, head->year, head->publisher, head->available);
        head = head->next;
    }
    fclose(file);
}

void readFile(Book **head)
{
    FILE *file = fopen(PATH, "rb");
    if (!file) {
        return;
    }
    Book book;
    while (fscanf(file, "%d,%99[^,],%99[^,],%99[^,],%d,%99[^,],%d\n", &book.id, book.author, book.title, book.category, &book.year, book.publisher, &book.available) != EOF)
    {
        addBookToEnd(head, &book);
    }
    fclose(file);
}

void printBook(Book *book)
{
    if (book) {
        printf("\nCatalog: %d \n", book->id);
        printf("Author: %s \n", book->author);
        printf("Title: %s \n", book->title);
        printf("Category: %s \n", book->category);
        printf("Year: %d \n", book->year);
        printf("Publisher: %s \n", book->publisher);
        printf("Available: %d \n", book->available);
    } else {
        printf("Book not found!\n");
    }
}

void deleteBook(Book **head)
{
    int id;
    printf("\nEnter the catalog number of the book to delete: ");
    scanf("%d", &id);

    Book *temp = *head;
    Book *prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Book not found!\n");
        return;
    }

    if (prev == NULL) {
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Book deleted successfully!\n");
}

void editBook(Book *head)
{
    int id;
    printf("\nEnter book catalog to edit: ");
    scanf("%d", &id);

    Book *book = getBookById(head, id);

    if(book)
    {
        printf("Enter the new author: ");
        fflush(stdin);
        fgets(book->author, 100 , stdin);
        book->author[strlen(book->author)-1] = '\0';

        printf("Enter the new title: ");
        fflush(stdin);
        fgets(book->title, 100 , stdin);
        book->title[strlen(book->title)-1] = '\0';

        printf("Enter the new category: ");
        fflush(stdin);
        fgets(book->category, 100 , stdin);
        book->category[strlen(book->category)-1] = '\0';

        printf("Enter the new year: ");
        scanf("%d", &book->year);

        printf("Enter the new publisher: ");
        fflush(stdin);
        fgets(book->publisher, 100 , stdin);
        book->publisher[strlen(book->publisher)-1] = '\0';

        printf("Enter the new availability (1 for available, 0 for not available): ");
        scanf("%d", &book->available);

        printf("Book edited successfully!\n");
    } else {
        printf("Book not found!\n");
    }
}

void searchBook(Book *head)
{
    int choice;
    printf("\nEnter your search criteria:\n");
    printf("1. Author\n");
    printf("2. Title\n");
    printf("3. Year\n");
    printf("4. Availability\n");
    printf("\nChoose: ");
    scanf("%d", &choice);

    if (choice == 1) {
        char author[100];
        printf("Enter author name: ");
        scanf("%s", author);
        clearScreen();
        printf("Books by %s:\n", author);

        while(head) {
            if (strcmp(head->author, author) == 0)
                printBook(head);
            head = head->next;
        }

    } else if (choice == 2) {
        char title[100];
        printf("Enter title: ");
        scanf("%s", title);
        clearScreen();
        printf("Books with title: %s \n", title);
        while(head) {
            if (strcmp(head->title, title) == 0)
                printBook(head);
            head = head->next;
        }
    } else if (choice == 3) {
        int year;
        printf("Enter year: ");
        scanf("%d", &year);
        clearScreen();
        printf("Books from year: %d \n", year);
        while(head) {
            if (head->year == year)
                printBook(head);
            head = head->next;
        }
    } else if (choice == 4) {
        int available;
        printf("Enter availability (1 for available, 0 for not available): ");
        scanf("%d", &available);
        clearScreen();
        printf("\nBooks %s:\n", available == 1 ? "available" : "not available");
        while(head) {
            if (head->available == available)
                printBook(head);
            head = head->next;
        }
    } else {
        printf("Invalid choice.\n");
    }
}

Book* sortBooks(Book *head)
{
    int size = getCountBook(head);
    if (size < 2) {
        printf("Not enough books to sort\n");
        return head;
    }

    Book *Books = (Book*)malloc(size * sizeof(Book));
    Book *tmp = head;

    for (int i = 0; i < size; i++) {
        Books[i] = *head;
        head = head->next;
    }
    head = tmp;

    printf("Sort by:\n1. Author\n2. Title\n3. Availability\nChoose: ");
    int choice;
    scanf("%d", &choice);
    clearScreen();

    if (choice == 1) {
        qsort(Books, size, sizeof(Book), compareBooksByAuthor);
    } else if (choice == 2) {
        qsort(Books, size, sizeof(Book), compareBooksByTitle);
    } else if (choice == 3) {
        qsort(Books, size, sizeof(Book), (int(*) (const void *, const void *)) compareBooksByAvailability);
    } else {
        printf("Invalid choice.\n");
        free(Books);
        return head;
    }

    for (int i = 0; i < size; i++) {
        *head = Books[i];
        head = head->next;
    }
    free(Books);
    return tmp;
}
