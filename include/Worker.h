//
// Created by Ceram J on 2024/5/10.
//

#ifndef STAFF_WORKER_H
#define STAFF_WORKER_H
#include <iostream>
#include <string>
using namespace std;

class Worker
{
public:

  //显示个人信息
  virtual void showInfo() = 0;
  //获取岗位名称
  virtual string getDeptName() = 0;

  int m_Id;
  string m_Name;
  int m_DeptID;


};


#endif // STAFF_WORKER_H
