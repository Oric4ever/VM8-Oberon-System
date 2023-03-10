#include <inttypes.h>

#define  byte uint8_t
#define sbyte int8_t
#define  word uint16_t
#define sword int16_t
#define dword int32_t
#define qword double

extern word BC, IP, FRAME_PTR, STACK_PTR;
extern byte bdos(word fct, word param);
extern word bios(word fct, word param);
extern void init_bios(char *);
extern void warm_boot(void);
extern byte mem[];
extern byte *MEM(int addr);
extern word *WMEM(int addr);

#define  FETCH            mem[IP++]
#define WFETCH            (mem[IP++] | (mem[IP++]<<8))
#define IFETCH            ((sbyte)FETCH)
#define GLOBAL_PTR        (*WMEM(0x0312))
#define LOCAL             WMEM(LOCAL_PTR)
#define GLOBAL            WMEM(GLOBAL_PTR)
#define STACK_ADDRESSED   WMEM(ppop())
#define DSTACK_ADDRESSED  DMEM(ppop())
#define BARRAY_INDEXED(i) (* MEM((word)(ppop() + i)))
#define WARRAY_INDEXED(i) (*WMEM((word)(ppop() + i*2)))
#define DARRAY_INDEXED(i) (*DMEM((word)(ppop() + i*4)))
#define QARRAY_INDEXED(i) (*QMEM((word)(ppop() + i*8)))
#define MODULE(m)         GLOBAL[-9-(m)]
#define EXTERN(m)         WMEM(MODULE(m))
#define STACK_LIMIT       *WMEM(0x0316)
#define FREE_LIST         0x0318
#define STACK             WMEM(STACK_PTR)
#define ITOP              ((sword)TOP)

#define BOUNDS_ERROR 2
#define IBOUNDS_ERROR 3
#define NEGATIVE_ERROR 4
#define OUTOFMEM_ERROR 5
#define POINTER_ERROR 7
#define DIVBYZERO_ERROR 8
#define NORETFUNCTION_ERROR 9
#define ENDOFCOROUT_ERROR 10
#define REALOVERFLOW_ERROR 11
#define OVERFLOW_ERROR 12
#define CASESELECT_ERROR 13
#define BADHEAP_ERROR 14
#define STRINGTOOLONG_ERROR 15
#define ILLEGAL_INSTRUCTION 16
#define STACKOVERFLOW_ERROR 17
