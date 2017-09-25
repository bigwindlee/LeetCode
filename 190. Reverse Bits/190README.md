Tortoise and Hare Algorithm：
You can make use of Floyd's cycle-finding algorithm, also know as tortoise and hare algorithm. The idea is to have two references to the list and move them at different speeds. Move one forward by 1 node and the other by 2 nodes. If the linked list has a loop they will definitely meet.

Since the runner's speed is faster than walker, then it is guaranteed that runner will pass walker in some time. The only thing we need to prove is that the runner never jumps over walker so never meet. Suppose the runner jumps over walker in one unit of time, then we need to guarantee that 2 > distance + 1. So distance < 1 so distance = 0. This implies that runner already meets walker, contradiction. So runner will never jumps over walker.

Runner will pass walker + runner never jumps over = runner will meet walker.