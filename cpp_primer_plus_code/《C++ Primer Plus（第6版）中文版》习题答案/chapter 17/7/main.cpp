#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>


using namespace std;

static void
showStr (const string& str)
{
	cout << str << endl;
}

class Storer 
{
	public:
		explicit Storer (ofstream& ofs) : ofs_(ofs) {}

		ofstream& operator() (const string& str)
		{
			auto	len = str.size();
			ofs_.write((char*)&len, sizeof(len));
			ofs_.write(str.data(), (streamsize)len);

			return (ofs_);
		}
	

	private:
		ofstream&	ofs_;
};

static void
getStrs (ifstream& ifs, vector<string>& vistr)
{
	while (true) {
		streamsize	len;
		ifs.read((char*)&len, sizeof(len));
		if (!ifs) {
			break;
		}

		char*	p_char = new char [len + 1];
		ifs.read(p_char, len);
		if (!ifs) {
			break;
		}
		p_char[len] = '\0';
		vistr.push_back(p_char);
		delete [] p_char;
	}
}

int main()
{
	vector<string> vostr;
	string temp;
	
	// acquire strings
	cout << "Enter strings (empty line to quit):\n";
	while (getline(cin,temp) && temp[0] != '\0')
		vostr.push_back(temp);
	cout << "Here is your input.\n";
	for_each(vostr.begin(), vostr.end(), showStr);

	// store in a file
	ofstream fout("strings.dat", ios_base::out | ios_base::binary);
	for_each(vostr.begin(), vostr.end(), Storer(fout));
	fout.close();

	// recover file contents
	vector<string> vistr;
	ifstream fin("strings.dat", ios_base::in | ios_base::binary);
	if (!fin.is_open())
	{
		cerr << "Could not open file for input.\n";
		exit(EXIT_FAILURE);
	}
	getStrs(fin, vistr);
	cout << "\nHere are the strings read from the file:\n";
	for_each(vistr.begin(), vistr.end(), showStr);

	return 0;
}
