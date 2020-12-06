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
        ListNode *head = nullptr;
        ListNode *prev = head;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr)
        {
            int val_1 = (l1 == nullptr) ? 0 : l1->val;
            int val_2 = (l2 == nullptr) ? 0 : l2->val;
            int sum = val_1 + val_2 + carry;

            carry = sum > 9 ? 1 : 0;
            sum = int(sum % 10);

            if (prev == nullptr)
            {
                head = new ListNode(sum);
                prev = head;
            }
            else
            {
                prev->next = new ListNode(sum);
                prev = prev->next;
            }

            if (l1 != nullptr)
                l1 = l1->next;
            if (l2 != nullptr)
                l2 = l2->next;
        }
        if (carry > 0)
        {
            prev->next = new ListNode(carry);
        }

        return head;
    }
};
