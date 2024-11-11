// 1. Xây dựng một lớp quản lý một dãy số, xây dụng cấu trúc dữ liệu danh sách liên kết đơn để
// lưu trữ. Với các phương thức:
// a. Tạo danh sách số, quá trình nhập sẽ dừng lại khi nhập dấu “#”.
// b. Thêm một phần tử vào danh sách, vị trí thêm vào do người dùng chọn.
// c. Nhập vào một số k (k≠0), đếm xem trong dãy có bao nhiêu số có giá trị = k?
// d. Kiểm tra xem trong danh sách có 3 số chẵn dương đứng cạnh nhau hay không?
// Nếu có hãy in ra vị trí của các số này.
// e. Sắp xếp danh sách theo thứ tự tăng dần.
// f. Xóa tất cả các số nguyên tố trong danh sách.
// g. Xóa tất cả các phần tử có giá trị trùng nhau trong danh sách, chỉ giữ lại 1 số.
// 2. Xây dựng ham main để kiểm tra các chức năng của lớp.
#include<iostream>
#include<cmath>
#include<conio.h>
#include"List.cpp"
using namespace std;
int menu(){
	cout<<"1.Tao danh sach.\n";
	cout<<"2.Them 1 phan tu vao danh sach.\n";
	cout<<"3.Nhap k, dem so lan k xuat hien trong danh sach.\n";
	cout<<"4.Ktra danh sach co 3 so chan duong dung canh nhau.\n";
	cout<<"5.Sap xep danh sach theo thu tu tang dan.\n";
	cout<<"6.Xoa cac so nguyen to trg danh sach.\n";
	cout<<"7.Xoa cac so trung nhau trong danh sach.\n";
	cout<<"8.Xuat danh sach.\n";
	int n;
	cout<<"Chon cac chuc nang tren:";
	cin>>n;
	return n;
}
int main(){
	s_list<int> L;
	int lc;
	do{
		system("cls");
		lc=menu();
		system("cls");
		switch(lc){
			case 1:
				cout<<"Nhap danh sach so(nhap # de dung):\n";
				while(true) {
			        string input;
			        cin>>input;
			        if (input == "#") {
			            break;
			        }
			        else{
			        	int so= stoi(input);		// chuyen chuoi thanh so
			        	L.push_back(so);
					}
			    }
			    break;
			case 2:
				int pos, x;
				cout<<"Nhap so can chen:";
				cin>>x;
				cout<<"\nNhap vi tri can chen:";
				cin>>pos;
				L.add_elem(x,pos);
				break;
			case 3:
				int k;
				cout<<"Nhap so can tim:";
				cin>>k;
				cout<<"So lan "<<k<<" xuat hien:"<<L.cout_elem(k);
				break;
			case 4:
				L.search_x();
				break;
			case 5:
				L.sort();
				for (s_list<int>:: iterator it = L.begin(); it!= L.end(); it++){
					cout<<*it<<" ";
				}
				cout << "\nDanh sach da duoc sap xep.\n";
				break;
			case 6:
				L.removePrimes();
				for (s_list<int>:: iterator it = L.begin(); it!= L.end(); it++){
					cout<<*it<<" ";
				}
				cout << "\nDa xoa cac so nguyen to trong danh sach.\n";
				break;
			case 7:
				L.removeDuplicates();
				for (s_list<int>:: iterator it = L.begin(); it!= L.end(); it++){
					cout<<*it<<" ";
				}
				cout << "\nDa xoa cac phan tu trung lap trong danh sach.\n";
				break;
			case 8:
				for (s_list<int>:: iterator it = L.begin(); it!= L.end(); it++){
					cout<<*it<<" ";
				}
				break;
		}
		getch();
	}while(lc!=9);
}
