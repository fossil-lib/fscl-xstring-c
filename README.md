# TSCL XString Library - **C**

The TSCL String is a robust and efficient library designed to streamline letter and string manipulation within the C programming language. Tailored to meet the diverse needs of developers working with characters and strings, this library offers a comprehensive set of functions and utilities that simplify common operations, making code development more intuitive and productive.

At its core, the TSCL String provides a collection of meticulously crafted functions for manipulating individual characters, facilitating tasks such as character comparison, conversion, and classification. Developers can seamlessly integrate these functions into their C programs to enhance precision and control over character-based operations.

Beyond individual characters, the TSCL String excels in managing strings, offering an array of functions tailored to tasks such as concatenation, substring extraction, and length determination. Whether working with fixed-size arrays or dynamic memory allocation, this library provides a versatile set of tools to handle strings of varying complexities.

One of the key strengths of the TSCL String lies in its emphasis on efficiency and performance. By optimizing algorithms and minimizing resource consumption, developers can trust the library to deliver swift and reliable results, even when dealing with large datasets or resource-constrained environments.

In addition to its functional prowess, the TSCL String boasts a user-friendly interface, allowing programmers to seamlessly integrate its capabilities into their projects. The documentation accompanying the library serves as a comprehensive guide, offering clear explanations and examples to expedite the learning curve for developers of all experience levels.

Whether you are a seasoned C programmer or a novice exploring the language, the TSCL String stands as a valuable companion, simplifying the intricacies of character and string manipulation and contributing to the overall efficiency and elegance of your C codebase.

## Who is This For?

This guide is designed for developers of all skill levels who want to use the Meson build system for their projects. It assumes basic familiarity with command-line interfaces and project organization.

## Prerequisites

Before getting started, make sure you have the following installed:

- **Meson Build System**: This project relies on Meson. If you don't have Meson installed, visit the official [Meson website](https://mesonbuild.com/Getting-meson.html) for installation instructions.

## Setting up Meson Build

1. **Install Meson**:
   - Follow the installation instructions on the [Meson website](https://mesonbuild.com/Getting-meson.html) for your operating system.

## Setting up, Compiling, Installing, and Running the Project

1. **Create a Wrap File**:

Create a directory named subprojects in the root directory, next create a file named `tscl-xstring-c.wrap` in the `subprojects` directory of your project with the following content:

   ```bash
   # ================ #
   #  TSCL Wrap File. #
   # ================ #
   [wrap-git]
   url = https://github.com/trilobite-stdlib/tscl-xstring-c.git
   revision = main
   
   [provide]
   tscl-xstring-c = tscl_xstring_c_dep
   ```

2. **Integrate Wrap File in Meson Build**:
   ```meson
   project('my_project', 'c',
       version : '0.1',
       default_options : ['warning_level=3'])

   exe = executable('my_project', 'my_project.c',
       dependencies : dependency('tscl-xstring-c'), # add this line
       install : true)

   test('basic', exe)
   ```

3. **Compile the Project**:
   ```bash
   meson setup builddir
   meson compile -C builddir
   ```

4. **Visit the reference guide to learn how to this**

Here is the link to the [Refrence Docs](https://trilobite.home.blog/reference-docs/)

## Including the Demo and Running Tests

To include the demo and run tests, you can use the following options when configuring the build:

- **Including the Demo**: Add `-Dwith_demo=enabled` when configuring the build.
- **Running Tests**: Add `-Dwith_test=enabled` when configuring the build.

Example:

```bash
meson setup builddir -Dwith_demo=enabled -Dwith_test=enabled
```

## Contributing

If you're interested in contributing to this project, please consider opening pull requests or creating issues on the [GitHub repository](https://github.com/dreamer-coding-555/meson-lib-c). Be sure to read the documentation on the [project website](https://trilobite.home.blog).

## Feedback and Support

If you encounter any issues, have questions, or would like to provide feedback, don't hesitate to open an issue on the [GitHub repository](https://github.com/dreamer-coding-555/meson-lib-c/issues).

## License

This project is licensed under the [Apache License 2.0](LICENSE).

---

Thank you for choosing this project with the Meson build system. Happy coding and building amazing projects!

## Contact

If you have questions or want to get in touch regarding programming solutions, you can find a way to contact me on my [website](https://trilobite.code.blog/contact/).
