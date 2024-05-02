#include <iostream>
#include <string.h>
using namespace std;
struct Ngay
{
	int x,y,z;
};
struct Sinhvien
{
	char maSV[9];
	char hoTen[50]; 
	int gioiTinh; 
	Ngay ngaySinh; 
	char diaChi[100]; 
	char lop[12]; 
	char khoa[7];
};
struct Node
{   Sinhvien data;
	Node* link;
};
Node* creatNode(Sinhvien a)
{   
    Node* t = new Node;
    t->data = a;
    t->link=NULL;
	return t;
}
struct list 
{
	Node* first;
	Node* last;
};
void creatlist(list& A)
{
	A.first = NULL;
	A.last = NULL;
}
void themdau(list& A, Node* N)
{
	if (A.first == NULL)
	{
		A.first = N;
		A.last = N;
	}
	else
	{   
		N->link= A.first;		
		A.first= N;
	}
	
}
void thembatky(list& A, Node* N)
{
	Node* b;
	b = A.first;
	while(b->link != NULL)
	{   
		if (strcmp(b->link->data.maSV, N->data.maSV) >= 0) break;
		b = b->link;
	}
	if (b==A.first & A.first->data.maSV== N->data.maSV) 
	{
		N->link= b;
		A.first = N;	
	}
	else
	{
		N->link= b->link;
		b->link = N;
	}
}
void xuatSV(Sinhvien a)
	{
	cout<<"Ma sinh vien: "<<a.maSV<<endl;
	cout<<"Ho ten: "<<a.hoTen<<endl;
	cout<<"Gioi tinh(0 la nam va 1 la nu): "<<a.gioiTinh<<endl;
	cout<<"Ngay, thang, nam sinh: "<<a.ngaySinh.x<<"/"<<a.ngaySinh.y<<"/"<<a.ngaySinh.z<<endl;
	cout<<"Dia chi: "<<a.diaChi<<endl;
	cout<<"Lop: "<<a.lop<<endl;
	cout<<"Khoa: "<<a.khoa<<endl;
	}
void xuat(list A)
{
	Node* t;
	int h=1;
	t = A.first;
	while(t != NULL)
	{   
	    cout<<"STT: "<<h<<endl;
		xuatSV(t->data);
		t = t->link;
		h = h + 1;
	}
}
Sinhvien nhapSV()
	{
	Sinhvien a;
	cout<<"Nhap ma sinh vien: ";
	cin.getline(a.maSV,9);
	cout<<"Nhap ho ten: ";
	cin.getline(a.hoTen,50);
	cout<<"Nhap gioi tinh (0 la nam va 1 la nu): ";
	cin>>a.gioiTinh;
	cout<<"Nhap ngay, thang, nam sinh: ";
	cin>>a.ngaySinh.x>>a.ngaySinh.y>>a.ngaySinh.z;
	cin.ignore();
	cout<<"Nhap dia chi: ";
	cin.getline(a.diaChi,100);
	cout<<"Nhap lop: ";
	cin.getline(a.lop,12);
	cout<<"Nhap khoa: ";
	cin.getline(a.khoa,7);
	return a;
	}
void sapxep(list& a)
{   
    Node* i; Node* j;
	Sinhvien t;
	for(i = a.first;i != NULL;i = i->link)
	for(j = i->link;j!= NULL;j = j->link)
	if (strcmp(i->data.maSV,j->data.maSV) > 0)
	{
		t = i->data;
		i->data=j->data;
		j->data=t;
	}
}
void sapxep1(list& a)
{   
    Node* i; Node* j;
	Sinhvien t;
	for(i = a.first;i != NULL;i = i->link)
	for(j = i->link;j!= NULL;j = j->link)
	if (i->data.ngaySinh.x > j->data.ngaySinh.x)
	{
		t = i->data;
		i->data=j->data;
		j->data=t;
	}
}
void xuat1(list A)
{
	Node* t;
	int h=1,g = 0,k=0;
	t = A.first;
	while(t != NULL)
	{ 
	  if(t->link == NULL && g == 1)  
		{
		cout<<"STT: "<<h<<endl;
		h = h + 1;
		xuatSV(t->data);
		break;
		}
	else
	{
	  if(t->link==NULL) break;
	  if (t->data.ngaySinh.x == t->link->data.ngaySinh.x)
	  	{
		    cout<<"STT: "<<h<<endl;
		    h = h + 1;
			xuatSV(t->data);
			k = 1;
			g = 1;
		}	
		else 
		if (g == 1)	
		{
		cout<<"STT: "<<h<<endl;
		xuatSV(t->data);
		h = h + 1;
		g = 0;
		}
	t = t->link;
	}
	}
	if (k == 0) cout<<"khong tim thay sinh vien"<<endl;
}
void xoaNode(list& a)
{
	Node* i;
	int t = 0;
	while(a.first->data.ngaySinh.x== a.first->link->data.ngaySinh.x)
	{
		a.first = a.first->link;
		t = 1;
	}
	if (t == 1) a.first = a.first->link;
	i = a.first;
	t = 0;
    while (i->link != NULL) 
    {
    while (i->link->data.ngaySinh.x == i->link->link->data.ngaySinh.x && i->link->link != a.last)
	{   
		i->link = i->link->link;
		t = 1;
	} 
	if (i->link->link == a.last && a.last->data.ngaySinh.x == i->link->data.ngaySinh.x) 
	{  
		a.last = i;
		i->link = NULL;
		break;
	} 
	if ( t == 1) i->link = i->link->link;
	if (i->link->link == a.last && a.last->data.ngaySinh.x == i->link->data.ngaySinh.x) 
	{  
		a.last = i;
		i->link = NULL;
	} 
	if (i->link->link == a.last) break;
	i = i->link;
    }
}
int main()
{   
    struct Sinhvien a;
    string t;
	list A;
	creatlist(A);
	t = "N";
	cout<<"Nhap thong tin sinh vien: "<<endl;
	while(t != "Y")
	{
		themdau(A,creatNode(nhapSV()));
		cout<<"Nhap N neu muon them sinh vien, Y neu ko muon them sinh vien"<<endl;
		getline(cin,t);
	}
	sapxep(A);
	xuat(A);
	cout<<"Nhap them sinh vien: "<<endl;thembatky(A,creatNode(nhapSV()));
	cout<<"Danh sach sau khi them: "<<endl;
	xuat(A);
	cout<<"Sinh vien co cung ngay sinh: "<<endl;
    sapxep1(A); xuat1(A);
    cout<<"Danh sach sau khi xoa: "<<endl;
    xoaNode(A); xuat(A);
}
