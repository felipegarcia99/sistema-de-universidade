#include<iostream>
#include<string>
#include<fstream>

#include"aluno.cpp"
#include"fazstring.cpp"

#define SSTR( x ) static_cast< std::ostringstream & >( \
        ( std::ostringstream() << std::dec << x ) ).str()

using namespace std;

class Arquivo {

	public:
		fstream arq;
		string mat;
		Aluno a;
		FazString b;


		void CriarArquivo() {
			cout<<"Digite o nome do aluno: ";
			cin>>a.nome;

			a.sexo='a';

			while(a.sexo!='M'&&a.sexo!='F') {
				cout<<"Digite o sexo do aluno(M ou F): ";
				cin>>a.sexo;
			}

			a.curso=0;

			while(a.curso!=1&&a.curso!=2&&a.curso!=3&&a.curso!=4) {
				cout<<"Digite o curso do aluno(1 para Eng. Comp. 2 para Cien. Comp. 3 para Eng. Prod. e 4  para Admin.): ";
				cin>>a.curso;
			}

			cout<<"Faça a data de nascimento do aluno: "<<endl<<endl;
			a.data_nascimento=b.makeDataNasc();

			a.matricula=b.makeMatricula(a.curso);

			mat=SSTR(a.matricula)+".txt";

			arq.open(mat.c_str(),fstream::out);
			arq<<a.nome<<endl<<a.matricula<<endl<<a.sexo<<endl<<a.data_nascimento<<endl<<a.curso;

			cout<<"Sua matrícula foi criada com sucesso!"<<endl<<"Seu número de matrícula é ";
			b.cor(10);
			cout<<a.matricula;
			b.cor(15);

			arq.close();
		}

		void LerArquivo() {
			cout<<"Digite sua matrícula: ";
			cin>>a.matricula;

			mat=SSTR(a.matricula)+".txt";

			arq.open(mat.c_str());
			if(arq==NULL) {
				cout<<"Matrícula inexistente";
			} else {
				b.GotoLine(arq, 1);
				arq>>a.nome;
				cout<<"Nome: ";
				b.cor(10);
				cout<<a.nome<<endl;
				b.cor(15);

				b.GotoLine(arq, 2);
				arq>>a.matricula;
				cout<<"Matrícula: ";
				b.cor(10);
				cout<<a.matricula<<endl;
				b.cor(15);

				b.GotoLine(arq, 3);
				arq>>a.sexo;
				cout<<"Sexo: ";
				b.cor(10);
				cout<<a.sexo<<endl;
				b.cor(15);

				b.GotoLine(arq, 4);
				arq>>a.data_nascimento;
				cout<<"Data de nascimento: ";
				b.cor(10);
				cout<<a.data_nascimento<<endl;
				b.cor(15);

				b.GotoLine(arq, 5);
				arq>>a.curso;
				cout<<"Curso: ";
				b.cor(10);
				switch(a.curso) {
					case 1:
						cout<<"Eng. Comp.";
						break;
					case 2:
						cout<<"Ciên. Comp.";
						break;
					case 3:
						cout<<"Eng. Prod.";
						break;
					case 4:
						cout<<"Admin.";
				}
				b.cor(15);
			}
			arq.close();
		}

		void MudarArquivo() {
			int esc;

			cout<<"Digite sua matrícula: ";
			cin>>a.matricula;

			mat=SSTR(a.matricula)+".txt";

			arq.open(mat.c_str());
			if(arq==NULL) {
				cout<<"Matrícula inexistente"<<endl;
				system("pause");
			} else {
				b.GotoLine(arq, 1);
				arq>>a.nome;
				cout<<"Nome: "<<a.nome<<endl;

				b.GotoLine(arq, 2);
				arq>>a.matricula;
				cout<<"Matrícula: "<<a.matricula<<endl;

				b.GotoLine(arq, 3);
				arq>>a.sexo;
				cout<<"Sexo: "<<a.sexo<<endl;

				b.GotoLine(arq, 4);
				arq>>a.data_nascimento;
				cout<<"Data de nascimento: "<<a.data_nascimento<<endl;

				b.GotoLine(arq, 5);
				arq>>a.curso;
				cout<<"Curso: ";
				switch(a.curso) {
					case 1:
						cout<<"Eng. Comp.";
						break;
					case 2:
						cout<<"Ciên. Comp.";
						break;
					case 3:
						cout<<"Eng. Prod.";
						break;
					case 4:
						cout<<"Admin.";
				}

				while(esc!=5) {
					cout<<endl<<endl;
					esc=alterar();
					switch(esc) {
						case 1:
							cout<<"Digite o novo nome do aluno: ";
							cin>>a.nome;
							break;
						case 2:
							a.curso=0;

							while(a.curso!=1&&a.curso!=2&&a.curso!=3&&a.curso!=4) {
								cout<<"Digite o novo curso do aluno(1 para Eng. Comp. 2 para Cien. Comp. 3 para Eng. Prod. e 4  para Admin.): ";
								cin>>a.curso;
							}
							break;
						case 3:
							a.sexo='a';

							while(a.sexo!='M'&&a.sexo!='F') {
								cout<<"Digite o novo sexo do aluno(M ou F): ";
								cin>>a.sexo;
							}
							break;
						case 4:
							cout<<"Faça a nova data de nascimento do aluno: "<<endl;
							a.data_nascimento=b.makeDataNasc();
							break;
						case 5:
							retornar();
							break;
						default:
							cout<<"Opção inválida";
							break;
					}
					arq.close();

					arq.open(mat.c_str(), std::ofstream::out | std::ofstream::trunc);
					arq<<a.nome<<endl<<a.matricula<<endl<<a.sexo<<endl<<a.data_nascimento<<endl<<a.curso;

					if(esc!=5) {
						cout<<"Sua matrícula foi alterada com sucesso!"<<endl<<"Você pode alterar outro dado se quiser"<<endl;

						cout<<"Nome: "<<a.nome<<endl;

						cout<<"Matrícula: "<<a.matricula<<endl;

						cout<<"Sexo: "<<a.sexo<<endl;

						cout<<"Data de nascimento: "<<a.data_nascimento<<endl;

						cout<<"Curso: ";
						switch(a.curso) {
							case 1:
								cout<<"Eng. Comp.";
								break;
							case 2:
								cout<<"Ciên. Comp.";
								break;
							case 3:
								cout<<"Eng. Prod.";
								break;
							case 4:
								cout<<"Admin.";
						}
					}
					arq.close();
				}
				cout<<endl;
			}
		}

		int alterar() {
			int alterar;
			alterar = 1;
			while (alterar != 5) {
				cout << "\t ________   _________   ________   ______________________   ________ \n";
				cout << "\t|  NOME  | |  CURSO  | |  SEXO  | |  DATA DE NASCIMENTO  | |  SAIR  |\n";
				cout << "\t|__<1>___| |___<2>___| |__<3>___| |_________<4>__________| |__<5>___|\n\t";
				cin >> alterar;
				system("cls");

				return alterar;
			}
		}

		void retornar() {
			cout<<"Retornando";
			Sleep(500);
			cout<<".";
			Sleep(500);
			cout<<".";
			Sleep(500);
			cout<<".";
			Sleep(1000);
		}
};
