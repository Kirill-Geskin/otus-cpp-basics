
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

Each new character read from the input stream can transfer the lexer to a new state or leave it in the
previous one (transition like a loop). Empty - initial state, End - final. The labels on the
arrows indicate the set of characters to navigate through.

![lexer-state-transition-state-machine](https://github.com/Kirill-Geskin/otus-cpp-basics/blob/main/Homework/IMG/lexer-state-transition-state-machine.png)



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