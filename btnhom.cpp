#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

class ngaysinh {
protected:
    int Ngay, Thang, Nam;
public:
    ngaysinh();
    ngaysinh(int ngay, int thang, int nam);
    ~ngaysinh();
    void nhap1();
    void xuat1();
    bool kiemtra();
    int getNgay();
    int getThang();
    int getNam();
};
ngaysinh::ngaysinh() {
    this->Ngay = 0;
    this->Thang = 0;
    this->Nam = 0;
}
ngaysinh::ngaysinh(int ngay, int thang, int nam) {
    this->Ngay = ngay;
    this->Thang = thang;
    this->Nam = nam;
}
ngaysinh::~ngaysinh() {}
void ngaysinh::nhap1() {
    cout << "\nNhap Ngay, Thang, Nam Sinh: " << endl;
    do {
        cout << "Ngay: ";
        cin >> Ngay;
        cout << "Thang: ";
        cin >> Thang;
        if (kiemtra() == false) {
            cout << endl << "Ngay Thang Khong Hop Le !! Nhap Lai Ngay Thang!!" << endl;
            cout << "\nNgay: ";
            cin >> Ngay;
            cout << endl << "Thang: ";
            cin >> Thang;
        }
    } while (kiemtra() == false);
    do {
        cout << "Nam: ";
        cin >> Nam;
        if (Nam > 2015 || Nam <= 2000) {
            cout << "Nhap lai nam sinh!!";
            cout << endl << "Nam: ";
            cin >> Nam;
        }
    } while (Nam > 2015 || Nam <= 1999);
}
bool ngaysinh::kiemtra() {
    bool kiemtra = true;
    if (Thang < 0 || Thang > 12) {
        kiemtra = false;
    }
    else {
        switch (Thang) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (Ngay < 1 || Ngay > 31) {
                kiemtra = false;
            }
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            if (Ngay < 1 || Ngay > 30) {
                kiemtra = false;
            }
            break;
        case 2:
            if ((Nam % 4 == 0 && Nam % 100 != 0) || (Nam % 400 == 0)) {
                if (Ngay < 1 || Ngay > 29) {
                    kiemtra = false;
                }
            }
            else {
                if (Ngay < 1 || Ngay > 28) {
                    kiemtra = false;
                }
            }
            break;
        }
    }
    return kiemtra;
}

int ngaysinh::getNgay() {
    return Ngay;
}
int ngaysinh::getThang() {
    return Thang;
}
int ngaysinh::getNam() {
    return Nam;
}
class nguoi : public ngaysinh {
protected:
    string hoten, quequan;
public:
    nguoi();
    nguoi(string hoten, string quequan);
    ~nguoi();
    void nhap2();
    string getquequan();
    string getten();
};
nguoi::nguoi() {
    this->quequan = "";
    this->hoten = "";
}
nguoi::nguoi(string hoten, string quequan) : ngaysinh() {
    this->quequan = quequan;
    this->hoten = hoten;
}
nguoi::~nguoi() {}
void nguoi::nhap2() {
    cin.ignore();
    cout << "Nhap ho va ten: ";
    getline(cin, hoten);
    cout << "Nhap que quan: ";
    getline(cin, quequan);
    ngaysinh::nhap1();
}
string nguoi::getquequan() {
    return quequan;
}
string nguoi::getten() {
    return hoten;
}
class diem : public nguoi {
protected:
    float toan, van, anh, ly, sinh, su, dia, dtb;
public:
    diem();
    diem(float toan, float van, float anh, float ly, float sinh, float su, float dia);
    ~diem();
    void nhap3();
    float gettoan();
    float getvan();
    float getanh();
    float getly();
    float getsinh();
    float getsu();
    float getdia();
    float getdtb();
};
diem::diem() : nguoi() {
    toan = 0;
    van = 0;
    anh = 0;
    ly = 0;
    sinh = 0;
    su = 0;
    dia = 0;
    dtb = 0;
}
diem::diem(float toan, float van, float anh, float ly, float sinh, float su, float dia) : nguoi() {
    this->toan = toan;
    this->van = van;
    this->anh = anh;
    this->ly = ly;
    this->sinh = sinh;
    this->su = su;
    this->dia = dia;
}
diem::~diem() {
    this->toan = 0;
    this->van = 0;
    this->anh = 0;
    this->ly = 0;
    this->sinh = 0;
    this->su = 0;
    this->dia = 0;
    this->dtb = 0;
}
float diem::gettoan() {
    return toan;
}
float diem::getvan() {
    return van;
}
float diem::getanh() {
    return anh;
}
float diem::getly() {
    return ly;
}
float diem::getsinh() {
    return sinh;
}
float diem::getsu() {
    return su;
}
float diem::getdia() {
    return dia;
}
float diem::getdtb() {
    return dtb;
}
void diem::nhap3() {
    nguoi::nhap2();
    cout << setw(50) << "\nNhap Diem Cua Hoc Sinh : ";
    do {
        cout << "\nNhap Diem Toan: ";
        cin >> toan;
        if (toan < 0.0 || toan > 10.0) {
            cout << "Nhap Lai Diem Toan: ";
            cin >> toan;
        }
    } while (toan < 0.0 || toan > 10.0);
	do {
        cout<<"Nhap Diem van: ";
	     cin >>  van;
        if ( toan < 0.0 ||  van >10.0){
            cout <<"Nhap Lai Diem van: ";
             cin >>  van;
        }
    }while( van < 0.0 ||  van >10.0);
    do {
        cout<<"Nhap Diem anh: ";
	     cin >>  anh;
        if ( van < 0.0 ||  anh >10.0){
            cout <<"Nhap Lai Diem anh: ";
             cin >>  anh;
        }
    }while( anh < 0.0 ||  anh >10.0);
    do{
    	cout<<"nhap Diem ly: ";
    	cin>>ly;
    	if(anh< 0.0 || ly >10.0){
    		cout <<"nhap lai Diem ly: ";
    		cin>>ly;
		}
	}while( ly < 0.0 ||  ly >10.0);
    do{
    	cout<<"nhap Diem sinh: ";
    	cin>>sinh;
    	if(ly< 0.0 || sinh >10.0){
    		cout <<"nhap lai Diem sinh: ";
    		cin>>sinh;
		}
	}while( sinh < 0.0 ||  sinh >10.0);
    do{
    	cout<<"nhap Diem su: ";
    	cin>>su;
    	if(sinh< 0.0 || su >10.0){
    		cout <<"nhap lai Diem su: ";
    		cin>>su;
    	}
	}while( su < 0.0 ||  su >10.0);
    do{
    	cout<<"nhap Diem dia: ";
    	cin>>dia;
    	if(su< 0.0 || dia >10.0){
    		cout <<"nhap lai Diem su: ";
    		cin>>dia;
    	}
    }while( dia < 0.0 ||  dia >10.0);
     	dtb=(toan+van+anh+ly+sinh+su+dia)/7;
}
class hocsinh : public diem {
private:
    string lop, msv;
    int stt;
public:
    hocsinh();
    hocsinh(string lop, string msv);
    ~hocsinh();
    void nhap4();
    void xuat3();
    void setstt(int stt);
    string getmsv();
    int getstt();
};
hocsinh::hocsinh() : diem() {
    lop = "";
    msv = "";
}
hocsinh::hocsinh(string lop, string msv) : diem() {
    this->lop = lop;
    this->msv = msv;
}
hocsinh::~hocsinh() {
    this->lop = "";
    this->msv = "";
}
void hocsinh::nhap4() {
    diem::nhap3();
    cin.ignore();
    cout << "Nhap lop: ";
    getline(cin, lop);
    cout << "Nhap msv: ";
    getline(cin, msv);
}
void hocsinh::setstt(int stt) {
    this->stt = stt;
}
int hocsinh::getstt() {
    return stt;
}
void hocsinh::xuat3() {
    cout << endl << setw(30) << left << hoten
        << setw(15) << left << quequan
        << setw(15) << left << msv
        << left << Ngay << "/" << Thang << "/" << Nam
        << setw(17) << left << toan
        << setw(15) << left << van
        << setw(15) << left << anh
        << setw(15) << left << ly
        << setw(15) << left << sinh
        << setw(15) << left << su
        << setw(15) << left << dia
        << setw(15) << left << dtb << endl;
    cout << setfill('-') << setw(190) << "-" << endl;
    cout << setfill(' ');
}
string hocsinh::getmsv() {
    return msv;
}
class quanly {
private:
    vector<hocsinh*> HS;
public:
    void NhapDS(int n);
    void XuatThongTinChung();
    void XuatDS();
    void luufile();
    void docfile();
    bool check(string h);
    void xoahs(string c);
    void themhs();
    void sapxep();
    hocsinh* timKiem(string msv);
};
bool quanly::check(string h) {
    for (int i = 0; i < this->HS.size(); i++) {
        if (h == HS.at(i)->getmsv())
            return true;
    }
    return false;
}
void quanly::NhapDS(int n) {
    hocsinh* hs;
    for (int i = 0; i < n; i++) {
        cout << "\n\t\tNhap Thong Tin Cua Hoc Sinh Thu " << i + 1 << endl;
        hs = new hocsinh;
        do {
            hs->nhap4();
            if (check(hs->getmsv())) {
                cout << "Ma So Hoc Sinh Da Ton Tai !" << endl;
                cout << "Vui Long Nhap Lai Thong Tin!" << endl;
            }
        } while (check(hs->getmsv()));
        HS.push_back(hs);
        cout << "\t\t" << setw(70) << setfill('-') << "-" << endl;
        cout << setfill(' ');
    }
}
void quanly::XuatThongTinChung() {
    cout << endl << "THONG TIN HOC SINH \n" << endl;
    cout << setw(30) << left << "hoten"
        << setw(15) << left << "quequan"
        << setw(15) << left << "msv"
        << setw(18) << left << "Ngay Sinh"
        << setw(15) << left << "toan"
        << setw(15) << left << "van"
        << setw(15) << left << "anh"
        << setw(15) << left << "ly"
        << setw(15) << left << "sinh"
        << setw(15) << left << "su"
        << setw(15) << left << "dia"
        << setw(15) << left << "dtb" << endl;
    cout << setw(190) << setfill('_') << "_" << endl;
    cout << setfill(' ');
}
void quanly::XuatDS() {
    if (HS.empty()) {
        cout << "Danh sach hoc sinh rong!" << endl;
        return;
    }
    int stt = 1;
    XuatThongTinChung();
    for (int i = 0; i < this->HS.size(); i++) {
        this->HS.at(i)->setstt(stt);
        this->HS.at(i)->xuat3();
        stt++;
    }
}
void quanly::xoahs(string c){
	if(HS.empty()){
        cout << "Danh sach hoc sinh rong!" << endl;
        return;
    }
    bool found = false; 
    for(int i = 0 ;i < this->HS.size();i++){
        if(HS.at(i)->getmsv()==c){
            HS.erase(HS.begin()+(i));
            found = true; 
            break;
        }
    }
    if (!found) {
        cout <<"\nKHONG TIM THAY MSV CAN XOA"<<endl;
    }
}

void quanly::sapxep(){
    if(HS.empty()){
        cout << "Danh sach hoc sinh rong!" << endl;
        return;
    }
    for(int i = 0 ;i < this->HS.size()-1;i++){
        for(int j = i+1; j< this->HS.size();j++ ){
            if(HS.at(i)->getdtb() < HS.at(j)->getdtb()){
                swap(HS.at(i),HS.at(j)); 
            }
        }   
    }   
}
void quanly::themhs() {
    hocsinh* hs;
    hs = new hocsinh;
    do {
        hs->nhap4();
        if (check(hs->getmsv())) {
            cout << "Ma So Hoc Sinh Da Ton Tai !" << endl;
            cout << "Vui Long Nhap Lai Thong Tin!" << endl;
        }
    } while (check(hs->getmsv()));
    HS.push_back(hs);

    ofstream file("./lop.txt", ios::app);
    if (!file.is_open()) {
        cout << "Khong the mo file!" << endl;
        return;
    }

    file << endl << setw(30) << left << hs->getten()
        << setw(15) << left << hs->getquequan()
        << setw(15) << left << hs->getmsv()
        << left << hs->getNgay() << "/" << hs->getThang() << "/" << setw(12) << left << hs->getNam()
        << setw(15) << left << hs->gettoan()
        << setw(15) << left << hs->getvan()
        << setw(15) << left << hs->getanh()
        << setw(15) << left << hs->getly()
        << setw(15) << left << hs->getsinh()
        << setw(15) << left << hs->getsu()
        << setw(15) << left << hs->getdia()
        << setw(15) << left << hs->getdtb() << endl;
    file << setfill('-') << setw(180) << "-" << endl;
    file << setfill(' ');

    file.close();
}

void quanly::luufile() {
    if (HS.empty()) {
        cout << "Danh sach hoc sinh rong, khong the luu file!" << endl;
        return;
    }
	ofstream file("./lop.txt");
    int stt = 1;
    file << endl << "THONG TIN HOC SINH \n" << endl;
    file << setw(30) << left << "hoten"
        << setw(15) << left << "quequan"
        << setw(15) << left << "msv"
        << setw(18) << left << "Ngay Sinh"
        << setw(15) << left << "toan"
        << setw(15) << left << "van"
        << setw(15) << left << "anh"
        << setw(15) << left << "ly"
        << setw(15) << left << "sinh"
        << setw(15) << left << "su"
        << setw(15) << left << "dia"
        << setw(15) << left << "dtb" << endl;
    file << setw(190) << setfill('_') << "_" << endl;
    file << setfill(' ');

    for (int i = 0; i < this->HS.size(); i++) {
        this->HS.at(i)->setstt(stt);
        file << endl << setw(30) << left << HS.at(i)->getten()
            << setw(15) << left << HS.at(i)->getquequan()
            << setw(15) << left << HS.at(i)->getmsv()
            << left << HS.at(i)->getNgay() << "/" << HS.at(i)->getThang() << "/" << setw(12) << left << HS.at(i)->getNam()
            << setw(15) << left << HS.at(i)->gettoan()
            << setw(15) << left << HS.at(i)->getvan()
            << setw(15) << left << HS.at(i)->getanh()
            << setw(15) << left << HS.at(i)->getly()
            << setw(15) << left << HS.at(i)->getsinh()
            << setw(15) << left << HS.at(i)->getsu()
            << setw(15) << left << HS.at(i)->getdia()
            << setw(15) << left << HS.at(i)->getdtb() << endl;
        file << setfill('-') << setw(190) << "-" << endl;
        file << setfill(' ');
        stt++;
    }

    file.close();
}
void quanly::docfile() {
	ifstream file("./lop.txt");
    hocsinh* hs;
    if (!file.is_open()) {
        cout << "Khong the mo file!" << endl;
        return;
    }
    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }
    file.close();
}

hocsinh* quanly::timKiem(string msv) {
    for (int i = 0; i < HS.size(); i++) {
        if (HS[i]->getmsv() == msv) {
            return HS[i];
        }
    }
    return 0;
}
int main() {
    quanly ql;
    hocsinh hs;
    bool daNhap = false;
    int c;
    
    do {
        cout << "\t\t\t_____________________________________________________________________________\n\n\n";
        cout << "\t\t\t==================================MENU=======================================\n\n\n";
        cout << "\t| Nhan phim 1 de nhap hoc sinh                       		" << endl;
        cout << "\t| Nhan Phim 2 de xuat danh sach                        		" << endl;
        cout << "\t| Nhan phim 3 de them hoc sinh              			" << endl;
        cout << "\t| Nhan phim 4 de xoa hoc sinh                        		" << endl;
        cout << "\t| Nhan phim 5 de sap xep theo diem trung binh                        		" << endl;
        cout << "\t| Nhan phim 6 de tim hoc sinh                         		" << endl;
        cout << "\t| Nhan phim 7 de luu file                         		" << endl;
        cout << "\t| Nhan phim 8 de doc file                        	" << endl;
        cout << "\t| Nhan phim 0 de out                        	" << endl;
        cout << "\n\t Vui long nhap lua chon cua ban : ";
        cin >> c;
        cout << endl;
        switch (c) {
            case 1:
                int n;
                cout << "Nhap so luong hoc sinh can them: ";
                cin >> n;
                ql.NhapDS(n);
                daNhap = true;
                break;
            case 2:
                ql.XuatDS();
                break;
            case 3:
				ql.themhs();
				daNhap = true;
                break;
            case 4:
				if (daNhap) {
        		string msv;
        		cout << "Nhap MSV hoc sinh can xoa: ";
       		 	cin >> msv;
        		ql.xoahs(msv);
        		cout << "Da xoa hoc sinh co MSV " << msv << "." << endl;
    			} else {
        		cout << "Danh sach hoc sinh rong!" << endl;
    			}
                break;
            case 5:
				ql.sapxep();
    			cout << "Da sap xep danh sach hoc sinh theo diem trung binh." << endl;
                break;
            case 6:
				if (!daNhap) {
				        cout << "Danh sach hoc sinh rong!" << endl;
				    }
				    else {
				        string msv;
				        cout << "Nhap MSV hoc sinh can tim: ";
				        cin.ignore();
				        getline(cin, msv);
				        hocsinh* timhocsinh = ql.timKiem(msv);
				        if (timhocsinh != 0) {
				            cout << "Hoc sinh co MSV " << msv << ":\n";
				            ql.XuatThongTinChung();
				            timhocsinh->xuat3();
				        }
				        else {
				            cout << "Khong tim thay hoc sinh co MSV " << msv << " trong danh sach." << endl;
				        }
				    }
                break;
            case 7:
                ql.luufile();
                break;
            case 8:
            	ql.docfile();
            	break;
            case 0:

                break;
            default:
                cout << "Lua chon khong hop le. Vui long thu lai." << endl;
                break;
        }
    } while (c != 0);

    return 0;
}


