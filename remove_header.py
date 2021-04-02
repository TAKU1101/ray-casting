import sys

def remove_header(filename):
    with open(filename, mode="r") as f:
        text = f.read()
    if text[:80] == "/* ************************************************************************** */":
        with open(filename, mode="w") as f:
            f.write(text[892:])
    else:
        print(filename + " is not header")

if __name__ == "__main__":
    for filename in sys.argv[1:]:
        remove_header(filename)