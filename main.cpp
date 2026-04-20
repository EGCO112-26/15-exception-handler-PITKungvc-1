#include <iostream>
#include <exception>
#include <stdexcept>
#include <limits>
#include <cstdlib>
using namespace std;

class DivByZero : public exception {
public:
    const char* what() const noexcept override {
        return "Division by zero";
    }
};

class InvalidInput : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid input";
    }
};

// Unused code commented out
/*
void check0(int x){
	if(x==0) throw(x);
}
*/

int main(){
	int x,y;
	double d;
	bool valid = false;
	do{
		try{
			// Simulate standard exception with new double[] multiple times
			for(int i=0; i<100; i++){  // Reduced to avoid excessive allocation
				double* myarray = new double[1000000];
				delete[] myarray;  // Clean up
			}

			cout<<"Enter 2 numbers: ";
			cin>>x>>y;
			if(cin.fail()){
				throw InvalidInput();
			}
			if(abs(x)>10000 || abs(y)>10000){
				throw out_of_range("Value out of range (-10000 to 10000)");
			}
			if(y==0){
				throw DivByZero();
			}

			d = static_cast<double>(x) / y;
			cout << "The result is " << d << endl;
			valid = true;
		}
		catch(const InvalidInput& e){
			cerr << e.what() << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		catch(const DivByZero& e){
			cerr << e.what() << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		catch(const out_of_range& e){
			cerr << e.what() << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		catch(const bad_alloc& e){
			cerr << "Memory allocation failed: " << e.what() << endl;
			valid = true;  // Exit on memory error
		}
		catch(...){
			cerr << "Unknown error" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}while(!valid);
	return 0;
}