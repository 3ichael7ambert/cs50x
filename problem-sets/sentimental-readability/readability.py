from cs50 import get_string
import re

def main():
    # Prompt user for input text
    text = get_string("Text: ")

    # Initialize counts
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    # Calculate L and S
    L = (letters / words) * 100
    S = (sentences / words) * 100

    # Coleman-Liau index formula
    index = 0.0588 * L - 0.296 * S - 15.8

    # Determine grade level
    grade = round(index)

    # Output the grade level
    if grade >= 16:
        print("Grade 16+")
    elif grade < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {grade}")

def count_letters(text):
    # Count letters (a to z and A to Z)
    return len([char for char in text if char.isalpha()])

def count_words(text):
    # Count words by splitting text at spaces
    return len(text.split())

def count_sentences(text):
    # Count sentences by counting ., !, ?
    return len(re.findall(r'[.!?]', text))

if __name__ == "__main__":
    main()
