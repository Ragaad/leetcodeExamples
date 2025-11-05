import unittest
from solution import ListNode , Solution

def to_list(head):
    out=[]
    while head:
        out.append(head.val)
        head=head.next
    return out

class TestAddTwoNumbers(unittest.TestCase):
    def setUp(self):
        self.sol=Solution()
    
    def check(self,l1,l2,expected):
        got=to_list(self.sol.addTwoNumbers(l1,l2))
        expected_list=to_list(expected)
        self.assertEqual(got,expected_list,
        f"for input {to_list(l1)} and {to_list(l2)} got {got} while expected {expected_list}")

        return got==expected_list 
    
    def test_examples(self):
        tests=[
            ([ListNode(2,ListNode(4,ListNode(3,None))),          #l1
            ListNode(5,ListNode(6,ListNode(4,None)))],           #l2
            ListNode(7,ListNode(0,ListNode(8,None)))),           #expected
            ([ListNode(0,None),
            ListNode(0,None)],
            ListNode(0,None)),
            ([ListNode(9,ListNode(9,ListNode(9,ListNode(9,ListNode(9,ListNode(9,ListNode(9,None))))))),
            ListNode(9,ListNode(9,ListNode(9,ListNode(9,None))))],
            ListNode(8,ListNode(9,ListNode(9,ListNode(9,ListNode(0,ListNode(0,ListNode(0,ListNode(1,None)))))))))
        ]  

        passed=0
        for test,expected in tests:
            if self.check(test[0],test[1],expected):
                passed+=1
        print(f"\nSummary: {passed}/{len(tests)}")

if __name__=="__main__":
    unittest.main()
