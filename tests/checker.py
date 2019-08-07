#!/usr/bin/python3

from include import *

def check_empty_list(checker=CHECKER):
	launch_cmd(checker, "", RES1_CH_FILE, RES2_CH_FILE, False)
	if (not check_file_content(RES2_CH_FILE, "") or not check_file_content(RES1_CH_FILE, "")):
		return (False)
	return (True)

def check_sorted_list(start=1, max_lenght=200, repetition=3, step=2):
	for f in range(start, max_lenght, step):
		for g in range(repetition):
			tab = new_random_valid_list(f)
			tab.sort()
			arg = ""
			for i in range(len(tab)):
				arg += " " + str(tab[i])
			launch_cmd(CHECKER, arg, RES1_CH_FILE, RES2_CH_FILE, False)
			if (check_file_content(RES1_CH_FILE, "OK\n") == False):
				colored_text(arg, "yellow")
				return (False)
	return (True)

def check_not_sorted_list(start=2, max_lenght=200, repetition=3, step=2):
	for f in range(start, max_lenght, step):
		for g in range(repetition):
			if (f <= 3):
				continue
			tab = new_random_valid_list(lenght=f)
			tabtab = list(tab)
			tabtab.sort()
			while (tab == tabtab):
				random.shuffle(tab)
				tabtab = list(tab)
				tabtab.sort()
			arg = ""
			for count in range(len(tab)):
				arg += " " + str(tab[count])
			launch_cmd(CHECKER, arg, RES1_CH_FILE, RES2_CH_FILE, False)
			if (check_file_content(RES1_CH_FILE, "KO\n") == False):
				colored_text(arg, "yellow")
				return (False)
	return (True)

def new_invalid_arg(charset, length=1):
	if (length == 0):
		return ("")
	str = ""
	for l in range(length):
		char = random.choice(charset)
		str += char
	return (str)


def new_randomly_bad_input(charset, lenght=20,invalid_lenght=2):
	list = new_random_valid_list(lenght)
	random_index = random.randint(0, len(list))
	arg = ""
	for f in range (len(list)):
		arg += " " + str(list[f])
		if (f == random_index):
			arg += " " + new_invalid_arg(charset, invalid_lenght) + " "
	return (arg)


def check_random_input(charset,start_len=1, max_len=10, repetition=3):
	for l in range(start_len, max_len):
		for rep in range(repetition):
			arg = new_randomly_bad_input(charset, invalid_lenght=l)
			launch_cmd(CHECKER, arg, RES1_CH_FILE, RES2_CH_FILE, False)
			if (check_checker_result(arg, RES1_CH_FILE, RES2_CH_FILE) == False):
				return (False)
	return (True)



def show_check_result(res, test_name):
	if (res == True):
		colored_text(test_name + " : [OK]\n", "green")
	else :
		colored_text(test_name + " : [KO]\n", "red")


def check_checker(checker=CHECKER, checker_ref=CHECKER_REF):
	colored_text("Checker tests :", "blue")

	show_check_result(check_empty_list(), "Empty list")

	show_check_result(check_sorted_list(start=1, max_lenght=10, repetition=4, step=1), "Sorted list 1")
	show_check_result(check_sorted_list(start=10, max_lenght=200, repetition=2, step=4), "Sorted list 2")

	show_check_result(check_not_sorted_list(start=3, max_lenght=10, repetition=4, step=1), "Not Sorted list 1")
	show_check_result(check_not_sorted_list(start=10, max_lenght=200, repetition=2, step=4), "Not Sorted list 2")

	charset = string.ascii_letters
	show_check_result(check_random_input(charset=charset, start_len=1, max_len=20, repetition=5), "Random Input 1")
	charset = string.hexdigits
	show_check_result(check_random_input(charset=charset, start_len=1, max_len=20, repetition=5), "Random Input 2")
	charset = string.hexdigits + string.ascii_letters
	show_check_result(check_random_input(charset=charset, start_len=1, max_len=20, repetition=5), "Random Input 3")
	charset = string.ascii_letters + "   "
	show_check_result(check_random_input(charset=charset, start_len=1, max_len=20, repetition=5), "Random Input 4")
	charset = string.ascii_letters + string.digits + "      "
	show_check_result(check_random_input(charset=charset, start_len=1, max_len=20, repetition=5), "Random Input 5")


check_checker()
