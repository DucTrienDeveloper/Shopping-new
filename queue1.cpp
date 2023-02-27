#include <iostream>
#include<conio.h>
#include<bits/stdc++.h>
#include"queue1.h"
using namespace std;

// Structure of Node.
//Logic:khởi tạo struct lưu tên khách hàng dưới dạng linked list queue
struct Node
{
	string cname;

	Node* link;
};

Node* front = NULL;
Node* rear = NULL;

/* Logic:kiểm tra queue rỗng 
  Step 1.front và rear= null => queue rỗng
*/
 
bool isempty()
{
	if (front == NULL && rear == NULL)
		return true;
	else
		return false;
}

/*Logic : hàm thêm queue 
* Step 1.Nhận tên 
*      2.check front(front = null queue rỗng)
*      3.sử dụng rear = node (rear = node cuối hiện tại)

*/


void enqueue(string name)
{
	Node* ptr = new Node();
	ptr->cname = name;
	ptr->link = NULL;

	//If inserting the first element/node
	if (front == NULL)
	{
		front = ptr;
		rear = ptr;
	}
	else
	{
		rear->link = ptr;
		rear = ptr;
	}
}

/* Logic : Hàm xóa 1 node trong queue
*  Step 1.check queue
*       2.front = rear (queue chỉ 1 node) 
*       3.front !=rear xóa node ở vị front , front về node sau
*/
void dequeue()
{
	if (isempty())
		cout << "Queue is empty\n";
	else
		//only one element/node in queue.
		if (front == rear)
		{
			free(front);
			front = rear = NULL;
		}
		else
		{
			Node* ptr = front;
			front = front->link;
			free(ptr);
		}
}



/*Logic : Show toàn bộ node trong queue
*  Step 1. Kiểm tra queue 
*       2. sử dụng front show toàn bộ node trong queue (front trỏ tới node đầu)
*/
void displayQueue()
{
	if (isempty())
		cout << "Queue is empty\n";
	else
	{
		Node* ptr = front;
		while (ptr != NULL)
		{
			cout << "\t" << ptr->cname << "\t  " << endl;
			ptr = ptr->link;

		}
	}
}
