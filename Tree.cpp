#include "Tree.h"

TreeDictionary::TreeDictionary() {
    
    _working = false;
    _root =  new TreeNode;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        _root->children[i] = nullptr;
    }
}

TreeDictionary::~TreeDictionary() {
    
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // делит рут
}

TreeDictionary::TreeNode* TreeDictionary::TreeNode::getNewNode(void) {
    // Выделяем память по новый узел
    struct TreeNode *pNode =  new TreeNode;

    // устанавливаем флаг конца слова в false
    pNode->isEndOfWord = false; 

    // инициализируем детей нулевым уазателем
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = nullptr;

    return pNode;
}

void TreeDictionary::TreeNode::insert(TreeNode* root, std::string key) {
    
    TreeNode* node = root; 
    
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a'; 

        // если указатель пустрой, создаем новый узел
        if (!node->children[index]) {
            node->children[index] = getNewNode();
        }
        node->children[index]->freq++;
        node = node->children[index];
    }
    // помечаем последний узлел как лист, т.е. конец слова
    node->isEndOfWord = true;
}

bool TreeDictionary::TreeNode::search(struct TreeNode*& root, std::string key) {
    
    for (int i = 0; i < key.length(); i++) 
    {
        int index = key[i] - 'a'; 
        if (!root->children[index]) {
            return false;
        }
        root = root->children[index]; 
    }
    return (root != nullptr); 
}

bool TreeDictionary::TreeNode::isEmpty(TreeNode* root) {
    
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            return false;
        }
    }
    return true;
} 

TreeDictionary::TreeNode* TreeDictionary::TreeNode::
remove(TreeNode* root, std::string key, int depth) { 
    // Если дерево пустое 
    if (!root)
        return nullptr;
  
    // если дошли до конца ключа 
    if (depth == key.size()) { 
  
        // Этот узел больше не конец слова 
        if (root->isEndOfWord)
            root->isEndOfWord = false; 
  
        // Если ключ не евляется префиксом, удаляем его
        if (isEmpty(root)) { 
            delete (root);
            root = nullptr;
        }

        return root;
    }

    // Если не дошли до конца ключа, рекурсивно вызываем для ребенка 
    // соответствующего символа 
    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth + 1); 
  
    // Если у корня нет дочернего слова 
    // (удален только один его дочерний элемент), 
    // и он не заканчивается другим словом. 
    if (isEmpty(root) && root->isEndOfWord == false) { 
        delete (root);
        root = nullptr; 
    }
  
    // возвращаем новый корень
    return root; 
}

void TreeDictionary::test_content() {
    _root->insert(_root, "start");
    _root->insert(_root, "star");
    _root->insert(_root, "computer");
    _root->insert(_root, "language");
    _root->insert(_root, "bridge");
    _root->insert(_root, "continue");
    _root->insert(_root, "slippers");
    _root->insert(_root, "witch");
    _root->insert(_root, "training");
    _root->insert(_root, "workout");
}

void TreeDictionary::find_w_f_p_recursion
(TreeNode* root, std::vector<std::string>& words, std::string pref, std::string postf) {

    if (root == _root) { return;}
    
    if(root->isEndOfWord) {
        std::string res = pref + postf;
        words.push_back(res);
    }
    
    for(int i = 0; i < ALPHABET_SIZE; ++i) {
        
        if(root->children[i] != nullptr) {
            char add_char = i + 'a';
            postf.push_back(add_char);
            find_w_f_p_recursion(root->children[i],words,pref,postf);
            postf.pop_back();
        }
    }
}

void TreeDictionary::find_words_for_prefixes
(std::vector<std::string>& words, std::string prefixes) {  
    
    TreeNode* root_for_find = _root;
    
    _root->search(root_for_find,prefixes);
    
    if (!root_for_find) {
        return;
    }
    
    std::string postfix;
    
    //вызываем рекурсивную функцию
    find_w_f_p_recursion(root_for_find, words, prefixes, postfix);
}
