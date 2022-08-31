reg_t tmp = npc;
set_pc(JUMP_TARGET);
// call
if (insn.rd() == 1) {
    fprintf(stderr, "call\n");
    p->get_state()->shstk.push(tmp);
}
WRITE_RD(tmp);
