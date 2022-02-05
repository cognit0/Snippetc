/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *makeNode(int val)
{
    struct ListNode *p;
    
    p = (struct ListNode *) malloc(sizeof(struct ListNode));
    p->val = val;
    p->next = NULL;
    return (p); 
}

void    addNode(struct ListNode *head, int val)
{
    struct ListNode *dump;
    
    dump = head;
    while (dump->next != NULL)
        dump = dump->next;
    dump->next = makeNode(val);
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    struct ListNode *n1 = l1;
    struct ListNode *n2 = l2;
    struct ListNode *dump;
    struct ListNode *head;
    
    head = makeNode(n1->val + n2->val);
    n1 = n1->next;
    n2 = n2->next;
    while (n1 || n2)
    {
        if (n1 && n2)
        {
            addNode(head, n1->val + n2->val);
            n1 = n1->next;
            n2 = n2->next;
        }
        else if (n1)
        {
            addNode(head, n1->val);
            n1 = n1->next;
        }
        else if (n2)
        {
            addNode(head, n2->val);
            n2 = n2->next;
        }
    }
    dump = head;
    while (dump)
    {
        if (dump->val > 9 && dump->next != NULL)
        {
            dump->val -= 10;
            dump->next->val += 1;
        }
        else if (dump->val > 9 && dump->next == NULL)
        {
            dump->val -= 10;
            addNode(head, 1);
        }
        dump = dump->next;
    }
    return (head);
}
