#include <iostream>
using namespace std;
typedef struct nodesach* Nodesachptr;
//Tạo cấu trúc sách
struct SACH
{
	char masach[10];
	char tensach[50];
	char theloai[50];
	char nxb[50];
	char tacgia[50];
};
//Nhập vào thông tin 1 quyển sách
void nhap_s(SACH &s)
{
	cout << "\nNhap ma sach\n";
	cin >> s.masach;
	cout << "\n Nhap ten sach\n";
	cin >> s.tensach;
	cout << "\n Nhap the loai\n";
	cin >> s.theloai;
	cout << "\n Nhap nha xuat ban\n";
	cin >> s.nxb;
	cout << "\n Nhap tac gia\n";
	cin >> s.tacgia;
}
//Xuất thông tin 1 quyển sách
void xuat_s(SACH s)
{
	cout << "_Ma sach: " << s.masach << "\n";
	cout << "_Ten sach: " << s.tensach << "\n";
	cout << "_The loai: " << s.theloai << "\n";
	cout << "_Nha xuat ban: " << s.nxb << "\n";
	cout << "_Tac gia: " << s.tacgia << "\n";
}
//Tạo cấu trúc danh sách liên kết đơn chứa danh sách quyển sách
struct nodesach
{
	SACH data;
	Nodesachptr link;
};
//Khởi tạo ds liên kết rỗng
void init_s(Nodesachptr& plist) 
{
	plist = NULL;
}
//Tạo một node có dữ liệu là thông tin 1 quyển sách
Nodesachptr taonode_s(SACH s)
{
	Nodesachptr n;
	n = new nodesach;
	n->data = s;
	n->link=NULL;
	return n;
}
//Thêm đầu 
void themdau(Nodesachptr & plist, SACH s)
{
	Nodesachptr n = taonode_s(s);
	n->link = plist;
	plist = n;
}
//Thêm cuối
void themcuoi(Nodesachptr& plist, SACH s)
{
	Nodesachptr n = taonode_s(s);
	Nodesachptr p = plist;
	if (plist == NULL)
	{
		themdau(plist, s);
	}
	else
	{
		if (p->link == NULL) {
			p->link = n;
		}
		else {
			while (p->link != NULL)
			{
				p = p->link;
			}
			p->link = n;
		}
	}
}
//Nhập sách vào danh sách
void nhapds_s(Nodesachptr& plist)
{
	int chon=1;
	cout << "Nhap sach vao danh sach";
	do
	{
		SACH s;
		nhap_s(s);
		themcuoi(plist, s);
		cout << "\n1. Tiep tuc nhap SACH\n";
		cout << "\n0. Ngung nhap SACH\n";
		cin >> chon;
	} while (chon);
}
//Xuất danh sách các quyển sách
void xuatds_s(Nodesachptr plist)
{
	Nodesachptr n = plist;
	if (plist == NULL) {
		cout << "\n Khong co sach";
	}
	else
	{
		while (n->link != NULL)
		{
			xuat_s(n->data);
			n = n->link;
		}
		xuat_s(n->data);
	}
}


//Kiểm tra mã sách
void ktramasach(Nodesachptr plist, SACH s) {

}

void nhap_s(SACH &s);
void xuat_s(SACH s);
void init_s(Nodesachptr& plist);
Nodesachptr taonode_s(SACH s);
void themdau(Nodesachptr& plist, SACH s);
void themcuoi(Nodesachptr& plist, SACH s);
void nhapds_s(Nodesachptr& plist);
void xuatds_s(Nodesachptr plist);

void main() {
	Nodesachptr sach;
	init_s(sach);
	nhapds_s(sach);
	xuatds_s(sach);
	system("pause");
}













