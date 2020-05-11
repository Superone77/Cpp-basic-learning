#pragma once
namespace SALES
{
	class Sales
	{
		private:
			static const int QUARTERS = 4;
			double sales[QUARTERS];
			double size;
			double average;
			double max;
			double min;

		private:
			double calcAverage (void) const;
			double calcMax (void) const;
			double calcMin (void) const;
			
		public:
			Sales () {setSales();}
			Sales (double arr[], int n);
			void setSales(void);
			void showSales(void) const;
	};
}
