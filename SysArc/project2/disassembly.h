#ifndef DISASSEMBLY_H_
#define DISASSEMBLY_H_
#endif

#ifndef IOSTREAM_H_
#include<iostream>
#endif

#ifndef FSTREAM_H_
#include<fstream>
#endif

#ifndef CSTDLIB_H_
#include<cstdlib>
#endif

#ifndef STRING_H_
#include<string>
#endif

#ifndef CSTRING_H_
#include<cstring>
#endif

using namespace std;

struct Ins{
	struct Ins * pfront = NULL;
	char data[32];
	char name[10];
	char op[20];
	int address;
	struct Ins * pnext = NULL;
};
 	
class Disassembly
{
	private:
		int bstr2int(char* data,int size_data,char* intstr);	
		int bstr2sint(char* data,int size_data,char* intstr);	
	public:
		void getdata(char* filepath,struct Ins* instart);
		void getIns(struct Ins* instart);
		void mkfile(char* filepath);	
};
