/*
Sample Starter Exercises For Scala From
http://ampcamp.berkeley.edu/3/exercises/introduction-to-the-scala-shell.html
*/
object ex1 {
	
	def main(args:Array[String]) = {
		val myNumbers = List(1,2,3)
		myNumbers.foreach(println)
	}	
	
	def cube(a:Int) : Int = { (a*a*a) }
	cube(3)

	myNumbers.map( num => (num, cube(num))).foreach(println)

	def fact(n:Int) : Int = { if(n==1) return 1 else return n*fact(n-1) }

	println(fact(5))

	val sumOfFactorials = myNumbers.map( num => fact(num) ).reduce( ( a,b ) => a+b )
	println(sumOfFactorials)

	
}
