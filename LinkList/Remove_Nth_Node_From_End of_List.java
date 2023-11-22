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

    public ListNode reverse(ListNode head){
        ListNode cur =head,prev=null;
        while(cur!=null){
            ListNode temp=cur.next;
            cur.next=prev;
            prev=cur;
            cur=temp;
        }
        return prev;
    }

    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode s1=reverse(head);
        int k=n-1;
        if(k==0){
           s1=s1.next;
           return reverse(s1);
        }
        ListNode ab=s1;
        {
            for(int i=0;i<k-1;i++){
                ab=ab.next;
            }
            ab.next=ab.next.next;
            return reverse(s1);
        }
    }
}