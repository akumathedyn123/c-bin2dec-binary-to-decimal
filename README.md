## Binary to Decimal Converter

This project implements a C program that converts binary numbers to their decimal equivalents. It efficiently handles both positive and negative binary numbers.

**Author:** Md. N e H Jack (akumathedyn123)
**License:** MIT

**Editable (Optional):**

* Feel free to modify the maximum binary string length (`#define MAX_BIN_STR_LEN 32`) within the `main.c` file if needed.

**Main File:** main.c

**How the Code Works:**

1. **Header Inclusions:**
   - `<stdio.h>`: Provides standard input/output functions like `printf` and `scanf`.
   - `<math.h>`: Offers mathematical functions like `pow` for calculating exponents.
   - `<string.h>`: Includes string manipulation functions like `strlen` and `strcpy`.

2. **`bin2dec` Function:**
   - Takes a binary string (`bin_str`) and a pointer to an integer (`neg_position`) to store the first digit's position (for negative numbers).
   - Handles potential errors:
     - Returns `-1` if the input contains invalid characters other than '0' and '1'.
   - Otherwise, converts the binary string to decimal:
     - Iterates through the string in reverse order.
     - Calculates the decimal equivalent of each binary digit using `(bin_str[j] - '0') * pow(2, i)`.
     - Updates the power of 2 (`i`) for each position.
   - Stores the first digit's position in `neg_position` (useful for calculating negative numbers).
   - Returns the converted decimal value.

3. **`main` Function:**
   - Declares variables:
     - `bin_str`: To store the user's binary input (maximum length defined by `MAX_BIN_STR_LEN`).
     - `is_neg_str`: To hold the user's response regarding a negative number (y/n).
     - `is_negative`: A flag to indicate if the input is negative.
     - `dec`: To store the converted decimal value.
     - `neg_binary`: To hold the calculated negative decimal (if applicable).
     - `neg_position`: Retrieved from `bin2dec`.
   - Prompts the user to enter a binary number and reads it into `bin_str`.
   - Validates the input:
     - Checks if each character is '0' or '1'. If not, prints an error message and exits.
   - Handles negative numbers:
     - If the first digit is '1', prompts the user to confirm if it's negative.
     - If the user confirms, sets `is_negative` to true.
   - Processes the binary number based on negativity:
     - **Positive:** Calls `bin2dec` to directly convert the binary string to decimal, printing the result.
     - **Negative:**
       - Extracts the positive part (without the leading '1') into `positive_part`.
       - Calls `bin2dec` to convert the positive part, storing the result in `dec`.
       - Calculates the negative decimal as `neg_binary = dec - pow(2, neg_position)`.
       - Prints the negative decimal equivalent.

**Running the Project**

1. **Clone the Repository (if applicable):**
   ```bash
   git clone https://your_repository_url.git
   cd Binary-to-Decimal-Converter
   ```

2. **Compile the Code:**
   **Linux/macOS (GCC):**
   ```bash
   gcc main.c -o binary_to_decimal
   ```
   **Windows (MinGW):**
   ```bash
   g++ main.c -o binary_to_decimal -lm
   ```
   **Windows (Clang):**
   ```bash
   clang main.c -o binary_to_decimal -lm
   ```

3. **Run the Program:**
   ```bash
   ./binary_to_decimal
   ```

**Example Usage:**

```
Enter a binary number: 101
Is the binary number negative? (y/n): n
The decimal equivalent: 5

Enter a binary number: 0101
The decimal equivalent: 5

Enter a binary number: 110
Is the binary number negative? (y/n): y
The decimal equivalent (negative): -2
```

## Additional Notes

### Error Handling and Robustness
* Consider adding more robust error handling for invalid inputs, such as empty strings or strings with characters other than '0' and '1'.
* Implement input validation to ensure the binary string length is within a reasonable range.

### Code Optimization
* For large binary numbers, explore alternative approaches like bitwise operations or lookup tables for potential performance improvements.

### Code Readability
* Add comments to explain the purpose of different code sections and variable names for better understanding.
* Consider using meaningful variable names to enhance code clarity.

### Functionality Expansion
* Extend the program to handle different number bases (e.g., octal, hexadecimal).
* Implement conversion from decimal to binary.
* Add support for floating-point binary numbers.


## Contribution

**We welcome contributions to improve this project!**

If you'd like to contribute, here's what you can do:

* **Report issues:** If you encounter any bugs or unexpected behavior, please open an issue on the project's issue tracker.
* **Suggest features:** If you have ideas for new features or improvements, feel free to open a feature request.
* **Submit pull requests:** If you have code changes or bug fixes, submit a pull request. Please follow the code style and formatting guidelines.

### Contributing Guidelines

* Fork the repository.
* Create a new branch for your feature or bug fix.
* Commit your changes with clear and concise commit messages.
* Push your changes to your fork.
* Submit a pull request to the main repository.

We appreciate your contributions to making this project better!

**Note:** For larger contributions or significant code changes, it's recommended to open an issue to discuss the proposed changes before starting work. Cheers guys.
