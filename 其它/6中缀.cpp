#include<iostream>
#include<string>
#include<stack>
#include<cstdlib>

using namespace std;

int getPriority(char ch){
    //获取优先级
    if (ch == '(') return 1;
    else if (ch == '+' || ch == '-') return 2;
    else if (ch == '*' || ch == '/') return 3;
    else return 4;
}

void calculate(stack<int> &s, char operation){
	int num1, num2, num3;
	num2 = s.top();
	s.pop();
	num1 = s.top();
	s.pop();
	if (operation == '+') {
		num3 = num1 + num2;
	}
	else if (operation == '-') {
		num3 = num1 - num2;
	}
	else if (operation == '*') {
		num3 = num1 * num2;
	}
	else if (operation == '/') {
		num3 = num1 / num2;
	}

	s.push(num3);
}

int calculator(string str){
	stack<int> s_number;
	stack<char> s_operation;
	int i = 0, j;
	int len = str.size();
	char tmp_operation;
	string tmp_num;
	while (i < len) {
		if (str[i] >= '0' && str[i] <= '9') {
			j = i;
			while (j < len && str[j] >= '0' && str[j] <= '9') { j++; }
			tmp_num = str.substr(i, j - i);
			s_number.push(atoi(tmp_num.c_str()));
			i = j;
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '^') {
			if (s_operation.empty()) {
				s_operation.push(str[i]);
			}
			else {
				while (!s_operation.empty()) {
					tmp_operation = s_operation.top();
					if (getPriority(tmp_operation) >= getPriority(str[i])) {
						//计算
						calculate(s_number, tmp_operation);
						s_operation.pop();
					}
					else break;
				}
				s_operation.push(str[i]);
			}
			i++;
		}
		else {
			if (str[i] == '(') s_operation.push(str[i]);
			else {
				while (s_operation.top() != '(') {
					tmp_operation = s_operation.top();
					//计算
					calculate(s_number, tmp_operation);
					s_operation.pop();
				}
				s_operation.pop();
			}
			i++;
		}

	}
	//遍历完后，若栈非空，弹出所有元素
	while (!s_operation.empty()) {
		tmp_operation = s_operation.top();
		//计算
		calculate(s_number, tmp_operation);
		s_operation.pop();
	}
	return s_number.top();
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
	int num_res = calculator(str);
	cout << num_res << endl;
	return 0;
}
