#include "booklist.cpp"
#include "book.cpp"
#include <bits/stdc++.h>

using namespace std;

class App
{
private:
    BookList bookList;

public:
    int menu()
    {
        cout << "1.In danh sach.\n";
        cout << "2.Them sach vao danh sach.\n";
        cout << "3.Tim sach.\n";
        cout << "4.Sua thong tin sach.\n";
        cout << "5.Xoa sach.\n";
        cout << "6.Sach ban chay.\n";
        cout << "7.Thoat chuong trinh.\n";
        int n;
        cout << "Chon chuc nang tren:";
        cin >> n;
        return n;
    }
    void app()
    {
        bookList.loadFromFile("book.txt");
        int lc;
        do
        {
            system("cls");
            lc = menu();
            system("cls");
            Book book;
            string keyword;
            string code;
            vector<Book> foundBooks;
            switch (lc)
            {
            case 1:
                cout << "Danh sach:" << endl;
                bookList.printAllBooks();
                system("pause");
                break;
            case 2:
                cout << "Nhap thong tin sach:" << endl;
                cin >> book;
                bookList.addBook(book);
                break;
            case 3:
                cout << "Nhap tu khoa tim kiem: ";
                cin.ignore();
                getline(cin, keyword);
                foundBooks = bookList.searchBooks(keyword);
                for (Book b : foundBooks) {
                    cout << b << endl;
                }
                system("pause");
                break;
            case 4:
                cout << "Nhap ma sach can sua: ";
                cin.ignore();
                getline(cin, code);
                bookList.editBook(code);
                break;
            case 5:
                cout << "Nhap ma sach can xoa: ";
                cin.ignore();
                getline(cin, code);
                bookList.removeBook(code);
                break;
             case 6:
                bookList.sortBySold(); 
                cout << "Danh sach ban chay:" << endl;
                bookList.printAllBooks();
                system("pause");
                break;
            case 7:
                bookList.saveToFile("book.txt");
                exit(0);
                break;
            default:
                cout << "Lua chon khong hop le. Vui long thu lai." << endl;
            }
        } while (lc != 7);
        bookList.saveToFile("book.txt");
    }
};
