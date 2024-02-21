// C++ Program to Demonstrate the Functioning of Enumerators 
// with an Example of Year 
#include <bits/stdc++.h> 
using namespace std; 

// Defining enum Year 
enum year { 
	Jan=1, 
	Feb, 
	Mar, 
	Apr, 
	May, 
	Jun, 
	Jul, 
	Aug, 
	Sep, 
	Oct, 
	Nov, 
	Dec 
}; 

// Driver Code 
int main() 
{ 
	int i; 

	// Traversing the year enum 
	for (i = Jan; i <= Dec; i++) 
		cout << i << " "; 

	return 0; 
}

