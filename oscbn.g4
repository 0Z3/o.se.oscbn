grammar oscbn;

//topLevelBundle
   // : first=oscBundleElem (SEQSEP rest=oscBundleElem)* 
   // ;

osc
   : oscBundle
   | oscMessage
   | oscUnclosedBundle
   ;

oscBundle
   : LBRACE RBRACE # emptyBundle
   | LBRACE first=oscBundleElem (SEQSEP rest=oscBundleElem)* RBRACE # nonEmptyBundle
   ;

oscUnclosedBundle
   : LBRACE # unclosedEmptyBundle
   | LBRACE first=oscBundleElem (SEQSEP rest=oscBundleElem)* # unclosedNonEmptyBundle
   // | LBRACE first=oscBundleElem (SEQSEP rest=oscBundleElem)* { notifyErrorListeners(_input->LT(1), "Shut it!!", NULL); } # unclosedNonEmptyBundle
   ;

oscBundleElem
   : oscBundle
   | oscMessage
   ;

oscMessage
   : OSCADDRESS BIND?
   | OSCADDRESS? BIND oscMessageItems
   | OSCPATTERN BIND?
   | OSCPATTERN? BIND oscMessageItems
   | oscMessageItems
   ;

oscMessageItems
   : oscMessageItem
   | LBRACKET first=oscMessageItem? (SEQSEP rest=oscMessageItem)* RBRACKET
   ;

oscMessageItem
   : INT32
   | FLOAT
   | STRING
   | BLOB
   | TIMETAG
   | oscBundle
   ;

OSCPATTERN
   : (CONTAINER | PCONTAINER)* PCONTAINER+ (CONTAINER | PCONTAINER)*
   ;

fragment
PCONTAINER
   : '/' (VALIDADDRESSCHAR | WILDCARD)* WILDCARD+ (VALIDADDRESSCHAR | WILDCARD)*
   ;
   
fragment
WILDCARD
   : '?'
   | '*'
   | '{' ~[ {}]+ (SEQSEP ~[ {}]+)* '}'
   | '[' '^'? ~[\]]+ ']'
   ;

OSCADDRESS
   : CONTAINER+
   ;

fragment
CONTAINER
   : '/' VALIDADDRESSCHAR*
   ;

fragment
VALIDADDRESSCHAR
   : ~[ #*,/?[\](){}\t\n:]
   ;

INT32
   : IntegerConstant
   ;

FLOAT
   : FloatingConstant
   ;

//////////////////////////////////////////////////////////////////////

Digit
    :   [0-9]
    ;

fragment
IntegerConstant
:   DecimalConstant // IntegerSuffix?
|   OctalConstant // IntegerSuffix?
|   HexadecimalConstant // IntegerSuffix?
|    BinaryConstant
;

fragment
BinaryConstant
    :    '0' [bB] [0-1]+
        ;

fragment
DecimalConstant
    :   NonzeroDigit Digit*
        ;

fragment
OctalConstant
    :   '0' OctalDigit*
        ;

fragment
HexadecimalConstant
    :   HexadecimalPrefix HexadecimalDigit+
        ;

fragment
HexadecimalPrefix
    :   '0' [xX]
        ;

fragment
NonzeroDigit
    :   [1-9]
        ;

fragment
OctalDigit
    :   [0-7]
        ;

fragment
HexadecimalDigit
    :   [0-9a-fA-F]
        ;

fragment
FloatingConstant
    :   DecimalFloatingConstant
        |   HexadecimalFloatingConstant
	    ;

fragment
DecimalFloatingConstant
    :   FractionalConstant ExponentPart? FloatingSuffix?
        |   DigitSequence ExponentPart FloatingSuffix?
	    ;

fragment
HexadecimalFloatingConstant
    :   HexadecimalPrefix HexadecimalFractionalConstant BinaryExponentPart FloatingSuffix?
        |   HexadecimalPrefix HexadecimalDigitSequence BinaryExponentPart FloatingSuffix?
	    ;

fragment
FractionalConstant
    :   DigitSequence? '.' DigitSequence
        |   DigitSequence '.'
	    ;

fragment
ExponentPart
    :   'e' Sign? DigitSequence
        |   'E' Sign? DigitSequence
	    ;

fragment
Sign
    :   '+' | '-'
        ;

DigitSequence
    :   Digit+
        ;

fragment
HexadecimalFractionalConstant
    :   HexadecimalDigitSequence? '.' HexadecimalDigitSequence
        |   HexadecimalDigitSequence '.'
	    ;

fragment
BinaryExponentPart
    :   'p' Sign? DigitSequence
        |   'P' Sign? DigitSequence
	    ;

fragment
HexadecimalDigitSequence
    :   HexadecimalDigit+
        ;

fragment
FloatingSuffix
    :   'f' | 'l' | 'F' | 'L'
        ;

//////////////////////////////////////////////////////////////////////

// fragment
// DIGITSEQUENCE
//    : DIGIT+
//    ;

// fragment
// DIGIT
//    : [0-9]
//    ;

// fragment
// NONZERODIGIT
//    : [1-9]
//    ;

STRING
      : '"' (~[\\"] | '\\' [\\"])* '"'
      ;

BLOB
   : 'b' (Digit Digit)*
   ;

fragment
ISO8601Year : ([1-9][0-9]*)?[0-9][0-9][0-9][0-9] ;

fragment
ISO8601Month : ('1'[0-2]|'0'[1-9]) ;

fragment
ISO8601Day : ('3'[0-1]|'0'[1-9]|[1-2][0-9]) ;

fragment
ISO8601Date : '-'? ISO8601Year '-' ISO8601Month '-' ISO8601Day? ;

fragment
ISO8601Hour : ('2'[0-3]|[0-1][0-9]) ;

fragment
ISO8601Minute : ([0-5][0-9]) ;

fragment
ISO8601Second : ([0-5][0-9])('.'[0-9]+)?? ;

fragment
ISO8601FracSecond : ('Z'|[+-]('2'[0-3]|[0-1][0-9])':'[0-5][0-9])? ;

fragment
ISO8601Time : 'T' ISO8601Hour ':' ISO8601Minute ':' ISO8601Second ISO8601FracSecond ;
        
TIMETAG
   : ISO8601Date ISO8601Time
   ;

BIND
   : ':'
   ;

LBRACKET
   : '['
   ;

RBRACKET
   : ']'
   ;

LBRACE
   : '{'
   ;

RBRACE
   : '}'
   ;

SEQSEP
   : ','
   ;

COMMENT
  :  '#' ~( '\r' | '\n' )* -> skip
  ;

WHITESPACE: [ \t\n\r] -> skip;
