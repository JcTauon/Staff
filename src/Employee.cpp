//
// Created by Ceram J on 2024/5/10.
//
#include "../include/Employee.h"

Employee::Employee(int id, string name, int did) {
  this->m_Id = id;
  this->m_Name = name;
  this->m_DeptID = did;
}

void Employee::showInfo() {
  cout << "职工编号 : " << this->m_Id
      << "\t职工姓名 : " << this->m_Name
      << "\t岗位 : " << this->getDeptName()
      << "\t岗位职责 : 完成经理交给的任务" << endl;
}

string Employee::getDeptName() {
  return string ("普通员工");
}