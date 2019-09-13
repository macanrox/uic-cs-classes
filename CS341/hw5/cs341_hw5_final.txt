#light

//
// F# grading program.
//
// Bresia Prudente (bprude2)
// U. of Illinois, Chicago
// CS341, Spring 2014
// Homework 5
//

//Tell F# to ignore the printing of exam scores
//on separate lines
let printfnList(L)
   printfn "** Elements of List **"
   List.map (printfn "%A") L

//use printfnList( [1; 2; 3] ) to call function
//use ignore( printfnList(...) ) to ignore returned "unit list"

// Read text files
let readFile( fileName ) = 
[ for text in System.IO.File.ReadAllLines( fileName ) -> text ]

// Both sum and length are doubles because we will need to
// find the average which is a double

// sum
// adds the sum of the element of the head and 
// elements at the tail of list
let rec sum( L ) = 
   match L with
      | [] -> 0.0
      | _ -> L.Head + sum( L.Tail )

// length
// grabs the file length
let rec length( L ) =
   match L with
      | [] -> 0.0
      | _ -> 1.0 + length( L.Tail )

// min
// finds the minimum element of the list
// refrain using "min"
let rec findMin( L, isMin ) = 
   match L with
      | [] -> isMin
      | _ -> if L.Head < isMin
               then findMin( L.Tail, L.Head )
               else findMin( L.Tail, isMin )

//recursively do this for a generic list
let doMin( L:'a list ) = 
   findMin( L.Tail, L.Head )

// max
// finds the maximum element of the list
// refrain using "max"
let rec findMax( L, isMax ) =
   match L with
   | [] -> isMax
   | _ -> if L.Head > isMax
            then findMax( L.Tail, L.Head )
            else findMax( L.Tail, isMax )

//recursively do this for a generic list
let doMax( L:'a list ) =
   findMax( L.Tail, L.Head )

// standDev
// We first need to clarify a formula based on definition in Wikipedia
// We calculate the square root of the average of the squared differences
// of their values
// Then calculate: 	
//	mean which is the sum of the values divided by the length
//	difference which is the square root of mean
//	result which is the square root of the sum of the difference 
//		divided by its length

let sqrtOfDiffer x y = ( x-y ) * ( x-y )

let standDev( values ) =
   let isMean = sum( values ) / length( value )
   let differs = List.map ( sqrtOfDiffer mean ) value
   let result = System.Math.Sqrt( sum( differs ) / length( differs ) )
   result

// calculateScores
// This is where we calculate scores

let calculateScores() = 
   printfn ""

   // Read contents of each exam files
   let exam1 = List.map System.DoubleParse ( readFile( "exam1.txt " ))
   let exam2 = List.map System.DoubleParse ( readFile( "exam2.txt " ))
   let exam3 = List.map System.DoubleParse ( readFile( "final.txt " ))

   // Calculate the weight of the scores
   let weightOfExam1 = List.map ( fun x -> x * 0.3 ) exam1
   let weightOfExam2 = List.map ( fun x -> x * 0.3 ) exam2	
   let weightOfFinal = List.map ( fun x -> x * 0.4 ) final

   // Calculate total scores
   let total = List.map3 ( fun x y z -> x + y + z ) weightOfExam1 weightOfExam2 weightOfFinal

   // Call this ignore because we need to print each scores per line
   ignore( printList( "** Final Scores **", total ))

   printfn ""
   printfn "** Statistics **"
   printfn "Maximum %A" ( doMax( total ))
   printfn "Minimum %A" ( doMin( total ))
   printfn "Average %A" ( sum( total )/ length( total ))
   printfn "Standard Deviation %A" ( standDev( total ))

// main
calculateScores()
