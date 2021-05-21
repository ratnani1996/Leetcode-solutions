/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class HeapNode
{
private:
    int val;
    int index;

public:
    HeapNode()
    {
        val = 0;
        index = 0;
    }
    HeapNode(int val, int index)
    {
        this->val = val;
        this->index = index;
    }
    int getVal() const
    {
        return val;
    }

    int getIndex() const
    {
        return index;
    }
};

class myComparator
{
public:
    int operator()(const HeapNode &p1, const HeapNode &p2)
    {
        return p1.getVal() > p2.getVal();
    }
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *newList = NULL;
        ListNode *endPointer = NULL;
        priority_queue<HeapNode, vector<HeapNode>, myComparator> minHeap;
        // minHeap.push(HeapNode(1, 0));
        // minHeap.push(HeapNode(2, 1));
        // minHeap.push(HeapNode(0, 1));

        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i] != NULL)
            {
                minHeap.push(HeapNode(lists[i]->val, i));
                lists[i] = lists[i]->next;
            }
        }

        while (!minHeap.empty())
        {
            HeapNode top = minHeap.top();
            if (newList == NULL)
            {
                ListNode *newNode = new ListNode(top.getVal());
                newList = newNode;
                endPointer = newNode;
            }
            else
            {
                ListNode *newNode = new ListNode(top.getVal());
                endPointer->next = newNode;
                endPointer = newNode;
            }
            minHeap.pop();
            if (lists[top.getIndex()] != NULL)
            {
                minHeap.push(HeapNode(lists[top.getIndex()]->val, top.getIndex()));
                lists[top.getIndex()] = lists[top.getIndex()]->next;
            }
        }
        return newList;
    }
};
