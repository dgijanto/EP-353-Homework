# Problem Set 1

Start Date and Time| Due Date and Time | Cut-off Date and Time |
---|---|---|
15:50:00 on September 8, 2022 | 14:00:00 on September 22, 2022 | 14:00:00 on September 29, 2022 |

\**Eastern Standard Time (EST) is used for dates and times with the 24-hour clock*

## Grading Rubric

Description|Grade
---|---:|
`HelloWorld.c` and `README.md` are submitted | 20%
All files (`HelloWorld.c` and `README.md`) have the correct names | 20%
`README.md` file is correctly formatted | 20%
Your problem set repository is accessible by the instructor without any issues | 20%
Your problem set repository has the correct file structure and naming | 20%

**Syllabus quiz is graded separately, and it will have a total of 5% of your final grade.*

## Recommended Reading 

- GitHub:
	- Go through the [GitHub Guides on Hello World](https://guides.github.com/activities/hello-world/) to set up a Git repository for the class.

	- Make sure to go through Steps 2 to 5 and understand the procedure of committing codes.

	- For a more comprehensive guide to writing on GitHub, read [Writing on GitHub](https://help.github.com/en/github/writing-on-github).

- Markdown:
	- Read [Mastering Markdown](https://guides.github.com/features/mastering-markdown/).

	- Read [Markdown Cheatsheet](https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet).

- C:
	- The C Programming Language book:
		- Chapter 0 ~ 0.4

	- The Audio Programming Book:
		- Chapter 1 ~ 1.1

- Online: 
	- [C/C++ for Visual Studio Code](https://code.visualstudio.com/docs/languages/cpp)
	- [Getting Started with Visual Studio Code](https://code.visualstudio.com/docs)
	- [Using Clang in Visual Studio Code](https://code.visualstudio.com/docs/cpp/config-clang-mac)

## Problem 1.1: Syllabus Quiz

Read the syllabus and take the syllabus quiz on OL.

## Problem 1.2: GitHub
[**GitHub**](https://github.com/) is a code hosting platform for version control and collaboration. GitHub lets you and others work together on projects from anywhere. Most importantly, we will be using GitHub to submit your problem sets and projects in this class.

Version control is a system that records changes to a file or a set of files over time so that you can recall specific versions later. Students pursuing software engineering skills must learn how to use a version control system such as **Git**. GitHub makes this procedure straightforward for us.

### Set up GitHub and Clone the Class Materials
- Go to [github.com](github.com) and create a new account. Share your GitHub user name with the instructor so that you can access the class repository. 

- Go to [desktop.github.com](desktop.github.com) and download the GitHub Desktop App. Launch GitHub Desktop. Sign in to GitHub.com with your account.

- Click on the `Clone a Repository from the Internet…` button in the GitHub Desktop app. Click on the `URL` tab and type in `github.com/EP-353/EP-353_Class_Materials`. Click on the `Clone` button and check the `~/Documents/GitHub/` directory for the cloned repository in the Finder. `~` means the home folder. On macOS, this means a folder with your user name.

### Create a New Repository for Problem Set Submission
- Let's create a new repository that you will be using to submit your problem sets and projects.

- On the GitHub Desktop app, click on the `Create a New Repository on your Hard Drive...` button. Alternatively, you can use the shortcut command cmd-N.

- Type in a name for your repository (i.e., `EP-353-ProblemSets`). Give a description and initialize the repository with a README. Click on the `Create Repository` button. You should now have a new folder inside the `~/Documents/GitHub/` directory in the Finder.

- Click on the `Publish Repository` button to reflect the local change on the GitHub server. Now, make a folder (i.e., ProblemSet1) within the new repository. Copy/paste the `README.md` file created earlier into this new folder. Changes should now appear on the left side of the GitHub Desktop app. Write a summary of your changes. Click on the `Commit to master` button and then `Push origin` to reflect your local changes to the repository.

- Each week, you will be creating a new folder within the `EP-353-ProblemSets` folder that you will be using to submit your problem sets and projects. For example, a folder with the problem set next week (Problem Set 2) should be named `ProblemSet2`.

- You should also add the instructor's GitHub user name (navreyort) in your repository for grading. Please follow the instruction [here](https://help.github.com/en/github/setting-up-and-managing-your-github-user-account/inviting-collaborators-to-a-personal-repository) on how to add collaborators.

- Ensure that the instructor has access to your GitHub repository by the due date.

## Problem 1.3: Compiling and Running C using CLI

1. Navigate to the class material folder `01.HelloWorld` -> `04.FirstLook` using the `cd` command in Terminal.
2. Make sure that the *Command Line Tools* is installed:
	
		xcode-select --install

3. Type the command `clang` to signify that we are using the [Clang Compiler](https://clang.llvm.org/). This compiler translates our C code (human-readable) into machine understandable code.

4. After `clang`, type `[nameofinputfile] -o [nameofoutputfile]`. This should look like:
	
		clang HelloWorld.c -o HelloWorld 
		
	In this command line, we named the output binary file `HelloWorld` compiled from the C file `HelloWorld.c`.

5. To Run the outputfile, type "./[nameofoutputfile]". This should look like:
 
 		./HelloWorld
	
	The `./` shortcut refers to the current directory.
	
6. In CLI, we can concatenate commands using `&&`:

		clang HelloWorld.c -o HelloWorld && ./HelloWorld

7. When running the compiled binary file, it should print `Hello, World!` to the terminal window.
8. Ensure to familiarize with compiling and running c programs as we will be doing this the entire semester.

## Problem 1.4: Markdown

- **Markdown** is an easy-to-read, easy-to-write syntax for formatting plain text. Files written in Markdown can be converted to many output formats, including HTML. The file extensions for Markdown can be `.md` or `.markdown`.

- Markdown is used to format `README.md` files on GitHub. Styling `README.md` on the GitHub platform makes it easier for us to read. The `README.md` file needs to be named exact for GitHub to recognize and format your texts in your repository.

- Your task in this problem is to write your `README.md` file. In your `README.md` file, You will describe the [HelloWorld.c](https://github.com/EP-353/EP-353_Class_Materials/blob/main/01.HelloWorld/03.FirstLook/HelloWorld.c) file that we covered in the class using plain English.

- Answer the following questions in describing the code in `HelloWorld.c`:
	1. What is the code doing?
	2. What programming elements are used in the code (e.g., comments)?
	3. What is the result of compiling and running the program?
	4. What happens if you change the text inside double quotes (`"`) within the printf function to something else?

- Your description of the code must be at least a paragraph long, and your `README.md` must at least contain:

	1. 1 Heading
	2. 1 Italic
	3. 1 Bold

- Include both `HelloWorld.c` (copy/paste from [here](https://github.com/EP-353/EP-353_Class_Materials/blob/main/01.HelloWorld/03.FirstLook/HelloWorld.c)) and `README.md` in your problem set 1 folder to get a full credit.

--- 
**EP-353: Audio Programming in C**  
Electronic Production and Design  
Berklee College of Music  