#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int data;
    struct ListNode* next;
};

ListNode* Insert(ListNode* head, int index, int data)
{
    ListNode* dummy_head = new ListNode();
    dummy_head->next = head;
    ListNode* temp = new ListNode();
    ListNode* position = dummy_head;
    for (int i = 0; i < index; ++i) {
        position = position->next;
    }
    temp->data = data;
    temp->next = position->next;
    position->next = temp;

    head = dummy_head->next;
    delete dummy_head;
    return head;
}

ListNode* DeleteNode(ListNode* head, int index)
{
    ListNode* dummy_head = new ListNode();
    dummy_head->next = head;
    ListNode* position = dummy_head;
    for (int i = 0; i < index; ++i) {
        position = position->next;
    }
    ListNode* temp = position->next;
    position->next = temp->next;
    delete temp;
    head = dummy_head->next;
    delete dummy_head;
    return head;
}

ListNode* Reverse(ListNode* head)
{
    if (head == NULL) {
        return head;
    }

    stack<ListNode*> node_stack;
    while (head != NULL) {
        node_stack.push(head);
        head = head->next;
    }

    ListNode* new_head = node_stack.top();

    while (!node_stack.empty()) {
        head = node_stack.top();
        node_stack.pop();
        if (node_stack.empty()) {
            head->next = NULL;
        } else {
            head->next = node_stack.top();
        }
    }

    return new_head;
}

void print(const ListNode* head)
{
    while (head != NULL) {
        cout << head->data << ' ';
        head = head->next;
    }

    cout << endl;
}

int main()
{
    ListNode* head = NULL;
    head = Insert(head, 0, 15);
    head = Insert(head, 0 ,10);
    head = Insert(head, 2, 20);
    head = Insert(head, 1, 30);
    print(head);
    head = Reverse(head);
    print(head);
    head = DeleteNode(head, 0);
    print(head);
    head = DeleteNode(head, 2);
    print(head);
    head = Reverse(head);
    print(head);

    head = DeleteNode(head, 0);
    print(head);
    head = Reverse(head);
    print(head);

    head = DeleteNode(head, 0);
    print(head);
    head = Reverse(head);
    print(head);

    return 0;
}
