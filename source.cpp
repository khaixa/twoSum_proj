#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>

std::vector<int> readNumbersFromFile(const std::string& filename){
    std::vector<int> numbers;
    std::ifstream file(filename);
    int num;
    while (file >> num){
        numbers.push_back(num);
    }
    file.close();
    return numbers;
}

long long performSummation(const std::vector<int>& numbers){
    long long sum = 0;
    int n = numbers.size();
    for (int i = 0; i < n; ++i){
        for (int j = i + 1; j < n; ++j){
            sum += numbers[i] + numbers[j];
        }
    }
    return sum;
}

int main(){
    std::string filename = "numbers.txt";
    std::vector<int> numbers = readNumbersFromFile(filename);

    clock_t start = clock();
    long long result = performSummation(numbers);
    clock_t end = clock();
    double seconds = double(end - start) / CLOCKS_PER_SEC;

    std::cout << "Sum: " << result << std::endl;
    std::cout << "Time: " << seconds << " seconds" << std::endl;


    return 0;
}