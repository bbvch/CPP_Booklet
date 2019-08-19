import glob
import os
import argparse

parser = argparse.ArgumentParser(description="Split *.cc files in examples by searching for //@")
parser.add_argument('--sourcedir', '-s', dest="source_dir", help='source directory containing the .cc files', required=True)
parser.add_argument('--targetdir', '-t' , dest='target_dir', help="target directory for the split examples", required=True)
args = parser.parse_args()


if not os.path.exists(args.target_dir):
    os.makedirs(args.target_dir)

num_examples = 0
example_files = []

for f in glob.glob(os.path.join(args.source_dir + "/*.cc")):
    f_in = open(f)

    lines = f_in.readlines()
    examples = {}
    current_example = None
    for l in lines:

        if l.startswith("//@"):
            prefix, num = l.strip().split('@')
            if current_example is not None and num != current_example:
                print("Error: Previous example did not end")
            elif current_example is None:
                current_example = num
                if current_example not in examples:
                    examples[current_example] = []
                    num_examples += 1
            elif current_example == num:  # end
                current_example = None
            else:
                print("I forgot to implement something")
        elif current_example is not None:
            # filter out non-compilation warnings
            if not l.startswith("#ifdef") and not l.startswith("#endif"):
                examples[current_example].append(l)

    f_in.close()
    if len(examples) > 0:
        for k in examples:
            bname = os.path.basename(f)
            filename = "examples/example_" + str(k) + "_chapter_" + bname
            example_files.append(filename)
            f_out = open(filename, 'w+')
            f_out.writelines(examples[k])
            f_out.close()

print("split examples into " + str(num_examples) + " files")
# print example_files
