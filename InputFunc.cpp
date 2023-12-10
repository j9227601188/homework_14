#include "InputFunc.h"

void inputFunc()
{
    TreeDictionary test;
    test.test_content();
    
    //to select words
    std::vector<std::string> words;
    test._working = true;
    int choice{0};
    
    while(test._working) {
        
        words.clear();
        std::cout << "Введите начало слова: ";
        std::string prefix;
        std::cin >> prefix;
                
        //заполняем вектор доступными вариантами
        test.find_words_for_prefixes(words, prefix);
               
        //std::cout << words.back()<<'\n';
        //words.pop_back();
        
        if ( words.empty() ) {
            std::cout << "Not found\n";
        }
        
        while ( !words.empty() ) {
            
            std::cout << "Do you want to choose word: " << words.back() << "?\n"
            << "1 - YES, 2 - Next word, 0 - Abort the selection, 3 - Exit the program\n:";
            std::cin >> choice;
            
            switch (choice) {
                case 0:
                    //Abort;
                    words.clear();
                    break;
        
                case 1:
                    //YES;
                    std::cout <<"You entered the word \"" << words.back() 
                    << "\"\nWe continue to enter\n";
                    words.clear();
                    break;
                
                case 2:
                    //Next word;
                    words.pop_back();
                    if (words.empty() ) {
                        std::cout << "Not found\n";
                    }
                    break;
                
                case 3:
                    //Exit the program;
                    return;

                default:
                    std::cout <<"ERROR the enter, please repeat\n";
                    break;
            }
        }
    }
}
