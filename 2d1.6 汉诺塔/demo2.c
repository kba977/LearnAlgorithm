//
//  main.c
//  汉诺塔
//
//  Created by kba977's Mac on 2016/10/1.
//  Copyright © 2016年 kba977. All rights reserved.
//

#include <stdio.h>

static int step = 0;

void hanoi(int n, char from, char to, char end) {
    
    if (n==1) {
        step++;
        printf("第%d步: 将%c柱上的圆盘移动到%c柱上\n", step, from, end);
    }
    else {
        hanoi(n-1, from, end, to);
        hanoi(1, from, to, end);
        hanoi(n-1, to, from, end);
    }
}
               
int main(void) {
    hanoi(3, 'A', 'B', 'C');
    return 0;
}
