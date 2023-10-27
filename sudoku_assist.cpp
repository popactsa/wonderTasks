#include <iostream>
#include <vector>
#include <array>
#include <string>

void pop_front(std::vector<int> &vec)
{
    vec.erase(vec.begin());
};

class sudoku_assistant{
    private:
        int positions;
        int sum;
        std::vector<int> numbers;
        std::vector<std::vector<int>> combination(std::vector<std::vector<int>> &hint_res, int depth, int tsum, int tpositions, std::vector<int> tnumbers, std::vector<int> chosen){
            int i;
            int* p;
            
                if (tsum == i || depth == 1){
                    chosen.push_back(i);
                    hint_res.push_back(chosen);
                    return hint_res;
                }
                else{
                    chosen.push_back(i);
                    pop_front(tnumbers);
                    combination(hint_res, depth + 1, tsum - i, tpositions, tnumbers, chosen);
                }
        };
    public:
        sudoku_assistant(int s, int n, std::vector<int> forbidden_numbers){
            sum = s;
            positions = n;
            bool sw;
            for (int i = 1; i <= 9; ++i){
                sw = 1;
                for (const auto j : forbidden_numbers){
                    if (j == i){
                        sw = 0;
                        break;
                    }
                }
                if (sw == 1){
                    numbers.push_back(i);
                }
            }
        };
        std::vector<std::vector<int>> hint(){
            std::vector<std::vector<int>> hint_res;
            std::vector<int> chosen;
            hint_res = combination(hint_res, 0, sum, positions, numbers, chosen);
            return hint_res;
        };
};

int main(){
    std::vector<int> forbidden_values = {2, 3};
    sudoku_assistant helpme(10, 3, forbidden_values);
    std::vector<std::vector<int>> res;
    res = helpme.hint();
    for (const auto it : res){
        for (const auto jt : it){
            std::cout<< jt << std::endl;
        }
    }
}