
struct Node{
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch){ // containskey means usko hamlog daal skte h or new ref. bna skte hai 
        if(links[ch-'a']!=NULL) return true;
        return false;
    }
    void put(char ch , Node* temp){
        links[ch-'a']=temp ;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void setEnd(){
       flag = 1;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie {
private :  Node*root ;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root ;
        for(int i=0;i<word.size();i++){
            if(!temp->containsKey(word[i])){
                temp->put(word[i],new Node());
            }
            // moves to the new reference trie
            temp = temp->get(word[i]);
        }
        temp->setEnd();
    }
    
    bool search(string word) {
        Node* temp = root;
        for(int i=0;i<word.size();i++){
            if(!temp->containsKey(word[i])) return false ;
            temp = temp->get(word[i]);
        }
        return temp->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* temp = root ;
      for(int i=0;i<prefix.size();i++){
          if(!temp->containsKey(prefix[i])){
              return false ;
          }
          temp = temp->get(prefix[i]);
      }
      return true ;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */