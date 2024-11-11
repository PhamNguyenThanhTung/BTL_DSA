#include <bits/stdc++.h>
#include "book.cpp"

#ifndef BOOKLIST_CPP
#define BOOKLIST_CPP
using namespace std;

class BookList
{
private:
    vector<Book> books;

public:
    void loadFromFile(const string &filename)
    {
        ifstream file(filename);
        if (file.is_open())
        {
            Book book;
            while (file >> book)
            {
                books.push_back(book);
                cout << endl;
            }
            file.close();
        }
        else
        {
            cout << "khong the mo de doc: " << filename << endl;
        }
    }

    void saveToFile(const string &filename)
    {
        ofstream file(filename, ios::trunc);
        if (file.is_open())
        {
            for (auto book = books.begin(); book != books.end(); ++book)
            {
                file <<"\n"<< book->getType() << '\n'
                     << book->getCode() << '\n'
                     << book->getTitle() << '\n'
                     << book->getAuthor() << '\n'
                     << book->getYear() << '\n'
                     << book->getLanguage() << '\n'
                     << book->getWeight() << '\n'
                     << book->getSize() << '\n'
                     << book->getPackaging() << '\n'
                     << book->getPages() << '\n'
                     << book->getStock() << '\n'
                     << book->getSold() << '\n'
                     << book->getPrice() << '\n'
                     << book->getDiscount() << '\n'
                     << book->getDescription() << "\n";
            }
            file.close();
        }
        else
        {
            cout << "Khong the mo file đe ghi: " << filename << endl;
        }
    }

    void printAllBooks()
    {
        if (books.empty())
        {
            cout << "khong co sach nao." << endl;
        }
        else
        {
            for (auto book : books)
            {
                cout << book << endl;
            }
        }
    }
    bool isCodeUnique(const string &code)
    {
        for (auto it = books.begin(); it != books.end(); ++it)
        {
            if (it->getCode() == code)
            {
                return false;
            }
        }
        return true;
    }
    void addBook(Book book)
    {
        while (!isCodeUnique(book.getCode()))
        {
            cout << "Ma sach da ton tai. Vui long nhap ma sach khac: ";
            string newCode;
            cin >> newCode;
            book.setCode(newCode);
        }
        books.push_back(book);
    }
    vector<Book> searchBooks(string &keyword)
    {
        vector<Book> foundBooks;
        for (auto it = books.begin(); it != books.end(); ++it)
        {
            if (it->getName().find(keyword) != string::npos)
            {
                foundBooks.push_back(*it);
            }
        }
        return foundBooks;
    }
    void editBook(string &code)
    {
        for (auto it = books.begin(); it != books.end(); ++it)
        {
            if (it->getCode() == code)
            {
                cout << "Sach can sua: " << *it << endl;
                cout << "Chon thong tin can sua (1. ma sach, 2. tac gia, 3. ten sach, 4. nam xuat ban, 5. ngon ngu, 6. trong luong, 7. kich thuoc, 8. bao bi, 9. so trang, 10. so hang ton, 11. so luong ban, 12. gia tien, 13. gia khuyen mai, 14. mo ta): ";
                int choice;
                cin >> choice;
                string temp;
                int tempInt;
                double tempDouble;
                switch (choice)
                {
                case 1:
                    do
                    {
                        cout << "Nhap ma sach moi: ";
                        cin.ignore();
                        getline(cin, temp);
                        if (!isCodeUnique(temp))
                        {
                            cout << "Ma sach da ton tai. Vui long nhap ma sach khac." << endl;
                        }
                    } while (!isCodeUnique(temp));
                    it->setCode(temp);
                    break;
                case 2:
                    cout << "Nhap tac gia moi: ";
                    cin.ignore();
                    getline(cin, temp);
                    it->setAuthor(temp);
                    break;
                case 3:
                    cout << "Nhap ten sach moi: ";
                    cin.ignore();
                    getline(cin, temp);
                    it->setTitle(temp);
                    break;
                case 4:
                    cout << "Nhap nam xuat ban moi: ";
                    cin >> tempInt;
                    it->setYear(tempInt);
                    break;
                case 5:
                    cout << "Nhap ngon ngu moi: ";
                    cin.ignore();
                    getline(cin, temp);
                    it->setLanguage(temp);
                    break;
                case 6:
                    cout << "Nhap trong luong moi: ";
                    cin >> tempDouble;
                    it->setWeight(tempDouble);
                    break;
                case 7:
                    cout << "Nhap kich thuoc moi: ";
                    cin.ignore();
                    getline(cin, temp);
                    it->setSize(temp);
                    break;
                case 8:
                    cout << "Nhap bao bi moi: ";
                    cin.ignore();
                    getline(cin, temp);
                    it->setPackaging(temp);
                    break;
                case 9:
                    cout << "Nhap so trang moi: ";
                    cin >> tempInt;
                    it->setPages(tempInt);
                    break;
                case 10:
                    cout << "Nhap so hang ton moi: ";
                    cin >> tempInt;
                    it->setStock(tempInt);
                    break;
                case 11:
                    cout << "Nhap so luong ban moi: ";
                    cin >> tempInt;
                    it->setSold(tempInt);
                    break;
                case 12:
                    cout << "Nhap gia tien moi: ";
                    cin >> tempDouble;
                    it->setPrice(tempDouble);
                    break;
                case 13:
                    cout << "Nhap gia khuyen mai moi: ";
                    cin >> tempDouble;
                    it->setDiscount(tempDouble);
                    break;
                case 14:
                    cout << "Nhap mo ta moi: ";
                    cin.ignore();
                    getline(cin, temp);
                    it->setDescription(temp);
                    break;
                default:
                    cout << "Lua chon khong hop le." << endl;
                }
                cout << "Sach da duoc sua thanh cong." << endl;
                break;
            }
        }
        
    }
    void removeBook(string code)
    {
        for (auto it = books.begin(); it != books.end(); ++it)
        {
            if (it->getCode() == code)
            {
                books.erase(it);
                break;
            }
        }
    }

    void sortBySold()
    {
        sort(books.begin(), books.end(), [](Book a, Book b) {
            return b < a;
        });
    }
    
};
#endif
