class ProductOfNumbers {
public:
    vector<int> arr;
    int n;
    ProductOfNumbers() {
        arr.push_back(1);
        n=0;
    }
    
    void add(int num) {
        if(num!=0){
            arr.push_back(num*arr[n]);
            n++;
        } 
        else{
            arr = {1};
            n=0;
        }
    }
    
    int getProduct(int k) {
        return k<arr.size() ? arr[n]/arr[n-k] : 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */