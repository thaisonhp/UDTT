#include<iostream>
#include<vector>
using namespace std ;

struct congviec{
	double start ; 
	double finish ;
};

void sort(double s[],int n){
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
 
void hienthi(vector <double>s , int n){
	for(int i = 0 ; i < s.size() ; i++){
		cout << s[i] << endl ;
	}
	cout << endl ;
}

void print_mang(double s[] ,int n){
	for(int i = 0 ; i < n ; i++){
		cout << s[i] << " ";
	}
	cout << endl ;
}

vector<double> F3(vector <double> &schedule , double s[] , double f[], int n){
	sort(s,n);
	sort(f,n);
	double last_finish = 0 ;
	for(int i = 0 ; i < n ;i++){
		if(s[i] >= last_finish){
			schedule.push_back(i) ; 
			last_finish = f[i] ;
		}
	}
	return schedule ;
}

int main(){
	vector <double> schedule;
	int n = 5 ; 
	double S[5] = {8,9,10,11,12}; 
	double F[5] = {8.5,11,11.5,12.5,13};
	F3(schedule,S,F,n);
	
	double result[5] =  {0,0,0,0,0};
	for(int i = 0 ; i < schedule.size();i++){
		result[int(schedule[i])] = 1 ;
	}
//	hienthi(schedule,schedule.size());
	print_mang(result,n);
	
}