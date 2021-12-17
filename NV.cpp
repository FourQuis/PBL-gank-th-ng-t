#include"NV.h"
NV::NV(int mnvien, string tnvien,int Gt, string nsinh, string dchi, string sdthoai, string mail)
    : _MNV(mnvien), _TenNV(tnvien),_GT(Gt),_NgaySinh(nsinh), _DiaChi(dchi), _Phone(sdthoai), _Email(mail)
{}
NV::~NV()
{
}
void NV::Input()
{
    cout << "ID: "; cin>>_MNV;
    cout << "Name: "; getline(cin >> ws, _TenNV);
    cout << "Male nhập 1 , Famale nhập 0 "; cin >> _GT;
    cout << "Date Of Birth: "; getline(cin >> ws, _NgaySinh);
    cout << "Add: "; getline(cin >> ws, _DiaChi);
    cout << "Phone: "; getline(cin >> ws, _Phone);
    cout << "Email: "; getline(cin >> ws, _Email);
}
void NV::Show()
{
      cout << "ID: " << _MNV << ", Name: " <<_TenNV <<" Sex :"<<((_GT==1)? " Nam":" Nữ ") <<" Date: " << _NgaySinh << ", Add: " << _DiaChi << ", Phone: " <<_Phone << ", Email: " << _Email << endl;
}
void NV::docfile(ifstream &inp){
    inp >> _MNV;
    getline(inp,_TenNV,',');
    inp >> _GT;
    getline(inp,_NgaySinh,',');
    getline(inp,_DiaChi,',');
    getline(inp,_Phone,',');
    getline(inp,_Email,',');
}
void NV::xuatfile(ofstream &oup){
   oup<<setw(15)<<left<<_MNV << setw(20) << _TenNV <<setw(10)<<left<<((_GT==1)? " Nam":" Nữ ")<<setw(14)<<left<<_NgaySinh<<setw(13)<<left<<_DiaChi<<setw(15)<< _Phone <<setw(25)<<_Email<<setw(5);

}
int  NV::MNV(){
     return this->_MNV;
}
string NV::TNV(){
    return this->_TenNV;
}



