#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

void enter_package(double* weights, int size) {

for (int i = 0;  i < size; i++) {

cout << "enter weight of the package " <<  i + 1 << ": "; 
cin >> weights[i]; 



	while ( cin.fail() || weights[i] < 0) {
	cout << "Please enter a weight above zero!: "; 
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
	cin >> weights[i];
	}
} 

}

		
 
void display_packages(const double* weights, int size){

cout << "Product Weight Report\n";
	for (int i = 0; i < size; i++){
	cout << "your package " << i + 1 << " : " << weights[i] << " lbs\n"<< endl;
	}

} 

double calculate_total(double* weights, int size){
	double total = 0;
	for (int i  = 0; i < size; i++){
	total += weights[i];
	
	}
	return total; 
} 

double find_heaviest(const double* weights, int size) {
	int heaviest = 0; 

	for (int i = 0; i < size; i++) {
		if (weights[i] > weights[heaviest]) {
			heaviest = i;
		}
	}
	return heaviest;
	
} 

int main(){

	cout << "\nWelcome to the package weight program\n"; 
	int numPackages = 0; 

	
	
	while (numPackages <= 0){
	cout << "How packages will you be weighting?: \n";
	cin >> numPackages;

	if (numPackages <= 0) {
		cout << "you must enter a number above zero!\n";
		continue;
	}else {
	break;
	}
	}
	

	double* weights = new double[numPackages]{}; 

	enter_package(weights, numPackages); 
	display_packages(weights, numPackages); 
	int total = calculate_total(weights, numPackages);
	double avg = static_cast<double>(total) / numPackages; 
int heavy = find_heaviest(weights, numPackages); 

	cout << "\nWeight summary\n"; 

	cout << " Total packages: " << total << endl;
	
	cout << fixed << setprecision(2) << "average weight: " << avg << endl; 
	cout << "Heaviest: " << heavy + 1 << " : " << heavy[weights] << endl;

	delete[] weights;

	weights = nullptr; 

	cout << "deletion successful\n";
	
	
}
