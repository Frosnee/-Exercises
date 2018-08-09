#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

int n;
std::vector<char> naoRepetida(const std::string& s)
{
	std::map<char, int> frequencia;
	for (int i = 0; i<s.size(); i++)
	{
		frequencia[s[i]]++;
	}
	std::vector<char> deFora;
	for (auto it = frequencia.begin(); it != frequencia.end(); it++)
	{
		if (it->second == 1)
			deFora.push_back(it->first);
	}
	return deFora;
}


void tipoFrase(short int total) {
	if (total >= 26) {
		cout << "Frase Completa\n--------------------------------\n";
	}
	else if(total >= 13){
		cout << "Frase Quase Completa\n--------------------------------\n";
	}
	else {
		cout << "Frase Mal Elaborada\n--------------------------------\n";
	}
}

bool contemNumero(string &c) {
	return (c.find_first_of("0123456789") != string::npos);
}

void digitarFrase() {
	for (int x; x < n; x++) {
		short int i = 0;
		string frase;
		cout << "Insira a Frase: ";
		getline(cin, frase);
		if (frase.length() < 3 || frase.length() > 1000 || contemNumero(frase)) {
			cout << "A quantidade de caracteres(apenas letras) precisa ser maior que 3 e menor que 1000.\n";
			return digitarFrase();
		}
		for (char c : naoRepetida(frase))
		{
			i++;
		}
		tipoFrase(i);
	}
}

int main() {
	cout << "Quantidade de testes: ";
	cin >> n;
	if (cin.fail()) {
		cin.clear();
		cin.ignore();
		cout << "Por favor, entre com um numero.\n";
		return main();
	}
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	digitarFrase();
	system("pause");
	return 0;
}
