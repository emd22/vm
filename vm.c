#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define VM_MODE 16B 0
#define VM_MODE_32B 1
#define VM_MODE_64B 2

#define vm_mov(mode, v1, v2) (mode >= 0x01 && mode <= 0x03)

#define VM_MOV      0x01
#define VM_MOV_CLR   0x00 // clear register
#define VM_MOV_V_RL  0x01 // move immediate value to low register
#define VM_MOV_V_RH  0x02 // move immediate value to high register
#define VM_MOV_V_R   0x03 // move immediate value to full register
#define VM_MOV_RL_R  0x04 // move low register to full register
#define VM_MOV_RH_R  0x05 // move high register to full register
#define VM_MOV_RL_RH 0x06 // move low register to high register
#define VM_MOV_RH_RL 0x07 // move high register to low register
#define VM_MOV_R_R   0x08 // move full register to full register

#define VM_JMP  0x02
#define VM_CALL 0x03
#define VM_RET  0x04
#define VM_ADD  0x05
#define VM_SUB  0x06
#define VM_MUL  0x07
#define VM_MODE_SW 0x08
#define VM_PUSH 0x09
#define VM_POP  0x0A

// REGISTERS
/*
registers use 64 bit values, but you can have access to low and high parts of each register depending on the mode.
on mode change, registers do not get cleared.
VM_MODE_64B:
    ALL: usable size is 64 bits
    LOW: gives low 32 bit value
    HIGH: gives high 32 bit value
VM_MODE_32B:
    ALL: usable size is 32 bits
    LOW: gives 16 bit value
    HIGH: gives 16 bit value
VM_MODE_16B:
    ALL: usable size is 16 bits
    LOW: gives 8 bit value
    HIGH: gives 8 bit value
*/
uint64_t registers[4];
unsigned char vm_mode = VM_MODE_64B;

void mov_im_reg(char mode, uint64_t val, uint8_t rloc) {
    switch (mode) {
        case VM_MOV_V_RL:
            registers[rloc] = val;
    };
}

inline void mov(char mode, uint64_t rloc0, uint8_t rloc1) {
    switch (mode) {
        case VM_MOV_CLR:
            registers[rloc0] = 0;
            break;
        case VM_MOV_V_RL:
            
    }    
}

int main() {
    FILE *fp = fopen("bc.bin", "rb");
    fseek(SEEK_END, 0, fp);
    unsigned long fsize = ftell(fp);
    rewind(fp);
    
    char *data = malloc(fsize);
    fread(data, 1, fsize, fp);
    char *newb = data;
    char ch;
    
    while (ch = *(newb++)) {
        switch (ch) {
            case 
        }; 
    }
}
