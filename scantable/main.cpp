#include "TArrList.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <TScanTable.h>

using namespace std;

int main()
{
  int * val;
  char data[256];
  int count;
  cout << "Enter count of elements in SeeTable: ";
  cin >> count;
  TScanTable<int> table(count);
  for (int i = 1; i <= count; i++)
  {
    val = new int;
    cout << "Enter key " << i << ": ";
	cin >> *val;
	cout << "Enter data " << i << ": ";
	cin >> data;
	table.Add(new TTabRecord<int>(data, val, true));
  }
  cout << endl << "Your Table : " << endl << table << endl;

	return 0;
}