#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(const string& str) {
	map<char, int> m;
	for (auto& c : str) {
		m[c]++;
	}
	return m;
}

int	main() {
	int count_cmd;
	cin >> count_cmd;

	string first, second;
	for (int i = 0; i < count_cmd; i++) {
		cin >> first >> second;
		if (BuildCharCounters(first) == BuildCharCounters(second))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
