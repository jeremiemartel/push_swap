import random
import string
import os
import sys
import signal

PUSHSWAP	= "./push_swap"
CHECKER		= "./checker"

PUSHSWAP_REF	= "./push_swap"
CHECKER_REF		= "./checker"

VALGRIND_ENABLE		= False

VALGRIND_CONF_FILE	= "./.my_supp.supp"
VALGRIND_ERROR_RET	= 97
VALGRIND_LOG_DIR	= "./logs"

colours = {
	"default"    :    "\033[0m",
	# style
	"bold"       :    "\033[1m",
	"underline"  :    "\033[4m",
	"blink"      :    "\033[5m",
	"reverse"    :    "\033[7m",
	"concealed"  :    "\033[8m",
	# couleur texte
	"black"      :    "\033[30m", 
	"red"        :    "\033[31m",
	"green"      :    "\033[32m",
	"yellow"     :    "\033[33m",
	"blue"       :    "\033[34m",
	"magenta"    :    "\033[35m",
	"cyan"       :    "\033[36m",
	"white"      :    "\033[37m",
	# couleur fond
	"on_black"   :    "\033[40m", 
	"on_red"     :    "\033[41m",
	"on_green"   :    "\033[42m",
	"on_yellow"  :    "\033[43m",
	"on_blue"    :    "\033[44m",
	"on_magenta" :    "\033[45m",
	"on_cyan"    :    "\033[46m",
	"on_white"   :    "\033[47m" }
 

max_int = (2 ** 31) - 1
min_int = (2 ** 31) * -1

BUFFER_FILE			= "./buffer"
RES1_CH_FILE		= "./res1_ch"
RES2_CH_FILE		= "./res2_ch"

RES1_PS_FILE		= "./res1_ps"
RES2_PS_FILE		= "./res2_ps"

def color(nom):
	sys.stdout.write(colours[nom])

def colored_text(text, color_name):
	color(color_name)
	print(text)
	color("default")

def clean_files():
	os.system("rm -f " + RES1_CH_FILE + " " + RES2_CH_FILE)
	os.system("rm -f " + RES1_PS_FILE + " " + RES2_PS_FILE)
	os.system("rm -f " + BUFFER_FILE)

def clean_file(file):
	str = "rm -r "
	for f in file:
		str += " " + f
	os.system("rm -f " + str)

def write_log():
	path = os.path.join(VALGRIND_LOG_DIR, "log_" + test_counter.count)

def test_counter():
	test_counter.count += 1
test_counter.count = 0

def check_file_content(filename, content):
	fdr = open(filename, 'r')
	str = ""
	line = fdr.readline()
	while (line != ""):
		str += line
		line = fdr.readline()
	if (str != content):
		return (False)
	return (True)

def new_random_valid_list(lenght = 20):
	tab = []
	count = 0
	while (count < lenght):
		nbr = random.randint(-2 * lenght, 2 * lenght)
		if (not (nbr in tab)):
			tab.append(nbr)
		else :
			continue
		count += 1
	return (tab)

def list_to_str(tab):
	res = ""
	for i in range(len(tab)):
		res += str(tab[i])
		res += " "
	return (res)

## input arg : True input is not modified in shell command
##				False : input is closed
##				String : input string is used as name of a file send as an input
def launch_cmd(programm, arg, file1, file2, input=True):
	clean_file([file1, file2])
	cmd = programm
	cmd += " " + arg + " "
	redirections = " 2>" + file2 + " 1>" + file1 + " "
	if (input == False):
		redirections += " 0<&- "
	elif (input != True):
		redirections += " < " + input + " "
	cmd += redirections
	os.system(cmd)

def valgrind_initial_configuration(file=VALGRIND_CONF_FILE):
	colored_text("Valgrind Initialisation : started", "cyan")
	os.system("./.init_valgrind.sh")
	colored_text("Valgrind Initialisation : finished", "cyan")

## input arg : True input is not modified in shell command
##				False : input is closed
##				String : input string is used as name of a file send as an input
def launch_cmd_valgrind(programm, arg, file1, file2, input=True):
	if (not os.path.exists(VALGRIND_CONF_FILE)):
		valgrind_initial_configuration(VALGRIND_CONF_FILE)
	if (not os.path.exists(VALGRIND_LOG_DIR)):
		os.system("mkdir " + VALGRIND_LOG_DIR)
	test_counter()
	print(test_counter.count)
	clean_file([file1, file2])
	cmd = "valgrind --leak-check=full --suppressions=" + VALGRIND_CONF_FILE + " "
	cmd += "--error-exitcode=" + str(VALGRIND_ERROR_RET) + " "
	cmd += "--log-file=" + BUFFER_FILE + " "
	cmd += " " + programm + " "
	cmd += " " + arg + " "
	redirections = " 2>" + file2 + " 1>" + file1 + " "
	if (input == False):
		redirections += " 0<&- "
	elif (input != True):
		redirections += " < " + input + " "
	cmd += redirections
	ret = os.system(cmd)
	if (ret == VALGRIND_ERROR_RET):
		path = os.path.join(VALGRIND_LOG_DIR, "log_" + str(test_counter.count))
		colored_text("Valgrind error, find logs in " + path, "red")
		os.system("mv " + BUFFER_FILE + " " + path)

if (VALGRIND_ENABLE):
	launch_cmd = launch_cmd_valgrind

## Return code:
#	0 : Error expected on STDERR
#	1 : OK expected on STDOUT
#	2 : KO expected on STDOUT
def do_args_contain_errors(s, verbose=False):
	for f in range(len(s)):
		if (string.digits.find(s[f]) == -1 and s[f] != ' ' and s[f] != '-' and s[f] != '"'):
			if (verbose):
				print("Arguments contains invalid characters : " + s[f])
			return (0)
	tab = s.split()
	for f in range(len(tab)):
		nbr = int(tab[f])
		if (nbr > max_int or nbr < min_int):
			if (verbose):
				print("Number is too big : " + str(nbr))
			return (0)
		for ff in range(f + 1, len(tab)):
			nbrnbr = int(tab[ff])
			if (nbr == nbrnbr):
				if (verbose):
					print("Identical numbers found " + tab[f])
				return (0)
	tabtab = list(tab)
	tabtab.sort()
	if (tabtab == tab):
		if (verbose):
			print("List is sorted")
		return (1)
	else :
		if (verbose):
			print("List is NOT sorted")
		return (2)

def check_checker_result(arg, file1, file2, verbose=False):
	ret = do_args_contain_errors(arg, verbose=verbose)
	if (ret == 0):
		if (not check_file_content(file1, "OK\n") or not check_file_content(file2, "")):
			colored_text(arg, "yellow")
			do_args_contain_errors(arg, verbose=True)
			return (False)
	elif (ret == 1):
		if (not check_file_content(file1, "KO\n") or not check_file_content(file2, "")):
			colored_text(arg, "yellow")
			do_args_contain_errors(arg, verbose=True)
			return (False)
	elif (ret == 2):
		if (not check_file_content(file1, "") or not check_file_content(file2, "Error\n")):
			colored_text(arg, "yellow")
			do_args_contain_errors(arg, verbose=True)
			return (False)
	return (True)
