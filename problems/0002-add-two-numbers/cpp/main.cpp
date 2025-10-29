#include "leetcode.hpp"
using namespace std;

// You already have ListNode in leetcode.hpp:
// struct ListNode { int val; ListNode* next; explicit ListNode(int x) : val(x), next(nullptr) {} };

class Solution {
public:
    // Add two non-empty linked lists representing non-negative integers.
    // Digits are stored in reverse order; each node contains a single digit.
    // Return the sum as a linked list (also in reverse order).
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {                                                                                                                                             
        // TODO: implement with carry handling. O(max(m,n)) time, O(1) extra space (excluding output).
        ListNode* l3=new ListNode(0);
        ListNode* current= l3;
        int sum=0;
        int carry=0;
        while( l1!=nullptr || l2 !=nullptr || carry >0){
            sum=carry;
            if ( l1 != nullptr){
                sum+=l1->val;
                l1=l1->next;
            }
            if ( l2 != nullptr){
                sum+=l2->val;
                l2=l2->next;
            }
            ListNode* node= new ListNode(sum%10);
            carry=sum/10;
            current=node;
            current=current->next;
            sum=0;
            
        }
        return l3->next; // replace with the list head you construct
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Tiny demo: (342) + (465) = (807)
    ListNode* a = list_from_vec({2,4,3});
    ListNode* b = list_from_vec({5,6,4});
    Solution s;
    ListNode* c = s.addTwoNumbers(a, b);
    auto v = vec_from_list(c);        // should be {7,0,8}
    for (int x : v) cout << x << " ";
    cout << "\n";
    return 0;
}
