// TEST DRIVEN DEVELOPMENT

#include <bits/stdc++.h>
using namespace std;

class Person {
public:
    string gender;
    int age;

    Person(string g, int a) : gender(g), age(a) {}
};

class Paper {
public:
    vector<string> topics;

    Paper(vector<string> t) : topics(t) {}
};

class Evaluator {
private:
    unordered_map<string, unordered_set<string>> trendingTopics;

public:
    Evaluator() {
        trendingTopics["female_young"] = {"fashion", "entertainment"};
        trendingTopics["female_middle"] = {"healthcare", "fashion"};
        trendingTopics["female_old"] = {"healthcare"};
        
        trendingTopics["male_young"] = {"sports", "entertainment"};
        trendingTopics["male_middle"] = {"sports", "healthcare"};
        trendingTopics["male_old"] = {"healthcare"};
    }

    bool evaluate(Paper* sundayPaper, Person* person) {
        string demographicKey;
        if (person->gender == "female") {
            if (person->age < 25) demographicKey = "female_young";
            else if (person->age < 50) demographicKey = "female_middle";
            else demographicKey = "female_old";
        } else if (person->gender == "male") {
            if (person->age < 25) demographicKey = "male_young";
            else if (person->age < 50) demographicKey = "male_middle";
            else demographicKey = "male_old";
        }

        const unordered_set<string>& topicsSet = trendingTopics[demographicKey];

        for (const string& topic : sundayPaper->topics) {
            if (topicsSet.count(topic)) {
                return true;
            }
        }
        return false;
    }
};

// Test cases
void runTests() {
    Paper sunday_1({"entertainment", "fashion", "sports", "healthcare"});
    Paper sunday_2({"fashion", "sports", "healthcare"});
    Paper sunday_3({"entertainment", "healthcare"});
    Paper sunday_4({"fashion", "sports", "healthcare"});
    Paper sunday_5({"sports", "healthcare"});

    Person youngFemale("female", 20);
    Person middleAgedMale("male", 35);
    Person olderFemale("female", 60);

    Evaluator evaluator;

    cout << "Test 1: " << (evaluator.evaluate(&sunday_1, &youngFemale) ? "Interested" : "Not Interested") << endl;
    cout << "Test 2: " << (evaluator.evaluate(&sunday_2, &middleAgedMale) ? "Interested" : "Not Interested") << endl;
    cout << "Test 3: " << (evaluator.evaluate(&sunday_3, &olderFemale) ? "Interested" : "Not Interested") << endl;
    cout << "Test 4: " << (evaluator.evaluate(&sunday_4, &middleAgedMale) ? "Interested" : "Not Interested") << endl;
    cout << "Test 5: " << (evaluator.evaluate(&sunday_5, &youngFemale) ? "Interested" : "Not Interested") << endl;
}

int main() {
    runTests();
    return 0;
}