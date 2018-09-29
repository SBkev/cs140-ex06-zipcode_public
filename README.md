## Exercise: Zipcode (20 Points)

The objective of this project is to learn about constructors:
how they're used, and how that are implemented.

The first thing you will need to do is fork and clone this assignment
from GitHub. Follow the instructions
[here](https://github.com/sbcc-cs140-fall2018/Course-Information/wiki)
to get started.

Be sure that you fork the project first and use the URL from
the forked project when you clone it in CLion.

### Requirements of this project

This project is based on the programming assignment #9 from Chapter 7. In 
it you will create a class called Zipcode (in the namespace `edu::sbcc::cs140`)
based on the POSTNET encoding of zipcodes as barcodes.

This class has two constructors, one that takes an integer, and one that takes a string.
The constructor that takes an integer(specifically `uint32_t`) takes the integer to
be a zipcode. For example, 93117. The constructor that takes a string takes the string
to be a barcode representation of the zipcode, as described in the book (for example `"010100001100001100011000110"`).

In addition to the constructors, the Zipcode class should also include two methods, `getZipcode`
, which returns the zipcode as an integer, and `getBarcode` which returns a string that represents
the barcode, encoded using POSTNET, as described in the book. Neither function takes any input
parameters. Be sure that these functions declare these methods with the proper *const-correctness*.

### Magic Numbers

*Magic Numbers* are the use of raw literal constants in the code. The problem with these types of
values is that they are not very readable, and are hard to change everywhere they are used. You
can imagine that if you use the number 5 throughout the code and need to change it to 6, this change
can be quite difficult. Which 5's do you change? All of them? Some of them? 

Readability is another issue. What does the number 5 represent? Using well named constants addresses
both of these issues. In this project, be sure to use constants to represent repeating literals 
through out your code. For example, rather than writing the following code to convert the sum 11 to 0,
as described in the write up for this assignment in the book:

```cpp
if (sum == 11) {
  sum = 0;
}
```

You could define a constant with in the `Zipcode` class that is more readable, and more easily changed
if used in multiple places in the code.

```cpp
if (sum == ZERO_SUM) {
  sum = 0;
}
```

Now, in order to create this constant, you must declare it in the `.h` header file, and define it
in the `.cc` file. For example, `zipcode.h` might have the following code:

```cpp
class Zipcode {
private:
  static const uint8_t ZERO_SUM;
  ... // The rest of the declaration follows
}
```

Then in `zipcode.cc` you would define its value, like this:

```cpp
const uint8_t Zipcode::ZERO_SUM = 11;
```

That code can go anywhere in the `.cc` file. 

Do the same for other numeric constants, and strings. I will assign extra points for avoiding the
use of magic numbers in your code for this assignment, and will begin to deduct points for using
magic numbers in future code. 

Notice in the above code, that I did not create a constant for zero in the code: 

```cpp
  sum = 0;
```

That's because 0, in this case, is not a magic number. A good rule of thumb is, that if you would
name the constant the same as the value, then it's not a magic number. Therefore, in this case a good
name for the the literal `0` is `ZERO`. In this case it's not necessary to define a constant. If 
you're not sure, error on the side of creating a constant. I will not deduct points for using too
many constants, but I will deduct points for using too few.

### Writing the code for this Project

There are only three requirements for creating the code for this project correctly. One,
be sure that you create a class named `Zipcode` in the namespace `edu::sbcc::cs140` with
the give interface from above. Two, you can put your implementation in a file with the 
name of your choice as long as it uses the `.cc` extension, and is in the `src` directory.
Three, you can put you class definition in a file called, exactly, `zipcode.h`, in the `include` directory.

#### All files must have the header comment

Be sure to add the proper header comment to each `.cc` and `.h` file you add to this project.

### Running the code for this project

Running this code should be straightforward. In the drop-down 
menu in the upper right-hand corner you should see a *Run
Configuration* called `Zipcode | Debug`. Make sure this 
configuration is selected and press the play button next to it.
In the **Run** view below the code you should see the output 
of running the program. It should look something like this:

```bash
93103
110100001100001111000001101

Process finished with exit code 0
```
Success! Now you can move on to testing your code.

### Testing the code for this project

Testing the code for this project is similar to running your code
as outlined above. In the drop-down menu in the upper right-hand
corner select the configuration `Zipcode_Gtest` and press the
play button next to it. In the **Run** view below the code you should
see the output of running these tests. It should look something
like this:

```bash
Running main() from gtest_main.cc
[==========] Running 6 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 6 tests from ZipcodeTest
[ RUN      ] ZipcodeTest.Constructors
[       OK ] ZipcodeTest.Constructors (0 ms)
[ RUN      ] ZipcodeTest.EndsWithZero
[       OK ] ZipcodeTest.EndsWithZero (0 ms)
[ RUN      ] ZipcodeTest.AllZeroes
[       OK ] ZipcodeTest.AllZeroes (0 ms)
[ RUN      ] ZipcodeTest.EmptyBarcodeFormat
[       OK ] ZipcodeTest.EmptyBarcodeFormat (0 ms)
[ RUN      ] ZipcodeTest.UnderflowFormat
[       OK ] ZipcodeTest.UnderflowFormat (0 ms)
[ RUN      ] ZipcodeTest.OnesNotAtStartAndEndFormat
[       OK ] ZipcodeTest.OnesNotAtStartAndEndFormat (0 ms)
Your unit test score is 20 out of 20 (0)
The assignment is worth a total of 25 where the remaining points
comes from grading related to documentation, algorithms, and other
criteria.

[----------] 6 tests from ZipcodeTest (0 ms total)

[----------] Global test environment tear-down
[==========] 6 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 6 tests.

Process finished with exit code 0
```

You should also see your score for this
assignment minus code styling points which I will add later.

### Submitting the code for this project

First, right click on the project name, then select `Git -> Commit Directory...`. 
Make sure only the files you want to push are selected, `main.cc` `zipcode.cc` (or whatever you called it) and `zipcode.h`.
Then uncheck `Perform code analysis` and `Check TODO`. It's OK to leave them checked,
but committing will take longer. Leave `Run git hooks` checked. Put a message in `Commit Message`
and then press the **Commit** button. If anything goes wrong check the _Version Control_ view
in the lower left corner and select the _Console_ tab.
 
Finally, right click on the project name,
then select `Git -> Repository -> Push...`. Follow the onscreen directions
and press **OK**. This step will run the tests again, check that everything is OK
and then submit them to the cloud to have the tests run for grading.

If you do not understand these directions, or wish to do them on the command
line rather than in CLion, then read these [directions](https://github.com/sbcc-cs140-fall2018/Course-Information/wiki/How-to-Turn-In-Every-Project).
