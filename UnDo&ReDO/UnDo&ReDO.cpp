#include <iostream>
#include "clsMyString.h"

using namespace std;

int main()
{
	clsMyString S1;
//cout<<	S1.Value;


	cout << "Value " << S1.Value << endl;
	S1.Value = "Maytham1";
	cout << "Value " << S1.Value << endl;
	S1.Value = "Maytham2";
	cout << "Value " << S1.Value << endl;
	S1.Value = "Maytham3";
	cout << "Value " << S1.Value << endl;

	S1.UnDo();
	cout << "Value aFter UnDo\n" << S1.Value << endl;
	S1.UnDo();
	cout << "Value aFter UnDo\n" << S1.Value << endl;

	S1.UnDo();
	cout << "Value aFter UnDo\n" << S1.Value << endl;


	S1.ReDo();
	cout << "Value aFter ReDo\n" << S1.Value << endl;
	S1.ReDo();
	cout << "Value aFter ReDo\n" << S1.Value << endl;

	S1.ReDo();
	cout << "Value aFter ReDo\n" << S1.Value << endl;

	

	system("pause >0");
	return 0;
}