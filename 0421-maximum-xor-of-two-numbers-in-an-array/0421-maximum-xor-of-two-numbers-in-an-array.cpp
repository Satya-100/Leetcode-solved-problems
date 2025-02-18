struct Node {
    Node* links[2];

    bool containsBit(int bit){
        return links[bit]!=NULL;
    }

    void put(int bit, Node* node){
        links[bit]=node;
    }

    Node* get(int bit){
        return links[bit];
    }
};

class Trie {
private:
    Node* root;

public:
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node* node = root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if(!node->containsBit(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num){
        Node* node = root;
        int res = 0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i) & 1;
            if(node->containsBit(1-bit)){
                res = res ^ (1<<i);
                node = node->get(1-bit);
            }
            else    node = node->get(bit);
        }
        return res;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for(int i: nums)    trie.insert(i);
        int ans = 0;

        for(int i: nums){
            ans = max(ans, trie.getMax(i));
        }

        return ans;
    }
};