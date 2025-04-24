#include<iostream>
#include<map>
using namespace std;

int main (int argc, char const *argv[])
{
    map <int,string> arr;
    arr[0] ="Hoang";
    arr[1] ="Long " ;
    arr[2]="Vu";   // nếu mà để arr[1] thì nó sẽ in ra key 1 và value là Vu những cái key phải là duy nhất (khác nhau ) tức nó lấy key sau cùng 

    for (const auto &index :arr)
    {
        cout<< "Key"<<index.first <<", value: "<<index.second <<endl;

    }
}