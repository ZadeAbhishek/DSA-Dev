using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  // Write your code here.
  // since Sequence Matters we cannot use set here not hashmap
   // Normal itr would work
   if(array.size() < sequence.size()) return false;
   int count = 0; // this should to end of the sequence 
   for(auto& num : array){
       if(num == sequence[count]) count++;
       if(count == sequence.size()) return true;
   }
  return false;
}
