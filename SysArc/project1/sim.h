#ifndef SIM_H_
#define SIM_H_
#endif

#ifndef IOSTREAM_H_
#define IOSTREAM_H_
#include<iostream>
#endif

#ifndef FSTREAM_H_
#define FSTREAM_H_
#include<fstream>
#endif

#ifndef CSTDLIB_H_
#define CSTDLIB_H_
#include<cstdlib>
#endif

#ifndef STRING_H_
#define STRING_H_
#include<string>
#endif

#ifndef CSTRING_H_
#define CSTRING_H_
#include<cstring>
#endif

#ifndef MAP_H_
#define MAP_H_
#include<map>
#endif

#ifndef UTILITY_H_
#define UTILITY_H_
#include<utility>
#endif

#include<stdio.h>
#include<stdlib.h>
using namespace std;
struct dataDetail
{
	char ins[10];
	char op[20];
	char address[10];
	struct dataDetail* pfront;
	struct dataDetail* pnext;
};
struct status
{
	int reg[32];
	int mem[24];
};

class Sim
{
	private:
		int getmem(status* status,char* address);
		void setmem(status* status,char* address,int data);
                int getmem(status* status,int address);
                void setmem(status* status,int address,int data);

		void setreg(status* status,char* reg,int data);
		int getreg(status* status,char* reg);
		int getimm(char* imm);
		int stoi(char* str);
		int getoffset(char *str);

	public:
		void getdata(char* filepath,struct dataDetail* data);
		void runbycycle(struct dataDetail* data,int* pc,status* status);
		void mkfile(char* filepath);
		void initmem(dataDetail* data,status* status);
};
