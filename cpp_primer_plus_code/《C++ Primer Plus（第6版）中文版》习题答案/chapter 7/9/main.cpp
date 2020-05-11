#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

const int SLEN = 30;
struct student {
	char fullname[SLEN];
	char hobby[SLEN];
	int ooplevel;
};

// getinfo() has two arguments: a pointer to the first element of
// an array of student structures and an int representing the
// number of elements of the array. The function solicits and
// stores data about students. It terminates input upon filling
// the array or upon encountering a blank line for the student
// name. The function returns the actual number of array elements
// filled.
int getinfo(student pa[], int n)
{
	int		num_array_elem = n;
	char	tmp[SLEN];
	for (unsigned i = 0; i < n; ++i) {
		cout << "输入姓名：";
		cin.getline(tmp, SLEN);
		bool	blank_line = true;
		for (unsigned j = 0; j < strlen(tmp); ++j) {
			if (!isspace(tmp[j])) {
				blank_line = false;
				break;
			}
		}
		if (blank_line) {
			num_array_elem = i;
			break;
		}
		strcpy(pa[i].fullname, tmp);

		cout << "输入兴趣：";
		cin.getline(pa[i].hobby, SLEN);

		cout << "输入面向对象程序设计能力的级别：";
		cin >> pa[i].ooplevel;
		cin.get();
	}

	return (num_array_elem);
}

// display1() takes a student structure as an argument
// and displays its contents
void display1(student st)
{
	cout << st.fullname << '\t' << st.hobby << '\t' << st.ooplevel << endl;
}

// display2() takes the address of student structure as an
// argument and displays the structure’s contents
void display2(const student * ps)
{
	cout << ps->fullname << '\t' << ps->hobby << '\t' << ps->ooplevel << endl;
	;
}

// display3() takes the address of the first element of an array
// of student structures and the number of array elements as
// arguments and displays the contents of the structures
void display3(const student pa[], int n)
{
	for (unsigned i = 0; i < n; ++i) {
		cout << pa[i].fullname << '\t' << pa[i].hobby << '\t' << pa[i].ooplevel << endl;
	}
}

int main()
{
	cout << "输入班级人数：";
	int class_size;
	cin >> class_size;
	while (cin.get() != '\n')
		continue;
	student * ptr_stu = new student[class_size];
	int entered = getinfo(ptr_stu, class_size);
	for (int i = 0; i < entered; i++)
	{
		display1(ptr_stu[i]);
		display2(&ptr_stu[i]);
	}
	display3(ptr_stu, entered);
	delete [] ptr_stu;
	cout << "完毕\n";
	return 0;
}
