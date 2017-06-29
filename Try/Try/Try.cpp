#include<iostream>
using namespace std;

int abc(int a, int b, int c) {
	if(a==0 && b ==0 && c ==0){
		throw "All parameters are 0";
	}
	return a + b * c;
}

int main() {
	try {
		cout << abc(0, 0, 0) << endl;
	}
	catch(char* e){
		cout << "The parameters are all 0";
		cout << e;
		system("pause");
		return 1;
	}
	
	return 0;
}