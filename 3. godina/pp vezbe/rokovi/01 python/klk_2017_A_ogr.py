# Napisati program koji redja brojeve u magican trougao. Magican 
# trougao je sacinjen od devet brojeva iz intervala [1,9], takvih 
# da svaka stranica sadrzi cetiri broja koji u zbiru daju 21.
import constraint

problem = constraint.Problem()

problem.addVariables("ABCDEFGHI", range(1, 10))

problem.addConstraint(constraint.AllDifferentConstraint())

def ogr(a, b, c, d):
    return a+b+c+d == 21

problem.addConstraint(ogr, "ABCD")
problem.addConstraint(ogr, "DEFG")
problem.addConstraint(ogr, "DHIA")

resenje = problem.getSolutions()

for r in resenja:
	print """
	         {0:d}
	    {1:d}    {2:d}
	  {3:d}        {4:d} 
	{5:d} {6:d} {7:d} {8:d}
	""".format(r['A'],r['B'],r['C'],r['D'],r['E'],r['F'],r['G'],r['H'],r['I'])