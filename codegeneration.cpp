#include "codegeneration.hpp"

template<typename T>
void genasm(T s) { std::cout << s << std::endl; }

template<typename T = std::string, typename... Arguments>
void genasm(T first, Arguments... rest) {
	genasm(first);
	genasm(rest...);
}

#define GEN_ASM genasm(
#define END_ASM );

const int EBP_CLASS_POINTER_OFFSET = 8;
const int OFFSET_SIZE = 4;


// CodeGenerator Visitor Functions: These are the functions
// you will complete to generate the x86 assembly code. Not
// all functions must have code, many may be left empty.

void CodeGenerator::visitProgramNode(ProgramNode* node) {
	// WRITEME: Replace with code if necessary

	std::string mainLabel("Main_main");
#if __APPLE__
	mainLabel = "_" + mainLabel;
#endif
	GEN_ASM
	".data",
	"printstr: .asciz \"%d\\n\"",
	".text",
	".globl " + mainLabel
	END_ASM

	node->visit_children(this);
}

void CodeGenerator::visitClassNode(ClassNode* node) {
	currentClassName = node->identifier_1->name;
	currentClassInfo = classTable->at(currentClassName);
	node->visit_children(this);
}

void CodeGenerator::visitMethodNode(MethodNode* node) {
	currentMethodName = node->identifier->name;
	currentMethodInfo = classTable->at(currentClassName).methods->at(currentMethodName);


	std::string methodLabel(currentClassName + "_" + currentMethodName);
#if __APPLE__
	methodLabel = "_" + methodLabel;
#endif

	GEN_ASM
	methodLabel + ":"
	END_ASM

	// Skip parameters and go straight to method body
	node->methodbody->accept(this);


}

void CodeGenerator::visitMethodBodyNode(MethodBodyNode* node) {
	GEN_ASM
	"# METHOD STARTUP",
	"push %ebp",
	"mov %esp, %ebp",
	"sub $" + std::to_string(currentMethodInfo.localsSize) + ", %esp",
	"push %edi",
	"push %esi",
	"push %ebx",
	"# METHOD STARTUP DONE\n"
	END_ASM


	node->visit_children(this);


	if (currentMethodName == currentClassName) {
		GEN_ASM
		"mov 8(%ebp), %eax"
		END_ASM
	}

	GEN_ASM
	"# METHOD CLEANUP",
	"pop %ebx",
	"pop %esi",
	"pop %edi",
	"mov %ebp, %esp", // Deallocate
	"pop %ebp",
	"ret",   // Return
	"# METHOD CLEANUP DONE\n"
	END_ASM
}

void CodeGenerator::visitParameterNode(ParameterNode* node) {
	node->visit_children(this);
}

void CodeGenerator::visitDeclarationNode(DeclarationNode* node) {
	node->visit_children(this);
}

void CodeGenerator::visitReturnStatementNode(ReturnStatementNode* node) {
	node->visit_children(this);
	GEN_ASM
	"pop %eax"
	END_ASM
}

void CodeGenerator::visitAssignmentNode(AssignmentNode* node) {
	node->visit_children(this);

	GEN_ASM
	"#### VISIT ASSIGNMENT NODE",
	"pop %eax"
	END_ASM

	if (node->identifier_2 == NULL) {
		int offset;
		if (currentMethodInfo.variables->count(node->identifier_1->name) > 0) {
			offset = currentMethodInfo.variables->at(node->identifier_1->name).offset;

			GEN_ASM
			"# " + node->identifier_1->name + " #",
			"# localOffset = " + std::to_string(offset),
			"mov %eax, " + std::to_string(offset) + "(%ebp)"
			END_ASM
		} else {
			offset = currentClassInfo.members->at(node->identifier_1->name).offset;

			int memberOffset = currentClassInfo.members->at(node->identifier_1->name).offset;

			GEN_ASM
			"# memberOffset = " + std::to_string(memberOffset),
			"mov 8(%ebp), %ebx",
			"mov %eax, " + std::to_string(memberOffset) + "(%ebx)"
			END_ASM
		}


	} else {
		int memberOffset = classTable->at(node->identifier_1->objectClassName).members->at(node->identifier_2->name).offset;

		int localOffset = 0;
		if (currentMethodInfo.variables->count(node->identifier_1->name) > 0) {
			localOffset = currentMethodInfo.variables->at(node->identifier_1->name).offset;

			GEN_ASM
			"mov " + std::to_string(localOffset) + "(%ebp), %ebx",
			"mov %eax, " + std::to_string(memberOffset) + "(%ebx)"
			END_ASM

		} else {
			localOffset = currentClassInfo.members->at(node->identifier_1->name).offset;

			GEN_ASM
			"mov 8(%ebp), %ebx",
			"mov " + std::to_string(localOffset) + "(%ebx), %eax",
			"mov %eax, " + std::to_string(memberOffset) + "(%ebx)"
			END_ASM
		}


	}

	GEN_ASM
	"#### VISIT ASSIGNMENT NODE DONE \n"
	END_ASM
}

void CodeGenerator::visitCallNode(CallNode* node) {
	node->visit_children(this);
}

void CodeGenerator::visitIfElseNode(IfElseNode* node) {
	node->expression->accept(this);

	// Generate comparison
	std::string labelNum = std::to_string(nextLabel());
	GEN_ASM
	"pop %eax",
	"cmp $1, %eax",
	"jne else_label" + labelNum
	END_ASM

	// Iterate over if (true) statements
	if (node->statement_list_1) {
		for (auto iter = node->statement_list_1->begin(); iter != node->statement_list_1->end(); iter++) {
			(*iter)->accept(this);
		}
	}

	// Create else label
	GEN_ASM
	"jmp end_label" + labelNum,
	"else_label" + labelNum + ":"
	END_ASM

	// Iterate over else (false) statements
	if (node->statement_list_2) {
		for (auto iter = node->statement_list_2->begin(); iter != node->statement_list_2->end(); iter++) {
			(*iter)->accept(this);
		}
	}

	// Create end label
	GEN_ASM
	"end_label" + labelNum + ":"
	END_ASM
}

void CodeGenerator::visitWhileNode(WhileNode* node) {
	std::string labelNum = std::to_string(nextLabel());

	GEN_ASM
	"top_while_label" + labelNum + ":"
	END_ASM

	node->expression->accept(this);

	GEN_ASM
	"pop %eax",
	"cmp $1, %eax",
	"jne end_while_label" + labelNum
	END_ASM

	// Iterate over while statements
	if (node->statement_list) {
		for (auto iter = node->statement_list->begin(); iter != node->statement_list->end(); iter++) {
			(*iter)->accept(this);
		}
	}

	// Create end label
	GEN_ASM
	"jmp top_while_label" + labelNum,
	"end_while_label" + labelNum + ":"
	END_ASM
}

void CodeGenerator::visitRepeatNode(RepeatNode* node) {
	std::string labelNum = std::to_string(nextLabel());

	GEN_ASM
	"top_repeat_label" + labelNum + ":"
	END_ASM

	// Iterate over while statements
	if (node->statement_list) {
		for (auto iter = node->statement_list->begin(); iter != node->statement_list->end(); iter++) {
			(*iter)->accept(this);
		}
	}

	node->expression->accept(this);

	GEN_ASM
	"pop %eax",
	"cmp $1, %eax",
	"jne end_repeat_label" + labelNum
	END_ASM

	// Create end label
	GEN_ASM
	"jmp top_repeat_label" + labelNum,
	"end_repeat_label" + labelNum + ":"
	END_ASM
}

void CodeGenerator::visitPrintNode(PrintNode* node) {

	// MAC ONLY CODE
	std::string printfCall("printf");
#if __APPLE__
	printfCall = "_" + printfCall;

	GEN_ASM
	"#BEFORE PRINT (MAC)",
	"mov %esp, %eax",
	"and $0xFFFFFFF0, %esp",
	"sub $4, %esp",
	"push %eax",
	"#BEFORE PRINT DONE (MAC)"
	END_ASM
#endif

	// Generate expression value
	node->visit_children(this);

	GEN_ASM
	// "push $1", // Example print value
	"push $printstr",
	"call " + printfCall,
	"add $8, %esp"
	END_ASM

// MAC ONLY CODE
#if __APPLE__
	GEN_ASM
	"#AFTER PRINT (MAC)",
	"add $8, %esp",
	"pop %esp",
	"#AFTER PRINT DONE (MAC)\n"
	END_ASM
#endif
}

void CodeGenerator::visitPlusNode(PlusNode* node) {
	node->visit_children(this);

	GEN_ASM
	"pop %eax",
	"pop %ebx",
	"add %ebx, %eax",
	"push %eax"
	END_ASM
}

void CodeGenerator::visitMinusNode(MinusNode* node) {
	node->visit_children(this);

	GEN_ASM
	"pop %ebx",
	"pop %eax",
	"sub %ebx, %eax",
	"push %eax"
	END_ASM
}

void CodeGenerator::visitTimesNode(TimesNode* node) {
	node->visit_children(this);

	GEN_ASM
	"pop %eax",
	"pop %ebx",
	"imul %ebx, %eax",
	"push %eax"
	END_ASM
}

void CodeGenerator::visitDivideNode(DivideNode* node) {
	node->visit_children(this);

	GEN_ASM
	"pop %ecx",
	"pop %eax",
	"cdq",
	"idiv %ecx",
	"push %eax"
	END_ASM
}

void CodeGenerator::visitLessNode(LessNode* node) {
	node->visit_children(this);

	GEN_ASM
	"pop %eax",
	"pop %ebx",
	"cmp %eax, %ebx",
	"setl %dl",
	"movzbl %dl, %eax",
	"push %eax"
	END_ASM

}

void CodeGenerator::visitLessEqualNode(LessEqualNode* node) {
	node->visit_children(this);

	GEN_ASM
	"pop %eax",
	"pop %ebx",
	"cmp %eax, %ebx",
	"setle %dl",
	"movzbl %dl, %eax",
	"push %eax"
	END_ASM
}

void CodeGenerator::visitEqualNode(EqualNode* node) {
	node->visit_children(this);

	GEN_ASM
	"pop %eax",
	"pop %ebx",
	"cmp %eax, %ebx",
	"sete %dl",
	"movzbl %dl, %eax",
	"push %eax"
	END_ASM
}

void CodeGenerator::visitAndNode(AndNode* node) {
	node->visit_children(this);

	GEN_ASM
	"pop %eax",
	"pop %ebx",
	"and %ebx, %eax",
	"push %eax"
	END_ASM
}

void CodeGenerator::visitOrNode(OrNode* node) {
	node->visit_children(this);

	GEN_ASM
	"pop %eax",
	"pop %ebx",
	"or %ebx, %eax",
	"push %eax"
	END_ASM
}

void CodeGenerator::visitNotNode(NotNode* node) {
	node->visit_children(this);

	GEN_ASM
	"pop %eax",
	"mov $1, %ebx",
	"xor %ebx, %eax",
	"push %eax"
	END_ASM
}

void CodeGenerator::visitNegationNode(NegationNode* node) {
	node->visit_children(this);

	GEN_ASM
	"pop %eax",
	"neg %eax",
	"push %eax"
	END_ASM
}

void CodeGenerator::visitMethodCallNode(MethodCallNode* node) {

	// Save-caller stuff
	GEN_ASM
	"#### METHOD CALL START"
	END_ASM

	// Push variables to stack
	int argumentCount = 0;
	if (node->expression_list != NULL ) {
		for (auto iter = node->expression_list->rbegin(); iter != node-> expression_list -> rend(); iter++) {
			(*iter) -> accept(this);
			argumentCount++;
		}
	}

	std::string methodName(node->identifier_1->name);
	std::string className(currentClassName);




	if (node->identifier_2 == NULL) {
		while (classTable->at(className).methods->count(methodName) == 0) {
			className = classTable->at(className).superClassName;
		}

		GEN_ASM
		"push 8(%ebp)"
		END_ASM
	} else {
		className = node->identifier_1->objectClassName;
		methodName = node->identifier_2->name;

		if (currentMethodInfo.variables->count(node->identifier_1->name) > 0) {
			GEN_ASM
			"push " + std::to_string(currentMethodInfo.variables->at(node->identifier_1->name).offset) + "(%ebp)"
			END_ASM
		} else {
			GEN_ASM
			"mov 8(%ebp), %ebx",
			"push " + std::to_string(currentClassInfo.members->at(node->identifier_1->name).offset) + "(%ebx)"
			END_ASM
		}

		while (classTable->at(className).methods->count(methodName) == 0) {
			className = classTable->at(className).superClassName;
		}
	}

	GEN_ASM
	"call " + className + "_" + methodName,
	"add $" + std::to_string(argumentCount * OFFSET_SIZE + OFFSET_SIZE) + ", %esp",
	"push %eax",
	"#### METHOD CALL END\n"
	END_ASM
}

void CodeGenerator::visitMemberAccessNode(MemberAccessNode* node) {
	node->visit_children(this);

	GEN_ASM
	"#### VISIT MEMBER ACCESS"
	END_ASM

	int localOffset;
	int memberOffset = classTable->at(node->identifier_1->objectClassName).members->at(node->identifier_2->name).offset;

	if (currentMethodInfo.variables->count(node->identifier_1->name) > 0) {
		localOffset = currentMethodInfo.variables->at(node->identifier_1->name).offset;

		GEN_ASM
		"# localOffset = " + std::to_string(localOffset),
		"# memebrOffset = " + std::to_string(memberOffset),
		"mov " + std::to_string(localOffset) + "(%ebp), %ebx",
		"mov " + std::to_string(memberOffset) + "(%ebx), %eax",
		"push %eax"
		END_ASM
	} else {
		localOffset = currentClassInfo.members->at(node->identifier_1->name).offset;
		GEN_ASM
		"# localOffset = " + std::to_string(localOffset),
		"# memebrOffset = " + std::to_string(memberOffset),
		"mov 8(%ebp), %ebx",

		"mov " + std::to_string(localOffset) + "(%ebx), %ecx",
		"mov " + std::to_string(memberOffset) + "(%ecx), %eax",
		"push %eax"
		END_ASM


	}



	GEN_ASM
	"#### VISIT MEMBER ACCESS DONE\n"
	END_ASM
}

void CodeGenerator::visitVariableNode(VariableNode* node) {
	node->visit_children(this);
	GEN_ASM
	"# VISIT VARIABLE"
	END_ASM

	if (currentMethodInfo.variables->count(node->identifier->name) > 0) {
		int offset = currentMethodInfo.variables->at(node->identifier->name).offset;

		GEN_ASM
		"#  VARIABLE LOCAL",
		"push " + std::to_string(offset) + "(%ebp)"
		END_ASM


	} else if (currentClassInfo.members->count(node->identifier->name) > 0) {
		int offset = currentClassInfo.members->at(node->identifier->name).offset;

		GEN_ASM
		"#  VARIABLE MEMBER",
		"mov 8(%ebp), %ebx",
		"mov " + std::to_string(offset) + "(%ebx), %eax",
		"push %eax"
		END_ASM
	}
	GEN_ASM
	"# VISIT VARIABLE DONE\n"
	END_ASM
}

void CodeGenerator::visitIntegerLiteralNode(IntegerLiteralNode* node) {
	node->visit_children(this);
	GEN_ASM
	"push $" + std::to_string(node->integer->value)
	END_ASM
}

void CodeGenerator::visitBooleanLiteralNode(BooleanLiteralNode* node) {
	node->visit_children(this);
	GEN_ASM
	"push $" + std::to_string(node->integer->value)
	END_ASM
}

void CodeGenerator::visitNewNode(NewNode* node) {
	node->visit_children(this);

	std::string mallocCall("malloc");
#if __APPLE__
	mallocCall = "_" + mallocCall;

	GEN_ASM
	"#### BEFORE NEW (MAC)",
	"mov %esp, %eax",
	"and $0xFFFFFFF0, %esp",
	"sub $4, %esp",
	"push %eax",
	"#### BEFORE NEW DONE (MAC)"
	END_ASM
#endif

	int classSize = classTable->at(node->identifier->name).membersSize;


	GEN_ASM
	"# name = " + node->identifier->name,
	"# classSize = " + std::to_string(classSize)
	END_ASM

	// CHECK IF CONSTURCTOR EXISTS
	if (classTable->at(node->identifier->name).methods->count(node->identifier->name) > 0) {
		GEN_ASM
		"#### CONSTRUCTOR CALL START"
		END_ASM


		// Push variables to stack
		int argumentCount = 0;
		if (node->expression_list != NULL ) {
			for (auto iter = node->expression_list->rbegin(); iter != node-> expression_list -> rend(); iter++) {
				(*iter) -> accept(this);
				argumentCount++;
			}
		}

		GEN_ASM
		"push $" + std::to_string(classSize),
		"call " + mallocCall,
		"add $4, %esp",
		"push %eax",
		"call " + node->identifier->name + "_" + node->identifier->name,
		"add $" + std::to_string(argumentCount * OFFSET_SIZE + OFFSET_SIZE) + ", %esp",
		"push %eax",
		"#### CONSTRUCTOR CALL END\n"
		END_ASM
	} else {
		GEN_ASM
		"push $" + std::to_string(classSize),
		"call " + mallocCall,
		"add $4, %esp",
		"push %eax"
		END_ASM
	}

	// MAC ONLY CODE
#if __APPLE__
	GEN_ASM
	"#### AFTER NEW (MAC)",
	"add $4, %esp",
	"pop %esp",
	"#### AFTER NEW DONE (MAC)\n"
	END_ASM
#endif

}

void CodeGenerator::visitIntegerTypeNode(IntegerTypeNode * node) {
	node->visit_children(this);
}

void CodeGenerator::visitBooleanTypeNode(BooleanTypeNode * node) {
	node->visit_children(this);
}

void CodeGenerator::visitObjectTypeNode(ObjectTypeNode * node) {
	node->visit_children(this);
}

void CodeGenerator::visitNoneNode(NoneNode * node) {
	node->visit_children(this);
}

void CodeGenerator::visitIdentifierNode(IdentifierNode * node) {
	node->visit_children(this);
}

void CodeGenerator::visitIntegerNode(IntegerNode * node) {
	node->visit_children(this);
}
