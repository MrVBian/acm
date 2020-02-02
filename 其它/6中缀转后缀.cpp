#include<iostream>
#include<string>
#include<stack>
#include<cmath>
#include<cstdlib>
#include<algorithm>

using namespace std;

int getPriority(char ch){
    //获取优先级
    if (ch == '(') return 1;
    else if (ch == '+' || ch == '-') return 2;
    else if (ch == '*' || ch == '/') return 3;
    else return 4;
}

string getPostfixExpression(string str){
    //将中缀表达式转化为后缀表达式
    stack<char> s;
    int len = str.size();
    int i = 0;
    char tmp;
    string res = "";
    while (i < len) {
        if (str[i] >= '0' && str[i] <= '9'){
            int j = i;
			while (j < len && str[j] >= '0' && str[j] <= '9') {
			    res.push_back(str[j]);
			    j++;
            }
			i = j - 1;
            res.push_back('|');
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^') {
            if (s.empty()) {
                s.push(str[i]);
            }
            else {
                while (!s.empty()) {
                    tmp = s.top();
                    if (getPriority(tmp) >= getPriority(str[i])) {
                        //弹出栈顶元素
                        res.push_back(tmp);
                        s.pop();
                    }
                    else break;
                }
                s.push(str[i]);
            }
        }
        else {
            if(str[i]=='(') s.push(str[i]);
            else {
                while (s.top() != '(') {
                    tmp = s.top();
                    res.push_back(tmp);
                    s.pop();
                }
                s.pop();
            }
        }
        i++;
    }

    //遍历完后，若栈非空，弹出所有元素
    while (!s.empty()) {
        tmp = s.top();
        res.push_back(tmp);
        s.pop();
    }
    return res;
}

int calculator(string str){
    //计算后缀表达式的值，默认中缀表达式所有数字都是一位的，在0-9之间
    stack<int> s;
    int len = str.size();
    int num1, num2, num3;
    for (int i = 0; i < len; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            int j = i;
            while (j < len && str[j] != '|')
                j++;
			s.push(atoi(str.substr(i, j - i).c_str()));
			i = j;
//			cout << "i: " << i << "  str[i]: " << str[i] << endl;
        }
        else {
			num2 = s.top();
			s.pop();

            num1 = s.top();
            s.pop();
            if (str[i] == '+') {
                num3 = num1 + num2;
            }
            else if (str[i] == '-') {
                num3 = num1 - num2;
            }
            else if (str[i] == '*') {
                num3 = num1 * num2;
            }
            else if (str[i] == '/') {
                num3 = num1 / num2;
            }
            s.push(num3);
//            cout << "**** : " << num1 << str[i] << num2 << "=" << num3 << endl;
        }
    }
    return s.top();
}

bool check(string str){
    int tag = 0;
    int len = str.size();
    for(int i = 0; i < len; ++i){
        if(str[i] == '(')
            tag = 1;
        else if(str[i] == ')'){
            if(!tag)
                return false;
        }
        else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/'){
            if(i != len-1)
                if(str[i+1] == '+' || str[i+1] == '-' || str[i+1] == '*' || str[i+1] == '/')
                    return false;
        }
    }
    return true;
}

int main(){
    string str;
    cin >> str;
    str = str.substr(0, str.size()-1);
    if(!check(str)){
        cout << "NO" << endl;
        return 0;
    }

    string res = getPostfixExpression(str);
//    cout <<"后缀表达式为:"<< endl << res << endl;
    int num_res = calculator(res);

    cout << num_res << endl;
    return 0;
}
