#include <cmath>
#include <iostream>
#include <numeric>
#include <vector>

/*double waverage(std::vector<double>) {
  int i = 0;
  std::vector<double> sigma;
  std::vector<double> values;
  int n = sigma.size();
  int p = values.size();
  std::vector<double> pesi;
  while (i < (n / 2)) {
    sigma.push_back(2 * i + 1);
    double wi = 1 / (sigma[2 * i + 1] * sigma[2 * i + 1]);
    pesi.push_back(wi);
    ++i;
  }
  while (i < (p / 2)) {
    values.push_back(2 * i);
    ++i;
  }
  std::vector<double> prod;
  while (i < p && i < n) {
    double pr = sigma[i] * values[i];
    prod.push_back(pr);
    ++i;
  }
  double num = std::accumulate(prod.begin(), prod.end(), 0.);
  double den = std::accumulate(pesi.begin(), pesi.end(), 0.);
  double wa = num / den;
  return wa;
*/
double waverage(std::vector<double> values) {
  int ix = 0;
  int iy = 1;
  int size = values.size();
  int n = size - 1;
  double num = 0.;
  /*
  while (iy <= n) {
    num += values[ix] * (1 / (values[iy] * values[iy]));
    ix = ix + 2;
    iy = iy + 2;
  }
  */
  for (; iy != n;)
  {
    num += values[ix] * (1 / (values[iy] * values[iy]));
    ix = ix + 2;
    iy = iy + 2;
  }

  
  /*
  while (iy <= n){
    den += (1/(values[iy]*values[iy]));
    iy = iy + 2;
  }
  */
 double den = 0.;
 for(; iy != n;)
 {
   den += (1/(values[iy]*values[iy]));
    iy = iy + 2;
 }
  double ans = num / den;
  return ans;
}

int main() {
  std::vector<double> input;
  for (double d; std::cin >> d;) {
    input.push_back(d);
  }
  double wa1 = waverage(input);
  std::cout << wa1 << '\n';
}