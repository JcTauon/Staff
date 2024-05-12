//
// Created by Ceram J on 2024/5/10.
//

#ifndef STAFF_MANAGER_H
#define STAFF_MANAGER_H
#include <iostream>
#include "Worker.h"
using namespace std;

class Manager: public Worker
{
public:
  Manager(int id, string name, int did);

  void showInfo();

  string getDeptName();

};
#endif // STAFF_MANAGER_H
