 #include<iostream>
// using namespace std;

template <typename typeA, typename typeB>
// nếu sử dụng typeA và typeB thì nó sẽ tự động chuyển kiểu dữ liệu của tham số đầu vào thành kiểu dữ liệu của typeA ví dụ 1.5+ 2 thành 3.5 còn 1 + 2.5 thì nó sẽ chuyển thành 3
// typeA tong(typeA a, typeB b)
// {
//     return (typeA)a+b;
// }
// dùng từ khóa auto để tự động nó hiểu giúp cho compiler tự suy luận kiểu dữ liệu của tham số đầu vào
auto tong(typeA a, typeB b)
{
    return a+b;
}
int main (int argc, char **argv)
{
    std::cout << tong(1,2) << std::endl;
    std::cout << tong(1.5,2.5) << std::endl;
    std::cout << tong(1.5,2) << std::endl;
    std::cout << tong(1,2.5) << std::endl;
    return 0;
}
// nhược điểm hai tham số phải cùng kiểu dữ liệu  nếu mà nhập hai tham số khác kiểu dữ liệu thì nó sẽ báo lỗi
