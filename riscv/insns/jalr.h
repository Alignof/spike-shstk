reg_t tmp = npc;
set_pc((RS1 + insn.i_imm()) & ~reg_t(1));
// call
if (insn.rd() == 1) {
    fprintf(stderr, "call\n");
    p->get_state()->shstk.push(tmp);
}
// ret
if (insn.rd() == 0 && insn.rs1() == 1 && insn.i_imm() == 0) {
    fprintf(stderr, "ret\n");
    uint64_t ret_addr = p->get_state()->shstk.pop();
    if (ret_addr != ((RS1 + insn.i_imm()) & ~reg_t(1))) {
        // exception
        fprintf(
            stderr,
            "exception at [0x%x]: value popped from shstk does not match return addr\n",
            pc
        );
    }
}
WRITE_RD(tmp);

