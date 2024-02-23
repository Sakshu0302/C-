#include<iostream>
#include<string.h>
using namespace std;

class book_store {
public:
    char* title;
    char* author;
    char* publisher;
    double price;
    int stock;
    static int unsucc;
    static int succ;

    book_store() {
        title = new char[20];
        author = new char[20];
        publisher = new char[20];
        price = 0;
        stock = 0;
    }

    void getdata() {
        cout << "\nEnter Book Title :";
        cin >> title;
        cout << "\nEnter Book Author :";
        cin >> author;
        cout << "\nEnter Book Publisher :";
        cin >> publisher;
        cout << "\nEnter Book Price :";
        cin >> price;
        cout << "\nEnter Total No. Copies :";
        cin >> stock;
    }

    void display() {
        cout << title << "\t\t" << author << "\t\t" << publisher << "\t\t" << price << "\t\t" << stock << "\n";
    }

    static void successfull() {
        succ++;
    }

    static void unsuccessfull() {
        unsucc++;
    }

    // Member function to update book details
    void updateDetails() {
        int choice;
        cout << "\nSelect the detail to update:\n";
        cout << "1. Name\n";
        cout << "2. Author\n";
        cout << "3. Publisher\n";
        cout << "4. Price\n";
        cout << "5. Number of Copies\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter new name: ";
            cin >> title;
            break;
        case 2:
            cout << "Enter new author: ";
            cin >> author;
            break;
        case 3:
            cout << "Enter new publisher: ";
            cin >> publisher;
            break;
        case 4:
            cout << "Enter new price: ";
            cin >> price;
            break;
        case 5:
            cout << "Enter new number of copies: ";
            cin >> stock;
            break;
        default:
            cout << "Invalid choice!";
            break;
        }
    }
};

int book_store::succ;
int book_store::unsucc;

int main() {
    int i = 0, n = 0, opt, copies;
    float new_price;
    char ch, book[20];
    book_store b[20];

    do {
        cout << "\n1.Enter Data\n2.Display Data\n3.Search Data\n4.Buy Book\n5.Transaction Details\n6.Update Details\n7.Exit\n";
        cout << "\nEnter Your Choice :";
        cin >> opt;

        switch (opt) {
        case 1:
            do {
                b[n].getdata();
                n++;
                cout << "\nWant to enter another entry(y/n) :";
                cin >> ch;
            } while (ch == 'y');
            break;
        case 2:
            cout << "\nName\t\tAuthor\t\tPublisher\t\tPrice\t\tStock\n";
            cout << "---------------------------------------------\n";
            for (i = 0; i < n; i++) {
                b[i].display();
            }
            break;
        case 3:
            cout << "Enter Book Name to be Search For :";
            cin >> book;
            for (i = 0; i < n; i++) {
                if (strcmp(b[i].title, book) == 0) {
                    cout << "\nBook Found!\n";
                    b[i].display();
                    break;
                }
            }
            if (i == n) {
                cout << "\nBook Not Found!\n";
            }
            break;
        case 4:
            cout << "\nWhich Book You Want to Buy :";
            cin >> book;
            for (i = 0; i < n; i++) {
                if (strcmp(b[i].title, book) == 0) {
                    cout << "\nHow Many Copies You Want to Buy :";
                    cin >> copies;
                    if (copies > b[i].stock) {
                        cout << "\nTransaction Unsuccessfull!\n";
                        book_store::unsuccessfull();
                    }
                    else {
                        cout << "Total Price to be paid Rs." << copies * b[i].price << "\n";
                        b[i].stock = b[i].stock - copies;
                        book_store::successfull();
                    }
                    break;
                }
            }
            break;
        case 5:
            cout << "\nTransaction Details:\n";
            cout << "\nTotal Transaction: " << book_store::succ + book_store::unsucc;
            cout << "\nSuccessfull Transaction :" << book_store::succ;
            cout << "\nUnsuccessfull Transaction: " << book_store::unsucc << "\n";
            break;
        case 6:
            cout << "Enter Book Name to Update Details :";
            cin >> book;
            for (i = 0; i < n; i++) {
                if (strcmp(b[i].title, book) == 0) {
                    b[i].updateDetails();
                    cout << "\nDetails Updated!\n";
                    break;
                }
            }
            if (i == n) {
                cout << "\nBook Not Found!\n";
            }
            break;
        case 7:
            exit(0);
            break;
        default:
            cout << "\nEnter Valid Choice!";
            break;
        }
    } while (opt != 8);
    return 0;
}
