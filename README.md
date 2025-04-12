# LibrarySystem

A simple library management system written in C to manage books with features like adding, deleting, editing, searching, sorting, and saving to a file.

## Features
- **Add a Book**: Add new books with details including author, title, category, year, publisher, and availability (1 for available, 0 for not available).
- **Delete a Book**: Remove a book from the library by its catalog number.
- **Edit a Book**: Modify the details of an existing book, such as author, title, category, year, publisher, or availability.
- **Search a Book**: Search for books by criteria like author, title, year, or availability status.
- **View All Books**: Display a list of all books in the library with their catalog numbers, titles, and authors, with an option to view full details of a selected book.
- **Sort All Books**: Sort the library by author, title, or availability status.
- **Save Changes**: Save all book data to `data/data.txt` for persistence.
- **Exit**: Exit the program.
## Requirements
- C compiler (e.g., GCC, MinGW)
- Standard C libraries

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/Akineyshen/LibrarySystem.git
   ```
2. Navigate to the project directory:
   ```bash
   cd LibrarySystem
   ```
3. Compile the code:
   ```bash
   gcc src/main.c -o main
   ```
4. Run the program:
   - On Windows: Double-click main.exe in the project directory, or run
    ```bash
   ./main.exe
   ```
   - On Linux: Run the compiled binary:
   ```bash
   ./main
   ```