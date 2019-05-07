/*Developed by Patricia Nunes Dourado;*/
#include "student.h"

Student::Student(string newStatus)
{
    setStatus(newStatus);
}

void Student::setName(string newName)
{
    name = newName;
}
void Student::setId(string newId)
{
    id = newId;
}
void Student::setDiscipline(string newDiscipline)
{
    discipline = newDiscipline;
}
void Student::setCampus(string newCampus)
{
    campus = newCampus;
}
void Student::setStatus(string newStatus)
{
    status = newStatus;
}
string Student::getName()
{
    return name;
}
string Student::getId()
{
    return id;
}
string Student::getStatus()
{
    return status;
}
string Student::getDiscipline()
{
    return discipline;
}
string Student::getCampus()
{
    return campus;
}
