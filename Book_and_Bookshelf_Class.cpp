#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    int pages;

public:
    Book(string t = "Untitled", int p = 0) : title(t), pages(p) {
        cout << "Constructor: \"" << title << "\" with " << pages << " pages\n";
    }

    ~Book() {
        cout << "Destructor: \"" << title << "\" destroyed\n";
    }

    void display() const {
        cout << "Title: " << title << ", Pages: " << pages << endl;
    }
};

class BookShelf {
private:
    Book** books;
    int size;

public:
    BookShelf() {
        size = 3;
        books = new Book*[size];
        books[0] = new Book("C++ Fundamentals", 300);
        books[1] = new Book("Data Structures", 450);
        books[2] = new Book("Algorithms", 500);
    }

    ~BookShelf() {
        for (int i = 0; i < size; ++i) {
            delete books[i];
        }
        delete[] books;
        cout << "BookShelf Destructor: Shelf destroyed\n";
    }

    void displayBooks() const {
        cout << "\nExample2:\n";
        cout << "Books on shelf:\n";
        for (int i = 0; i < size; ++i) {
            books[i]->display();
        }
        cout << "\n--- End of Program ---\n";
    }
};

int main() {
    // Example 1
    {
        Book library[3] = {
            Book("C++ Fundamentals", 300),
            Book("Data Structures", 450),
            Book("Algorithms", 500)
        };

        cout << "\nExample1:\n";
        cout << "--- Library Contents ---\n";
        for (int i = 0; i < 3; ++i) {
            library[i].display();
        }
        cout << "\n--- End of Program ---\n";
    }

    // Example 2
    {
        BookShelf* shelf = new BookShelf();
        shelf->displayBooks();
        delete shelf;
    }

    return 0;
}
