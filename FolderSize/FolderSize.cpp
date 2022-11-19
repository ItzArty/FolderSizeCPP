#include <iostream>
#include <filesystem>
#include <chrono>

using namespace std;
using namespace std::filesystem;
using namespace chrono;

int main( int argc, char** args ) {

	if (argc < 2) {

		cout << "Usage: " << args[0] << " [path]" << endl;

		return 0;

	}

	path target = args[1];

	if (!exists(target)) {

		cout << "Entered path does not exist." << endl;

		return 0;

	}

	recursive_directory_iterator& increment(error_code & ec) noexcept;

	unsigned long long totalSize = 0;

	steady_clock::time_point start = steady_clock::now();

	for ( auto& dir_entry : recursive_directory_iterator( target, directory_options::skip_permission_denied ) ) {

		try {

			if (dir_entry.is_regular_file()) totalSize += dir_entry.file_size();

		} catch ( exception& e ) {

			cout << e.what() << "\n";

		}

	}

	steady_clock::time_point end = steady_clock::now();

	cout << "Path evaluated: " << target.string() << endl;
	cout << "Total size: " << (totalSize / (1024 * 1024)) << "MB" << endl;
	cout << "Time elapsed: " << duration_cast<milliseconds>(end - start).count() << "ms" << endl;

	return 0;

}
