#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""Ping-pong.
This is a ping-pong look-alike but the maximum score is 9 instead of 11 due to
the use of only one 7 segment display per player.
To run it just copy this file to your home directory (usually /home/pi) and
execute the following command in the Raspberry command line
sudo python ~/ping-pongv1.py

Rules:
A point is won when the other player is unable to press the button on time to
send the “ball” (lit LED) to the other side or if the other player presses the
button in advance.
The player who wins the point starts the next service.
A game is won after 9 points.
A match should consist of any odd number of games (usually five or seven).

For the first service, the starting player is randomly selected.
The time between LED jumps is random to make it more difficult to predict.
The buzzer will sound every time a point is won.
"""

import random
import time

import RPi.GPIO as GPIO


# All constants and variables use board pins numbering system
BUTTON_1 = 7
BUTTON_2 = 40
IN = [BUTTON_1, BUTTON_2]  # all input pins

LEDS = [11, 13, 15, 18, 22, 29]
FIRST = 0  # first position,
LAST = len(LEDS) - 1  # last position

BUZZER = 16

# pins are ordered by letter according to the 7 segment display documentation
DISPLAY_1 = [21, 19, 12, 10, 8, 23, 24]
DISPLAY_2 = [36, 35, 33, 32, 31, 37, 38]

OUT = LEDS + [BUZZER] + DISPLAY_1 + DISPLAY_2  # all output pins

# masks are ordered by letter according to the 7 segment display documentation
DIGITS_MASKS = {0: [1, 1, 1, 1, 1, 1, 0], 1: [0, 1, 1, 0, 0, 0, 0],
                2: [1, 1, 0, 1, 1, 0, 1], 3: [1, 1, 1, 1, 0, 0, 1],
                4: [0, 1, 1, 0, 0, 1, 1], 5: [1, 0, 1, 1, 0, 1, 1],
                6: [1, 0, 1, 1, 1, 1, 1], 7: [1, 1, 1, 0, 0, 0, 0],
                8: [1, 1, 1, 1, 1, 1, 1], 9: [1, 1, 1, 0, 0, 1, 1]}

# LEDs direction
RIGHT = 1
LEFT = -1

MAX_SCORE = 9

# global score vars
player_1 = 0
player_2 = 0


def set_in_pins(pins):
    """Setup input pins."""
    for pin in pins:
        GPIO.setup(pin, GPIO.IN, GPIO.PUD_DOWN)  # activates pull down resistor


def set_out_pins(pins):
    """Setup output pins."""
    for pin in pins:
        GPIO.setup(pin, GPIO.OUT)


def pin_low(pin):
    """Activates low (0 volts / GND) signal on specified pin."""
    GPIO.output(pin, GPIO.LOW)


def all_low(pins_lst):
    """Activates low (0 volts / GND) signal on all pins on the list."""
    for pin in pins_lst:
        pin_low(pin)


def show_digit(digit=0, display=DISPLAY_1):
    """Show digit in specififed display."""
    # enumerate returns position and value from digit's mask
    for pos, value in enumerate(DIGITS_MASKS[digit]):
        GPIO.output(display[pos], value)


def show_scores():
    """Shows players scores."""
    show_digit(player_1, DISPLAY_1)  # show player 1 score on 1st display
    show_digit(player_2, DISPLAY_2)  # show player 2 score on 2nd display


def pin_high(pin):
    """Activates high (3.3v) signal on specified pin."""
    GPIO.output(pin, GPIO.HIGH)


def led_on(pos):
    """Switch LED on and pauses."""
    pin_high(LEDS[pos])
    if pos in [FIRST, LAST]:  # 1st or last LED
        pause = 0.3  # fixed delay to allow button response
    else:
        pause = random.choice([0.5, 1, 1.5, 2])  # random delay
    time.sleep(pause)


def led_off(pos):
    """Switch LED off."""
    pin_low(LEDS[pos])


def is_on(pin):
    """True if pin has a high signal."""
    return GPIO.input(pin) == GPIO.HIGH


def buzzer(pin, pause=1):
    """Activates buzzer."""
    pin_high(pin)
    time.sleep(pause)
    pin_low(pin)


def end_service():
    """Buzzes and updates scores."""
    buzzer(BUZZER)
    show_scores()
    time.sleep(2)


def out_sequence(pause=1):
    """Shows LED sequence from inside out."""
    nr_leds = len(LEDS)
    for pos in range(nr_leds / 2, 0, -1):  # reverse order
        # activate pair
        pin_high(LEDS[pos - 1])
        pin_high(LEDS[-pos + nr_leds])

        time.sleep(pause)

        # deactivate pair
        pin_low(LEDS[pos - 1])
        pin_low(LEDS[-pos + nr_leds])
    time.sleep(pause)


try:
    GPIO.setmode(GPIO.BOARD)  # setup pin numbering system
    GPIO.setwarnings(False)

    set_in_pins(IN)  # setup input pins
    set_out_pins(OUT)  # setup output pins

    all_low(OUT)  # clear all output pins

    cur_pos = random.choice([FIRST, LAST])  # define 1st LED to be lit
    if cur_pos == FIRST:
        direction = RIGHT
    else:
        direction = LEFT

    show_scores()

    while player_1 < MAX_SCORE and player_2 < MAX_SCORE:
        # light LED (ball) and pause for a little time to allow the players to
        # press the button
        led_on(cur_pos)

        led_off(cur_pos)

        if ((direction == RIGHT and cur_pos < LAST) or  # not in last position
            (direction == LEFT and cur_pos > FIRST)):  # not in first position

            if is_on(BUTTON_1):  # if button 1 was pressed player 1 loses
                player_2 += 1
                cur_pos = LAST
                direction = LEFT
                end_service()
            elif is_on(BUTTON_2):  # if button 2 was pressed player 2 loses
                player_1 += 1
                cur_pos = FIRST
                direction = RIGHT
                end_service()
            else:
                cur_pos += direction  # updates position

        else:  # it is the first or last position

            if ((cur_pos == LAST and is_on(BUTTON_2)) or
                (cur_pos == FIRST and is_on(BUTTON_1))):

                direction *= -1  # change direction
                cur_pos += direction

            else:  # player didn't push button on time

                if cur_pos == FIRST:  # player 1 loses
                    player_2 += 1
                    cur_pos = LAST
                    direction = LEFT
                else:  # player 2 loses
                    player_1 += 1
                    cur_pos = FIRST
                    direction = RIGHT
                end_service()

    out_sequence()

except KeyboardInterrupt as error:
    pass

finally:  # always executed
    GPIO.cleanup()  # restores all pins pre-game state
