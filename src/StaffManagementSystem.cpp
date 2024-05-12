#include "../include/Employee.h"
#include "../include/Worker.h"
#include "../include/WorkerManager.h"
#include <iostream>
using namespace std;

int main() {
  WorkerManager wm;

  int choice;
  while (true) {
    WorkerManager::showMenu();
    cout << "请输入您的选择: " << endl;
    cin >> choice;

    switch (choice) {
    case 0:
      WorkerManager::exitSystem();
      break;
    case 1:
      wm.addEmp();
      break;
    case 2:
      wm.show_Emp();
      break;
    case 3:
      wm.del_Emp();
      break;
    case 4:
      wm.mod_Emp();
      break;
    case 5:
      wm.find_Emp();
      break;
    case 6:
      wm.sort_Emp();
      break;
    case 7:
      wm.clean_File();
      break;
    default:

      break;
    }
  }

  return 0;
}
