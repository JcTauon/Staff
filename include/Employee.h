//
// Created by Ceram J on 2024/5/10.
//

#ifndef STAFF_EMPLOYEE_H
#define STAFF_EMPLOYEE_H
#include <iostream>
#include "../include/Worker.h"
using namespace std;

class Employee : public Worker
{
public:

  Employee(int id, string name, int did);

  void showInfo();

  string getDeptName();
};
#endif // STAFF_EMPLOYEE_H
