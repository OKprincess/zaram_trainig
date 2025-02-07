// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vriscv_top__Syms.h"
#include "Vriscv_top.h"
#include "Vriscv_top_riscv_top.h"



// FUNCTIONS
Vriscv_top__Syms::Vriscv_top__Syms(Vriscv_top* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_activity(false)
    , __Vm_baseCode(0)
    , __Vm_didInit(false)
    // Setup submodule names
    , TOP__riscv_top(Verilated::catName(topp->name(), "riscv_top"))
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    TOPp->riscv_top = &TOP__riscv_top;
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    TOP__riscv_top.__Vconfigure(this, true);
    // Setup scopes
    __Vscope_TOP.configure(this, name(), "TOP", "TOP", 0, VerilatedScope::SCOPE_OTHER);
    __Vscope_riscv_top.configure(this, name(), "riscv_top", "riscv_top", 0, VerilatedScope::SCOPE_OTHER);
    // Setup export functions
    for (int __Vfinal=0; __Vfinal<2; __Vfinal++) {
        __Vscope_TOP.varInsert(__Vfinal,"i_clk", &(TOPp->i_clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_TOP.varInsert(__Vfinal,"i_rstn", &(TOPp->i_rstn), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_riscv_top.varInsert(__Vfinal,"i_clk", &(TOP__riscv_top.i_clk), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
        __Vscope_riscv_top.varInsert(__Vfinal,"i_rstn", &(TOP__riscv_top.i_rstn), false, VLVT_UINT8,VLVD_IN|VLVF_PUB_RW,0);
    }
}
