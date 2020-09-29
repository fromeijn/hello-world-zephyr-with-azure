/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr.h>
#include <sys/printk.h>

#include <azure/core/az_json.h>
#include <azure/core/az_result.h>
#include <azure/core/az_span.h>

void main(void)
{
	printk("Hello World!\n", CONFIG_BOARD);

	az_span my_first_span = AZ_SPAN_FROM_STR("Hello Azure");
	// use size for printing az_span (since it is not 0 terminated.)
	printk("%.*s\n", az_span_size(my_first_span), az_span_ptr(my_first_span));

	uint8_t buffer[200] = {0};
	az_json_writer writer = {0};

	az_result result = az_json_writer_init(&writer, AZ_SPAN_FROM_BUFFER(buffer), NULL);
	// {
	result = az_json_writer_append_begin_object(&writer);
	// {"name":
	result = az_json_writer_append_property_name(&writer, AZ_SPAN_FROM_STR("name"));
	// {"name":true
	result = az_json_writer_append_bool(&writer, true);
	// {"name":true}
	result = az_json_writer_append_end_object(&writer);

	printk("%s\n", buffer);
}
