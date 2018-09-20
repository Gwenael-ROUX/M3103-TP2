#include <iostream>
#include <memory>

#include "node.hpp"
#include "list.hpp"

using namespace std;

void ListeDouble ()
{
    CList <string> aList ;
    aList.Show();
    aList.push_front("a");
    aList.push_front("b");
    aList.push_front("c");
    aList.push_front("d");
    aList.push_front("e");
    aList.push_back("g");
    aList.push_back("h");
    aList.push_back("i");

    aList.Show();

    shared_ptr <CNode<string>> ptr (aList.Find ("h"));
    cout << (ptr != nullptr ? "trouve" : "absent") << endl;
    aList.Delete(ptr);
    aList.Show();
}
int main()
{
    ListeDouble();
    return 0;
}
