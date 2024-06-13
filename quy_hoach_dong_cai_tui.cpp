#include<iostream>
#include<vector>
#include<iomanip>

using namespace std ; 

struct phone{
	string nhan ; 
	int kichthuoc ; 
	int gia ; 
};

struct F2_result{
	int x ; 
	vector<phone> a ;
};

F2_result F2(phone d[] , int n ,int s){
	int F[n+1][s+1]; 
	vector<phone> d_new  ; 
	phone root = {"No Name",0,0};
	d_new.push_back(root);
	for(int i = 0 ; i < n ; i++){
		d_new.push_back(d[i]);
	}
	for(int i = 0 ; i <= s ; i++){
		F[0][i] = 0 ;
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = 0 ; j <= s ; j++){
			F[i][j] = F[i-1][j];
			if(j >= d_new[i].kichthuoc){
				int tmp = d_new[i].gia + F[i-1][j - d_new[i].kichthuoc];
				if(tmp > F[i][j]){
					F[i][j] = tmp ;
				}
			}
		}
	}
	
	// in bang 
	for(int i = 0 ; i <= n ; i++){
		for(int j = 0 ; j <= s ; j++){
			cout << F[i][j] << " " ;
		}
		cout << endl ;
	}
	// truy vet 
	int i = n , j = s ; 
	F2_result result ;
	while(i){
		if(F[i][j] != F[i-1][j]){
			result.a.push_back(d[i-1]);
			j = j - d[i].kichthuoc ;
		}
		i--;
	}
	result.x = result.a.size() ;
	return result;
}

int main(){
	// kich thuoc s 
	int s = 15 ; 
	int n = 6 ; 
	phone d[n] = {
		{"nokia",5,1000000},
		{"iphone",3,2550000},
		{"samsung",2,1054000},
		{"oppo",6,2000000},
		{"realme",7,2500000},
		{"vectos",10,1500000}
	};
	F2_result  result = F2(d,n,s);
	cout << "So luong dien thoai la:" << result.x << endl ;
	cout << "So luong quat mua duoc la: " << result.a.size() << endl ; 
	cout << "--------------------------------------------------" << endl ;
	cout << "Name"  << "\t"; 
	cout << setw(25) << "KICH THUOC";
	cout << setw(15) << "GIA BAN" << endl ;
	cout << "--------------------------------------------------" << endl ; 
	for(int i = 0 ; i < result.a.size() ;i++){
		cout << result.a[i].nhan << "\t";
		cout << setw(25) << result.a[i].kichthuoc ;
		cout << fixed << setprecision(0) << setw(15) << result.a[i].gia << endl ;
	}
}
