#include <stdio.h>

int add(int x, int y);

int call_add(int x, int y) {
    return add(x, y);
}

int main(void) {
    int ret = call_add(1, 2);
    printf("%d\n", ret);
    return 0;
}

// O0 :
//
// 0000000000001149 <call_add>:
//     1149:       f3 0f 1e fa             endbr64 
//     114d:       55                      push   %rbp
//     114e:       48 89 e5                mov    %rsp,%rbp
//     1151:       48 83 ec 10             sub    $0x10,%rsp
//     1155:       89 7d fc                mov    %edi,-0x4(%rbp)
//     1158:       89 75 f8                mov    %esi,-0x8(%rbp)
//     115b:       8b 55 f8                mov    -0x8(%rbp),%edx
//     115e:       8b 45 fc                mov    -0x4(%rbp),%eax
//     1161:       89 d6                   mov    %edx,%esi
//     1163:       89 c7                   mov    %eax,%edi
//     1165:       e8 3d 00 00 00          callq  11a7 <add>
//     116a:       c9                      leaveq 
//     116b:       c3                      retq   
//
// 000000000000116c <main>:
//     116c:       f3 0f 1e fa             endbr64 
//     1170:       55                      push   %rbp
//     1171:       48 89 e5                mov    %rsp,%rbp
//     1174:       48 83 ec 10             sub    $0x10,%rsp
//     1178:       be 02 00 00 00          mov    $0x2,%esi
//     117d:       bf 01 00 00 00          mov    $0x1,%edi
//     1182:       e8 c2 ff ff ff          callq  1149 <call_add>
//     1187:       89 45 fc                mov    %eax,-0x4(%rbp)
//     118a:       8b 45 fc                mov    -0x4(%rbp),%eax
//     118d:       89 c6                   mov    %eax,%esi
//     118f:       48 8d 3d 6e 0e 00 00    lea    0xe6e(%rip),%rdi        # 2004 <_IO_stdin_used+0x4>
//     1196:       b8 00 00 00 00          mov    $0x0,%eax
//     119b:       e8 b0 fe ff ff          callq  1050 <printf@plt>
//     11a0:       b8 00 00 00 00          mov    $0x0,%eax
//     11a5:       c9                      leaveq 
//     11a6:       c3                      retq   
//
// 00000000000011a7 <add>:
//     11a7:       f3 0f 1e fa             endbr64 
//     11ab:       55                      push   %rbp
//     11ac:       48 89 e5                mov    %rsp,%rbp
//     11af:       89 7d fc                mov    %edi,-0x4(%rbp)
//     11b2:       89 75 f8                mov    %esi,-0x8(%rbp)
//     11b5:       8b 55 fc                mov    -0x4(%rbp),%edx
//     11b8:       8b 45 f8                mov    -0x8(%rbp),%eax
//     11bb:       01 d0                   add    %edx,%eax
//     11bd:       5d                      pop    %rbp
//     11be:       c3                      retq   
//     11bf:       90                      nop

// O1 :
// 0000000000001149 <call_add>:
//     1149:       f3 0f 1e fa             endbr64 
//     114d:       48 83 ec 08             sub    $0x8,%rsp
//     1151:       e8 3e 00 00 00          callq  1194 <add>
//     1156:       48 83 c4 08             add    $0x8,%rsp
//     115a:       c3                      retq   
//
// 000000000000115b <main>:
//     115b:       f3 0f 1e fa             endbr64 
//     115f:       48 83 ec 08             sub    $0x8,%rsp
//     1163:       be 02 00 00 00          mov    $0x2,%esi
//     1168:       bf 01 00 00 00          mov    $0x1,%edi
//     116d:       e8 22 00 00 00          callq  1194 <add>
//     1172:       89 c2                   mov    %eax,%edx
//     1174:       48 8d 35 89 0e 00 00    lea    0xe89(%rip),%rsi        # 2004 <_IO_stdin_used+0x4>
//     117b:       bf 01 00 00 00          mov    $0x1,%edi
//     1180:       b8 00 00 00 00          mov    $0x0,%eax
//     1185:       e8 c6 fe ff ff          callq  1050 <__printf_chk@plt>
//     118a:       b8 00 00 00 00          mov    $0x0,%eax
//     118f:       48 83 c4 08             add    $0x8,%rsp
//     1193:       c3                      retq   
//
// 0000000000001194 <add>:
//     1194:       f3 0f 1e fa             endbr64 
//     1198:       8d 04 37                lea    (%rdi,%rsi,1),%eax
//     119b:       c3                      retq   
//     119c:       0f 1f 40 00             nopl   0x0(%rax)