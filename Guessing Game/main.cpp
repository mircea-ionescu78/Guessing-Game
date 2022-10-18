#include <iostream>
#include <vector>

int life = 0;
int difficulty_input = 0;
int word = 0;
int temp_right,temp_index = 0;
bool menu_flag = true;
//This is a comment
//is it gonna work?
std::string str_input = "";

std::vector<std::string> guessed_letters;

std::vector<std::vector<std::string>> easy_words = {
    {"a","p","p","l","e"},
    {"c","a","r"},
    {"c","h","e","e","s","e"},
    {"c","o","l","d"},
    {"w","a","v","e"},
    {"b","o","a","t"},
    {"h","e","a","l"},
    {"f","o","u","r"}
};

std::vector<std::vector<std::string>> medium_words = {
    {"c","h","o","s","e","n"},
    {"f","i","s","h","e","r","m","a","n"},
    {"a","t","t","e","n","t","i","o","n"},
    {"p","i","x","e","l"},
    {"z","o","m","b","i","e"},
    {"r","h","y","t","h","m"},
    {"j","u","m","p","e","r"},
    {"j","o","g","g","e","r"}
};

std::vector<std::vector<std::string>> hard_words = {
    {"c","r","y","p","t"},
    {"e","m","b","e","z","z","l","e"},
    {"v","o","o","d","o","o"},
    {"o","x","i","d","i","z","e"},
    {"w","y","v","e","r","n"},
    {"s","p","h","i","n","x"},
    {"h","a","z","a","r","d"},
    {"b","l","i","z","z","a","r","d"}
};



void filling(){
    for(int i = 0; i < easy_words[word].size(); i++){
        guessed_letters.push_back("_");
    }
}

void Validation(){
        if(temp_index == 0){
            life = life - 1;
        }
        else{
            if(guessed_letters.size() == temp_right){
                word++;
                temp_right = 0;
                guessed_letters.clear();
                filling();
            }
            else if (word == 7){
                std::cout << "Do you still want to play? y/n\n";
                std::cin >> str_input;
                if(str_input == "y") menu_flag = true;
                else exit(0);
            }
        }
    temp_index = 0;
}

void EasyGame(){
    filling();
    while(life >= 0)
    {
        std::cout << "Lives: " << life << "\n";
        std::cout << "The word has " << easy_words[word].size() << " letters\n";
        
        for(int i = 0; i < guessed_letters.size(); i++){
            std::cout << guessed_letters[i];
        }
        
        std::cout << "\nGuess a letter: ";
        std::cin >> str_input;
        for(int i = 0; i < easy_words[word].size(); i++){
                if(str_input == easy_words[word][i]){
                    guessed_letters[i] = str_input;
                    temp_right++;
                    temp_index++;
            }
        }
        Validation();
    }
}
    
void MediumGame(){
    filling();
    while(life >= 0)
    {
        std::cout << "Lives: " << life << "\n";
        std::cout << "The word has " << medium_words[word].size() << " letters\n";
        
        for(int i = 0; i < guessed_letters.size(); i++){
            std::cout << guessed_letters[i];
        }
        
        std::cout << "\nGuess a letter: ";
        std::cin >> str_input;
        for(int i = 0; i < medium_words[word].size(); i++){
                if(str_input == medium_words[word][i]){
                    guessed_letters[i] = str_input;
                    temp_right++;
                    temp_index++;
            }
        }
        Validation();
    }
}

void HardGame(){
    filling();
    while(life >= 0)
    {
        std::cout << "Lives: " << life << "\n";
        std::cout << "The word has " << hard_words[word].size() << " letters\n";
        
        for(int i = 0; i < guessed_letters.size(); i++){
            std::cout << guessed_letters[i];
        }
        
        std::cout << "\nGuess a letter: ";
        std::cin >> str_input;
        for(int i = 0; i < hard_words[word].size(); i++){
                if(str_input == hard_words[word][i]){
                    guessed_letters[i] = str_input;
                    temp_right++;
                    temp_index++;
            }
        }
        Validation();
    }
}

int main() {

    
    while(menu_flag == true){
        std::cout << "--__-- Welcome to Guess The Word Game --__--\n";
        std::cout << "1 - Play on Easy Mode\n";
        std::cout << "2 - Play on Medium Mode\n";
        std::cout << "3 - Play on Hard Mode\n";
        std::cout << "4 - Quit\n";
        std::cin >> difficulty_input;
        switch (difficulty_input) {
            case 1:
                life = 8;
                menu_flag = false;
                EasyGame();
                break;
            case 2:
                life = 6;
                menu_flag = false;
                MediumGame();
                break;
            case 3:
                life = 4;
                menu_flag = false;
                HardGame();
                break;
            default:
                break;
        }
    }
    return 0;
}
