class TrieNode {
public:
    char ch;
    TrieNode* child[26];
    int wordend;
    
    TrieNode(char c){
        ch=c;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        wordend=0;
    }
};


class Trie {
public:
    TrieNode *root=NULL;
    Trie() {
        root=new TrieNode('\0');
    }
    
    void insert(string word) {
        TrieNode *curr=root;
        for(int i=0;i<word.length();i++){
            int index=word[i]-'a';
            if(curr->child[index]==NULL){
                curr->child[index]=new TrieNode(word[i]);
            }
            
            curr=curr->child[index];
        }
        curr->wordend++;
    }
    
    bool search(string word) {
        TrieNode *curr=root;
        for(int i=0;i<word.length();i++){
            int index=word[i]-'a';
            if(curr->child[index]==NULL){
                return false;
            }
            
            curr=curr->child[index];
        }
        return curr->wordend>0?true:false;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr=root;
        for(int i=0;i<prefix.length();i++){
            int index=prefix[i]-'a';
            if(curr->child[index]==NULL){
                return false;
            }
            
            curr=curr->child[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
