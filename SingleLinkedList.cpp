#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    string line;
    double fraction;
    char character;
    Node *next;

    Node () : next(nullptr) {}
    Node(int val) : data(val), next(nullptr) {}
    Node(double frac) : fraction(frac), next(nullptr) {}
    Node(string str) : line(str), next(nullptr) {}
    Node(char ch) : character(ch), next(nullptr) {}
    Node(int val, string str, double frac, char ch) : data(val), line(str), character(ch), fraction(frac), next(nullptr) {}
};

class SingleLinkedList
{
public:
    Node *head;
    int size;
    SingleLinkedList() : head(nullptr), size(0) {}

    void insert_back(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = nullptr;
        }
        size++;
    }

    void insert_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void insert_after_node(Node *current, int val)
    {
        Node * temp = find_tail();
        if (current == temp)
        {
            insert_back(val);
        }
        else
        {
            Node *newNode = new Node(val);
            newNode->next = current->next;
            current->next = newNode;
            size++;
        }
    }

    void remove_front()
    {
        if (size == 0)
        {
            cout << "Underflow" << endl;
        }
        else if (size == 1)
        {
            head = nullptr;
            size--;
        }
        else
        {
            head = head->next;
            size--;
        }
    }

    void remove_back()
    {
        if (size == 0)
        {
            cout << "Underflow" << endl;
        }
        else if (size == 1)
        {
            head = nullptr;
            size--;
        }
        else
        {
            Node *temp = head;
            while (temp->next->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = nullptr;
            size--;
        }
    }

    Node *find_node(int val)
    {
        Node *temp = head;
        if(temp == nullptr)
            return nullptr;
        while (temp->next != nullptr)
        {
            if (temp->next->data == val)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    Node * find_tail()
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        return temp;
    }

    int find_tail_data()
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        return temp->data;
    }

    void display()
    {
        Node *current = head;
        if (head == nullptr)
        {
            cout << "Head=NULL, Tail=NULL Empty";
        }
        else
        {
            cout << "Head=" << head->data << ", Tail=" << find_tail_data() << " ";
            while (current != nullptr)
            {
                cout << current->data << " ";
                current = current->next;
            }
        }
        cout << endl;
    }

    int getSize()
    {
        return size;
    }

    void remove_node_with_val(int val)
    {
        Node *temp = find_node(val);
        if (temp == nullptr)
        {
            cout << "Value Not Found" << endl;
        }
        else if(size==0)
        {
            cout << "Underflow" << endl;
        }
        else if (size == 1)
        {
            head = nullptr;
            size--;
        }
        else if (temp == head)
        {
            remove_front();
        }
        else
        {
            temp->next = temp->next->next;
            size--;
        }
    }

    void update_node(Node *current, int val)
    {
        current->data = val;
    }
};

int main()
{
    SingleLinkedList sll;
    int choice;
    while (1)
    {
        cin >> choice;
        if (choice == 1)
        {
            int num;
            cin >> num;
            sll.insert_front(num);
            // cout << "Head=" << dll.head->data << ", Tail=" << dll.tail->data << " ";
            sll.display();
            cout << endl;
        }
        else if (choice == 2)
        {
            int num;
            cin >> num;
            sll.insert_back(num);
            // cout << "Head=" << dll.head->data << ", Tail=" << dll.tail->data << " ";
            sll.display();
            
            cout << endl;
        }
        else if (choice == 3)
        {
            int num, val;
            cin >> num >> val;
            Node *current = sll.find_node(val);
            if (current == nullptr)
            {
                cout << "Value Not Found" << endl;
                // cout << "Head=" << dll.head->data << ", Tail=" << dll.tail->data << " ";
                sll.display();
                
                cout << endl;
            }
            else
            {
                sll.insert_after_node(current, num);
                // cout << "Head=" << dll.head->data << ", Tail=" << dll.tail->data << " ";
                sll.display();
                
                cout << endl;
            }
        }
        else if (choice == 4)
        {
            int num, val;
            cin >> num >> val;
            Node *current = sll.find_node(val);
            if (current == nullptr)
            {
                cout << "Value Not Found" << endl;
                // cout << "Head=" << dll.head->data << ", Tail=" << dll.tail->data << " ";
                sll.display();
            
                cout << endl;
            }
            else
            {
                sll.update_node(current, num);
                // cout << "Head=" << dll.head->data << ", Tail=" << dll.tail->data << " ";
                sll.display();
                
                cout << endl;
            }
        }
        else if (choice == 5)
        {
            sll.remove_front();
            // cout << "Head=" << dll.head->data << ", Tail=" << dll.tail->data << " ";
            sll.display();
        
            cout << endl;
        }
        else if (choice == 6)
        {
            int num;
            cin >> num;
            sll.remove_node_with_val(num);
            // cout << "Head=" << dll.head->data << ", Tail=" << dll.tail->data << " ";
            sll.display();
            
            cout << endl;
        }
        else if (choice == 7)
        {
            sll.remove_back();
            // cout << "Head=" << dll.head->data << ", Tail=" << dll.tail->data << " ";
            sll.display();
    
            cout << endl;
        }
        else if (choice == 8)
        {
            break;
        }
    }
}