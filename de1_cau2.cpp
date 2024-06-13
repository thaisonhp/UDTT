#include<iostream>
#include<vector>
#include<iomanip>
using namespace std ;


// bai toan tham lam 
// khoi tai cau truc du lieu 
struct quat{
	string name ;
	string mausac;
	int gia   ; 
};

struct F1_result{
	int c ; 
	vector<quat> s ; 
};
void sapxep(quat d[] , int n){
	for(int i = 0 ; i < n ; i++){
		for(int j = i + 1; j < n ; j++){
			if(d[j].gia < d[i].gia){
				quat tmp = d[j];
				d[j] = d[i] ; 
				d[i] = tmp ;
			}
		}
	}
}
F1_result F1(quat d[] , int n , int p ){
	sapxep(d,n);
	// danh sach quat ban nhieu nhat 
//	for(int i = 0 ; i < n ;i++){
//		cout << d[i].name << "\t";
//		cout << setw(25) << d[i].mausac ;
//		cout << fixed << setprecision(0) << setw(15) << d[i].gia << endl ;
//	}
	F1_result result ;
//	vector<quat> s ; 
	int index = 0 ; 
	while(p >= d[index].gia && index < n){

		result.s.push_back(d[index]);
		p -= d[index].gia ;
		index ++ ;
	}
	// so luong quat 
	result.c = result.s.size();
//	cout << "Ket qua: " << result.c << endl ;
	return result ;
}

int main(){
	int p = 7000000 ; 
	int n = 6; // kich thuoc danh sach 
	quat d[n] = {
		{"nokia","red",1000000},
		{"iphone","black",2550000},
		{"samsung","white",1054000},
		{"oppo","yellow",2000000},
		{"realme","pink",2500000},
		{"vectos","gray",1500000}
	}; 
	F1_result result = F1(d,n,p);
	cout << "So luong quat mua duoc la: " << result.c << endl ; 
	cout << "--------------------------------------------------" << endl ;
	cout << "Name"  << "\t"; 
	cout << setw(25) << "MAU SAC";
	cout << setw(15) << "GIA BAN" << endl ;
	cout << "--------------------------------------------------" << endl ; 
	for(int i = 0 ; i < result.s.size() ;i++){
		cout << result.s[i].name << "\t";
		cout << setw(25) << result.s[i].mausac ;
		cout << fixed << setprecision(0) << setw(15) << result.s[i].gia << endl ;
	}
}
