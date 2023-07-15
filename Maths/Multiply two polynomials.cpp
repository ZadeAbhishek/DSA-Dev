#include<bits/stdc++.h>
using namespace std;

void operator<<(ostream &Cout, vector<int> temp){
    for(auto x : temp){
        Cout<<x<<" ";
    }
    Cout<<"\n";
}

vector<int> multiply_polynomial(vector<int> x , vector<int> y){
    vector<int> result(x.size() + y.size() - 1,0);

    for(int i = 0 ; i < x.size() ; i++){
        for(int j = 0 ; j < y.size() ; j++){
            result[i+j] += x[i] * y[j];
        }
    }
    return result;
}

int main(){
    vector<int> x = {5, 0, 10, 6};
    vector<int> y = {1, 2, 4};
    cout<<multiply_polynomial(x,y);
}

/*
First polynomial is 5 + 0x^1 + 10x^2 + 6x^3
Second polynomial is 1 + 2x^1 + 4x^2
Product polynomial is 5 + 10x^1 + 30x^2 + 26x^3 + 52x^4 + 24x^5

(x + y)(x + y) = (x*x + x*y) + (y*x + y*y);
*/