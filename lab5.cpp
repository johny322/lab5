#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;


int main(){
int i = 0;
float h = 0.000001;
long double I = 0, I2 = 0, d = 0;
const int n = 1000000;
static double x[n];
fstream f;
x[0] = 0.0;

for(i = 0; i <= n; i++){ x[i] = 0.0; }
for(i = 0; i <= n; i++){ x[i] = i * h; }
for(i = 0; i <= (n - 1); i++){
    I += ((1 / (1 + ((x[i] + x[i + 1]) / 2))) * (cos(100 * x[i]) - cos(100 * x[i + 1]))) / 100;
    }
cout << fixed << setprecision(16);
///cout << I << endl;

float H = 0.0000005;
const int N = 2000000;
static double y[N];
y[0] = 0.0;

for(i = 0; i <= N; i++){ y[i] = 0.0; }
for(i = 0; i <= N; i++){ y[i] = double(i * H); }
for(i = 0; i <= (N - 1); i++){
    I2 += double((double(1 / (1 + double((y[i] + y[i + 1]) / 2))) * double(double(cos(100 * y[i])) - double(cos(100 * y[i + 1])))) / 100);
    }

///cout << I2 << endl;
d = fabs(I2 - I) / 3;
///cout << d << endl;

f.open("ans1.dat", ios::out);
    if(f){
        f << I << " " << d << endl;
        cout << "Successfully" << endl << "File name: ans1.dat" << endl;
		f.close();
    }
	 else
		cout << "Error opening file for writing!" << endl;
}
