//
// Created by Ceram J on 2024/5/10.
//

#ifndef STAFF_WORKERMANAGER_H
#define STAFF_WORKERMANAGER_H
#include <iostream>
#include "Worker.h"
#include "Boss.h"
#include "Employee.h"
#include "Manager.h"
#include <fstream>
#define FILENAME "empFile.txt"
using namespace std;

class WorkerManager
{
public:
    WorkerManager();

    static void showMenu();

    static void exitSystem();

    void save() const;

    void addEmp();

    static int getEmpNum();

    void init_Emp() const;

    void show_Emp() const;

    void del_Emp();

    int isExit(int id) const;

    void mod_Emp();

    void find_Emp();

    void sort_Emp();

    int m_EmpNum;

    Worker ** m_EmpArray;

    bool m_FileIsEmpty;

    void clean_File();

    ~WorkerManager();
};

#endif //STAFF_WORKERMANAGER_H
