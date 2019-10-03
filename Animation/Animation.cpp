#include "aAnimation1.h"
#include "aTriangleDemo.h"

int main() {
	cout << "Would you like to see 1(aAnimation1) or 2(aTriangleDemo): ";
	int choice = 1;
	cin >> choice;
	if (choice == 1) aAnimation1 main(5); 
	else if (choice == 2) aTriangleDemo main(5);
	system("pause");
	return 0;
}
