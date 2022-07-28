#include<iostream>
using namespace std;

int fibonacci(int n){
	if(n>1) return fibonacci(n-1)+fibonacci(n-2);
	if(n==0) return 0;
	else if(n==1) return 1;
}
int main(){
	for(int i=2; i<15;i++){
		cout<<fibonacci(i)<<endl;	
	}
	return 0;
}
