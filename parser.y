%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <iostream>

    #include "ast.hpp"
    #define YYMAXDEPTH      500
    #define YYDEBUG 1
     #define YYINITDEPTH 500
    int yylex(void);
    void yyerror(const char *);
    
    extern ASTNode* astRoot;
%}

%error-verbose


%token T_ARROW
%token T_PLUS   
%token T_MINUS
%token T_MULT
%token T_DIVIDE
%token T_AND 
%token T_OR      
%token T_NOT               
%token T_OPAREN  
%token T_CPAREN  
%token T_OBRACET 
%token T_CBRACET 
%token T_SEMICOLON
%token T_COMMA  
%token T_DOT     
%token T_ASSIGNMENT             
%token T_LESSEQ  
%token T_LESS   
%token T_EQUALS             
%token T_IFSTMNT 
%token T_ELSESTMNT        
%token T_WHILESTMNT    
%token T_REPEATSTMNT
%token T_UNTILSTMNT           
%token T_PRINTSTMNT          
%token<integer_ptr> T_LITERAL
%token<integer_ptr> T_TRUE
%token<integer_ptr> T_FALSE      
%token T_BOOLEAN 
%token T_INTEGER 
%token T_NONE
%token T_NEW
%token T_EXTENDS
%token T_EOF
%token T_COLON 
%token T_RETURN
%token T_CLASS
%token<identifier_ptr> T_IDENTIFIER

%left T_OR 
%left T_AND
%left T_LESSEQ T_LESS T_EQUALS
%left T_PLUS T_MINUS
%left T_MULT T_DIVIDE
%right NOT UNARYMINUS



%type <expression_ptr>       EXPRESSION
%type <memberaccess_ptr>     MEMBER_ACCESS
%type <new_ptr>              CLASS_NAME
%type <expression_list_ptr>  ARGUMENTS
%type <methodcall_ptr>       METHODCALL

%type <returnstatement_ptr>  RETURN_CONTROL;

%type<declaration_list_ptr>  DECLRATION_STATEMENTS;
%type<identifier_list_ptr>   DECLARATION;
%type <type_ptr>             MEMBER_TYPES;
%type <type_ptr>             RETURN_MEMBER_TYPES;
%type <declaration_ptr> X;

%type <methodbody_ptr>       BODY;
%type <statement_list_ptr>   STATEMENTS;

%type <ifelse_ptr>           IF_ELSE;
%type <statement_list_ptr> ELSE_BLOCK;
%type <while_ptr>            WHILELOOP;
%type <repeat_ptr>           REPEAT_UNTIL;
%type <print_ptr>            PRINT;
%type <statement_ptr>        STATEMENT;
%type <assignment_ptr>       ASSIGNING;

%type <parameter_ptr>        PARM;
%type <parameter_list_ptr>   PARAMETERS;

%type<declaration_list_ptr> MEMBERS;
%type<declaration_ptr> MEMBER;

%type <method_list_ptr>      METHODS;
%type <method_ptr>           METHOD;

%type<class_ptr> CLASS_BLOCK;
%type<identifier_ptr> INHERITS;
%type <class_list_ptr>       CLASSES;
%type <class_ptr>            CLASS;

%type<program_ptr>          START;


%%


START : CLASSES           {$$= new ProgramNode($1); astRoot=$$;}     
CLASSES : CLASSES CLASS   {$$= $1; $$->push_back($2);}
      | CLASS             {$$= new std::list<ClassNode*>(); $$->push_back($1);}
      ;            

CLASS : T_IDENTIFIER INHERITS T_OBRACET CLASS_BLOCK T_CBRACET {$4->identifier_1= $1;
                                                               $4->identifier_2= $2;
                                                               $$=$4; }
      ;

INHERITS : T_EXTENDS T_IDENTIFIER {$$= $2;}
         | {$$= NULL;}
         ;
CLASS_BLOCK : MEMBERS METHODS {$$= new ClassNode(NULL, NULL, $1, $2    ); }
            | MEMBERS         {$$= new ClassNode(NULL, NULL, $1, NULL  ); }
            | METHODS         {$$= new ClassNode(NULL, NULL, NULL, $1  ); }
            |                 {$$= new ClassNode(NULL, NULL, NULL, NULL); }               
            ;
MEMBERS : MEMBERS MEMBER T_SEMICOLON   {$$= $1; $$->push_back($2);}
        | MEMBER T_SEMICOLON           {$$= new std::list<DeclarationNode*>(); $$->push_back($1);}
MEMBER :  MEMBER_TYPES T_IDENTIFIER   {std::list<IdentifierNode*> *s = new std::list<IdentifierNode*>();
                                       s->push_back($2);
                                       $$= new DeclarationNode($1,s); $$->objectClassName= $1->objectClassName; $$->basetype= $1->basetype;  }
       ;
MEMBER_TYPES : T_BOOLEAN    {$$= new BooleanTypeNode(); $$->objectClassName= "Boolean"; $$->basetype= bt_boolean;}
             | T_INTEGER    {$$= new IntegerTypeNode(); $$->objectClassName= "Integer"; $$->basetype= bt_integer;}
             | T_IDENTIFIER {$$= new ObjectTypeNode($1); $$->objectClassName= $1->name; $$->basetype= bt_object; }
             ;
METHODS : METHODS METHOD  {$$= $1; $$->push_back($2);}
        | METHOD          {$$= new std::list<MethodNode*>(); $$->push_back($1);}
        ;
RETURN_MEMBER_TYPES : T_BOOLEAN {$$= new BooleanTypeNode(); $$->objectClassName= "Boolean"; $$->basetype= bt_boolean;}
                    | T_INTEGER {$$= new IntegerTypeNode(); $$->objectClassName= "Integer"; $$->basetype= bt_integer;}
                    | T_IDENTIFIER {$$= new ObjectTypeNode($1); $$->objectClassName= $1->name; $$->basetype= bt_object;}
                    | T_NONE       {$$= new NoneNode(); $$->objectClassName="None"; $$->basetype= bt_none;}
                    ;
METHOD : T_IDENTIFIER T_OPAREN PARAMETERS T_CPAREN T_ARROW RETURN_MEMBER_TYPES T_OBRACET BODY T_CBRACET {$$= new MethodNode( $1, $3,$6, $8 ); $$->objectClassName= $6->objectClassName; $$->basetype= $6->basetype;}
        | T_IDENTIFIER T_OPAREN T_CPAREN T_ARROW RETURN_MEMBER_TYPES T_OBRACET BODY T_CBRACET {$$= new MethodNode( $1, NULL,$5, $7 );}
        ;
PARAMETERS :  PARAMETERS T_COMMA PARM                  {$$= $1; $$->push_back($3);}
           |  PARM                                     {$$= new std::list<ParameterNode*>(); $$->push_back($1);}
           ;
PARM : T_IDENTIFIER T_COLON MEMBER_TYPES              {$$= new ParameterNode($3, $1); $$->objectClassName= $3->objectClassName; $$->basetype= $3->basetype;}              
     ;
BODY :DECLRATION_STATEMENTS STATEMENTS RETURN_CONTROL {$$= new MethodBodyNode($1,$2,$3);}
     | DECLRATION_STATEMENTS RETURN_CONTROL           {$$= new MethodBodyNode($1,NULL,$2);}
     | STATEMENTS RETURN_CONTROL                      {$$= new MethodBodyNode(NULL,$1,$2);}
     | RETURN_CONTROL                                 {$$= new MethodBodyNode(NULL, NULL, $1);}
     ;

DECLRATION_STATEMENTS : DECLRATION_STATEMENTS X  T_SEMICOLON   {$$= $1; $$->push_back($2);}
                      | X T_SEMICOLON                         {$$= new std::list<DeclarationNode*>(); $$->push_back($1);}
                      ;
X : MEMBER_TYPES DECLARATION  {$$= new DeclarationNode($1,$2); $$->basetype= $1->basetype; $$->objectClassName= $1->objectClassName;}

DECLARATION :  DECLARATION T_COMMA T_IDENTIFIER {$$=$1; $$->push_back($3);    }
            |  T_IDENTIFIER                     {$$= new std::list<IdentifierNode*>(); $$->push_back($1);  }
            ;

RETURN_CONTROL : T_RETURN EXPRESSION T_SEMICOLON  {$$= new ReturnStatementNode($2); $$->basetype=$2->basetype; $$->objectClassName= $2->objectClassName; }
               |                                  {$$= NULL;}
               ;

STATEMENTS : STATEMENTS STATEMENT   {$$=$1; $$->push_back($2);}
           | STATEMENT              {$$= new std::list<StatementNode*>(); $$->push_back($1);    }
           ;
STATEMENT  : METHODCALL T_SEMICOLON {$$= new CallNode($1);}
           | ASSIGNING T_SEMICOLON {$$=$1;}
           | WHILELOOP {$$=$1;}
           | REPEAT_UNTIL T_SEMICOLON {$$=$1;}
           | PRINT T_SEMICOLON {$$=$1;}
           | IF_ELSE {$$=$1;}
           ;
ASSIGNING : T_IDENTIFIER T_DOT T_IDENTIFIER T_ASSIGNMENT EXPRESSION   {$$= new AssignmentNode($1,$3,$5);}                                                        
          | T_IDENTIFIER  T_ASSIGNMENT EXPRESSION                     {$$= new AssignmentNode($1,NULL,$3);}
          ;
WHILELOOP : T_WHILESTMNT EXPRESSION T_OBRACET STATEMENTS T_CBRACET {$$= new WhileNode($2,$4);}
          ;
MEMBER_ACCESS : T_IDENTIFIER T_DOT T_IDENTIFIER                                                           {$$= new MemberAccessNode($1,$3);}
              ;
EXPRESSION : T_OPAREN EXPRESSION T_CPAREN                                                                 {$$= $2;}
           | EXPRESSION T_AND    EXPRESSION                                                               {$$= new AndNode($1, $3);		  $$->objectClassName= $1->objectClassName; $$->basetype= $1->basetype;}
           | EXPRESSION T_OR     EXPRESSION                                                               {$$= new OrNode($1, $3);		  $$->objectClassName= $1->objectClassName; $$->basetype= $1->basetype;}
           | EXPRESSION T_LESSEQ EXPRESSION                                                               {$$= new LessEqualNode($1, $3); $$->objectClassName= "Boolean"; $$->basetype= bt_boolean;}
           | EXPRESSION T_LESS   EXPRESSION                                                               {$$= new LessNode($1, $3) ;	  $$->objectClassName= "Boolean"; $$->basetype= bt_boolean;}
           | EXPRESSION T_PLUS   EXPRESSION                                                               {$$= new PlusNode($1, $3) ;	  $$->objectClassName= $1->objectClassName; $$->basetype= $1->basetype;}       
           | EXPRESSION T_EQUALS EXPRESSION                                                               {$$= new EqualNode($1, $3);	  $$->objectClassName= "Boolean"; $$->basetype= bt_boolean;}
           | EXPRESSION T_MINUS  EXPRESSION                                                               {$$= new MinusNode($1, $3);	  $$->objectClassName= $1->objectClassName; $$->basetype= $1->basetype;}       
           | EXPRESSION T_MULT   EXPRESSION                                                               {$$= new TimesNode($1, $3);	  $$->objectClassName= $1->objectClassName; $$->basetype= $1->basetype;}       
           | EXPRESSION T_DIVIDE EXPRESSION                                                               {$$= new DivideNode($1,$3);	  $$->objectClassName= $1->objectClassName; $$->basetype= $1->basetype;}       
           | T_MINUS EXPRESSION  %prec UNARYMINUS                                                         {$$= new NegationNode($2);	  $$->objectClassName= $2->objectClassName; $$->basetype= $2->basetype;}
           | T_NOT   EXPRESSION  %prec NOT                                                                {$$= new NotNode($2);	 		  $$->objectClassName= $2->objectClassName; $$->basetype= $2->basetype;}  
           | T_LITERAL                                                                                    {$$= new IntegerLiteralNode($1);$$->objectClassName= "Integer"; $$->basetype= bt_integer;}
           | MEMBER_ACCESS                                                                                {$$= $1;}
           | T_IDENTIFIER                                                                                 {$$= new VariableNode($1);}
           | METHODCALL                                                                                   {$$=$1;}
           | T_TRUE                                                                                       {$$= new BooleanLiteralNode($1);$$->objectClassName= "Boolean"; $$->basetype=bt_boolean;}
           | T_FALSE                                                                                      {$$= new BooleanLiteralNode($1);$$->objectClassName= "Boolean"; $$->basetype=bt_boolean;}
           | T_NEW CLASS_NAME                                                                             {$$=$2;}
           ;                                                        
ARGUMENTS :  ARGUMENTS T_COMMA EXPRESSION                                                                 {$$=$1; $$->push_back($3);  }
          |  EXPRESSION                                                                                   {$$= new std::list<ExpressionNode*>(); $$->push_back($1);}
          ;
METHODCALL : T_IDENTIFIER T_OPAREN ARGUMENTS T_CPAREN                                                     {$$= new MethodCallNode($1, NULL, $3); }
           | T_IDENTIFIER T_OPAREN  T_CPAREN                                                              {$$= new MethodCallNode($1, NULL, NULL);}
           | T_IDENTIFIER T_DOT T_IDENTIFIER T_OPAREN ARGUMENTS T_CPAREN                                  {$$= new MethodCallNode($1, $3, $5);}
           | T_IDENTIFIER T_DOT T_IDENTIFIER T_OPAREN T_CPAREN                                            {$$= new MethodCallNode($1, $3, NULL);}     
           ;
CLASS_NAME :  T_IDENTIFIER                                                                                {$$= new NewNode($1,NULL); $$->basetype= bt_object; $$->objectClassName= $1->name;}
           |  T_IDENTIFIER T_OPAREN ARGUMENTS T_CPAREN                                                    {$$= new NewNode($1,$3)  ; $$->basetype= bt_object; $$->objectClassName= $1->name;}
	   	     |  T_IDENTIFIER T_OPAREN T_CPAREN													                                      {$$= new NewNode($1,NULL); $$->basetype= bt_object; $$->objectClassName= $1->name;}          
           ;
 
REPEAT_UNTIL : T_REPEATSTMNT T_OBRACET STATEMENTS T_CBRACET T_UNTILSTMNT T_OPAREN  EXPRESSION T_CPAREN {$$= new RepeatNode($3,$7);}
             ;
IF_ELSE : T_IFSTMNT EXPRESSION T_OBRACET STATEMENTS T_CBRACET ELSE_BLOCK {$$= new IfElseNode($2,$4,$6);}
        ;
ELSE_BLOCK : T_ELSESTMNT T_OBRACET STATEMENTS T_CBRACET                  {$$= $3;}
           |                                                             {$$= NULL;}
           ; 
PRINT : T_PRINTSTMNT EXPRESSION                                          {$$= new PrintNode($2);}
      ;

 

%%

extern int yylineno;

void yyerror(const char *s) {
  fprintf(stderr, "%s at line %d\n", s, yylineno);
  exit(0);
}
