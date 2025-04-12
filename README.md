# Library Management System
![Language](https://img.shields.io/badge/language%20C-%23548dff?style=for-the-badge&logo=c&logoColor=FFFFFF)
![Size](https://img.shields.io/github/repo-size/Akineyshen/LibrarySystem?label=Size&style=for-the-badge&color=548dff&labelColor=FCFCFC)
![Last Commit](https://img.shields.io/github/last-commit/Akineyshen/LibrarySystem?label=Last%20Commit&style=for-the-badge&color=548dff&labelColor=FCFCFC)
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

## Screenshots

<img src="https://i.imgur.com/kxzxkB3.png" alt="Main Menu Interface">

<img src="https://i.imgur.com/FvdctVg.png" alt="Main Menu Interface">

<img src="https://i.imgur.com/8NYVZJN.png" alt="Main Menu Interface">