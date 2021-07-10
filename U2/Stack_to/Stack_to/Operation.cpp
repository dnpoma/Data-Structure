#include "Operation.h"

int Operation::precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void Operation::infix_to_postfix(std::string s) {
    Stack<char> st;
    std::string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;
        else if (c == '(')
            st.insert_front('(');

        else if (c == ')') {
            while (st.get_first()->get_data() != '(')
            {
                result += st.get_first()->get_data();
                st.delete_front();
            }
            st.delete_front();
        }

        else {
            while (!st.empty_stack() && precedence(s[i]) <= precedence(st.get_first()->get_data())) {
                result += st.get_first()->get_data();
                st.delete_front();
            }
            st.insert_front(c);
        }
    }

    while (!st.empty_stack()) {
        result += st.get_first()->get_data();
        st.delete_front();
    }

    std::cout << result << std::endl;
}


double Operation::postfix_evaluation(char* exp) {
    Stack<double> stack;
    for (int i = 0; exp[i]; i++) {
        if (exp[i] == ' ')continue;
        else if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            i--;
            stack.insert_front(num);
        }
        else {
            double val1 = stack.get_first()->get_data();
            stack.delete_front();
            double val2 = stack.get_first()->get_data();
            stack.delete_front();

            switch (exp[i])
            {
            case '+': stack.insert_front(val2 + val1); break;
            case '-': stack.insert_front(val2 - val1); break;
            case '*': stack.insert_front(val2 * val1); break;
            case '/': stack.insert_front(val2 / val1); break;
            }
        }
    }
    std::cout << stack.get_first()->get_data() << std::endl;
    return stack.get_first()->get_data();
}

double Operation::prefix_evaluation(std::string exp) {
    Stack<double> stack;
    for (int j = exp.size() - 1; j >= 0; j--) {
        if (exp[j] == ' ')continue;
        if (isdigit(exp[j])) {
            double num = 0;
            int i = j;
            while (j<exp.size() && isdigit(exp[j])) 
                j--;
            j++;
            for (int k = j; k <= i; k++) {
                num = num * 10 + (exp[k] - '0');
            }
         
            stack.insert_front(num);
        }
        else {
            double val1 = stack.get_first()->get_data();
            stack.delete_front();
            double val2 = stack.get_first()->get_data();
            stack.delete_front();

            switch (exp[j])
            {
            case '+': stack.insert_front(val1 + val2); break;
            case '-': stack.insert_front(val1 - val2); break;
            case '*': stack.insert_front(val1 * val2); break;
            case '/': stack.insert_front(val1 / val2); break;
            default: std::cout << "Invalid Expression" << std::endl; return 0;
            }
        }
    }
    std::cout << "Respuesta: " << stack.get_first()->get_data() << std::endl;
    return stack.get_first()->get_data();
}