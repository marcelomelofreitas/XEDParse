#include "Translator.h"

bool IsIClassJump(xed_iclass_enum_t IClass)
{
	return (IClass >= XED_ICLASS_JB && IClass <= XED_ICLASS_JZ);
}

bool IsIClassCall(xed_iclass_enum_t IClass)
{
	return (IClass == XED_ICLASS_CALL_FAR || IClass == XED_ICLASS_CALL_NEAR);
}

int BranchClassBytes(xed_iclass_enum_t IClass, bool Imm8)
{
	switch (IClass)
	{
	case XED_ICLASS_JB:
	case XED_ICLASS_JBE:
	case XED_ICLASS_JL:
	case XED_ICLASS_JLE:
	case XED_ICLASS_JNB:
	case XED_ICLASS_JNBE:
	case XED_ICLASS_JNL:
	case XED_ICLASS_JNLE:
	case XED_ICLASS_JNO:
	case XED_ICLASS_JNP:
	case XED_ICLASS_JNS:
	case XED_ICLASS_JNZ:
	case XED_ICLASS_JO:
	case XED_ICLASS_JP:
	case XED_ICLASS_JS:
	case XED_ICLASS_JZ:
		return (Imm8) ? 2 : 6;

	case XED_ICLASS_JRCXZ:
		return 2;

	//case XED_ICLASS_JMP_FAR:
	//case XED_ICLASS_CALL_FAR:
	//	return 0;// ?

	case XED_ICLASS_JMP:
		return (Imm8) ? 2 : 5;

	case XED_ICLASS_CALL_NEAR:
		return 5;
	}
    return 0;
}

bool TranslateBranchInst(XEDPARSE *Parse, Inst *Instruction)
{
	// Check if it needs to be fixed
	if (!IsIClassJump(Instruction->Class) && !IsIClassCall(Instruction->Class))
		return true;

	// Any branch instruction can only have one operand max
	if (Instruction->OperandCount > 1)
	{
		strcpy(Parse->error, "Too many operands in branch");
		return false;
	}

	// This is only handled if the operand is an immediate
	InstOperand *operand = &Instruction->Operands[0];

	if (operand->Type == OPERAND_IMM)
	{
		LONGLONG delta = TranslateRelativeCip(Parse, operand->Imm.imm, operand->Imm.Signed);

		// XED doesn't automatically do this for some reason
		//
		// Modify the delta so that it accommodates for the instruction size
		// CALL doesn't apply here
		//
		// IF DELTA <= 127 [SHORT JUMP]
		delta -= BranchClassBytes(Instruction->Class, (abs(delta) <= 127));

		// Branches can't have a larger displacement than 32bits
		if (delta > LONG_MAX || delta < LONG_MIN)
		{
            strcpy(Parse->error, "Branch displacement is too large");
			return false;
		}

		operand->Size			= inttoopsize(xed_shortest_width_signed(delta, 0xFF));
		operand->Imm.Signed		= true;
		operand->Imm.RelBranch	= true;
		operand->Imm.simm		= delta;
	}

	return true;
}