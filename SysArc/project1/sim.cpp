#include "sim.h"
using namespace std;

void Sim::getdata(char* filepath,struct dataDetail* data)
{
	ifstream fin;
	fin.open(filepath);
	char ch;
	char cstr[20];
	int i;
	char flag=0;
	struct dataDetail* temp; 
	temp = data;

	while(ch != EOF)
	{
		ch = fin.get();
		if(ch == '\t' && flag == 0)
		{
			ch = '0';
			for(i=0;(ch >='0') && (ch <= '9');i++)
			{
				ch = fin.get();
				cstr[i] = ch;	
			}
			memcpy(temp->address,cstr,i);
			ch = 'A';
			for(i=0;(ch >='A') && (ch <= 'Z');i++)
			{
				ch = fin.get();
				cstr[i] = ch;	
			}
			memcpy(temp->ins,cstr,i);
			if(!memcmp(temp->ins,"BREAK",5)) 
			{
				flag = 1;
			}
			else
			{
				fin.getline(cstr,20,'\n');
				memcpy(temp->op,cstr,fin.gcount());
			}
			temp->pnext = (struct dataDetail*)malloc(sizeof(struct dataDetail));
			temp->pnext->pfront = temp;
			temp = temp->pnext;
		}else if(ch == '\t' && flag == 1)
		{
			ch = '0';
			for(i=0;(ch >='0') && (ch <= '9');i++)
			{
				ch = fin.get();
				cstr[i] = ch;	
			}
			memcpy(temp->address,cstr,i);
			fin.getline(cstr,20,'\n');
			memcpy(temp->op,cstr,fin.gcount());
			temp->pnext = (struct dataDetail*)malloc(sizeof(struct dataDetail));
			temp->pnext->pfront = temp;
			temp = temp->pnext;
		}

	}
fin.close();
}

void Sim::runbycycle(struct dataDetail* data,int* pc,status* status)
{
	dataDetail* temp;
	int flag = 0;
	temp = data;
	while(atoi(temp->address) != *pc && temp->pnext != NULL)
	{
		temp = temp->pnext;
	}
	if(!memcmp(temp->ins,"ADD",3))
	{
		for(int i=0;temp->op[i]!='\0';i++)
		{
			if(temp->op[i]=='#')
			{
				flag = 1;
			}
		}
		if(flag==1)
		{
			int rs,rt,imm;
			rs = getreg(status,&temp->op[2]);
			imm = getimm(temp->op);
			rt = rs + imm;
			setreg(status,temp->op,rt);	
		}
		else
		{
			int rs,rt,rd;
			rs = getreg(status,&temp->op[2]);
			rt = getreg(status,&temp->op[7]);
			rd = rs + rt;
			setreg(status,temp->op,rd);
		}	
	}
	else if(!memcmp(temp->ins,"SUB",3))
	{
		for(int i=0;temp->op[i]!='\0';i++)
                {
                        if(temp->op[i]=='#')
                        {
                                flag = 1;
                        }
                }
                if(flag==1)
                {
                        int rs,rt,imm;
                        rs = getreg(status,&temp->op[2]);
                        imm = getimm(temp->op);
                        rt = rs - imm;
                        setreg(status,temp->op,rt);
                }
                else
                {
                        int rs,rt,rd;
                        rs = getreg(status,&temp->op[2]);
                        rt = getreg(status,&temp->op[7]);
                        rd = rs - rt;
                        setreg(status,temp->op,rd);
                }

	}
	else if(!memcmp(temp->ins,"MUL",3))
	{
		for(int i=0;temp->op[i]!='\0';i++)
                {
                        if(temp->op[i]=='#')
                        {
                                flag = 1;
                        }
                }
                if(flag==1)
                {
                        int rs,rt,imm;
                        rs = getreg(status,&temp->op[2]);
                        imm = getimm(temp->op);
                        rt = rs * imm;
                        setreg(status,temp->op,rt);
                }
                else
                {
                        int rs,rt,rd;
                        rs = getreg(status,&temp->op[2]);
                        rt = getreg(status,&temp->op[7]);
                        rd = rs * rt;
                        setreg(status,temp->op,rd);
                }

	}
	else if(!memcmp(temp->ins,"AND",3))
	{
		for(int i=0;temp->op[i]!='\0';i++)
                {
                        if(temp->op[i]=='#')
                        {
                                flag = 1;
                        }
                }
                if(flag==1)
                {
                        int rs,rt,imm;
                        rs = getreg(status,&temp->op[2]);
                        imm = getimm(temp->op);
                        rt = rs & imm;
                        setreg(status,temp->op,rt);
                }
                else
                {
                        int rs,rt,rd;
                        rs = getreg(status,&temp->op[2]);
                        rt = getreg(status,&temp->op[7]);
                        rd = rs & rt;
                        setreg(status,temp->op,rd);
                }

	}
	else if(!memcmp(temp->ins,"NOR",3))
	{
		for(int i=0;temp->op[i]!='\0';i++)
                {
                        if(temp->op[i]=='#')
                        {
                                flag = 1;
                        }
                }
                if(flag==1)
                {
                        int rs,rt,imm;
                        rs = getreg(status,&temp->op[2]);
                        imm = getimm(temp->op);
                        rt =~(rs | imm);
                        setreg(status,temp->op,rt);
                }
                else
                {
                        int rs,rt,rd;
                        rs = getreg(status,&temp->op[2]);
                        rt = getreg(status,&temp->op[7]);
                        rd =~(rs | rt);
                        setreg(status,temp->op,rd);
                }

	}
	else if(!memcmp(temp->ins,"SLT",3))
	{
		for(int i=0;temp->op[i]!='\0';i++)
                {
                        if(temp->op[i]=='#')
                        {
                                flag = 1;
                        }
                }
                if(flag==1)
                {
                        int rs,rt,imm;
                        rs = getreg(status,&temp->op[2]);
                        imm = getimm(temp->op);
                        rt = rs < imm;
                        setreg(status,temp->op,rt);
                }
                else
                {
                        int rs,rt,rd;
                        rs = getreg(status,&temp->op[2]);
                        rt = getreg(status,&temp->op[7]);
                        rd = rs < rt;
                        setreg(status,temp->op,rd);
                }

	}
	else if(!memcmp(temp->ins,"SLL",3))
	{
		for(int i=0;temp->op[i]!='\0';i++)
                {
                        if(temp->op[i]=='#')
                        {
                                flag = 1;
                        }
                }
                if(flag==1)
                {
                        unsigned int rd,rt,imm;
                        rt = getreg(status,&temp->op[2]);
                        imm = getimm(temp->op);
                        rd = rt << imm;
                        setreg(status,temp->op,rd);
                }
                else
                {
                        unsigned int sa,rt,rd;
                        sa = getreg(status,&temp->op[7]);
                        rt = getreg(status,&temp->op[2]);
                        rd = rt << sa;
                        setreg(status,temp->op,rd);
                }

	}
	else if(!memcmp(temp->ins,"SRL",3))
	{
		for(int i=0;temp->op[i]!='\0';i++)
                {
                        if(temp->op[i]=='#')
                        {
                                flag = 1;
                        }
                }
                if(flag==1)
                {
                        unsigned int rd,rt,imm;
                        rt = getreg(status,&temp->op[2]);
                        imm = getimm(temp->op);
                        rd = rt >> imm;
                        setreg(status,temp->op,rd);
                }
                else
                {
                        unsigned int sa,rt,rd;
                        sa = getreg(status,&temp->op[7]);
                        rt = getreg(status,&temp->op[2]);
                        rd = rt >> sa;
                        setreg(status,temp->op,rd);
                }

	}
	else if(!memcmp(temp->ins,"SRA",3))
	{
		for(int i=0;temp->op[i]!='\0';i++)
                {
                        if(temp->op[i]=='#')
                        {
                                flag = 1;
                        }
                }
                if(flag==1)
                {
                        int rd,rt,imm;
                        rt = getreg(status,&temp->op[2]);
                        imm = getimm(temp->op);
                        rd = rt >> imm;
                        setreg(status,temp->op,rd);
                }
                else
                {
                        int sa,rt,rd;
                        sa = getreg(status,&temp->op[7]);
                        rt = getreg(status,&temp->op[2]);
                        rd = rt >> sa;
                        setreg(status,temp->op,rd);
                }

	}
	else if(!memcmp(temp->ins,"NOP",3))
	{
		
	}
	else if(!memcmp(temp->ins,"BEQ",3))
	{
                int rs,rt,offset;
                rs = getreg(status,temp->op);
                rt = getreg(status,&temp->op[2]);
                offset = getimm(temp->op);
                if(rs == rt)
                {
                        *pc = *pc + (offset);

                }
		
	}
	else if(!memcmp(temp->ins,"BGTZ",4))
	{
                int rs,offset;
                rs = getreg(status,temp->op);
                offset = getimm(temp->op);
                if(rs>0)
                {
                        *pc = *pc + (offset);

                }
		
	}
	else if(!memcmp(temp->ins,"BLTZ",4))
	{
                int rs,offset;
                rs = getreg(status,temp->op);
		offset = getimm(temp->op);
		if(rs<0)
		{
			*pc = *pc + (offset);
		
		}
		
	}
	else if(!memcmp(temp->ins,"SW",2))
	{
                int base,rd,offset;
                base = getreg(status,&temp->op[2]);
                offset = getoffset(temp->op);
		rd = getreg(status,temp->op);
                setmem(status, base + offset,rd);

		
	}
	else if(!memcmp(temp->ins,"LW",2))
	{
		int base,rd,offset;
		base = getreg(status,&temp->op[2]);
		offset = getoffset(temp->op);
		rd = getmem(status, base + offset);
		
		setreg(status,temp->op,rd);

	}
	else if(!memcmp(temp->ins,"JR",2))
	{
		int rs;
                rs = getreg(status,temp->op);
                *pc = rs;
                return;

	}
	else if(!memcmp(temp->ins,"J",1))
	{
		int imm;
		imm = getimm(temp->op);
		*pc = imm;
		return;	
	}
	else if(!memcmp(temp->ins,"BREAK",5))
	{
		*pc = 0;
		return;
	}	
	
	*pc = *pc + 4;
}

void Sim::mkfile(char* filepath)
{
	
	ofstream fout;
        int pc = 64;
	int cycle = 0;
        struct dataDetail* data = (struct dataDetail*)malloc(sizeof(struct dataDetail));
	struct dataDetail* temp;
        struct status* status = (struct status*)malloc(sizeof(struct status));
	
	getdata(filepath,data);
	initmem(data,status);	
	fout.open("simulation.txt");
	while(pc <= 144 && pc > 0)
	{
		cycle++;
		fout << "--------------------" << '\n'
		<< "Cycle:" << cycle << '\t' << pc << '\t';
		temp = data;
		while(atoi(temp->address)!=pc & temp->pnext != NULL)
		{
			temp = temp->pnext;
		}
		runbycycle(data,&pc,status);
		if(memcmp(temp->ins,"BREAK",5))
		{
			fout << temp->ins << '\t' << temp->op << '\n' << '\n';
			fout << "Registers" << '\n'
			<< "R00:" ;
		}
		else
		{
			fout << temp->ins << '\t' << temp->op << '\n';
			fout << "Registers" << '\n'
			<< "R00:" ;
		}
		for(int i=0;i<16;i++)
		{
			fout << '\t' << status->reg[i];
		}
		fout << '\n' << "R16:";
		for(int i=16;i<32;i++)
		{
			fout << '\t' << status->reg[i];
		}
		fout << '\n' << '\n' <<"Data" << '\n'
		<< "148:";
		for(int i=0;i<8;i++)
		{
			fout << '\t' << status->mem[i];
		}
		fout << '\n' << "180:";
		for(int i=8;i<16;i++)
		{
			fout << '\t' << status->mem[i];
		}
		fout << '\n' << "212:";
		for(int i=16;i<24;i++)
		{
			fout << '\t' << status->mem[i];
		}
		fout << '\n' << '\n';
	}
fout.close();

}

void Sim::initmem(dataDetail* data,status* status)
{
        dataDetail* temp;
        int flag = 0;
	int pc = 148;
        temp = data;
	for(int i=0;i<24;i++){
		while(atoi(temp->address) != (pc+(i*4)) && temp->pnext != NULL)
		{
			temp = temp->pnext;
		}
		status->mem[i] = atoi(temp->op);
	}
}

int Sim::getmem(status* status,char* address)
{
	int imm = getimm(address);
	return status->mem[(imm-148)/4];	
}

void Sim::setmem(status* status,char* address,int data)
{
	int imm = getimm(address);
	status->mem[(imm-148)/4] = data;	
}

int Sim::getmem(status* status,int address)
{
        return status->mem[(address-148)/4];
}

void Sim::setmem(status* status,int address,int data)
{
        status->mem[(address-148)/4] = data;
}

void Sim::setreg(status* status,char* reg,int data)
{
	char temp[5];
	int flag = 0;
	int count = 0;
	for(int i=0;reg[i] != '\0';i++)
	{
		if(reg[i]=='R')
		{
			flag = 1;
		}
		else if(flag==1 && reg[i] != ',')
		{
			temp[count]=reg[i];
			count++;	
		}else if(flag == 1 && reg[i] == ',')
		{
			break;
		}
	}
	if(count == 1)
	{
		status->reg[temp[0]-0x30] = data;
	}
	else if(count == 2)
	{
		status->reg[(temp[0]-0x30)*10 + (temp[1]-0x30)] = data;
	}
}

int Sim::getreg(status* status,char* reg)
{
        char temp[5];
        int flag = 0;
        int count = 0;
        for(int i=0;reg[i] != '\0';i++)
        {
                if(reg[i]=='R')
                {
                        flag = 1;
                }
                else if(flag==1 && reg[i] != ',' && reg[i] != ')')
                {
                        temp[count]=reg[i];
                        count++; 
                }else if(flag == 1 && reg[i] == ',')
		{
			break;
		}
                else if(flag == 1 && reg[i] == ')')
		{
			break;
		}
        }
        if(count == 1)
        {
                return status->reg[temp[0]-0x30];
        }
        else if(count == 2)
        {
                return status->reg[(temp[0]-0x30)*10 + (temp[1]-0x30)];
        }
	return 0;
}

int Sim::getimm(char* imm)
{
        char temp[5];
        int flag = 0;
        int count = 0;
        for(int i=0;imm[i] != '\0';i++)
        {
                if(imm[i]=='#')
                {
                        flag = 1;
                }
                else if(flag==1)
                {
                        temp[count]=imm[i];
                        count++;
                }
        }
        if(count == 1)
        {
                return temp[0]-0x30;
        }
        else if(count == 2)
        {
                return (temp[0]-0x30)*10 + (temp[1]-0x30);
        }
        else if(count == 3)
        {
                return (temp[0]-0x30)*100 + (temp[1]-0x30)*10 + (temp[2]-0x30);
        }
        return 0;
}

int Sim::stoi(char* str)
{
	int count = 0;
	while(str[count]!='\0')
	{
		count++;
	}
	if(count == 1)
	{
		return str[0]-0x30;
	}
	else if(count == 2)
	{
		return (str[0]-0x30)*10 + (str[1]-0x30);
	}
	else if(count == 3)
	{
		return (str[0]-0x30)*100 + (str[1]-0x30)*10 + (str[2]-0x30);
	}
	return 0;
}

int Sim::getoffset(char *str)
{
	int count = 0;
	int base = 0;
	while(str[count]!=' ')
	{
		count++;
	}
	base = count + 1;
	while(str[count]!='(')
	{
		count++;
	}
        if((count-base) == 1)
        {
                return str[base]-0x30;
        }
        else if((count-base) == 2)
        {
                return (str[base]-0x30)*10 + (str[base+1]-0x30);
        }
        else if((count-base) == 3)
        {
                return (str[base]-0x30)*100 + (str[base+1]-0x30)*10 + (str[base+2]-0x30);
        }
        return 0;
}

