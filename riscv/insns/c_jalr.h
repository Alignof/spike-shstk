require_extension('C');
require(insn.rvc_rs1() != 0);
reg_t tmp = npc;
set_pc(RVC_RS1 & ~reg_t(1));
// call
if (insn.rvc_rd() == 1 && insn.rvc_rs1() == 1) {
    p->get_state()->shstk.push(tmp);
}
// ret
if (insn.rvc_rd() == 1 && insn.rvc_rs1() == 1 && insn.rvc_imm() == 0) {
    uint64_t ret_addr = p->get_state()->shstk.pop();
    if (ret_addr != (RVC_RS1 & ~reg_t(1))) {
        // exception
        printf("exception: value poped from shstk does not match return addr\n");
    }
}
WRITE_REG(X_RA, tmp);
