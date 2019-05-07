#include<stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string.h>
#include <locale.h>
#include "student.h"
/*
Developed by Patricia Nunes Dourado;*/

vector<Student> studentM;//Students registered
vector<Student> studentT;//Students not enrolled

using namespace std;

void loadReg(string file)
{
    ifstream f (file.c_str(),ios::in);
    Student student("Not registered");
    string id="default",name,discipline,aux,status;
    char c;

    if(f.is_open())
    {
        while(!f.eof())
        {
            getline(f,id,';');
            getline (f,name,';');
            getline (f,discipline,';');
            getline (f,aux,';');
            getline (f,aux,';');
            getline (f,status,';');

            student.setId(id);
            student.setName(name);
            student.setDiscipline(discipline);
            student.setStatus(status);
            studentM.push_back(student);
            do{
                f.get(c);
            }while(c!='\n');
        }
        f.close();
    }
    else
        printf("Error opening the file!\n");
}

void loadList(string file)
{
    ifstream f (file.c_str(),ios::in);
    Student student("Not registered");
    string name,id;

    if(f.is_open())
    {
        while(!f.eof())
        {
            getline (f,id,'\t');
            student.setId(id);
            getline (f,name,'\n');
            student.setName(name);
            studentT.push_back(student);

        }
        f.close();
    }
}

void compareNEnr_reg()
{
    int i,j;

    for(i=0;i<studentT.size();i++)
        for(j=0;j<studentM.size();j++)
            if(!strcmp(studentT[i].getId().c_str(),studentM[j].getId().c_str()))
            {
                studentT[i].setStatus(studentM[j].getStatus());
                studentT[i].setDiscipline(studentM[j].getDiscipline());
                studentT[i].setCampus(studentM[j].getCampus());
            }
}

void store_NEnr_reg(string file)
{
    ofstream f (file.c_str(),ios::out);
    int i;

    if(f.is_open())
    {
        f.write("N\t\tID\t\tSTUDENT\t\tDISCIPLINE\t\tCAMPUS\t\tSTATUS\n\n",sizeof(string));
        for(i=0;i<studentT.size();i++)
            if(strcmp(studentT[i].getStatus().c_str(),"Not registered"))
				f<<i+1<<"\t\t"<<studentT[i].getId().c_str()<<"\t\t"<<studentT[i].getName().c_str()<<"\t\t"<<studentT[i].getDiscipline().c_str()<<"\t\t"<<studentT[i].getStatus().c_str()<<"\n";
    }
    f.close();
}
int main()
{

    loadReg("input/registered.txt");
    loadList("input/check.txt");
    compareNEnr_reg();
    store_NEnr_reg("output/nenr_reg.txt");

    return 0;
}
