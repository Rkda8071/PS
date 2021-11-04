#include<bits/stdc++.h>
using namespace std;

stack<char> s;
char a[110];

int main(){
    scanf("%s",a+1);
    for(int i=1;a[i]!=NULL;i++){
        char x = a[i];
        if(x == '+' || x == '-'){
            if(!s.empty() && (s.top() == '+' || s.top() == '-')){
                printf("%c",s.top());
                s.pop();
            }
            s.push(x);
        }else if(x == '*' || x == '/'){
            s.push(x);
        }else if(x == '('){
            s.push(x);
        }else if(x == ')'){
            while(!s.empty() && s.top()!='('){
                printf("%c",s.top());
                s.pop();
            }
            s.pop(); // ( 삭제
            if(!s.empty() && (s.top() == '*' || s.top() == '/')){
                printf("%c",s.top());
                s.pop();
            }
        }else{ // 알파벳
            printf("%c",x);
            if(!s.empty() && (s.top() == '*' || s.top() == '/')){
                printf("%c",s.top());
                s.pop();
            }
        }
    }
    while(!s.empty()){
        printf("%c",s.top());
        s.pop();
    }
    return 0;
}
