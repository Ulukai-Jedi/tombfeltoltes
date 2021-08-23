#include <iostream>
#include <vector>
#include <random>

int main() {
	std::vector<int> A1;
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 10000);

    for (int i = 0; i < 10; i++) {
        A1.push_back(uniform_dist(e1));
    }
    
    for (int i = 0; i < A1.size(); i++) {
        std::cout << A1[i] << " ";
    }
 
}