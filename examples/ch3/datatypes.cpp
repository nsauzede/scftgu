#define SC_INCLUDE_FX

#include <systemc.h>

//sc_dt::sc_bigint<200> bigint_200_bits ;
sc_dt::sc_int<13> hello(42);


int sc_main(int sc_argc,  char *sc_argv[]) {

    // Bit vector
    {
        sc_bv<7> opcode = "0110011";
        sc_bv<5> rs1 = 0;
        sc_bv<5> rs2 = 1;
        sc_bv<5> rd = "10101";
        sc_bv<3> func3 = 0;
        sc_bv<7> func7 = "0000000";

        sc_bv<32> inst = opcode;
        inst.range(11,7) = rd;
        inst.range(24,20) = rs2;

        sc_bv<1> all = inst.and_reduce();

        sc_bv<7> mask = "000011";
        sc_bv<7> active = opcode & mask;
    }

    // Logic vector
    sc_lv<5> lv_active;
    {
        sc_lv<5> positions = "01xz1";
        sc_lv<6> mask      = "Xz1001";
        lv_active       = positions & mask;
        sc_lv<1> all = lv_active.and_reduce();
        sc_lv<2> uninit;
        uninit[0] = sc_dt::SC_LOGIC_Z;
        uninit[1] = sc_dt::SC_LOGIC_X;

        lv_active.range(3,2) = "00";
    }

    // ints
    {
        sc_uint<24> rgb = 0xFF8040;
        sc_int<5> sample = lv_active;
    }


    // big ints
    {
        sc_biguint<129>  remainder = "0x420000000000000000";
        sc_biguint<64>  divisor = 0x4200000000;
    }


    // fixed
    {
        sc_ufixed<5,3> a = "0b101.01";
        sc_fixed<5,3> b = "2.5";
        sc_ufixed<5,3> c = 7.75;
        const sc_ufixed<19,3> PI("3.141592654");
        sc_fix temp(20,17,SC_RND_INF,SC_SAT);
        temp = 36.6;
        sc_fixed_fast<7,1> foo;

        std::cout << "PI=" << PI << "\n";
        printf("a=%s, c=%f\n", a.to_string().c_str(), (float) c);

    }


    return 0;
}

