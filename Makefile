CC = gcc
CFLAGS = -std=c18 -Wall -Wextra -O0 -g
LDLIBS = -lm

TARGETS = \
	adding_big_numbers \
	alphabet_position \
	array_exchange \
	base64 \
	base64_numeric_translator \
	big_integer_modulo \
	blackjack_scorer \
	bonus_time \
	categorize_new_member \
	clockwise_spiral \
	common_denominators \
	count_codepoints \
	counting_change_combinations \
	count_ip_addresses \
	cuboids_volumes_difference \
	decode_morse \
	decode_roman \
	determinant \
	directions_reduction \
	divide_number_strings \
	escape_the_maze \
	eval_math_expression \
	evaporator \
	factorial_decomposition \
	factorial_trailing_zeros \
	fibonacci_squares_perimeter \
	find_date \
	find_the_odd_int \
	format_duration \
	get_count \
	get_the_vowels \
	grab_csv_columns \
	greed_is_good \
	hex_string_to_rgb \
	high_and_low \
	human_readable_time \
	integer_sqrt \
	int32_to_ipv4 \
	irreducible_sum_of_rationals \
	is_anagram \
	is_ordered \
	is_valid_ip \
	is_valid_ISBN_10 \
	josephus_permutation \
	josephus_survivor \
	land_perimeter \
	large_factorials \
	last_digit_of_large_number \
	least_common_multiple \
	letters_to_numbers \
	longest \
	make_spiral \
	maximum_subarray_sum \
	mean_square_error \
	merged_string_checker \
	move_zeros \
	multiples_of_3_or_5 \
	multply_number_strings \
	my_strtok \
	next_bigger_number \
	non_even_substrings \
	not_very_secure \
	number_proper_fractions \
	ocr \
	ordered_set \
	order_words \
	parseint-reloaded \
	prime_factor_decomposition \
	prime_time \
	product_consecutive_fibnum \
	range_extraction \
	rational_arithmetic \
	rectangle_rotation \
	rgb_to_hex \
	roman_num_encoder \
	roman_num_helper \
	rot13 \
	rotate \
	run_length_encoding \
	scramble \
	simple_time_difference \
	skyscrapers_4x4_puzzle \
	skyscrapers_6x6_puzzle \
	skyscrapers_7x7_puzzle \
	snail_sort \
	snakes_and_ladders \
	sort_numbers \
	sort_one_three_two \
	square_into_squares \
	square_matrix_multiplication \
	strclr \
	string_incrementer \
	string_reverse \
	strings_mix \
	substring_instance_count \
	sum_number_strings \
	sum_of_intervals \
	ten_minutes_walk \
	the_observed_pin \
	tic_tac_toe_checker \
	weight_for_weight \
	who_likes_it \
	write_out_numbers \
	your_own_printf \
	zonk_game

.PHONY: all clean reformat run vrun

all: $(TARGETS)

%: %.c %_main.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

clean:
	rm -f $(TARGETS)

reformat:
	clang-format --style=Chromium -i *.c

run:
	./`zenity --title="Execute Program" --height 600 --list --text="Choose Executable" --column=Executable $(TARGETS)`

vrun:
	valgrind --leak-check=full --show-error-list=yes ./`zenity --title="Valgrind Program" --height 600 --list --text="Choose Executable" --column=Executable $(TARGETS)`
