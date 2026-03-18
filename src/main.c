#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

/* 1000 msec = 1 sec */
#define SLEEP_1_SEC  1000
#define SLEEP_500_MS 500
#define SLEEP_100_MS 100

/* The devicetree node identifier for the "led0" alias. */
#define RED_LED_NODE DT_ALIAS(led1)
#define GREEN_LED_NODE DT_ALIAS(led2)
#define BLUE_LED_NODE DT_ALIAS(led3)
#define NON_RGB_LED_NODE DT_ALIAS(led0)

/*
 * A build error on this line means your board is unsupported.
 * See the sample documentation for information on how to fix this.
 */
struct gpio_dt_spec blue_rgbled = GPIO_DT_SPEC_GET(BLUE_LED_NODE, gpios);
struct gpio_dt_spec green_rgbled = GPIO_DT_SPEC_GET(GREEN_LED_NODE, gpios);
struct gpio_dt_spec red_rgbled = GPIO_DT_SPEC_GET(RED_LED_NODE, gpios);
struct gpio_dt_spec non_rgbled = GPIO_DT_SPEC_GET(NON_RGB_LED_NODE, gpios);
enum color_enum {
	R,G,B
};
struct led_state {
	bool toggle;
	struct gpio_dt_spec* led;
	enum color_enum color;
};
struct led_state state = {.toggle = false, .led = &blue_rgbled, .color=B};
const int sleep_pattern[10] = {SLEEP_1_SEC,SLEEP_1_SEC, SLEEP_100_MS,SLEEP_100_MS,SLEEP_100_MS, SLEEP_500_MS, SLEEP_500_MS, SLEEP_100_MS,SLEEP_100_MS,SLEEP_100_MS};
int pattern_counter = 0;
int configure(struct gpio_dt_spec* led) {
	int ret = gpio_pin_configure_dt(led, GPIO_OUTPUT_ACTIVE);
	if (ret < 0) {
		return 0;
	}
	return 1;
}
int main(void)
{
	int ret = 0;
	if (!gpio_is_ready_dt(&non_rgbled) && !gpio_is_ready_dt(&blue_rgbled) && !gpio_is_ready_dt(&green_rgbled) && !gpio_is_ready_dt(&red_rgbled)) {
		return 0;
	}
	ret += configure(&non_rgbled);
	ret += configure(&blue_rgbled);
	ret += configure(&green_rgbled);
	ret += configure(&red_rgbled);
	if (ret != 4) return 0;
	gpio_pin_set(non_rgbled.port,non_rgbled.pin,0);
	gpio_pin_set(blue_rgbled.port,blue_rgbled.pin,0);
	gpio_pin_set(red_rgbled.port,red_rgbled.pin,0);
	gpio_pin_set(green_rgbled.port,green_rgbled.pin,0);

	while (1) {
		ret = gpio_pin_toggle_dt(state.led);
		if (ret < 0) {
			return 0;
		}

		state.toggle = !state.toggle;
		printf("LED state: %s\n", state.toggle ? "ON" : "OFF");
		if (pattern_counter > 9) {
			pattern_counter = 0;
			gpio_pin_set(state.led->port,state.led->pin,0);
			state.toggle = false;
			if (state.color == B) {
				state.led = &red_rgbled;
				state.color = R;
			}
			else if (state.color == R) {
				state.led = &green_rgbled;
				state.color = G;
			}
			else if (state.color == G) {
				state.led = &blue_rgbled;
				state.color = B;
			}			
		}
		k_msleep(sleep_pattern[pattern_counter]);
		pattern_counter++;
	}
	return 0;
}