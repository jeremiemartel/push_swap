#!/usr/bin/python3

from include import *

def check_performance_show_note(moy, notes, min, max):
	note = len(notes)
	i = 0
	while (note > 0 and notes[i] < moy):
		i += 1
		note -= 1
	if (i >= len(notes)):
		i = len(notes) - 1
	colored_text("max tolerated value : " + str(notes[i]), "cyan")
	if (max > notes[len(notes) - 1]):
		colored_text("note : [KO]", "red")
		return
	if (moy > notes[len(notes) - 1]):
		colored_text("note : [KO]", "red")
	elif (note == len(notes) and len(notes) == 1):
		colored_text("note : [OK]", "green")
	elif (note == len(notes)):
		colored_text("note : " + str(note), "green")
	else :
		colored_text("note : " + str(note), "yellow")
		
def check_performance_check_valid_result (file_ps_1=RES1_PS_FILE, file_ps_2=RES2_PS_FILE, file_ch_1=RES1_CH_FILE, file_ch_2=RES2_CH_FILE):
	if (check_file_content(file_ch_2, "") == False):
		colored_text("Bad programm output : see " + file_ch_2, "red")
		return (False)
	elif (check_file_content(file_ch_1, "OK\n") == False):
		colored_text("Bad programm output : see " + file_ch_1, "red")
		return (False)
		colored_text("Bad programm output : see " + file_ps_2, "red")
	elif (check_file_content(file_ps_2, "") == False):
		return (False)
	return (True)

def	check_performance_get_score(filename=RES1_PS_FILE):
	fdr = open(filename, 'r')
	line = fdr.readline()
	count = 0
	while (line != ""):
		count += 1
		line = fdr.readline()
	return (count)

def check_performance_sorted(max_lenght, repeat=30, notes=None):
	colored_text("Sorted test : " +  str(max_lenght) + " max len", "magenta")
	sum = 0
	ret = None
	for rep in range(repeat):
		arg = new_random_valid_list(lenght=max_lenght)
		arg.sort()
		arg = list_to_str(arg)
		while (do_args_contain_errors(arg) != 1):
			arg = new_random_valid_list(lenght=max_lenght)
			arg.sort()
			arg = list_to_str(arg)
		launch_cmd(PUSHSWAP, arg, RES1_PS_FILE, RES2_PS_FILE, True)
		launch_cmd(CHECKER, arg, RES1_CH_FILE, RES2_CH_FILE, RES1_PS_FILE)
		if (check_performance_check_valid_result() == False):
			colored_text(str(arg), "yellow")
			return (False)
		ret = check_performance_get_score()
		if (rep == 0):
			max_val, min_val = ret, ret
		else :
			max_val = max(max_val, ret)
			min_val = min(min_val, ret)
		sum += ret
	moy = int(sum / repeat)
	colored_text("Final result   : " + str(moy), "green")
	colored_text("Maximum result : " + str(max_val), "green")
	if (notes != None):
		check_performance_show_note(moy, notes, max_val, min_val)
	print("")
	return (moy)

def check_performance_random(lenght, repeat=30, notes=None):
	colored_text("Performance test : " +  str(lenght) + " len", "magenta")
	sum = 0
	ret = None
	for rep in range(repeat):
		arg =list_to_str (new_random_valid_list(lenght=lenght))
		while (do_args_contain_errors(arg) != 2):
			arg = list_to_str(new_random_valid_list(lenght=lenght))
		launch_cmd(PUSHSWAP, arg, RES1_PS_FILE, RES2_PS_FILE, True)
		launch_cmd(CHECKER, arg, RES1_CH_FILE, RES2_CH_FILE, RES1_PS_FILE)
		if (check_performance_check_valid_result() == False):
			colored_text(str(arg), "yellow")
			return (False)
		ret = check_performance_get_score()
		if (rep == 0):
			max_val, min_val = ret, ret
		else :
			max_val = max(max_val, ret)
			min_val = min(min_val, ret)
		sum += ret
	moy = int(sum / repeat)
	colored_text("Final result   : " + str(moy), "green")
	colored_text("Maximum result : " + str(max_val), "green")
	if (notes != None):
		check_performance_show_note(moy, notes, max_val, min_val)
	print("")
	return (moy)

check_performance_sorted(7, 10, [0])

check_performance_random(5, 20, [12])

check_performance_random(100, 30, [700, 900, 1100, 1300, 1500])
check_performance_random(500, 20, [5500, 7000, 8500, 10000, 11500])
