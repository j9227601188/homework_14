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
        
        //Inserts a word into the tree
        void insert(TreeNode* root, std::string);
        
        // Returns true if the key is in the tree, otherwise false
        bool search(TreeNode*&, std::string);
        
        // Returns true if root has a leaf, otherwise false
        bool isEmpty(TreeNode*);
        
        // Recursive key removal function from the tree
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
