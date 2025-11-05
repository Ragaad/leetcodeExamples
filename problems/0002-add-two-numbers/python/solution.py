from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        result=None
        num1=l1
        num2=l2
        carry=0

        while num1 or num2:
            if not result:
                result=ListNode()
                num3=result
            else:
                num3.next=ListNode()
                num3=num3.next

            if num1 and num2:
                sum=num1.val+num2.val
                num1=num1.next
                num2=num2.next
            elif num1:
                sum=num1.val
                num1=num1.next
            else:
                sum=num2.val
                num2=num2.next
            sum+=carry
            
            num3.val=sum%10
            carry=int(sum/10)
                
        if carry>0:
            num3.next=ListNode()
            num3=num3.next
            num3.val=carry

        return result

def solve(*args, **kwargs):
    sol=Solution()
    l1=ListNode(2,ListNode(4,ListNode(3,None)))
    l2=ListNode(5,ListNode(6,ListNode(4,None)))
    l3=sol.addTwoNumbers(l1,l2)
    print("The result linked list: ",end="[")
    while l3:
        print(l3.val,end=",")
        l3=l3.next
    print("]")


if __name__ == "__main__":
    solve()
