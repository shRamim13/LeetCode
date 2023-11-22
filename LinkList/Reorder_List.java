/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {

public ListNode midNode(ListNode head){
    ListNode fast=head,slow=head;
    while(fast.next!=null&&fast.next.next!=null){
        fast=fast.next.next;
        slow=slow.next;
    }
    return slow;
}

public ListNode reverse(ListNode head){
    ListNode cur=head,prev=null;
    while(cur!=null){
        ListNode temp=cur.next;
        cur.next=prev;
        prev=cur;
        cur=temp;
    }
    return prev;
}    

public void reorderList(ListNode head) {
        ListNode MidNode = midNode(head);
        ListNode s2 = reverse(MidNode.next);
        ListNode s1 = head;
        MidNode.next = null; // Break the link between the first and second halves
        while (s1 != null && s2 != null) {
            ListNode t1 = s1.next;
            ListNode t2 = s2.next;
            s1.next = s2;
            s2.next = t1;
            s1 = t1;
            s2 = t2;
        }
    }
}