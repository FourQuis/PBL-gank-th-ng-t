
#include "NV.h"
#include <fstream>
#include <windows.h>
int n;
int spt = 0;
int c1 = 0, c2 = 0, c3 = 0;
void textcolor(WORD color) {
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);

    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0;
    wAttributes |= color;

    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}
class NV_PhaChe : public NV {
private:
    string CV;
    int _Tluong;

public:
    NV_PhaChe() {
        _Tluong = 0;
        string CV = " ";
    };
    virtual void Input();
    virtual void docfile(ifstream &inp);
    virtual void xuatfile(ofstream &oup);
    void Show();
    int TL();
    int h;
};
void NV_PhaChe::xuatfile(ofstream &oup) {
    NV::xuatfile(oup);
    oup << left << "\t\t" << CV << "\t\t\t" << TL() << "\t\t\t";
    oup << t.GetDay() << "-" << t.GetMonth() << "-" << t.GetYear();
}
void NV_PhaChe::docfile(ifstream &inp) {
    NV::docfile(inp);
    getline(inp, CV, ',');
    int ngay, thang, nam;
    inp >> ngay >> thang >> nam;
    t.SetDay(ngay);
    t.SetMonth(thang);
    t.SetYear(nam);
    inp.ignore();
    inp >> h;
    PBNV = 1;
}
void NV_PhaChe::Input() {
    NV::Input();
    int ngay, thang, nam;
    cout << "Nhập chức vụ làm việc :";
    getline(cin >> ws, CV);
    cout << "Nhập ngày tháng bạn vào làm  :" << endl;
    cout << "Nhập ngày : ";
    cin >> ngay;
    cout << "Nhập tháng : ";
    cin >> thang;
    cout << "Nhập năm : ";
    cin >> nam;
    t.SetDay(ngay);
    t.SetMonth(thang);
    t.SetYear(nam);
    cout << "Nhập tổng số giờ làm trong 1 ngày : ";
    cin >> h;
    PBNV = 1;
    cout << "Bạn thêm nhân viên thành công !";
    cout << endl;
}
void NV_PhaChe::Show() {
    NV::Show();
    cout << "Vị trí :  " << CV;
    cout << endl;
    cout << "Số tiền lương làm trong 1 tháng :" << TL() << endl;
    cout << "Ngày đến làm việc:";
    cout << t.GetDay() << " " << t.GetMonth() << " " << t.GetYear() << endl;
    cout << "=======================================================" << endl;
    ;
}
// PPC:NV Phụ Pha chế  , PCC : Pha chế chính
int NV_PhaChe::TL() {
    string x = CV;
    int MLPPC = 12000;
    int MLPCC = 20000;
    int l2 = 0;
    if (x == "PhuPhaChe")
        l2 = MLPPC * h * 30;
    else if (x == "PhaCheChinh")
        l2 = MLPCC * h * 30;
    return l2;
}
class NV_Order : public NV {
private:
    string _OD;
    int _TL;

public:
    NV_Order() {
        _TL = 0;
        string _OD = " ";
    }
    ~NV_Order();
    virtual void Input();
    virtual void Show();
    virtual void docfile(ifstream &inp);
    virtual void xuatfile(ofstream &oup);
    int TL();
    int h1;
};
void NV_Order::xuatfile(ofstream &oup) {
    NV::xuatfile(oup);
    oup << left << "\t\t" << _OD << "\t\t\t" << TL() << "\t\t\t" << t.GetDay() << "-" << t.GetMonth() << "-" << t.GetYear();
}
void NV_Order::docfile(ifstream &inp) {
    NV::docfile(inp);
    getline(inp, _OD, ',');
    int ngay, thang, nam;
    inp >> ngay >> thang >> nam;
    t.SetDay(ngay);
    t.SetMonth(thang);
    t.SetYear(nam);
    inp.ignore();
    inp >> h1;
    PBNV = 2;
}
void NV_Order::Input() {
    NV::Input();
    int ngay, thang, nam;
    cout << "Nhập vị trí làm việc:";
    cin >> _OD;
    cout << "Nhập ngày tháng bạn vào làm  :" << endl;
    cout << "Nhập ngày : ";
    cin >> ngay;
    cout << "Nhập tháng : ";
    cin >> thang;
    cout << "Nhập năm ";
    cin >> nam;
    t.SetDay(ngay);
    t.SetMonth(thang);
    t.SetYear(nam);
    cout << "Nhập tổng số giờ làm trong 1 ngày : ";
    cin >> h1;
    PBNV = 2;
    cout << "Bạn thêm nhân viên thành công !";
    cout << endl;
}
// OD gồm Bưng bàn , Thanh toán

void NV_Order::Show() {
    NV::Show();
    cout << "Vị trí :  " << _OD;
    cout << endl;
    cout << "Số tiền lương làm trong 1 tháng :" << TL() << endl;
    cout << "Ngày đến làm việc:";
    cout << t.GetDay() << " " << t.GetMonth() << " " << t.GetYear() << endl;
    cout << "=======================================================" << endl;
}
int NV_Order::TL() {
    int l1 = 0;
    int Phuvu = 10000;
    int ThanhToan = 11000;
    string x = _OD;
    if (x == "PhucVu")
        l1 = Phuvu * h1 * 30;
    else if (x == "ThanhToan")
        l1 = ThanhToan * h1 * 30;
    return l1;
}
class NV_Baove : public NV {
private:
    string _BV;
    int _TL;

public:
    NV_Baove() {
        _TL = 0;
        string _BV = " ";
    };
    ~NV_Baove();
    virtual void Input();
    virtual void Show();
    virtual void docfile(ifstream &inp);
    virtual void xuatfile(ofstream &oup);
    int TL();
    int h3;
};
void NV_Baove::xuatfile(ofstream &oup) {
    NV::xuatfile(oup);
    oup << left << "\t\t\t" << _BV << "\t\t\t" << TL() << "\t\t\t" << t.GetDay() << "-" << t.GetMonth() << "-" << t.GetYear();
}
void NV_Baove::docfile(ifstream &inp) {
    NV::docfile(inp);
    getline(inp, _BV, ',');
    int ngay, thang, nam;
    inp >> ngay >> thang >> nam;
    t.SetDay(ngay);
    t.SetMonth(thang);
    t.SetYear(nam);
    inp.ignore();
    inp >> h3;
    PBNV = 3;
}
void NV_Baove::Input() {
    NV::Input();
    int ngay, thang, nam;
    cout << "Nhập vị trí làm việc:";
    cin >> _BV;
    cout << "Nhập ngày tháng bạn vào làm  :" << endl;
    cout << "Nhập ngày : ";
    cin >> ngay;
    cout << "Nhập tháng : ";
    cin >> thang;
    cout << "Nhập năm ";
    cin >> nam;
    t.SetDay(ngay);
    t.SetMonth(thang);
    t.SetYear(nam);
    cout << "Nhập tổng số giờ làm trong 1 ngày : ";
    cin >> h3;
    PBNV = 3;
    cout << "Bạn thêm nhân viên thành công !";
    cout << endl;
}
void NV_Baove::Show() {
    NV::Show();
    cout << "Vị trí :  " << _BV;
    cout << endl;
    cout << "Số tiền lương làm trong 1 tháng :" << TL() << endl;
    cout << "Ngày đến làm việc:";
    cout << t.GetDay() << " " << t.GetMonth() << " " << t.GetYear() << endl;
    cout << "=======================================================" << endl;
}
// NV bảo vệ  BVTC , BVGX
int NV_Baove::TL() {
    string x = _BV;
    int BaoVeXe = 7000;
    int BaoVeCong = 7500;
    int l = 0;
    if (x == "BaoVeXe")
        l = BaoVeXe * h3 * 30;
    else if (x == "BaoVeCong")
        l = BaoVeCong * h3 * 30;
    ;
    return l;
}
class QLNV {
private:
    NV *DSNV[100];

public:
    int u = 0;
    void NhapDs();
    void Nhapfile();
    void Xuatfile();
    void XuatDs();
    void Sort();
    int Timnhanvien(int);
    void Update(int);
    void Delete(int);
    int Timnhanvien1(int);
};
void QLNV::Sort() {
    for (int i = 0; i < spt - 1; i++) {
        for (int j = i + 1; j < spt; j++)
            if (DSNV[i]->MNV() > DSNV[j]->MNV()) {
                NV *temp = DSNV[i];
                DSNV[i] = DSNV[j];
                DSNV[j] = temp;
            }
    }
    cout << "Sắp xếp thành công : " << endl;
    system("pause");
}
void QLNV::Xuatfile() {
    ofstream oup1;
    oup1.open("NVPCOUT.txt", ios::out);
    ofstream oup2;
    oup2.open("NVODOUT.txt", ios::out);
    ofstream oup3;
    oup3.open("NVBVOUT.txt", ios::out);
    ofstream oup;
    oup.open("DANHSACH.txt", ios::out);
    // Cả file
    oup << setw(70) << "DANH SÁCH NHÂN VIÊN QUÁN CÀ PHÊ " << endl;
    oup << setw(10) << "  Mã nhân viên |" << setw(10) << " Tên nhân viên |" << setw(10) << " Giới tính |" << setw(10) << " Ngày sinh |" << setw(10) << "   Địa chỉ   |" << setw(10) << " Số điện thoại |" << setw(20) << "     Email               \t\t|" << setw(12) << "   Công việc \t\t|" << setw(10) << "   Lương   |" << setw(10) << " Ngày đến làm việc |" << endl;
    for (int i = 1; i <= 147; i++) {
        oup << "=";
    }
    oup << endl;
    // Nhân viên pha chế
    oup1 << setw(70) << "DANH SÁCH NHÂN VIÊN PHA CHE QUÁN CÀ PHÊ " << endl;
    oup1 << setw(10) << "  Mã nhân viên |" << setw(10) << " Tên nhân viên |" << setw(10) << " Giới tính |" << setw(10) << " Ngày sinh |" << setw(10) << "   Địa chỉ   |" << setw(10) << " Số điện thoại |" << setw(20) << "     Email               |" << setw(12) << "   Công việc |" << setw(10) << "   Lương   |" << setw(10) << " Ngày đến làm việc |" << endl;
    for (int i = 1; i <= 147; i++) {
        oup1 << "=";
    }
    oup1 << endl;
    // Nhân viên Order
    oup2 << setw(70) << "DANH SÁCH NHÂN VIÊN ORDER QUÁN CÀ PHÊ " << endl;
    oup2 << setw(10) << "  Mã nhân viên |" << setw(10) << " Tên nhân viên |" << setw(10) << " Giới tính |" << setw(10) << " Ngày sinh |" << setw(10) << "   Địa chỉ   |" << setw(10) << " Số điện thoại |" << setw(20) << "     Email               |" << setw(12) << "   Công việc |" << setw(10) << "   Lương   |" << setw(10) << " Ngày đến làm việc |" << endl;
    for (int i = 1; i <= 147; i++) {
        oup2 << "=";
    }
    oup2 << endl;
    // Nhân viên Bảo Vệ
    oup3 << setw(70) << "DANH SÁCH NHÂN VIÊN BAO VEQUÁN CÀ PHÊ " << endl;
    oup3 << setw(10) << "  Mã nhân viên |" << setw(10) << " Tên nhân viên |" << setw(10) << setw(10) << " Giới tính |"
         << " Ngày sinh |" << setw(10) << "   Địa chỉ   |" << setw(10) << " Số điện thoại |" << setw(20) << "     Email               |" << setw(12) << "   Công việc |" << setw(10) << "   Lương   |" << setw(10) << " Ngày đến làm việc |" << endl;
    for (int i = 1; i <= 147; i++) {
        oup3 << "=";
    }
    oup3 << endl;
    int lc;
    do {
        system("cls");
        cout << "\t************ Xuất danh sách nhân viên ************" << endl;
        cout << "\t**    1. Nhân viên Pha chế                      **" << endl;
        cout << "\t**    2. Nhân viên Order                        **" << endl;
        cout << "\t**    3. Nhân viên Bảo Vệ                       **" << endl;
        cout << "\t**    4. Tất cả nhân viên                       **" << endl;
        cout << "\t**    0. Quay lại                               **" << endl;
        cout << ">>Nhập lựa chọn :";
        cin >> lc;
        system("cls");
        switch (lc) {
        case 1: {

            for (int i = 0; i < spt; i++)
                if (DSNV[i]->PBNV == 1) {
                    DSNV[i]->xuatfile(oup1);
                    oup1 << endl;
                }
            oup1.close();
            cout << "Bạn đã xuất file thành công" << endl;
            system("pause");
            break;
        }
        case 2: {
            for (int i = 0; i < spt; i++)
                if (DSNV[i]->PBNV == 2) {
                    DSNV[i]->xuatfile(oup2);
                    oup2 << endl;
                }
            oup2.close();
            cout << "Bạn đã xuất file thành công" << endl;
            system("pause");
            break;
        }
        case 3: {
            for (int i = 0; i < spt; i++)
                if (DSNV[i]->PBNV == 3) {
                    DSNV[i]->xuatfile(oup3);
                    oup3 << endl;
                }

            oup3.close();
            cout << "Bạn đã xuất file thành công" << endl;
            system("pause");
            break;
        }
        case 4: {
            for (int i = 0; i < spt; i++) {
                if (DSNV[i]->PBNV == 1 || DSNV[i]->PBNV == 2 || DSNV[i]->PBNV == 3)
                    DSNV[i]->xuatfile(oup);
                oup << endl;
            }
            cout << "Bạn đã xuất file thành công" << endl;
            system("pause");
            oup.close();
            break;
        }
        default:
            break;
        }
    } while (lc != 0);
}
void QLNV::Nhapfile() {
    int lc;
    int t1 = 0, t2 = 0, t3 = 0;
    int xb = 0, xh = 0, xm = 0;
    bool dathem1 = false;
    bool dathem2 = false;
    bool dathem3 = false;
    NV *nv;
    do {
        system("cls");
        cout << "\t************ Nhập danh sách nhân viên ************" << endl;
        cout << "\t**    1. Nhân viên Pha chế                      **" << endl;
        cout << "\t**    2. Nhân viên Order                        **" << endl;
        cout << "\t**    3. Nhân viên Bảo Vệ                       **" << endl;
        cout << "\t**    0. Quay lại                               **" << endl;
        cout << ">>Nhập lựa chọn : ";
        cin >> lc;
        system("cls");
        switch (lc) {
        case 1: {
            system("cls");
            if (dathem3 == true)
                xb = t3;
            if (dathem2 == true)
                xh = t2;
            ifstream inp;
            inp.open("NVPC.txt", ios::in);
            inp >> n;
            t1 = n;
            c1 = xb + xh;
            spt = t1 + t2 + t3;
            for (int i = c1; i < spt; i++) {
                DSNV[i] = new NV_PhaChe();
                DSNV[i]->docfile(inp);
            }
            dathem1 = true;
            cout << "Đọc file thành công" << endl;
            system("pause");
            cout << endl;
            inp.close();
            break;
        }
        case 2: {
            system("cls");
            if (dathem1 == true)
                xm = t1;
            if (dathem3 == true)
                xb = t3;
            ifstream inp;
            inp.open("NVOD.txt", ios::in);
            inp >> n;
            t2 = n;
            dathem2 = true;
            c2 = xm + xb;
            spt = t1 + t2 + t3;
            for (int i = c2; i < spt; i++) {
                DSNV[i] = new NV_Order();
                DSNV[i]->docfile(inp);
            }
            cout << "Đọc file thành công" << endl;
            system("pause");
            cout << endl;
            inp.close();
            break;
        }
        case 3: {
            system("cls");
            if (dathem1 == true)
                xm = t1;
            if (dathem2 == true)
                xh = t2;
            ifstream inp;
            inp.open("NVBV.txt", ios::in);
            inp >> n;
            t3 = n;
            c3 = xm + xh;
            dathem3 = true;
            spt = t1 + t2 + t3;
            for (int i = c3; i < spt; i++) {
                DSNV[i] = new NV_Baove();
                DSNV[i]->docfile(inp);
            }
            cout << "Đọc file thành công" << endl;
            system("pause");
            cout << endl;
            inp.close();
            break;
        }
        default:
            break;
        }
    } while (lc != 0);
    spt = t1 + t2 + t3;
}
void QLNV::Update(int m) {
    u1:
        int i = 0;
    for (i = 0; i < spt; i++) {
        if (DSNV[i]->MNV() == m)
            break;
    }
    if (i <= spt) {
        cout << "Cap nhat Nhan vien: " << endl;
        DSNV[i]->Show();
        DSNV[i]->Input();
        cout << "Cap nhat hoan tat" << endl;
    }
    cout << "Bạn muốn cập nhật nữa không [Y/n]";
    u3:
    string Up = " ";
    cin >> Up;
   
    if (Up == "Y") { cout << "Nhập mã nhân viên bạn muốn cập nhật"<<endl;
                     cout << " MNV :" ; cin >> m; goto u1;
                     }
    else if (Up == "n") {goto u2;}
    else { cout << " Bạn đã nhập sai vui lòng nhập lại :"; goto u3;}
     u2:system("pause");                
}
int QLNV::Timnhanvien(int m) {
k4:
    system("cls");
    int index = -1;
    for (int i = 0; i < spt; i++) {
        if (DSNV[i]->MNV() == m) {
            index = i;
            DSNV[i]->Show();
            break;
        }
    }
    if (index == -1) {
        cout << "Không có nhân viên bạn tìm kiếm " << endl;
        cout << "Ban có muốn thêm nhân viên [Y/n]";
    k1:
        string t5 = " ";
        cin >> t5;
        if (t5 == "Y") {
            system("cls");
            QLNV::NhapDs();
        }
    }
k3:
    string t4 = " ";
    cout << "Bạn muốn tiếp tục tìm kiếm không [Y/n] :";
    cin >> t4;
    if (t4 == "Y") {
        system("cls");
        cout << " MNV = ";
        cin >> m;
        goto k4;
    } else if (t4 == "n") {
        goto k2;
    } else {
        cout << "Bạn đã nhập sai vui lòng nhập lại";
        goto k3;
    }
k2:
    system("pause");
    return index;
}
int QLNV::Timnhanvien1(int m) {
    system("cls");
    int index = -1;
    for (int i = 0; i < spt; i++) {
        if (DSNV[i]->MNV() == m) {
            index = i;
            break;
        }
    }

    return index;
}
void QLNV::Delete(int m) {
    int index = 0;
    for (index = 0; index < spt; index++) {
        if (DSNV[index]->MNV() == m)
            break;
    }
    if (index <= spt) {
        NV *DSNV1[50];
        DSNV1[spt] = new NV();
        for (int i = 0; i < spt; i++) {
            if (i < index) {
                DSNV1[i] = DSNV[i];
            } else if (i > index) {
                DSNV1[i - 1] = DSNV[i];
            }
        }
        DSNV[spt] = new NV[spt - 1];
        for (int i = 0; i < spt - 1; i++) {
            DSNV[i] = DSNV1[i];
        }
        cout << "Da xoa thanh cong" << endl;
        spt--;
    }
}
void QLNV::NhapDs() {
    int t;
    NV *nv;
    do {
        { system("cls");
            cout << "\t************ Thêm nhân viên ************" << endl;
            cout << "\t*    1. Nhân viên Pha chế              *" << endl;
            cout << "\t*    2. Nhân viên Order                *" << endl;
            cout << "\t*    3. Nhân viên Bảo Vệ               *" << endl;
            cout << "\t*    0. Quay lại                       *" << endl;
            cout << "\t****************************************" << endl;
            cout << "Mời bạn chọn :";
            cin >> t;
            system("cls");
        b3:
            switch (t) {
            case 1: {
            rep:
                DSNV[spt] = new NV_PhaChe();
                DSNV[spt]->Input();
                string t1 = " ";

                cout << "Bạn muôn thêm nữa không [Y/n] :";
            r1:
                getline(cin >> ws, t1);
                if (t1 == "Y") {
                    spt++;
                    goto rep;
                } else if (t1 == "n") {
                    break;
                } else {
                    cout << "Bạn đã nhập sai vui lòng nhập lại :";
                    goto r1;
                };
                system("pause");
                cout << endl;
                break;
            }
            case 2: {
            rep1:
                DSNV[spt] = new NV_Order();
                DSNV[spt]->Input();
                string t2 = " ";

                cout << "Bạn muôn thêm nữa không [Y/n] :";
            r2:
                getline(cin >> ws, t2);
                if (t2 == "Y") {
                    spt++;
                    goto rep;
                } else if (t2 == "n") {
                    break;
                } else {
                    cout << "Bạn đã nhập sai vui lòng nhập lại :";
                    goto r2;
                };
                system("pause");
                cout << endl;
                break;
            }
            case 3: {
            rep3:
                DSNV[spt] = new NV_Baove();
                DSNV[spt]->Input();
                string t3 = " ";

                cout << "Bạn muôn thêm nữa không [Y/n] :";
            r3:
                getline(cin >> ws, t3);
                if (t3 == "Y") {
                    spt++;
                    goto rep;
                } else if (t3 == "n") {
                    break;
                } else {
                    cout << "Bạn đã nhập sai vui lòng nhập lại :";
                    goto r3;
                };
                system("pause");
                cout << endl;
                break;
            }
            default:
                break;
            }
            spt++;
        }
    } while (t != 0);
}
void QLNV::XuatDs() {
    int t;
    NV *nv;
    do {
    rep1:
        textcolor(1);
        cout << "\t************ Hiển thị nhân viên ************" << endl;
        cout << "\t**    1. Nhân viên Pha chế                **" << endl;
        cout << "\t**    2. Nhân viên Order                  **" << endl;
        cout << "\t**    3. Nhân viên Bảo Vệ                 **" << endl;
        cout << "\t**    4. Tất cả nhân viên                 **" << endl;
        cout << "\t**    0. Quay lại                         **" << endl;
        cout << "\t********************************************" << endl;
        cout << ">>Nhập lựa chọn :";
        cin >> t;
        system("cls");
        switch (t) {
        case 1: {
            for (int i = 0; i < spt; i++) {
                if (DSNV[i]->PBNV == 1)
                    DSNV[i]->Show();
            }
            system("pause");
            cout << endl;
            break;
        }
        case 2: {
            for (int i = 0; i < spt; i++) {
                if (DSNV[i]->PBNV == 2)
                    DSNV[i]->Show();
            }
            cout << endl;
            break;
        }
        case 3: {
            cout << spt;
            for (int i = 0; i < spt; i++) {
                if (DSNV[i]->PBNV == 3)
                    DSNV[i]->Show();
            }
            cout << endl;
            break;
        }
        case 4: {
            cout << "Số lượng nhân viên :" << spt << endl;
            cout << endl;
            for (int i = 0; i < spt; i++) {
                if (DSNV[i]->PBNV == 1 || DSNV[i]->PBNV == 2 || DSNV[i]->PBNV == 3) {
                    DSNV[i]->Show();
                }
                cout << endl;
            }
            cout << endl;
            system("pause");
            goto rep1;
            break;
        }
        case 0: {
            break;
        }
        }
    } while (t != 0);
}
int main() {
    QLNV QL;
    int c;
    while (true) {
        system("cls");
        textcolor(10);
        cout << R"(
       ____                     _               _                         _
      /___ \_   _  __ _ _ __   | |_   _   _ __ | |__   __ _ _ __   __   _(_) ___ _ __
     //  / / | | |/ _` | '_ \  | | | | | | '_ \| '_ \ / _` | '_ \  \ \ / / |/ _ \ '_ \ 
/ \_/ /| |_| | (_| | | | | | | |_| | | | | | | | | (_| | | | |  \ V /| |  __/ | | |
    \___,_\ \__,_|\__,_|_| |_| |_|\__, | |_| |_|_| |_|\__,_|_| |_|   \_/ |_|\___|_| |_|
                                  |___/                                                )"
             << '\n';
        textcolor(2);
        cout << "\t************[ Quản lý nhân viên cà phê ]*************\t" << endl;
        cout << "\t**    1. Hiển thị danh sách nhân viên              **\t" << endl;
        cout << "\t**    2. Thêm nhân viên                            **\t" << endl;
        cout << "\t**    3. Tìm nhân viên theo mã nhân viên           **\t" << endl;
        cout << "\t**    4. Cập nhật nhân viên                        **\t" << endl;
        cout << "\t**    5. Sắp xếp theo mã nhân viên                 **\t" << endl;
        cout << "\t**    6. Xóa nhân viên                             **\t" << endl;
        cout << "\t**    7. Dọc danh sách từ file                     **\t" << endl;
        cout << "\t**    8. Xuất danh sách từ file                    **\t" << endl;
        cout << "\t**    0. Thoat                                     **\t" << endl;
        cout << "\t*****************************************************\t" << endl;
        cout << ">>Nhập lựa chọn  : ";
        cin >> c;
        switch (c) {
        case 2: {
            system("cls");
            QL.NhapDs();
            break;
        }
        case 1: {
            system("cls");
            QL.XuatDs();
            system("pause");
            break;
        }
        case 3: {
            system("cls");
            int mnv;
            cout << "Nhập mã nhân viên bạn muốn tìm kiếm :" << endl;
            cout << "MNV = ";
            cin >> mnv;
            QL.Timnhanvien(mnv);
            break;
        }
        case 4: {
            system("cls");
            int mnv;
            cout << " Nhập mã nhân viên bạn muốn cập nhật " << endl;
            cout << "MNV = ";
            cin >> mnv;
            if (QL.Timnhanvien1(mnv) == -1){
                cout << "Không có nhân viên" << endl;
                cout << "Bạn có muôn thêm nhân viên [Y/n]";
                b2:
                string tn = " ";
                cin >> tn;
                if (tn=="Y") {QL.NhapDs();} 
                else if (tn == "n") goto b3;
                else {
                    cout << "Bạn đã nhập sai vui lòng nhập lại ";
                    goto b2;
                }
                }
            else {
                QL.Update(mnv);
            };
            b3:
            break;
        }
        case 6: {
            system("cls");
            int mnv;
            cout << "Nhập mã nhân viên bạn muốn xóa :" << endl;
            cout << "MNV = ";
            cin >> mnv;
            if (QL.Timnhanvien1(mnv) == -1)
                cout << "Không có nhân viên bạn cần xóa ";
            else {
                QL.Delete(mnv);
                system("pause");
                break;
            }
        }
        case 7: {
            system("cls");
            QL.Nhapfile();
            break;
        }
        case 8: {
            system("cls");
            QL.Xuatfile();
            break;
        }
        case 5: {
            system("cls");
            QL.Sort();
            break;
        }
        case 0: {   system("cls");
            cout << endl;
            cout << endl;
                      textcolor(19);
            cout << "    |==============================================================================|\t\t"<< endl;
            cout << "    |   PBL        :   Đồ án cơ sở lập trình                    |                  |\t\t"<<endl;
            cout << "    |   Đề tài     :   Quản lý nhân viên Cafe                   |                  |\t\t"<<endl; 
            cout << "    |   Người hướng dẫn : Phan Thanh Tao                        |                  |\t\t"<< endl;
            cout << "    |   Sinh viên thực hiện : [Lê Tứ Qúy : 20TCLC_Nhat2]        |                  |\t\t"   <<endl;
            cout << "    |                         [Lê Tiến Đạt : 20TCLC_Nhat1]      |                  |\t\t"<<endl;
            cout << "    ------------------------------------------------------------|";
            cout << R"(
    |                                                                              |
    | _______ _                 _       __                       _                 |
    | |__   __| |               | |     / _|                     (_)               |
    |    | |  | |__   __ _ _ __ | | __ | |_ ___  _ __   _   _ ___ _ _ __   __ _    |
    |    | |  | '_ \ / _` | '_ \| |/ / |  _/ _ \| '__| | | | / __| | '_ \ / _` |   |
    |    | |  | | | | (_| | | | |   <  | || (_) | |    | |_| \__ \ | | | | (_| |   |
    |    |_|  |_| |_|\__,_|_| |_|_|\_\ |_| \___/|_|     \__,_|___/_|_| |_|\__, |   |
    |                                                                      __/ |   |
    |                                                                     |___/    |
    |===============================================================================
)";
            return 0;
        }
        }
    }
    system("pause");
    return 0;
}

// QLNV::QLNV()
// {
//     this->p = nullptr;
//     this->_Length = 0;
// }
// QLNV::~QLNV()
// {
//     delete[] this->p;
// }
//  int QLNV::Length()
//  {
//      return this->_Length;
//  }

// void QLNV::Length(int value)
// {
//     this->_Length = value;
// }

// void QLNV::Add(NV s)
// {
//     if(this->_Length == 0)
//     {
//         this->p = new NV[this->_Length+1];
//         *(p + this->_Length) = s;
//     }
//     else
//     {
//         NV *temp = new NV[this->_Length];
//         for (int i = 0; i < this->_Length; i++)
//         {
//             *(temp + i) = *(this->p + i);
//         }
//         delete[] this->p;

//         this->p = new NV[this->_Length+1];
//         for (int i = 0; i < this->_Length; i++)
//         {
//             *(this->p + i) = *(temp + i);
//         }
//         *(p + this->_Length) = s;
//     }
//     this->_Length++;
// }

// void QLNV::Insert(NV s, int index)
// {

// }

// void QLNV::Show()
// {
//     for (int i = 0; i < this->_Length; i++)
//     {
//         (*(this->p+i)).Show();
//     }
// }

// void QLNV::Update(string m)
// {
//     int index = IndexOf(m);
//     if(index >= 0)
//     {
//         string d;
//         cout << "Lương cần thay đổi: ";
//         cin >> d;
//         (this->p+index)->Luong(d);
//     }
// }

// void QLNV::Delete(NV s)
// {
//     int index = IndexOf(s.MNV());
//     if(index >= 0)
//     {
//         if(this->_Length == 1)
//         {
//             delete[] this->p;
//         }
//         else
//         {
//             NV *temp = new NV[this->_Length];
//             for (int i = 0; i < this->_Length; i++)
//             {
//                 *(temp + i) = *(this->p + i);
//             }
//             delete[] this->p;
//             this->p = new NV[this->_Length-1];
//             for (int i = 0; i < this->_Length-1; i++)
//             {
//                 if(i < index)
//                 {
//                     *(this->p+i) = *(temp+i);
//                 }
//                 else
//                 {
//                     *(this->p+i) = *(temp+i+1);
//                 }
//             }
//         }
//         this->_Length--;
//     }