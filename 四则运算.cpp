#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>

// 检查是否为运算符
bool isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

// 获取运算符的优先级
int precedence(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return 0;
}

// 中缀表达式转后缀表达式 (逆波兰表达式)
std::string infixToPostfix(const std::string& expression) {
	std::stack<char> operators;
	std::string postfix = "";
	
	for (size_t i = 0; i < expression.length(); ++i) {
		char c = expression[i];
		
		// 如果是空格，跳过
		if (isspace(c)) continue;
		
		// 如果是数字，加入到结果
		if (isdigit(c)) {
			postfix += c;
			while (i + 1 < expression.length() && isdigit(expression[i + 1])) {
				postfix += expression[++i];
			}
			postfix += " ";
		}
		// 左括号入栈
		else if (c == '(') {
			operators.push(c);
		}
		// 右括号，弹出直到遇到左括号
		else if (c == ')') {
			while (!operators.empty() && operators.top() != '(') {
				postfix += operators.top();
				postfix += " ";
				operators.pop();
			}
			operators.pop(); // 弹出左括号
		}
		// 如果是运算符
		else if (isOperator(c)) {
			while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
				postfix += operators.top();
				postfix += " ";
				operators.pop();
			}
			operators.push(c);
		}
	}
	
	// 将剩余的操作符加入后缀表达式
	while (!operators.empty()) {
		postfix += operators.top();
		postfix += " ";
		operators.pop();
	}
	
	return postfix;
}

// 计算后缀表达式的值
double evaluatePostfix(const std::string& postfix) {
	std::stack<double> values;
	size_t i = 0;
	
	while (i < postfix.length()) {
		if (isspace(postfix[i])) {
			i++;
			continue;
		}
		
		// 如果是数字
		if (isdigit(postfix[i])) {
			double num = 0;
			while (i < postfix.length() && isdigit(postfix[i])) {
				num = num * 10 + (postfix[i] - '0');
				i++;
			}
			values.push(num);
		}
		// 如果是运算符
		else if (isOperator(postfix[i])) {
			double val2 = values.top(); values.pop();
			double val1 = values.top(); values.pop();
			switch (postfix[i]) {
				case '+': values.push(val1 + val2); break;
				case '-': values.push(val1 - val2); break;
				case '*': values.push(val1 * val2); break;
				case '/': values.push(val1 / val2); break;
			}
			i++;
		}
	}
	
	return values.top();
}

int main() {
	std::string expression;
	std::cout << "请输入四则运算表达式: ";
	std::getline(std::cin, expression);
	
	// 1. 中缀表达式转后缀表达式
	std::string postfix = infixToPostfix(expression);
	std::cout << "后缀表达式: " << postfix << std::endl;
	
	// 2. 计算后缀表达式的值
	double result = evaluatePostfix(postfix);
	std::cout << "计算结果: " << result << std::endl;
	
	return 0;
}

