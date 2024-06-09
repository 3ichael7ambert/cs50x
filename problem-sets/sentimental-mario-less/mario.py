def get_height():
    while True:
        try:
            # Prompt the user for the height of the pyramid
            height = int(input("Height: "))
            if 1 <= height <= 8:
                return height
        except ValueError:
            pass  # If input is not an integer, continue prompting

def print_pyramid(height):
    for i in range(1, height + 1):
        # Print spaces
        print(" " * (height - i), end="")
        # Print hashes
        print("#" * i)

def main():
    height = get_height()
    print_pyramid(height)

if __name__ == "__main__":
    main()
