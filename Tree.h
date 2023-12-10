#pragma once
#include <iostream>
#include <string>
#include <vector>

const int ALPHABET_SIZE = 26; 
  
class TreeDictionary
{
    public:
    struct TreeNode
    { 
        struct TreeNode *children[ALPHABET_SIZE];
        bool isEndOfWord;               //true for end of file
        int freq = 0;                   //for find prefix
    
        // New TreeNode
        TreeNode *getNewNode(void);     
        
        //Вставляет слово в дерево
        void insert(TreeNode* root, std::string);
        
        // Возврашает true если ключ есть в дереве, иначе false
        bool search(TreeNode*&, std::string);
        
        // Вохвращает true если root имеет лист, иначе false 
        bool isEmpty(TreeNode*);
        
        // Рекурсивная функция удаления ключа из дерева
        TreeNode* remove(TreeNode*, std::string, int);
    };
    
    TreeDictionary();
    ~TreeDictionary();
    TreeNode* _root;
    bool _working; //for exit
    
    void test_content(); //for testing
    
    void find_w_f_p_recursion(TreeNode*, std::vector<std::string>&, std::string, std::string);

    void find_words_for_prefixes(std::vector<std::string>&, std::string);
};
