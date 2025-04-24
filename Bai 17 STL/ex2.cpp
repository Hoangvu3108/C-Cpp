#include <iostream>
#include <list>

using namespace std;

int main(int argc, char const *argv[])
{
    list<int> arr;

    arr.push_back(1);
    arr.push_back(23);
    arr.push_back(34);
    arr.push_back(41);
    arr.push_back(50);
    arr.push_front(0);
    arr.push_front(-1);

    list<int>::iterator it = arr.begin();
    int index = 0;

    for (it = arr.begin(); it != arr.end();)
    {
        if (index == 2)
        {
            it = arr.insert(it, 2); // Thêm vào vị trí index
            ++it; // Cập nhật iterator sau khi insert
        }
        else if (index == 3)
        {
            it = arr.erase(it); // Xóa phần tử tại vị trí index và cập nhật iterator
            continue; // Không tăng iterator vì erase đã trả về iterator mới
        }
        else
        {
            ++it; // Chỉ tăng iterator nếu không insert hoặc erase
        }
        index++;
    }

    for (it = arr.begin(); it != arr.end(); ++it)
    {
        cout << "Value : " << *it << endl;
    }

    return 0;
}