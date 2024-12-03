struct state {
    // ...

    state() {
    }

    void edit() {
    }

    void undo() {
    }

    int eval() const {
    }
};

state anneal(int ms) {
    const double temp_start = 10, temp_end = 0.001;
    clock_t start = clock();

    state cur;
    int cur_cost = cur.eval(), new_cost, mn_cost = cur_cost;
    while (true) {
        double elapsed_frac = double(clock() - start) / CLOCKS_PER_SEC * 1000 / ms;
        if (elapsed_frac >= 1) {
            break;
        }

        cur.edit();
        new_cost = cur.eval();

        double temp = temp_start * pow(temp_end / temp_start, elapsed_frac);
        if (new_cost < cur_cost || double(rand()) / RAND_MAX < exp((cur_cost - new_cost) / temp)) {
            cur_cost = new_cost;
        } else {
            cur.undo();
        }

        mn_cost = min(mn_cost, cur_cost);
    }
    return cur;
}