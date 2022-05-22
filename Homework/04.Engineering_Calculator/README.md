
# Task 4 - "Engineering calculator"

This repository implements a lexer and a parser for building an arithmetic expression calculator

In this task, you have to write an engineering calculator that takes a text with an arithmetic
expression as input and, as a result of its work, converts it into an abstract syntax tree (ASD)
( AST - Abstract Syntax Tree). AST is the internal representation of the program inside the
compiler. In this work, you will need to print the resulting structure to the screen. In future
works, we will develop this example, providing it with additional functionality.

Compiler schema
It includes 2 main blocks - lexical and syntactic analyzers.

At the input of the `lexical analyzer` (lexer) are symbols, at the output it forms tokens, which
are elementary bricks. For example, the number 123 has 3 characters, but is a single integer
token.

## The algorithm of the lexical analyzer

The lexer is based on the logic of the state machine. Its code is described in the header file
`lexer.h` and the implementation file lexer.cpp. The main logic is inside the method
`Lexer::next_token()`. This method should parse the next token into input character stream
and return its type. A typed enum is used to encode the token type (enum class)token. More
details at enum class can be found in article [4]. Unlike a normal C-style enum (enum), a typed enum allows
the compiler to control types when assignment and comparison, as well as to monitor the
coverage of all possible transitions inswitch constructs.

The lexer also stores its internal state, encoded using a typed enum.State. For parsing some
tokens, for example numbers and names, the lexer needs to read several characters from
the input stream. So to get the value of a number from a symbolic representation, you need
to read the numbers from left to right, constantly accumulate their result in the
accumulator, multiplying the current result by 10 (left shift) and adding a new number.

The scheme of transitions between the states of the lexer is shown below.
Each new character read from the input stream can transfer the lexer to a new state or leave it in the
previous one (transition like a loop). Empty - initial state, End - final. The labels on the
arrows indicate the set of characters to navigate through.

![lexer-state-transition-state-machine](https://github.com/Kirill-Geskin/otus-cpp-basics/blob/main/Homework/IMG/lexer-state-transition-state-machine.png)

Let's consider the following example. The input to the lexer is the string 12 + a. The initial state is Empty. Read the first character '1'. There is a transition from the Empty state to the ReadNumber state signed as 0-9 (which means any character from '0' to '9' or any digit). The state changes to ReadNumber, and the class member variable number_ is set to 1. The next character '2' remains in the same ReadNumber state, and the variable number_ is assigned the value 10 * 1 + 2 = 12. The next character '+' puts the automaton in the Empty state (jump on the arrow 0̂-9,which is read as any character except the range from '0' to '9'). In this case, the next_token() method returns the value Token::Number, signaling that a number has been read from the input stream. The read '+' character is remembered so that it can be used the next time the method is called.

The next time next_token() is called, we process the stored '+' character and stay in the current Empty state, returning the Operator token. The subsequent call will bring us to the ReadName state, since the character 'a' was not encountered. And from Empty there is a transition to ReadName along the range of characters 'a-z'. After the end-of-file or end-of-line sign appears in the stream, the lexer goes to the final state End and always returns a special End token, signaling that the data in the input stream has ended.


## The algorithm of the parser

The parser receives a stream of tokens as input and converts it into an AST as shown in the example below.

![the-algorithm-of-the-parser](https://github.com/Kirill-Geskin/otus-cpp-basics/blob/main/Homework/IMG/the-algorithm-of-the-parser.png)

Its implementation is described in the parser.h and parser.cpp files. The implementation of 
the Parser::parse() method uses the expr(), term(), and prim() protected helper methods. 
These methods implement the logic of the recursive descent algorithm for parsing 
arithmetic expressions. Consider the following notation, which can be used to describe an 
arbitrary abstract arithmetic expression. Let the expression E (expression) can consist of:

1. One term T (term)
2. The term T + another expression E
3. The term T is another expression of E.

These 3 options can be written as E -> T | T+E | T - E. Here the symbol '|' means 'or'. Such a 
recursive definition for the expression E allows one to describe an expression with any 
number of terms.
The term itself can be

1. Basic element (number or variable name) P (prim)
2. base element * T
3. Base element / T

or in shorter notation T -> P | P * T | P/T.
For the base element, you can describe P -> Number | Name.
For example, the expression 3 * 4 / 5 can be obtained from T using a series of substitutions to 
the rules described above:
T -> P * T -> P * P / T -> P * P / P

All together describes the grammar of the language of arithmetic expressions (without brackets) in 
the formBackusa-Naura (BNF) E -> T | T+E | T - ET -> P | P*T| P/TP -> Number | Name
Consider, using the expression 3 + 4 - 5 as an example, how a parser can be built based on 
the obtained BNF. We start by calling a method to parse the expression E (expr). We read 
the first term() term, which creates a node of type Number and returns as a pointer to the 
ASTNode. The evolution of AST when parsing this example is shown in Figure 4. Next, we 
read the addition operator '+' and the next term '4'. We form a tree from them, at the root 
of which is the Add node, and in its subtrees the Number(3) and Number(4) nodes. The next 
Sub operation becomes the new root of the tree with a Number(5) node in the right 
subtree. Since the token

![the-algorithm-of-the-parser-1](https://github.com/Kirill-Geskin/otus-cpp-basics/blob/main/Homework/IMG/the-algorithm-of-the-parser-1.png)



Assembly instructions
C++17 compiler required

To build the project, run the following commands

mkdir build && cd build
cmake ..
cmake --build .
Work examples:

$echo "3 + 12 * 4" | ./calc
	3
+
		12
	*
		4
$echo "a*a + 2*a*b + b*b" | ./calc
			a
	*
		a
+
			2
		*
			a
	*
		b
+
		b
	*
		b