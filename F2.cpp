#include <iostream>
using namespace std;
int Gera(int x, int y) {
    int r=0;
        int i = x;
        do {
            r=x*x;
        }
        while (i < y);
        return r;

}

int main() {
  cout << Gera(2,3);
  return 0;
}
