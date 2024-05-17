#include<iostream>

using namespace std ;

void sort(int s[],int n){
	for(int i = 0 ; i < n ;i++){
		for(int j = i ; j < n ; j++){
			if(s[j] > s[i]){
				int tmp = s[i] ; 
				s[i] = s[j] ;
				s[j] = tmp ;
			}
		}
	}
}

// lay so luong dong xu
int F1(int s[] , int n, int m){
	sort(s,n);
	int p = 0 ;
	int i = 0;
	while(m >= 0 && i < n){
		p += m / s[i] ; 
		m -= p*s[i] ; 
		i++;
	}
	if(m > 0){
		return 0;
	}else{
		return p;
	}
}
void hienthi(int s[] , int n){
	for(int i = 0 ; i < n ; i++){
		cout << s[i] << " " ;
	}
	cout << endl ;
}
int main(){
	int n = 5 , m  = 20; 
	int s[5] = {5,1,3,7,6};
	int p = F1(s,n,m);
	hienthi(s,n);
	if(p){
		cout << "Can it nhat " << p << " dong!" << endl;
	}else{
		cout << "No solution" ;
	}
}