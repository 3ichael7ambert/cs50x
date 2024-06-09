import csv
import sys

def main():
    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # Read database file into a variable
    database_filename = sys.argv[1]
    dna_sequence_filename = sys.argv[2]

    with open(database_filename, newline='') as database_file:
        reader = csv.DictReader(database_file)
        database = list(reader)
        str_names = reader.fieldnames[1:]  # Get the STR names (excluding 'name')

    # Read DNA sequence file into a variable
    with open(dna_sequence_filename) as dna_file:
        dna_sequence = dna_file.read()

    # Find longest match of each STR in DNA sequence
    str_counts = {str_name: longest_match(dna_sequence, str_name) for str_name in str_names}

    # Check database for matching profiles
    for person in database:
        if all(str_counts[str_name] == int(person[str_name]) for str_name in str_names):
            print(person['name'])
            return

    print("No match")

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        while True:
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    return longest_run

if __name__ == "__main__":
    main()
