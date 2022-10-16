/*实现功能：输入命题公式的合式公式，求出公式的真值表，并输出该公式的主合取范式和主析取范式。

输入：命题公式的合式公式

输出：公式的主析取范式和主析取范式，输出形式为：“ mi ∨ mj ; Mi ∧ Mj” ，极小项和 ∨ 符号之间有一个空格，极大项和 ∧ 符号之间有一个空格；主析取范式和主合取范式之间用“ ; ”隔开，“ ; ”前后各有一个空格。 永真式的主合取范式为 1 ，永假式的主析取范式为 0 。

输入公式的符号说明：

! 非，相当于书面符号中的 “ ¬ ”

& 与，相当于书面符号中的 “ ∧ ”

| 或，相当于书面符号中的 “ ∨ ”

- 蕴含联结词，相当于书面符号中的 “ → ”

+ 等价联结词，相当于书面符号中的 “ ↔ ”

( 前括号

) 后括号*/

#include <cmath>  
#include <cstdio>  
#include <cstdlib>  
#include <queue>  
#include <stack>  
#include <iostream>  
using namespace std;  
  
typedef struct NODE {  
    char symbol;  
    int value;  
    struct NODE *leftson;  
    struct NODE *rightson;  
} node;  
stack<node *> gene;        //从后缀表达式构造树所用的栈  
int symbolvalue[128] = {0};     //储存每个命题变元的值  
int truelist[1024] = {0};  //真值表  
int pri[128] = {0};        //运算符优先级  
stack<char> calcu;         //转后缀表达式使用的栈  
queue<char> anser;         //转后缀表达式的结果  
  
/*计算root的值*/  
void cal(node *root) {  
    if (root->leftson == root->rightson) {  
        root->value = symbolvalue[root->symbol];  
        return;  
    }  
    if (root->leftson != NULL) {  
        cal(root->leftson);  
    }  
    if (root->rightson != NULL) {  
        cal(root->rightson);  
    }  
    switch (root->symbol) {  
        case '!':  
            root->value = !root->leftson->value;  
            break;  
        case '&':  
            root->value = root->leftson->value && root->rightson->value;  
            break;  
        case '|':  
            root->value = root->leftson->value || root->rightson->value;  
            break;  
        case '-':  
            if (root->leftson->value == 1 && root->rightson->value == 0) {  
                root->value = 0;  
            } else {  
                root->value = 1;  
            }  
            break;  
        case '+':  
            if (root->leftson->value == root->rightson->value) {  
                root->value = 1;  
            } else {  
                root->value = 0;  
            }  
            break;  
    }  
    return;  
}  
  
node *newnode(char c) {  
    node *t = (node *)malloc(sizeof(node));  
    t->symbol = c;  
    t->value = 0;  
    t->leftson = NULL;  
    t->rightson = NULL;  
    return t;  
}  
  
int main() {  
    pri['-'] = 1;  
    pri['+'] = 1;  
    pri['&'] = 2;  
    pri['|'] = 2;  
    pri['!'] = 3;  
    pri['('] = -1;  
    pri[')'] = 4;  
    char c;  
    while (1) {  //将输入转化为后缀表达式  
        scanf("%c", &c);  
        if (c == '\n') {  
            while (!calcu.empty()) {  
                anser.push(calcu.top());  
                calcu.pop();  
            }  
            goto end;  
        }  
        symbolvalue[c] = 1;  
        switch (pri[c]) {  
            case 4:  
                while (calcu.top() != '(') {  
                    anser.push(calcu.top());  
                    calcu.pop();  
                }  
                calcu.pop();  
                break;  
            case 0:  
                anser.push(c);  
                break;  
            case -1:  
                calcu.push(c);  
                break;  
            default:  
                while (!calcu.empty() && pri[calcu.top()] >= pri[c]) {  
                    anser.push(calcu.top());  
                    calcu.pop();  
                }  
                calcu.push(c);  
        }  
    }  
end:;  
    node *p;  
    while (!anser.empty()) {  //将后缀表达式转化为二叉树  
        c = anser.front();  
        anser.pop();  
        switch (pri[c]) {  
            case 3:  
                p = newnode('!');  
                p->leftson = gene.top();  
                gene.pop();  
                gene.push(p);  
                break;  
            case 0:  
                p = newnode(c);  
                gene.push(p);  
                break;  
            default:  
                p = newnode(c);  
                p->rightson = gene.top();  
                gene.pop();  
                p->leftson = gene.top();  
                gene.pop();  
                gene.push(p);  
                break;  
        }  
    }  
    node *root = gene.top();  
    int symbols, symbole;  
    for (int i = 65; i < 123; i++) {  //计算使用的命题变元字母  
        if (symbolvalue[i - 1] < symbolvalue[i]) {  
            symbols = i;  
        }  
        if (symbolvalue[i - 1] > symbolvalue[i]) {  
            symbole = i - 1;  
            break;  
        }  
    }  
    int num = symbole - symbols + 1;  
    for (int i = 0; i < pow(2, num); i++) {  //计算真值表  
        for (int j = symbols; j <= symbole; j++) {  
            symbolvalue[j] =  
                1 &  
                i >> (symbole -  
                      j);  //用右移位和按位与将i转化为命题变元取值的二进制编码  
        }  
        cal(root);  
        truelist[i] = root->value;  
    }  
    int out = 0;  
    for (int i = 0; i < pow(2, num); i++) {  //主析取范式  
        if (truelist[i] == 1) {  
            if (out > 0) {  
                printf("∨ ");  
            }  
            printf("m%d ", i);  
            out++;  
        }  
    }  
    if (out == 0) {  
        printf("0 ");  
    }  
    printf(";");  
    out = 0;  
    for (int i = 0; i < pow(2, num); i++) {  //主合取范式  
        if (truelist[i] == 0) {  
            if (out > 0) {  
                printf(" ∧");  
            }  
            printf(" M%d", i);  
            out++;  
        }  
    }  
    if (out == 0) {  
        cout<<" 1";  
    }  
    cout<<endl;  
    return 0;  
}  
