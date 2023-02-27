#include <bits/stdc++.h> 
#include"stackme.h"
using namespace std;

/* Logic : khởi tạo struct dưới với cấu trúc dữ liệu là stack 
*/
struct bucket
{
	int data;
	bucket* link;
};

struct bucket* top;

/* Logic : Thêm node 
* Step 1 . Kiểm tra bộ nhớ
*      2. Khởi tạo biến temp
*      3. Biến temp nhận dữ liệu được gửi vào
*      4. Biến top = temp (top trỏ tới node sau hiện tại trong stack)=>node được thêm
*/
void push(int data)
{
	struct bucket* temp;
	temp = new bucket();

	if (!temp) {
		cout << "\nHeap Overflow";
		exit(1);
	}

	temp->data = data;

	temp->link = top;

	top = temp;
}
/* Logic : Kiểm tra stack rỗng
* Step 1 . Top == null => stack rỗng
*/
int isEmpty()
{
	return top == NULL;
}



/* Logic : hàm lấy ra 1 node trong stack
*  Step 1 . Kiểm tra stack 
*       2 . Khởi tạo biến temp = top 
*       3 . top trỏ về biến node trước đó (node cũ bị xóa)
  */
void bpop()
{
	struct bucket* temp;


	if (top == NULL) {
		cout << "\nStack Underflow" << endl;
		exit(1);
	}
	else {

		temp = top;
		top = top->link;// node sau trỏ tới node trước
		temp->link = NULL;

		// release memory of top node 
		free(temp);

	}
	cout << "Your Trolli No is :" << top->data << endl;
	cout << "                  ___" << endl;
	cout << "                 /  |" << endl;
	cout << "  ______________/   --" << endl;
	cout << " |___/__ /___/_|     " << endl;
	cout << " |__/___/___/__|     " << endl;
	cout << " |_/___/___/___|     " << endl;
	cout << "    _______/         " << endl;
	cout << "     O   O           " << endl;


}
/* Logic : hàm hiển thị stack
* Step 1 . Kiểm tra stack 
*      2. Khởi tạo biến temp = top 
*      3. Show toàn bộ thông tin trong temp 
*      4. temp = temp.link (trỏ tới node phía trước)
*/
void bdisplay()
{
	struct bucket* temp;


	if (top == NULL) {
		cout << "\nStack Underflow";
		exit(1);
	}
	else {
		temp = top;
		while (temp != NULL)
		{
			cout << temp->data << " ";
			temp = temp->link; // trỏ tới node trước 
		}
	}
}




