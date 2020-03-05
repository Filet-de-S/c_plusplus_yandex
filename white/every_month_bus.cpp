 #include <iostream>
#include <vector>
#include <string>

using namespace std;

int	main()
{
	int dl;
	cin >> dl;
	int w = 0;
	vector<vector<string>> dela(31);
	vector<string> fin;
	vector<int> d_mon = {30, 27, 30, 29, 30, 29, 30, 30, 29, 30, 29, 30};
	int im = 0;
	string cmd;
	int day;
	for (int i = 0; i < dl; ++i) {
		cin >> cmd;
		string task;
		if (cmd == "ADD") {
			cin >> day >> task;
			dela[day - 1].push_back(task);
		}
		else if (cmd == "NEXT") {
			int next = im + 1 > 11 ? 0 : im + 1;
			if (d_mon[im] > d_mon[next]) {
			    int tmp = 1 + d_mon[next];
				for (int i = d_mon[im]; tmp <= i; ++tmp) {
					dela[d_mon[next]].insert(end(dela[d_mon[next]]), begin(dela[tmp]), end(dela[tmp]));
				    }
			}
			dela.resize(d_mon[next] + 1);
			im = next;
		}
		else {
			cin >> day;
			string emp = "";
			w = 0;
			for (int i = 0; i < dela[day - 1].size(); ++i) {
			    if (dela[day - 1][i] == "")
			        ;
			    else {
			        w++;
                    if (emp == "")
                        emp += dela[day - 1][i];
                    else
                        emp += " " + dela[day - 1][i];
                }
			}

			emp = emp == "" ? to_string(w) : (to_string(w) + " " + emp);
            fin.push_back(emp);
		}
	}

	for (auto f : fin) {
	    cout << f << endl;
	}
}
