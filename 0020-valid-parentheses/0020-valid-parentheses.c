#define MAX_SIZE 100000

bool isValid(char* s) {
    int stack[MAX_SIZE];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++){
        char ch = s[i];

        if (ch == '(' || ch == '[' || ch == '{'){
            stack[++top] = ch;
        }
        else if (ch == ')' || ch == ']' || ch == '}'){
            if (top == -1) return false;

            char t = stack[top];

            if (ch == ')' && t == '(' ||
                ch == ']' && t == '[' ||
                ch == '}' && t == '{')
                top--;

            else return false;
        }
    }
    return top == -1;
}