#include <iostream>
using namespace std;

void check0(int x){
	if(x==0) throw(x);
}

int main(){
	int x,y,a;
	double d;
do{
	a=0;
try{
	int i;
	double* myarray;
	for(i=0; i<10000000; i++){
		cout<<"Allocating memory..."<<i<<endl;
		myarray = new double(500000000);
	}

	cout<<"Enter 2 numbers";
	cin>>x>>y;
	/*curated exception handling*/
	if(cin.fail()){
		throw("Incorrect type entered");
		//cerr<<"Incorrect type entered"; return 1;
	}
	if(abs(x)>1000 ||abs(y)>1000){
		throw("Value out of range");
		//cerr<<"alue out of range"; return 1;
	}
	check0(y);
	if (y==0) {
		throw("Error divide by zero");
		//cerr<< "Error divide by zero"; return 1;
	}

	/*normal code*/
	d=(double) x/y;
	cout<< "The result is" <<d<<endl;
}
catch(const char* error){ //จัดการ error
	cerr<<error<<endl;
	a=1;
	cin.clear();
	cin.ignore(50, '\n');
	//return -1;
}
catch(int e){
	switch(e){
		case 101: cerr<<"Incorrect numbers "<<endl; break;
		case 0: cerr<<"Divided by zero"<<endl; break;
	}
}
catch(...){//ไม่เข้ากรณีไหนเลย ทำให้ pass parameter ไม่ได้ จะไม่รู้ว่า error ชนิดอะไร
	cout<<"Memory leak!!"<<endl;
}
}while(a);
	return 0;
}