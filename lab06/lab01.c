#include <stdio.h>

long incr(long* p, long val);

long call_incr() {
    long v1 = 15213;
    long v2 = incr(&v1, 3000);
    return v1 + v2;
}

int main(void) {
    call_incr();
    return 0;
}

// 0000000000001149 <call_incr>:
//     1149:       f3 0f 1e fa             endbr64 
//     114d:       55                      push   %rbp
//     114e:       48 89 e5                mov    %rsp,%rbp
//     1151:       48 83 ec 20             sub    $0x20,%rsp
//     1155:       64 48 8b 04 25 28 00    mov    %fs:0x28,%rax
//     115c:       00 00 
//     115e:       48 89 45 f8             mov    %rax,-0x8(%rbp)
//     1162:       31 c0                   xor    %eax,%eax
//     1164:       48 c7 45 e8 6d 3b 00    movq   $0x3b6d,-0x18(%rbp)
//     116b:       00 
//     116c:       48 8d 45 e8             lea    -0x18(%rbp),%rax
//     1170:       be b8 0b 00 00          mov    $0xbb8,%esi
//     1175:       48 89 c7                mov    %rax,%rdi
//     1178:       e8 3e 00 00 00          callq  11bb <incr>
//     117d:       48 89 45 f0             mov    %rax,-0x10(%rbp)
//     1181:       48 8b 55 e8             mov    -0x18(%rbp),%rdx
//     1185:       48 8b 45 f0             mov    -0x10(%rbp),%rax
//     1189:       48 01 d0                add    %rdx,%rax
//     118c:       48 8b 4d f8             mov    -0x8(%rbp),%rcx
//     1190:       64 48 33 0c 25 28 00    xor    %fs:0x28,%rcx
//     1197:       00 00 
//     1199:       74 05                   je     11a0 <call_incr+0x57>
//     119b:       e8 b0 fe ff ff          callq  1050 <__stack_chk_fail@plt>
//     11a0:       c9                      leaveq 
//     11a1:       c3                      retq   

// 00000000000011a2 <main>:
//     11a2:       f3 0f 1e fa             endbr64 
//     11a6:       55                      push   %rbp
//     11a7:       48 89 e5                mov    %rsp,%rbp
//     11aa:       b8 00 00 00 00          mov    $0x0,%eax
//     11af:       e8 95 ff ff ff          callq  1149 <call_incr>
//     11b4:       b8 00 00 00 00          mov    $0x0,%eax
//     11b9:       5d                      pop    %rbp
//     11ba:       c3                      retq   

// 00000000000011bb <incr>:
//     11bb:       f3 0f 1e fa             endbr64 
//     11bf:       55                      push   %rbp
//     11c0:       48 89 e5                mov    %rsp,%rbp
//     11c3:       48 89 7d e8             mov    %rdi,-0x18(%rbp)
//     11c7:       48 89 75 e0             mov    %rsi,-0x20(%rbp)
//     11cb:       48 8b 45 e8             mov    -0x18(%rbp),%rax
//     11cf:       48 8b 00                mov    (%rax),%rax
//     11d2:       48 89 45 f0             mov    %rax,-0x10(%rbp)
//     11d6:       48 8b 55 f0             mov    -0x10(%rbp),%rdx
//     11da:       48 8b 45 e0             mov    -0x20(%rbp),%rax
//     11de:       48 01 d0                add    %rdx,%rax
//     11e1:       48 89 45 f8             mov    %rax,-0x8(%rbp)
//     11e5:       48 8b 45 e8             mov    -0x18(%rbp),%rax
//     11e9:       48 8b 55 f8             mov    -0x8(%rbp),%rdx
//     11ed:       48 89 10                mov    %rdx,(%rax)
//     11f0:       48 8b 45 f0             mov    -0x10(%rbp),%rax
//     11f4:       5d                      pop    %rbp
//     11f5:       c3                      retq   
//     11f6:       66 2e 0f 1f 84 00 00    nopw   %cs:0x0(%rax,%rax,1)
//     11fd:       00 00 00 

// (gdb) x/128xb $rsp
// 0x7fffffffe160: 0x90    0xe1    0xff    0xff    0xff    0x7f    0x00    0x00
// 0x7fffffffe168: 0x7d    0x51    0x55    0x55    0x55    0x55    0x00    0x00
// 0x7fffffffe170: 0xe8    0xf2    0xfb    0xf7    0xff    0x7f    0x00    0x00
// 0x7fffffffe178: 0x6d    0x3b    0x00    0x00    0x00    0x00    0x00    0x00
// 0x7fffffffe180: 0x00    0x00    0x00    0x00    0x00    0x00    0x00    0x00
// 0x7fffffffe188: 0x00    0x7e    0xaa    0x33    0x27    0x2b    0xac    0xa4
// 0x7fffffffe190: 0xa0    0xe1    0xff    0xff    0xff    0x7f    0x00    0x00
// 0x7fffffffe198: 0xb4    0x51    0x55    0x55    0x55    0x55    0x00    0x00
// 0x7fffffffe1a0: 0x00    0x00    0x00    0x00    0x00    0x00    0x00    0x00
// 0x7fffffffe1a8: 0x83    0x20    0xdf    0xf7    0xff    0x7f    0x00    0x00
// 0x7fffffffe1b0: 0x20    0xc6    0xff    0xf7    0xff    0x7f    0x00    0x00
// 0x7fffffffe1b8: 0x98    0xe2    0xff    0xff    0xff    0x7f    0x00    0x00
// 0x7fffffffe1c0: 0x00    0x00    0x00    0x00    0x01    0x00    0x00    0x00
// 0x7fffffffe1c8: 0xa2    0x51    0x55    0x55    0x55    0x55    0x00    0x00
// 0x7fffffffe1d0: 0x00    0x52    0x55    0x55    0x55    0x55    0x00    0x00
// 0x7fffffffe1d8: 0x3e    0x75    0x95    0x29    0x0b    0xcc    0x74    0x3a
// (gdb) i f 0
// Stack frame at 0x7fffffffe170:
//  rip = 0x5555555551cb in incr (incr.c:2); saved rip = 0x55555555517d
//  called by frame at 0x7fffffffe1a0
//  source language c.
//  Arglist at 0x7fffffffe158, args: p=0x7fffffffe178, val=3000
//  Locals at 0x7fffffffe158, Previous frame's sp is 0x7fffffffe170
//  Saved registers:
//   rbp at 0x7fffffffe160, rip at 0x7fffffffe168
// (gdb) i f 1
// Stack frame at 0x7fffffffe1a0:
//  rip = 0x55555555517d in call_incr (lab01.c:7); saved rip = 0x5555555551b4
//  called by frame at 0x7fffffffe1b0, caller of frame at 0x7fffffffe170
//  source language c.
//  Arglist at 0x7fffffffe168, args: 
//  Locals at 0x7fffffffe168, Previous frame's sp is 0x7fffffffe1a0
//  Saved registers:
//   rbp at 0x7fffffffe190, rip at 0x7fffffffe198
// (gdb) i f 2
// Stack frame at 0x7fffffffe1b0:
//  rip = 0x5555555551b4 in main (lab01.c:12); saved rip = 0x7ffff7df2083
//  caller of frame at 0x7fffffffe1a0
//  source language c.
//  Arglist at 0x7fffffffe198, args: 
//  Locals at 0x7fffffffe198, Previous frame's sp is 0x7fffffffe1b0
//  Saved registers:
//   rbp at 0x7fffffffe1a0, rip at 0x7fffffffe1a8

// (gdb) disas main
// Dump of assembler code for function main:
//    0x00005555555551a2 <+0>:     endbr64 
//    0x00005555555551a6 <+4>:     push   %rbp
//    0x00005555555551a7 <+5>:     mov    %rsp,%rbp
//    0x00005555555551aa <+8>:     mov    $0x0,%eax
//    0x00005555555551af <+13>:    callq  0x555555555149 <call_incr>
//    0x00005555555551b4 <+18>:    mov    $0x0,%eax
//    0x00005555555551b9 <+23>:    pop    %rbp
//    0x00005555555551ba <+24>:    retq   
// End of assembler dump.
// (gdb) disas call_incr
// Dump of assembler code for function call_incr:
//    0x0000555555555149 <+0>:     endbr64 
//    0x000055555555514d <+4>:     push   %rbp
//    0x000055555555514e <+5>:     mov    %rsp,%rbp
//    0x0000555555555151 <+8>:     sub    $0x20,%rsp
//    0x0000555555555155 <+12>:    mov    %fs:0x28,%rax
//    0x000055555555515e <+21>:    mov    %rax,-0x8(%rbp)
//    0x0000555555555162 <+25>:    xor    %eax,%eax
//    0x0000555555555164 <+27>:    movq   $0x3b6d,-0x18(%rbp)
//    0x000055555555516c <+35>:    lea    -0x18(%rbp),%rax
//    0x0000555555555170 <+39>:    mov    $0xbb8,%esi
//    0x0000555555555175 <+44>:    mov    %rax,%rdi
//    0x0000555555555178 <+47>:    callq  0x5555555551bb <incr>
//    0x000055555555517d <+52>:    mov    %rax,-0x10(%rbp)
//    0x0000555555555181 <+56>:    mov    -0x18(%rbp),%rdx
//    0x0000555555555185 <+60>:    mov    -0x10(%rbp),%rax
//    0x0000555555555189 <+64>:    add    %rdx,%rax
//    0x000055555555518c <+67>:    mov    -0x8(%rbp),%rcx
//    0x0000555555555190 <+71>:    xor    %fs:0x28,%rcx
//    0x0000555555555199 <+80>:    je     0x5555555551a0 <call_incr+87>
//    0x000055555555519b <+82>:    callq  0x555555555050 <__stack_chk_fail@plt>
//    0x00005555555551a0 <+87>:    leaveq 
//    0x00005555555551a1 <+88>:    retq   
// End of assembler dump.
// (gdb) disas incr
// Dump of assembler code for function incr:
//    0x00005555555551bb <+0>:     endbr64 
//    0x00005555555551bf <+4>:     push   %rbp
//    0x00005555555551c0 <+5>:     mov    %rsp,%rbp
//    0x00005555555551c3 <+8>:     mov    %rdi,-0x18(%rbp)
//    0x00005555555551c7 <+12>:    mov    %rsi,-0x20(%rbp)
// => 0x00005555555551cb <+16>:    mov    -0x18(%rbp),%rax
//    0x00005555555551cf <+20>:    mov    (%rax),%rax
//    0x00005555555551d2 <+23>:    mov    %rax,-0x10(%rbp)
//    0x00005555555551d6 <+27>:    mov    -0x10(%rbp),%rdx
//    0x00005555555551da <+31>:    mov    -0x20(%rbp),%rax
//    0x00005555555551de <+35>:    add    %rdx,%rax
//    0x00005555555551e1 <+38>:    mov    %rax,-0x8(%rbp)
//    0x00005555555551e5 <+42>:    mov    -0x18(%rbp),%rax
//    0x00005555555551e9 <+46>:    mov    -0x8(%rbp),%rdx
//    0x00005555555551ed <+50>:    mov    %rdx,(%rax)
//    0x00005555555551f0 <+53>:    mov    -0x10(%rbp),%rax
//    0x00005555555551f4 <+57>:    pop    %rbp
//    0x00005555555551f5 <+58>:    retq   
// End of assembler dump.