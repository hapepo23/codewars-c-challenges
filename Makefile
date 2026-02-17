CC = gcc
CFLAGS = -std=c18 -Wall -Wextra -O0 -g
LDLIBS = -lm

TARGETS = \
	adding_big_numbers \
	alphabet_position \
	array_diff \
	array_exchange \
	base64 \
	base64_numeric_translator \
	beeramid \
	big_integer_modulo \
	bit_counting \
	blackjack_scorer \
	bonus_time \
	build_tower \
	categorize_new_member \
	clockwise_spiral \
	common_denominators \
	convert_string_to_array \
	count_characters \
	count_codepoints \
	counting_change_combinations \
	counting_duplicates \
	count_ip_addresses \
	create_phone_number \
	cuboids_volumes_difference \
	decode_morse \
	decode_roman \
	detect_pangram \
	determinant \
	digital_root \
	directions_reduction \
	divide_number_strings \
	dna_to_rna_conversion \
	equal_sides_of_array \
	escape_the_maze \
	eval_math_expression \
	evaporator \
	expanded_form \
	factorial_decomposition \
	factorial_trailing_zeros \
	fibonacci_squares_perimeter \
	find_date \
	find_parity_outlier \
	find_the_odd_int \
	find_the_unique_number \
	first_fibonacci \
	format_duration \
	get_count \
	get_middle_character \
	get_the_vowels \
	grab_csv_columns \
	grasshopper_summation \
	greed_is_good \
	hex_string_to_rgb \
	high_and_low \
	human_readable_time \
	int32_to_ipv4 \
	integer_sqrt \
	irreducible_sum_of_rationals \
	is_anagram \
	is_ordered \
	is_prime \
	is_triangle \
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
	maskify \
	matrix_addition \
	maximum_subarray_sum \
	mean_square_error \
	merged_string_checker \
	move_zeros \
	multiples_of_3_or_5 \
	multiplication_table \
	multiply_number_strings \
	my_strtok \
	next_bigger_number \
	next_perfect_square \
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
	ranking_poker_hands \
	rational_arithmetic \
	rectangle_rotation \
	rgb_to_hex \
	roman_num_encoder \
	roman_num_helper \
	rot13 \
	rotate \
	rotate_matrix_counter_clockwise \
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
	sort_the_odd \
	spin_words \
	square_digits \
	square_into_squares \
	square_matrix_multiplication \
	strclr \
	string_ends_with \
	string_incrementer \
	string_reverse \
	strings_mix \
	string_to_camel_case \
	substring_instance_count \
	sum_number_strings \
	sum_of_intervals \
	sum_two_smallest_numbers \
	ten_minutes_walk \
	the_observed_pin \
	tic_tac_toe_checker \
	transpose_matrix \
	tv_remote \
	valid_braces \
	value_of_x \
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
