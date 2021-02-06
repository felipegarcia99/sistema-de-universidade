#include<iostream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<sstream>
#include<ctime>
#include<fstream>
#include<limits>
#include<windows.h>

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

class FazString {
	public:

		int makeMatricula(int x) {
			FILE *testearq;
			int mati;
			string mats;
			while(1) {
				mati=170000;
				mati+=x*1000;

				mati+=rand()%999+1;
				mats=SSTR(mati)+".txt";

				testearq=fopen(mats.c_str(),"r");
				if(testearq==NULL) {
					break;
				}
			}
			fclose(testearq);

			return mati;
		}

		string makeDataNasc() {
			int d,m,a;
			string data;
			cout<<"Digite o dia em que você nasceu: ";
			cin>>d;
			cout<<"Digite o mês em que você nasceu: ";
			cin>>m;
			cout<<"Digite o ano em que você nasceu: ";
			cin>>a;

			data=SSTR(d)+"/"+SSTR(m)+"/"+SSTR(a);

			return data;
		}

		std::fstream& GotoLine(std::fstream& file, unsigned int num) {
			file.seekg(std::ios::beg);
			for(int i=0; i < num - 1; ++i) {
				file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			}
			return file;
		}

		void cor(int cor) {
			HANDLE hStdOut=GetStdHandle(STD_OUTPUT_HANDLE);

			SetConsoleTextAttribute(hStdOut,cor);
		}
};
