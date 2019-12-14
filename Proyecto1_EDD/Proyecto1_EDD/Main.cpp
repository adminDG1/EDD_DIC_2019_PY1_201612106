#include <iostream>
#include <fstream>
#include <iomanip> //para stw
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

int main()
{
	// a JSON value
	json j_original = R"({
  "baz": [{"bar":"b1"},{"bar1":"b1"}],
  "foo": {"bar":"b","bar3":"h"}
})"_json;

	// access members with a JSON pointer (RFC 6901)
	cout << j_original["/foo/bar3"_json_pointer] << endl;
	cout << j_original["/baz/1/bar1"_json_pointer] << endl;
	//cout<<j_original["baz/Name"]<<endl;
	// "two"

	// ]

	// create a JSON object with different entry types
	json js =
	{
		{ "integer", 1 },
		{ "floating", 42.23 },
		{ "string", "hello world" },
		{ "boolean", true },
		{ "object",{ { "key1", 1 },{ "key2", 2 } } },
		{ "array",{ 1, 2, 3 } }
	};

	// access existing values
	//int v_integer = j_original.value("foo", 0);
	//cout << v_integer<<endl;


	cout << endl;



	//

	// create an array using push_back
	json jd;
	jd.push_back("foo");
	jd.push_back(1);
	jd.push_back(true);

	// also use emplace_back
	jd.emplace_back(1.78);
	cout << jd << endl;

	// iterate the array
	for (json::iterator it = jd.begin(); it != jd.end(); ++it) {
		std::cout << *it << '\n';
	}

	/* range-based for
	for (auto& element : jd) {
	std::cout << element << '\n';
	}

	// getter/setter
	const auto tmp = jd[0].get<std::string>();
	jd[1] = 42;
	bool foo = jd.at(2);

	// range-based for
	for (auto& element : jd) {
	std::cout << element << '\n';
	} */
	cout << endl;
	cout << endl;

	/////////////////////////////////////////////

	json o;
	o["foo"] = 23;
	o["bar"] = false;
	o["baz"] = 3.141;

	// also use emplace
	o.emplace("weather", "sunny");

	cout << o << endl;

	// special iterator member functions for objects
	for (json::iterator it = o.begin(); it != o.end(); ++it) {
		std::cout << it.key() << " : " << it.value() << "\n";
	}
	cout << endl;
	cout << o["weather"] << endl;
	string stringo;
	o["weather"].get_to(stringo);
	cout << stringo << endl;

	std::cin.get();

}