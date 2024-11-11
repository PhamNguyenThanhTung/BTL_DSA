#include <bits/stdc++.h>
#ifndef BOOK_CPP
#define BOOK_CPP
using namespace std;

class Book
{
private:
    string type; //loại sách 
    string code; //mã sách
    string title; //tên sách
    string author; //tác giả
    int year; //năm xuất bản
    string language; //ngôn ngữ
    double weight; //trọng lượng
    string size; //kích thước
    string packaging; //bao bì
    int pages; //số trang
    int stock; //số lượng tồn
    int sold; //số lượng bán
    double price; //giá tiền
    double discount; //giá khuyến mãi
    string description; //mô tả

public:
    Book()
    {
        type = "";
        code = "";
        title = "";
        author = "";
        year = 0;
        language = "";
        weight = 0;
        size = "";
        packaging = "";
        pages = 0;
        stock = 0;
        sold = 0;
        price = 0;
        discount = 0;
        description = "";
    };
    friend istream &operator>>(istream &is, Book &b)
    {
        
        cout << "Loai sach: ";
        is.ignore();
        getline(is, b.type);
        cout << "Ma sach: ";
        getline(is, b.code);
        cout << "Ten sach: ";
        getline(is, b.title);
        cout << "Tac gia: ";
        getline(is, b.author);
        cout << "Nam xuat ban: ";
        is >> b.year;
        is.ignore();
        cout << "Ngon ngu: ";
        getline(is, b.language);
        cout << "Trong luong: ";
        is >> b.weight;
        is.ignore();
        cout << "Kich thuoc: ";
        getline(is, b.size);
        cout << "Bao bi: ";
        getline(is, b.packaging);
        cout << "So trang: ";
        is >> b.pages;
        is.ignore();
        cout << "So hang ton: ";
        is >> b.stock;
        is.ignore();
        cout << "So luong ban: ";
        is >> b.sold;
        is.ignore();
        cout << "Gia tien: ";
        is >> b.price;
        is.ignore();
        cout << "Gia khuyen mai: ";
        is >> b.discount;
        is.ignore();
        cout << "Mo ta: ";
        getline(is, b.description);
        return is;
    };
    friend ostream &operator<<(ostream &os, const Book &b)
    {
        cout << "******************************" << endl;
        os << "Loai sach: " << b.type << endl;
        os << "Ma sach: " << b.code << endl;
        os << "Ten sach: " << b.title << endl;
        os << "Tac gia: " << b.author << endl;
        os << "Nam xuat ban: " << b.year << endl;
        os << "Ngon ngu: " << b.language << endl;
        os << "Trong luong: " << b.weight << endl;
        os << "Size: " << b.size << endl;
        os << "Bao bi: " << b.packaging << endl;
        os << "So trang: " << b.pages << endl;
        os << "So hang ton: " << b.stock << endl;
        os << "So luong ban: " << b.sold << endl;
        os << "Gia tien: " << b.price << endl;
        os << "Gia khuyen mai: " << b.discount << endl;
        os << "Mo ta: " << b.description << endl;
        cout << "******************************" << endl;
        return os;
    };
    
    string getCode()
    {
        return code;
    };
    string getTitle()
    {
        return title;
    };
    string getName()
    {
        return title + " " + type + " " + code + " " + author;
    }
    string getType()
    {
        return type;
    }

    void setCode(string t)
    {
        code = t;
    }
    string getAuthor()
    {
        return author;
    }
    int getYear()
    {
        return year;
    }
    string getLanguage()
    {
        return language;
    }
    double getWeight()
    {
        return weight;
    }
    string getSize()
    {
        return size;
    }
    string getPackaging()
    {
        return packaging;
    }
    int getPages()
    {
        return pages;
    }
    int getStock()
    {
        return stock;
    }
    int getSold()
    {
        return sold;
    }
    double getPrice()
    {
        return price;
    }
    double getDiscount()
    {
        return discount;
    }
    string getDescription()
    {
        return description;
    }
    void setTitle(string t)
    {
        title = t;
    }
    void setType(string t)
    {
        type = t;
    }
    void setAuthor(string t)
    {
        author = t;
    }
    void setYear(int t)
    {
        year = t;
    }
    void setLanguage(string t)
    {
        language = t;
    }
    void setWeight(double t)
    {
        weight = t;
    }
    void setSize(string t)
    {
        size = t;
    }
    void setPackaging(string t)
    {
        packaging = t;
    }
    void setPages(int t)
    {
        pages = t;
    }
    void setStock(int t)
    {
        stock = t;
    }
    void setSold(int t)
    {
        sold = t;
    }
    void setPrice(double t)
    {
        price = t;
    }
    void setDiscount(double t)
    {
        discount = t;
    }
    void setDescription(string t)
    {
        description = t;
    }


    bool operator<(const Book& other) const {
       
        return this->sold < other.sold;
    }
};
#endif
