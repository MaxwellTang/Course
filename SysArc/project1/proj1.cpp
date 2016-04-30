#include "disassembly.h"
#include "sim.h"
using namespace std;

int main()
{
	int option = 0;
	cout << "1.disassembly" << endl;
	cout << "2.simulation" << endl;
	cout << "please input number:" ;
	cin >> option;
	switch(option)
	{
	case 1:
	{
		Disassembly* disassembly = new Disassembly();
		disassembly->mkfile("sample.txt");
		delete disassembly;
		break;
	}
	case 2:
	{
		Sim* sim = new Sim();
		sim->mkfile("disassembly.txt");
		delete sim;	
		break;
	}
	default:
	{
		break;
	}
	}
}
