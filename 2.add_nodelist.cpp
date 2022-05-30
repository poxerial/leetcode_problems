struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *rst = new ListNode((l1->val + l2->val) % 10);
        ListNode *p = rst;
        int remainder = (l1->val + l2->val) / 10;
        while (l1->next != nullptr && l2->next != nullptr)
        {
            l1 = l1->next;
            l2 = l2->next;
            int tmp = l1->val + l2->val + remainder;
            remainder = tmp / 10;
            p->next = new ListNode(tmp % 10);
            p = p->next;
        }
        if (l1->next != l2->next)
        {
            ListNode *rest = l1->next == nullptr ? l2 : l1;
            while (rest->next)
            {
                rest = rest->next;
                int tmp = rest->val + remainder;
                remainder = tmp / 10;
                p->next = new ListNode(tmp % 10);
                p = p->next;
            }
        }
        if (remainder)
        {
            p->next = new ListNode(remainder);
        }
        return rst;
    }
};