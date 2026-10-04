#include <iostream>
#include <string>
using namespace std;

struct Song {
    string title;
    Song* prev;
    Song* next;
    Song(string t) { title = t; prev = NULL; next = NULL; }
};

class Playlist {
    Song* head;
    Song* tail;
    Song* current;
public:
    Playlist() { head = tail = current = NULL; }

    void addSong(string title) {
        Song* s = new Song(title);
        if (head == NULL) { head = tail = current = s; return; }
        tail->next = s;
        s->prev = tail;
        tail = s;
    }

    void removeSong(string title) {
        Song* t = head;
        while (t != NULL && t->title != title) t = t->next;
        if (t == NULL) { cout << "Song not found: " << title << endl; return; }

        if (t->prev != NULL) t->prev->next = t->next; else head = t->next;
        if (t->next != NULL) t->next->prev = t->prev; else tail = t->prev;
        if (current == t) current = (t->next != NULL) ? t->next : t->prev;
        delete t;
        cout << "Removed: " << title << endl;
    }

    void playNext() {
        if (current == NULL) { cout << "Playlist is empty" << endl; return; }
        if (current->next == NULL) { cout << "Already at the last song" << endl; return; }
        current = current->next;
        cout << "Now playing: " << current->title << endl;
    }

    void playPrevious() {
        if (current == NULL) { cout << "Playlist is empty" << endl; return; }
        if (current->prev == NULL) { cout << "Already at the first song" << endl; return; }
        current = current->prev;
        cout << "Now playing: " << current->title << endl;
    }

    void nowPlaying() {
        if (current != NULL) cout << "Now playing: " << current->title << endl;
    }

    void displayForward() {
        cout << "Forward : ";
        for (Song* t = head; t != NULL; t = t->next) cout << t->title << "  ";
        cout << endl;
    }

    void displayBackward() {
        cout << "Backward: ";
        for (Song* t = tail; t != NULL; t = t->prev) cout << t->title << "  ";
        cout << endl;
    }
};

int main() {
    Playlist p;
    p.addSong("Song 1");
    p.addSong("Song 2");
    p.addSong("Song 3");
    p.addSong("Song 4");

    p.displayForward();
    p.displayBackward();
    p.nowPlaying();
    p.playNext();
    p.playNext();
    p.playPrevious();
    p.removeSong("Song 2");
    p.displayForward();
    p.playNext();
    p.playNext();
    p.playPrevious();
    return 0;
}
