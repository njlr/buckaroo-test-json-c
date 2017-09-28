#include <gtest/gtest.h>

#include <json-c/json_inttypes.h>
#include <json-c/json_object.h>
#include <json-c/json_tokener.h>
#include <json-c/json_util.h>

TEST(jsonc, basics) {

	const char *input = "{\n\
		\"string_of_digits\": \"123\",\n\
		\"regular_number\": 222,\n\
		\"decimal_number\": 99.55,\n\
		\"boolean_true\": true,\n\
		\"boolean_false\": false,\n\
		\"big_number\": 2147483649,\n\
		\"a_null\": null,\n\
	}";

	struct json_object* o = json_tokener_parse(input);

  ASSERT_TRUE(o);

  const char* stringified = json_object_to_json_string(o);

  struct json_object* p = json_tokener_parse(stringified);

	ASSERT_TRUE(p);
}
