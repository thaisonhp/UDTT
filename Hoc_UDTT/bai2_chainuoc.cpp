#include<iostream>

using namespace std ;
void sort(int s[],int n){
	/*
	Ham nay de xap sep tang dan vi no yeu cau lay toi da so luong chai
	*/
	for(int i = 0 ; i < n ;i++){
		for(int j = i ; j < n ; j++){
			if(s[j] < s[i]){
				int tmp = s[i] ; 
				s[i] = s[j] ;
				s[j] = tmp ;
			}
		}
	}
}

int F2(int x[] , int n, int d){
	/*
	ham nay thi tham lam thoi 
	*/
	sort(x,n);
	int p = 0 ;
	int i = 0;
	while(d >= x[i] && i < n){
		p += 1 ; 
		d -= x[i] ; 
		i++;
	}
	return p ;
}
void hienthi(int s[] , int n){
	for(int i = 0 ; i < n ; i++){
		cout << s[i] << " " ;
	}
	cout << endl ;
}

int main(){
	int n = 5 , d = 11 ; 
	int x[5] = {5,9,7,4,2};
	int p = F2(x,n,d);
	hienthi(x,n);
	cout << "So luong chai nuoc toi da duoc do day la :" << p << " chai!" << endl ;
}