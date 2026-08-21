class MinStack {
    int *stiva, *stiva_min;
    int vf;
public:
    MinStack() {
        stiva = new int[30000];
        stiva_min = new int[30000];
        vf = -1;
    }
    
    void push(int val) {
        vf++;
        stiva[vf] = val;
        if (vf > 0) {
            if (val < stiva_min[vf-1]) stiva_min[vf] = val;
            else stiva_min[vf] = stiva_min[vf - 1];
        }
        else stiva_min[vf] = val;
    }
    
    void pop() {
        vf--;
    }
    
    int top() {
        return stiva[vf];
    }
    
    int getMin() {
        return stiva_min[vf];
    }
};
