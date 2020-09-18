#include <string>
#include <vector>

using namespace std;

bool isRight(string s) {
	int sum = 0;
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
			sum += 1;
		else
			sum -= 1;

		if (sum < 0)
			return false;
	}

	return true;
}

string convert_u(string s) {
	
	string temp = s.substr(1, s.length() - 2);
	for (size_t i = 0; i < temp.length(); i++)
	{
		if (temp[i] == '(')
			temp[i] = ')';
		else 
			temp[i] = '(';
	}

	return temp;
}

string convert(string s) {
	if (isRight(s))
		return s;

	string answer;
	// step 1
	if (s.length() == 0)
		return s;

	// step 2
	int sum = 0;
	string u, v;
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] == '(')
			sum += 1;
		else
			sum -= 1;

		if (sum == 0) {
			u = s.substr(0, i + 1);
			v = s.substr(i + 1);
			break;
		}
	}

	// step 3
	if (isRight(u)) {
		answer = u + convert(v);
		return answer;
	}
	else {
		answer += "(";
		answer += convert(v) + ")";
		answer += convert_u(u);
	}

	return answer;
}

string solution(string p) {
    string answer = convert(p);
    return answer;
}

int main()
{
	string s = ")(";
	string answer = solution(s);

	return 0;
}