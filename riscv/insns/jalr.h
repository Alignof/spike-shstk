reg_t tmp = npc;
set_pc((RS1 + insn.i_imm()) & ~reg_t(1));
// call
if (insn.rd() == 1 && insn.rs1() == 1) {
    p->get_state()->shstk.push(tmp);
}
// ret
if (insn.rd() == 1 && insn.rs1() == 1 && insn.i_imm() == 0) {
    uint64_t ret_addr = p->get_state()->shstk.pop();
    if (ret_addr != ((RS1 + insn.i_imm()) & ~reg_t(1))) {
        // exception
    }
}
WRITE_RD(tmp);

