#include<bits/stdc++.h>
using namespace std;

enum Split{EQUAL,EXACT,PERCENTAGE};

class User;
class Expense;
class SplitWise;

class User{
    int id;
    string name;
    vector<pair<User,double>> UserExpenseSheet;
    double totalExpenseSofar;
    int getUniqueId();

    public:
    User(string &);
    int getId();
    string getName();
    vector<pair<user,double>> getUserExpenseSheet();
    double getTotalExpenseSofar();
    void addToUserExpenseSheet(User &, double);
    void printTotalBalance();
    bool operator== (const User& user)const; 
};

class Expense{
    int id;
    string description;
    Split split;
    vector<double> percentDistribution;
    vector<double> exactDistribution;
    int getUniqueId();
    User *creditor;
    vector<user> defaulters;
    double exactAmount;

public:
    
    Expense(User&,Split,vector<User>&,double);

    int getId() const { return id; }

    string getDescription() const { return description; }
    void setDescription(const string &description_) { description = description_; }

    Split getSplit() const { return split; }

    vector<double> getPercentDistribution() const { return percentDistribution; }
    void setPercentDistribution(const vector<double> &percentDistribution_) { percentDistribution = percentDistribution_; }

    vector<double> getExactDistribution() const { return exactDistribution; }
    void setExactDistribution(const vector<double> &exactDistribution_) { exactDistribution = exactDistribution_; }

    User* getCreditor() const { return creditor; }

    vector<user> getDefaulters() const { return defaulters; }

    double getExactAmount() const { return exactAmount; }
};

class SplitWise{
    vector<User> users;
    unordered_set<int> UserIds;
    bool calculateExpenses(Expenses&);
    bool verifyUsers(User&,vector<User>);
    vector<double> divideEqually(double,size_t);

    public:
    SplitWise(){}
    void registerUser(User&);
    void addExpense(Expense&);
    void printBalanceForAllUser();
    const vector<User>& getUser() const;

public:
    vector<User> getUsers() const { return users; }
};


//********************************8

vector<double> SplitWise::divideEqually(double totalAmount , size_t memeberCount){
    vector<double> parts;
    for(size_t i = 0 ; i < memeberCount; ++i){
        double part = trunc((100.0*totalAmount)/(memeberCount - i))/ 100.0;
        parts.push_back(part);
        totalAmount -= part;
    }

    return parts;
}

bool SplitWise::calculateExpenses(Expense& expense){

    User creditor = *expense.getCreditor();
    vector<User> defaulters = expense.getDefaulters();
    vector<double> amtPerHead;
    Switch(expense.getSplit()){
        case Split::EQUAL:
              amtPerHead = divideEqually(expense.getExactTotalAmount(),defaulters.size());
              for(size_t i = 0 ; i < defaulters.size(); i++){
                auto iter = find(users.begin(),user.end(),creditor);
                if(iter != users.end()){
                    iter->addtoUserExpenseSheet(defaulter[i],(-1)*amtPerHead[i]);
                }
                iter = find(users.begin(),user.end(),defaulters[i]);
                if(iter != users.end()){
                    iter->addtoUserExpenseSheet(creditor,amtPerHead[i]);
                }
              }  

        case Split::EXACT:

        case Split::PERCENTAGE:

        default:
             break;
    }
}

void SplitWise::printBalanceForAllUser(){
    for(User user: users) user.printTotalBalance();
}

 inline bool User::operator== (const User& user)const{
    return this->id == user.getId();

 }; 

void SplitWise::registerUser(User &user){
    if(userIds.find(user.getId() == userIds.end())){
        users.push_back(user);
        userIds.insert(user,getIds());
    }
}

void SplitWise::addExpense(Expense& expense){
    if(verifyUsers(*expense.getCreditor(),expense.getDefaulters()) == false){
        cout<<"Can't process expense. Kidly register all user and retry\n";
        return;
    }
    calculateExpenses(expense);
}

bool SplitWise::verifyUsers(User user,vector<User> users){
    if(find(users.begin(),users.end(),user) == users.end()) users.push_back(user);

    for(User usr: users){
        if(userIds.find(usr.getId()) == userIds.end()) return false;
     }
     return true;  
}

Expense::Expense(User& creditor,Split split, vector<User>& defaulters, double exactTotalAmount){
    this->creditor = &creditor;
    this->split = split;
    this->defaulters = defaulters;
    this->exactAmount = exactAmount;
    this->id = getUniqueId();
}

int Expense::getUniqueId(){
    static int userId = 1;
    return userId++;
}

User:User(string &name){
    this->name = name;
    this->id = getUniqueId();
    this->totalExpenseSoFar = 0;
    this->userExpenseSheet.clear();
}

void User::addToUserExpenseSheet(User & user, double value){
   if(*this == user) return;

   this->totalExpenseSofar += value;
   for(auto &newExpense : UserExpenseSheet){
       if(newExpense.first == user){
        newExpense.second += value;
        return;
       }
   }
   UserExpenseSheet.push_back(make_pair(user,value));
}

void User::printTotalBalance(){
    if(totalExpenseSofar > 0) cout<<this->getName().c_str <<" owes a total of "<<this->getTotalExpenseSofar <<"\n";
    else cout<<this->getName().c_str <<" owes back a total of "<<this->getTotalExpenseSofar * (-1) <<"\n";
}

int User::getUniqueId(){
    static int userId = 1;
    return userId++;
}

int User::getId(){
    return this->id;
}

string User::getName(){
    return this->name;
}

vector<pair<user,double>> User::getUserExpenseSheet(){
    return this->UserExpenseSheet;
}

double User::getTotalExpenseSofar(){
    return this->totalExpenseSofar;
}

int main(){}