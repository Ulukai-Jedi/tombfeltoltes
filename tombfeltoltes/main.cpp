#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

template <class T>
void kiir (const std::vector<T>& tomb){
    for (int i = 0; i < tomb.size(); i++) {
        std::cout << tomb[i] << " ";
    }
    std::cout<<std::endl;
}

void rendez(std::vector<int>& tomb) {
    for (int i = 1; i < tomb.size(); i++) {
        int j = i - 1;
        while (j >= 0 && tomb[j] > tomb[j + 1]) {
            int k = tomb[j];
            tomb[j] = tomb[j + 1];
            tomb[j + 1] = k;
            j--;
        }
    }
}

int main() {
	std::vector<int> A1;
    std::vector<int> A2;
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 10000);

    for (int i = 0; i < 10; i++) {
        A1.push_back(uniform_dist(e1));
    }
    
    for (int i = 0; i < 15; i++) {
        A2.push_back(uniform_dist(e1));
    }
    
    kiir<int>(A1);
    kiir<int>(A2);

    //std::sort(A1.begin(), A1.end()); C++ saját függvénye a rendezésre! :)
    //std::sort(A2.begin(), A2.end());

    rendez(A1);
    rendez(A2);

    kiir<int>(A1);
    kiir<int>(A2);

    std::vector<int> A3;
    int k = 0;
    int l = 0;
    for (int i = 0; i < A1.size() + A2.size(); i++) {
        if (l >= A2.size() ||  A1[k] < A2[l]) {
            A3.push_back(A1[k]);
            k++;
        }
        else {
            A3.push_back(A2[l]);
            l++;
        }
    }
    kiir<int>(A3);

    return 0;
 }

/*Ciklus i : = (E + 1) - tõl U - ig
j: = i - 1
Ciklus amíg j >= E és a[j] > a[j + 1]
Csere(j, j + 1)
j : = j - 1
Ciklus vége
Ciklus vége*/