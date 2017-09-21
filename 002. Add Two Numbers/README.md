使用一个 dummyHead，可避免对头节点的特殊处理：
    dummyHead := &ListNode{0, nil}
	curr := dummyHead
    ...
    
    // Append a node
    curr.Next = &ListNode{}  
    curr = curr.Next
    
    return dummyHead.Next
    