//
// Created by Ceram J on 2024/5/10.
//

#ifndef STAFF_BOSS_H
#define STAFF_BOSS_H
#include <iostream>
using namespace std;

#include "Worker.h"

class Boss : public Worker
{
public:
  Boss(int id, string name, int deptId);
  virtual void showInfo();
  virtual string getDeptName();
};

#endif // STAFF_BOSS_H
