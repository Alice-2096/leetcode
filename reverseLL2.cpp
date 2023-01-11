
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *res = new ListNode(), *start = head, *begin;
        if (left > 1)
        {
            res->next = head;
            int ind = 1;
            while (left - ind > 1)
            {
                start = start->next;
                ind++;
            }
            begin = start->next;
            // start->next = reversed list head.
        }
        else
            begin = head;

        // reverse linked list from begin
        ListNode *prev = begin, *curr = begin->next, *tmp;
        int ind = left;
        while (curr && left < right)
        {
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
            left++;
        }

        begin->next = curr;
        if (left > 1)
            start->next = prev;
        else
            return prev;
        return res->next;
    }
};
int main()
{
    Solution s;
    s.reverseBetween(ListNode *head, int left, int right)
    return 0;
}
