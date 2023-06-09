#include <bits/stdc++.h>
#include <conio.h>
#include <mylib.h>

using namespace std;

//may bay
class MayBay{
	private:
		string soHieu;
		string loai;
		int soDay;
		int soDong;
	public:
//ham khoi tao may bay
		MayBay(){}
		MayBay(string soHieu, string loai, int soDay, int soDong){
			MayBay::soHieu = soHieu;
			MayBay::loai = loai;
			MayBay::soDay = soDay;
			MayBay::soDong = soDong;
		}
		
//setter may bay
		void setSoHieu(string soHieu){
			MayBay::soHieu = soHieu;
		}
		void setLoai(string loai){
			MayBay::loai = loai;
		}
		void setSoDay(int soDay){
			MayBay::soDay = soDay;
		}
		void setSoDong(int soDong){
			MayBay::soDong = soDong;
		}
		
//getter may bay
		string getSoHieu(){
			return soHieu;
		}
		string getLoai(){
			return loai;
		}
		int getSoDay(){
			return soDay;
		}
		int getSoDong(){
			return soDong;
		}
		
//nhap may bay
		void nhap(string soHieu){
			MayBay::soHieu = soHieu;
			cout << "Loai may bay: ";
			getline(cin, loai);
			do{
				cout << "So day: ";
				cin >> soDay;
				cout << "So dong: ";
				cin >> soDong;
				cout << "So cho: " << soDay*soDong << endl;
				if(soDay*soDong < 20){
					cout << "So cho phai >= 20. Vui long nhap lai.\n";
					system("cls");
				}
			}while(soDay*soDong < 20);
		}
		
//xuat may bay
		void xuat(){
			cout << soHieu << "\t\t" << loai << "\t\t" << soDay*soDong << endl;
			//soDay*soDong = so cho
		}
};

//danh sach may bay
#define TOIDA_MAYBAY 300

class DanhSachMayBay{
	private:
		int soLuong = 0;
		MayBay *danhSach[TOIDA_MAYBAY];
	public:
		
//ham tim kiem may bay
		int timMayBay(string soHieu){
			for(int i=0; i<soLuong; i++){
				if(soHieu.compare(danhSach[i]->getSoHieu()) == 0){
					return i;
				}
			}
			return -1;
		}
		
//ham xoa may bay
		int xoaMayBay(MayBay mayBay, string &thongBao){
			int tim = timMayBay(mayBay.getSoHieu());
			if(tim == -1){
				thongBao = "\nSo hieu khong ton tai. Vui long nhap lai.\n";
				return 0;
			}
			for(int i=tim; i<soLuong-1; i++){
				*danhSach[i] = *danhSach[i+1];
			}
			delete danhSach[soLuong-1];
			soLuong--;
			return 1;
		}
		
//ham sap xep may bay
		void sapXepMayBay(){
			for(int i=0; i<soLuong-1; i++){
				for(int j=i+1; j<soLuong; j++){
					if(danhSach[i]->getSoHieu().compare(danhSach[j]->getSoHieu()) > 0){
						MayBay *tmp = danhSach[i];
						danhSach[i] = danhSach[j];
						danhSach[j] = tmp;
					}
				}
			}
		}

//a. Cap nhat danh sach cac may bay
//them may bay
		int themMayBay(MayBay mayBay){
			danhSach[soLuong] = new MayBay(mayBay.getSoHieu(), mayBay.getLoai(), mayBay.getSoDay(), mayBay.getSoDong());
			soLuong++;
			return 1;
		}
		void thucHienThemMayBay(){
			MayBay mayBay;
			string soHieuNhap;
			if(soLuong == TOIDA_MAYBAY){
				cout << "Danh sach day. Khong the them.\n";
				return;
			}
			cout << "//NHAP THONG TIN MAY BAY//\n";
			cout << "So hieu may bay: ";
			fflush(stdin);
			getline(cin, soHieuNhap);
			if(timMayBay(soHieuNhap) != -1){
				cout << "\nSo hieu may bay bi trung. Vui long nhap lai.\n";
				return;
			}
			mayBay.nhap(soHieuNhap);
			themMayBay(mayBay);
			cout << "\nThem thanh cong.\n";
		}
		
//xuat may bay
		void xuatDanhSachMayBay(){
			cout << "//DANH SACH MAY BAY//\n";
			cout << "\nSTT\tSO HIEU\t\tLOAI MAY BAY\tSO CHO\n";
			for(int i=0; i<soLuong; i++){
				cout << i+1 << "\t";
				danhSach[i]->xuat();	
			}
		}
		
//thuc hien xoa may bay
		void thucHienXoaMayBay(){
			MayBay mayBay;
			string thongBao;
			string soHieuNhap;
			if(soLuong == 0){
				cout << "Danh sach rong. Khong the xoa.\n";
				return;
			}
			cout << "//XOA MAY BAY//\n";
			cout << "Nhap so hieu may bay can xoa: ";
			fflush(stdin);
			getline(cin, soHieuNhap);
			mayBay.setSoHieu(soHieuNhap);
			if(xoaMayBay(mayBay, thongBao) == 0){
				cout << thongBao << endl;
				return;
			}
			cout << "\nXoa thanh cong.\n";
		}
		
//sua may bay
		int suaMayBay(MayBay mayBay, int viTri){
			*danhSach[viTri] = mayBay;
		}
		
//thuc hien sua may bay
		void thucHienSuaMayBay(){
			MayBay mayBay;
			string soHieuNhap;
			if (soLuong == 0){
				cout << "Danh sach rong. Khong the sua.\n";
				return;
			}
			cout << "//SUA THONG TIN MAY BAY//\n";
			cout << "Nhap so hieu may bay: ";
			fflush(stdin);
			getline(cin, soHieuNhap);
			mayBay.setSoHieu(soHieuNhap);
			int viTri = timMayBay(mayBay.getSoHieu());
			if(viTri == -1){
				cout << "\nMa so khong ton tai. Vui long nhap lai.\n";
				return;
			}
			mayBay.nhap(soHieuNhap);
			suaMayBay(mayBay, viTri);
			cout << "\nSua thanh cong.\n";
		}

//xoa danh sach may bay
		void xoaDanhSach(){
			while(soLuong>0){
				delete danhSach[soLuong];
				soLuong--;
			}
		}
};

void doiKichThuocConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void hopChon(int x, int y, int cao, int rong, int mauChu, string noiDung){
	SetColor(9);
	for(int ix = x; ix <= x+rong; ix++){
		gotoxy(ix, y);
		cout << char(196);
		gotoxy(ix, y+cao);
		cout << char(196);
	}
	for (int iy = y; iy <= y+cao; iy++){
		gotoxy(x, iy);
		cout << char(179);
		gotoxy(x+rong, iy);
		cout << char(179);
	}
	gotoxy(x, y);
	cout << char(218);
	gotoxy(x+rong, y);
	cout << char(191);
	gotoxy(x, y+cao);
	cout << char(192);
	gotoxy(x+rong, y+cao);
	cout << char(217);
	
	SetColor(mauChu);
	gotoxy(x+2, y+1);
	cout << noiDung;
}

void hangMayBay(int x, int y, int cao, int rong){
	for(int ix = x; ix <= rong; ix++){
		for(int iy = y; iy <= cao; iy++){
			SetBGColor(9);
			gotoxy(ix, iy);
			cout << " ";
		}	
	}
	SetColor(15);
	gotoxy(2, 1);
	cout << "47 AIRLINES";
	gotoxy(105, 1);
	cout << "YOUR HAPPINESS IS OUR PRIDE";
	SetBGColor(0);
}

void danhSachChucNangMayBay(string &noiDung, int soLuong){
	switch(soLuong){
		case 0:{
			noiDung = "Them may bay vao danh sach";
			break;
		}
		case 1:{
			noiDung = "Xuat danh sach may bay";
			break;
		}
		case 2:{
			noiDung = "Xoa may bay";
			break;
		}
		case 3:{
			noiDung = "Sua thong tin may bay";
			break;
		}
	}
	soLuong++;
}

void nHopChonMayBay(int x, int y, int cao, int rong, int mauChu, int sl){
	string noiDung;
	for(int i = 0; i < sl; i++){
		danhSachChucNangMayBay(noiDung, i);
		hopChon(x, y+(i*cao), cao, rong, mauChu, noiDung);
		if(i!=0){
			SetColor(9);
			gotoxy(x, y+(i*cao));
			cout << char(195);
			gotoxy(x+rong, y+(i*cao));
			cout << char(180);
			gotoxy(x, y+cao+(i*cao));
			cout << char(192);
		}
	}
}

void menuMayBay(){
	nHopChonMayBay(50, 10, 2, 30, 14, 4);
}

void danhSachChucNangChinh(string &noiDung, int soLuong){
	switch(soLuong){
		case 0:{
			noiDung = "Quan ly may bay";
			break;
		}
		case 1:{
			noiDung = "Quan ly chuyen bay";
			break;
		}
	}
	soLuong++;
}

void hopChonChinh(int x, int y, int cao, int rong, int mauChu, string noiDung){
	SetColor(9);
	for(int ix = x; ix <= x+rong; ix++){
	gotoxy(ix, y);
	cout << char(196);
	gotoxy(ix, y+cao);
	cout << char(196);
	}	
	SetColor(0);
	for(int iy = y; iy <= y+cao; iy++){
		gotoxy(x, iy);
		cout << char(179);
		gotoxy(x+rong, iy);
		cout << char(179);
	}
	
	SetColor(mauChu);
	gotoxy(x+24, y+1);
	cout << noiDung;
}

void nHopChonChinh(int x, int y, int cao, int rong, int mauChu, int sl){
	string noiDung;
	for(int i = 0; i < sl; i++){
		danhSachChucNangChinh(noiDung, i);
		hopChonChinh(x+(i*rong), y, cao, rong, mauChu, noiDung);
		if(i!=0){
			SetColor(9);
			for(int iy = y; iy <= y+cao; iy++){
				gotoxy(x+(i*rong), iy);
				cout << char(179);
			}
			gotoxy(x+rong, y);
			cout << char(194);
			gotoxy(x+rong, y+cao);
			cout << char(193);
		}
	}
}

void menuChinh(){
	doiKichThuocConsole(1000, 600);
	hangMayBay(0, 0, 2, 133);
	nHopChonChinh(0, 3, 2, 66, 14, 2);
	gotoxy(48, 14);
	cout << "Chon";
	gotoxy(86, 14);
	cout << "Thoat";
	hopChon(38, 13, 2, 8, 9, "ENTER");
	hopChon(78, 13, 2, 6, 9, "ESC");
	cout << endl;
}

//void chonChucNangMayBay(){
//	DanhSachMayBay ds;
//	while(true){
//		//danhSachChucNangMayBay();
//		char luaChon = getch();
//		system("cls");
//		switch(luaChon){
//			case '1':{
//				ds.thucHienThemMayBay();
//				ds.sapXepMayBay();
//				break;
//			}
//			case '2':{
//				ds.xuatDanhSachMayBay();
//				break;
//			}
//			case '3':{
//				ds.thucHienXoaMayBay();
//				break;
//			}
//			case '4':{
//				ds.thucHienSuaMayBay();
//				break;
//			}
//			case '0':{
//				cout << "Chuong trinh ket thuc.\n";
//				ds.xoaDanhSach();
//				return;
//			}
//		}
//		cout << "\n-----------------------------\n";
//		cout << "Bam phim bat ky de tiep tuc\n";
//		getch();
//		system("cls");
//	}
//	
//}

int main(){
	menuChinh();
	return 0;
}
