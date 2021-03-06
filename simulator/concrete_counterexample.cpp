/*******************************************************************\

Module: Counterexamples

Author: Daniel Kroening

  Date: June 2003

\*******************************************************************/

#include "concrete_counterexample.h"

/*******************************************************************\

Function: show_counterexample_gui

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void show_counterexample_gui(
  std::ostream &out,
  const contextt &context,
  const concrete_counterexamplet &counterexample)
{
  const namespacet ns(context);
  show_goto_trace_gui(out, ns, counterexample.goto_trace);
}

/*******************************************************************\

Function: show_counterexample

  Inputs:

 Outputs:

 Purpose:

\*******************************************************************/

void show_counterexample(
  std::ostream &out,
  const contextt &context,
  const concrete_counterexamplet &counterexample)
{
  namespacet ns(context);
  
  show_goto_trace(out, ns, counterexample.goto_trace);

  #if 0
  unsigned cycle=0;

  for(concrete_counterexamplet::additional_tracet::const_iterator
      it=counterexample.additional_trace.begin();
      it!=counterexample.additional_trace.end();
      it++, cycle++)
  {
    out << "Transition system state " << cycle << std::endl;
    out << "----------------------------------------------------" << std::endl;

    for(additional_concrete_statet::valuest::const_iterator
        v_it=it->values.begin();
        v_it!=it->values.end();
        v_it++)
      counterexample_value(out, ns, v_it->first, v_it->second,
                           pretty_names);

    out << std::endl;
  }
  #endif

}
