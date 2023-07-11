class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int,string>> convertion = {{1000, "M"},{900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
    string Roman = "";
    for(int i = 0 ; i < convertion.size(); i++){
        while(num >= convertion[i].first){
            Roman += convertion[i].second;
            num -= convertion[i].first; 
        }
    }

    return Roman;
}
};
// TC O(13) ~ O(1)