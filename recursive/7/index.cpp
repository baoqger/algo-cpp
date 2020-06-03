#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include <iostream> 
using namespace std; 

int fun(int count) 
{ 
	cout << count << endl; 
	if(count < 3) 
	{ 
		fun(fun(fun(++count))); 
	} 
	return count; 
} 

int main() 
{ 
	fun(1); 
	return 0; 
} 

// This code is contributed by Shubhamsingh10 
