require_extension('C');
require(insn.rvc_rs1() != 0);
set_pc(RVC_RS1 & ~reg_t(1));
// ret
if (insn.rvc_rs1() == 1) {
    fprintf(stderr, "ret\n");
    uint64_t ret_addr = p->get_state()->shstk.pop();
    if (ret_addr != (RVC_RS1 & ~reg_t(1))) {
        // exception
        fprintf(
            stderr,
            "exception at [0x%x]: value popped from shstk does not match return addr\n",
            pc
        );
    }
}
