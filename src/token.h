/*
 * token.h
 *
 * $Id$
 *
 */

#ifndef __tptlib_token_h
#define __tptlib_token_h

#include <string>

namespace TPTLib {

enum TokenTypes {
	token_error = 0,
	token_eof,
	token_id,			// ${id name}
	token_usermacro,	// @userdefinedmacro
	token_integer,		// 12345
	token_string,		// "string"
	token_text,			// alphanum
	token_comment,		// # comment character
	token_whitespace,	// space, tab, carriage return symbol
	token_newline,		// \n, \r, \r\n
	token_joinline,		// \\n, \\r, \\r\n
	token_escape,		// \escape character
	token_openbrace,	// {
	token_closebrace,	// }
	token_openparen,	// (
	token_closeparen,	// )
	token_comma,		// ,
	token_quote,		// "
	token_operator,		// + - */ % || && ^^
	token_relop,		// < <= == != > >=
	token_include,		// @include
	token_foreach,		// @foreach
	token_while,		// @while
	token_next,			// @next
	token_last,			// @last
	token_if,			// @if
	token_else,			// @else
	token_empty,		// @empty
	token_macro,		// @macro
	token_set,			// @set
	token_rand,			// @rand
	token_concat,		// @concat
};

template<typename E=TokenTypes> struct Token {
	E type;
	typedef E en;
	std::string value;
};

} // end namespace TPTLib

#endif // __tptlib_token_h