#include <iostream>  
#include <sstream>  
#include <string>  
#include <cmath>  

using namespace std;

int main() {
	double M[20][40];
	long long E[20][40];
	 
	// 打表  
	for (int i = 0; i <= 9; ++i) for (int j = 1; j <= 30; ++j) {
		double m = 1 - pow(2, -1 - i), e = pow(2, j) - 1;
		double t = log10(m) + e * log10(2);
		E[i][j] = t, M[i][j] = pow(10, t - E[i][j]);
	}

	// 输入并输出结果  
	string in;
	while (cin >> in && in != "0e0") {
		// 处理输入  
		for (string::iterator i = in.begin(); i != in.end(); ++i) if (*i == 'e') *i = ' ';
		istringstream ss(in);
		double A; int B;
		ss >> A >> B;
		while (A < 1) A *= 10, B -= 1;
		// 在打好的表中寻找答案  
		for (int i = 0; i <= 9; ++i) for (int j = 1; j <= 30; ++j) {
			if (B == E[i][j] && (fabs(A - M[i][j]) < 1e-4 || fabs(A / 10 - M[i][j]) < 1e-4)) {
				cout << i << ' ' << j << endl;
				break;
			}
		}
	}
}