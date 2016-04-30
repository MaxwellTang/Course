#include "disassembly.h"
using namespace std;

void Disassembly::getdata(char* filepath,struct Ins* instart){
	ifstream fin;
	int number;
	fin.open(filepath);
	char buf[128][32];
	struct Ins* tempins;
	tempins = instart;
	for(int flag=0,j=0;j<128;j++){
		for(int i=0;i<32;i++){
			fin >> buf[j][i];
			if(buf[j][i] == '0' || buf[j][i] == '1')	
			{
			}
			else
			{
				number = j;
				flag = 1;
			}
		}
		if(flag == 1){break;}
	}
	//transmit ins
	for(int i=0;i<number;i++)
	{
		tempins->address = 64 + i*4;
		memcpy(tempins->data,buf[i],32);
		if(i+1 < number){
			tempins->pnext = (struct Ins*)malloc(sizeof(struct Ins));
			tempins->pnext->pfront = tempins;
			tempins = tempins->pnext;
		}
	}	
	fin.close();
}

void Disassembly::getIns(struct Ins* instart){
	if(instart->data[0] == '0')
	{
		if(!memcmp(&instart->data[1],"00000",5))
		{
			if(!memcmp(&instart->data[26],"100010",6))
			{
				char rt[4];
				char rs[4];
				char rd[4];
				char poi = 0;
	
				memcpy(instart->name,"SUB",4);	
				bstr2int(&instart->data[6],5,rs);
				bstr2int(&instart->data[11],5,rt);
				bstr2int(&instart->data[16],5,rd);
				
				instart->op[poi]='R';
				poi++;
				for(int i=0;rd[i]!='\0';i++)
				{
					instart->op[poi]=rd[i];
					poi++;
				}
				instart->op[poi]=',';
				poi++;
				instart->op[poi]=' ';
				poi++;
				instart->op[poi]='R';
				poi++;
				for(int i=0;rs[i]!='\0';i++)
				{
					instart->op[poi]=rs[i];
					poi++;
				}
				instart->op[poi]=',';
				poi++;
				instart->op[poi]=' ';
				poi++;
				instart->op[poi]='R';
				poi++;
				for(int i=0;rt[i]!='\0';i++)
				{
					instart->op[poi]=rt[i];
					poi++;
				}
				instart->op[poi]='\0';
				poi++;
					
			}
			else if(!memcmp(&instart->data[26],"100000",6))
			{
				char rt[4];
				char rs[4];
				char rd[4];
				char poi = 0;
	
				memcpy(instart->name,"ADD",4);	
				bstr2int(&instart->data[6],5,rs);
				bstr2int(&instart->data[11],5,rt);
				bstr2int(&instart->data[16],5,rd);
				
				instart->op[poi]='R';
				poi++;
				for(int i=0;rd[i]!='\0';i++)
				{
					instart->op[poi]=rd[i];
					poi++;
				}
				instart->op[poi]=',';
				poi++;
				instart->op[poi]=' ';
				poi++;
				instart->op[poi]='R';
				poi++;
				for(int i=0;rs[i]!='\0';i++)
				{
					instart->op[poi]=rs[i];
					poi++;
				}
				instart->op[poi]=',';
				poi++;
				instart->op[poi]=' ';
				poi++;
				instart->op[poi]='R';
				poi++;
				for(int i=0;rt[i]!='\0';i++)
				{
					instart->op[poi]=rt[i];
					poi++;
				}
				instart->op[poi]='\0';
				poi++;
			}
			else if(!memcmp(&instart->data[26],"001000",6))
			{
				char rs[4];
				char poi = 0;

				memcpy(instart->name,"JR",4);	
				bstr2int(&instart->data[6],5,rs);

				instart->op[poi]='R';
				poi++;
				for(int i=0;rs[i]!='\0';i++)
				{
					instart->op[poi]=rs[i];
					poi++;
				}
				instart->op[poi]='\0';
				poi++;
			}
			else if(!memcmp(&instart->data[26],"000011",6))
			{
				char rt[4];
				char rs[4];
				char rd[4];
				char poi = 0;
				memcpy(instart->name,"SRA",4);	
				bstr2int(&instart->data[21],5,rs);
				bstr2int(&instart->data[11],5,rt);
				bstr2int(&instart->data[16],5,rd);
				
				instart->op[poi]='R';
				poi++;
				for(int i=0;rd[i]!='\0';i++)
				{
					instart->op[poi]=rd[i];
					poi++;
				}
				instart->op[poi]=',';
				poi++;
				instart->op[poi]=' ';
				poi++;
				instart->op[poi]='R';
				poi++;
				for(int i=0;rt[i]!='\0';i++)
				{
					instart->op[poi]=rs[i];
					poi++;
				}
				instart->op[poi]=',';
				poi++;
				instart->op[poi]=' ';
				poi++;
				instart->op[poi]='#';
				poi++;
				for(int i=0;rs[i]!='\0';i++)
				{
					instart->op[poi]=rt[i];
					poi++;
				}
				instart->op[poi]='\0';
				poi++;
			}
			else if(!memcmp(&instart->data[26],"000010",6))
			{
				char rt[4];
				char rs[4];
				char rd[4];
				char poi = 0;
				memcpy(instart->name,"SRL",4);	
				bstr2int(&instart->data[21],5,rs);
				bstr2int(&instart->data[11],5,rt);
				bstr2int(&instart->data[16],5,rd);
				
				instart->op[poi]='R';
				poi++;
				for(int i=0;rd[i]!='\0';i++)
				{
					instart->op[poi]=rd[i];
					poi++;
				}
				instart->op[poi]=',';
				poi++;
				instart->op[poi]=' ';
				poi++;
				instart->op[poi]='R';
				poi++;
				for(int i=0;rt[i]!='\0';i++)
				{
					instart->op[poi]=rs[i];
					poi++;
				}
				instart->op[poi]=',';
				poi++;
				instart->op[poi]=' ';
				poi++;
				instart->op[poi]='#';
				poi++;
				for(int i=0;rs[i]!='\0';i++)
				{
					instart->op[poi]=rt[i];
					poi++;
				}
				instart->op[poi]='\0';
				poi++;
			}
			else if(!memcmp(&instart->data[26],"000000",6))
			{
				if(!memcmp(instart->data,"00000000000000000000000000000000",32))
				{
					memcpy(instart->name,"NOP",4);
				}	
				else{
				char rt[4];
				char rs[4];
				char rd[4];
				char poi = 0;
				memcpy(instart->name,"SLL",4);
				bstr2int(&instart->data[21],5,rs);
				bstr2int(&instart->data[11],5,rt);
				bstr2int(&instart->data[16],5,rd);
				
				instart->op[poi]='R';
				poi++;
				for(int i=0;rd[i]!='\0';i++)
				{
					instart->op[poi]=rd[i];
					poi++;
				}
				instart->op[poi]=',';
				poi++;
				instart->op[poi]=' ';
				poi++;
				instart->op[poi]='R';
				poi++;
				for(int i=0;rt[i]!='\0';i++)
				{
					instart->op[poi]=rt[i];
					poi++;
				}
				instart->op[poi]=',';
				poi++;
				instart->op[poi]=' ';
				poi++;
				instart->op[poi]='#';
				poi++;
				for(int i=0;rs[i]!='\0';i++)
				{
					instart->op[poi]=rs[i];
					poi++;
				}
				instart->op[poi]='\0';
				poi++;
				}
			}
			else if(!memcmp(&instart->data[26],"101010",6))
			{
				char rt[4];
				char rs[4];
				char rd[4];
				char poi = 0;
				memcpy(instart->name,"SLT",4);	
				bstr2int(&instart->data[6],5,rs);
				bstr2int(&instart->data[11],5,rt);
				bstr2int(&instart->data[16],5,rd);
				
				instart->op[poi]='R';
				poi++;
				for(int i=0;rd[i]!='\0';i++)
				{
					instart->op[poi]=rd[i];
					poi++;
				}
				instart->op[poi]=',';
				poi++;
				instart->op[poi]=' ';
				poi++;
				instart->op[poi]='R';
				poi++;
				for(int i=0;rs[i]!='\0';i++)
				{
					instart->op[poi]=rs[i];
					poi++;
				}
				instart->op[poi]=',';
				poi++;
				instart->op[poi]=' ';
				poi++;
				instart->op[poi]='R';
				poi++;
				for(int i=0;rt[i]!='\0';i++)
				{
					instart->op[poi]=rt[i];
					poi++;
				}
				instart->op[poi]='\0';
				poi++;
			}
			else if(!memcmp(&instart->data[26],"100100",6))
			{
				char rt[4];
				char rs[4];
				char rd[4];
				char poi = 0;
				memcpy(instart->name,"AND",4);	
				bstr2int(&instart->data[6],5,rs);
				bstr2int(&instart->data[11],5,rt);
				bstr2int(&instart->data[16],5,rd);
				
				instart->op[poi]='R';
				poi++;
				for(int i=0;rd[i]!='\0';i++)
				{
					instart->op[poi]=rd[i];
					poi++;
				}
				instart->op[poi]=',';
				poi++;
				instart->op[poi]=' ';
				poi++;
				instart->op[poi]='R';
				poi++;
				for(int i=0;rs[i]!='\0';i++)
				{
					instart->op[poi]=rs[i];
					poi++;
				}
				instart->op[poi]=',';
				poi++;
				instart->op[poi]=' ';
				poi++;
				instart->op[poi]='R';
				poi++;
				for(int i=0;rt[i]!='\0';i++)
				{
					instart->op[poi]=rt[i];
					poi++;
				}
				instart->op[poi]='\0';
				poi++;
			}
			else if(!memcmp(&instart->data[26],"100111",6))
			{
				char rt[4];
				char rs[4];
				char rd[4];
				char poi = 0;
				memcpy(instart->name,"NOR",4);	
				bstr2int(&instart->data[6],5,rs);
				bstr2int(&instart->data[11],5,rt);
				bstr2int(&instart->data[16],5,rd);
				
				instart->op[poi]='R';
				poi++;
				for(int i=0;rd[i]!='\0';i++)
				{
					instart->op[poi]=rd[i];
					poi++;
				}
				instart->op[poi]=',';
				poi++;
				instart->op[poi]=' ';
				poi++;
				instart->op[poi]='R';
				poi++;
				for(int i=0;rs[i]!='\0';i++)
				{
					instart->op[poi]=rs[i];
					poi++;
				}
				instart->op[poi]=',';
				poi++;
				instart->op[poi]=' ';
				poi++;
				instart->op[poi]='R';
				poi++;
				for(int i=0;rt[i]!='\0';i++)
				{
					instart->op[poi]=rt[i];
					poi++;
				}
				instart->op[poi]='\0';
				poi++;
			}
			else if(!memcmp(&instart->data[26],"001101",6))
			{
				memcpy(instart->name,"BREAK",6);	
			}
			else
			{
				memcpy(instart->name,"NULL",5);	
			}
			
		}
		else if(!memcmp(&instart->data[1],"11100",5))
		{
			if(!memcmp(&instart->data[26],"000010",6))
			{
				char rt[4];
				char rs[4];
				char rd[4];
				char poi = 0;
				memcpy(instart->name,"MUL",4);	
				bstr2int(&instart->data[6],5,rs);
				bstr2int(&instart->data[11],5,rt);
				bstr2int(&instart->data[16],5,rd);
				
				instart->op[poi]='R';
				poi++;
				for(int i=0;rd[i]!='\0';i++)
				{
					instart->op[poi]=rd[i];
					poi++;
				}
				instart->op[poi]=',';
				poi++;
				instart->op[poi]=' ';
				poi++;
				instart->op[poi]='R';
				poi++;
				for(int i=0;rs[i]!='\0';i++)
				{
					instart->op[poi]=rs[i];
					poi++;
				}
				instart->op[poi]=',';
				poi++;
				instart->op[poi]=' ';
				poi++;
				instart->op[poi]='R';
				poi++;
				for(int i=0;rt[i]!='\0';i++)
				{
					instart->op[poi]=rt[i];
					poi++;
				}
				instart->op[poi]='\0';
				poi++;
			}
			else
			{
				memcpy(instart->name,"NULL",5);	
			}
		}
		else if(!memcmp(&instart->data[1],"00111",5))
		{
			char rs[4];
			char offset[10];
			char poi=0;
			char data[18];
			for(int i=0;i<18;i++)
			{
				if(i<16)data[i]=instart->data[16+i];
				else data[i]='0';
			}
			memcpy(instart->name,"BGTZ",5);	
			bstr2int(&instart->data[6],5,rs);
			bstr2int(data,18,offset);
			
			instart->op[poi]='R';
			poi++;
			for(int i=0;rs[i]!='\0';i++)
			{
				instart->op[poi]=rs[i];
				poi++;
			}
			instart->op[poi]=',';
			poi++;
			instart->op[poi]=' ';
			poi++;
			instart->op[poi]='#';
			poi++;
			for(int i=0;offset[i]!='\0';i++)
			{
				instart->op[poi]=offset[i];
				poi++;
			}
			instart->op[poi]='\0';
		}
		else if(!memcmp(&instart->data[1],"00100",5))
		{
			char rs[4];
			char rt[4];
			char offset[10];
			char poi=0;
			char data[18];
			for(int i=0;i<18;i++)
			{
				if(i<16)data[i]=instart->data[16+i];
				else data[i]='0';
			}
			memcpy(instart->name,"BEQ",4);	
			bstr2int(&instart->data[6],5,rs);
			bstr2int(&instart->data[11],5,rt);
			bstr2int(data,18,offset);
			
			instart->op[poi]='R';
			poi++;
			for(int i=0;rs[i]!='\0';i++)
			{
				instart->op[poi]=rs[i];
				poi++;
			}
			instart->op[poi]=',';
			poi++;
			instart->op[poi]=' ';
			poi++;
			instart->op[poi]='R';
			poi++;
			for(int i=0;rt[i]!='\0';i++)
			{
				instart->op[poi]=rt[i];
				poi++;
			}
			instart->op[poi]=',';
			poi++;
			instart->op[poi]=' ';
			poi++;
			instart->op[poi]='#';
			poi++;
			for(int i=0;offset[i]!='\0';i++)
			{
				instart->op[poi]=offset[i];
				poi++;
			}
			instart->op[poi]='\0';
			
		}
		else if(!memcmp(&instart->data[1],"00010",5))
		{
			char offset[10];
			char poi=0;
			char data[18];
			for(int i=0;i<18;i++)
			{
				if(i<16)data[i]=instart->data[16+i];
				else data[i]='0';
			}
			memcpy(instart->name,"J",2);	
			bstr2int(data,18,offset);
			instart->op[poi]='#';
			poi++;
			for(int i=0;offset[i]!='\0';i++)
			{
				instart->op[poi]=offset[i];
				poi++;
			}
			instart->op[poi]='\0';
			
		}
		else if(!memcmp(&instart->data[1],"00001",5))
		{
			char rs[4];
			char offset[10];
			char poi=0;
			char data[18];
			for(int i=0;i<18;i++)
			{
				if(i<16)data[i]=instart->data[16+i];
				else data[i]='0';
			}
			memcpy(instart->name,"BLTZ",5);	
			bstr2int(&instart->data[6],5,rs);
			bstr2int(data,18,offset);
			
			instart->op[poi]='R';
			poi++;
			for(int i=0;rs[i]!='\0';i++)
			{
				instart->op[poi]=rs[i];
				poi++;
			}
			instart->op[poi]=',';
			poi++;
			instart->op[poi]=' ';
			poi++;
			instart->op[poi]='#';
			poi++;
			for(int i=0;offset[i]!='\0';i++)
			{
				instart->op[poi]=offset[i];
				poi++;
			}
			instart->op[poi]='\0';
		}
		else
		{
			memcpy(instart->name,"NULL",5);	
		}
	}
	else
	{
		if(!memcmp(&instart->data[1],"10000",5))
		{
			char rs[4];
			char rt[4];
			char offset[10];
			char poi=0;
			char data[18];
			memcpy(instart->name,"ADD",4);	
			bstr2int(&instart->data[6],5,rs);
			bstr2int(&instart->data[11],5,rt);
			bstr2int(&instart->data[16],16,offset);
			
			instart->op[poi]='R';
			poi++;
			for(int i=0;rt[i]!='\0';i++)
			{
				instart->op[poi]=rt[i];
				poi++;
			}
			instart->op[poi]=',';
			poi++;
			instart->op[poi]=' ';
			poi++;
			instart->op[poi]='R';
			poi++;
			for(int i=0;rs[i]!='\0';i++)
			{
				instart->op[poi]=rs[i];
				poi++;
			}
			instart->op[poi]=',';
			poi++;
			instart->op[poi]=' ';
			poi++;
			instart->op[poi]='#';
			poi++;
			for(int i=0;offset[i]!='\0';i++)
			{
				instart->op[poi]=offset[i];
				poi++;
			}
			instart->op[poi]='\0';
			
		}
		else if(!memcmp(&instart->data[1],"10001",5))
		{
			char rs[4];
			char rt[4];
			char offset[10];
			char poi=0;
			char data[18];
			memcpy(instart->name,"SUB",4);	
			bstr2int(&instart->data[6],5,rs);
			bstr2int(&instart->data[11],5,rt);
			bstr2int(&instart->data[16],16,offset);
			
			instart->op[poi]='R';
			poi++;
			for(int i=0;rt[i]!='\0';i++)
			{
				instart->op[poi]=rt[i];
				poi++;
			}
			instart->op[poi]=',';
			poi++;
			instart->op[poi]=' ';
			poi++;
			instart->op[poi]='R';
			poi++;
			for(int i=0;rs[i]!='\0';i++)
			{
				instart->op[poi]=rs[i];
				poi++;
			}
			instart->op[poi]=',';
			poi++;
			instart->op[poi]=' ';
			poi++;
			instart->op[poi]='#';
			poi++;
			for(int i=0;offset[i]!='\0';i++)
			{
				instart->op[poi]=offset[i];
				poi++;
			}
			instart->op[poi]='\0';
			
		}
		else if(!memcmp(&instart->data[1],"00001",5))
		{
			char rs[4];
			char rt[4];
			char offset[10];
			char poi=0;
			char data[18];
			memcpy(instart->name,"MUL",4);	
			bstr2int(&instart->data[6],5,rs);
			bstr2int(&instart->data[11],5,rt);
			bstr2int(&instart->data[16],16,offset);
			
			instart->op[poi]='R';
			poi++;
			for(int i=0;rt[i]!='\0';i++)
			{
				instart->op[poi]=rt[i];
				poi++;
			}
			instart->op[poi]=',';
			poi++;
			instart->op[poi]=' ';
			poi++;
			instart->op[poi]='R';
			poi++;
			for(int i=0;rs[i]!='\0';i++)
			{
				instart->op[poi]=rs[i];
				poi++;
			}
			instart->op[poi]=',';
			poi++;
			instart->op[poi]=' ';
			poi++;
			instart->op[poi]='#';
			poi++;
			for(int i=0;offset[i]!='\0';i++)
			{
				instart->op[poi]=offset[i];
				poi++;
			}
			instart->op[poi]='\0';
			
		}
		else if(!memcmp(&instart->data[1],"10010",5))
		{
			char rs[4];
			char rt[4];
			char offset[10];
			char poi=0;
			char data[18];
			memcpy(instart->name,"AND",4);	
			bstr2int(&instart->data[6],5,rs);
			bstr2int(&instart->data[11],5,rt);
			bstr2int(&instart->data[16],16,offset);
			
			instart->op[poi]='R';
			poi++;
			for(int i=0;rt[i]!='\0';i++)
			{
				instart->op[poi]=rt[i];
				poi++;
			}
			instart->op[poi]=',';
			poi++;
			instart->op[poi]=' ';
			poi++;
			instart->op[poi]='R';
			poi++;
			for(int i=0;rs[i]!='\0';i++)
			{
				instart->op[poi]=rs[i];
				poi++;
			}
			instart->op[poi]=',';
			poi++;
			instart->op[poi]=' ';
			poi++;
			instart->op[poi]='#';
			poi++;
			for(int i=0;offset[i]!='\0';i++)
			{
				instart->op[poi]=offset[i];
				poi++;
			}
			instart->op[poi]='\0';
			
		}
		else if(!memcmp(&instart->data[1],"10011",5))
		{
			char rs[4];
			char rt[4];
			char offset[10];
			char poi=0;
			char data[18];
			memcpy(instart->name,"NOR",4);	
			bstr2int(&instart->data[6],5,rs);
			bstr2int(&instart->data[11],5,rt);
			bstr2int(&instart->data[16],16,offset);
			
			instart->op[poi]='R';
			poi++;
			for(int i=0;rt[i]!='\0';i++)
			{
				instart->op[poi]=rt[i];
				poi++;
			}
			instart->op[poi]=',';
			poi++;
			instart->op[poi]=' ';
			poi++;
			instart->op[poi]='R';
			poi++;
			for(int i=0;rs[i]!='\0';i++)
			{
				instart->op[poi]=rs[i];
				poi++;
			}
			instart->op[poi]=',';
			poi++;
			instart->op[poi]=' ';
			poi++;
			instart->op[poi]='#';
			poi++;
			for(int i=0;offset[i]!='\0';i++)
			{
				instart->op[poi]=offset[i];
				poi++;
			}
			instart->op[poi]='\0';
			
		}
		else if(!memcmp(&instart->data[1],"10101",5))
		{
			char rs[4];
			char rt[4];
			char offset[10];
			char poi=0;
			char data[18];
			memcpy(instart->name,"SLT",4);	
			bstr2int(&instart->data[6],5,rs);
			bstr2int(&instart->data[11],5,rt);
			bstr2int(&instart->data[16],16,offset);
			
			instart->op[poi]='R';
			poi++;
			for(int i=0;rt[i]!='\0';i++)
			{
				instart->op[poi]=rt[i];
				poi++;
			}
			instart->op[poi]=',';
			poi++;
			instart->op[poi]=' ';
			poi++;
			instart->op[poi]='R';
			poi++;
			for(int i=0;rs[i]!='\0';i++)
			{
				instart->op[poi]=rs[i];
				poi++;
			}
			instart->op[poi]=',';
			poi++;
			instart->op[poi]=' ';
			poi++;
			instart->op[poi]='#';
			poi++;
			for(int i=0;offset[i]!='\0';i++)
			{
				instart->op[poi]=offset[i];
				poi++;
			}
			instart->op[poi]='\0';
			
		}
		else if(!memcmp(&instart->data[1],"01011",5))
		{
			char rs[4];
			char rt[4];
			char offset[10];
			char poi=0;
			char data[18];
			memcpy(instart->name,"SW",3);	
			bstr2int(&instart->data[6],5,rs);
			bstr2int(&instart->data[11],5,rt);
			bstr2int(&instart->data[16],16,offset);
			
			instart->op[poi]='R';
			poi++;
			for(int i=0;rt[i]!='\0';i++)
			{
				instart->op[poi]=rt[i];
				poi++;
			}
			instart->op[poi]=',';
			poi++;
			instart->op[poi]=' ';
			poi++;
			for(int i=0;offset[i]!='\0';i++)
			{
				instart->op[poi]=offset[i];
				poi++;
			}
			instart->op[poi]='(';
			poi++;
			instart->op[poi]='R';
			poi++;
			for(int i=0;rs[i]!='\0';i++)
			{
				instart->op[poi]=rs[i];
				poi++;
			}
			instart->op[poi]=')';
			poi++;
			instart->op[poi]='\0';
		}
		else if(!memcmp(&instart->data[1],"00011",5))
		{
			char rs[4];
			char rt[4];
			char offset[10];
			char poi=0;
			char data[18];
			memcpy(instart->name,"LW",3);	
			bstr2int(&instart->data[6],5,rs);
			bstr2int(&instart->data[11],5,rt);
			bstr2int(&instart->data[16],16,offset);
			
			instart->op[poi]='R';
			poi++;
			for(int i=0;rt[i]!='\0';i++)
			{
				instart->op[poi]=rt[i];
				poi++;
			}
			instart->op[poi]=',';
			poi++;
			instart->op[poi]=' ';
			poi++;
			for(int i=0;offset[i]!='\0';i++)
			{
				instart->op[poi]=offset[i];
				poi++;
			}
			instart->op[poi]='(';
			poi++;
			instart->op[poi]='R';
			poi++;
			for(int i=0;rs[i]!='\0';i++)
			{
				instart->op[poi]=rs[i];
				poi++;
			}
			instart->op[poi]=')';
			poi++;
			instart->op[poi]='\0';
			
		}
		else 
		{
			memcpy(instart->name,"NULL",5);	
		}
	}
}

void Disassembly::mkfile(char* filepath){
        struct Ins* ins = (struct Ins*) malloc(sizeof(struct Ins));
        struct Ins* tempIns;
	ofstream fin;
	int flag = 0;
	char intstr[10];
	fin.open("disassembly.txt");
	getdata(filepath,ins);
        tempIns = ins;
        while(1)
        {
		if(!flag){
			for(int i=0;i<6;i++)
			{
				fin << tempIns->data[i];
			}
			fin << ' ';
			for(int i=6;i<11;i++)
			{
				fin << tempIns->data[i];
			}
			fin << ' ';
			for(int i=11;i<16;i++)
			{
				fin << tempIns->data[i];
			}
			fin << ' ';
			for(int i=16;i<21;i++)
			{
				fin << tempIns->data[i];
			}
			fin << ' ';
			for(int i=21;i<26;i++)
			{
				fin << tempIns->data[i];
			}
			fin << ' ';
			for(int i=26;i<32;i++)
			{
				fin << tempIns->data[i];
			}
			getIns(tempIns);
			fin << '\t';
			fin << tempIns->address << '\t';
			fin << tempIns->name; 
			if(!memcmp(tempIns->name,"BREAK",5))
			{
				flag = 1;
				fin << '\n';
			}
			else{
				fin << ' ' << tempIns->op <<'\n';
			}
			if(tempIns->pnext != NULL)tempIns = tempIns->pnext;
			else break;
		}
		else if(flag == 1)
		{
			for(int i=0;i<32;i++)
			{
				fin << tempIns->data[i];
			}
			getIns(tempIns);
			fin << '\t';
			fin << tempIns->address << '\t';
			if(bstr2sint(tempIns->data,32,intstr))
			{
				fin << '-' << intstr << '\n';
			}	
			else
			{
				fin << intstr << '\n';
			}
			if(tempIns->pnext != NULL)tempIns = tempIns->pnext;
			else break;
		}
        }
	while(fin.is_open())
	{
		fin.close();
	}
        tempIns = ins;
	while(tempIns->pnext != NULL)
	{
		tempIns = tempIns->pnext;
		free(tempIns->pfront);
	}
	free(tempIns);
	return;
}

int Disassembly::bstr2int(char* data,int size_data,char* intstr)
{
	int temp = 0;
	for(int i=1;i<=size_data;i++)
	{
		temp += ((data[i-1] - 0x30)*(1<<(size_data-i)));
	}

	int i = 0;
	do
	{
		intstr[i] = (temp%10) + 0x30;
		temp = temp/10;
		i++;
	}while(temp != 0);
	intstr[i] = '\0';

	if(i%2 && i!=1)
	{
		int m,n,temp;
		m = 0;
		n = i - 1;
		while(m!=n)
		{
			temp = intstr[m];
			intstr[m] = intstr[n];
			intstr[n] = temp;
			m++;
			n--;
		}
	}
	else if(i!=1)
	{
		int m,n,temp;
		m = 0;
		n = i - 1;
		while(m<n)
		{
			temp = intstr[m];
			intstr[m] = intstr[n];
			intstr[n] = temp;
			m++;
			n--;
		}
	}
	return temp;
}

int Disassembly::bstr2sint(char* data,int size_data,char* intstr)
{
	int temp = 0;
	int flag = 0;
	if(data[0] == '1')
	{
		flag = 1;
		for(int i=0;i<size_data;i++)
		{
			if(data[i] == '1') data[i] = '0';
			else data[i] = '1';
		}
	}
	for(int i=1;i<=size_data;i++)
	{
		temp += ((data[i-1] - 0x30) << (size_data-i));
	}

	if(flag == 1)
	{
		temp ++;
	}

	int i = 0;
	do
	{
		intstr[i] = (temp%10) + 0x30;
		temp = temp/10;
		i++;
	}while(temp != 0);
	intstr[i] = '\0';

	if(i%2 && i!=1)
	{
		int m,n,temp;
		m = 0;
		n = i - 1;
		while(m==n)
		{
			temp = intstr[m];
			intstr[m] = intstr[n];
			intstr[n] = temp;
			m++;
			n--;
		}
	}
	else if(i!=1)
	{
		int m,n,temp;
		m = 0;
		n = i - 1;
		while(m<n)
		{
			temp = intstr[m];
			intstr[m] = intstr[n];
			intstr[n] = temp;
			m++;
			n--;
		}
	}
	return flag;
}
