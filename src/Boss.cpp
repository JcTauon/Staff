//
// Created by Ceram J on 2024/5/10.
//

#include "../include/Boss.h"

Boss::Boss(int id, string name, int did)
{
  this->m_Id = id;
  this->m_Name = name;
  this->m_DeptID = did;
}
void Boss::showInfo()
{
  cout << "职工编号 : " << this->m_Id
       << "\t职工姓名 : " << this->m_Name
       << "\t岗位 : " << this->getDeptName()
       << "\t岗位职责 : 管理公司所有事物" << endl;
}
string Boss::getDeptName()
{
  return string("老板");
}
