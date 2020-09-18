#include <iostream>
#include <vector>
#include <algorithm>

int L, C; // L: length of code, C: number of alphabet

char alphabet[16];
int min_jaeum = 2;
int min_moeum = 1;

std::vector<char> moeum = {'a', 'e', 'i', 'o', 'u'};

struct CodeMaster {
	int n_jaeum;
	int n_moeum;
	int last_idx;
	std::vector<char> code;

	CodeMaster(int _n_jaeum, int _n_moeum, int _last, std::vector<char> _code) :
		n_jaeum(_n_jaeum), n_moeum(_n_moeum), code(_code), last_idx(_last) {}
};

bool isPossible(CodeMaster& master, char add)
{
	if (master.code.size() >= L)
		return false;

	auto it = std::find(master.code.begin(), master.code.end(), add);
	if (it != master.code.end()) { 
		return false;
	}

	int n_jaeum = master.n_jaeum;
	int n_moeum = master.n_moeum;
	it = std::find(moeum.begin(), moeum.end(), add);
	if (it != moeum.end()) { // add is moeum
		n_moeum += 1;
	}
	else {
		n_jaeum += 1;
	}

	int n_needed = 0;
	if (n_moeum < min_moeum)
		n_needed += (min_moeum - n_moeum);

	if (n_jaeum < min_jaeum)
		n_needed += (min_jaeum - n_jaeum);

	if (n_needed > L - master.code.size() - 1)
		return false;

	// add 'add' to master
	master.n_jaeum = n_jaeum;
	master.n_moeum = n_moeum;
	master.code.push_back(add);

	return true;
}

void dfs(CodeMaster& codeMaster)
{
	if (codeMaster.code.size() == L) {
		
		codeMaster.code.push_back('\0');
		std::cout << codeMaster.code.data() << std::endl;

		return;
	}

	int maxIdx = C - (L - codeMaster.code.size() - 1);
	for (int i = codeMaster.last_idx + 1; i < maxIdx; i++)
	{
		CodeMaster next = codeMaster;
		if (isPossible(next, alphabet[i])) {
			next.last_idx = i;
			dfs(next);
		}
	}
}

int main()
{
	std::cin >> L >> C;

	for (size_t i = 0; i < C; i++)
	{
		std::cin >> alphabet[i];
	}

	std::sort(alphabet, alphabet + C);

	CodeMaster code(0, 0, -1, std::vector<char> {});
	dfs(code);
	return 0;
}