#include<bits/stdc++.h>

using namespace std;

class Sprint;
class User;
class Task;

enum TaskStatus {
    OPEN,
    IN_PROGRESS,
    RESOLVED,
    DELAYED,
    COMPLETED
};
enum TaskType {
    STORY,
    FEATURE,
    BUG
};

class User {
    vector < Task > taskList;
    vector < Sprint > sprintList;

    public:
    Task createTask(TaskType);
    Task createTask(string);
    Sprint createSprint(int, int, string);
    bool addToSprint(Sprint & , Task & );
    bool removeFromSprint(Sprint & , Task & );
    bool changeStatus(Task & , TaskStatus);
    void printAllTasks();
};

class Task {
    int id;
    string substract;
    User user;
    TaskType tasktype;
    TaskStatus taskstatus;

    public:
    void setSubstract(string);
    void setUser(User);
    void setTasktype(TaskType);
    void setTaskstatus(TaskStatus);
    int getId();
    int getUniqueId();
    Task();

};

int Task::getUniqueId() {
    static int taskId = 1;
    return taskId++;
}

int Task::getId() {
    return this -> id;
}

void Task::setSubstract(string substract) {
    this -> substract = substract;
}

void Task::setUser(User user) {
    this -> user = user;
}

void Task::setTasktype(TaskType tasktype) {
    this -> tasktype = tasktype;
}

void Task::setTaskstatus(TaskStatus taskstatus) {
    this -> taskstatus = taskstatus;
}

Task::Task() {
    this -> taskstatus = TaskStatus::OPEN;
    this -> id = getUniqueId();
}

class Sprint {
    int begin;
    int end;
    string name;
    vector < Task > tasks;

    public:
        int getBegin();
    int getEnd();
    string getName();
    const vector < Task > & getTasks() const;
    Sprint(int, int, string);
    void addTask(Task & );
    void printDetails();
    void eraseTask(int taskNumber);
};

void Sprint::eraseTask(int taskNumber) {
    tasks.erase(tasks.begin() + taskNumber);
}

void Sprint::addTask(Task & task) {
    this -> tasks.push_back(task);
}

void Sprint::printDetails() {
    cout << "Sprint Name: " << this -> name << "\nSprint Begin: " << this -> begin << "\nSprint Ends: " << this -> end << endl;
}

const vector < Task > & Sprint::getTasks() const {
    return tasks;
}

int Sprint::getBegin() {
    return this -> begin;
}

int Sprint::getEnd() {
    return this -> end;
}

string Sprint::getName() {
    return this -> name;
}

Sprint::Sprint(int begin, int end, string name) {
    this -> begin = begin;
    this -> end = end;
    this -> name = name;
}

Sprint User::createSprint(int begin, int end, string name) {
    Sprint sprint(begin, end, name);
    sprintList.push_back(sprint);

    return sprint;
}

bool User::addToSprint(Sprint & sprint, Task & task) {
    for (Sprint spr: sprintList) {
        if ((spr.getBegin() == sprint.getBegin()) && (spr.getEnd() == sprint.getEnd()) && (spr.getName()) == sprint.getName()) {
            sprint.addTask(task);
            return true;
        }
    }
    return false;
}

bool User::removeFromSprint(Sprint & sprint, Task & task) {

    vector < Task > taskList;
    for (Sprint spr: sprintList) {
        if ((spr.getBegin() == sprint.getBegin()) && (spr.getEnd() == sprint.getEnd()) && (spr.getName()) == sprint.getName()) {
            taskList = sprint.getTasks();
            break;
        }
    }
    int i = 0;
    for (Task t: taskList) {
        if (t.getId() == task.getId()) {
            sprint.eraseTask(i);
            return true;
        }
        i++;
    }
    return false;

}

void User::printAllTasks() {
    for (Task task: taskList) {
        cout << task.getId() << " ";
    }
    cout << endl;
}

bool User::changeStatus(Task & task, TaskStatus status) {

    for (Task & t: taskList) {
        if (t.getId() == task.getId()) {
            t.setTaskstatus(status);
            return true;
        }
    }
    return false;

}

Task User::createTask(TaskType tasktype) {
    if (tasktype == TaskType::STORY) {
        cout << "Warning! Task of type STORY is Created with no Substract." << endl;
    }
    Task task;
    task.setTasktype(tasktype);
    task.setUser( * this);
    taskList.push_back(task);
    return task;
}

Task User::createTask(string substact) {
    Task task;
    task.setTasktype(TaskType::STORY);
    task.setSubstract(substact);
    task.setUser( * this);
    taskList.push_back(task);
    return task;
}

int main() {
    User user1, user2;
    Task task1 = user1.createTask(TaskType::FEATURE);
    Task task11 = user1.createTask(TaskType::BUG);
    Task task2 = user2.createTask(TaskType::BUG);
    Task task22 = user2.createTask("This is a subtract");

    Sprint sprint1 = user1.createSprint(22, 33, "Sprint1");
    Sprint sprint2 = user2.createSprint(44, 55, "Sprint2");

    cout << user1.changeStatus(task11, TaskStatus::IN_PROGRESS) << endl; //1

    cout << user1.addToSprint(sprint1, task1) << "\n"; //1
    cout << user1.addToSprint(sprint1, task11) << "\n"; //1
    cout << user1.addToSprint(sprint2, task1) << "\n"; //0
    cout << user1.removeFromSprint(sprint1, task11) << "\n"; //1
    cout << user2.addToSprint(sprint1, task1) << "\n"; //0
    cout << user2.removeFromSprint(sprint1, task2) << "\n"; //0
    cout << user2.addToSprint(sprint2, task1) << "\n"; //1
    cout << user2.addToSprint(sprint2, task2) << "\n"; //1

    sprint1.printDetails();
    cout << endl;
    user1.printAllTasks();
}