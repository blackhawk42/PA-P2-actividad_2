import sys
import getopt

def print_help():
    print("use: {} [-w|u] FILE [FILE..]".format(sys.argv[0]), file=sys.stderr)
    print("use: {} -h".format(sys.argv[0]), file=sys.stderr)
    print("Change line endings from Unix (\\n) to Windows style (\\r\\n) and viceversa", file=sys.stderr)
    print("\t-w, -u\tRespectively, convert to Windows or Unix line ends. Default is to convert to Windows-style endings.", file=sys.stderr)


def unix2windows(data):
    if data.find(b'\r\n') >= 0:
        return data
    else:
        return data.replace(b'\n', b'\r\n')


def windows2unix(data):
    if data.find(b'\r\n') >= 0:
        return data.replace(b'\r\n', b'\n')
    else:
        return data

if __name__ == "__main__":
    try:
        opts, args = getopt.gnu_getopt(sys.argv[1:], "wuh")

    except getopt.GetoptError as err:
        print(err, file=sys.stderr)
        print_help()
        sys.exit(2)


    if len(args) == 0:
        print_help()
        sys.exit(0)

    replace_func = unix2windows
    for o, a in opts:
        if o == "-w":
            replace_func = unix2windows

        elif o == "-u":
            replace_func = windows2unix

        elif o == "-h":
            print_help()
            sys.exit(0)

        else:
            print("option not recognised: {}".format(o))
            print_help()
            sys.exit(2)

    data = None

    for filename in args:
        with open(filename, "rb") as f:
            data = replace_func(f.read())

        with open(filename, "wb") as f:
            f.write(data)


        