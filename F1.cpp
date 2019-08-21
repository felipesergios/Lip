#include <iostream>
using namespace std;
int Gera(int x, int y) {
    int r=0;
    for (int i = x; i <= y; i++) {
        r += i;
        }
        return r;

}

int main() {
  cout << Gera(5,8);
  return 0;
}
