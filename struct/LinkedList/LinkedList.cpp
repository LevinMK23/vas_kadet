#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

struct Node{
    int val;
    Node *l, *r;
    Node(){
        l = nullptr;
        r = nullptr;
    }
};

struct LinkedList{
    int size;
    Node *first, *last;
    
    LinkedList(){
        last = new Node();
        first = last;
        size = 0;
    }
    
    void addBack(int el){
        if(size == 0){
            last = new Node();
            first = last;
            last->val = el;
        }
        else {
            Node *node = new Node();
            node->val = el;
            last->r = node;
            node->l = last;
            last = node;
        }
        size++;
    }
    
    void addFront(int el){
        if(size == 0){
            last = new Node();
            first = last;
            last->val = el;
        }
        else {
            Node *node = new Node();
            node->val = el;
            first->l = node;
            node->r = first;
            first = node;
        }
        size++;
    }
    
    void showList(){
        Node *t = first;
        while(t != nullptr){
            cout << t->val << " ";
            t = t->r;
        }
        cout << endl;
    }
};

int toInt(string s){
    int ans = 0, r = 1;
    for(int i = (int)s.size() - 1; i >= 0; i--){
        ans += (s[i] - '0') * r;
        r *= 10;
    }
    return ans;
}

int main(){
    LinkedList list;
    for (int i = 0; i < 30; i++) {
        list.addFront(i+1);
    }
    list.showList();
    list.showList();
}
