#include <iostream>
#include <cstring>

using namespace std;

class TList
{
	public:
		typedef	int	Item;

	public:
		TList (const Item arr[] = NULL, unsigned n = 0);
		bool isFull (void) const;
		bool isEmpty (void) const;
		bool append (const Item& item);
		void visit (void (*pf) (Item& item));

	private:
		static const unsigned	mk_capacity = 4;

	private:
		Item		m_content[mk_capacity];
		unsigned	m_size;
		
};
		
TList::TList (const Item arr[], unsigned n) {
	if (NULL == arr) {
		m_size = 0;
		return;
	}

	m_size = mk_capacity < n ? mk_capacity : n;
	for (unsigned i = 0; i < m_size; ++i) {
		m_content[i] = arr[i];
	}
}
		
bool
TList::isFull (void) const
{
	return (mk_capacity == m_size);
}
		
bool
TList::isEmpty (void) const
{
	return (0 == m_size);
}

bool 
TList::append (const Item& item)
{
	if (isFull()) {
		return (false);
	}

	m_content[m_size++] = item;
	return (true);
}
		
void
TList::visit (void (*pf) (Item& item))
{
	for (unsigned i = 0; i < m_size; ++i) {
		pf(m_content[i]);
	}
}

static void
show (TList::Item& item)
{
	cout << item << ' ';
}

int
main (void) 
{     
	TList	one;
	one.visit(show);
	cout << endl;
	cout << "是否空：" << boolalpha << one.isEmpty();
	cout << endl << "=========" << endl;

	TList::Item	arr[] = {1, 2, 3};
	TList	two(arr, sizeof(arr)/sizeof(arr[0]));
	two.visit(show);
	cout << endl;
	cout << "是否满：" << two.isFull();
	cout << endl;
	cout << "是否空：" << two.isEmpty();
	cout << endl;
	cout << "追加一项：" << two.append(16);
	cout << endl;
	two.visit(show);
	cout << endl;


	cout << endl;
	return (0);
} 
