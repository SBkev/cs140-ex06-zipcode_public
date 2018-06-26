## Exercise: Zipcode (20 Points)

The objective of this project is to learn how to implement operators for C++ classes
and use input and output streams.

The first thing you will need to do is fork and clone this assignment
from GitHub. Follow the instructions
[here](https://github.com/sbcc-cs140-fall2018/HowToStartEveryProject)
to get started.

Be sure that you fork the project first and use the URL from
the forked project when you clone it in CLion.

### Requirements of this project

This project is based on the programming assignment #2 from Chapter 8. In 
it you will create a class called Complex (in the namespace `edu::sbcc::cs140`)
based on the mathematical understanding of the imaginary numbers. Imaginary numbers
are made up of two components, a real part and an imaginary part. The imaginary
part is a constant times the square root of -1.

This class has two constructors (or one with a default parameter). The first
constructor takes two parameters, both of type `double`, representing the real
and imaginary parts of a complex number respectively. The second takes a single
`double` parameter representing the real part of an imaginary number (the 
imaginary part is then 0).

This class also has two accessor methods, getRealPart and getImaginaryPart, to
return the individual components of the complex number. Be sure to use proper
*constness* for these methods.

Finally, this class defines several operators. Specifically you must implement +, -, 
*, ==, !=, << and >>. You don't need to implement the = operator (do you understand
why?). These operators should be external to the class, though still in the `edu.sbcc.cs140` 
namespace, and also be declared as friend methods. Also, as in the original assignment
you should declare a constant `i` within Complex that has the form `(0, 1)`.

You are free to add any private helper methods you need, but are not required to do so.

For the << and >> methods see the formatting specification below to make sure you
can pass all the unit test included with this project.

### << Formatting

When outputting a Complex instance to a stream, the output should be of the form [[-]d[.d]][ {+,-} d[.d]]. 
Below are a few examples of how Complex numbers should look after calling your `<<` operator 
implementation:

1. -1 + i
2. 2.1 - 1.1i
3. -1
4. -i

Notice in the first example that there is no space between the `-` and the `1` for the real
term, but there is for the operator between the real and imaginary parts. Also notice that 
when either the real or imaginary parts are zero, no term is added to the output. In the 
fourth case, notice that there is not space between the `-` operator and the `i`.

### >> Formatting

The formatting for input is more flexible with regards to space. That being said, your 
implementation of the `>>` operator should handle any of the formats above, with or without
all the spaces. In addition, your code should be able to handle improperly formatted 
input. By handle, I mean not crash and not update the real or imaginary parts unless the
format is correct.
 
### Writing the code for this Project

There are only three requirements for creating the code for this project correctly. One,
be sure that you create a class named `Complex` in the namespace `edu::sbcc::cs140` with
the give interface from above. Two, you can put your implementation in a file with the 
name of your choice as long as it uses the `.cc` extension, and is in the `src` directory.
Three, you can put you class definition in a file with the name of your choice as long as 
it uses the `.h` extension, and is in the `include` directory.

#### All files must have the header comment

Be sure to add the proper header comment to each `.cc` and `.h` file you add to this project.

### Testing the code for this project

Testing the code for this project is similar to running your code
as outlined above. In the drop-down menu in the upper right-hand
corner select the configuration `ComplexNumbers_Gtest` and press the
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
Your unit test score is 22 out of 20 (2)
The assignment is worth a total of 25 where the remaining points
comes from grading related to documentation, algorithms, and other
criteria.

[----------] 6 tests from ZipcodeTest (0 ms total)

[----------] Global test environment tear-down
[==========] 6 tests from 1 test case ran. (0 ms total)
[  PASSED  ] 6 tests.

Process finished with exit code 0
```

Remember, red good, green bad. If your tests pass you should see green
text and your code ran fine. You should also see your score for this
assignment minus code styling points which I will add later.

### Submitting the code for this project

At the bottom of CLion there should be a view tab labeled **Version Control**.
Select this tab at the bottom of the screen. You should see a tab called **Local Changes**.
Under **Unversion Files** you should have two files: `helloworld.cc` and `helloworld.h`.
Select these files and right-click on them. In the drop-down menu
select **Add to VCS**. Next, right-click on these files again, which should
now be under **Default** and select **Commit**. Add the appropriate
commit message and click **OK**. Finally, right click on the committed files,
select `Git -> Repository -> Push...`. Follow the onscreen directions
and press **OK**. This step will run the tests again, check that everything is OK
and then submit them to the cloud to have the tests run for grading.

If you do not understand these directions, or wish to do them on the command
line rather than in CLion, then read these [directions](https://github.com/sbcc-cs140-fall2018/HowToSubmitEveryProject).