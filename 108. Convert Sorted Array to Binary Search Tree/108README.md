思路：
1) Get the Middle of the array and make it root.
2) Recursively do same for left half and right half.
    a) Get the middle of left half and make it left child of the root
        created in step 1.
    b) Get the middle of right half and make it right child of the
        root created in step 1.
