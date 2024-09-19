#define PROBLEM "https://judge.yosupo.jp/problem/aplusb"

#include "../../../misc/template.h"
#include "../../../utils/encode.h"

const int T = 1000;

int main() {
	for (int i = 0; i < T; i++) {
		auto arr = rand_arr<int, 2500>(1e9);
		auto enc = encode<decltype(arr), 5>(arr);
		auto dec = decode<decltype(arr), 5>(enc);
		assert(arr == dec);
	}

	for (int i = 0; i < T; i++) {
		array<array<int, 50>, 50> arr;
		for (int j = 0; j < 50; j++) {
			arr[j] = rand_arr<int, 50>(1e9);
		}
		auto enc = encode<decltype(arr), 5>(arr);
		auto dec = decode<decltype(arr), 5>(enc);
		assert(arr == dec);
	}

	cerr << "Tests passed\n";

	int a, b;
	cin >> a >> b;
	cout << a + b << '\n';
}