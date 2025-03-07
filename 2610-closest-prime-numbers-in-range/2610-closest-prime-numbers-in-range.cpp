class Solution {
    bool isPrime(int number){
        if(number<2)    return false;
        if(number==2 || number==3)  return true;
        if(number%2==0) return false;
        for(int i=3;i*i<=number;i+=2){
            if(number%i==0) return false;
        }
        return true;
    }

public:
    vector<int> closestPrimes(int left, int right) {
        int diff=INT_MAX;
        int A = -1, B = -1;
        int prevPrime = -1;

        for(int i=left;i<=right;i++){
            if(isPrime(i)){
                if(prevPrime){
                    int temp = i - prevPrime;
                    if(temp<diff){
                        diff = temp;
                        A = prevPrime;
                        B = i;
                    }

                    if(diff<=2) return {A, B};
                }
                prevPrime = i;
            }
        }

        return A==-1 ? vector<int>{-1, -1} : vector<int>{A, B};
    }
};