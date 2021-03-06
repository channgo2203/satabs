/*
 * concurrency_aware_abstractor.h
 *
 *  Created on: Aug 2, 2011
 *      Author: alad
 */

#ifndef CONCURRENCY_AWARE_ABSTRACTOR_H_
#define CONCURRENCY_AWARE_ABSTRACTOR_H_

#include <memory>

#include "abstractor.h"

#include <util/std_expr.h>
#include <util/location.h>

#include <pointer-analysis/value_set_analysis.h>


class concurrency_aware_abstractort : public abstractort {
public:

	concurrency_aware_abstractort(
      const argst &args,
      std::auto_ptr<abstractort> specific_abstractor,
      const goto_functionst &functions,
      const bool _passive_nondet) :
		abstractort(args),
		specific_abstractor(specific_abstractor),
		pointer_info(args.concrete_model.ns),
    passive_nondet(_passive_nondet)
	{
		status("Performing pointer analysis for concurrency-aware abstraction");
		pointer_info(functions);
		status("Pointer analysis complete");
	}

	virtual ~concurrency_aware_abstractort()
	{

	}

protected:
	virtual void pred_abstract_block(
			goto_programt::const_targett target,
			const predicatest &predicates,
			abstract_transition_relationt &
			abstract_transition_relation);

        virtual void abstract_assume_guard(
                        const predicatest &predicates,
                        exprt &expr,
                        const namespacet &ns,
                        goto_programt::const_targett program_location);

	std::set<symbol_exprt> targets_of_lvalue(const exprt& lvalue, goto_programt::const_targett program_location);

	bool broadcast_required(
	  		  goto_programt::const_targett target,
	  		  const predicatet &predicate,
	  		  goto_programt::const_targett program_location);

private:
	std::auto_ptr<abstractort> specific_abstractor;
	value_set_analysist pointer_info;
  const bool passive_nondet;


};

#endif /* CONCURRENCY_AWARE_ABSTRACTOR_H_ */
