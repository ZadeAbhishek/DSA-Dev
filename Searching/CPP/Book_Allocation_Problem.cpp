/*
 Book allocation problem this is template to similar problem in which binary search is used
 for example ships and days problem. So basically learn it throughly

 problem statement
 there are i books in books vector in which books[i] represent total page number of book
 there are m student we have to distribute book to student in such as way
 1. Everyone will get alteast one book
 2. Book allocation is contigious
 
 return max number of book that can be allocate to student minimally
 if no present return -1

 for example
 m = 2 books = [10,20,30,40]
 so we can distrubute this in following way

 1. 10 | 20 30 40    ----> 10 | 90 ---max--> 90
 2. 10 20 | 30 40    ----> 30 | 70 ---max--> 70
 3. 10 20 30 | 40    ----> 60 | 40 ---max--> 60 

 here we can see last combination gives us 60 max to one student which is minimum of all the combination

 approch is simple think like binary search

 start = 10 (min of array)
 end = 100 (sum of array)

we are taking sum of array as end becuase no matter what for given example count will not go above 100
now we have range 
apply binary search
********************************************************
itr1.
s = 10
e = 100
mid = (10+100)/2 = 55
1-> 10+20 = 30 we cannot add 30 to this since it will be more than value of mid(55) 
               so we add to next iteration
2-> 30     we cannot add 40
 
3-> 40

now distribution count is more than our 2 we have this combination is not poosible
so if 55 takes 3 distribution that means it is not sufficent so we have to increse range
therefore start will become mid + 1 ie start = 56 e = 100

*********************************************************
itr2.
s = 56
e = 100
m = (56+100)/2 = 78
1-> 10+20+30
2-> 40
since is equal to student return true
this means 78 might be our ans but we can one thing if 78 is possible then greater than 78 is also possible 
therefore we will search less than 78 
so start = 56 end = 77

*********************************************************
itr3.
s = 56
e = 77
m = (56+77)/2 = 61
1-> 10+20+30
2-> 40
since is equal to student return true
this means 61 might be our ans but we can one thing if 61 is possible then greater than 61 is also possible 
therefore we will search less than 61 
so start = 56 end = 60

*********************************************************
itr4.
s = 56
e = 60
m = (56+60)/2 = 58
1-> 10+20
2-> 30
3-> 40
no posible we return false 
update start = 59
end = 60

*********************************************************
itr5.
s = 59
e = 60
m = (59+60)/2 = 59
1-> 10+20
2-> 30
3-> 40
no posible we return false 
update start = 60
end = 60

*********************************************************
itr6.
s = 60
e = 60
m = (60+60)/2 = 60
1-> 10+20+30
2-> 40
possible return true
update e = 59 
there start = 60 and end = 59 
start > end return mid i.e 60

60 will our answer

*/

//implementation
#include<iostream>
#include<vector>
#include<numeric>

bool check_Partition(std::vector<int> books, int students, int mid){
    int sum = 0;
    int count = 1;
    for(int x : books){
        if(sum + x > mid) count++,sum = 0;
        sum += x;
    }
    if(count > students) return false;
    return true;
}


int get_Max_Distribution(std::vector<int> books, int students){
    int start = 0;
    int end = std::accumulate(books.begin(),books.end(),0);
    int mid;
    int ans = -1;
    while(start <= end){
        mid = (start + end)/2;
        if(check_Partition(books,students,mid)){
            ans = mid;
            end = mid - 1;
        }
        else start = mid + 1;
    }
    return ans;
}


int main(){
    std::vector<int> books = {10,20,30,40};
    int students = 2;
    std::cout<<get_Max_Distribution(books,students)<<"\n";
}
