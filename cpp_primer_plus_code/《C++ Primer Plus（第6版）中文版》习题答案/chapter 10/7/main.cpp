#include <iostream>
#include <cstring>

using namespace std;

class TPlorg
{
	private:
		static	const unsigned	mk_size = 20;
		
	private:
		char		m_name[mk_size];
		unsigned	m_contentment_idx;

	public:
		TPlorg (const char* name = "Plorg");
		void setContentmentIdx (unsigned contentment_idx);
		void showPlorg (void) const;
};

TPlorg::TPlorg (const char* name)
{
	m_contentment_idx = 50;
	strncpy(m_name, name, mk_size-1);
	m_name[mk_size-1] = '\0';
}
		
void
TPlorg::setContentmentIdx (unsigned contentment_idx)
{
	m_contentment_idx = contentment_idx;
}
		
void
TPlorg::showPlorg (void) const
{
	cout << m_name << ' ' << m_contentment_idx;
}

int
main (void) 
{     
	TPlorg	plorg();
	plorg.showPlorg();
	cout << endl;
	plorg.setContentmentIdx(12);
	plorg.showPlorg();


	cout << endl;
	return (0);
} 
