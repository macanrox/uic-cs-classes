module PPMImageLibrary

#light

//
// F#-based PPM image library
//
// Bresia Anne Prudente
// University of Illinois at Chicago
// CS341, Spring 2014
// Homework 6
//

//
// DebugOutput:
//
// Outputs to console, which appears in the "Output" window pane of
// Visual Studio when you run with debugging (F5).
//
let rec private OutputImage(image:int list list) = 
  match image with
  | [ ] -> printfn "**END**"
  |  _  -> printfn "%A" image.Head
           OutputImage(image.Tail)
           
let DebugOutput(width:int, height:int, depth:int, image:int list list) =
  printfn "**HEADER**"
  printfn "W=%A, H=%A, D=%A" width height depth
  printfn "**IMAGE**"
  OutputImage(image)


//
// TransformFirstRowWhite:
//
// An example transformation: replaces the first row of the given image
// with a row of all white pixels.
//
let TransformFirstRowWhite(depth:int, image:int list list) = 
  let numCols = image.Head.Length  // number of columns in first row
  let AllWhite = [ for i in 1 .. numCols -> depth ]  // white is RGB = depth depth depth
  AllWhite :: image.Tail  // first row all white :: followed by rest of original image


//
// WriteP3Image:
//
// Writes the given image out to a text file, in "P3" format.  Returns true if successful,
// false if not.
//
let WriteP3Image(filepath:string, width:int, height:int, depth:int, image:int list list) =
  let pDepth = string(width) + string(" ") + string(height) 
  let pSave = ["P3"; pDepth; string(depth)]     //create a unit that specifies string values
  System.IO.File.WriteAllLines(filepath, pSave)    //to write the data to the file
  true  // success


//
// TransformGrayscale
//
// Converts the image to grayscale and returns resulting image as a list of lists.
//

// Call a recursive function that grabs average of all 3 elements
let rec avgGray(row:int list, a:int) =
  match row with
  | [] -> []    //empty list
  | _ -> let avg = (row.Head + row.Tail.Head + row.Tail.Tail.Head)/3    //take the first 3 elements and find their average
         let listRow = List.map(fun x -> avg)row   //converts list 
         listRow@avgGray(row.Tail, a+3) //parse through row for each 3 elements

// Perform tail recursion
let rec TransformGrayRec(image:int list list) =
  match image with
  | [] -> []    //empty list
  | _ -> [avgGray(image.Head, 1)]@TransformGrayRec(image.Tail)  //perform tail recursion

// Call recursive tail in main function
let TransformGrayscale(image:int list list) =
  TransformGrayRec(image)   //call recursive function


//
// TransformInvert
//
// Invert an image's RGB values
//
// Uses the equation: 
// newValue = MaxColorDepth - currentValue
// i.e. pixel has 255 128 0, you will get 0 127 255

// recursive tail function
let rec invertRec(depth:int, row:int list) =
  match row with
  | [] -> []    //empty list
  | _ -> let transform = [depth - row.Head; depth - row.Tail.Head; depth - row.Tail.Tail.Head]  //perform equation
         transform@invertRec(depth, row.Tail.Tail.Tail)    //recursively do this for all pixels

// actual code
let rec TransformInvert(depth:int, image:int list list) = 
  match image with
  | [] -> []
  | _ -> invertRec(depth, image.Head)@TransformInvert(depth, image.Tail)

//
// TransformFlipHorizontal
//
// Flips image horizontally
//

let rec flipHorizontalRec(row:int list, a:int) = 
  match row with
  | [] -> []    //empty string
  | _ -> let reverse = List.rev[row.Head; row.Tail.Head; row.Tail.Tail.Head]    //reverse the list
         reverse@flipHorizontalRec(row.Tail, a) //reverse an arbitrary list

let rec TransformFlipHorizontalRec(image:int list list) = 
  match image with
  | [] -> []    //empty string
  | _ -> [flipHorizontalRec(image.Head, 0)]@TransformFlipHorizontalRec(image)

let rec TransformFlipHorizontal(image:int list list) =
  TransformFlipHorizontalRec(image)
  

//
// TransformFlipVertical
//
// Flips image vertically
//
let rec flipVerticalRec(cols:int list, a:int) = 
  match cols with
  | [] -> []    //empty string
  | _ -> let reverse = List.rev[cols.Head; cols.Tail.Head; cols.Tail.Tail.Head]    //reverse the list
         reverse@flipHorizontalRec(cols.Tail, a) //reverse an arbitrary list

let rec TransformVerticalRec(image:int list list) = 
  match image with
  | [] -> []    //empty string
  | _ -> [flipHorizontalRec(image.Head, 1)]@TransformFlipHorizontalRec(image)

let rec TransformFlipVertical(image:int list list) =
  TransformFlipHorizontalRec(image)


//
// << extra function here >>
//
// come up with some extra function
//