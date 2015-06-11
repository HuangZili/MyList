#include <iostream>
#include "MyList.h"

using namespace std;

int main(){
	MyList<int> a, b;
	int i;
	for (i=0; i<5; ++i)
		a.push(i);
    //a.display();
    // a = [0, 1, 2, 3, 4]
	a[3] = 15; // a = [0, 1, 2, 15, 4]
	//a.display();
	a.sort(); // a = [0, 1, 2, 4, 15]
	//a.display();
	a.reverse(); // a = [15, 4, 2, 1, 0]
	//a.display();
	a += 12; // a = [15, 4, 2, 1, 0, 12]
	//a.display();
	for (i=0; i<a.get_size(); ++i)
		cout<<a[i]<<endl;
    b = a.get_item(4, -3);// b = []
    //b.display();
	b = a.get_item(3, -1); // b = [1, 0, 12]
	//b.display();
	a += b; // a = [15, 4, 2, 1, 0, 12, 1, 0, 12]
	//a.display();
	for (i=0; i<a.get_size(); ++i)
		cout<<a.get_item(i)<<endl;
	cout<<a.count(5)<<endl;
	b.clean(); // b = []
	cout<<b.get_size()<<endl;
	a.erase(2, 5); // a = [15, 4, 1, 0, 12]
	b = a + a; // b = [15, 4, 1, 0, 12, 15, 4, 1, 0, 12]
	//b.display();
	b.insert(3, 116); // b = [15, 4, 1, 116, 0, 12, 15, 4, 1, 0, 12]
	b.remove(4); // b = [15, 1, 116, 0, 12, 15, 4, 1, 0, 12]
	cout<<b<<endl;
	MyList<double> c(10, 3.14);
	for (i=0; i<100; ++i)
		c.push(1.1*i);
	cout<<c.get_item(100, 105)<<endl;

	return 0;
}

