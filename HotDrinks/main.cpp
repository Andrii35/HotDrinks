#include"drinks.h"

int main() {

	Mashine drinks(1000,100,1000,1000,100);
	map<string, int>admin{ {"admin",1111 } };

	Menu(drinks, admin);
	
	system("pause");
}