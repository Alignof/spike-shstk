require_extension('C');
require(insn.rvc_rs1() != 0);
reg_t tmp = npc;
set_pc(RVC_RS1 & ~reg_t(1));
// call
fprintf(stderr, "call\n");
p->get_state()->shstk.push(tmp);
WRITE_REG(X_RA, tmp);
