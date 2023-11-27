public Node copyRandomList(Node head) {
        if (head == null) return null;

        // Step 1: Create a copy of each node and insert it after the original node
        Node cur = head;
        while (cur != null) {
            Node copy = new Node(cur.val);
            copy.next = cur.next;
            cur.next = copy;
            cur = copy.next;
        }

        
        // Step 2: Assign random pointers for the copied nodes
        cur = head;
        while(cur!=null){
                if(cur.next!=null){
                    cur.next.random=(cur.random!=null)?cur.random.next:null;
                }
                cur=cur.next.next;
            }

        // Step 3: Separate the original and copied lists
        cur = head;
        Node copyHead = head.next;
        Node copyCur = copyHead;
        while (cur != null) {
            cur.next = cur.next.next;
            if (copyCur.next != null) {
                copyCur.next = copyCur.next.next;
            }
            cur = cur.next;
            copyCur = copyCur.next;
        }
        return copyHead;
    }