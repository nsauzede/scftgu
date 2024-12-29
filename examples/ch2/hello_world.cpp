#include <systemc>

using namespace sc_core;


SC_MODULE(Hello_SystemC)  {

    SC_CTOR(Hello_SystemC) {
        SC_THREAD(main_thread);

    }

    void main_thread(void) {

        SC_REPORT_INFO("example", "In main thread.");
    }
};

int sc_main(int sc_argc, char *sc_argv[]) {

    Hello_SystemC hello_systemc0("hello_systemc0");

    sc_start();

    return 0;
}
