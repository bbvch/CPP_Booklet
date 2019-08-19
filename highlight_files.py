import glob
import os
import argparse
import pygments
import pygments.lexers
import pygments.formatters
import pygments.styles

parser = argparse.ArgumentParser(description="Split *.cc files in examples by searching for //@")
parser.add_argument('--sourcedir', '-s', dest="source_dir", help='source directory containing the .cc files', required=True)
parser.add_argument('--targetdir', '-t' , dest='target_dir', help="target directory for the split examples", required=True)
args = parser.parse_args()


if not os.path.exists(args.target_dir):
    os.makedirs(args.target_dir)

# use the command below to print all available styles
# styles = list(pygments.styles.get_all_styles())
# print(styles)

example_files = []
lexer = pygments.lexers.get_lexer_by_name("cpp")
formatter = pygments.formatters.HtmlFormatter(full=True, style=pygments.styles.get_style_by_name('friendly'))

# use the line below to get the css
# print(formatter.get_style_defs('.highlight'))

num_files = 0
for f in glob.glob(os.path.join(args.source_dir + "/*.cc")):
  in_file = open(f, 'r')
  filename = os.path.basename(f)

  out_file = open(os.path.join(args.target_dir, filename + ".html"), 'w')
  fmt = pygments.highlight(in_file.read(), lexer, formatter, out_file)
  in_file.close()
  out_file.close()
  num_files += 1
  
print("Highlighted " + str(num_files) + " files into " + str(args.target_dir))