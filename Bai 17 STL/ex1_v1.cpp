#include <iostream>
#include <vector>

using namespace std;
int main (int argc, char const *argv[])
{
    vector <int> arr= {21,44,25,11,31,8,3}; // những phần tử có địa chỉ được cấp ở phân vùng heap nhưng bản thân giá trị của arr được cấp ở phân vùng stack 
    arr.size(); // size() là một hàm của vector nên nó sẽ trả về số lượng phần tử của vector
    for (size_t i=0;i <arr.size();i++)
    {
        cout << "Value :" << arr.at(i) << endl;
        // cout  << "VALUE : " << arr[i] << endl;
    }
}