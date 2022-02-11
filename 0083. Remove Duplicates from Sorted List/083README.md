思路：
  方法1）使用2个指针，双重循环，p指向当前node，q一直前进直到发现一个和p不同的值；

  方法2）其实只需要1个指针curr，单重循环；在单重循环中分2条线，curr.Val == curr.Next.Val 以及 curr.Val != curr.Next.Val
