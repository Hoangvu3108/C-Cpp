#include<stdio.h>
void print(){
	printf("Hello Word");
}
int main(){
	void (*ptr)();	
	ptr= print;// gán địa chỉ hàm print cho con trỏ ptr
	ptr(); // gọi con trỏ ptr để thực hiện hàm print
}
