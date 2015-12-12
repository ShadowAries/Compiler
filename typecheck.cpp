/**
CS160- Project 5
typecheck.cpp
Purpose: To construct a symbol table and perform type checking on input programs using the AST

@author Armin Akhbari
@version 1.0 11/18/15
*/
#include "typecheck.hpp"

template < class a_type, class b_type>
void set_type_expression(a_type *x, b_type *y) {

	x->basetype = y->basetype;
	x->objectClassName = y->objectClassName;
}
template <class a_type>
bool check_integer_type(a_type* node) {

	return (node->basetype == bt_integer) && !(node->objectClassName.compare("Integer"));
}
template <class a_type>
bool check_boolean_type(a_type* node) {
	return (node->basetype == bt_boolean) && !(node->objectClassName.compare("Boolean"));

}


bool is_class(ClassTable *table, std::string &name) {

	return table->count(name) > 0;
}
template <class a_type>
void  check_valid_integer_operator(a_type *node) {
	if (check_integer_type(node->expression_1))
		check_same_type_express(node->expression_1->basetype, node->expression_1->objectClassName, node->expression_2->basetype, node->expression_2->objectClassName, expression_type_mismatch);
	else {
		typeError(expression_type_mismatch);
	}
}

bool check_equal_type(BaseType& a, std::string obj_class_name, BaseType& b, std::string& obj2_class_name) {
	if (a != b)
		return false;
	else {
		if (obj_class_name.compare(obj2_class_name) != 0)
			return false;
	}
	return true;
}

bool check_arguement_methode(std::string methodName, MethodTable *mtable, std::list<ExpressionNode*>* ex_list) {

	int number_of_expre_in_list = (ex_list == NULL) ? 0 : ex_list->size();
	int number_of_params = !(mtable->count(methodName)) ? 0 : mtable->at(methodName).parameters->size();
	if (number_of_params != number_of_expre_in_list)
		typeError(argument_number_mismatch);

	std::list<ExpressionNode*>::iterator it2;
	std::list<CompoundType>::iterator it;
	if (number_of_expre_in_list)
		for (it = mtable->at(methodName).parameters->begin(), it2 = ex_list->begin(); it != (mtable->at(methodName).parameters)->end(); ++it, it2++)
			if (!check_equal_type(it->baseType, it->objectClassName, (*it2)->basetype, (*it2)->objectClassName))
				typeError(argument_type_mismatch);

	return true;
}

bool find_my_method_in_class_methods(MethodCallNode *node, std::string current_class_name, ClassTable &classTable) {
	std::string looking_method(node->identifier_1->name);
	if (node->identifier_2 != NULL) {
		looking_method = node->identifier_2->name;
		if (!is_class(&classTable, node->identifier_1->objectClassName))
			typeError(not_object);
	}


	do {
		if (classTable.at(current_class_name).methods->count(looking_method) > 0) {
			check_arguement_methode(looking_method, classTable.at(current_class_name).methods, node->expression_list);
			node->basetype = classTable.at(current_class_name).methods->at(looking_method).returnType.baseType;
			node->objectClassName = classTable.at(current_class_name).methods->at(looking_method).returnType.objectClassName;
			return true;
		}
		else {
			current_class_name = classTable.at(current_class_name).superClassName;
		}

	} while (!current_class_name.empty());

	return false;

}
bool find_my_attribute_in_class_members(IdentifierNode *node, std::string current_class_name, ClassTable &classTable) {

	do {
		if (classTable.at(current_class_name).members->count(node->name) > 0) {
			node->basetype = classTable.at(current_class_name).members->at(node->name).type.baseType;
			node->objectClassName = classTable.at(current_class_name).members->at(node->name).type.objectClassName;
			return true;
		}
		else {
			current_class_name = classTable.at(current_class_name).superClassName;
		}

	} while (!current_class_name.empty());

	return false;
}
bool find_my_variable_locally(IdentifierNode *node, VariableTable *vTable) {
	if (vTable->count(node->name) > 0) {
		node->basetype = vTable->at(node->name).type.baseType;
		node->objectClassName = vTable->at(node->name).type.objectClassName;
		return true;
	}
	return false;
}

void check_no_member_main(ClassNode *node) {


	if (!node->identifier_1->name.compare("Main") && node->declaration_list != NULL)
		typeError(main_class_members_present);

}
void main_method_exist_check(ClassNode *node, MethodTable *table) {

	if (!node->identifier_1->name.compare("Main"))
	{
		std::map<std::string, MethodInfo>::iterator it;
		it = table->find("main");
		if (it == table->end())
			typeError(no_main_method);
		else {
			if (it->second.parameters->size() > 0)
				typeError(main_method_incorrect_signature);
		}


	}


}
void check_main_class_exists(ClassTable *table) {

	std::map<std::string, ClassInfo>::iterator it;
	it = table->find("Main");
	if (it == table->end())
		typeError(no_main_class);

}
void check_same_type_express(BaseType& ex1, std::string ex1_objectClassName, BaseType& ex2, std::string ex2_objectClassName, TypeErrorCode errorCode) {
	if (ex1 != ex2) {
		typeError(errorCode);
	}
	else {
		if (ex1_objectClassName.compare(ex2_objectClassName) != 0) {
			typeError(errorCode);
		}
	}
}
bool check_variable_is_member_of_a_class(IdentifierNode *object, IdentifierNode *memberNode, ClassTable &classTable) {
	if (!is_class(&classTable, object->objectClassName))
		typeError(not_object);
	if (classTable.at(object->objectClassName).members->count(memberNode->name) > 0) {
		memberNode->basetype = classTable.at(object->objectClassName).members->at(memberNode->name).type.baseType;
		memberNode->objectClassName = classTable.at(object->objectClassName).members->at(memberNode->name).type.objectClassName;
		return true;
	}
	if (!find_my_attribute_in_class_members(memberNode, object->objectClassName, classTable)) {
		typeError(undefined_member);
	}
	return true;
}
bool check_variable_is_method_of_a_class(IdentifierNode *object, IdentifierNode *memberNode, ClassTable &classTable) {

	if (classTable.at(object->objectClassName).methods->count(memberNode->name) == 0) {
		typeError(undefined_method);
		return false;
	}
	else {
		memberNode->basetype = classTable.at(object->objectClassName).methods->at(memberNode->name).returnType.baseType;
		memberNode->objectClassName = classTable.at(object->objectClassName).methods->at(memberNode->name).returnType.objectClassName;
		return true;



	}
}
std::string default_base_type(BaseType base_type, std::string class_name) {

	switch (base_type) {

	case bt_integer:
		return "Integer";
	case bt_boolean:
		return "Boolean";
	case bt_none:
		return "None";
	case bt_object:
		return class_name;
	default:
		return NULL;

	}
}
CompoundType make_compound_type(BaseType base_Type, std::string object_Class_Name) {
	CompoundType output;
	output.baseType = base_Type;
	output.objectClassName = default_base_type(base_Type, object_Class_Name);
	return output;
}
// Defines the function used to throw type errors. The possible
// type errors are defined as an enumeration in the header file.
void typeError(TypeErrorCode code) {
	switch (code) {
	case undefined_variable:
		std::cerr << "Undefined variable." << std::endl;
		break;
	case undefined_method:
		std::cerr << "Method does not exist." << std::endl;
		break;
	case undefined_class:
		std::cerr << "Class does not exist." << std::endl;
		break;
	case undefined_member:
		std::cerr << "Class member does not exist." << std::endl;
		break;
	case not_object:
		std::cerr << "Variable is not an object." << std::endl;
		break;
	case expression_type_mismatch:
		std::cerr << "Expression types do not match." << std::endl;
		break;
	case argument_number_mismatch:
		std::cerr << "Method called with incorrect number of arguments." << std::endl;
		break;
	case argument_type_mismatch:
		std::cerr << "Method called with argument of incorrect type." << std::endl;
		break;
	case while_predicate_type_mismatch:
		std::cerr << "Predicate of while loop is not boolean." << std::endl;
		break;
	case repeat_predicate_type_mismatch:
		std::cerr << "Predicate of repeat loop is not boolean." << std::endl;
		break;
	case if_predicate_type_mismatch:
		std::cerr << "Predicate of if statement is not boolean." << std::endl;
		break;
	case assignment_type_mismatch:
		std::cerr << "Left and right hand sides of assignment types mismatch." << std::endl;
		break;
	case return_type_mismatch:
		std::cerr << "Return statement type does not match declared return type." << std::endl;
		break;
	case constructor_returns_type:
		std::cerr << "Class constructor returns a value." << std::endl;
		break;
	case no_main_class:
		std::cerr << "The \"Main\" class was not found." << std::endl;
		break;
	case main_class_members_present:
		std::cerr << "The \"Main\" class has members." << std::endl;
		break;
	case no_main_method:
		std::cerr << "The \"Main\" class does not have a \"main\" method." << std::endl;
		break;
	case main_method_incorrect_signature:
		std::cerr << "The \"main\" method of the \"Main\" class has an incorrect signature." << std::endl;
		break;
	}
	exit(1);
}

// TypeCheck Visitor Functions: These are the functions you will
// complete to build the symbol table and type check the program.
// Not all functions must have code, many may be left empty.

void TypeCheck::visitProgramNode(ProgramNode* node) {
	// WRITEME: Replace with code if necessary
	classTable = new ClassTable();

	node->visit_children(this);

	//look for main now
	check_main_class_exists(classTable);
}

void TypeCheck::visitClassNode(ClassNode* node) {
	currentVariableTable = NULL;
	currentMethodTable = NULL;
	currentMemberOffset = -4;


	currentClassName = node->identifier_1->name;
	(*classTable)[currentClassName] = *(new ClassInfo);

	//update the size of this class :)
	classTable->at(currentClassName).methods = new MethodTable();
	classTable->at(currentClassName).members = new VariableTable();

	// X extends Y. verifying if Y exists
	if (node->identifier_2 != NULL) {
		if (is_class(classTable, node->identifier_2->name)) {
			classTable->at(currentClassName).superClassName = node->identifier_2->name;

			for (auto iter = classTable->at(node->identifier_2->name).members->begin(); iter != classTable->at(node->identifier_2->name).members->end(); iter++) {
				(*classTable->at(currentClassName).members)[(*iter).first] = { (*iter).second.type, currentMemberOffset += 4, 4 };
			}

		} else {
			typeError(undefined_class);
		}
	}




	// If the class is "Main", it shouldn't have members
	check_no_member_main(node);


	node->visit_children(this);
	// if the class is "Main", it should have a constructor
	main_method_exist_check(node, currentMethodTable);

	classTable->at(currentClassName).membersSize = classTable->at(currentClassName).members->size() * 4;

}

void TypeCheck::visitMethodNode(MethodNode* node) {
	//////----OFFSET SETTING
	currentLocalOffset = 0;
	currentParameterOffset = 8;
	currentMethodTable = classTable->at(currentClassName).methods;
	currentVariableTable = NULL;
	(*currentMethodTable)[node->identifier->name] = *(new methodinfo);
	(*currentMethodTable)[node->identifier->name].parameters = new std::list<CompoundType>();
	currentVariableTable = new VariableTable();
	(*currentMethodTable)[node->identifier->name].returnType = make_compound_type(node->type->basetype, node->type->objectClassName);
	(*currentMethodTable)[node->identifier->name].variables = currentVariableTable;


	set_type_expression(node->methodbody, node->type);
	node->visit_children(this);


	//populating Parameter's list if the method has parameters
	if (node->parameter_list != NULL)
		for (std::list<ParameterNode*>::iterator iter = node->parameter_list->begin();
		        iter != node->parameter_list->end(); iter++) {
			(*currentMethodTable)[node->identifier->name].parameters->push_back(make_compound_type((*iter)->type->basetype, (*iter)->type->objectClassName));
		}


	//constructor should return none.
	std::string lowered_currentClassName(currentClassName);
	lowered_currentClassName[0] = tolower(lowered_currentClassName[0]);
	if (!node->identifier->name.compare(lowered_currentClassName)) {
		if (node->type->basetype != bt_none) {
			if (lowered_currentClassName.compare("main") == 0) {
				typeError(main_method_incorrect_signature);
			} else {
				typeError(constructor_returns_type);
			}
		}
	}

	(*currentMethodTable)[node->identifier->name].localsSize = 4 * (*currentMethodTable)[node->identifier->name].variables->size() - 4 * (*currentMethodTable)[node->identifier->name].parameters->size();
}

void TypeCheck::visitMethodBodyNode(MethodBodyNode* node) {

	node->visit_children(this);

	if (node->returnstatement != NULL)
		check_same_type_express(node->basetype, node->objectClassName, node->returnstatement->basetype, node->returnstatement->objectClassName, return_type_mismatch);
	else {
		if (node->basetype != bt_none)
			typeError(return_type_mismatch);
	}
}

void TypeCheck::visitParameterNode(ParameterNode* node) {
	if (is_class(classTable, node->type->objectClassName) || check_integer_type(node->type) || check_boolean_type(node->type))
		(*currentVariableTable)[node->identifier->name] = { make_compound_type(node->basetype, node->objectClassName), currentParameterOffset += 4, 4 };
	else
		typeError(undefined_class);
}

void TypeCheck::visitDeclarationNode(DeclarationNode* node) {

	// Memeber type node, identifier node

	if (currentVariableTable != NULL) {
		//local Variables
		if (is_class(classTable, node->type->objectClassName) || check_integer_type(node->type) || check_boolean_type(node->type))
			for (std::list<IdentifierNode*>::iterator itn = node->identifier_list->begin(); itn != node->identifier_list->end(); itn++) {
				(*currentVariableTable)[(*itn)->name] = { make_compound_type(node->type->basetype, node->type->objectClassName), currentLocalOffset -= 4, 4 };
			}
		else
			typeError(undefined_class);
	}
	else //membervariables declaration
		if (is_class(classTable, node->type->objectClassName) || check_integer_type(node->type) || check_boolean_type(node->type)) {
			for (std::list<IdentifierNode*>::iterator itn = node->identifier_list->begin(); itn != node->identifier_list->end(); itn++) {
				(*classTable->at(currentClassName).members)[(*itn)->name] = { make_compound_type(node->basetype, node->objectClassName), currentMemberOffset += 4, 4 };
			}
		} else {
			typeError(undefined_class);
		}


}

void TypeCheck::visitReturnStatementNode(ReturnStatementNode* node) {
	node->visit_children(this);
	set_type_expression(node, node->expression);
}

void TypeCheck::visitAssignmentNode(AssignmentNode* node) {
	node->visit_children(this);
	if (node->identifier_2 != NULL) {

		if (find_my_variable_locally(node->identifier_1, currentVariableTable) ||
		        find_my_attribute_in_class_members(node->identifier_1, currentClassName, *classTable)) {

			check_variable_is_member_of_a_class(node->identifier_1, node->identifier_2, *classTable);
			check_same_type_express(node->identifier_2->basetype, node->identifier_2->objectClassName, node->expression->basetype, node->expression->objectClassName, assignment_type_mismatch);
		}
		else
			typeError(undefined_variable);

	}

	else {
		if (find_my_variable_locally(node->identifier_1, currentVariableTable) ||
		        find_my_attribute_in_class_members(node->identifier_1, currentClassName, *classTable))
			check_same_type_express(node->identifier_1->basetype, node->identifier_1->objectClassName, node->expression->basetype, node->expression->objectClassName, assignment_type_mismatch);

		else
			typeError(undefined_variable);
	}
}

void TypeCheck::visitCallNode(CallNode* node) {
	node->visit_children(this);

}

void TypeCheck::visitIfElseNode(IfElseNode* node) {
	node->visit_children(this);
	if (node->expression->basetype != bt_boolean)
		typeError(if_predicate_type_mismatch);
}

void TypeCheck::visitWhileNode(WhileNode* node) {
	node->visit_children(this);
	if (node->expression->basetype != bt_boolean)
		typeError(while_predicate_type_mismatch);
}

void TypeCheck::visitRepeatNode(RepeatNode* node) {
	node->visit_children(this);
	if (node->expression->basetype != bt_boolean)
		typeError(repeat_predicate_type_mismatch);
}

void TypeCheck::visitPrintNode(PrintNode* node) {
	node->visit_children(this);
	// WRITEME: Replace with code if necessary
}

void TypeCheck::visitPlusNode(PlusNode* node) {
	node->visit_children(this);
	check_valid_integer_operator(node);
	set_type_expression(node, node->expression_1);

}

void TypeCheck::visitMinusNode(MinusNode* node) {
	node->visit_children(this);
	check_valid_integer_operator(node);
	set_type_expression(node, node->expression_1);

}

void TypeCheck::visitTimesNode(TimesNode* node) {
	node->visit_children(this);
	check_valid_integer_operator(node);
	set_type_expression(node, node->expression_1);

}

void TypeCheck::visitDivideNode(DivideNode* node) {
	node->visit_children(this);
	check_valid_integer_operator(node);
	set_type_expression(node, node->expression_1);


}

void TypeCheck::visitLessNode(LessNode* node) {
	node->visit_children(this);
	check_valid_integer_operator(node);
	node->basetype = bt_boolean;
	node->objectClassName = "Boolean";
}

void TypeCheck::visitLessEqualNode(LessEqualNode* node) {
	node->visit_children(this);
	check_valid_integer_operator(node);
	node->basetype = bt_boolean;
	node->objectClassName = "Boolean";
}

void TypeCheck::visitEqualNode(EqualNode* node) {
	node->visit_children(this);
	if (check_boolean_type(node->expression_1) || check_integer_type(node->expression_1))
		check_same_type_express(node->expression_1->basetype, node->expression_1->objectClassName, node->expression_2->basetype, node->expression_2->objectClassName, expression_type_mismatch);
	else
		typeError(expression_type_mismatch);
	node->basetype = bt_boolean;
	node->objectClassName = "Boolean";
}

void TypeCheck::visitAndNode(AndNode* node) {
	node->visit_children(this);
	if (check_boolean_type(node->expression_1))
		check_same_type_express(node->expression_1->basetype, node->expression_1->objectClassName, node->expression_2->basetype, node->expression_2->objectClassName, expression_type_mismatch);
	else {
		typeError(expression_type_mismatch);
	}
	set_type_expression(node, node->expression_1);
}

void TypeCheck::visitOrNode(OrNode* node) {
	node->visit_children(this);
	if (check_boolean_type(node->expression_1))
		check_same_type_express(node->expression_1->basetype, node->expression_1->objectClassName, node->expression_2->basetype, node->expression_2->objectClassName, expression_type_mismatch);
	else {

		typeError(expression_type_mismatch);
	}
	set_type_expression(node, node->expression_1);

}

void TypeCheck::visitNotNode(NotNode* node) {
	node->visit_children(this);
	if (check_boolean_type(node->expression))
		set_type_expression(node, node->expression);
	else
		typeError(expression_type_mismatch);

}
void TypeCheck::visitNegationNode(NegationNode* node) {
	node->visit_children(this);
	if (check_integer_type(node->expression))
		set_type_expression(node, node->expression);
	else {

		typeError(expression_type_mismatch);
	}
}

void TypeCheck::visitMethodCallNode(MethodCallNode* node) {
	node->visit_children(this);
	if (node->identifier_2 == NULL)
	{
		if (!find_my_method_in_class_methods(node, currentClassName, *classTable))
			typeError(undefined_method);

	}
	else {//method call from member variable
		if (find_my_variable_locally(node->identifier_1, currentVariableTable) ||
		        find_my_attribute_in_class_members(node->identifier_1, currentClassName, *classTable)) {
			if (!find_my_method_in_class_methods(node, node->identifier_1->objectClassName, *classTable))
				typeError(undefined_method);
		}
		else
			typeError(undefined_variable);
	}
}

void TypeCheck::visitMemberAccessNode(MemberAccessNode* node) {
	if (find_my_variable_locally(node->identifier_1, currentVariableTable) ||
	        find_my_attribute_in_class_members(node->identifier_1, currentClassName, *classTable)) {

		check_variable_is_member_of_a_class(node->identifier_1, node->identifier_2, *classTable);
		set_type_expression(node, node->identifier_2);

	}
	else
		typeError(undefined_variable);



}

void TypeCheck::visitVariableNode(VariableNode* node) {
	if (!find_my_variable_locally(node->identifier, currentVariableTable) && !find_my_attribute_in_class_members(node->identifier, currentClassName, *classTable))
		typeError(undefined_variable);
	set_type_expression(node, node->identifier);
}

void TypeCheck::visitIntegerLiteralNode(IntegerLiteralNode* node) {
	// WRITEME: Replace with code if necessary
}

void TypeCheck::visitBooleanLiteralNode(BooleanLiteralNode* node) {
	// WRITEME: Replace with code if necessary
}

void TypeCheck::visitNewNode(NewNode* node) {
	if (!is_class(classTable, node->identifier->name))
		typeError(undefined_class);
	if (!classTable->at(node->identifier->name).methods->count(node->identifier->name) && node->expression_list != NULL)
		typeError(argument_number_mismatch);
	node->visit_children(this);
	check_arguement_methode(node->identifier->name, classTable->at(node->identifier->name).methods, node->expression_list);

}

void TypeCheck::visitIntegerTypeNode(IntegerTypeNode* node) {
	// WRITEME: Replace with code if necessary
}

void TypeCheck::visitBooleanTypeNode(BooleanTypeNode* node) {
	// WRITEME: Replace with code if necessary
}

void TypeCheck::visitObjectTypeNode(ObjectTypeNode* node) {
	// WRITEME: Replace with code if necessary
}

void TypeCheck::visitNoneNode(NoneNode* node) {
	// WRITEME: Replace with code if necessary
}

void TypeCheck::visitIdentifierNode(IdentifierNode* node) {


}

void TypeCheck::visitIntegerNode(IntegerNode* node) {
	// WRITEME: Replace with code if necessary
}


// The following functions are used to print the Symbol Table.
// They do not need to be modified at all.

std::string genIndent(int indent) {
	std::string string = std::string("");
	for (int i = 0; i < indent; i++)
		string += std::string(" ");
	return string;
}

std::string string(CompoundType type) {
	switch (type.baseType) {
	case bt_integer:
		return std::string("Integer");
	case bt_boolean:
		return std::string("Boolean");
	case bt_none:
		return std::string("None");
	case bt_object:
		return std::string("Object(") + type.objectClassName + std::string(")");
	default:
		return std::string("");
	}
}


void print(VariableTable variableTable, int indent) {
	std::cout << genIndent(indent) << "VariableTable {";
	if (variableTable.size() == 0) {
		std::cout << "}";
		return;
	}
	std::cout << std::endl;
	for (VariableTable::iterator it = variableTable.begin(); it != variableTable.end(); it++) {
		std::cout << genIndent(indent + 2) << it->first << " -> {" << string(it->second.type);
		std::cout << ", " << it->second.offset << ", " << it->second.size << "}";
		if (it != --variableTable.end())
			std::cout << ",";
		std::cout << std::endl;
	}
	std::cout << genIndent(indent) << "}";
}

void print(MethodTable methodTable, int indent) {
	std::cout << genIndent(indent) << "MethodTable {";
	if (methodTable.size() == 0) {
		std::cout << "}";
		return;
	}
	std::cout << std::endl;
	for (MethodTable::iterator it = methodTable.begin(); it != methodTable.end(); it++) {
		std::cout << genIndent(indent + 2) << it->first << " -> {" << std::endl;
		std::cout << genIndent(indent + 4) << string(it->second.returnType) << "," << std::endl;
		std::cout << genIndent(indent + 4) << it->second.localsSize << "," << std::endl;
		print(*it->second.variables, indent + 4);
		std::cout << std::endl;
		std::cout << genIndent(indent + 2) << "}";
		if (it != --methodTable.end())
			std::cout << ",";
		std::cout << std::endl;
	}
	std::cout << genIndent(indent) << "}";
}

void print(ClassTable classTable, int indent) {
	std::cout << genIndent(indent) << "ClassTable {" << std::endl;
	for (ClassTable::iterator it = classTable.begin(); it != classTable.end(); it++) {
		std::cout << genIndent(indent + 2) << it->first << " -> {" << std::endl;
		if (it->second.superClassName != "")
			std::cout << genIndent(indent + 4) << it->second.superClassName << "," << std::endl;
		print(*it->second.members, indent + 4);
		std::cout << "," << std::endl;
		print(*it->second.methods, indent + 4);
		std::cout << std::endl;
		std::cout << genIndent(indent + 2) << "}";
		if (it != --classTable.end())
			std::cout << ",";
		std::cout << std::endl;
	}
	std::cout << genIndent(indent) << "}" << std::endl;
}

void print(ClassTable classTable) {
	print(classTable, 0);
}
