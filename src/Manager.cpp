//
// Created by Ceram J on 2024/5/10.
//

#include "../include/Manager.h"

Manager::Manager(int id, std::string name, int did) {
  this->m_Id = id;
  this->m_Name = name;
  this->m_DeptID = did;
}

void Manager::showInfo() {
  cout << "职工编号 : " << this->m_Id
       << "\t职工姓名 : " << this->m_Name
       << "\t岗位 : " << this->getDeptName()
       << "\t岗位职责 : 完成老板交给的任务" << endl;
}

string Manager::getDeptName() {
  return string("经理");
}