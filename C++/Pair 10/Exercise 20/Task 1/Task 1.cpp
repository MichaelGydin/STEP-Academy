#include <iostream>
using namespace std;

struct Book {
    string title;
    string author;
    string publisher;
    string genre;
};

void editBook(Book& book) {
    cout << "Enter new title: "; cin >> book.title;
    cout << "Enter new author: "; cin >> book.author;
    cout << "Enter new publisher: "; cin >> book.publisher;
    cout << "Enter new genre: "; cin >> book.genre;
}

void printBooks(const Book books[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << "Title: " << books[i].title << ", Author: " << books[i].author
            << ", Publisher: " << books[i].publisher << ", Genre: " << books[i].genre << endl;
    }
}

void searchBooksByAuthor(const Book books[], int size, const string& author) {
    for (int i = 0; i < size; ++i) {
        if (books[i].author == author) {
            cout << "Title: " << books[i].title << ", Publisher: " << books[i].publisher << ", Genre: " << books[i].genre << endl;
        }
    }
}

void searchBookByTitle(const Book books[], int size, const string& title) {
    for (int i = 0; i < size; ++i) {
        if (books[i].title == title) {
            cout << "Author: " << books[i].author << ", Publisher: " << books[i].publisher << ", Genre: " << books[i].genre << endl;
        }
    }
}

void sortBooksByTitle(Book books[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (books[j].title > books[j + 1].title) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

void sortBooksByAuthor(Book books[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (books[j].author > books[j + 1].author) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

void sortBooksByPublisher(Book books[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (books[j].publisher > books[j + 1].publisher) {
                Book temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
}

int main() {
    Book library[10] = {
        {"Book1", "Author1", "Publisher1", "Genre1"},
        {"Book2", "Author2", "Publisher2", "Genre2"},
        {"Book3", "Author1", "Publisher3", "Genre3"},
        {"Book4", "Author3", "Publisher4", "Genre4"},
        {"Book5", "Author4", "Publisher5", "Genre5"},
        {"Book6", "Author2", "Publisher1", "Genre6"},
        {"Book7", "Author3", "Publisher2", "Genre7"},
        {"Book8", "Author4", "Publisher3", "Genre8"},
        {"Book9", "Author1", "Publisher4", "Genre9"},
        {"Book10", "Author2", "Publisher5", "Genre10"}
    };

    int choice;
    while (true) {
        cout << "\nLibrary Menu:\n";
        cout << "1. Edit a book\n";
        cout << "2. Print all books\n";
        cout << "3. Search books by author\n";
        cout << "4. Search book by title\n";
        cout << "5. Sort books by title\n";
        cout << "6. Sort books by author\n";
        cout << "7. Sort books by publisher\n";
        cout << "8. Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 8) break;

        switch (choice) {
        case 1: {
            int index;
            cout << "Enter the index of the book to edit (0-9): ";
            cin >> index;
            if (index >= 0 && index < 10) {
                editBook(library[index]);
            }
            else {
                cout << "Invalid index!" << endl;
            }
            break;
        }
        case 2:
            printBooks(library, 10);
            break;
        case 3: {
            string author;
            cout << "Enter the author to search: ";
            cin.ignore();
            getline(cin, author);
            searchBooksByAuthor(library, 10, author);
            break;
        }
        case 4: {
            string title;
            cout << "Enter the title to search: ";
            cin.ignore();
            getline(cin, title);
            searchBookByTitle(library, 10, title);
            break;
        }
        case 5:
            sortBooksByTitle(library, 10);
            cout << "Books sorted by title." << endl;
            break;
        case 6:
            sortBooksByAuthor(library, 10);
            cout << "Books sorted by author." << endl;
            break;
        case 7:
            sortBooksByPublisher(library, 10);
            cout << "Books sorted by publisher." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
}
