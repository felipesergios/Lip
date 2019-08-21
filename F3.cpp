#include <iostream>
using namespace std;
int Fat(int y) {
    int r=1;
    for (int i = 1; i <= y; i++) {
        r = r* i;
        }
        return r;
}
int SomaFat(int A , int B){
    int R = Fat(A)+Fat(B);
    return R;
}

int main() {
  cout << SomaFat(5,3);
  return 0;
}
