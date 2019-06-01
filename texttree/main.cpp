#include "TText.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
  TText txt;
  bool f = true;
  int cmd = 0;
  std::cout << "Press Enter to Start";
  while (f)
  {
    getchar();
    char buff[256];
    txt.Print();
    cout << endl;
    cout << "Current Level " << txt.GetCurrent()->GetLevel() << endl;
    cout << "Current link '" << (txt.GetCurrent())->ToStr() << "'"<< endl;
    cout << "0 - exit" << endl;
    cout << "1 - go down" << endl;
    cout << "2 - go next" << endl;
    cout << "3 - insert next" << endl;
    cout << "4 - insert down" << endl;
    cout << "5 - delete next" << endl;
    cout << "6 - delete down" << endl;
    cout << "7 - reset" << endl;
    cin >> cmd;
    switch (cmd)
    {
    case 0:
      f = false;
      break;
    case 1:
      txt.GoDownLink();
      break;
    case 2:
      txt.GoNextLink();
      break;
    case 3:
      std::cout << "Enter sentence" << endl;
      cin >> buff;
      txt.InsertNext(buff);
      break;
    case 4:
      std::cout << "Enter sentence" << endl;
      cin >> buff;
      txt.InsertDown(buff);
      break;
    case 5:
      txt.DelNext();
      break;
    case 6:
      txt.DelDown();
      break;
    case 7:
      txt.Reset();
      break;
    }
  }
}