#include <iostream>
#include <vector>

using namespace std;
int main (int argc, char const *argv[])
{
    vector <int> arr= {21,44,25,11,31,8,3}; // những phần tử có địa chỉ được cấp ở phân vùng heap nhưng bản thân giá trị của arr được cấp ở phân vùng stack 
    arr.size(); // size() là một hàm của vector nên nó sẽ trả về số lượng phần tử của vector
    // for (size_t i=0;i <arr.size();i++)
    // {
    //     cout << "Value :" << arr.at(i) << endl;
    //     // cout  << "VALUE : " << arr[i] << endl;
    // }
    arr.push_back(30); // thêm phần tử vào cuối mảng

    arr.push_back(40);   // thêm phần tử vào cuối mảng

    arr.pop_back(); // sẽ tự động xóa đi phần tử cuoi cùng của mảng
    arr.insert(arr.begin(), 10); // thêm phần tử vào đầu mảng
    arr.insert(arr.end(), 20); // thêm phần tử vào cuối mảng
    arr.insert(arr.begin()+3,6);  // thêm phần tử vào vị trí thứ 3 nếu muốn thêm vị trí như thế nào thì sẽ cộng nên số cộng thêm vào bởi index của arr.begin () có index=0;
    // for (auto &i : arr)
    for (const auto &index: arr) // vòng lòng for cải tiến ở đây const dùng để đọc auto tự động suy diễn dứ liệu  
    {
        cout << "Value : " << index << endl; // khong can phải gọi ra arr.at(index)
       
    }


    return 0;

}
// kiểu dữ liệu size_t dùng để tính kích của cái mảng  size_t n = sizeof(arr)/sizeof(arr[0]); // sizeof trả về kích thước của mảng 