/*
######################LinkList


class Node<T> {
    T data;
    Node next;
    Node(T data){
        this.data=data;
    }
}

void main(){
    Node<Integer> n1=new Node(10);
    Node<Integer> n1=new Node(20);
    Node<Integer> n1=new Node(30);
    Node<Integer> n1=new Node(40);
    Node<Integer> head=n1;
    head.next=n2;
    n2.next=n3;
    n3.next=n4;
    n4.next=null;

    traverse(head);
}
 void traverse(Node head){
     Node cur=head;
     while(cur!=null){
        print(cur.data);
        cur=cur.next;
     }
 }
void insert(int data,Node head,int position){
    Node toAdd=new Node(data);
    if(position==0){
        toAdd.next=head;
        head=toAdd;
        return;
    }
    Node prev=head;

    for(int i=0;i<position-1;++i){
        prev=prev.next;
    }
    toAdd.next=prev.next;
    prev.next=toAdd;
}

void Delete(Node head,int position){
    if(position==0){
        head=head.next;
        return;
    }
    Node prev=head;

    for(int i=0;i<pos-1;++i){
        prev=prev.next;
    }
    prev.next=perv.next.next;
}
*/

// class Solution {
//     public ListNode reverseList(ListNode head) {
//         if(head==null || head.next==null){return head;}
//         ListNode newhead=reverseList(head.next);
//         ListNode headnext=head.next;
//         headnext.next=head;
//         head.next=null;
//         return newhead;
//     }
// }


class Solution {
    public ListNode reverseList(ListNode head) {
       ListNode cur=head;
       ListNode prev=null;
       while(cur!=null){
           ListNode temp=cur.next;
           cur.next=prev;
           prev=cur;
           cur=temp;
       }
       return prev;
    }
}

