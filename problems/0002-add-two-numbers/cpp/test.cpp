#include "leetcode.hpp"
#include <gtest/gtest.h>
using namespace std;

class Solution {
public:
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

TEST(AddTwoNumbers, Example_342_plus_465) {
    Solution s;
    auto* a = list_from_vec({2,4,3});  // 342
    auto* b = list_from_vec({5,6,4});  // 465
    auto* c = s.addTwoNumbers(a, b);   // 807
    EXPECT_EQ(vec_from_list(c), (vector<int>{7,0,8}));
}

TEST(AddTwoNumbers, DifferentLengths_NoFinalCarry) {
    Solution s;
    auto* a = list_from_vec({9,9});       // 99
    auto* b = list_from_vec({1});         // 1
    auto* c = s.addTwoNumbers(a, b);      // 100 -> {0,0,1}
    EXPECT_EQ(vec_from_list(c), (vector<int>{0,0,1}));
}

TEST(AddTwoNumbers, CarryChains) {
    Solution s;
    auto* a = list_from_vec({9,9,9,9});     // 9999
    auto* b = list_from_vec({1});           // 1
    auto* c = s.addTwoNumbers(a, b);        // 10000 -> {0,0,0,0,1}
    EXPECT_EQ(vec_from_list(c), (vector<int>{0,0,0,0,1}));
}

TEST(AddTwoNumbers, OneIsZero) {
    Solution s;
    auto* a = list_from_vec({0});           // 0
    auto* b = list_from_vec({7,3});         // 37
    auto* c = s.addTwoNumbers(a, b);        // 37
    EXPECT_EQ(vec_from_list(c), (vector<int>{7,3}));
}

TEST(AddTwoNumbers, BothZero) {
    Solution s;
    auto* a = list_from_vec({0});
    auto* b = list_from_vec({0});
    auto* c = s.addTwoNumbers(a, b);        // 0
    EXPECT_EQ(vec_from_list(c), (vector<int>{0}));
}

TEST(AddTwoNumbers, LongMixed) {
    Solution s;
    auto* a = list_from_vec({2,4,9});       // 942
    auto* b = list_from_vec({5,6,4,9});     // 9465
    auto* c = s.addTwoNumbers(a, b);        // 10407 -> {7,0,4,0,1}
    EXPECT_EQ(vec_from_list(c), (vector<int>{7,0,4,0,1}));
}
