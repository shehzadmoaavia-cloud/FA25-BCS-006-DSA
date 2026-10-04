#include <iostream>
#include <string>
using namespace std;

struct Task {
    string name;
    int priority;
    string status;            // pending, in-progress, completed
    Task* next;
    Task(string n, int p, string s) { name = n; priority = p; status = s; next = NULL; }
};

class Scheduler {
    Task* head;
    Task* tail;
    Task* current;            // last task that was given to the CPU
public:
    Scheduler() { head = tail = current = NULL; }

    void addTask(string name, int priority, string status) {
        Task* t = new Task(name, priority, status);
        if (head == NULL) { head = tail = t; t->next = t; return; }
        tail->next = t;
        t->next = head;       // keep it circular
        tail = t;
    }

    void removeTask(string name) {
        if (head == NULL) { cout << "No tasks" << endl; return; }
        Task* prev = tail;
        Task* cur = head;
        bool found = false;
        do {
            if (cur->name == name) { found = true; break; }
            prev = cur;
            cur = cur->next;
        } while (cur != head);

        if (!found) { cout << "Task not found: " << name << endl; return; }

        if (cur == head && cur == tail) {          // only one task
            head = tail = current = NULL;
        } else {
            prev->next = cur->next;
            if (cur == head) head = cur->next;
            if (cur == tail) tail = prev;
            if (current == cur) current = prev;
        }
        delete cur;
        cout << "Removed task: " << name << endl;
    }

    Task* getNextTask() {
        if (head == NULL) return NULL;
        Task* start = (current == NULL) ? head : current->next;
        Task* t = start;
        do {
            if (t->status == "pending") { current = t; return t; }
            t = t->next;
        } while (t != start);
        return NULL;          // no pending task
    }

    void updateStatus(string name, string status) {
        if (head == NULL) { cout << "No tasks" << endl; return; }
        Task* t = head;
        do {
            if (t->name == name) {
                t->status = status;
                cout << "Updated: " << t->name << " | priority " << t->priority
                     << " | " << t->status << endl;
                return;
            }
            t = t->next;
        } while (t != head);
        cout << "Task not found: " << name << endl;
    }

    void displayAll() {
        if (head == NULL) { cout << "No tasks" << endl; return; }
        Task* t = head;
        do {
            cout << t->name << " | priority " << t->priority << " | " << t->status << endl;
            t = t->next;
        } while (t != head);
    }
};

int main() {
    Scheduler s;
    s.addTask("Design", 1, "pending");
    s.addTask("Coding", 2, "in-progress");
    s.addTask("Testing", 3, "pending");
    s.addTask("Deploy", 2, "completed");

    cout << "--- All tasks ---" << endl;
    s.displayAll();

    cout << "--- Round robin ---" << endl;
    for (int i = 0; i < 3; i++) {
        Task* t = s.getNextTask();
        if (t != NULL) cout << "Next task: " << t->name << endl;
        else cout << "No pending task" << endl;
    }

    cout << "--- Update / Remove ---" << endl;
    s.updateStatus("Design", "completed");
    s.updateStatus("Coding", "pending");
    s.removeTask("Deploy");
    s.displayAll();

    Task* t = s.getNextTask();
    if (t != NULL) cout << "Next task: " << t->name << endl;
    return 0;
}
