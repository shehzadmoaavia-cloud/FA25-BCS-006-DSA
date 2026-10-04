#include <iostream>
#include <string>
using namespace std;

struct Item {
    string name;
    Item* prev;
    Item* next;
    Item(string n) { name = n; prev = NULL; next = NULL; }
};

struct Section {
    string name;
    Item* items;
    Section* prev;
    Section* next;
    Section(string n) { name = n; items = NULL; prev = NULL; next = NULL; }
};

struct Store {
    string name;
    string city;
    Section* sections;
    Store* prev;
    Store* next;
    Store(string n, string c) {
        name = n; city = c;
        sections = NULL; prev = NULL; next = NULL;
    }
};

class Inventory {
    Store* head;

    Store* findStore(string name) {
        for (Store* s = head; s != NULL; s = s->next)
            if (s->name == name) return s;
        return NULL;
    }
    Section* findSection(Store* st, string name) {
        for (Section* s = st->sections; s != NULL; s = s->next)
            if (s->name == name) return s;
        return NULL;
    }
public:
    Inventory() { head = NULL; }

    void addStore(string name, string city) {
        Store* st = new Store(name, city);
        if (head == NULL) { head = st; return; }
        Store* t = head;
        while (t->next != NULL) t = t->next;
        t->next = st;
        st->prev = t;
    }

    void addSection(string store, string section) {
        Store* st = findStore(store);
        if (st == NULL) { cout << "Store not found" << endl; return; }
        if (findSection(st, section) != NULL) {
            cout << "Section already exists" << endl;
            return;
        }
        Section* sec = new Section(section);
        if (st->sections == NULL) { st->sections = sec; return; }
        Section* t = st->sections;
        while (t->next != NULL) t = t->next;
        t->next = sec;
        sec->prev = t;
    }

    void addItem(string store, string section, string item) {
        Store* st = findStore(store);
        if (st == NULL) { cout << "Store not found" << endl; return; }
        Section* sec = findSection(st, section);
        if (sec == NULL) { cout << "Section not found" << endl; return; }
        Item* it = new Item(item);
        if (sec->items == NULL) { sec->items = it; return; }
        Item* t = sec->items;
        while (t->next != NULL) t = t->next;
        t->next = it;
        it->prev = t;
    }

    void removeItem(string store, string section, string item) {
        Store* st = findStore(store);
        if (st == NULL) { cout << "Store not found" << endl; return; }
        Section* sec = findSection(st, section);
        if (sec == NULL) { cout << "Section not found" << endl; return; }
        Item* t = sec->items;
        while (t != NULL && t->name != item) t = t->next;
        if (t == NULL) { cout << "Item not found" << endl; return; }
        if (t->prev != NULL) t->prev->next = t->next; else sec->items = t->next;
        if (t->next != NULL) t->next->prev = t->prev;
        delete t;
        cout << "Removed " << item << " from " << store << "/" << section << endl;
    }

    void displaySection(string store, string section) {
        Store* st = findStore(store);
        if (st == NULL) { cout << "Store not found" << endl; return; }
        Section* sec = findSection(st, section);
        if (sec == NULL) { cout << "Section not found" << endl; return; }
        cout << store << " -> " << section << ": ";
        if (sec->items == NULL) cout << "(empty)";
        for (Item* i = sec->items; i != NULL; i = i->next) cout << i->name << "  ";
        cout << endl;
    }

    void displayStore(string store) {
        Store* st = findStore(store);
        if (st == NULL) { cout << "Store not found" << endl; return; }
        cout << "Store: " << st->name << " (" << st->city << ")" << endl;
        for (Section* s = st->sections; s != NULL; s = s->next) {
            cout << "  " << s->name << ": ";
            if (s->items == NULL) cout << "(empty)";
            for (Item* i = s->items; i != NULL; i = i->next) cout << i->name << "  ";
            cout << endl;
        }
    }
};

int main() {
    Inventory inv;
    inv.addStore("Store-1", "Lahore");
    inv.addStore("Store-2", "Karachi");

    inv.addSection("Store-1", "Toys");
    inv.addSection("Store-1", "Grocery");
    inv.addSection("Store-1", "Fruits");
    inv.addSection("Store-2", "Toys");

    inv.addItem("Store-1", "Toys", "Car");
    inv.addItem("Store-1", "Toys", "Doll");
    inv.addItem("Store-1", "Grocery", "Rice");
    inv.addItem("Store-1", "Grocery", "Sugar");
    inv.addItem("Store-1", "Fruits", "Apple");
    inv.addItem("Store-2", "Toys", "Puzzle");

    inv.displaySection("Store-1", "Toys");
    inv.displayStore("Store-1");
    cout << endl;
    inv.removeItem("Store-1", "Toys", "Car");
    inv.displaySection("Store-1", "Toys");
    inv.displayStore("Store-2");
    return 0;}
