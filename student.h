/*Developed by Patricia Nunes Dourado;*/
#ifndef studentH
#define studenteH
#include<string>
#include<stdio.h>
#include<stdlib.h>

using namespace std;

class Student
{
	private:
		string name;
		string id;
		string discipline;
		string campus;
		string status;
    public:
        Student(string);
		void setName(string);
		void setId(string);
		void setDiscipline(string);
		void setCampus(string);
		void setStatus(string);
		string getName();
		string getId();
		string getDiscipline();
		string getCampus();
		string getStatus();
};

#endif
