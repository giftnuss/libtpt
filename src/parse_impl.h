/*
 * parse_impl.h
 *
 * Parser Implementation
 *
 * $Id$
 *
 */

#ifndef __tptlib_parse_impl_h
#define __tptlib_parse_impl_h

#ifdef _MSC_VER
// Disable long symbol name warning on MSVC++
#pragma warning(disable:4786)
#endif

#include <tptlib/parse.h>
#include "lexical.h"
#include "macro.h"

namespace TPTLib {

struct Parser::Impl {
	Lex lex;
	unsigned level;	// if/loop level
	SymbolMap localsymmap;
	SymbolMap& symbols;	// alias reference to whatever symbol map is in
						// use
	ErrorList errlist;
	Token<> tok;
	MacroList macros;

	Impl(Buffer& buf, const SymbolTable* st) : lex(buf), level(0),
		symbols(localsymmap) { if (st) localsymmap = *st; }
	Impl(Buffer& buf, SymbolMap& sm) : lex(buf), level(0),
		symbols(sm) { }
	void recorderror(const std::string& desc, const Token<>* neartoken=0);
	bool getnextparam(std::string& value);
	bool getnextstrict(Token<>& target);
	bool getparamlist(ParamList& pl);

	bool pass1(std::ostream* os);

	Token<> parse_level0(Token<>& left);
	Token<> parse_level1(Token<>& left);
	Token<> parse_level2(Token<>& left);
	Token<> parse_level3(Token<>& left);
	Token<> parse_level4(Token<>& left);
	Token<> parse_level5(Token<>& left);
	Token<> parse_level6(Token<>& left);
	Token<> parse_level7(Token<>& left);
	Token<> parse_rand(Token<>& left);
	Token<> parse_empty(Token<>& left);

	void parse_include(std::ostream* os);
	void parse_if(std::ostream* os);
	void parse_set(std::ostream* os);

	void parse_macro();

	void addmacro(const std::string& name, const ParamList& params,
		const std::string& body);
	void execmacro(const std::string& name, const ParamList& params);
};


} // end namespace TPTLib

#endif // __tptlib_parse_impl_h
