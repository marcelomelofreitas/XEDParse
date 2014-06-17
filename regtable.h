#pragma once

// Update 'enum REG' along with RegisterIds
// Update 'enum SEG' along with SegmentIds

extern "C"
{
	#include "xed2\include\xed-interface.h"
}

enum REG
{
	/* Invalid */
	REG_INVALID,

	/* Processor control registers */
	REG_CR0,
	REG_CR2,
	REG_CR3,
	REG_CR4,
#ifdef _WIN64
	REG_CR8,
#endif

	/* Debug registers */
	REG_DR0,
	REG_DR1,
	REG_DR2,
	REG_DR3,
	REG_DR6,
	REG_DR7,

	/* X86 general purpose registers */
	REG_EAX,
	REG_AX,
	REG_AH,
	REG_AL,

	REG_EBX,
	REG_BX,
	REG_BH,
	REG_BL,

	REG_ECX,
	REG_CX,
	REG_CH,
	REG_CL,

	REG_EDX,
	REG_DX,
	REG_DH,
	REG_DL,

	REG_EDI,
	REG_DI,

	REG_ESI,
	REG_SI,

	REG_EBP,
	REG_BP,

	REG_ESP,
	REG_SP,

	/* X64 general purpose registers */
#ifdef _WIN64
	REG_RAX,
	REG_RBX,
	REG_RCX,
	REG_RDX,

	REG_RSI,
	REG_SIL,

	REG_RDI,
	REG_DIL,

	REG_RBP,
	REG_BPL,

	REG_RSP,
	REG_SPL,

	REG_RIP,

	REG_R8,
	REG_R8D,
	REG_R8W,
	REG_R8B,

	REG_R9,
	REG_R9D,
	REG_R9W,
	REG_R9B,

	REG_R10,
	REG_R10D,
	REG_R10W,
	REG_R10B,

	REG_R11,
	REG_R11D,
	REG_R11W,
	REG_R11B,

	REG_R12,
	REG_R12D,
	REG_R12W,
	REG_R12B,

	REG_R13,
	REG_R13D,
	REG_R13W,
	REG_R13B,

	REG_R14,
	REG_R14D,
	REG_R14W,
	REG_R14B,

	REG_R15,
	REG_R15D,
	REG_R15W,
	REG_R15B,
#endif //_WIN64

	/* Floating point XXM# */
	REG_XMM0,
	REG_XMM1,
	REG_XMM2,
	REG_XMM3,
	REG_XMM4,
	REG_XMM5,
	REG_XMM6,
	REG_XMM7,
#ifdef _WIN64
	REG_XMM8,
	REG_XMM9,
	REG_XMM10,
	REG_XMM11,
	REG_XMM12,
	REG_XMM13,
	REG_XMM14,
	REG_XMM15,
#endif // _WIN64

	/* Advanced vector extensions V1 YMM# */
	REG_YMM0,
	REG_YMM1,
	REG_YMM2,
	REG_YMM3,
	REG_YMM4,
	REG_YMM5,
	REG_YMM6,
	REG_YMM7,
#ifdef _WIN64
	REG_YMM8,
	REG_YMM9,
	REG_YMM10,
	REG_YMM11,
	REG_YMM12,
	REG_YMM13,
	REG_YMM14,
	REG_YMM15,
#endif // _WIN64

	/* Segment registers */
	REG_SINVALID,
	REG_CS,
	REG_DS,
	REG_ES,
	REG_FS,
	REG_GS,
	REG_SS,
};

enum SEG
{
	SEG_INVALID,
	SEG_CS,
	SEG_DS,
	SEG_ES,
	SEG_FS,
	SEG_GS,
	SEG_SS,
};

struct RegEntry
{
	const char		*Name;
	REG				RegId;
	xed_reg_enum_t	XedId;
	REGSIZE			Size;
};

static RegEntry RegisterIds[] =
{
	/* Invalid */
	{ "rinval", REG_INVALID, XED_REG_INVALID, SIZE_BYTE },

	/* Processor control registers */
#ifndef _WIN64
	{ "cr0", REG_CR0, XED_REG_CR0, SIZE_DWORD },
	{ "cr2", REG_CR2, XED_REG_CR2, SIZE_DWORD },
	{ "cr3", REG_CR3, XED_REG_CR3, SIZE_DWORD },
	{ "cr4", REG_CR4, XED_REG_CR4, SIZE_DWORD },
#else
	{ "cr0", REG_CR0, XED_REG_CR0, SIZE_QWORD },
	{ "cr2", REG_CR2, XED_REG_CR2, SIZE_QWORD },
	{ "cr3", REG_CR3, XED_REG_CR3, SIZE_QWORD },
	{ "cr4", REG_CR4, XED_REG_CR4, SIZE_QWORD },
	{ "cr8", REG_CR8, XED_REG_CR8, SIZE_QWORD },
#endif // ndef _WIN64

	/* Debug registers */
#ifndef _WIN64
	{ "dr0", REG_DR0, XED_REG_DR0, SIZE_DWORD },
	{ "dr1", REG_DR1, XED_REG_DR1, SIZE_DWORD },
	{ "dr2", REG_DR2, XED_REG_DR2, SIZE_DWORD },
	{ "dr3", REG_DR3, XED_REG_DR3, SIZE_DWORD },
	{ "dr6", REG_DR6, XED_REG_DR6, SIZE_DWORD },
	{ "dr7", REG_DR7, XED_REG_DR7, SIZE_DWORD },
#else
	{ "dr0", REG_DR0, XED_REG_DR0, SIZE_QWORD },
	{ "dr1", REG_DR1, XED_REG_DR1, SIZE_QWORD },
	{ "dr2", REG_DR2, XED_REG_DR2, SIZE_QWORD },
	{ "dr3", REG_DR3, XED_REG_DR3, SIZE_QWORD },
	{ "dr6", REG_DR6, XED_REG_DR6, SIZE_QWORD },
	{ "dr7", REG_DR7, XED_REG_DR7, SIZE_QWORD },
#endif // ndef _WIN64

	/* X86 general purpose registers */
	{ "eax", REG_EAX, XED_REG_EAX, SIZE_DWORD },
	{ "ax", REG_AX, XED_REG_AX, SIZE_WORD },
	{ "ah", REG_AH, XED_REG_AH, SIZE_BYTE },
	{ "al", REG_AL, XED_REG_AL, SIZE_BYTE },

	{ "ebx", REG_EBX, XED_REG_EBX, SIZE_DWORD },
	{ "bx", REG_BX, XED_REG_BX, SIZE_WORD },
	{ "bh", REG_BH, XED_REG_BH, SIZE_BYTE },
	{ "bl", REG_BL, XED_REG_BL, SIZE_BYTE },

	{ "ecx", REG_ECX, XED_REG_ECX, SIZE_DWORD },
	{ "cx", REG_CX, XED_REG_CX, SIZE_WORD },
	{ "ch", REG_CH, XED_REG_CH, SIZE_BYTE },
	{ "cl", REG_CL, XED_REG_CL, SIZE_BYTE },

	{ "edx", REG_EDX, XED_REG_EDX, SIZE_DWORD },
	{ "dx", REG_DX, XED_REG_DX, SIZE_WORD },
	{ "dh", REG_DH, XED_REG_DH, SIZE_BYTE },
	{ "dl", REG_DL, XED_REG_DL, SIZE_BYTE },

	{ "edi", REG_EDI, XED_REG_EDI, SIZE_DWORD },
	{ "di", REG_DI, XED_REG_DI, SIZE_WORD },

	{ "esi", REG_ESI, XED_REG_ESI, SIZE_DWORD },
	{ "si", REG_SI, XED_REG_SI, SIZE_WORD },

	{ "ebp", REG_EBP, XED_REG_EBP, SIZE_DWORD },
	{ "bp", REG_BP, XED_REG_BP, SIZE_WORD },

	{ "esp", REG_ESP, XED_REG_ESP, SIZE_DWORD },
	{ "sp", REG_SP, XED_REG_SP, SIZE_WORD },

	/* X64 general purpose registers */
#ifdef _WIN64
	{ "rax", REG_RAX, XED_REG_RAX, SIZE_QWORD },
	{ "rbx", REG_RBX, XED_REG_RBX, SIZE_QWORD },
	{ "rcx", REG_RCX, XED_REG_RCX, SIZE_QWORD },
	{ "rdx", REG_RDX, XED_REG_RDX, SIZE_QWORD },

	{ "rsi", REG_RSI, XED_REG_RSI, SIZE_QWORD },
	{ "sil", REG_SIL, XED_REG_SIL, SIZE_BYTE },

	{ "rdi", REG_RDI, XED_REG_RDI, SIZE_QWORD },
	{ "dil", REG_DIL, XED_REG_DIL, SIZE_BYTE },

	{ "rbp", REG_RBP, XED_REG_RBP, SIZE_QWORD },
	{ "bpl", REG_BPL, XED_REG_BPL, SIZE_BYTE },

	{ "rsp", REG_RSP, XED_REG_RSP, SIZE_QWORD },
	{ "spl", REG_SPL, XED_REG_SPL, SIZE_BYTE },

	{ "rip", REG_RIP, XED_REG_RIP, SIZE_QWORD },

	{ "r8", REG_R8, XED_REG_R8, SIZE_QWORD },
	{ "r8d", REG_R8D, XED_REG_R8D, SIZE_DWORD },
	{ "r8w", REG_R8W, XED_REG_R8W, SIZE_WORD },
	{ "r8b", REG_R8B, XED_REG_R8B, SIZE_BYTE },

	{ "r9", REG_R9, XED_REG_R9, SIZE_QWORD },
	{ "r9d", REG_R9D, XED_REG_R9D, SIZE_DWORD },
	{ "r9w", REG_R9W, XED_REG_R9W, SIZE_WORD },
	{ "r9b", REG_R9B, XED_REG_R9B, SIZE_BYTE },

	{ "r10", REG_R10, XED_REG_R10, SIZE_QWORD },
	{ "r10d", REG_R10D, XED_REG_R10D, SIZE_DWORD },
	{ "r10w", REG_R10W, XED_REG_R10W, SIZE_WORD },
	{ "r10b", REG_R10B, XED_REG_R10B, SIZE_BYTE },

	{ "r11", REG_R11, XED_REG_R11, SIZE_QWORD },
	{ "r11d", REG_R11D, XED_REG_R11D, SIZE_DWORD },
	{ "r11w", REG_R11W, XED_REG_R11W, SIZE_WORD },
	{ "r11b", REG_R11B, XED_REG_R11B, SIZE_BYTE },

	{ "r12", REG_R12, XED_REG_R12, SIZE_QWORD },
	{ "r12d", REG_R12D, XED_REG_R12D, SIZE_DWORD },
	{ "r12w", REG_R12W, XED_REG_R12W, SIZE_WORD },
	{ "r12b", REG_R12B, XED_REG_R12B, SIZE_BYTE },

	{ "r13", REG_R13, XED_REG_R13, SIZE_QWORD },
	{ "r13d", REG_R13D, XED_REG_R13D, SIZE_DWORD },
	{ "r13w", REG_R13W, XED_REG_R13W, SIZE_WORD },
	{ "r13b", REG_R13B, XED_REG_R13B, SIZE_BYTE },

	{ "r14", REG_R14, XED_REG_R14, SIZE_QWORD },
	{ "r14d", REG_R14D, XED_REG_R14D, SIZE_DWORD },
	{ "r14w", REG_R14W, XED_REG_R14W, SIZE_WORD },
	{ "r14b", REG_R14B, XED_REG_R14B, SIZE_BYTE },

	{ "r15", REG_R15, XED_REG_R15, SIZE_QWORD },
	{ "r15d", REG_R15D, XED_REG_R15D, SIZE_DWORD },
	{ "r15w", REG_R15W, XED_REG_R15W, SIZE_WORD },
	{ "r15b", REG_R15B, XED_REG_R15B, SIZE_BYTE },
#endif // _WIN64

	/* Floating point XXM# */
	{ "xmm0", REG_XMM0, XED_REG_XMM0, SIZE_XMMWORD },
	{ "xmm1", REG_XMM1, XED_REG_XMM1, SIZE_XMMWORD },
	{ "xmm2", REG_XMM2, XED_REG_XMM2, SIZE_XMMWORD },
	{ "xmm3", REG_XMM3, XED_REG_XMM3, SIZE_XMMWORD },
	{ "xmm4", REG_XMM4, XED_REG_XMM4, SIZE_XMMWORD },
	{ "xmm5", REG_XMM5, XED_REG_XMM5, SIZE_XMMWORD },
	{ "xmm6", REG_XMM6, XED_REG_XMM6, SIZE_XMMWORD },
	{ "xmm7", REG_XMM7, XED_REG_XMM7, SIZE_XMMWORD },
#ifdef _WIN64
	{ "xmm8", REG_XMM8, XED_REG_XMM8, SIZE_XMMWORD },
	{ "xmm9", REG_XMM9, XED_REG_XMM9, SIZE_XMMWORD },
	{ "xmm10", REG_XMM10, XED_REG_XMM10, SIZE_XMMWORD },
	{ "xmm11", REG_XMM11, XED_REG_XMM11, SIZE_XMMWORD },
	{ "xmm12", REG_XMM12, XED_REG_XMM12, SIZE_XMMWORD },
	{ "xmm13", REG_XMM13, XED_REG_XMM13, SIZE_XMMWORD },
	{ "xmm14", REG_XMM14, XED_REG_XMM14, SIZE_XMMWORD },
	{ "xmm15", REG_XMM15, XED_REG_XMM15, SIZE_XMMWORD },
#endif // _WIN64

	/* Advanced vector extensions V1 YMM# */
	{ "ymm0", REG_YMM0, XED_REG_YMM0, SIZE_YMMWORD },
	{ "ymm1", REG_YMM1, XED_REG_YMM1, SIZE_YMMWORD },
	{ "ymm2", REG_YMM2, XED_REG_YMM2, SIZE_YMMWORD },
	{ "ymm3", REG_YMM3, XED_REG_YMM3, SIZE_YMMWORD },
	{ "ymm4", REG_YMM4, XED_REG_YMM4, SIZE_YMMWORD },
	{ "ymm5", REG_YMM5, XED_REG_YMM5, SIZE_YMMWORD },
	{ "ymm6", REG_YMM6, XED_REG_YMM6, SIZE_YMMWORD },
	{ "ymm7", REG_YMM7, XED_REG_YMM7, SIZE_YMMWORD },
#ifdef _WIN64
	{ "ymm8", REG_YMM8, XED_REG_YMM8, SIZE_YMMWORD },
	{ "ymm9", REG_YMM9, XED_REG_YMM9, SIZE_YMMWORD },
	{ "ymm10", REG_YMM10, XED_REG_YMM10, SIZE_YMMWORD },
	{ "ymm11", REG_YMM11, XED_REG_YMM11, SIZE_YMMWORD },
	{ "ymm12", REG_YMM12, XED_REG_YMM12, SIZE_YMMWORD },
	{ "ymm13", REG_YMM13, XED_REG_YMM13, SIZE_YMMWORD },
	{ "ymm14", REG_YMM14, XED_REG_YMM14, SIZE_YMMWORD },
	{ "ymm15", REG_YMM15, XED_REG_YMM15, SIZE_YMMWORD },
#endif // _WIN64

	/* Advanced vector extensions V2 ZMM# */
	/* TODO */

	/* Segment registers */
	{ "sinval", REG_SINVALID, XED_REG_INVALID, SIZE_WORD },
	{ "cs", REG_CS, XED_REG_CS, SIZE_WORD },
	{ "ds", REG_DS, XED_REG_DS, SIZE_WORD },
	{ "es", REG_ES, XED_REG_ES, SIZE_WORD },
	{ "fs", REG_FS, XED_REG_FS, SIZE_WORD },
	{ "gs", REG_GS, XED_REG_GS, SIZE_WORD },
	{ "ss", REG_SS, XED_REG_SS, SIZE_WORD },
};

struct SegEntry
{
	const char		*Name;
	SEG				SegId;
	xed_reg_enum_t	XedId;
	REGSIZE			Size;
};

static SegEntry SegmentIds[] =
{
	/* Segment registers (same as RegisterIds) */
	{ "sinval", SEG_INVALID, XED_REG_INVALID, SIZE_WORD },
	{ "cs", SEG_CS, XED_REG_CS, SIZE_WORD },
	{ "ds", SEG_DS, XED_REG_DS, SIZE_WORD },
	{ "es", SEG_ES, XED_REG_ES, SIZE_WORD },
	{ "fs", SEG_FS, XED_REG_FS, SIZE_WORD },
	{ "gs", SEG_GS, XED_REG_GS, SIZE_WORD },
	{ "ss", SEG_SS, XED_REG_SS, SIZE_WORD },
};

bool IsControlRegister(REG reg);
bool IsDebugRegister(REG reg);
bool IsSegmentRegister(REG reg);
bool IsXmmRegister(REG reg);
bool IsYmmRegister(REG reg);

REG getregister(const char* text);
SEG getsegment(const char* text);

xed_reg_enum_t regtoxed(REG reg);
xed_reg_enum_t segtoxed(SEG seg);

const char *regtostring(REG reg);
const char *segtostring(SEG seg);

REGSIZE getregsize(REG reg);
REGSIZE getsegsize(SEG seg);