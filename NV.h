#include<string>
#include<fstream>
#include<iostream>
#include "Date.h"
#include <iomanip>
using namespace std;
class NV
{
    protected:
        int  _MNV; 
        int _GT;
        string _TenNV;
        string _NgaySinh;
        string _DiaChi;
        string _Phone;
        string _Email;
    public:
        // hàm dựng
        NV(int =0, string = "",int = 0, string = "", string = "", string = "", string = "");
        // hàm huỷ
        ~NV();
        Date t;
        string TNV();
        int MNV();
        int PBNV = 0 ;
        virtual void Show();
        virtual void Input();
        virtual void docfile(ifstream &inp);
        virtual void xuatfile(ofstream &inp);
        void Inputime(Date &date);
        void Outputtime(Date date);
};
