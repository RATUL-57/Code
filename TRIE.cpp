#include <bits/stdc++.h>
using namespace std;

const int alphabet = 26;

class Node
{
public:
    bool endmark;
    int word_count;
    string word;
    Node *next[alphabet];

    Node() : endmark(false), word(""), word_count(0)
    {
        for (int i = 0; i < alphabet; i++)
        {
            next[i] = nullptr;
        }
    }
};

class TRIE
{
public:
    Node *root;

    TRIE() : root(new Node()) {}
    void insert_in_trie(Node * current, string given_word);
    bool search_in_trie(Node * current, string given_word);
    Node* search_node_in_trie(Node * current, string given_word);
    void display_all_word(Node *current, string line, int level);
    int word_count_for_prefix(string prefix);
    void find_word_by_ending(Node * current, char last, char end, int &total);
    int word_count_for_start_and_end(char start, char end);
    
};

void TRIE::insert_in_trie(Node * current, string given_word)
{
    int length = given_word.size();
    for (int i = 0; i < length; i++)
    {
        int index = given_word[i] - 'a';
        if (current->next[index] == nullptr)
        {
            current->next[index] = new Node();
        }
        current->word_count++;
        current = current->next[index];
    }
    current->endmark = true;
    current->word = given_word;
}

Node* TRIE::search_node_in_trie(Node * current, string given_word)
{
    int length = given_word.size();
    for (int i = 0; i < length; i++)
    {
        int index = given_word[i] - 'a';
        if (current->next[index] == nullptr)
        {
            return nullptr;
        }
        current = current->next[index];
    }
    return current;
}

bool TRIE::search_in_trie(Node * current, string given_word)
{
    int length = given_word.size();
    for (int i = 0; i < length; i++)
    {
        int index = given_word[i] - 'a';
        if (current->next[index] == nullptr)
        {
            return false;
        }
        current = current->next[index];
    }
    return current != nullptr && current->endmark;
}

void TRIE::display_all_word(Node *current, string line, int level)
{
    if (current == nullptr)
    {
        return;
    }

    if (current->endmark)
    {
        if (level < line.size())
        {
            line[level] = '\0';
        }
        else
        {
            line.push_back('\0');
        }
        cout << line << endl;
    }

    for (int i = 0; i < alphabet; i++)
    {
        if (current->next[i] != nullptr)
        {
            if (level < line.size())
            {
                line[level] = 'a' + i;
            }
            else
            {
                line.push_back('a' + i);
            }
            display_all_word(current->next[i], line, level + 1);
        }
    }
}

int TRIE::word_count_for_prefix(string prefix)
{
    Node *current = root;
    int length = prefix.size();
    for (int i = 0; i < length; i++)
    {
        int index = prefix[i] - 'a';
        if (current->next[index] == nullptr)
        {
            return 0;
        }
        current = current->next[index];
    }
    return current->word_count;
}

void TRIE::find_word_by_ending(Node* current, char last, char end, int& total)
{
    if (current == nullptr) {
        return;
    }

    if (current->endmark && last == end) {
        total++;
    }

    for (int i = 0; i < alphabet; i++) {
        if (current->next[i] != nullptr) {
            char nextChar = 'a' + i;
            find_word_by_ending(current->next[i], nextChar, end, total);
        }
    }
}

int TRIE::word_count_for_start_and_end(char start, char end)
{
    std::string letter = "";
    letter += start;
    Node* temp = search_node_in_trie(root, letter);
    if (temp == nullptr) {
        return 0;
    } else {
        int total = 0;
        find_word_by_ending(temp, start, end, total);
        return total;
    }
}


int main()
{
    TRIE tr;
    int total_word;
    cin >> total_word;
    while(total_word--)
    {
        string word;
        cin >> word;
        tr.insert_in_trie(tr.root,word);
    }
    
}
