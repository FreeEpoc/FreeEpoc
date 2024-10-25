//=======================================================================
// Copyright 1997, 1998, 1999, 2000 University of Notre Dame.
// Authors: Andrew Lumsdaine, Lie-Quan Lee, Jeremy G. Siek
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
//=======================================================================

/*
 * � Portions copyright (c) 2006-2007 Nokia Corporation.  All rights reserved.
*/

#include <boost/config.hpp>
#include <vector>
#include <list>

#ifdef __SYMBIAN32__
#include "std_log_result.h"
#define LOG_FILENAME_LINE __FILE__, __LINE__
#endif
// THIS FILE MUST PRECEDE ALL OTHER BOOST GRAPH FILES
// Due to ADL nastiness involving the vertices() function
#include <boost/graph/vector_as_graph.hpp>
// THIS FILE MUST PRECEDE ALL OTHER BOOST GRAPH FILES

#include <boost/graph/graph_concepts.hpp>
#include <boost/graph/graph_archetypes.hpp>

int main(int,char*[])
{
  using namespace boost;
  // Check "vector as graph"
  {
    typedef std::vector< std::list<int> > Graph;
    function_requires< VertexListGraphConcept<Graph> >();
    function_requires< IncidenceGraphConcept<Graph> >();
    function_requires< AdjacencyGraphConcept<Graph> >();
  }
  
  #ifdef __SYMBIAN32__
  	std_log(LOG_FILENAME_LINE,"[End Test Case ]");

	testResultXml("vector_graph_cc");
	close_log_file();
#endif
  return 0;
}