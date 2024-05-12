//
// Created by Ceram J on 2024/5/10.
//

#include "../include/WorkerManager.h"

WorkerManager::WorkerManager() {
  // 文件不存在
  ifstream ifs;
  ifs.open(FILENAME, ios::in);

  if (!ifs.is_open()) {
    // cout << "文件不存在!!!" << endl;
    //  初始化属性
    //  初始化记录人数
    this->m_EmpNum = 0;
    // 初始化数组指针
    this->m_EmpArray = NULL;
    // 初始化文件是否为空
    this->m_FileIsEmpty = true;
    ifs.close();
    return;
  }

  // 文件存在，数据为空
  char ch;
  ifs >> ch;
  if (ifs.eof()) {
    // 文件为空
    // cout << "文件为空" << endl;
    this->m_EmpNum = 0;
    // 初始化数组指针
    this->m_EmpArray = nullptr;
    // 初始化文件是否为空
    this->m_FileIsEmpty = true;
    ifs.close();
    return;
  }

  // 当文件存在，并且记录数据
  int num = WorkerManager::getEmpNum();
  // cout << "职工数为: " << num << endl;
  this->m_EmpNum = num;

  // 开辟空间
  this->m_EmpArray = new Worker *[this->m_EmpNum];
  // 将文件中的数据,存到数组中
  this->init_Emp();

  //  for (int i = 0; i < num; i++) {
  //    cout << " 职工编号 : " << this->m_EmpArray[i]->m_Id
  //         << " 姓名 : " << this->m_EmpArray[i]->m_Name
  //         << " 部门编号 : " << this->m_EmpArray[i]->m_DeptID << endl;
  //  }
}

void WorkerManager::showMenu() {
  cout << "************* Worker Management System *************" << endl;
  cout << "************* 1. 添加员工信息 *************" << endl;
  cout << "************* 2. 显示职工信息 *************" << endl;
  cout << "************* 3. 删除离职员工 *************" << endl;
  cout << "************* 4. 修改职工信息 *************" << endl;
  cout << "************* 5. 查找职工信息 *************" << endl;
  cout << "************* 6. 按照编号排序 *************" << endl;
  cout << "************* 7. 清空所有文档 *************" << endl;
  cout << "************* 0. 退出管理程序 *************" << endl;
  cout << endl;
}

void WorkerManager::exitSystem() {
  cout << "欢迎下次使用 !!" << endl;
  exit(0);
}

void WorkerManager::addEmp() {
  cout << "请输入添加员工数量" << endl;
  int addNum = 0;

  cin >> addNum;
  if (addNum > 0) {
    int newSize =
        this->m_EmpNum + addNum; // 计算新空间大小 = 原来的个数 + 新增的个数

    // 开辟新空间
    auto **newSpace = new Worker *[newSize];

    // 将原来空间里的数据,拷贝到新空间内
    if (this->m_EmpArray != nullptr) {
      for (int i = 0; i < this->m_EmpNum; i++) {
        newSpace[i] = this->m_EmpArray[i];
      }
    }

    // 批量添加新数据
    for (int i = 0; i < addNum; i++) {
      int id;
      string name;
      int dSelect;

      cout << "请输入第 " << i + 1 << " 个新职工编号: " << endl;
      cin >> id;

      cout << "请输入第 " << i + 1 << " 个新职工姓名: " << endl;
      cin >> name;

      cout << "请选择该职工岗位: " << endl;
      cout << "1. 普通职工" << endl;
      cout << "2. 经理" << endl;
      cout << "3. 老板" << endl;
      cin >> dSelect;

      Worker *worker = nullptr;
      switch (dSelect) {
      case 1:
        worker = new Employee(id, name, 1);
        break;
      case 2:
        worker = new Manager(id, name, 2);
        break;
      case 3:
        worker = new Boss(id, name, 3);
        break;
      default:
        break;
      }

      // 将创建职工指针,保存进数组中
      newSpace[this->m_EmpNum + i] = worker;
    }

    // 释放原有空间
    delete[] this->m_EmpArray;

    // 更改新空间指向
    this->m_EmpArray = newSpace;

    // 更新新空间人数
    this->m_EmpNum = newSize;

    // 更新职工标志不为空
    this->m_FileIsEmpty = false;

    cout << "成功添加" << addNum << "名新职工!" << endl;

    this->save();
  } else {
    cout << "输入有误!!" << endl;
  }
}

void WorkerManager::save() const {
  ofstream ofs;
  ofs.open(FILENAME, ios::out);

  for (int i = 0; i < this->m_EmpNum; i++) {
    ofs << this->m_EmpArray[i]->m_Id << " " << this->m_EmpArray[i]->m_Name
        << " " << this->m_EmpArray[i]->m_DeptID << endl;
  }

  // 关闭文件
  ofs.close();
}

int WorkerManager::getEmpNum() {
  ifstream ifs;
  ifs.open(FILENAME, ios::in);

  int id;
  string name;
  int deptId;
  int num = 0;

  while (ifs >> id && ifs >> name && ifs >> deptId) {
    num++;
  }

  return num;
}

void WorkerManager::init_Emp() const {
  ifstream ifs;
  ifs.open(FILENAME, ios::in);

  int id;
  string name;
  int deptID;

  int index = 0;
  while (ifs >> id && ifs >> name && ifs >> deptID) {
    Worker *worker = nullptr;
    if (deptID == 1) {
      worker = new Employee(id, name, deptID);
    } else if (deptID == 2) {
      worker = new Manager(id, name, deptID);
    } else {
      worker = new Boss(id, name, deptID);
    }

    this->m_EmpArray[index] = worker;
    index++;
  }
  ifs.close();
}

void WorkerManager::show_Emp() const {
  // 文件是否为空
  if (this->m_FileIsEmpty) {
    cout << "文件不存在或记录为空 ! " << endl;
  } else {
    for (int i = 0; i < m_EmpNum; ++i) {
      this->m_EmpArray[i]->showInfo();
    }
  }
}

void WorkerManager::del_Emp() {
  if (this->m_FileIsEmpty) {
    cout << "文件不存在或记录为空 ! " << endl;
  } else {
    cout << "请输入想要删除员工的编号 : " << endl;
    int id = 0;
    cin >> id;

    int index = this->isExit(id);

    if (index != -1) {
      for (int i = index; i < this->m_EmpNum - 1; i++) {
        this->m_EmpArray[i] = this->m_EmpArray[++i];
      }
      this->m_EmpNum--;
      this->save();

      cout << "删除成功" << endl;
    } else {
      cout << "删除失败, 未找到该员工。" << endl;
    }
  }
}

int WorkerManager::isExit(int id) const {
  int index = -1;
  for (int i = 0; i < this->m_EmpNum; i++) {
    if (this->m_EmpArray[i]->m_Id == id) {
      index = i;
      break;
    }
  }

  return index;
}

void WorkerManager::mod_Emp() {
  if (this->m_FileIsEmpty) {
    cout << "文件不存在或记录为空 ! " << endl;
  } else {
    cout << "请输入修改职工的编号 : " << endl;
    int id;
    cin >> id;

    int res = this->isExit(id);
    if (res != -1) {
      this->m_EmpArray[res] = nullptr;
      int newId = 0;
      string newName;
      int dSelect = 0;

      cout << "查到 : " << id << "号职工, 请输入新职工号 : " << endl;
      cin >> newId;

      cout << "请输入新姓名 : " << endl;
      cin >> newName;

      cout << "请输入岗位 : " << endl;
      cout << "1、普通职工" << endl;
      cout << "2、经理" << endl;
      cout << "3、老板" << endl;

      cin >> dSelect;
      Worker *worker = nullptr;
      switch (dSelect) {
      case 1:
        worker = new Employee(newId, newName, dSelect);
        break;
      case 2:
        worker = new Manager(newId, newName, dSelect);
        break;
      case 3:
        worker = new Boss(newId, newName, dSelect);
        break;
      }

      this->m_EmpArray[res] = worker;
      cout << "修改成功 ! " << endl;

      this->save();
    } else {
      cout << "修改失败, 查无此人 ! " << endl;
    }
  }
}

void WorkerManager::find_Emp() {
  if (this->m_FileIsEmpty) {
    cout << "文件不存在或记录为空 ! " << endl;
  } else {
    cout << "请输入查找的方式 : " << endl;
    cout << "1、按照职工编号查找 " << endl;
    cout << "2、按照职工姓名查找 " << endl;

    int select = 0;
    cin >> select;

    if (select == 1) {
      int id;
      cout << "请输入查找的职工的编号 : " << endl;
      cin >> id;

      int res = isExit(id);
      if (res != -1) {
        cout << "查找成功! 该职工信息如下 : " << endl;
        this->m_EmpArray[res]->showInfo();
      } else {
        cout << "查找失败！查无此人" << endl;
      }
    } else if (select == 2) {
      cout << "请输入查找的姓名 : " << endl;
      string name;
      cin >> name;

      bool flag = false;
      for (int i = 0; i < m_EmpNum; ++i) {
        if (this->m_EmpArray[i]->m_Name == name) {
          cout << "查找成功, 职工编号为: " << this->m_EmpArray[i]->m_Id << endl;
          flag = true;
          this->m_EmpArray[i]->showInfo();
        }
      }

      if (!flag) {
        cout << "查找失败, 查无此人! " << endl;
      }
    } else {
      cout << "输入选项有误 ! " << endl;
    }
  }
}

void WorkerManager::sort_Emp() {
  if (this->m_FileIsEmpty) {
    cout << "文件为空或记录不存在! " << endl;
  } else {
    cout << "请选择排序方式: " << endl;
    cout << "1、按职工号进行升序 " << endl;
    cout << "2、按职工号进行降序 " << endl;

    int select = 0;
    cin >> select;
    for (int i = 0; i < m_EmpNum; i++) {
      int minOrMax = i;
      for (int j = i + 1; j < this->m_EmpNum; ++j) {
        if (select == 1) {
          if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id) {
            minOrMax = j;
          }
        } else {
          if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id) {
            minOrMax = j;
          }
        }
      }

      // 判断一开始认定的最小值或最大值，是不是计算的最小值或最大值，如果不是，就交换数据
      if (i != minOrMax) {
        Worker *temp = this->m_EmpArray[i];
        this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
        this->m_EmpArray[minOrMax] = temp;
      }
    }

    cout << "排序成功, 排序后的结果 : " << endl;
    this->save();
    this->show_Emp();
  }
}

void WorkerManager::clean_File() {
  cout << "确定清空? " << endl;
  cout << "1、确定 " << endl;
  cout << "2、返回 " << endl;

  int select = 0;
  cin >> select;

  if (select == 1)
  {
    ofstream ofs(FILENAME, ios::trunc); //删除文件后重新创建
    ofs.close();

    if (this->m_EmpArray != nullptr)
    {
      //删除堆区的每个职工对象
      for (int i = 0; i < this->m_EmpNum; ++i) {
        this->m_EmpArray[i] = nullptr;
      }

      delete[] this->m_EmpArray;
      this->m_EmpArray = nullptr;
      this->m_EmpNum = 0;
      this->m_FileIsEmpty = true;
    }
    cout << "清空成功! " << endl;
  }
}


WorkerManager::~WorkerManager() {
  if (this->m_EmpArray != nullptr) {
    delete[] this->m_EmpArray;
    this->m_EmpArray = nullptr;
  }
}
