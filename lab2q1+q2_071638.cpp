#include <iostream>
using namespace std;
template <typename T>
class linklist
{
    struct node
    {
        T data;
        node *next;
        node()
        {
            next = NULL;
        }
    };

public:
    node *head;
    node *tail;
    linklist()
    {
        head = NULL;
        tail = NULL;
    }
    class Iterator
    {

    public:
        node *curr;

        Iterator()
        {
            curr = NULL;
        }
        T operator*()
        {
            return (curr->data);
        }
        Iterator operator++()
        {
            curr = curr->next;
            return *this;
        }
        Iterator operator++(int)
        {
            Iterator itr = *this;
            curr = curr->next;
            return itr;
        }
        friend bool operator!=(Iterator &obj, Iterator &obj1)
        {
            if (obj.curr != obj1.curr)
                return true;
            return false;
        }
    };
    void insert_at_front(T val)
    {
        node *new_node = new node;
        new_node->data = val;
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        node *temp = head;
        new_node->next = head;
        head = new_node;
    }
    void print()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    Iterator begin()
    {
        Iterator itr;
        itr.curr = head;
        return itr;
    }
    Iterator end()
    {
        Iterator itr;
        itr.curr = tail;
        // cout << itr.curr->data << endl;
        return itr;
    }
    void insert_at_back(T val)
    {
        node *new_node = new node;
        new_node->data = val;
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
        tail = new_node->next;
        // cout << "tail" << tail->data << endl;
    }
    void delete_at_front()
    {
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }
        node *temp = head;
        head = head->next;
        delete temp;
    }
    void delete_at_end()
    {
        if (head->next == NULL)
        {
            delete_at_front();
            return;
        }
        node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        node *delete_node = temp->next;
        temp->next = NULL;
        delete delete_node;
        tail = temp->next;
    }
    bool search(T val)
    {
        if (head == NULL)
            return false;
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->data == val)
                return true;
            temp = temp->next;
        }
        return false;
    }
    linklist union_of_lists(linklist l2)
    {
        linklist u;
        node *temp = head;
        while (temp != NULL)
        {
            u.insert_at_back(temp->data);
            temp = temp->next;
        }
        while (l2.head != NULL)
        {
            if (!(u.search(l2.head->data)))
                u.insert_at_back(l2.head->data);
            l2.head = l2.head->next;
        }
        return u;
    }
    linklist intersection_of_lists(linklist l2)
    {
        linklist u;
        node *temp = head;
        node *temp1 = l2.head;
        while (temp != NULL)
        {

            while (temp1 != NULL)
            {
                if (temp->data == temp1->data)
                {
                    if (!(u.search(temp->data)))
                        u.insert_at_back(temp->data);
                    break;
                }
                temp1 = temp1->next;
            }
            temp1 = l2.head;
            temp = temp->next;
        }
        return u;
    }
    void sort()
    {
        node *temp1 = head;
        node *temp2;
        for (; temp1 != NULL; temp1 = temp1->next)
        {
            for (temp2 = head; temp2->next != NULL; temp2 = temp2->next)
            {
                if (temp2->data > temp2->next->data)
                    swap(temp2->data, temp2->next->data);
            }
        }
    }
};
int main()
{
    // Q1
    //  linklist<int> l;
    //  l.insert_at_front(2);
    //  l.insert_at_front(6);
    //  l.insert_at_front(7);
    //  l.insert_at_back(3);
    //  l.insert_at_back(8);
    //  l.insert_at_back(1);
    //  l.print();
    //  linklist<int>::Iterator it;
    //  it = l.begin();
    //  linklist<int>::Iterator et;
    //  for (; it != et; it++)
    //      cout << it.curr->data << "->";
    //  cout << endl;
    //  l.delete_at_front();
    //  l.delete_at_end();
    //  it = l.begin();
    //  et = l.end();
    //  for (; it != et; it++)
    //      cout << it.curr->data << "->";
    //  cout << endl;
    //  l.print();
    //  ________________________________________

    // Q2
    linklist<int> l;
    linklist<int> l2;
    int x = 0;
    cout << "enter input:-";
    for (int i = 0; i < 6; i++)
    {
        cin >> x;
        l.insert_at_back(x);
    }
    l.print();
    cout << "Enter input:-";
    for (int i = 0; i < 10; i++)
    {
        cin >> x;
        l2.insert_at_back(x);
    }

    l2.print();
    linklist<int> l3;
    l3 = l.union_of_lists(l2);
    l3.print();
    linklist<int> l4;
    l4 = l.intersection_of_lists(l2);
    l4.print();
    linklist<int> l5;
    l5.insert_at_back(3);
    l5.insert_at_back(2);
    l5.insert_at_back(1);
    l5.print();
    l5.sort();
    l5.print();
}