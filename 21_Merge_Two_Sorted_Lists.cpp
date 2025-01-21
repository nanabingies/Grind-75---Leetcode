#include <iostream>
#include <algorithm>
#include <list>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(-200), next(nullptr) {}   // default empty list
    //ListNode() {};
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            bool start = true;
            ListNode* temp_1 = list1;
            ListNode* temp_2 = list2;

            ListNode* result = new ListNode();
            ListNode* back;
            ListNode* temp_result = new ListNode();// result;

            do {
                if (temp_1 == nullptr) {
                    if (temp_2 == nullptr) {
                        break;
                    } else if (temp_2->val == -200) {
                        break;
                    } else {
                        if (result->val == -200) {  // first
                            result = temp_2;
                            break;
                        }
                        back->next = temp_2;
                        break;
                    }
                }

                if (temp_2 == nullptr) {
                    if (temp_1 == nullptr) {
                        break;
                    } else if (temp_1->val == -200) {
                        break;
                    } else {
                        if (result->val == 200) {
                            result = temp_1;
                            break;
                        }
                        back->next = temp_1;
                        break;
                    }
                }

                if (temp_1->val == -200) {
                    if (temp_2->val == -200) {
                        break;
                    } else {
                        back->next = temp_2;
                    }
                }

                if (temp_2->val == -200) {
                    if (temp_1->val == -200) {
                        break;
                    } else {
                        back->next = temp_1;
                    }
                }

                if (temp_1->val < temp_2->val) {
                    auto _ = new ListNode(temp_1->val);
                    if (result->val == -200) {  // first
                        result = _;
                    } else {
                        back->next = _;
                    }

                    temp_1 = temp_1->next;
                    back = _;
                } else if (temp_2->val < temp_1->val) {
                    auto _ = new ListNode(temp_2->val);

                    if (result->val == -200) {  // first
                        result = _;
                    } else {
                        back->next = _;
                    }

                    temp_2 = temp_2->next;
                    back = _;
                } else {
                    
                    auto _ = new ListNode(temp_1->val);
                    auto __ = new ListNode(temp_2->val);
                    _->next = __;

                    if (result->val == -200) {  // first
                        result = _;
                    } else {
                        back->next = _;
                    }
                    
                    temp_1 = temp_1->next;
                    temp_2 = temp_2->next;
                    back = __;
                }
                
            } while (!false);

            if (result->val == -200) {
                if (result->next != nullptr) {
                    delete result->next;
                    result->next = nullptr;
                }
                delete result;
                result = nullptr;
                return nullptr;
            }
            return result;
        }
};

int main(int argc, char* argv[]) {
    Solution soln;
    std::list<ListNode*> list1, list2;

    ListNode* l_1_1 = new ListNode(1);
    ListNode* l_1_2 = new ListNode(2);
    ListNode* l_1_3 = new ListNode(4);
    l_1_1->next = l_1_2;
    l_1_2->next = l_1_3;
    list1.push_front(l_1_1);
    list1.push_back(l_1_2);
    list1.push_back(l_1_3);

    ListNode* l_2_1 = new ListNode(1);
    ListNode* l_2_2 = new ListNode(3);
    ListNode* l_2_3 = new ListNode(4);
    l_2_1->next = l_2_2;
    l_2_2->next = l_2_3;
    list2.push_front(l_2_1);
    list2.push_back(l_2_2);
    list2.push_back(l_2_3);

    ListNode* result = soln.mergeTwoLists(l_1_1, l_2_1);

    ListNode* temp = result;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::putchar('\n');

    delete l_1_1; delete l_1_2; delete l_1_3;
    delete l_2_1; delete l_2_2; delete l_2_3;
    list1.clear();
    list2.clear();

    std::cout << "-------------------------------------------" << std::endl;

    l_1_1 = new ListNode();
    l_2_1 = new ListNode();

    result = soln.mergeTwoLists(l_1_1, l_2_1);
    temp = result;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::putchar('\n');

    delete l_1_1; delete l_2_1;
    list1.clear();
    list2.clear();

    std::cout << "-------------------------------------------" << std::endl;

    l_1_1 = new ListNode();
    l_2_1 = new ListNode(0);

    result = soln.mergeTwoLists(l_1_1, l_2_1);
    temp = result;
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::putchar('\n');

    return 0;
}
