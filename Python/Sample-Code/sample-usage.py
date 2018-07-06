#!/usr/bin/python

import sys, getopt

def main(argv)
  inputfile = ''
  outputfile = ''
  try:
    opts, args = getopt.getopt(argv,"hi:o:",["ifile="])
  except getopt.GetoptError:
    print 'sample-usage.py  -i <inputfile> -o <outputfile>'
    sys.exit(2)
  for opt, arg in opts:
    if opt == '-h':
      print 'sample-usage.py -i <inputfile> -o <outputfile>'
      sys.exit()
    elif opt in ("-i", "--ifile"):
      inputfile = arg
    elif opt in ("-o", "--ofile"):
    outputfile = arg
  print 'Input file is "', inputfile, '\"'
  print 'Output file is"', outputfile, '\"'

if __name__ == "__main__":
  main(sys.argv[1:])

# OUTPUT:

# $ sample-usage.py -h
#   usage: sample-usage -i <inputfile> -o <outputfile>

# $ sample-usage.py -i BMP -o
#   usage: sample-usage.py -i <inputfile> -o <outputfile>

# $ sample-usage.py -i inputfile
#   Input file is "inputfile"
#   Output file is ""
