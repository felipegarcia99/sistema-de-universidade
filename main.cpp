#include<iostream>
#include<cstdlib>
#include<ctime>
#include<clocale>
#include<windows.h>

#include"arquivo.cpp"

using namespace std;

void UFGG();
void menu();
void saindo();

Arquivo x;

int main(int argc,char** argv) {
	srand(time(NULL));
	setlocale(LC_ALL,"");
	system("mode 90,25");
	system("color 0f");
	x.b.cor(15);

	menu();

	return 0;
}

void UFGG() {
	cout<<" Universidade";
	x.b.cor(12);
	cout<<"          ##     ##  ######";
	x.b.cor(9);
	cout<<"  #######   #######";
	x.b.cor(15);
	cout<<"               Autores:     " << endl;
	Sleep(100);
	cout<<" Federal";
	x.b.cor(12);
	cout<<"               ##     ##  ##      ";
	x.b.cor(9);
	cout<<"##        ##";
	x.b.cor(15);
	cout<<"                    Felipe Garcia" << endl;
	Sleep(100);
	cout<<" de";
	x.b.cor(12);
	cout<<"                    ##     ##  ####";
	x.b.cor(9);
	cout<<"    ##   ###  ##   ###";
	x.b.cor(15);
	cout<<"              Gabriel Melém" << endl;
	Sleep(100);
	cout<<" Gangola";
	x.b.cor(12);
	cout<<"               ##     ##  ##";
	x.b.cor(9);
	cout<<"      ##    #   ##    #";
	x.b.cor(15);
	cout<<"               George Neves " << endl;
	Sleep(100);
	cout<<" Grings";
	x.b.cor(12);
	cout<<"                 #######   ##";
	x.b.cor(9);
	cout<<"      #######   #######";
	x.b.cor(15);
	cout<<"               .............\n\n\n" << endl;
	Sleep(100);
}


void menu() {
	int matricula, opc;
	opc = 1;
	while (opc != 4) {
		system("cls");
		UFGG();
		cout << "\t ____________   ________________   _________________   ________\n";
		cout << "\t|  CADASTRO  | |  EXIBIR DADOS  | |  ALTERAR DADOS  | |  SAIR  |\n";
		cout << "\t|_____<1>____| |_______<2>______| |_______<3>_______| |___<4>__|\n\t";
		cin >> opc;
		system("cls");

		switch (opc) {
			case 1:
				UFGG();
				x.CriarArquivo();
				cout<<endl;
				system("pause");
				break;
			case 2:
				UFGG();
				x.LerArquivo();
				cout<<endl;
				system("pause");
				break;
			case 3:
				UFGG();
				x.MudarArquivo();
				break;
			case 4:
				saindo();
				break;
		}
	}
}

void saindo() {
	cout<<"Saindo";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	Sleep(500);
	cout<<".";
	Sleep(1000);
}
