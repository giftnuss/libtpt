/*
 * parse.cxx
 *
 * Parser
 *
 * $Id$
 *
 */


#include <tptlib/parse.h>
#include "parse_impl.h"

#include <algorithm>
#include <sstream>

namespace TPTLib {


Parser::Parser(Buffer& buf, const SymbolTable* st)
{
	imp = new Impl(buf, st);
}

Parser::Parser(Buffer& buf, SymbolMap& sm)
{
	imp = new Impl(buf, sm);
}

Parser::~Parser()
{
	delete imp;
}

std::string Parser::run()
{
	std::stringstream ss;
	run(ss);
	return ss.str();
}

bool Parser::run(std::ostream& os)
{
	imp->errlist.clear();
	return imp->pass1(&os);
}

bool Parser::syntax()
{
	return imp->pass1(0);
}

unsigned Parser::geterrorcount()
{
	return imp->errlist.size();
}

bool Parser::geterrorlist(std::vector< std::string >& errlist)
{
	if (imp->errlist.size())
	{
		errlist.clear();
		std::copy(imp->errlist.begin(), imp->errlist.end(), errlist.begin());
		return true;
	}
	else
		return false;
}


} // end namespace TPTLib