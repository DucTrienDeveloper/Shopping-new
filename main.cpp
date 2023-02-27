#include<iostream>
#include<string>
#include <sstream>
#include"queue1.h"
#include"animation.h"
#include"stackme.h"

using namespace std;

int search(int);
int display();
string check(int);       //   for checking quantity

////////////////////////////////////////////////////////////////////
struct node
{
	int ID;
	string proName;             // khai báo sản phẩm bằng struct dữa theo ctdl linked list
	double prePrice;            // trong sản phẩm khai báo : ID , tên, giá , số lượng (sản phẩm)
	int quantity;               
	struct    node* next;       // khởi tạo con trỏ 
};

struct node* head = NULL;       // khởi tạo biến toàn cục là con trỏ head 

/*
* Logic: Đẩy dữ liệu vào trong linked list 
*   Step:
*       1.Khởi tạo một biến cục bộ t để lưu lại giá trị của node
*       2.Khởi tạo biến p với vị trí là head 
*       3.Kiểm tra head (head == null) linked list chưa có  node {head!=null} có node
*       3.1 Chưa có node , con trỏ p trỏ tới t => t thuộc linked list, t = head( vì chưa có node)
*       3.1 Có node , p tới node tiếp theo (khi con trỏ của p == null) dừng lại .
*   input: id,name,pre
*   output: list sản phẩm
*/
void beg()
{
	system("cls");
	int id, quant;           
	string name;                          // khởi tạo 2 biến cục bộ là con trỏ t và p
	double pre;                           
    struct node* t = new node;            // t = null ; p = head;
    struct node* p = head;

	cout << "\t\t\tEnter product ID:-";     // nhập id , tên ,giá , số lượng 
	cin >> id;                              // Đổ vào t 
	t->ID = id;
	cout << "\t\t\tEnter product Name:-"; 
	cin >> name;
	t->proName = name;
	cout << "\t\t\tEnter product price:-";  
	cin >> pre;
	t->prePrice = pre;
	cout << "\t\t\tEnter product quantity:-"; 
	cin >> quant;
	t->quantity = quant;

	if (head == NULL)          // nếu head chưa có giá trị 
	{
		t->next = head;        // con trỏ next của t = head ; 
		head = t;              // head = t => t là giá trị đầu tiên được khởi tạo => head != null
	}
	else           // khi head có giá trị 
	{
		while (p->next != NULL)     // khi chưa tìm được node có con trỏ bằng null 
		{                            
			p = p->next;            // đẩy tới node tiếp theo 
		}
		                            // khi tìm được node(*) có con trỏ bằng null 
		p->next = t;                // con trỏ của node(*) trỏ tới t 
		t->next = NULL;   // con trỏ của node t = null => node t là node cuối được đẩy giá trị hiện tại

	}
	system("cls");
	cout << "\n\n\t\t\t\tThis product is Inserted!\n\n\n";

}/*
   *Logic: Hàm nhận id và tìm kiếm node dựa vào id nhận .
   *Step : 1.khởi tạo count (giống như đếm vị trí trong mảng)
   *       2.khởi tạo biến cục bộ p = head ( vị trí đầu tiên)
   *       3.tìm kiếm id của từng node,không tìm thấy thì tới node tiếp theo(p=p.next)
   *Input: id 
   *Output: count(vị trí)
 */

///////////////////////////////////////////////////////////////////////////////////////////
int search(int id)                     //    for search item in list
{
	int count = 1;
	struct node* p = head;     // khởi tạo biến cục bộ p 
	while (p != NULL)          // khi p!= null => linked list vẫn còn giá trị  
	{
		if (p->ID == id)       // tìm kiếm được dựa trên id   
			break;            
		else                    
			count++;           // đếm vị trị 
		p = p->next;           //tới node tiếp theo 
	}
	
	return count;
}

////////////////////////////////////////////////////////////////////////

/*
* Logic:xóa node của linked list
* Step :
*     1.liên tiếp khởi tạo 2 biến cục bộ cur và pre = head
*     2.Truyền vào id của node cần xóa 
*     3.Tìm kiếm node cần xóa
*     4.Xóa node bằng cách node trước không trỏ tới node cần xóa

*/
void delPro()      // xóa sản phẩm 
{
	system("cls");
	display();
	int id;
	struct node* cur = head;    // khởi tạo 2 biến cục bộ cur và pre
	struct node* pre = head;
	cout << "\n\nEnter ID to delete that product:\n\n";
	cin >> id;        // truyền id 
	if (head == NULL)
	{
		system("cls");                  // check trong linked list
		cout << "List is empty" << endl;
	}
	int pos = 0;
	int count = display();               // gọi hàm hiển thị       
	pos = search(id);                    // gọi hàm tìm kiếm vị trí truyền vào id     
	if (pos <= count) {

		while (cur->ID != id) {          // lấy cur làm mốc , khi chưa tìm được 
			pre = cur;                   // cur = pre 
 			cur = cur->next;             // cur đi tiếp node tiếp theo (cur trước , pre sau )
		}
		pre->next = cur->next;           // khi tìm thấy, con trỏ của pre = con trỏ của cur 
		system("cls");                   // xóa bằng cách pre không trỏ tới cur 
		cout << "\n<<item is deleted>>\n";
	}
	else {
		cout << "\n<<<Not found>>\n\n";
	}
}

//////////////////////////////////////////////////////////////////////////////////

/*
* Logic: Thay đổi thông tin node
* Step: 1. truyền id node cần thay đổi
*       2. tìm kiếm node có id cần thay đổi
*       3. thay đổi thông tin trong node

*/
void modify()
{
	int id;              // hàm sửa xản phẩm 
	double pre;        
	string pName;
	int nid; int nq;     
	if (head == NULL)          // kiểm tra linked list
	{
		system("cls");
		cout << "List is empty" << endl;
	}
	else
	{
		display();  // gọi hàm hiển thị 
		cout << "\n\nEnter ID to modify product Name and its price:\n";
		cin >> id;
		struct node* cur = head;      // khởi tạo biến cục bộ cur 
		int pos = 0;
		int count = display();               
		pos = search(id);
		//   
		if (pos <= count)
		{
			while (cur->ID != id)       // khi id của cur chưa bằng id cần xóa 
			{
				cur = cur->next;       // cur đi tiếp
			}
			                         // khi tìm được 
			cout << "\nOld ID : " << cur->ID << endl;
			cout << "\nOld Name : " << cur->proName << endl;
			cout << "\nOld Price : " << cur->prePrice << endl;
			cout << "\nOld Quantity : " << cur->quantity << endl;
                                            // gán lại giá trị của node với id của sửa
			cout << endl << endl;
			cout << "Enter new ID:";
			cin >> nid;
			cur->ID = nid;
			cout << "Enter new Name:";
			cin >> pName;
			cur->proName = pName;
			cout << "Enter new Price:";
			cin >> pre;
			cur->prePrice = pre;
			cout << "Enter new Quantity:";
			cin >> nq;
			cur->quantity = nq;
		}
		        // không tìm thấy được node với id cần sửa
		else
		{
			cout << id << " is <<<Not found>>\n\n";
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////

int display()
{
	system("cls");
	int c = 0;             //  khởi tạo biến cục bộ p 
	struct node* p = head;
	cout << "Existing products are:\n";
	cout << "ID\t\tProduct Name\t\t\Price\t\tQuantity\n";
	cout << "=================================================================|\n";
	while (p != NULL)  // xâu ra toàn bộ giá trị trong node
	{
		cout << p->ID << "\t\t" << p->proName << "\t\t\t" << p->prePrice << "\t\t\t" << check(p->quantity) << "\n"; //    call   check func and pass quantity
		p = p->next;  // đi tới node tiếp theo
		c = c + 1;
	}
	cout << "\nTotal products in our store is : " << c << "\n\n\n";
	return c;
}
////////////////////////////////////////////////////////////////////////////////////////
string check(int quant)

{              //        check function
	int a = quant;
	stringstream ss;
	ss << a;
	string quantity = ss.str();

	if (quant <= 0)
		return "out of stock!";
	else
		return quantity;
}

///////////////////////////////////////////////////////////////////////
/*
* Logic : Hàm dành cho customer
*       Step: 1.Show danh sách sản phẩm
*             2.Chọn số mặt hàng cần mua
*             3. Id của mặt hàng(check id)
*             4.Số lượng mặt hàng(không đủ thì về step 2)
*             5.Tính toán tiền
* 

*/
void buy()
{
	system("cls");    // gọi hàm hiển thị
	display();
	string products[20];
	//   for display sold items
	int pay = 0, no, c = 0, price, id, i = 1;

	if (head == NULL)          // kiểm tra linked list 
	{
		cout << "\n<<<<There is no items to buy>>>>\n\n";
	}
	else
	{
		cout << "How many items you wanna to buy!\n";  // số lượng sản phẩm muốn mua
		cin >> no;
		int count = display();          
		while (i <= no)
		{
			struct node* cur = head;   // khởi tạo biến cục bộ cur 
			int quant, cho;   a:          
			cout << "Enter id of item that you want to buy: ";
			int id, pos = 0;       // nhập id sản phẩm muốn mua
			cin >> id;
			if (id == -1) { system("cls"); return; }// kiểm tra id 
			pos = search(id);    // gọi hàm tìm kiếm với id 
			if (pos <= count)
			{
			
				while (cur->ID != id)   // tìm kiếm node với id tương ứng ( chưa tìm được)
				{
					cur = cur->next; // đi tới node tiếp theo 
				}
				            // sau khi tìm được
				cout << "How many quantities you want:";
				cin >> quant;      // nhập số lượng 
				if (cur->quantity < quant) // kiểm tra số lượng
				{               // 
					cout << "\n\n\t\t\t----The Quantity You Entered is not available---" << endl;
					cout << "\n\t\t\t-----(Press -1 for Back to Main Menu)------" << endl;
					goto a;

				}
				products[c] = cur->proName;   // this will conatin the items buy names in array; 
				c++;

				pay = pay + (cur->prePrice * quant);         //     calculate Bill
				cur->quantity = cur->quantity - quant;           //    change quantity
				i++;

			}
			else
			{

				cout << "\n<<<<<<<<<This item is not available in our store at this time>>>>\n\n";

			}
		}
		string customer;
		cout << "\n\t\t Enter Your Name :"; cin >> customer;
		enqueue(customer);
		system("cls");
		cout << "\n\n\n\n\t\t\tYou have bought : ";
		for (int i = 0; i < no; i++)
		{              //    show that item you have bought
			cout << products[i] << ",";
		}
		price = pay * (0.90);           //    with 5% discount
		cout << "\n\nOriginal price : " << pay;
		cout << "\n with 10% discount: " << price << "\nThank you! for the shopping\n\n";




	}
}


/////////////////////////////////////////////////////////////////////////////////////////
void administator()
{
	system("cls");
	int ch;


	do {

		//            choice for below message



		cout << "\t\t============================================" << endl;
		cout << "\t\t|          Administator Portal              |" << endl;
		cout << "\t\t============================================" << endl;

		cout << "\t\t     Enter 1 for ADD a new product    " << endl;
		cout << "\t\t     Enter 2 to display all products   " << endl;
		cout << "\t\t     Enter 3 for MODIFY Existing product" << endl;
		cout << "\t\t     Enter 4 for Delete a particular product item" << endl;
		cout << "\t\t     Enter 5 for Customers List " << endl;
		cout << "\t\t     Enter 6 for Dequeue customer" << endl;
		cout << "\t\t     Enter 7 for Generate hash" << endl;
		cout << "\t\t     Enter 0 for Main Menu" << endl;


		cout << "\nEnter Your choice >>>";   cin >> ch;
		switch (ch) {
		case 1:
			beg();
			break;
		case 2:
			system("cls");
			display();
			break;
		case 3:
			modify();
			system("cls");
			break;
		case 4:
			delPro();
			cout << "\n-------Product is Deleted-------\n";
			break;
		case 5:
			system("cls");
			cout << "|============CUSTOMERS NAMES LIST==============|" << endl;
			displayQueue();
			break;
		case 6:
			system("cls");
			cout << "|============CUSTOMERS NAMES LIST==============|" << endl;
			dequeue();
			displayQueue();
			break;


		default: system("cls");

		}
	} while (ch != 0);
}



//        Main function
int main()
{

	for (int i = 0; i <= 51; i++)
	{

		push(i);
	}

	int ch;
	while (ch != 3) {

		//            choice for below message

		cout << "\n\t\t|--------<Main Menu>-----------|";
		cout << "\n\n";
		cout << "\t\t 1)Administator of Market\n";
		cout << "\t\t 2)Customer               \n";
		cout << "\t\t 3)Exit                    \n";



		cout << "\nEnter Your choice >>>"; cin >> ch;
		switch (ch) {
		case 1:


			administator();
			break;

		case 2:
			cout << endl << endl;
			bpop();
			system("pause");
			buy();
			break;

		case 3:
			cout << "\n\n\t\t\t\t\tThank You\t\t\t\t";
			break;

		}
	}
	return 0;
}






